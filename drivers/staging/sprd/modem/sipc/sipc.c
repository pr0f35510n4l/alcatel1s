/*
 * Copyright (C) 2015 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/debugfs.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_irq.h>
#include <linux/platform_device.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/wait.h>
#include <linux/sipc.h>
#include <linux/sizes.h>

#ifdef CONFIG_SPRD_MAILBOX
#include "../include/sprd_mailbox.h"
#else
#define SPRD_DEV_P2V(paddr)	(paddr)
#define SPRD_DEV_V2P(vaddr)	(vaddr)
#endif

#include "../include/sipc_priv.h"

#define SMSG_TXBUF_ADDR		(0)
#define SMSG_TXBUF_SIZE		(SZ_1K)
#define SMSG_RXBUF_ADDR		(SMSG_TXBUF_SIZE)
#define SMSG_RXBUF_SIZE		(SZ_1K)

#define SMSG_RINGHDR		(SMSG_TXBUF_SIZE + SMSG_RXBUF_SIZE)
#define SMSG_TXBUF_RDPTR	(SMSG_RINGHDR + 0)
#define SMSG_TXBUF_WRPTR	(SMSG_RINGHDR + 4)
#define SMSG_RXBUF_RDPTR	(SMSG_RINGHDR + 8)
#define SMSG_RXBUF_WRPTR	(SMSG_RINGHDR + 12)

struct sipc_core sipc_ap;
EXPORT_SYMBOL(sipc_ap);

#if defined(CONFIG_DEBUG_FS)
void sipc_debug_putline(struct seq_file *m, char c, int n)
{
	char buf[300];
	int i, max, len;

	/* buf will end with '\n' and 0 */
	max = ARRAY_SIZE(buf) - 2;
	len = (n > max) ? max : n;

	for (i = 0; i < len; i++)
		buf[i] = c;

	buf[i] = '\n';
	buf[i + 1] = 0;

	seq_puts(m, buf);
}
EXPORT_SYMBOL(sipc_debug_putline);
#endif

/* if it's upon mailbox arch, overwrite the implementation*/
#ifdef CONFIG_SPRD_MAILBOX
#ifdef CONFIG_SPRD_MAILBOX_FIFO
static u32 sipc_rxirq_status(u8 id)
{
	struct sipc_child_node_info *info = sipc_ap.sipc_tags[id];

	return mbox_core_fifo_full(info->core_id);
}

static void sipc_rxirq_clear(u8 id)
{
}

static void sipc_txirq_trigger(u8 id, u64 msg)
{
	struct sipc_child_node_info *info = sipc_ap.sipc_tags[id];

	mbox_raw_sent(info->core_id, msg);
}
#else
static u32 sipc_rxirq_status(u8 id)
{
	return 1;
}

#define DEFINE_SIPC_RXIRQ_CLEAR_FN(id)
static void sipc_rxirq_clear(u8 id)
{
}

static void sipc_txirq_trigger(u8 id)
{
	struct sipc_child_node_info *info = sipc_ap.sipc_tags[id];

	mbox_raw_sent(info->core_id, 0);
}
#endif
#else
static u32 sipc_rxirq_status(u8 id)
{
	return 1;
}

static void sipc_rxirq_clear(u8 id)
{
	struct sipc_child_node_info *info = sipc_ap.sipc_tags[id];

	__raw_writel(info->ap2cp_bit_clr,
		     ((__force void __iomem *))(unsigned long)
		     info->cp2ap_int_ctrl);
}

static void sipc_txirq_trigger(u8 id)
{
	struct sipc_child_node_info *info = sipc_ap.sipc_tags[id];

	__raw_writel(info->ap2cp_bit_trig,
		     ((__force void __iomem *))(unsigned long)
		     info->ap2cp_int_ctrl);
}

