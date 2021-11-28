/*
 * Copyright (c) 2021, NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <fsl_iomuxc.h>
#include <fsl_gpio.h>
#include <soc.h>
#include <logging/log.h>

LOG_MODULE_REGISTER(mimxrt1160_evk, LOG_LEVEL_INF);

static int mimxrt1160_evk_init(const struct device *dev)
{
	ARG_UNUSED(dev);

	CLOCK_EnableClock(kCLOCK_Iomuxc);

	/* Enable USER_LED_CTRL1 */
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_04_GPIO9_IO03, 0U);

#if DT_NODE_HAS_STATUS(DT_NODELABEL(lpuart1), okay) && CONFIG_SERIAL
	/* LPUART1 TX/RX */
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_24_LPUART1_TXD, 0U);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_25_LPUART1_RXD, 0U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_24_LPUART1_TXD, 0x02U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_25_LPUART1_RXD, 0x02U);
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(flexcan3), okay) && CONFIG_CAN
	IOMUXC_SetPinMux(IOMUXC_GPIO_LPSR_00_FLEXCAN3_TX, 1U);
	IOMUXC_SetPinMux(IOMUXC_GPIO_LPSR_01_FLEXCAN3_RX, 1U);

	IOMUXC_SetPinConfig(IOMUXC_GPIO_LPSR_00_FLEXCAN3_TX, 0x02U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_LPSR_01_FLEXCAN3_RX, 0x02U);
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(lpspi1), okay) && CONFIG_SPI
	/* LPSPI1 SCK, PCS0, SIN, SOUT */
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_28_LPSPI1_SCK, 0U);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_29_LPSPI1_PCS0, 0U);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_30_LPSPI1_SOUT, 0U);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_31_LPSPI1_SIN, 0U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_28_LPSPI1_SCK, 0x02U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_29_LPSPI1_PCS0, 0x02U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_30_LPSPI1_SOUT, 0x02U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_31_LPSPI1_SIN, 0x02U);
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(lpi2c1), okay) && CONFIG_I2C
	/* LPI2C1 SDA, SCL */
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_08_LPI2C1_SCL, 1U);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_09_LPI2C1_SDA, 1U);
	/* Open drain, with software input on */
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_08_LPI2C1_SCL, 0x10U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_09_LPI2C1_SDA, 0x10U);
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(lpi2c5), okay) && CONFIG_FXOS8700
#if !defined(CONFIG_FXOS8700_TRIGGER_NONE)
	IOMUXC_SetPinMux(IOMUXC_GPIO_DISP_B2_13_GPIO11_IO14, 0U);
	IOMUXC_SetPinMux(IOMUXC_GPIO_DISP_B2_14_GPIO11_IO15, 0U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_DISP_B2_13_GPIO11_IO14, 0x02U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_DISP_B2_14_GPIO11_IO15, 0x02U);
#endif
	/* LPI2C5 SDA, SCL */
	IOMUXC_SetPinMux(IOMUXC_GPIO_LPSR_04_LPI2C5_SDA, 1U);
	IOMUXC_SetPinMux(IOMUXC_GPIO_LPSR_05_LPI2C5_SCL, 1U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_LPSR_04_LPI2C5_SDA, 0x20U);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_LPSR_05_LPI2C5_SCL, 0x20U);
#endif
	return 0;
}

SYS_INIT(mimxrt1160_evk_init, PRE_KERNEL_1, 0);
