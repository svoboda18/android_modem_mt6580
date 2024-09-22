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
 *   mm_ratcm_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ******************************************************************************/

#ifndef MM_RATCM_STRUCT_H
#define MM_RATCM_STRUCT_H

#include "l3_inc_enums.h"
#include "mcd_l3_inc_struct.h"
#include "l3_inc_local.h"
#include "l3llc_enums.h"
#include "mmllc_enums.h"
#include "as2nas_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "ps_public_enum.h"
#include "mm_ratcm_enums.h"
#include "rsvas_enum.h"
#include "kal_public_defs.h"

/* Ripple: AS/NAS common define and struct */
//#define MAX_NUM_PLMN_PER_RAT 16 

/*
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 mcc1;
    kal_uint8 mcc2; 
    kal_uint8 mcc3;
    kal_uint8 mnc1; 
    kal_uint8 mnc2;
    kal_uint8 mnc3; 
} local_plmn_id_struct;

typedef struct {
    LOCAL_PARA_HDR
    local_plmn_id_struct plmn_id;
    kal_uint8 la_code[2]; 
}local_lai_struct;

typedef struct {
    LOCAL_PARA_HDR
    local_plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
    kal_uint8 ra_code;
}local_rai_struct;
*/

/* Ripple: Remove 2006/01/13
typedef struct {
    LOCAL_PARA_HDR
    plmn_id_struct plmn_id;
    kal_uint8 power_level;
    kal_uint8 high_quality_plmn_count; 
    kal_uint8 may_suitalbe_cell_exist;
} available_plmn_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 available_plmn_count;
    kal_uint8 high_quality_plmn_count; 
    available_plmn_struct available_plmn[MAX_NUM_PLMN_PER_RAT];
} as_plmn_list_struct;
*/
/* ~Ripple */

typedef struct {
    LOCAL_PARA_HDR 
    rat_enum rat;
} mm_ratcm_set_rat_mode_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_bool is_successful;
} mm_ratcm_set_rat_mode_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR 
    //kal_uint8 prefer_band;
    kal_uint8 requested_gsm_band;
    kal_uint8 requested_umts_fdd_band[SIZE_OF_UMTS_BAND]; /* mtk00714: umts multi-band */
    kal_uint8 drx_para[2]; /* for split paging cycle and non-drx timer */
    kal_uint8 imeisv_value_digit0;
    kal_uint8 imeisv_value_digit_byte[8];
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
    gprs_transfer_preference_enum prefer;
#endif
#ifdef __HSPA_PREFERENCE_SETTING__
    hspa_preference_enum hspa_preference; /* MAUI_02361221: hspa_preference */
#endif
} mm_ratcm_init_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 trx_id;
    plmn_search_type_enum plmn_search_type;
    rat_enum rat;
    kal_uint8 plmn_id_count;
    plmn_id_struct plmn_id[MAX_NUM_SEARCH_PLMN];
    kal_bool is_manual_sel;
#if defined(__CSG_SUPPORT__) || defined (UNIT_TEST)
    kal_bool is_manual_csg_sel;
    kal_uint32 csg_id;
#endif    
    kal_bool is_ir_cell_resel_allowed;
    kal_uint16 factory_mode_arfcn; //0xFFFF means invalid arfcn, /* 20081110 mtk00714, for fast camp on test machine */    
    kal_bool  trigger_by_signal_appear;
#if defined(__UMTS_R7__) || defined (UNIT_TEST)
    kal_bool  is_higher_plmn_search; //CSCE_R7	
#endif
    scan_type_enum          scan_type;
    kal_uint32              search_period; 
} mm_ratcm_plmn_search_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 trx_id;
    plmn_search_result_enum result;
    rat_enum rat;
    plmn_id_struct selected_plmn;
    kal_bool is_uas_plmn_list_present;
    as_plmn_list_struct uas_plmn_list;
    kal_bool is_gas_plmn_list_present;
    as_plmn_list_struct gas_plmn_list;
    as_cell_type_enum   selected_cell_type; //20081027