#endif
static int sipc_create(struct sipc_device *sipc)
{
	struct sipc_init_data *pdata = sipc->pdata;
	struct smsg_ipc *inst;
	struct sipc_child_node_info *info;
	void __iomem *base;
	u32 num;
	int ret = 0, i, j = 0;

	if (!pdata)
		return -ENODEV;

	num = pdata->chd_nr;
	inst = sipc->smsg_inst;
	info = pdata->info_table;

	for (i = 0; i < num; i++) {
		if (j < pdata->newchd_nr && info[i].is_new) {
			if (!info[i].mode) {
				base = (void __iomem *)shmem_ram_vmap_nocache(
							(u32)info[i].ring_base,
							info[i].ring_size);
				if (!base) {
					pr_info("sipc chd%d ioremap return 0\n",
						i);
					return -ENOMEM;
				}
				info[i].smem_vbase = (void *)base;

				pr_info("sipc:[tag%d] after ioremap vbase=0x%p, pbase=0x%x, size=0x%x\n",
					j, base,
					info[i].ring_base,
					info[i].ring_size);
				inst[j].txbuf_size = SMSG_TXBUF_SIZE /
					sizeof(struct smsg);
				inst[j].txbuf_addr = (uintptr_t)base +
					SMSG_TXBUF_ADDR;
				inst[j].txbuf_rdptr = (uintptr_t)base +
					SMSG_TXBUF_RDPTR;
				inst[j].txbuf_wrptr = (uintptr_t)base +
					SMSG_TXBUF_WRPTR;

				inst[j].rxbuf_size = SMSG_RXBUF_SIZE /
					sizeof(struct smsg);
				inst[j].rxbuf_addr = (uintptr_t)base +
					SMSG_RXBUF_ADDR;
				inst[j].rxbuf_rdptr = (uintptr_t)base +
					SMSG_RXBUF_RDPTR;
				inst[j].rxbuf_wrptr = (uintptr_t)base +
					SMSG_RXBUF_WRPTR;
			}

			inst[j].id = sipc_ap.sipc_tag_ids;
			sipc_ap.sipc_tags[sipc_ap.sipc_tag_ids] = &info[i];
			sipc_ap.sipc_tag_ids++;

			ret = smsg_ipc_create(inst[j].dst, &inst[j]);

			pr_info("sipc:[tag%d] created, dst = %d\n",
				j, inst[j].dst);
			j++;
			if (ret)
				break;
		}
	}
	return ret;
}

static int sipc_parse_dt_v1(struct sipc_init_data **init, struct device *dev)
{
	u32 val[3];
	int ret = -1;
	struct sipc_init_data *pdata;
	struct sipc_child_node_info *info;

	pdata = devm_kzalloc(dev,
			     sizeof(struct sipc_init_data) +
			     sizeof(struct sipc_child_node_info),
			     GFP_KERNEL);
	if (!pdata) {
		pr_err("sipc: failed to alloc mem for pdata\n");
		return -ENOMEM;
	}

	pdata->is_alloc = 1;
	pdata->chd_nr = 1;
	info = pdata->info_table;
	info->mode = 1;

	ret = of_property_read_string(dev->of_node,
				      "sprd,name",
				      (const char **)&info->name);
	if (ret)
		goto error;
	pr_info("sipc: name=%s\n", info->name);

#ifdef CONFIG_SPRD_MAILBOX_SENSOR
	ret = of_property_read_u32_array(dev->of_node, "sprd,dst", val, 3);
	if (!ret)
		info->core_sensor_id = (u8)val[2];
	else
		info->core_sensor_id = (u8)RECV_MBOX_SENSOR_ID;

	pr_info("sipc: core_sensor_id = %u\n", info->core_sensor_id);
#else
	ret = -1;
#endif

	if (ret) {
		ret = of_property_read_u32_array(dev->of_node,
						 "sprd,dst", val, 2);
		if (ret) {
			pr_err("sipc: parse dst info failed.\n");
			goto error;
		}
	}

	info->dst = (u8)val[0];
	info->core_id = (u8)val[1];

	pr_info("sipc: dst = %u, core_id = %u\n", info->dst, info->core_id);
	if (info->dst >= SIPC_ID_NR) {
		pr_err("sipc: dst info is invalid.\n");
		goto error;
	}

	if (!smsg_ipcs[info->dst]) {
		pdata->newchd_nr++;
		info->is_new = 1;
	} else {
		info->is_new = 0;
	}

	ret = of_property_read_u32_array(dev->of_node,
					 "sprd,smem-info",
					 val,
					 3);
	if (ret) {
		pr_err("sipc: parse smem info failed.\n");
		goto error;
	}
	pdata->smem_base = val[0];
	pdata->mapped_smem_base = val[1];
	pdata->smem_size = val[2];
	pr_info("sipc: smem_base = 0x%x, mapped_smem_base = 0x%x, smem_size = 0x%x\n",
		pdata->smem_base, pdata->mapped_smem_base, pdata->smem_size);

	*init = pdata;

	return 0;

error:
	devm_kfree(dev, pdata);

	return ret;
}

