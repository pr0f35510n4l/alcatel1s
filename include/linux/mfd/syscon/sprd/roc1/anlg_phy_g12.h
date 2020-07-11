/*
 * Copyright (C) 2018 Spreadtrum Communications Inc.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 * updated at 2018-06-28 19:05:47
 *
 */


#ifndef ANLG_PHY_G12_H
#define ANLG_PHY_G12_H



#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ANA_BB_PWR_CTRL      (0x0000)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ANA_BB_RST_CTRL      (0x0004)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ANA_BB_EN_CTRL       (0x0008)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_CTRL2          (0x000C)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_CTRL2           (0x0010)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_CTRL0          (0x0014)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_CTRL1          (0x0018)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_BIST_CTRL      (0x001C)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_CTRL0           (0x0020)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_CTRL1           (0x0024)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_BIST_CTRL       (0x0028)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_CTRL0           (0x002C)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_CTRL1           (0x0030)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_CTRL2           (0x0034)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_BIST_CTRL       (0x0038)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TEST_CLK_CTRL        (0x003C)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CTRL0         (0x0040)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CTRL1         (0x0044)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CTRL2         (0x0048)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CTRL3         (0x004C)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_PLL_RESERVED         (0x0050)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_RESERVED       (0x0054)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_RESERVED        (0x0058)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_RESERVED        (0x005C)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_RESERVED      (0x0060)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_PERFOR         (0x0064)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_PERFOR          (0x0068)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_PERFOR          (0x006C)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_PERFOR        (0x0070)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_BIST_CTRL       (0x0074)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_CTRL0           (0x0078)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_CTRL1           (0x007C)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_CTRL2           (0x0080)
#define REG_ANLG_PHY_G12_ANALOG_PLL_TOP_REG_SEL_CFG_0        (0x0084)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ANA_BB_PWR_CTRL */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_PD                BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_PD                 BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_PD                 BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_PD               BIT(1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_PD                 BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ANA_BB_RST_CTRL */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_RST               BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_RST                BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_RST                BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_RST              BIT(1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_RST                BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ANA_BB_EN_CTRL */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_CLKOUT_EN          BIT(28)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_DIV1_EN          BIT(27)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_DIV2_EN          BIT(26)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_DIV3_EN          BIT(25)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CLKOUT_EN        BIT(24)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ANALOG_TESTMUX(x)       (((x) & 0xFFFF) << 8)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_POSTDIV            BIT(7)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_POSTDIV           BIT(6)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_OD_TWPLL_CLKOUT_EN      BIT(5)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_OD_LPLL_CLKOUT_EN       BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_OD_GPLL_CLKOUT_EN       BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_OD_ISPPLL_CLKOUT_EN     BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_CLKOUT_EN          BIT(1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_OD_APLL_CLKOUT_EN       BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_CTRL2 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_CLKOUT_EN         BIT(6)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_DIV1_EN           BIT(5)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_DIV2_EN           BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_DIV3_EN           BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_DIV5_EN           BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_DIV7_EN           BIT(1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_LOCK_DONE         BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_CTRL2 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_CLKOUT_EN          BIT(5)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_DIV1_EN            BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_DIV2_EN            BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_DIV3_EN            BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_DIV5_EN            BIT(1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_LOCK_DONE          BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_CTRL0 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_N(x)              (((x) & 0x7FF) << 10)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_IBIAS(x)          (((x) & 0x3) << 8)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_LPF(x)            (((x) & 0x7) << 5)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_SDM_EN            BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_MOD_EN            BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_DIV_S             BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_REF_SEL(x)        (((x) & 0x3))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_CTRL1 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_NINT(x)           (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_KINT(x)           (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_BIST_CTRL */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_BIST_EN           BIT(24)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_BIST_CTRL(x)      (((x) & 0xFF) << 16)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_BIST_CNT(x)       (((x) & 0xFFFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_CTRL0 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_N(x)               (((x) & 0x7FF) << 10)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_IBIAS(x)           (((x) & 0x3) << 8)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_LPF(x)             (((x) & 0x7) << 5)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_SDM_EN             BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_MOD_EN             BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_DIV_S              BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_REF_SEL(x)         (((x) & 0x3))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_CTRL1 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_NINT(x)            (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_KINT(x)            (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_BIST_CTRL */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_BIST_EN            BIT(24)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_BIST_CTRL(x)       (((x) & 0xFF) << 16)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_BIST_CNT(x)        (((x) & 0xFFFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_CTRL0 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_N(x)               (((x) & 0x7FF) << 9)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_IBIAS(x)           (((x) & 0x3) << 7)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_LPF(x)             (((x) & 0x7) << 4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_SDM_EN             BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_MOD_EN             BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_DIV_S              BIT(1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_REF_SEL            BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_CTRL1 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_NINT(x)            (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_KINT(x)            (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_CTRL2 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_POSTDIV            BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_LOCK_DONE          BIT(1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_LOCK_DONE          BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_BIST_CTRL */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_BIST_EN            BIT(24)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_BIST_CTRL(x)       (((x) & 0xFF) << 16)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_BIST_CNT(x)        (((x) & 0xFFFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TEST_CLK_CTRL */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TEST_CLK_EN             BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TEST_CLK_DIV(x)         (((x) & 0x3))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CTRL0 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_N(x)             (((x) & 0x7FF) << 5)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_IBIAS(x)         (((x) & 0x3) << 3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_LPF(x)           (((x) & 0x7))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CTRL1 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_NINT(x)          (((x) & 0x7F) << 25)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_KINT(x)          (((x) & 0x7FFFFF) << 2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_SDM_EN           BIT(1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_MOD_EN           BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CTRL2 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_DIV_S            BIT(11)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_REF_SEL          BIT(10)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_BIST_EN          BIT(9)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_BIST_CTRL(x)     (((x) & 0xFF) << 1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_POSTDIV          BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CTRL3 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_BIST_CNT(x)      (((x) & 0xFFFF) << 1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_LOCK_DONE        BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_PLL_RESERVED */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ANALOG_PLL_RESERVED(x)  (((x) & 0x3FFFFFFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_RESERVED */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_SSC_CTRL(x)       (((x) & 0xFF) << 11)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_RESERVED(x)       (((x) & 0x7FF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_RESERVED */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_SSC_CTRL(x)        (((x) & 0xFF) << 11)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_RESERVED(x)        (((x) & 0x7FF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_RESERVED */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_RESERVED(x)        (((x) & 0x7FF) << 8)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_SSC_CTRL(x)        (((x) & 0xFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_RESERVED */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_RESERVED(x)      (((x) & 0x7FF) << 8)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_SSC_CTRL(x)      (((x) & 0xFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_PERFOR */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_ICP(x)            (((x) & 0x7) << 10)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_CP_EN             BIT(9)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_LDO_TRIM(x)       (((x) & 0xF) << 5)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_VCO_TEST_EN       BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_FBDIV_EN          BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_CP_OFFSET(x)      (((x) & 0x3) << 1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_TWPLL_FREQ_DOUBLE_EN    BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_PERFOR */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_ICP(x)             (((x) & 0x7) << 10)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_CP_EN              BIT(9)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_LDO_TRIM(x)        (((x) & 0xF) << 5)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_VCO_TEST_EN        BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_FBDIV_EN           BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_CP_OFFSET(x)       (((x) & 0x3) << 1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_LPLL_FREQ_DOUBLE_EN     BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_PERFOR */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_ICP(x)             (((x) & 0x7) << 10)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_CP_EN              BIT(9)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_LDO_TRIM(x)        (((x) & 0xF) << 5)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_VCO_TEST_EN        BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_FBDIV_EN           BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_CP_OFFSET(x)       (((x) & 0x3) << 1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_GPLL_FREQ_DOUBLE_EN     BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_PERFOR */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_ICP(x)           (((x) & 0x7) << 10)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CP_EN            BIT(9)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_LDO_TRIM(x)      (((x) & 0xF) << 5)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_VCO_TEST_EN      BIT(4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_FBDIV_EN         BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_CP_OFFSET(x)     (((x) & 0x3) << 1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_ISPPLL_FREQ_DOUBLE_EN   BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_BIST_CTRL */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_BIST_CTRL(x)       (((x) & 0xFF) << 17)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_BIST_EN            BIT(16)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_BIST_CNT(x)        (((x) & 0xFFFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_CTRL0 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_NINT(x)            (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_KINT(x)            (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_CTRL1 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_LPF(x)             (((x) & 0x7) << 20)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_MOD_EN             BIT(19)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_N(x)               (((x) & 0x7FF) << 8)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_POSTDIV            BIT(7)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_ICP(x)             (((x) & 0x7) << 4)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_REF_SEL            BIT(3)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_DIV_S              BIT(2)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_IBIAS(x)           (((x) & 0x3))

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_CTRL2 */