#if defined (__R6_NETWORK_SHARING__) || defined (UNIT_TEST)
    kal_uint8 multi_plmn_count;
    plmn_id_struct multi_selected_plmn[MAX_NUM_MULTI_PLMN];
    as_cell_type_enum multi_selected_cell_type[MAX_NUM_MULTI_PLMN];
#endif
    scan_type_enum scan_type;
    kal_bool is_stored_list_exist; // only for stored search not for fullband + fullband and stored
    fullband_result_enum is_fullband_finished;
} mm_ratcm_plmn_search_cnf_struct;

typedef struct 
{ 
    LOCAL_PARA_HDR 
    kal_uint8 multi_plmn_count; 
    plmn_id_struct multi_plmn_id[MAX_NUM_MULTI_PLMN]; 
    as_cell_type_enum multi_cell_type[MAX_NUM_MULTI_PLMN];
    rat_enum rat;
    /// source from cell reselection or search 
} mm_ratcm_plmn_found_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 eq_plmn_count;
    plmn_id_struct eq_plmn_id[MAX_NUM_EQ_PLMN]; /* The eq_plmn_id[0] should be RPLMN */
} mm_ratcm_eq_plmn_list_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 plmn_id_count;
    plmn_id_struct plmn_id[MAX_NUM_HPLMN]; //MAX_NUM_HPLMN: 4
    kal_uint8 home_country_mcc[3];
} mm_ratcm_hplmn_info_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 la_code[2];
    forbidden_la_type_enum forbidden_la_type; /* forbidden_la_type_enum */
    plmn_id_struct plmn_id;
} mm_ratcm_add_forbidden_la_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 la_code[2];
    plmn_id_struct plmn_id;
    kal_bool delete_all;
} mm_ratcm_del_forbidden_la_req_struct;

#if defined(__CSG_SUPPORT__) || defined (UNIT_TEST)
typedef struct {
    LOCAL_PARA_HDR
    csg_update_type_enum csg_update_type;
    plmn_id_struct plmn_id;
    kal_uint32 csg_id;
} mm_ratcm_update_allowed_csg_list_req_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 gibi_tag;
    rat_enum rat;
    kal_bool is_data_pending;
    traffic_class_enum max_traffic_class;
    kal_bool is_sys_info_present;
#if defined (__R6_NETWORK_SHARING__) || defined (UNIT_TEST)
    kal_uint8 multi_plmn_count;
    plmn_id_struct multi_plmn_id[MAX_NUM_MULTI_PLMN];
    as_cell_type_enum multi_plmn_cell_type[MAX_NUM_MULTI_PLMN];
#endif
    plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
    kal_uint8 ra_code;
    kal_uint32 cell_id; //mtk02475: extended cell id in UMTS
    kal_bool cell_support_cs;
    kal_bool cell_support_ps; /* if FALSE, nmo and ra_code should not refer. */
    kal_bool is_acc_class_present;
    kal_uint16 acc_class;
    kal_uint8 extra_info_bitmask; /* mtk02475: for DSAC/data_speed_support update in connected mode*/
#if defined (__R6_DSAC__) || defined (UNIT_TEST)
    kal_uint8 dsac_plmn_bitmask;
    kal_uint16 cs_dsac[MAX_NUM_MULTI_PLMN];
    kal_uint16 ps_dsac[MAX_NUM_MULTI_PLMN];
#endif
    kal_uint8 t3212_timer_val;
    network_mode_enum nmo;
    as_cell_type_enum cell_type;
    att_flag_enum att_flag;
    kal_bool mscr;
    rr_mm_sgsnr_flag_enum sgsnr;
#if defined(__PS_SERVICE__) || defined (UNIT_TEST)
    data_speed_support_enum cell_data_speed_support; /* MAUI_02361221: for egprs and hspa */
#endif	