static int sipc_parse_dt(struct sipc_init_data **init, struct device *dev)
{
	struct device_node *np = dev->of_node, *nchd;
	struct sipc_init_data *pdata;
	struct sipc_child_node_info *info;
	struct resource res;
#ifndef CONFIG_SPRD_MAILBOX
	u32 int_ctrl_phy[2];
#endif
	u32 data, nr;
	int ret, i;

	nr = of_get_child_count(np);
	if (nr == 0 || nr >= SIPC_ID_NR)
		return (!nr ? -ENODEV : -EINVAL);
	pdata = devm_kzalloc(dev,
			     sizeof(struct sipc_init_data) +
			     nr * sizeof(struct sipc_child_node_info),
			     GFP_KERNEL);
	if (!pdata) {
		pr_err("sipc: failed to alloc mem for pdata\n");
		return -ENOMEM;
	}

	pdata->is_alloc = 1;
	ret = of_address_to_resource(np, 0, &res);
	if (ret)
		goto error;
	pdata->chd_nr = nr;

	pdata->smem_base = (u32)res.start;
	pdata->mapped_smem_base = pdata->smem_base;
	pdata->smem_size = (u32)(res.end - res.start + 1);
	pr_info("sipc: chd_nr=%d smem_base=0x%x, smem_size=0x%x\n",
		pdata->chd_nr, pdata->smem_base, pdata->smem_size);

	i = 0;
	info = pdata->info_table;

	for_each_child_of_node(np, nchd) {
		ret = of_property_read_string(nchd, "sprd,name",
					      (const char **)&info[i].name);
		if (ret)
			goto error;
		pr_info("sipc:[%d] name=%s\n", i, info[i].name);

		ret = of_property_read_u32(nchd, "sprd,dst", &data);
		if (ret)
			goto error;
		info[i].dst = (u8)data;
		pr_info("sipc:[tag%d] dst=%u\n", i, info[i].dst);
		if (smsg_ipcs[info[i].dst] == NULL) {
			pdata->newchd_nr++;
			info[i].is_new = 1;
		} else {
			info[i].is_new = 0;
		}

#ifndef CONFIG_SPRD_MAILBOX
		/* get ipi base addr */
		ret = of_property_read_u32(nchd,
					   "sprd,ap2cp",
					   &int_ctrl_phy[0]);
		if (ret)
			goto error;
		info[i].ap2cp_int_ctrl = SPRD_DEV_P2V(int_ctrl_phy[0]);

		ret = of_property_read_u32(nchd,
					   "sprd,cp2ap",
					   &int_ctrl_phy[1]);
		if (ret)
			goto error;
		info[i].cp2ap_int_ctrl = SPRD_DEV_P2V(int_ctrl_phy[1]);

		pr_info("sipc:[tag%d] ap2cp_int_ctrl=0x%x, ap2cp_ctrl_phy=0x%x, cp2ap_int_ctrl=0x%x, cp2ap_ctrl_phy=0x%x\n",
			i, info[i].ap2cp_int_ctrl,
			int_ctrl_phy[0],
			info[i].cp2ap_int_ctrl,
			int_ctrl_phy[1]);

		ret = of_property_read_u32(nchd,
					   "sprd,trig",
					   &info[i].ap2cp_bit_trig);
		if (ret)
			goto error;

		ret = of_property_read_u32(nchd,
					   "sprd,clr",
					   &info[i].ap2cp_bit_clr);
		if (ret)
			goto error;
		pr_info("sipc:[%d] ap2cp_bit_trig=0x%x, ap2cp_bit_clr=0x%x\n",
			i, info[i].ap2cp_bit_trig, info[i].ap2cp_bit_clr);
#endif
		if (strcmp(info[i].name, "sipc-pmsys") != 0) {
			/* get smem base addr */
			ret = of_address_to_resource(nchd, 0, &res);
			if (ret)
				goto error;
			info[i].smem_base = (u32)res.start;
			info[i].smem_size = (u32)(res.end - res.start + 1);
			pr_info("sipc:[tag%d] smem_base=0x%x, smem_size=0x%x\n",
				i, info[i].smem_base, info[i].smem_size);

			/* get ring base addr */
			ret = of_address_to_resource(nchd, 1, &res);
			if (ret)
				goto error;
			info[i].ring_base = (u32)res.start;
			info[i].ring_size = (u32)(res.end - res.start + 1);
			pr_info("sipc:[tag%d] ring_base=0x%x, ring_size=0x%x\n",
				i, info[i].ring_base, info[i].ring_size);
		} else {
			if (!of_address_to_resource(nchd, 1, &res)) {
				/* for sipc-pmsys & sipc-lte don't
				 * belong to the same node
				 */
				info[i].ring_base = (u32)res.start;
				info[i].ring_size = (u32)(res.end -
							       res.start + 1);
				pr_info("sipc:[tag%d] pmsys ring_base=0x%x, ring_size=0x%x\n",
					i,
					info[i].ring_base,
					info[i].ring_size);

				ret = of_address_to_resource(nchd, 0, &res);
				if (ret)
					goto error;
				info[i].smem_base = (u32)res.start;
				info[i].smem_size = (u32)(res.end -
							       res.start + 1);
				pr_info("sipc:[tag%d] pmsys smem_base=0x%x, smem_size=0x%x\n",
					i,
					info[i].ring_base,
					info[i].ring_size);
			} else {
				ret = of_address_to_resource(nchd, 0, &res);
				if (ret)
					goto error;
				info[i].ring_base = (u32)res.start;
				info[i].ring_size = (u32)(res.end -
							       res.start + 1);
				pr_info("sipc:[tag%d] pmsys ring_base=0x%x, ring_size=0x%x\n",
					i,
					info[i].ring_base,
					info[i].ring_size);
			}
		}

#ifdef CONFIG_SPRD_MAILBOX
		ret = of_property_read_u32(nchd,
					   "mailbox,core",
					   &data);
		if (ret)
			goto error;

		info[i].core_id = (u8)data;
		pr_info("sipc:[tag%d] core_id=%u\n", i, info[i].core_id);
#else
		/* get irq */
		info[i].irq = irq_of_parse_and_map(nchd, 0);
		if (!info[i].irq) {
			ret = -EINVAL;
			goto error;
		}
		pr_info("sipc:[tag%d] irq=%d\n", i, info[i].irq);
#endif
		i++;
	}
	*init = pdata;
	return 0;
error:
	devm_kfree(dev, pdata);
	return ret;
}

