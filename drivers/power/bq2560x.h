#ifndef __LINUX_bq2560x_H
#define __LINUX_bq2560x_H

/* Register 00h */
#define BQ2560X_REG_00			0x00
#define REG00_ENHIZ_MASK		GENMASK(7, 7)
#define REG00_ENHIZ_SHIFT		7
#define	REG00_HIZ_ENABLE		1
#define	REG00_HIZ_DISABLE		0

#define	REG00_STAT_CTRL_MASK		GENMASK(6, 5)
#define REG00_STAT_CTRL_SHIFT		5
#define	REG00_STAT_CTRL_STAT		0
#define	REG00_STAT_CTRL_ICHG		1
#define	REG00_STAT_CTRL_IINDPM		2
#define	REG00_STAT_CTRL_DISABLE		3

#define REG00_IINLIM_MASK		GENMASK(4, 0)
#define REG00_IINLIM_SHIFT		0
#define	REG00_IINLIM_LSB		100
#define	REG00_IINLIM_BASE		100

/* Register 01h */
#define BQ2560X_REG_01			0x01
#define REG01_PFM_DIS_MASK		GENMASK(7, 7)
#define	REG01_PFM_DIS_SHIFT		7
#define	REG01_PFM_ENABLE		0
#define	REG01_PFM_DISABLE		1

#define REG01_WDT_RESET_MASK		GENMASK(6, 6)
#define REG01_WDT_RESET_SHIFT		6
#define REG01_WDT_RESET			1

#define	REG01_OTG_CONFIG_MASK		GENMASK(5, 5)
#define	REG01_OTG_CONFIG_SHIFT		5
#define	REG01_OTG_ENABLE		1
#define	REG01_OTG_DISABLE		0

#define REG01_CHG_CONFIG_MASK		GENMASK(4, 4)
#define REG01_CHG_CONFIG_SHIFT		4
#define REG01_CHG_DISABLE		0
#define REG01_CHG_ENABLE		1

#define REG01_SYS_MINV_MASK		GENMASK(3, 1)
#define REG01_SYS_MINV_SHIFT		1

#define	REG01_MIN_VBAT_SEL_MASK		GENMASK(0, 0)
#define	REG01_MIN_VBAT_SEL_SHIFT	0
#define	REG01_MIN_VBAT_2P8V		0
#define	REG01_MIN_VBAT_2P5V		1

/* Register 0x02*/
#define BQ2560X_REG_02			0x02
#define	REG02_BOOST_LIM_MASK		GENMASK(7, 7)
#define	REG02_BOOST_LIM_SHIFT		7
#define	REG02_BOOST_LIM_0P5A		0
#define	REG02_BOOST_LIM_1P2A		1

#define	REG02_Q1_FULLON_MASK		GENMASK(6, 6)
#define	REG02_Q1_FULLON_SHIFT		6
#define	REG02_Q1_FULLON_ENABLE		1
#define	REG02_Q1_FULLON_DISABLE		0

#define REG02_ICHG_MASK			GENMASK(5, 0)
#define REG02_ICHG_SHIFT		0
#define REG02_ICHG_BASE			0
#define REG02_ICHG_LSB			60

/* Register 0x03*/
#define BQ2560X_REG_03			0x03
#define REG03_IPRECHG_MASK		GENMASK(7, 4)
#define REG03_IPRECHG_SHIFT		4
#define REG03_IPRECHG_BASE		60
#define REG03_IPRECHG_LSB		60

#define REG03_ITERM_MASK		GENMASK(3, 0)
#define REG03_ITERM_SHIFT		0
#define REG03_ITERM_BASE		60
#define REG03_ITERM_LSB			60

/* Register 0x04*/
#define BQ2560X_REG_04			0x04
#define REG04_VREG_MASK			GENMASK(7, 3)
#define REG04_VREG_SHIFT		3
#define REG04_VREG_BASE			3856
#define REG04_VREG_MAX			4624
#define REG04_VREG_LSB			32

#define	REG04_TOPOFF_TIMER_MASK		GENMASK(2, 1)
#define	REG04_TOPOFF_TIMER_SHIFT	1
#define	REG04_TOPOFF_TIMER_DISABLE	0
#define	REG04_TOPOFF_TIMER_15M		1
#define	REG04_TOPOFF_TIMER_30M		2
#define	REG04_TOPOFF_TIMER_45M		3

#define REG04_VRECHG_MASK		GENMASK(0, 0)
#define REG04_VRECHG_SHIFT		0
#define REG04_VRECHG_100MV		0
#define REG04_VRECHG_200MV		1

/* Register 0x05*/
#define BQ2560X_REG_05			0x05
#define REG05_EN_TERM_MASK		GENMASK(7, 7)
#define REG05_EN_TERM_SHIFT		7
#define REG05_TERM_ENABLE		1
#define REG05_TERM_DISABLE		0