#if defined(__PPACR_SUPPORT__) || defined (UNIT_TEST)
    kal_uint8 ppacr_plmn_bitmask;
    ppacr_info_struct ppacr_info_plmn_list[MAX_NUM_MULTI_PLMN];
#endif

#if defined(__CSG_SUPPORT__) || defined (UNIT_TEST)
    kal_bool is_csg_cell;
    csg_info_struct csg_info;
#endif 

} mm_ratcm_sys_info_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_bool is_uas_plmn_list_present;
    as_plmn_list_struct uas_plmn_list;
    kal_bool is_gas_plmn_list_present;
    as_plmn_list_struct gas_plmn_list;
#ifdef __GEMINI__
    as_suspend_mode_reason_enum cause; /* for RR suspend mode */
#endif /* __GEMINI__ */
} mm_ratcm_plmn_loss_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    rat_enum rat;
    kal_bool is_manual_list;
    scan_type_enum     scan_type;
    kal_uint8 plmn_count; 
    plmn_id_struct plmn_id[MAX_NUM_EQ_PLMN];
} mm_ratcm_plmn_list_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_bool is_uas_plmn_list_present;
    as_plmn_list_struct uas_plmn_list;
    kal_bool is_gas_plmn_list_present;
    as_plmn_list_struct gas_plmn_list;
} mm_ratcm_plmn_list_cnf_struct;

#if defined(__CSG_SUPPORT__)|| defined (UNIT_TEST)
typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
    kal_uint8 plmn_count;
    plmn_id_struct plmn_id[MAX_NUM_EQ_PLMN];
} mm_ratcm_csg_list_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    //kal_bool is_uas_csg_list_present;
    as_csg_list_struct uas_csg_list;
} mm_ratcm_csg_list_cnf_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR 
    RATCM_RRC_PagingCause paging_cause; 
    domain_id_enum cn_domain_id;
    ue_id_type_enum ue_id_type;
} mm_ratcm_page_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint32 old_tlli;
    kal_uint32 new_tlli;
    tlli_update_type_enum status_tlli;
    rai_struct rai;
} mm_ratcm_tlli_assign_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_bool is_tmsi_lai_present;
    kal_uint8 tmsi[4];
    kal_bool is_lai_abnormal; /* MAUI_01959495 */
    lai_struct reg_lai;
    kal_bool is_ptmsi_rai_present;
    kal_uint8 ptmsi[4];
    kal_bool is_rai_abnormal; /* MAUI_01959495 */
    rai_struct reg_rai;
    kal_uint8 umts_ps_drx_clc;
} mm_ratcm_paging_param_assign_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    domain_id_enum cn_domain_id;
    kal_bool is_new_keys;
    kal_uint8 cksn;
    kal_bool gsm_cipher_key_infoP;
    kal_uint8 gsm_cipher_key_info[8];
    kal_uint8 ps_cipher_algo;
    kal_bool umts_keys_infoP;
    kal_uint8 umts_cipher_key_info[16];
    kal_uint8 umts_integrity_key_info[16];
} mm_ratcm_security_mode_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    sync_ind_cause_enum cause;
    channel_type_enum channel_type; /* channel_type_enum */
    channel_mode_enum channel_mode; /* channel_mode_enum */
    kal_uint8 si;
    kal_bool is_cipher_on;
} mm_ratcm_sync_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    domain_id_enum cn_domain_id;
    kal_bool is_integrity_enabled;
    Ciphering_Status umts_ciphering_status;
    kal_uint8 service_req_mui;
} mm_ratcm_security_mode_complete_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    domain_id_enum cn_domain_id;
    Ciphering_Status umts_ciphering_status; /* Ciphering_Status */
} mm_ratcm_security_mode_change_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 mui;
    kal_uint16 gibi_tag;
    domain_id_enum cn_domain_id;
    mm_ratcm_est_cause_enum estb_cause; 
    peer_msg_id_struct peer_msg_id;
    kal_bool is_service_req;