#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_RESERVED(x)        (((x) & 0x7FF) << 19)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_SDM_EN             BIT(18)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_CP_EN              BIT(17)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_CP_OFFSET(x)       (((x) & 0x3) << 15)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_FBDIV_EN           BIT(14)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_FREQ_DOUBLE_EN     BIT(13)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_LDO_TRIM(x)        (((x) & 0xF) << 9)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_SSC_CTRL(x)        (((x) & 0xFF) << 1)
#define BIT_ANLG_PHY_G12_ANALOG_PLL_TOP_APLL_VCO_TEST_EN        BIT(0)

/* REG_ANLG_PHY_G12_ANALOG_PLL_TOP_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_TWPLL_PD        BIT(22)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_LPLL_PD         BIT(21)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_GPLL_PD         BIT(20)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_ISPPLL_PD       BIT(19)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_APLL_PD         BIT(18)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_TWPLL_RST       BIT(17)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_LPLL_RST        BIT(16)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_GPLL_RST        BIT(15)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_ISPPLL_RST      BIT(14)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_APLL_RST        BIT(13)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_GPLL_CLKOUT_EN  BIT(12)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_ISPPLL_DIV2_EN  BIT(11)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_ISPPLL_DIV3_EN  BIT(10)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV1_EN   BIT(9)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV2_EN   BIT(8)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV3_EN   BIT(7)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV5_EN   BIT(6)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV1_EN    BIT(5)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV2_EN    BIT(4)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV3_EN    BIT(3)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV5_EN    BIT(2)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_TWPLL_REF_SEL   BIT(1)
#define BIT_ANLG_PHY_G12_DBG_SEL_ANALOG_PLL_TOP_LPLL_REF_SEL    BIT(0)


#endif /* ANLG_PHY_G12_H */


