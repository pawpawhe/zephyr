/*
 * Copyright (c) 2018, NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include "device_imx.h"

static int udoo_neo_full_m4_init(const struct device *dev)
{
	ARG_UNUSED(dev);

#if DT_NODE_HAS_STATUS(DT_NODELABEL(gpio4), okay)
	/* GPIO4_IO06 pin mux configuration (red LED) */
	IOMUXC_SW_MUX_CTL_PAD_NAND_DATA02 =
				IOMUXC_SW_MUX_CTL_PAD_NAND_DATA02_MUX_MODE(5);
	IOMUXC_SW_PAD_CTL_PAD_NAND_DATA02 =
				IOMUXC_SW_PAD_CTL_PAD_NAND_DATA02_PUE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_NAND_DATA02_PKE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_NAND_DATA02_SPEED(2) |
				IOMUXC_SW_PAD_CTL_PAD_NAND_DATA02_DSE(6);
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(uart5), okay) && CONFIG_SERIAL
	/* UART5 pin mux configuration */
	IOMUXC_SW_MUX_CTL_PAD_SD4_DATA4 =
				IOMUXC_SW_MUX_CTL_PAD_SD4_DATA4_MUX_MODE(2);
	IOMUXC_SW_MUX_CTL_PAD_SD4_DATA5 =
				IOMUXC_SW_MUX_CTL_PAD_SD4_DATA5_MUX_MODE(2);
	IOMUXC_SW_PAD_CTL_PAD_SD4_DATA4 =
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA4_PKE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA4_PUE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA4_PUS(2)   |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA4_SPEED(2) |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA4_DSE(6)   |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA4_SRE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA4_HYS_MASK;
	IOMUXC_SW_PAD_CTL_PAD_SD4_DATA5 =
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA5_PKE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA5_PUE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA5_PUS(2)   |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA5_SPEED(2) |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA5_DSE(6)   |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA5_SRE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_SD4_DATA5_HYS_MASK;
	IOMUXC_UART5_IPP_UART_RXD_MUX_SELECT_INPUT =
			IOMUXC_UART5_IPP_UART_RXD_MUX_SELECT_INPUT_DAISY(0);
#endif

	return 0;
}

SYS_INIT(udoo_neo_full_m4_init, PRE_KERNEL_1, 0);