#define REG05_WDT_MASK			GENMASK(5, 4)
#define REG05_WDT_SHIFT			4
#define REG05_WDT_DISABLE		0
#define REG05_WDT_40S			1
#define REG05_WDT_80S			2
#define REG05_WDT_160S			3
#define REG05_WDT_BASE			0
#define REG05_WDT_LSB			40

#define REG05_EN_TIMER_MASK		GENMASK(3, 3)
#define REG05_EN_TIMER_SHIFT		3
#define REG05_CHG_TIMER_ENABLE		1
#define REG05_CHG_TIMER_DISABLE		0

#define REG05_CHG_TIMER_MASK		GENMASK(2, 2)
#define REG05_CHG_TIMER_SHIFT		2
#define REG05_CHG_TIMER_5HOURS		0
#define REG05_CHG_TIMER_10HOURS		1

#define	REG05_TREG_MASK			GENMASK(1, 1)
#define	REG05_TREG_SHIFT		1
#define	REG05_TREG_90C			0
#define	REG05_TREG_110C			1

#define REG05_JEITA_ISET_MASK		GENMASK(0, 0)
#define REG05_JEITA_ISET_SHIFT		0
#define REG05_JEITA_ISET_50PCT		0
#define REG05_JEITA_ISET_20PCT		1

/* Register 0x06*/
#define BQ2560X_REG_06			0x06
#define	REG06_OVP_MASK			GENMASK(7, 6)
#define	REG06_OVP_SHIFT			0x6
#define	REG06_OVP_5P5V			0
#define	REG06_OVP_6P2V			1
#define	REG06_OVP_10P5V			2
#define	REG06_OVP_14P3V			3

#define	REG06_BOOSTV_MASK		GENMASK(5, 4)
#define	REG06_BOOSTV_SHIFT		4
#define	REG06_BOOSTV_4P85V		0
#define	REG06_BOOSTV_5V			1
#define	REG06_BOOSTV_5P15V		2
#define	REG06_BOOSTV_5P3V		3

#define	REG06_VINDPM_MASK		GENMASK(3, 0)
#define	REG06_VINDPM_SHIFT		0
#define	REG06_VINDPM_BASE		3900
#define	REG06_VINDPM_LSB		100

/* Register 0x07*/
#define BQ2560X_REG_07			0x07
#define REG07_FORCE_DPDM_MASK		GENMASK(7, 7)
#define REG07_FORCE_DPDM_SHIFT		7
#define REG07_FORCE_DPDM		1

#define REG07_TMR2X_EN_MASK		GENMASK(6, 6)
#define REG07_TMR2X_EN_SHIFT		6
#define REG07_TMR2X_ENABLE		1
#define REG07_TMR2X_DISABLE		0

#define REG07_BATFET_DIS_MASK		GENMASK(5, 5)
#define REG07_BATFET_DIS_SHIFT		5
#define REG07_BATFET_OFF		1
#define REG07_BATFET_ON			0

#define REG07_JEITA_VSET_MASK		GENMASK(4, 4)
#define REG07_JEITA_VSET_SHIFT		4
#define REG07_JEITA_VSET_4100		0
#define REG07_JEITA_VSET_VREG		1

#define	REG07_BATFET_DLY_MASK		GENMASK(3, 3)
#define	REG07_BATFET_DLY_SHIFT		3
#define	REG07_BATFET_DLY_0S		0
#define	REG07_BATFET_DLY_10S		1

#define	REG07_BATFET_RST_EN_MASK	GENMASK(2, 2)
#define	REG07_BATFET_RST_EN_SHIFT	2
#define	REG07_BATFET_RST_DISABLE	0
#define	REG07_BATFET_RST_ENABLE		1

#define	REG07_VDPM_BAT_TRACK_MASK	GENMASK(1, 0)
#define	REG07_VDPM_BAT_TRACK_SHIFT	0
#define	REG07_VDPM_BAT_TRACK_DISABLE	0
#define	REG07_VDPM_BAT_TRACK_200MV	1
#define	REG07_VDPM_BAT_TRACK_250MV	2
#define	REG07_VDPM_BAT_TRACK_300MV	3

/* Register 0x08*/
#define BQ2560X_REG_08			0x08
#define REG08_VBUS_STAT_MASK		GENMASK(7, 5)
#define REG08_VBUS_STAT_SHIFT		5
#define REG08_VBUS_TYPE_NONE		0
#define REG08_VBUS_TYPE_USB		1
#define REG08_VBUS_TYPE_ADAPTER		3
#define REG08_VBUS_TYPE_OTG		7

#define REG08_CHRG_STAT_MASK		GENMASK(4, 3)
#define REG08_CHRG_STAT_SHIFT		3
#define REG08_CHRG_STAT_IDLE		0
#define REG08_CHRG_STAT_PRECHG		1
#define REG08_CHRG_STAT_FASTCHG		2
#define REG08_CHRG_STAT_CHGDONE		3

#define REG08_PG_STAT_MASK		GENMASK(2, 2)
#define REG08_PG_STAT_SHIFT		2
#define REG08_POWER_GOOD		1