static void sipc_destroy_pdata(struct sipc_init_data **ppdata,
			       struct device *dev)
{
	struct sipc_init_data *pdata = *ppdata;
	struct sipc_child_node_info *info;
	int i, num;

	if (pdata) {
		num = pdata->chd_nr;
		for (i = 0; i < num; i++) {
			info = pdata->info_table;
			if (info[i].smem_vbase)
				shmem_ram_unmap(info[i].smem_vbase);
		}
		if (pdata->is_alloc)
			devm_kfree(dev, pdata);
	}
}

static const struct of_device_id sipc_match_table[] = {
	{.compatible = "sprd,sipc", .data = sipc_parse_dt, },
	{.compatible = "sprd,sipc-v1", .data = sipc_parse_dt_v1, },
	{ },
};

static int sipc_probe(struct platform_device *pdev)
{
	struct sipc_init_data *pdata = pdev->dev.platform_data;
	struct sipc_device *sipc;
	struct sipc_child_node_info *info;
	struct smsg_ipc *smsg;
	const struct of_device_id *of_id;
	int (*parse)(struct sipc_init_data **, struct device *);
	u32 num, dst;
	int i, j = 0;

	if (!pdata && pdev->dev.of_node) {
		of_id = of_match_node(sipc_match_table, pdev->dev.of_node);
		if (!of_id) {
			pr_err("sipc: failed to get of_id\n");
			return -ENODEV;
		}
		parse = (int(*)(struct sipc_init_data **,
				struct device *))of_id->data;
		if (parse && parse(&pdata, &pdev->dev)) {
			pr_err("sipc: failed to parse dt, parse(0x%p)\n",
			       parse);
			return -ENODEV;
		}
	}

	sipc = devm_kzalloc(&pdev->dev, sizeof(struct sipc_device), GFP_KERNEL);
	if (!sipc) {
		sipc_destroy_pdata(&pdata, &pdev->dev);
		return -ENOMEM;
	}

	num = pdata->chd_nr;
	smsg = devm_kzalloc(&pdev->dev,
			    pdata->newchd_nr * sizeof(struct smsg_ipc),
			    GFP_KERNEL);
	if (!smsg) {
		sipc_destroy_pdata(&pdata, &pdev->dev);
		devm_kfree(&pdev->dev, sipc);
		return -ENOMEM;
	}
	pr_info("sipc: tag count = %d\n", num);
	info = pdata->info_table;
	for (i = 0; i < num; i++) {
		if (j < pdata->newchd_nr && info[i].is_new) {
			smsg[j].name = info[i].name;
			smsg[j].dst = info[i].dst;
#ifdef CONFIG_SPRD_MAILBOX
			smsg[j].core_id = info[i].core_id;
#ifdef CONFIG_SPRD_MAILBOX_SENSOR
			smsg[j].core_sensor_id = info[i].core_sensor_id;
#endif
#else
			smsg[j].irq = info[i].irq;
#endif
			smsg[j].rxirq_status = sipc_rxirq_status;
			smsg[j].rxirq_clear = sipc_rxirq_clear;
			smsg[j].txirq_trigger = sipc_txirq_trigger;

#ifdef CONFIG_SPRD_MAILBOX
			pr_info("sipc:[tag%d] smsg name=%s, dst=%u, core_id=%d\n",
				j, smsg[j].name, smsg[j].dst, smsg[j].core_id);
#else
			pr_info("sipc:[tag%d] smsg name=%s, dst=%u, irq=%d\n",
				j, smsg[j].name, smsg[j].dst, smsg[j].irq);
#endif
			j++;
		}
	}

	sipc->pdata = pdata;
	sipc->smsg_inst = smsg;
	dst = pdata->info_table->dst;
	sipc_ap.sipc_dev[dst] = sipc;

	pr_info("sipc: smem_init smem_base=0x%x, smem_size=0x%x\n",
		pdata->smem_base, pdata->smem_size);
	if (dst == SIPC_ID_LTE ||
	    dst == SIPC_ID_CPW ||
	    dst == SIPC_ID_CPT)
		smem_set_default_pool(pdata->smem_base);

	smem_init(pdata->smem_base, pdata->smem_size, dst);
	smsg_suspend_init();

	sipc_create(sipc);

	platform_set_drvdata(pdev, sipc);
	return 0;
}

static int sipc_remove(struct platform_device *pdev)
{
	struct sipc_device *sipc = platform_get_drvdata(pdev);

	sipc_destroy_pdata(&sipc->pdata, &pdev->dev);
	devm_kfree(&pdev->dev, sipc->smsg_inst);
	devm_kfree(&pdev->dev, sipc);
	return 0;
}

static struct platform_driver sipc_driver = {
	.driver = {
		.owner = THIS_MODULE,
		.name = "sipc",
		.of_match_table = sipc_match_table,
	},
	.probe = sipc_probe,
	.remove = sipc_remove,
};

static int __init sipc_init(void)
{
	return platform_driver_register(&sipc_driver);
}

static void __exit sipc_exit(void)
{
	platform_driver_unregister(&sipc_driver);
}

subsys_initcall_sync(sipc_init);
module_exit(sipc_exit);

MODULE_AUTHOR("Qiu Yi");
MODULE_DESCRIPTION("SIPC module driver");
MODULE_LICENSE("GPL");