#if defined (__R6_DSAC__) || defined (UNIT_TEST)
    kal_bool is_dsac_present;
    kal_uint16 selected_dsac_info;
#endif
#if defined (__R6_NETWORK_SHARING__) || defined (UNIT_TEST)
    plmn_id_struct selected_plmn;
#endif

#if defined(__PPACR_SUPPORT__) || defined (UNIT_TEST)
   ppac_checked_type_enum   PPACCheckedType;
   kal_uint16             selectedPPACInfo; //used by PPAC_LR_ALLOWED
#endif

} mm_ratcm_conn_est_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    as_est_cnf_cause_enum result; 
    kal_bool wait_gibi_flag;
} mm_ratcm_conn_est_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_successful;
    domain_id_enum cn_domain_id;
} mm_ratcm_conn_est_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    as_rel_scope_enum scope;
} mm_ratcm_conn_rel_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    as_rel_scope_enum scope;
    kal_bool ps_resume_flag;
    kal_bool wait_gibi_flag;
} mm_ratcm_conn_rel_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    RATCM_RRC_ReleaseCause cause;
    kal_bool ps_resume_flag;
    kal_bool wait_gibi_flag;
} mm_ratcm_conn_rel_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    regn_proc_status_enum mm_proc_status;
    kal_uint32 t3212_or_t3302;
    gmm_ms_state_enum ms_state;
    mmas_regn_status_enum regn_status;
    plmn_search_status_enum plmn_search_status; 
    plmn_search_type_enum plmn_search_type;	/* new plmn search type */
    lai_struct lai; /* for GAS bar cell */
    kal_uint32 cell_id; /* for GAS bar cell */
#if defined(__REL8__) || defined (UNIT_TEST)
    kal_uint8 r_eq_plmn_count;
    plmn_id_struct r_eq_plmn_id[MAX_NUM_EQ_PLMN];
#endif
} mm_ratcm_regn_status_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    action_on_ready_timer_enum action;
    gmm_ms_state_enum new_state;
    kal_uint32 value;
} mm_ratcm_ready_timer_update_req_struct; /* should be same as ratcm_gas_ready_timer_update_req_struct. */

typedef struct {
    LOCAL_PARA_HDR 
    ready_timer_status_enum status;
} mm_ratcm_ready_timer_update_ind_struct; /* should be same as ratcm_gas_ready_timer_update_ind_struct. */

typedef struct {
    LOCAL_PARA_HDR 
    kal_bool is_gprs_required;
} mm_ratcm_service_change_req_struct; /* Should same as ratcm_gas_service_change_req_struct. */

typedef struct {
    LOCAL_PARA_HDR      
    kal_uint8 mui;
    kal_uint16 gibi_tag;
    DC_Priority  priority;
    kal_bool is_service_req;
} mm_ratcm_cs_data_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_bool is_integrity_applied;
} mm_ratcm_cs_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 mui;
    kal_uint16 gibi_tag;
    llc_sapi_enum sapi;
    rp_enum radio_priority;
    kal_uint8 cipher_ind;
    res_req_cause msg_type;
    kal_uint8 nsapi;
    kal_uint32 tlli;
    kal_uint8 pfi;
    concise_qos_struct qos_param;    
    peer_msg_id_struct peer_msg_id;
} mm_ratcm_ps_data_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    //kal_uint8 mui;
    DC_Status status;
    peer_msg_id_struct peer_msg_id;
} mm_ratcm_ps_data_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_integrity_applied;    
    kal_uint32 tlli;
} mm_ratcm_ps_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_bool is_cs_reset_keys;
    kal_bool is_ps_reset_keys;
} mm_ratcm_reset_keys_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint32 tlli;
} mm_ratcm_llc_resume_req_struct; /* Should be same as ratcm_llc_resume_req_struct */

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint32 tlli;
} mm_ratcm_llc_suspend_req_struct; /* Should be same as ratcm_llc_suspend_req_struct */

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint32 tlli;
    res_req_cause cause; /* res_req_cause */
    llgmm_cell_update_type_enum cell_update_type; /* llgmm_cell_update_type_enum */
} mm_ratcm_llc_trigger_req_struct; /* Should be same as ratcm_llc_trigger_req_struct */

