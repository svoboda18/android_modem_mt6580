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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   m12198.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *   MIPI feature
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime:  $
 * $Log:      $
 *
 * 09 24 2015 siyu.li
 * [MOLY00128208] [Rainier][MT6580] MIPI Driver Porting
 * .2G MIPI DRDI support
 *
 * 12 09 2014 sherman.chung
 * [MOLY00087046] [MML1] move MIPI initial  CW Table to MML1
 * .
 *
 * 11 03 2014 yi-ying.lin
 * [MOLY00082836] [L1D][Modify] MT6735 L1D driver developement
 * 	.
 *
 * 06 17 2014 yi-ying.lin
 * [MOLY00068792] [L1D][Modify] Modify DT-coexistence and provide 2G RX status to LTE feature option
 * 	.
 *
 * 06 11 2014 sherman.chung
 * [MOLY00069147] [MT6290][L1D] Add 2G DRDI feature
 * .
 *
 * 06 10 2014 yi-ying.lin
 * [MOLY00068792] [L1D][Modify] Modify DT-coexistence and provide 2G RX status to LTE feature option
 * Rollback //MOLY/TRUNK/MOLY/mcu/interface/modem/l1/gsm/external/l1cal.h to revision 17
 *
 * 05 29 2014 yi-ying.lin
 * [MOLY00067365] [L1D][Modify] MT6752 L1D driver developement.
 *
 * 05 08 2014 sherman.chung
 * [MOLY00064465] [MT6595][L1D] Improve 2G MIPI suppoert ability
 * .
 *
 * 04 15 2014 ola.lee
 * [MOLY00062691] [L1D] Improve 2G MIPI Interslot Ramping Performance
 * 	.
 *
 * 04 08 2014 sherman.chung
 * [MOLY00061577] [MT6592][TDs][CMCC case][DT23G][8.4.1.35][M]fail
 * .
 *
 * 03 13 2014 yi-ying.lin
 * [MOLY00059400] [L1D][Modify] DT-coexistence L1D control patch back
 * 	.
 *
 * 01 08 2014 vend_sherman.chung
 * [MOLY00052619] [MT6290][L1D] Update MIPI control table sructure
 * .
 *
 * 01 07 2014 vend_sherman.chung
 * [MOLY00052619] [MT6290][L1D] Update MIPI control table sructure
 * .
 *
 * 12 19 2013 vend_sherman.chung
 * [MOLY00049822] [MT6290][MML1] Re-organize VMIPI enable control flow with 2/3/4G
 * .
 *
 * 12 16 2013 hosen.chen
 * [MOLY00046159] [L1D][Modify] Check in code of MT6595 2G modem driver modification
 * 	.
 *
 * 10 28 2013 vend_sherman.chung
 * [MOLY00043231] [MT6290] Add 2G MIPI Control table store at NVRAM feature
 * .
 *
 * 10 24 2013 vend_sherman.chung
 * [MOLY00043231] [MT6290] Add 2G MIPI Control table store at NVRAM feature
 * .
 *
 * 09 14 2013 yuyang.hsiao
 * [MOLY00037929] [L1D] Fix MIPI build error
 * 	.
 *
 * 08 12 2013 chunyen.wu
 * [MOLY00033346] [L1D][Modify] MIPI Power on and off modify
 * .
 *
 * 07 17 2013 chunyen.wu
 * [MOLY00030116] [L1D][Modify] MIPI load on MT6290
 * .
 *
 * 07 17 2013 chunyen.wu
 * [MOLY00030116] [L1D][Modify] MIPI load on MT6290
 * .
 *
 *******************************************************************************/

#include "l1d_cid.h"
#include "l1d_reg.h"
#include "l1d_custom_rf.h"
#include "l1d_rf.h"
#include "l1d_data.h"
#include "l1d_mipi.h"
#include "l1d_mipi_data.h"
#include "m12190.h"


#if IS_MIPI_SUPPORT
#include "l1d_custom_mipi.h"
#include "dcl.h"

sMIPISETTING l1d_mipi;  // MIPI only

const char is_2g_mipi_enable=IS_2G_MIPI_ENABLE;

/*----------------------------------------*/
/* MIPI Power on/off Table                */
/*----------------------------------------*/

#define MIPI_POWERON_NUM        (sizeof(MIPI_POWERON_TABLE) /sizeof(sGGE_MIPIDATA))
#define MIPI_POWEROFF_NUM       (sizeof(MIPI_POWEROFF_TABLE)/sizeof(sGGE_MIPIDATA))

/*BSI Readback Common*/
#define MASK(n)                          ((1<<n)-1)
#define REG_SET(val,off,len)             (((val)&(MASK(len)))<<(off))

