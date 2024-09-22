/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    pdn_hw_mt6280_series.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines PDN HW registers for MT6280 series chips.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"

#ifndef __PDN_HW_MT6280_SERIES_H__
#define __PDN_HW_MT6280_SERIES_H__

/* MD2GSYS */

#define DRVPDN_MD2GSYS_CG_CON0          (MD2GCONFG_base+0x0000)
#define DRVPDN_MD2GSYS_CG_CON2          (MD2GCONFG_base+0x0008)
#define DRVPDN_MD2GSYS_CG_CON4          (MD2GCONFG_base+0x0030)

#define DRVPDN_MD2GSYS_CG_SET0          (MD2GCONFG_base+0x0010)
#define DRVPDN_MD2GSYS_CG_SET2          (MD2GCONFG_base+0x0018)
#define DRVPDN_MD2GSYS_CG_SET4          (MD2GCONFG_base+0x0034)

#define DRVPDN_MD2GSYS_CG_CLR0          (MD2GCONFG_base+0x0020)
#define DRVPDN_MD2GSYS_CG_CLR2          (MD2GCONFG_base+0x0028)
#define DRVPDN_MD2GSYS_CG_CLR4          (MD2GCONFG_base+0x0038)

#define MD2GSYS_CG_CON0_GCC         0x0002
#define MD2GSYS_CG_CON0_IRDMA       0x0040
#define MD2GSYS_CG_CON0_TXBUF       0x0100
#define MD2GSYS_CG_CON0_RXBUF       0x0200
#define MD2GSYS_CG_CON0_IRDBG       0x2000
#define MD2GSYS_CG_CON0_AHB2DSPIO   0x8000

#define MD2GSYS_CG_CON2_APC_PRE      0x0010
#define MD2GSYS_CG_CON2_VAFE         0x0100
#define MD2GSYS_CG_CON2_BFE          0x0200

#define MD2GSYS_CG_CON4_APC          0x0010

/* MD sys global */

#define DRVPDN_MD_PWR_GLOBAL_CON0  (CONFIG_base+0x00A0)

#define DRVPDN_MD_PWR_GLOBAL_SET0  (CONFIG_base+0x00A4)

#define DRVPDN_MD_PWR_GLOBAL_CLR0  (CONFIG_base+0x00A8)

#define MD_PWR_GLOBAL_CON0_SFC             0x00000002
#define MD_PWR_GLOBAL_CON0_TRACE           0x00000010
#define MD_PWR_GLOBAL_CON0_LMU             0x00000020
#define MD_PWR_GLOBAL_CON0_ALC             0x00000040
#define MD_PWR_GLOBAL_CON0_ABM             0x00000080
#define MD_PWR_GLOBAL_CON0_ADOE            0x00000100
#define MD_PWR_GLOBAL_CON0_TIU_BUFF        0x00000200
#define MD_PWR_GLOBAL_CON0_PF_BUFF         0x00000400
#define MD_PWR_GLOBAL_CON0_BOOT_SLV        0x00000800
#define MD_PWR_GLOBAL_CON0_PFC             0x00001000

#define DRVPDN_MD_NONPWR_GLOBAL_CON0  (CONFIG_base+0x00C0)

#define DRVPDN_MD_NONPWR_GLOBAL_SET0  (CONFIG_base+0x00C4)

#define DRVPDN_MD_NONPWR_GLOBAL_CLR0  (CONFIG_base+0x00C8)

#define MD_NONPWR_GLOBAL_CON0_UART            0x00000001
#define MD_NONPWR_GLOBAL_CON0_DBG             0x00000002
#define MD_NONPWR_GLOBAL_CON0_OSTIMER         0x00000004
#define MD_NONPWR_GLOBAL_CON0_SEJ             0x00000008
#define MD_NONPWR_GLOBAL_CON0_SDCTL           0x00000010
#define MD_NONPWR_GLOBAL_CON0_DMA             0x00000020
#define MD_NONPWR_GLOBAL_CON0_SIM1            0x00000040
#define MD_NONPWR_GLOBAL_CON0_SIM2            0x00000080
#define MD_NONPWR_GLOBAL_CON0_MBIST           0x00000100