#define REG08_THERM_STAT_MASK		GENMASK(1, 1)
#define REG08_THERM_STAT_SHIFT		1

#define REG08_VSYS_STAT_MASK		GENMASK(0, 0)
#define REG08_VSYS_STAT_SHIFT		0
#define REG08_IN_VSYS_STAT		1

/* Register 0x09*/
#define BQ2560X_REG_09			0x09
#define REG09_FAULT_WDT_MASK		GENMASK(7, 7)
#define REG09_FAULT_WDT_SHIFT		7
#define REG09_FAULT_WDT			1

#define REG09_FAULT_BOOST_MASK		GENMASK(6, 6)
#define REG09_FAULT_BOOST_SHIFT		6
#define REG09_FAULT_BOOT		1

#define REG09_FAULT_CHRG_MASK		GENMASK(5, 4)
#define REG09_FAULT_CHRG_SHIFT		4
#define REG09_FAULT_CHRG_NORMAL		0
#define REG09_FAULT_CHRG_INPUT		1
#define REG09_FAULT_CHRG_THERMAL	2
#define REG09_FAULT_CHRG_TIMER		3

#define REG09_FAULT_BAT_MASK		GENMASK(3, 3)
#define REG09_FAULT_BAT_SHIFT		3
#define	REG09_FAULT_BAT_OVP		1

#define REG09_FAULT_NTC_MASK		GENMASK(2, 0)
#define REG09_FAULT_NTC_SHIFT		0
#define	REG09_FAULT_NTC_NORMAL		0
#define REG09_FAULT_NTC_WARM		2
#define REG09_FAULT_NTC_COOL		3
#define REG09_FAULT_NTC_COLD		5
#define REG09_FAULT_NTC_HOT		6

/* Register 0x0A */
#define BQ2560X_REG_0A			0x0a
#define	REG0A_VBUS_GD_MASK		GENMASK(7, 7)
#define	REG0A_VBUS_GD_SHIFT		7
#define	REG0A_VBUS_GD			1

#define	REG0A_VINDPM_STAT_MASK		GENMASK(6, 6)
#define	REG0A_VINDPM_STAT_SHIFT		6
#define	REG0A_VINDPM_ACTIVE		1

#define	REG0A_IINDPM_STAT_MASK		GENMASK(5, 5)
#define	REG0A_IINDPM_STAT_SHIFT		5
#define	REG0A_IINDPM_ACTIVE		1

#define	REG0A_TOPOFF_ACTIVE_MASK	GENMASK(3, 3)
#define	REG0A_TOPOFF_ACTIVE_SHIFT	3
#define	REG0A_TOPOFF_ACTIVE		1

#define	REG0A_ACOV_STAT_MASK		GENMASK(2, 2)
#define	REG0A_ACOV_STAT_SHIFT		2
#define	REG0A_ACOV_ACTIVE		1

#define	REG0A_VINDPM_INT_MASK		GENMASK(1, 1)
#define	REG0A_VINDPM_INT_SHIFT		1
#define	REG0A_VINDPM_INT_ENABLE		0
#define	REG0A_VINDPM_INT_DISABLE	1

#define	REG0A_IINDPM_INT_MASK		GENMASK(0, 0)
#define	REG0A_IINDPM_INT_SHIFT		0
#define	REG0A_IINDPM_INT_ENABLE		0
#define	REG0A_IINDPM_INT_DISABLE	1

#define	REG0A_INT_MASK_MASK		GENMASK(1, 0)
#define	REG0A_INT_MASK_SHIFT		0

/* Register 0x0B */
#define	BQ2560X_REG_0B			0x0b
#define	REG0B_RESET_MASK		GENMASK(7, 7)
#define	REG0B_RESET_SHIFT		7
#define	REG0B_RESET			1

#define REG0B_PN_MASK			GENMASK(6, 3)
#define REG0B_PN_SHIFT			3

#define REG0B_DEV_REV_MASK		GENMASK(1, 0)
#define REG0B_DEV_REV_SHIFT		0

struct bq2560x {
	struct i2c_client *client;
	struct gpio_desc *vbus_detect;
	struct delayed_work feed_watchdog_work;
	struct delayed_work vbus_detect_work;
};

extern void bq2560x_reset_timer(void);
extern void bq2560x_sw_reset(void);
extern void bq2560x_set_vindpm(u8 reg_val);
extern void bq2560x_termina_cur_set(u8 reg_val);
extern void bq2560x_termina_vol_set(u8 reg_val);
extern void bq2560x_init(void);
extern void bq2560x_otg_enable(int enable);
extern void bq2560x_stop_charging(u32 flag);
extern u8 bq2560x_get_sys_status(void);
extern u8 bq2560x_get_fault_val(void);
extern u8 bq2560x_get_chgcur(void);
extern void bq2560x_enable_chg(void);
extern void bq2560x_set_chg_current_limit(u32 limit);
extern void bq2560x_set_chg_current(u8 reg_val);
#endif