const sGGE_MIPIDATA MIPI_POWERON_TABLE[] =
{
      /*    No.	  elm type	      ,  port select		  ,  data format			   ,usid		           , address   ,data 	*/
   //  {  /*  0 */  GGE_MIPI_ASM ,  GGE_MIPI_PORT0	  ,  GGE_MIPI_REG_W 		   ,MIPI_USID_ASM0 , 0x1C        , 0x38 },
     {  /*  0 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x00, 0x2F }, 
     {  /*  1 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x07, 0xC0 }, 
     {  /*  2 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x0B, 0x01 }, 
     {  /*  3 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x20, 0xEF }, 
     {  /*  4 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x21, 0xA5 }, 
     {  /*  5 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x22, 0xE7 }, 
     {  /*  6 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x23, 0x7C }, 
     {  /*  7 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x24, 0x00 }, 
     {  /*  8 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x26, 0x2C }, 
     {  /*  9 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x27, 0xCF }, 
     {  /* 10 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x28, 0x93 }, 
     {  /* 11 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x29, 0x70 }, 
     {  /* 12 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x2A, 0x0B }, 
     {  /* 13 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x2C, 0xAF }, 
     {  /* 14 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x2D, 0xAF }, 
     {  /* 15 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x2E, 0xCB }, 
     {  /* 16 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x2F, 0x7F }, 
     {  /* 17 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x30, 0x2E }, 
     {  /* 18 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x31, 0x1F }, 
     {  /* 19 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x32, 0x4C }, 
     {  /* 20 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x33, 0x0F }, 
     {  /* 21 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x34, 0x18 }, 
     {  /* 22 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x35, 0x19 }, 
     {  /* 23 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x36, 0x10 }, 
     {  /* 24 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x38, 0xEF }, 
     {  /* 25 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x3A, 0x47 }, 
     {  /* 26 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x3B, 0x7C }, 
     {  /* 27 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x3C, 0x00 }, 
     {  /* 28 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x3E, 0x2C }, 
     {  /* 29 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x3F, 0xDF }, 
     {  /* 30 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x40, 0x93 }, 
     {  /* 31 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x41, 0x70 }, 
     {  /* 32 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x42, 0x0B }, 
     {  /* 33 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x44, 0xCF }, 
     {  /* 34 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x45, 0x6B }, 
     {  /* 35 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x46, 0x30 }, 
     {  /* 36 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x47, 0x73 }, 
     {  /* 37 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x49, 0x1F }, 
     {  /* 38 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x4A, 0x4C }, 
     {  /* 39 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x4B, 0xCA }, 
     {  /* 40 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x4C, 0x80 }, 
     {  /* 41 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x4D, 0x60 }, 
     {  /* 42 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x4E, 0x10 }, 
     {  /* 43 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x50, 0xEF }, 
     {  /* 44 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x51, 0x43 }, 
     {  /* 45 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x52, 0x58 }, 
     {  /* 46 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x53, 0x2B }, 
     {  /* 47 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x54, 0x0A }, 
     {  /* 48 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x55, 0x15 }, 
     {  /* 49 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x56, 0x2C }, 
     {  /* 50 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x57, 0x07 }, 
     {  /* 51 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x58, 0x00 }, 
     {  /* 52 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x59, 0x00 }, 
     {  /* 53 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x5A, 0x00 }, 
     {  /* 54 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x5C, 0xCF }, 
     {  /* 55 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x5D, 0x2D }, 
     {  /* 56 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x5E, 0x14 }, 
     {  /* 57 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x5F, 0x7F }, 
     {  /* 58 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x60, 0x0C }, 
     {  /* 59 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x62, 0x4C }, 
     {  /* 60 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x63, 0x0E }, 
     {  /* 61 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x64, 0x00 }, 
     {  /* 62 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x65, 0x00 }, 
     {  /* 63 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x66, 0x19 }, 
     {  /* 64 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x68, 0xEF }, 
     {  /* 65 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x69, 0x03 }, 
     {  /* 66 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x6B, 0x27 }, 
     {  /* 67 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x6C, 0x0A }, 
     {  /* 68 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x6D, 0x07 }, 
     {  /* 69 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x6E, 0x28 }, 
     {  /* 70 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x6F, 0x03 }, 
     {  /* 71 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x70, 0x00 }, 
     {  /* 72 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x71, 0x00 }, 
     {  /* 73 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x72, 0x00 }, 
     {  /* 74 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x84, 0x71 }, 
     {  /* 75 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x89, 0x05 }, 
     {  /* 76 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x8B, 0x15 }, 
     {  /* 77 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x8C, 0xC0 }, 
     {  /* 78 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x8E, 0x00 }, 
     {  /* 79 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x8F, 0x00 }, 
     {  /* 80 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x90, 0x90 }, 
     {  /* 81 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x91, 0x46 }, 
     {  /* 82 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x92, 0x3D }, 
     {  /* 83 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x93, 0x1D }, 
     {  /* 84 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x94, 0x18 }, 
     {  /* 85 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x95, 0x96 }, 
     {  /* 86 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x96, 0x08 }, 
     {  /* 87 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x98, 0x9A }, 
     {  /* 88 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x99, 0xF8 }, 
     {  /* 89 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x9A, 0x1F }, 
     {  /* 90 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x9B, 0x00 }, 
     {  /* 91 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x9C, 0x00 }, 
     {  /* 92 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x9D, 0x48 }, 
     {  /* 93 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x9E, 0x70 }, 
     {  /* 94 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0x9F, 0x38 }, 
     {  /* 95 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xA5, 0x15 }, 
     {  /* 96 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xA6, 0xC0 }, 
     {  /* 97 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xA8, 0x00 }, 
     {  /* 98 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xA9, 0x00 }, 
     {  /* 99 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xAA, 0x90 }, 
     {  /*100 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xAB, 0x52 }, 
     {  /*101 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xAC, 0x39 },
     {  /*102 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xAD, 0x25 }, 
     {  /*103 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xAE, 0xB8 },
     {  /*104 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xB0, 0x07 }, 
     {  /*105 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xB2, 0x99 },
     {  /*106 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xB3, 0xF8 }, 
     {  /*107 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xB4, 0x1F },
     {  /*108 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xB5, 0x00 }, 
     {  /*109 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xB6, 0x00 },
     {  /*110 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xB7, 0x50 }, 
     {  /*111 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xC7, 0x0E },
     {  /*112 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xC9, 0xAC }, 
     {  /*113 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xCB, 0x05 },
     {  /*114 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xD5, 0xCA }, 
     {  /*115 */  GGE_MIPI_PA ,  GGE_MIPI_PORT0     ,  GGE_MIPI_REG_W_EXT_1ST            ,MIPI_USID_PA0 ,0xD8, 0xCA },
};

const sGGE_MIPIDATA MIPI_POWEROFF_TABLE[] =
{
     /*	  No.	 elm type		 ,	port select 		 ,	data format 			  ,usid 				  , address   ,data    */
   // {  /*  0 */	GGE_MIPI_ASM ,	GGE_MIPI_PORT0	 ,	GGE_MIPI_REG_W			  ,MIPI_USID_ASM0 , 0x1C		, 0x38 , },
};



/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void normalize_tq( signed int src_tq, signed int *dst_tq,signed short tq_wrap )
{  signed int dst1_tq = src_tq;
   if( dst1_tq>TQ_VALIDATE ||
       dst1_tq<=(signed short)(TQ_VALIDATE-tq_wrap) )
   {  dst1_tq  = TQ_MAXIMUM;   }
   else if(dst1_tq<0)
   {  dst1_tq += tq_wrap;  }

   *dst_tq = dst1_tq;
}

#define  NORMALIZE_TQ( src_tq, dst_tq, tq_wrap)      normalize_tq( src_tq, &dst_tq, tq_wrap)


