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
 * Filename:
 * ---------
 * custom_nvram_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   The file contains nvram configuration default value.
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_NOT_PRESENT

#include "kal_general_types.h"

#include "nvram_enums.h"            /* NVRAM_CLEAN_FOLDER_FACTORY */
#include "custom_nvram_int_config.h"
#include "nvram_data_items.h"

#include "ccci.h" //for SBP ccci misc info
#include "ps_public_utility.h"
#include "nvram_interface.h"
#include "nvram_editor_data_item.h"

#ifdef __GEMINI_3G_SWITCH__
extern kal_uint8 MASTER_SIM_CFG;
#endif

#define SBP_ID_INVALID 0xffffffff
#define SBP_TEST_MODE 8286

kal_bool custom_nvram_set_sbp_id(kal_uint32 sbp_id);
void nvram_custom_reset_rrc_dynamic_cap();
void custom_nvram_reset_regional_phone_mode();
void custom_nvram_reset_pf_conformance_testmode();
void custom_reset_nvram_lids(kal_uint32 sbp_id);

kal_uint32 old_sbp_id = 0;
kal_uint32 default_sbp_id = 0;
kal_uint32 ims_operator_code = 0;

typedef void(*SBP_RESET_NVRAM_LID)();

typedef struct{
	SBP_RESET_NVRAM_LID sbp_reset_nvram_lid_funcptr;
}sbp_nvram_lid_reset_table;


sbp_nvram_lid_reset_table nvram_lid_reset_func_tbl[]={
	nvram_custom_reset_rrc_dynamic_cap,
    custom_nvram_reset_regional_phone_mode,
    custom_nvram_reset_pf_conformance_testmode   
};

/*
 * Restore factory begin
 */


/*****************************************************************************
 * FUNCTION
 *  nvram_custom_get_max_record_size
 * DESCRIPTION
 *  Return the maximum record size, every nvram lid record size cannot bigger than this
 * PARAMETERS
 * RETURNS
 *  maximum record size
 *****************************************************************************/
kal_uint32 nvram_custom_max_record_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return NVRAM_CUSTOM_CFG_MAX_RECORD_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_custom_lock_pattern
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_bool nvram_custom_lock_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (NVRAM_CUSTOM_CFG_DEFAULT_LOCK_STATUS == __UNLOCKED__)
    return KAL_FALSE;
#else
    return KAL_TRUE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  sbp_is_test_mode
 *
 * DESCRIPTION
 * Set SBP to test mode.
 * In test mode, we read current values of nvram files instead of using default values before applying SBP settings.
 *
 * PARAMETERS
 *  [IN]    N/A
 * RETURNS
 *   KAL_TRUE    : SBP is in test mode
 *   KAL_FALSE   : SBP is not in test mode
 *****************************************************************************/

kal_bool sbp_is_test_mode (void)
{
    nvram_ef_sbp_modem_data_config_struct sbp_data_buf;

    nvram_external_read_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                             1, 
                             (kal_uint8*)&sbp_data_buf, 
                             NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);

    if (SBP_TEST_MODE == sbp_data_buf.sbp_mode)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_nvram_config
 * DESCRIPTION
 *  Pre-process nvram data items at nvram task init.
 *  This function will be always invoked at nvram task init, right after NVRAM initialization.
 *  User can pre-process nvram data items via using NVRMA external API here.
 *     nvram_external_write_data()
 *     nvram_external_read_data()
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/

void custom_nvram_config(void)
{
#if !defined(L4_NOT_PRESENT) && !defined(__L4_TASK_DISABLE__)
    kal_uint32 sbp_id = 0;
#ifdef __GEMINI_3G_SWITCH__
{   // Read current SIM MAP setting
    kal_uint8 data[8];

    nvram_external_read_data(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, data, NVRAM_EF_SYS_CACHE_OCTET_SIZE);
    MASTER_SIM_CFG = data[L4C_SETTING_3G_SERVICE_BITMAP];
}
#endif

#if defined(__MODEM_CCCI_EXIST__) && defined(__MTK_TARGET__)
    if (ccci_misc_info_feature_support(CCMSG_ID_MISCINFO_SBP_ID, 4, &sbp_id) == CCCI_MISC_INFO_SUPPORT)
#endif
        {
            default_sbp_id = sbp_id;
            custom_nvram_set_sbp_id(sbp_id);
        }
#endif /* !defined(L4_NOT_PRESENT) && !defined(__L4_TASK_DISABLE__) */
}