#ifdef __PS_HO__
typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 cipher_algo;    
} mm_ratcm_llc_psho_ind_struct; /* Should be same as ratcm_llc_psho_ind_struct */
#endif

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_expiry; /*KAL_TRUE: T3122 expires, MM will retry LU immediately
						  KAL_FALSE: T3122 is stopped */
} mm_ratcm_t3122_timeout_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_expiry; /*KAL_TRUE: CCO activation time expires, MM will retry LU immediately
						  KAL_FALSE: CCO activation time is stopped */
} mm_ratcm_cco_activation_time_timeout_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    rat_enum rat;
} mm_ratcm_signal_appear_ind_struct;

#ifdef __DYNAMIC_BAND_SEL__
typedef struct {
    LOCAL_PARA_HDR
    band_selection_enum gsm_band; /* refer to band_selection_enum value*/ 
    kal_bool is_gsm_band_present;  
    kal_uint8 umts_fdd_band[SIZE_OF_UMTS_BAND];    /* 3G band change */
    kal_bool is_umts_band_present; /* 3G band change */
}mm_ratcm_set_preferred_band_req_struct;
#endif

#ifdef __GEMINI__
typedef struct {
    LOCAL_PARA_HDR
    sim_config_status_enum sim_config_status;
    sim_insert_status_enum sim_insert_status;
} mm_ratcm_sim_status_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 req_id;
} mm_ratcm_ps_session_start_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_success; /*TRUE if session can be started*/
    kal_uint8 req_id;
} mm_ratcm_ps_session_start_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    rsvas_service_type_enum cause;
} mm_ratcm_suspend_ind_struct;

#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
//mtk02475: local param struct is only exist in GEMINI 2.0 project
typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_virtual_idle_mode;
} mm_ratcm_resume_ind_struct;
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_virtual_idle_mode;
} mm_ratcm_virtual_mode_ind_struct;
#endif /* __GEMINI__ */

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
typedef struct {
    LOCAL_PARA_HDR
    gprs_transfer_preference_enum prefer;
} mm_ratcm_set_gprs_transfer_preference_req_struct;
#endif

/* MAUI_02852442, __NO_PSDATA_SEND_SCRI__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_bool force_send_SCRI;
	end_session_cause_enum cause;
}mm_ratcm_end_ps_data_session_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    end_session_result_enum cause;
}mm_ratcm_end_ps_data_session_cnf_struct;
/* __NO_PSDATA_SEND_SCRI__ */

typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
    domain_id_enum connection_domain;
} mm_ratcm_cell_change_finish_ind_struct;

/* MAUI_03101878, [Silver Clam][CV][SilverClam-94]Pre-CV-CMAS: GPRS failed due to timeout */
typedef struct {
    LOCAL_PARA_HDR
    lai_struct current_lai;
} mm_ratcm_cb_loc_update_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_bool is_sim_inserted;
} mm_ratcm_sim_info_reset_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
    kal_uint32 cell_id;
    kal_bool  is_la_valid;
    kal_uint8 la_code[2];
    kal_bool  is_ra_valid;
    kal_uint8 ra_code;
    kal_uint8 multi_plmn_count;
    plmn_id_struct multi_plmn_id[MAX_NUM_MULTI_PLMN];
} mm_ratcm_cell_global_identity_info_ind_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    RATCM_RRC_LocalReleaseType localReleaseType;
    kal_uint16 locally_released_PS_RAB_bitmap;
    traffic_class_enum max_traffic_class;
} mm_ratcm_local_release_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 imeisv_value_digit0;
    kal_uint8 imeisv_value_digit_byte[8];
}mm_ratcm_set_imei_req_struct;

#endif /* MM_RATCM_STRUCT_H */