#define  HWRITE_1_SDATA( ctrl1, data1 )                                       \
{  HW_WRITE_BSI_DATA_1( data_idx, ((ctrl1)), (data1) );                       \
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_MIPI_DRDI_SUPPORT
void L1D_MIPI_Table_Update(void)
{
   unsigned char band=0;

   for (band=FrequencyBand1900;band>0;band--)
   {
     if(GGE_MIPI_CTRL_TABLE[band] != 0)
     {
         GGE_MIPI_CTRL_TABLE_RX_EVENT[band]     = GGE_MIPI_CTRL_TABLE[band]->mipi_rx_ctrl_table.mipi_rxctrl_event;
         GGE_MIPI_CTRL_TABLE_RX_DATA[band]      = GGE_MIPI_CTRL_TABLE[band]->mipi_rx_ctrl_table.mipi_rxctrl_data;
         GGE_MIPI_CTRL_TABLE_TX_EVENT[band]     = GGE_MIPI_CTRL_TABLE[band]->mipi_tx_ctrl_table.mipi_txctrl_event;
         GGE_MIPI_CTRL_TABLE_TX_DATA[band]      = GGE_MIPI_CTRL_TABLE[band]->mipi_tx_ctrl_table.mipi_txctrl_data;         
         GGE_MIPI_CTRL_TABLE_PA_DATA[band]      = &GGE_MIPI_CTRL_TABLE[band]->mipi_tx_ctrl_table.mipi_txctrl_pa_data;
         GGE_MIPI_CTRL_TABLE_TXMID_EVENT[band]  = (sGGE_MIPIEVENT*)GGE_MIPI_CTRL_TABLE[band]->mipi_txmid_ctrl_table.mipi_txmidctrl_event;
         GGE_MIPI_CTRL_TABLE_TXMID_DATA[band]   = GGE_MIPI_CTRL_TABLE[band]->mipi_txmid_ctrl_table.mipi_txmidctrl_data;
     }
   }
   
}
#endif

void L1D_MIPI_PM_BOUND_EVENT( void )
{
   unsigned short         idx,idx_1,large_SR3=0,delta=0;
   short                  tq;
   sGGE_MIPIEVENT*       mipi_rx_cwin_event;

   for( idx_1=1; idx_1<5 ; idx_1++)
   {
      large_SR3=0;
      mipi_rx_cwin_event = GGE_MIPI_CTRL_TABLE_RX_EVENT[idx_1];
      for( idx=0 ; idx<GGE_MIPI_RTX_EVENT_NUM ; idx++, mipi_rx_cwin_event++ )
      {
         if( mipi_rx_cwin_event->mipi_evt_type == GGE_MIPI_TRX_OFF )
         {
            tq = (mipi_rx_cwin_event->mipi_evt_timing);
            if(tq>large_SR3)
            large_SR3=tq;
         }
      }

      delta = (large_SR3>QR_BOFF_2_IDLE) ? (large_SR3-QR_BOFF_2_IDLE+2) : 0;
      l1d_mipi.pm_delta[idx_1] = delta;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_MIPI_Init_Data( void )
{
   l1d_mipi.is_init        = 0;
   l1d_mipi.tx_mid_idx     = 0;
   l1d_mipi.cur_slot       = 0;
   L1D_MIPI_PM_BOUND_EVENT();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_MIPI_Init_BSI( void )
{
   if(is_2g_mipi_enable)
   {
      HW_WRITE( BSI_IO_CON        , 0x2       );      //UMTS_BSI_IO_CON
      HW_WRITE( BSI_MIPI_CON, SCTRL_MIPI_MAIN ); /* Dual BSI MIPI Control */
   }
}

void L1D_MIPI_Init( void )
{
   if(is_2g_mipi_enable)
   {
      L1D_MIPI_Init_Data();
      L1D_MIPI_Init_BSI();

      l1d_mipi.is_init = 1;
      L1D_MIPI_PowerOn();
      l1d_mipi.is_init = 0;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_PMU_VMIPISetting( char vmipion )
{
   //Do not support in MT6580
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_MIPI_TX_BSI_DISABLE( unsigned short win )
{
   if(is_2g_mipi_enable)
   {      
      unsigned long  bsi_ena  = HW_READ( BSI_ENA  );
      unsigned long  bsi_ena1 = HW_READ( BSI_ENA1 );
      unsigned long  en_reg_idx, en_reg_bit;
      unsigned short i;
      #ifdef BSI_ENA2
         "Please check L1D_MIPI_TX_BSI_DISABLE() porting @ m12198.c"
      #endif

      for( i=0; i<GGE_MIPI_RTX_EVENT_NUM;   i++ )
      {
         en_reg_idx = GGE_MIPI_RTX_EVIDX(win,i)>>5;
         en_reg_bit = GGE_MIPI_RTX_EVIDX(win,i)&0x1F;
         switch( en_reg_idx )
         {
            case 0 : bsi_ena  &= ~(1<<en_reg_bit);
            case 1 : bsi_ena1 &= ~(1<<en_reg_bit);
         }
      }

      for( i=0; i<GGE_MIPI_TXMID_EVENT_NUM; i++ )
      {
         en_reg_idx = GGE_MIPI_TXMID_EVIDX(win,i)>>5;
         en_reg_bit = GGE_MIPI_TXMID_EVIDX(win,i)&0x1F;
         switch( en_reg_idx )
         {
            case 0 : bsi_ena  &= ~(1<<en_reg_bit);
            case 1 : bsi_ena1 &= ~(1<<en_reg_bit);
         }
      }

      HW_WRITE( BSI_ENA  , bsi_ena );
      HW_WRITE( BSI_ENA1 , bsi_ena1 );
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_MIPI_RTX_WIN( signed int win_idx, unsigned short win_type )
{
   if(is_2g_mipi_enable)
   {
      unsigned short       idx,MIPI_RTX_WIN_EVENT_NUM,QB_ONOFF_2_FSYNC;
      short                tq;
      const APBADDR*       reg_ptr=0;
      sGGE_MIPIEVENT*          mipi_rtx_win_event=0;

      switch( win_type )
      {
         case MIPI_RX_START:
         {
            mipi_rtx_win_event     = GGE_MIPI_CTRL_TABLE_RX_EVENT[l1d_mipi.band];
            reg_ptr                = (const APBADDR*)GGE_MIPI_RTX_REG_TABLE[win_idx];
            MIPI_RTX_WIN_EVENT_NUM = GGE_MIPI_RTX_EVENT_NUM;
            QB_ONOFF_2_FSYNC       = QB_RON_2_FSYNC;
            break;
         }
         case MIPI_RX_MIDDLE:
         {
            
            MIPI_RTX_WIN_EVENT_NUM = 0;
            QB_ONOFF_2_FSYNC       = 0;
            break;
         }
         case MIPI_RX_END:
         {
            mipi_rtx_win_event     = GGE_MIPI_CTRL_TABLE_RX_EVENT[l1d_mipi.band];
            reg_ptr                = (const APBADDR*)GGE_MIPI_RTX_REG_TABLE[win_idx];
            MIPI_RTX_WIN_EVENT_NUM = GGE_MIPI_RTX_EVENT_NUM;
            QB_ONOFF_2_FSYNC       = QB_FSYNC_2_ROFF;
            break;
         }
         case MIPI_TX_START:
         {
            mipi_rtx_win_event     = GGE_MIPI_CTRL_TABLE_TX_EVENT[l1d_mipi.band];
            reg_ptr                = (const APBADDR*)GGE_MIPI_RTX_REG_TABLE[win_idx];
            MIPI_RTX_WIN_EVENT_NUM = GGE_MIPI_RTX_EVENT_NUM;
            QB_ONOFF_2_FSYNC       = QB_TON_2_FSYNC;
            break;
         }
         case MIPI_TX_MIDDLE:
         {
            mipi_rtx_win_event     = GGE_MIPI_CTRL_TABLE_TXMID_EVENT[l1d_mipi.band];
            reg_ptr                = (const APBADDR*)GGE_MIPI_TXMID_REG_TABLE[win_idx];
            MIPI_RTX_WIN_EVENT_NUM = GGE_MIPI_TXMID_EVENT_NUM;
            QB_ONOFF_2_FSYNC       = QB_TON_2_FSYNC;
            break;
         }
         case MIPI_TX_END:
         {
            mipi_rtx_win_event     = GGE_MIPI_CTRL_TABLE_TX_EVENT[l1d_mipi.band];
            reg_ptr                = (const APBADDR*)GGE_MIPI_RTX_REG_TABLE[win_idx];
            MIPI_RTX_WIN_EVENT_NUM = GGE_MIPI_RTX_EVENT_NUM;
            QB_ONOFF_2_FSYNC       = QB_FSYNC_2_TOFF;
            break;
         }
         default:
         {
            mipi_rtx_win_event     = GGE_MIPI_CTRL_TABLE_RX_EVENT[l1d_mipi.band];
            reg_ptr                = (const APBADDR*)GGE_MIPI_RTX_REG_TABLE[win_idx];
            MIPI_RTX_WIN_EVENT_NUM = 0;
            QB_ONOFF_2_FSYNC       = 0;
         }
      }

      for( idx=0 ; idx<MIPI_RTX_WIN_EVENT_NUM ; idx++, reg_ptr++, mipi_rtx_win_event++ )
      {
         if( mipi_rtx_win_event->mipi_evt_type == GGE_MIPI_EVENT_NULL )
         {  break;  }
         else if( ( ( mipi_rtx_win_event->mipi_evt_type == GGE_MIPI_TRX_ON ) || (mipi_rtx_win_event->mipi_evt_type == GGE_MIPI_TXMID ) ) &&
                ( ( win_type == MIPI_RX_START) || (win_type == MIPI_TX_START ) || (win_type == MIPI_TX_MIDDLE ) ) )
         {
            if( (mipi_rtx_win_event->mipi_evt_type == GGE_MIPI_TXMID ) )
            {
               /* --------------------------------------------------------- */
               /*                | is_mod_change | is_cur_8psk | mode_type  */
               /* ---------------|---------------|-------------|----------- */
               /*  GMSK->GMSK:   |       0       |       0     |     0      */
               /*  8PSK->8PSK:   |       0       |       1     |     1      */
               /*  8PSK->GMSK:   |       1       |       0     |     2      */
               /*  GMSK->8PSK:   |       1       |       1     |     3      */
               /* --------------------------------------------------------- */
               char is_cur_8psk   = (l1d_rf.tx_mod_type2 & (1<<l1d_mipi.cur_slot)) ? 1 : 0;
               char is_mod_change = (l1d_rf.change       & (1<<l1d_mipi.cur_slot)) ? 1 : 0;
               char mode_type     = (is_mod_change<<1)|is_cur_8psk;

               tq = (-1)*((mipi_rtx_win_event+mode_type*GGE_MIPI_TXMID_EVENT_NUM)->mipi_evt_timing-QB_ONOFF_2_FSYNC);
            }
            else
            {  tq = (-1)*(mipi_rtx_win_event->mipi_evt_timing-QB_ONOFF_2_FSYNC);
            }
            HW_WRITE( *reg_ptr , tq );
         }
         else if(  ( mipi_rtx_win_event->mipi_evt_type == GGE_MIPI_TRX_OFF ) &&
                  !( (win_type == MIPI_RX_START)||(win_type == MIPI_TX_START) )  )
         {
            tq = (mipi_rtx_win_event->mipi_evt_timing-QB_ONOFF_2_FSYNC);
            HW_WRITE( *reg_ptr , tq );
         }
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_MIPI_RX_SB( signed int cwin_idx, signed short pos_on, signed short pos_off, signed short tq_wrap )
{
   if(is_2g_mipi_enable)
   {
      unsigned short    idx;
      short             tq;
      signed int        tq_cnt;
      const   APBADDR*  creg_ptr;
      sGGE_MIPIEVENT*       mipi_rx_cwin_event = GGE_MIPI_CTRL_TABLE_RX_EVENT[l1d_mipi.band];

      creg_ptr = (const APBADDR*)GGE_MIPI_RTX_REG_TABLE[cwin_idx];

      for( idx=0 ; idx<GGE_MIPI_RTX_EVENT_NUM ; idx++, creg_ptr++, mipi_rx_cwin_event++ )
      {
         if( mipi_rx_cwin_event->mipi_evt_type == GGE_MIPI_EVENT_NULL )
            break;
         else if( mipi_rx_cwin_event->mipi_evt_type == GGE_MIPI_TRX_ON )
         {
            tq = (-1)*(mipi_rx_cwin_event->mipi_evt_timing-QB_RON_2_FSYNC);
            NORMALIZE_TQ( pos_on+tq, tq_cnt, tq_wrap );
            HW_WRITE( *creg_ptr , tq_cnt );
         }
         else if( mipi_rx_cwin_event->mipi_evt_type == GGE_MIPI_TRX_OFF )
         {
            tq = (mipi_rx_cwin_event->mipi_evt_timing-QB_FSYNC_2_ROFF);
            NORMALIZE_TQ( pos_off+tq, tq_cnt, tq_wrap );
            HW_WRITE( *creg_ptr , tq_cnt );
         }
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_MIPI_stopFSIwindow( void )
{
   if(is_2g_mipi_enable)
   {
      unsigned short       idx;
      short                tq;
      const   APBADDR*     creg_ptr;
      sGGE_MIPIEVENT*          mipi_rx_cwin_event = GGE_MIPI_CTRL_TABLE_RX_EVENT[l1d_mipi.band];

      creg_ptr = (const APBADDR*)GGE_MIPI_RTX_REG_TABLE[FS_CWIN_IDX];

      for( idx=0 ; idx<GGE_MIPI_RTX_EVENT_NUM ; idx++, creg_ptr++, mipi_rx_cwin_event++ )
      {
         if( mipi_rx_cwin_event->mipi_evt_type == GGE_MIPI_EVENT_NULL )
            break;
         else if( mipi_rx_cwin_event->mipi_evt_type == GGE_MIPI_TRX_OFF )
         {
            tq = (mipi_rx_cwin_event->mipi_evt_timing-QB_FSYNC_2_ROFF+TQ_FSWIN_STOP_FSYNC);
            HW_WRITE( *creg_ptr , tq );
         }
      }
      L1D_MIPI_SetSData_FSIWinOff_SR();
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void  L1D_MIPI_RX_PM( signed int cwin_idx, unsigned short is_pm_enhance, unsigned short is_pm_1r7pm , unsigned short is_pm_tddm )
{
   if(is_2g_mipi_enable)
   {
      unsigned short       idx;
      short                tq;
      short                tq_pm_len;
      const   APBADDR*     creg_ptr;
      sGGE_MIPIEVENT*          mipi_rx_cwin_event = GGE_MIPI_CTRL_TABLE_RX_EVENT[l1d_mipi.band];

      creg_ptr = (const APBADDR*)GGE_MIPI_RTX_REG_TABLE[cwin_idx];

      if( is_pm_enhance )
      {
         if( is_pm_1r7pm )
         {
            tq_pm_len = TQ_1R7PM_PMWIN_LEN_IN_IDLE;
         }
         else // L1D_WIN_PM_IS_8PM()
         {
            tq_pm_len = TQ_SHORT_PMWIN_LEN_IN_IDLE;
         }
      }
      else if(is_pm_tddm)
      {
         tq_pm_len = TQ_1R7PM_PMWIN_LEN_IN_IDLE;
      }
      else
      {
         tq_pm_len = TQ_SHORT_PMWIN_LEN;
      }

      for( idx=0 ; idx<GGE_MIPI_RTX_EVENT_NUM ; idx++, creg_ptr++, mipi_rx_cwin_event++ )
      {
         if( mipi_rx_cwin_event->mipi_evt_type == GGE_MIPI_EVENT_NULL )
         {  break;  }
         else if( mipi_rx_cwin_event->mipi_evt_type == GGE_MIPI_TRX_ON )
         {
            tq = (-1)*(mipi_rx_cwin_event->mipi_evt_timing-QB_RON_2_FSYNC);
            HW_WRITE( *creg_ptr , tq );
         }
         else if( mipi_rx_cwin_event->mipi_evt_type == GGE_MIPI_TRX_OFF )
         {
            tq = (mipi_rx_cwin_event->mipi_evt_timing-QB_FSYNC_2_ROFF);
            HW_WRITE( *creg_ptr , tq_pm_len+tq );
         }
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
unsigned short L1D_MIPI_Parity_Bit( unsigned short data )
{
   unsigned short parity_bit = 1;
   unsigned short temp       = data;

   while(temp)
   {
      parity_bit ^= ((temp)&0x1);
      temp>>=1;
   }

   return ((data<<1)|(parity_bit&0x1));
}

static unsigned long L1D_MIPI_Combine_Data(unsigned short mipi_data_seq,unsigned short mipi_usid,unsigned short mipi_addr,unsigned long mipi_data)
{
   unsigned long mipi_combine_data = 0;
   
   switch (mipi_data_seq)
   {
      case GGE_MIPI_REG_0_W:
      {
         /*Bit 31~28--27_26_25_24--23_22_21_20--19_18_17_16--15~12--11~8--7~~4--3~~0 */
         /*     0000--S3_S2_S1_S0-- 1_D6_D5_D4--D3_D2_D1_D0-- 0000--0000--0000--0000 */
         mipi_combine_data = (((mipi_usid&0x0F)<<24)|(0x80<<16)|((mipi_data&0x7F)<<16));
         break;
      }
      case GGE_MIPI_REG_W:
      {
         /*Bit 31~28--27_26_25_24--23_22_21_20--19_18_17_16--15_14_13_12--11_10_9 _8 --7~~4--3~~0 */
         /*     0000--S3_S2_S1_S0-- 0  1  0 A4--A3_A2_A1_A0--D7_D6_D5_D4--D3_D2_D1_D0--0000--0000 */
         mipi_combine_data = (((mipi_usid&0x0F)<<24)|(0x40<<16)|((mipi_addr&0x1F)<<16)|((mipi_data&0xFF)<<8));
         break;
      }
      case GGE_MIPI_REG_W_EXT_1ST:
      {
         /*Bit 31~28--27_26_25_24--23_22_21_20--19_18_17_16--15_14_13_12--11_10_9 _8 -- 7 _6 _5 _4-- 3 _2 _1 _0 */
         /*     0000--S3_S2_S1_S0-- 0  0  0  0--B3_B2_B1_B0--A7_A6_A5_A4--A3_A2_A1_A0--D7_D6_D5_D4--D3_D2_D1_D0 */
         mipi_combine_data = (((mipi_usid&0x0F)<<24)|(mipi_data&0x000F0000)|((mipi_addr&0xFF)<<8)|(mipi_data&0xFF));
         break;
      }
      case GGE_MIPI_REG_W_EXT_BYTE:
      {
         /*Bit 31~28--27~24-- 23_ 22_ 21_ 20-- 19_ 18_ 17_ 16-- 15_ 14_ 13_ 12-- 11 _10 _9 _8 --7 _6 _5 _4-- 3 _2 _1 _0 */
         /*     0000-- 0000--D23_D22_D21_D20--D19_D18_D17_D16--D15_D14_D13_D12--D11_D10_D9_D8--D7_D6_D5_D4--D3_D2_D1_D0 */
         mipi_combine_data = (mipi_data&0x00FFFFFF);
         break;
      }
      default:
      {
         extern void L1D_RF_Info_Trace( unsigned short idx, long v1, long v2 );
         /*l1d_custom_mipi.c mipi_data_seq setting abnormal*/
         L1D_RF_Info_Trace(31912,mipi_data_seq,mipi_usid); 
         L1D_RF_Info_Trace(31912,mipi_addr,mipi_data); 
      }   
   }
   return mipi_combine_data;
}

static unsigned long L1D_MIPI_Gen_Data( unsigned long *pData, unsigned short mipi_data_seq )
{
   unsigned long  data_len = 0;
   unsigned short dataH, dataL;

   dataL = (*pData)&0xFFFF;
   dataH = (*pData)>>16;

   if( mipi_data_seq == GGE_MIPI_REG_0_W )
   {
      *pData   = L1D_MIPI_Parity_Bit( dataH );
      data_len = 12/*command frame*/ + 1 /*Parity*/;
   }
   else if( mipi_data_seq == GGE_MIPI_REG_W )
   {
      dataL    = L1D_MIPI_Parity_Bit( (unsigned short)(dataL>>8) );
      dataH    = L1D_MIPI_Parity_Bit( dataH&0x0FFF );
     *pData    = (dataH<<9)|dataL;
      data_len = 12/*command frame*/ + 8/*data frame*/ + 1*2 /*Parity*/;
   }
   else if( mipi_data_seq == GGE_MIPI_REG_W_EXT_1ST )
   {
      unsigned short dataL_H, dataL_L;

      dataL_L  = L1D_MIPI_Parity_Bit( (unsigned short)(dataL&0xFF) );
      dataL_H  = L1D_MIPI_Parity_Bit( (unsigned short)(dataL>>8)   );
      dataH    = L1D_MIPI_Parity_Bit( dataH);
      *pData   = (dataH<<18)|(dataL_H<<9)|dataL_L;
      data_len = 12/*command frame*/ + 8*2/*data frame*/ + 1*3 /*Parity*/;
   }
   else if( mipi_data_seq == GGE_MIPI_REG_W_EXT_BYTE )
   {
      unsigned short dataL_H, dataL_L;

      dataL_L  = L1D_MIPI_Parity_Bit( (unsigned short)(dataL&0xFF) );
      dataL_H  = L1D_MIPI_Parity_Bit( (unsigned short)(dataL>>8)   );
      dataH    = L1D_MIPI_Parity_Bit( (unsigned short)(dataH&0xFF) );
      *pData   = (dataH<<18)|(dataL_H<<9)|dataL_L;
      data_len = 8*3/*data frame*/ + 1*3 /*Parity*/;
   }
   else
   { /*ASSERT(0)*/; }

   return data_len;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_MIPI_CWIN_SELECT_CUR_SLOT( unsigned short slot_con, unsigned char  cwin_indx )
{
   if(is_2g_mipi_enable)
   {
      unsigned short sidx, i, pre_slot=0, cwin_count=0;

      for( sidx = slot_con; sidx!=0; sidx>>=4 )
      {
         i = sidx & 0x07;
         if( ( cwin_indx == cwin_count ) && ( cwin_indx == 0 || ( i > pre_slot+1 ) ) )
         {
            l1d_mipi.cur_slot = i;
            break;
         }
         else
         {
            if( ( cwin_count < cwin_indx ) &&  ( cwin_count == 0 || i > pre_slot+1 ) )
               cwin_count++;
            pre_slot = i;
         }
      }
   }
}

void  L1D_MIPI_SetSData_SX(  unsigned short rt_type )
{               		
   if(is_2g_mipi_enable)
   {

      int                  event_idx, data_idx, subband_idx, win_idx, pa_data_idx=0;
      int                  MIPI_RTX_SetEVENT_NUM,MIPI_RTX_NUM_reset;
      unsigned short       event_idx_per_win, data_idx_per_win;
      unsigned short       data_st_idx, data_sp_idx;
      unsigned short       mipi_data_seq, mipi_port_sel;
      unsigned short       mipi_usid,mipi_addr;
      unsigned long        mipi_data;
      unsigned long        mipi_data_len, mipi_data_ctrl;
      sGGE_MIPIEVENT*          mipi_rtx_win_event;
      sGGE_MIPIDATA_SUBBAND*   mipi_rtx_win_data;

      switch( rt_type )
      {
         case MIPI_SETDATA_SR:
         {
            mipi_rtx_win_event    = GGE_MIPI_CTRL_TABLE_RX_EVENT[l1d_mipi.band];
            mipi_rtx_win_data     = GGE_MIPI_CTRL_TABLE_RX_DATA[l1d_mipi.band];
            MIPI_RTX_SetEVENT_NUM = GGE_MIPI_RTX_EVENT_NUM;
            win_idx               = l1d_rf.cwin_idx;
            MIPI_RTX_NUM_reset    = GGE_MIPI_RTX_DATA_NUM;
            break;
         }
         case MIPI_SETDATA_ST:
         {
            mipi_rtx_win_event    = GGE_MIPI_CTRL_TABLE_TX_EVENT[l1d_mipi.band];
            
            /*MT6580 does not support DSDA DCS TX NOTCH SWITCH*/
          /*#if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
                    if( (l1d_mipi.band == FrequencyBand1800) && (L1D_RF_IS_DCS_Change_to_TX_Notch()) )
                         mipi_rtx_win_data  = GGE_MIPI_CTRL_TABLE_TX_DATA_NOTCH_SWITCH[l1d_mipi.band];
                    else
                         mipi_rtx_win_data  = GGE_MIPI_CTRL_TABLE_TX_DATA[l1d_mipi.band];*/

            mipi_rtx_win_data     = GGE_MIPI_CTRL_TABLE_TX_DATA[l1d_mipi.band];

            MIPI_RTX_SetEVENT_NUM = GGE_MIPI_RTX_EVENT_NUM;
            win_idx               = l1d_rf.cwin_idx;
            MIPI_RTX_NUM_reset    = GGE_MIPI_RTX_DATA_NUM;
            break;
         }
         case MIPI_SETDATA_STM:
         {
            mipi_rtx_win_event    = GGE_MIPI_CTRL_TABLE_TXMID_EVENT[l1d_mipi.band];
            mipi_rtx_win_data     = GGE_MIPI_CTRL_TABLE_TXMID_DATA[l1d_mipi.band];
            MIPI_RTX_SetEVENT_NUM = GGE_MIPI_TXMID_EVENT_NUM;
            win_idx               = l1d_mipi.tx_mid_idx;
            MIPI_RTX_NUM_reset    = GGE_MIPI_TXMID_DATA_NUM;
            break;
         }
         default:
         {
            mipi_rtx_win_event    = GGE_MIPI_CTRL_TABLE_RX_EVENT[l1d_mipi.band];
            mipi_rtx_win_data     = GGE_MIPI_CTRL_TABLE_RX_DATA[l1d_mipi.band];
            MIPI_RTX_SetEVENT_NUM = 0;
            win_idx               = l1d_rf.cwin_idx;
            MIPI_RTX_NUM_reset    = GGE_MIPI_RTX_DATA_NUM;
         }
      }

      /* Reset all the MIPI data as reserve event id */
      for( data_idx_per_win=0; data_idx_per_win<MIPI_RTX_NUM_reset; data_idx_per_win++ )
      {
         if( rt_type == MIPI_SETDATA_STM )
         {  data_idx = GGE_MIPI_TXMID_DTIDX( win_idx, data_idx_per_win );  }
         else
         {  data_idx = GGE_MIPI_RTX_DTIDX(   win_idx, data_idx_per_win );  }
         HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
      }

      /* Search all the event per cwin to set each data */
      for( event_idx_per_win=0; event_idx_per_win<MIPI_RTX_SetEVENT_NUM ; event_idx_per_win++, mipi_rtx_win_event++ )
      {
         if( mipi_rtx_win_event->mipi_evt_type==GGE_MIPI_EVENT_NULL )
         {  break;  }
         if( rt_type == MIPI_SETDATA_STM )
         {  event_idx = GGE_MIPI_TXMID_EVIDX( win_idx, event_idx_per_win );  }
         else
         {  event_idx = GGE_MIPI_RTX_EVIDX(   win_idx, event_idx_per_win );  }
         data_st_idx = mipi_rtx_win_event->mipi_data_stsp.mipi_data_st;
         data_sp_idx = mipi_rtx_win_event->mipi_data_stsp.mipi_data_sp;

         for( data_idx_per_win=data_st_idx; data_idx_per_win<=data_sp_idx; data_idx_per_win++ )
         {
            /* Search for subband index */
            for( subband_idx=0; subband_idx<GGE_MIPI_SUBBAND_NUM; subband_idx++)
            {
               if ( mipi_rtx_win_data[data_idx_per_win].mipi_subband_data[subband_idx].subband_arfcn==GGE_NULL_ARFCN )
               {
                  /* Add to avoid customer typo or wrong mipi table setting to cause buffer underflow access */
                  if(subband_idx==0)
                  {
                     extern void L1D_RF_Info_Trace( unsigned short idx, long v1, long v2 );
                     /*l1d_custom_mipi.c subband_arfcn setting abnormal*/
                     L1D_RF_Info_Trace(31911,subband_idx,GGE_NULL_ARFCN); 
                     L1D_RF_Info_Trace(l1d_mipi.band,data_st_idx,data_sp_idx);
                  }
                  subband_idx>0?(subband_idx--):0;
                  break;
               }
               if ( l1d_mipi.arfcn <= mipi_rtx_win_data[data_idx_per_win].mipi_subband_data[subband_idx].subband_arfcn)
                  break;
               /* Add to avoid customer typo or wrong mipi table setting to cause buffer overflow access */
               if(subband_idx==(GGE_MIPI_SUBBAND_NUM-1))
               {
                  extern void L1D_RF_Info_Trace( unsigned short idx, long v1, long v2 );
                  /*l1d_custom_mipi.c subband_arfcn setting abnormal*/
                  L1D_RF_Info_Trace(31913,subband_idx,31913); 
                  L1D_RF_Info_Trace(l1d_mipi.band,data_st_idx,data_sp_idx);                  
                  break;
               }
            }
            mipi_usid     = mipi_rtx_win_data[data_idx_per_win].mipi_usid;
            mipi_addr     = mipi_rtx_win_data[data_idx_per_win].mipi_subband_data[subband_idx].mipi_addr;
            mipi_data_seq = mipi_rtx_win_data[data_idx_per_win].mipi_data_seq;
            mipi_port_sel = mipi_rtx_win_data[data_idx_per_win].mipi_port_sel;

         if( mipi_rtx_win_data[data_idx_per_win].mipi_subband_data[subband_idx].mipi_data==GGE_MIPI_PA_G8 )
         {
            if(pa_data_idx>=GGE_MIPI_SUBBAND_PA_DATA_NUM)
            {
               extern void L1D_RF_Info_Trace(unsigned short idx, long v1, long v2);
               /*l1d_custom_mipi.c subband_pa_data setting abnormal*/
               L1D_RF_Info_Trace(31915,subband_idx,31915);
               L1D_RF_Info_Trace(l1d_mipi.band,data_st_idx,data_sp_idx);
               break;
            }
            if( (l1d_rf.tx_mod_type2>>l1d_mipi.cur_slot)&0x1 )
            {
                 mipi_data = GGE_MIPI_CTRL_TABLE_PA_DATA[l1d_mipi.band]->mipi_8psk_data[pa_data_idx][subband_idx];
            }
            else 
            {
                mipi_data = GGE_MIPI_CTRL_TABLE_PA_DATA[l1d_mipi.band]->mipi_gmsk_data[pa_data_idx][subband_idx];
            }
            pa_data_idx++;
         }
         else/*Not PA ON/MID data case*/
         {
             mipi_data = mipi_rtx_win_data[data_idx_per_win].mipi_subband_data[subband_idx].mipi_data;
         }

         mipi_data= L1D_MIPI_Combine_Data(mipi_data_seq, mipi_usid, mipi_addr, mipi_data);
         mipi_data_len = L1D_MIPI_Gen_Data( &mipi_data, mipi_data_seq );

         if( rt_type == MIPI_SETDATA_STM )
            data_idx = GGE_MIPI_TXMID_DTIDX( win_idx, data_idx_per_win );
         else
            data_idx = GGE_MIPI_RTX_DTIDX( win_idx, data_idx_per_win );
            mipi_data_ctrl = MIPI_SCTRL_WORD(0, mipi_data_len, mipi_port_sel, event_idx );
         HWRITE_1_SDATA( mipi_data_ctrl, mipi_data );
         }
      }
   }
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void  L1D_MIPI_PowerOn( void )
{
   if(is_2g_mipi_enable)
   {
      unsigned short i;
      unsigned short BSI_num=0;
      unsigned long  mipi_data, mipi_data_len;
      
      if(l1d_mipi.is_init == 1)
      {
         IMM_MODE_BEGIN( IMMMASK_ALL );

    //  L1D_PMU_VMIPISetting(1);  
     // WAIT_TIME_QB(100);
        BSI_num = MIPI_POWERON_NUM;

        for( i=0 ; i<BSI_num; i++ )
        {
            if( MIPI_POWERON_TABLE[i].mipi_data_seq == GGE_MIPI_WAIT )
            {
                if(MIPI_POWERON_TABLE[i].mipi_data<=30)
                   WAIT_TIME_QB(MIPI_POWERON_TABLE[i].mipi_data);
                else
                   WAIT_TIME_QB(30);
            }
            else
            {
                mipi_data = L1D_MIPI_Combine_Data(MIPI_POWERON_TABLE[i].mipi_data_seq, MIPI_POWERON_TABLE[i].mipi_usid
                                                , MIPI_POWERON_TABLE[i].mipi_addr, MIPI_POWERON_TABLE[i].mipi_data);
                mipi_data_len = L1D_MIPI_Gen_Data(&mipi_data, MIPI_POWERON_TABLE[i].mipi_data_seq);
                IMM_SEND_BSI( MIPI_SCTRL_IMOD(0,mipi_data_len,MIPI_POWERON_TABLE[i].mipi_port_sel), mipi_data );
            }
         }
         IMM_MODE_END(  );
      }
   }
}

void  L1D_MIPI_PowerOff( void )
{
   if(is_2g_mipi_enable)
   {
      unsigned short i;
      unsigned short BSI_num=0;
      unsigned long  mipi_data, mipi_data_len;

      IMM_MODE_BEGIN( IMMMASK_BSI );

      BSI_num = MIPI_POWEROFF_NUM;

      for( i=0 ; i<BSI_num; i++ )
      { 
         if( MIPI_POWEROFF_TABLE[i].mipi_data_seq == GGE_MIPI_WAIT )
         {
            if(MIPI_POWEROFF_TABLE[i].mipi_data<=30)
               WAIT_TIME_QB(MIPI_POWEROFF_TABLE[i].mipi_data);
            else
               WAIT_TIME_QB(30);
         }
         else
         {
         mipi_data = L1D_MIPI_Combine_Data(MIPI_POWERON_TABLE[i].mipi_data_seq, MIPI_POWERON_TABLE[i].mipi_usid
                                          , MIPI_POWERON_TABLE[i].mipi_addr, MIPI_POWERON_TABLE[i].mipi_data);
         mipi_data_len = L1D_MIPI_Gen_Data(&mipi_data, MIPI_POWERON_TABLE[i].mipi_data_seq);

            IMM_SEND_BSI( MIPI_SCTRL_IMOD(0,mipi_data_len,MIPI_POWEROFF_TABLE[i].mipi_port_sel), mipi_data );
         }
      }

      IMM_MODE_END(  );
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void  L1D_MIPI_SetSData_FSIWinOff_SR( void )
{
   int                  event_idx, data_idx, subband_idx;
   unsigned short       event_idx_per_cwin, data_idx_per_cwin;
   unsigned short       data_st_idx, data_sp_idx;
   unsigned short       mipi_data_seq, mipi_port_sel;
   unsigned long        mipi_data;
   unsigned short       mipi_usid,mipi_addr;
   unsigned long        mipi_data_len, mipi_data_ctrl;
   sGGE_MIPIEVENT*          mipi_rx_cwin_event = GGE_MIPI_CTRL_TABLE_RX_EVENT[l1d_mipi.band];
   sGGE_MIPIDATA_SUBBAND*   mipi_rx_cwin_data  = GGE_MIPI_CTRL_TABLE_RX_DATA[l1d_mipi.band];

   /* Reset all the MIPI data as reserve event id */
   for( data_idx_per_cwin=0; data_idx_per_cwin<GGE_MIPI_RTX_DATA_NUM; data_idx_per_cwin++ )
   {
      data_idx = GGE_MIPI_RTX_DTIDX( FS_CWIN_IDX, data_idx_per_cwin );
      HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
   }

   /* Search all the event per cwin to set each data */
   for( event_idx_per_cwin=0; event_idx_per_cwin<GGE_MIPI_RTX_EVENT_NUM ; event_idx_per_cwin++, mipi_rx_cwin_event++ )
   {
      if( mipi_rx_cwin_event->mipi_evt_type==GGE_MIPI_EVENT_NULL )
      {  break;  }
      else if( mipi_rx_cwin_event->mipi_evt_type==GGE_MIPI_TRX_OFF )
      {
         event_idx = GGE_MIPI_RTX_EVIDX( FS_CWIN_IDX, event_idx_per_cwin );
         data_st_idx = mipi_rx_cwin_event->mipi_data_stsp.mipi_data_st;
         data_sp_idx = mipi_rx_cwin_event->mipi_data_stsp.mipi_data_sp;
         for( data_idx_per_cwin=data_st_idx; data_idx_per_cwin<=data_sp_idx; data_idx_per_cwin++ )
         {
            /* Search for subband index */
            for( subband_idx=0; subband_idx<GGE_MIPI_SUBBAND_NUM; subband_idx++)
            {
               if ( mipi_rx_cwin_data[data_idx_per_cwin].mipi_subband_data[subband_idx].subband_arfcn==GGE_NULL_ARFCN)
               {
                  /* Add to avoid customer typo or wrong mipi table setting to cause buffer underflow access */
                  if(subband_idx==0)
                  {
                     extern void L1D_RF_Info_Trace( unsigned short idx, long v1, long v2 );
                     /*l1d_custom_mipi.c subband_arfcn setting abnormal*/
                     L1D_RF_Info_Trace(31911,subband_idx,GGE_NULL_ARFCN); 
                     L1D_RF_Info_Trace(l1d_mipi.band,data_st_idx,data_sp_idx);
                  }
                  subband_idx>0?(subband_idx--):0;
                  break;
               }
               if ( ( l1d_mipi.arfcn <= mipi_rx_cwin_data[data_idx_per_cwin].mipi_subband_data[subband_idx].subband_arfcn))
                  break;
               /* Add to avoid customer typo or wrong mipi table setting to cause buffer overflow access */
               if(subband_idx==(GGE_MIPI_SUBBAND_NUM-1))
               {
                  extern void L1D_RF_Info_Trace( unsigned short idx, long v1, long v2 );
                  /*l1d_custom_mipi.c subband_arfcn setting abnormal*/
                  L1D_RF_Info_Trace(31913,subband_idx,31913); 
                  L1D_RF_Info_Trace(l1d_mipi.band,data_st_idx,data_sp_idx);                  
                  break;
               }
            }

            mipi_usid     = mipi_rx_cwin_data[data_idx_per_cwin].mipi_usid;
            mipi_addr     = mipi_rx_cwin_data[data_idx_per_cwin].mipi_subband_data[subband_idx].mipi_addr;
            mipi_data     = mipi_rx_cwin_data[data_idx_per_cwin].mipi_subband_data[subband_idx].mipi_data;
            mipi_data_seq = mipi_rx_cwin_data[data_idx_per_cwin].mipi_data_seq;
            mipi_port_sel = mipi_rx_cwin_data[data_idx_per_cwin].mipi_port_sel;

            mipi_data     = L1D_MIPI_Combine_Data (mipi_data_seq,mipi_usid,mipi_addr,mipi_data);
            mipi_data_len = L1D_MIPI_Gen_Data( &mipi_data, mipi_data_seq );

            data_idx      = GGE_MIPI_RTX_DTIDX( FS_CWIN_IDX, data_idx_per_cwin );
            mipi_data_ctrl= MIPI_SCTRL_WORD( 0, mipi_data_len, mipi_port_sel, event_idx );

            HWRITE_1_SDATA( mipi_data_ctrl, mipi_data );
         }
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void  L1D_MIPI_DUMP_CW(kal_uint32 usId, kal_uint32 start_addr, kal_uint32 stop_addr)
{
   kal_uint32 addr;
   unsigned long mipiaddr,mipidata;

   IMM_MODE_BEGIN(IMMMASK_ALL);
   for (addr=start_addr ; addr<stop_addr+1 ; addr++)
   {
      if((addr==0x00)|(addr==0x01))   /*register read*/
      {
          mipiaddr = L1D_MIPI_Parity_Bit((0x0E<<8)/*usid*/|(0x3<<5)/*read command*/|(addr&0x1F));
          IMM_RECEIVE_BSI(0,mipiaddr,MIPI_SCTRL_IMOD(0,22,GGE_MIPI_PORT0),&mipidata);
      }
      else  /*extend read*/
      {
          /*TBD: Byte Count set to 3, for 4 bytes read back*/
          mipiaddr = L1D_MIPI_Parity_Bit((usId<<8)|(0x2<<4)/*read command*/|(3<<0)/*BC*/);
          mipiaddr = (mipiaddr<<9)|L1D_MIPI_Parity_Bit(addr & 0xFF);
          
          L1D_MIPI_GetImmBSI_EXT(mipiaddr, &mipidata, 0/*byteId*/);
      }
      /*remove parity bit, 1bit*/
      mipidata >>= 1;

      extern void L1D_RF_Info_Trace(unsigned short idx, long v1, long v2);   
      L1D_RF_Info_Trace(6588,addr,mipidata);    
   
   }
   IMM_MODE_END();
}

void L1D_MIPI_EXT_RD_PARSING(kal_uint32 d32_H, kal_uint32 d32_L, kal_uint8 byte_id, kal_uint32 *bsi_data)
{
   if(byte_id == 0)
       *bsi_data = ((d32_H&0xF)<<5)|(((d32_L&(0x1F<<27))>>27)&0x1F);
   else if(byte_id == 1)
       *bsi_data = (d32_L &(0x1FF<<18))>>18;
   else if(byte_id == 2)
       *bsi_data = (d32_L &(0x1FF<<9))>>9;
   else if(byte_id == 3)
       *bsi_data = (d32_L &(0x1FF<<0))>>0;
}

void L1D_MIPI_GetImmBSI_EXT(kal_uint32 bsi_addr, kal_uint32 *bsi_data, kal_uint8 byteId)
{
   unsigned long bsi_rdaddr_backup;
   unsigned long bsi_rdaddr_con_backup;
   unsigned long bsi_rdcs_con_backup;
   unsigned long bsi_rdcon_backup;
   kal_uint32    d32   = 0;
    
   /* Backup original settings */
   bsi_rdcon_backup      = HW_READ( BSI_RDCON      );
   bsi_rdaddr_con_backup = HW_READ( BSI_RDADDR_CON );
   bsi_rdaddr_backup     = HW_READ( BSI_RDADDR     );
   bsi_rdcs_con_backup   = HW_READ( BSI_RDCS_CON   );
   
   *bsi_data = 0;

   if(is_2g_mipi_enable)
   {
      HW_WRITE( BSI_RDADDR, bsi_addr );
      HW_WRITE( BSI_RDADDR_CON, MIPI_C_BSI_RDADDR_CON_EXT_MAIN );
      HW_WRITE( BSI_RDDAT_H, 0x0                           ); /* Clear Ready bit before triggering immediate read back event */
      HW_WRITE( BSI_RDCON, MIPI_C_BSI_RDCON_EXT_START_SETTING  );
      HW_WRITE( BSI_RDCON, MIPI_C_BSI_RDCON_EXT_IMMRD_SETTING  );
   }
   /*Wait for readback ready*/
   do{
        d32 = HW_READ(BSI_RDDAT_H);
     }while(!((d32)&0x80000000));
   
   L1D_MIPI_EXT_RD_PARSING(d32, HW_READ(BSI_RDDAT), byteId, bsi_data);
   
   /*Restore original setting*/
#if IS_COSIM_ON_L1SIM_SUPPORT
   /* do not restore in the modem sim; otherwise, the settings can not be checked */
#else
   HW_WRITE( BSI_RDADDR,      bsi_rdaddr_backup             );
   HW_WRITE( BSI_RDADDR_CON, (bsi_rdaddr_con_backup&0xFFFF) );
   HW_WRITE( BSI_RDCS_CON,   (bsi_rdcs_con_backup&0xFFFF)   );
   HW_WRITE( BSI_RDCON,       bsi_rdcon_backup              );
#endif
}
#endif /* IS_MIPI_SUPPORT */