/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_sbp_id
 * DESCRIPTION
 * similar to custom_nvram_config()
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
kal_bool custom_nvram_set_sbp_id(kal_uint32 sbp_id)
{
    nvram_ef_sbp_modem_config_struct *default_sbp_feature = NULL;
    nvram_ef_sbp_modem_config_struct sbp_feature_buf;
    nvram_ef_sbp_modem_data_config_struct *default_sbp_data_buf = NULL;
    nvram_ef_sbp_modem_data_config_struct sbp_data_buf;

    /* Update related NVRAM files according to SBP ID */
    if (sbp_id != SBP_ID_INVALID)
    {  
    	/* If SBP ID is Valid then reset all SBP Features and SBP Data Values to their Default values
		      after that set the SBP Features according to  the Operator Id*/
    	if ((KAL_FALSE == sbp_is_test_mode())&&
            (NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_SBP_MODEM_CONFIG_LID, 1, (kal_uint8**)&default_sbp_feature)))
        {
            /* Reset to the default value first */
            kal_mem_cpy(&sbp_feature_buf, default_sbp_feature, sizeof(nvram_ef_sbp_modem_config_struct));
        }
        else
        {
            /* Read current settings in NVRAM */
            nvram_external_read_data(NVRAM_EF_SBP_MODEM_CONFIG_LID, 
                                     1, 
                                     (kal_uint8*)&sbp_feature_buf, 
                                     NVRAM_EF_SBP_MODEM_CONFIG_SIZE);
        }

        if ((KAL_FALSE == sbp_is_test_mode())&&
            (NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 1, (kal_uint8**)&default_sbp_data_buf)))
        {
             /* Reset to the default value first */
            kal_mem_cpy(&sbp_data_buf, default_sbp_data_buf, sizeof(nvram_ef_sbp_modem_data_config_struct));
        }
        else
        {
            /* Read current settings in NVRAM */
            nvram_external_read_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                                     1, 
                                     (kal_uint8*)&sbp_data_buf, 
                                     NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);
        }

		custom_reset_nvram_lids(sbp_id);
		
        sbp_feature_buf.sbp_mode = sbp_id;


        if (sbp_id == 3) //for Orange
        {
            sbp_set_md_feature(SBP_HPPLMN_REGARDLESS_ANY_MCC, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_DISABLE_RPLMN_FROM_GLOCI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_ORANGE_H_PLUS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

        #if defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__)
	    // ORG_FD
            {
                kal_uint8 buf[NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE];
                nvram_ef_umts_usime_rrc_dynamic_struct* pUMTS_USIME_RRC_dynamic_cap;
 
                nvram_external_read_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
                                         1,
                                         buf,
                                         NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE);

                pUMTS_USIME_RRC_dynamic_cap = (nvram_ef_umts_usime_rrc_dynamic_struct*)buf;
                pUMTS_USIME_RRC_dynamic_cap->rrce_feature_cap |= 0x10;  

                nvram_external_write_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
                                          1,
                                          buf,
                                          NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE);
            }
        #endif
        }
        else if (sbp_id == 6) //for Vodafone
        {
            nvram_ef_regional_phone_mode_struct regional_phone_mode;
            
            regional_phone_mode.mode = 1;
            nvram_external_write_data(NVRAM_EF_REGIONAL_PHONE_MODE_LID, 
                                      1, 
                                      (kal_uint8*)&regional_phone_mode, 
                                      NVRAM_EF_REGIONAL_PHONE_MODE_SIZE);
            
            sbp_set_md_feature(SBP_MM_TRY_ABNORMAL_LAI_ONCE_MORE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_USE_SM_QOS_SUBSCRIBED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
        }
        else if (sbp_id == 7) //for AT&T
        {
            sbp_set_md_feature(SBP_USIM_CSP_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_ENS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_ENS_RAT_BALANCING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_ATNT_HPPLMN_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_DISABLE_AUTO_RETURN_PRE_RPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_DISABLE_RPLMN_FROM_GLOCI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_AT_ME_IDENTIFICATION_WITHOUT_HEADER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SAT_NO_EVDL_IN_SESSION, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_IMEI_LOCK_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_STAR_SHORT_STRING_AS_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_CUSTOMIZED_IDLE_STRING_AS_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_DISABLE_RETRY_ABNORMAL_LAI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_ILL_MS_ME_CAUSE_PS_INVALID_SIM, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_NOT_TRY_ANOTHER_RAT_FOR_LU_ABNORMAL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
			sbp_set_md_feature(SBP_SAT_REISSUE_REFRESH_AFTER_SMS_ACK, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SAT_REISSUE_REFRESH_AFTER_CALL_END, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
        }
        else if (sbp_id == 8) //for T-Mobile
        {
            sbp_set_md_feature(SBP_ATNT_HPPLMN_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_TMO_PLMN_MATCHING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_TMO_ECC_NOTIFICATION_ENABLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
        }
        else if (sbp_id == 11) //for H3G
        {
            sbp_set_md_feature(SBP_PERMANENT_AUTO_SEL_MODE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_TRY_ABNORMAL_LAI_ONCE_MORE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_HPPLMN_1ST_ATTEMPT_ENHANCE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_RPLMN_HPLMN_COMBINED_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
        }
        else if ((sbp_id == 105) /*for AMX*/ || (sbp_id == 112) /*Telcel*/ ||(sbp_id == 120) /*Claro*/)
        {

            {
              kal_uint32 pSetting;
              kal_uint8  *profile_setting_ptr = (kal_uint8*) get_ctrl_buffer(NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

              nvram_external_read_data(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
                                       1,
                                       profile_setting_ptr,
                                       NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

              kal_mem_cpy((kal_uint8*)&pSetting, profile_setting_ptr, NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

              pSetting |= 0x00400000;
              kal_mem_cpy(profile_setting_ptr,(kal_uint8*) &pSetting, NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);
              nvram_external_write_data(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
                                        1,
                                        profile_setting_ptr,
                                        NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

              free_ctrl_buffer(profile_setting_ptr);
            }

        }
        else if((sbp_id == 112) /* Telcel */ ||(sbp_id == 120)/* Claro */) 
        {
            				
#if defined(__UMTS_FDD_MODE__) && defined(__UMTS_R8__)
              
              kal_uint8 nvram_read_buf[NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE];
              nvram_ef_umts_usime_rrc_dynamic_struct* pUMTS_USIME_RRC_dynamic_cap;
              
              // Read NVRAM setting
              nvram_external_read_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
                             1,
                             nvram_read_buf,
                             NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE);
              pUMTS_USIME_RRC_dynamic_cap = (nvram_ef_umts_usime_rrc_dynamic_struct*)nvram_read_buf;               
              
              /* eFACH/eRACH/eDRX feature enable */
        	    pUMTS_USIME_RRC_dynamic_cap->r7_cap1 |= 0x04; //_MAC_EHS_SUPPORT

        	    //__CUSTOMIZE_ENHANCED_COMMON_STATE_SUPPORT__
        	    pUMTS_USIME_RRC_dynamic_cap->r7_cap1 |= 0x40; //hsdschReceptionCellUraPch (bit 7)
        	    pUMTS_USIME_RRC_dynamic_cap->r7_cap1 |= 0x20; //hsdschReceptionCellFach (bit 6)

        	    //__CUSTOMIZE_HSDSCH_DRX_CELL_FACH_SUPPORT__
        	    pUMTS_USIME_RRC_dynamic_cap->r8_cap1 |= 0x02; //supportOfHsdschDrxOperation (bit 2)

        	    //__CUSTOMIZE_MAC_IIS_SUPPORT
        	    pUMTS_USIME_RRC_dynamic_cap->r8_cap2 |= 0x04; //supportOfMACiis  (bit 3)

        	    //__CUSTOMIZE_COMMON_EDCH_SUPPORT__
        	    pUMTS_USIME_RRC_dynamic_cap->r8_cap2 |= 0x02; // supportOfCommonEDCH  (bit 2)
        	  
        	    nvram_external_write_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
                                  1,
                                  nvram_read_buf,
                                  NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE); 
                                    
#endif                          
                             
         }


        // Write new settings to NVRAM
        nvram_external_write_data(NVRAM_EF_SBP_MODEM_CONFIG_LID, 
                                  1, 
                                  (kal_uint8*)&sbp_feature_buf, 
                                  NVRAM_EF_SBP_MODEM_CONFIG_SIZE);

        nvram_external_write_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                                  1, 
                                  (kal_uint8*)&sbp_data_buf, 
                                  NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);

    }
    else
    {
        /* incorect sbp id */
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_custom_reset_rrc_dynamic_cap
 * DESCRIPTION
 *  This function will reset nvram parameters to the default value for NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID.
 * PARAMETERS
 *   null
 * RETURNS
 *****************************************************************************/
void nvram_custom_reset_rrc_dynamic_cap()
{
#if defined(__UMTS_FDD_MODE__)|| defined(__UMTS_TDD128_MODE__)

	kal_uint8* nvram_write_buf_ptr = NULL;

	if (NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
															 1,
															 &nvram_write_buf_ptr))
	{
		nvram_external_write_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE);
	}
#endif
}

/*****************************************************************************
 * FUNCTION
 *	custom_nvram_reset_regional_phone_mode
 *
 * DESCRIPTION
 *	This function will reset nvram parameters to the default value for NVRAM_EF_REGIONAL_PHONE_MODE_LID.
 *
 * PARAMETERS
 *	none
 *
 * RETURNS
 *	none
 *
 *****************************************************************************/
void custom_nvram_reset_regional_phone_mode()
{
	kal_uint8* nvram_write_buf_ptr = NULL;
	nvram_ef_regional_phone_mode_struct regional_phone_mode;
	nvram_default_value_enum result;

	result = nvram_get_default_value(NVRAM_EF_REGIONAL_PHONE_MODE_LID,
									1,
									&nvram_write_buf_ptr);

	if (NVRAM_DEFAULT_VALUE_ZERO == result)
	{
		
		regional_phone_mode.mode = 0;
		nvram_external_write_data(NVRAM_EF_REGIONAL_PHONE_MODE_LID, 
								  1, 
								  (kal_uint8*)&regional_phone_mode, 
								  NVRAM_EF_REGIONAL_PHONE_MODE_SIZE);

	}
	else if (NVRAM_DEFAULT_VALUE_FF == result)
	{
		
		regional_phone_mode.mode = 0xff;
		nvram_external_write_data(NVRAM_EF_REGIONAL_PHONE_MODE_LID, 
								  1, 
								  (kal_uint8*)&regional_phone_mode, 
								  NVRAM_EF_REGIONAL_PHONE_MODE_SIZE);

	
	}
	
	return;
}

/*****************************************************************************
 * FUNCTION
 *	custom_nvram_reset_pf_conformance_testmode
 *
 * DESCRIPTION
 *	This function will reset nvram parameters to the default value for NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID.
 *
 * PARAMETERS
 *	none
 *
 * RETURNS
 *	none
 *
 *****************************************************************************/
void custom_nvram_reset_pf_conformance_testmode()
{
	kal_uint8* nvram_write_buf_ptr = NULL;
	nvram_default_value_enum result;

	result = nvram_get_default_value(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
									1,
									&nvram_write_buf_ptr);

	if (NVRAM_DEFAULT_VALUE_ZERO == result)
	{
		
	  kal_uint32 pSetting;

	  pSetting = 0x00000000;
	  nvram_external_write_data(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
								1,
								&pSetting,
								NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);
	

	}
	else if (NVRAM_DEFAULT_VALUE_POINT == result)
	{
		nvram_external_write_data(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);
	} 
	
}

/*****************************************************************************
 * FUNCTION
 *  custom_reset_nvram_lids
 * DESCRIPTION
 *  This function will reset nvram parameters to the default value for the lids present in the table nvram_lid_reset_func_tbl
 * PARAMETERS
 *   SBP ID: this is the new sbp_id received from the CCCI
 * RETURNS
 *****************************************************************************/
void custom_reset_nvram_lids(kal_uint32 sbp_id)
{
    kal_uint8 table_size = 0, i = 0;
	nvram_ef_sbp_modem_config_struct *sbp_feature_buf;
	
	sbp_feature_buf = (nvram_ef_sbp_modem_config_struct*)get_ctrl_buffer
						(sizeof(nvram_ef_sbp_modem_config_struct));

	nvram_external_read_data(NVRAM_EF_SBP_MODEM_CONFIG_LID, 
							 1,
							 (kal_uint8*)sbp_feature_buf, 
						     NVRAM_EF_SBP_MODEM_CONFIG_SIZE);

	old_sbp_id = sbp_feature_buf->sbp_mode;


	if(old_sbp_id != sbp_id)
	{
	    table_size = sizeof(nvram_lid_reset_func_tbl)/sizeof(sbp_nvram_lid_reset_table);

		for(i = 0; i < table_size; i++)
		{
		  nvram_lid_reset_func_tbl[i].sbp_reset_nvram_lid_funcptr();
		}
	}

	// Free allocated buffer
    if (sbp_feature_buf != NULL)
    {
        free_ctrl_buffer(sbp_feature_buf);
        sbp_feature_buf = NULL;
    }
}

#endif /* NVRAM_NOT_PRESENT */