/* MODEM sys */
#define DRVPDN_MODEM_CG_CON0         (MDCONFIG_base+0x0000)
#define DRVPDN_MODEM_CG_CON2         (MDCONFIG_base+0x0008)
#define DRVPDN_MODEM_CG_CON4         (MDCONFIG_base+0x0088)

#define DRVPDN_MODEM_CG_SET0         (MDCONFIG_base+0x0020)
#define DRVPDN_MODEM_CG_SET2         (MDCONFIG_base+0x0028)
#define DRVPDN_MODEM_CG_SET4         (MDCONFIG_base+0x00A8)

#define DRVPDN_MODEM_CG_CLR0         (MDCONFIG_base+0x0010)
#define DRVPDN_MODEM_CG_CLR2         (MDCONFIG_base+0x0018)
#define DRVPDN_MODEM_CG_CLR4         (MDCONFIG_base+0x0098)

#define MODEM_CG_CON0_BSI_PMIC       0x00000004
#define MODEM_CG_CON0_BPI_PMIC       0x00000008
#define MODEM_CG_CON0_BSI_3G         0x00000010
#define MODEM_CG_CON0_BPI_3G         0x00000020
#define MODEM_CG_CON0_WTIMER         0x00000040
#define MODEM_CG_CON0_AFC_3G         0x00000080
#define MODEM_CG_CON0_PFC_DEC        0x00000100
#define MODEM_CG_CON0_BYC_ACC        0x00000200
#define MODEM_CG_CON0_ATB            0x20000000
#define MODEM_CG_CON0_PFC_ENC        0x40000000

#define MODEM_CG_CON2_TDMA           0x00000001
#define MODEM_CG_CON2_BSI_2G_T       0x00000004
#define MODEM_CG_CON2_BPI_2G_T       0x00000008
#define MODEM_CG_CON2_AFC_2G_T       0x00000010
#define MODEM_CG_CON2_DIVIDER        0x00000800
#define MODEM_CG_CON2_FCS            0x00001000
#define MODEM_CG_CON2_GCU            0x00002000

#define MODEM_CG_CON4_BSI_2G         0x00000004
#define MODEM_CG_CON4_BPI_2G         0x00000008
#define MODEM_CG_CON4_AFC_2G         0x00000010

/* AP sys */

#define DRVPDN_AP_CG_CON0      (AP_CONFIG_base+0x0000)

#define DRVPDN_AP_CG_SET0      (AP_CONFIG_base+0x0004)

#define DRVPDN_AP_CG_CLR0      (AP_CONFIG_base+0x0008)

#define AP_CG_CON0_EFUSE_MACRO       0x00000001
#define AP_CG_CON0_EFUSE             0x00000002
#define AP_CG_CON0_I2C               0x00000004
#define AP_CG_CON0_AP_UART1          0x00000008
#define AP_CG_CON0_AP_UART2          0x00000010
#define AP_CG_CON0_NFI               0x00000020
#define AP_CG_CON0_HIF               0x00000040
#define AP_CG_CON0_AP_USB            0x00000080
#define AP_CG_CON0_AP_DMA            0x00000100
#define AP_CG_CON0_AP_DBG            0x00000200
#define AP_CG_CON0_MSDC              0x00000400
#define AP_CG_CON0_AP_CCIF           0x00000800
#define AP_CG_CON0_LCD               0x00001000
#define AP_CG_CON0_PWM               0x00002000
#define AP_CG_CON0_SPI               0x00004000
#define AP_CG_CON0_SPI_PAD           0x00008000
#define AP_CG_CON0_AP_TRACE          0x00010000
#define AP_CG_CON0_TIU               0x00020000
#define AP_CG_CON0_DBG_FBCLK         0x00040000

#endif  /* !__PDN_HW_MT6280_SERIES_H__ */

