/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * custom_sms_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sms customization functions, 
 *   custom can use these functions to config parameters. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
**   Includes
*/
#include "kal_general_types.h"

#ifdef __SP_RIL_SUPPORT__
// for Smart Phone (ex: Windows Mobile/Android) project default value
#define CNMI_PARA_MODE  2
#define CNMI_PARA_MT  2
#define CNMI_PARA_BM  2
#define CNMI_PARA_DS  1
#else
/* For AT+CNMI <mode> parameter, the value should be (0-3) */
#define CNMI_PARA_MODE  0
/* For AT+CNMI <mt> parameter, the value should be (0-3) */
#define CNMI_PARA_MT  0
/* For AT+CNMI <bm> parameter, the value should be (0,2, or 3) */
#define CNMI_PARA_BM  0
/* For AT+CNMI <ds> parameter, the value should be (0 or 1) */
#define CNMI_PARA_DS  0
#endif

/* 0xFFFF means default check all the service tables */
#define SERVICE_TABLE_BITMAP 0xFFFF


/*Disable MT SMS and STK send SMS*/
#ifdef __DISABLE_SMS__
#define SMS_DISABLE  1    
#else
#define SMS_DISABLE  0
#endif
typedef struct
{
    kal_uint32 hplmn_id;
	kal_uint8  sc_addr[12];
}smsc_hplmn_map;

smsc_hplmn_map table1[] = {
	405872,0x07,0x91,0x19,0x09,0x02,0x00,0x50,0x00,0,0,0,0,
	40445, 0x07,0x91,0x19,0x89,0x54,0x80,0x07,0x10,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,
		
	/* For Example 40486, 0x07,0x91,0x19,0x89,0x68,0x00,0x45,0x44,0,0,0,0, 
           here mcc=404, mnc=86 SMSC ADDR len = 7, and then SMSC ADDR*/
};
#define SMSC_PLMN_TABLE_SIZE  (sizeof(table1)/sizeof(smsc_hplmn_map))

/*****************************************************************************
* FUNCTION
*   sms_cnmi_para_mode 
* DESCRIPTION
*   This function is used to define the spec 27.005 section 3.4.1 
*   AT+CNMI <mode> parameter, the value sholud be (0-3)
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 sms_cnmi_para_mode(void)
{
   return (CNMI_PARA_MODE);
}


/*****************************************************************************
* FUNCTION
*   sms_cnmi_para_mt
* DESCRIPTION
*   This function is used to define the spec 27.005 section 3.4.1 
*   AT+CNMI <mt> parameter, the value sholud be (0-3)
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 sms_cnmi_para_mt(void)
{
   return (CNMI_PARA_MT);
}


/*****************************************************************************
* FUNCTION
*   sms_cnmi_para_bm
* DESCRIPTION
*   This function is used to define the spec 27.005 section 3.4.1 
*   AT+CNMI <bm> parameter, the value sholud be (0,2, or 3)
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 sms_cnmi_para_bm(void)
{
   return (CNMI_PARA_BM);
}


/*****************************************************************************
* FUNCTION
*   sms_cnmi_para_ds
* DESCRIPTION
*   This function is used to define the spec 27.005 section 3.4.1 
*   AT+CNMI <ds> parameter, the value sholud be (0 or 1)
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 sms_cnmi_para_ds(void)
{
   return (CNMI_PARA_DS);
}

/*****************************************************************************
* FUNCTION
*   sms_check_sim_service_table
* DESCRIPTION
*   This function is used to config if the SIM file need to check service table 
*   1: It will check service table, 0: It will not check service table
*
*            +---------+---------+---------------+---------+
*            |  BIT16  |  BIT15  | ... |  BIT 1  |  BIT 0  |
*            +---------+---------+---------------+---------+
*
*   BIT  0: Efsmss
*   BIT  1: EFsmsp
*   BIT  2: EFcbmi
*   BIT  3: EFcbmid
*   BIT  4: EFcbmir 
*   BIT  5: EFext6          (R4 file)
*   BIT  6: EFmbdn          (R4 file)
*   BIT  7: EFmbi           (R4 file)
*   BIT  8: EFmwis          (R4 file)
*   BIT  9: EFext1
*   BIT 10: EFmailbox_num   (CPHS file)
*   BIT 11: EFsms
*
* PARAMETERS
*
* RETURNS
*   kal_uint16
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint16 sms_check_sim_service_table(void)
{
   return (SERVICE_TABLE_BITMAP);
}



/*****************************************************************************
* FUNCTION
*   custom_sms_is_disabled 
* DESCRIPTION
*   This function is used to get the value of SMS disable. 
*   0: SMS works normally
*   1: "MT SMS" and "STK send SMS" are disbaled 
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 custom_sms_is_disabled(void)
{
   return (SMS_DISABLE);
}


kal_bool custom_get_sc_addr(kal_uint32 plmn_id, kal_uint8 *sc_addr)
{
    kal_uint8 i,j;
    for(i = 0 ; i < SMSC_PLMN_TABLE_SIZE; i++)
    {
        if( table1[i].hplmn_id == plmn_id ) 
        {
        	/*kal_mem_cpy(sc_addr, table1[i].sc_addr, table1[i].sc_addr[0]+1);*/
			for( j = 0; j < 12; j++ )
			{
				sc_addr[j] =  table1[i].sc_addr[j];
			}
			return KAL_TRUE;
        }
    }
	return KAL_FALSE;
}
/*****************************************************************************
* FUNCTION
*   custom_is_fdn_check_required
* DESCRIPTION
*   This function returns true if the FDN check is required and false if it is not required.
* PARAMETERS
*    hplmn_id of the operator whose SIM card is inserted
* RETURNS
*   kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool custom_is_fdn_check_required(kal_uint32 hplmn_id)
{
    switch(hplmn_id)
    {
        case 33402:                /*33402 & 334020 are the hplmn ID for TELCEL operator*/
		case 334020:
		    return KAL_FALSE;
			
		default:
			return KAL_TRUE;
    }
}
