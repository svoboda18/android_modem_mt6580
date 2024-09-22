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
 * spc_drv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MD speech control  
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "kal_trace.h"
#include "string.h"
#include "fsal.h"

// #include "l1audio.h"

#include "audio_enum.h"
#include "l1audio_def.h"
#include "am.h"
#include "afe.h"
#include "media.h"
#include "l1sp_trc.h"
#include "audcoeff_default.h"
#include "dcl.h"


#include "spc_io.h"
#include "audio_em_struct.h"
#include "aud_common_config.h" // for DEFAULT_SPEECH_COMMON_PARA. in customer folder


#include "spc_drv.h" // including "sp_drv.h" 
#include "pcm4way.h"
#include "pcmrec.h"
#include "rawpcmrec.h"
#include "bgSnd.h"
#include "ctm_drv.h"
#include "vm.h"
#include "sidetone.h"
//TO DO #include "mml1_rf_global.h"

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#endif

typedef enum {
	SPC_APP_SPEECH_USAGE = 0,	
	SPC_APP_PCMNWAY_USAGE,
	SPC_APP_RECORD_USAGE, // either "SPC_APP_RECORD_USAGE" or "SPC_APP_PCM_REC_USAGE & SPC_APP_VM_REC_USAGE" usage
	SPC_APP_BGSND_USAGE,	
	
	SPC_APP_CTM_USAGE,
	SPC_APP_ACLOOPBACK_USAGE,

	SPC_APP_PCM_REC_USAGE, // 6, add from MT658 chip
	SPC_APP_VM_REC_USAGE,
	
	SPC_APP_HOLD_USAGE, // cannot mix with other speech application
	SPC_APP_HOSTED_USAGE,	
	SPC_APP_PCMROUTER_USAGE, 

	//We can't enable all record function, only following selections are acceptable:
	//1. SPC_APP_RECORD_USAGE
	//2. SPC_APP_PCM_REC_USAGE
	//3. SPC_APP_PCM_REC_USAGE     + SPC_APP_VM_REC_USAGE
	//4. SPC_APP_RAW_PCM_REC_USAGE
	//5. SPC_APP_RAW_PCM_REC_USAGE + SPC_APP_VM_REC_USAGE
	SPC_APP_RAW_PCM_REC_USAGE, //11, add from MT6752 chip
	
	SPC_APP_MAX = 16 // due to spcAppUsage is uint16. so only 16 application can existing.
} MSG_SPC_APP_T;

typedef enum{
	SPC_EM_INIT_COMMON = 0,
	SPC_EM_INIT_WB,
	SPC_EM_INIT_DMNR,
	SPC_EM_INIT_LSPK_DMNR,

	SPC_EM_INIT_MAX = 16 // due to spcEmInit is unit16, so only 16 em data message can existing. 
} SPC_EM_INIT_T;

typedef struct _SPC_T_
{
	kal_uint16           spcGetEpofTimes;
	kal_uint16           spFeatureList;
	kal_uint16           spcAppUsage; //Please reference MSG_SPC_APP_T for bit definition

	kal_uint16           spcEmInit; 

	// DSP mute 
	kal_bool             spcMuteUl;
	kal_bool             spcMuteDl;

	kal_bool             spcMuteUlEnhResult;
	kal_bool             spcMuteUlSource;
} _SPC_T;


typedef struct spcBufInfoStruct 
{
   uint16 syncWord;
   uint16 type;
   uint16 length;
} spcBufInfo;

// ----------------------------------------------------------------------------
// Global Variable
// ----------------------------------------------------------------------------

static _SPC_T gSpc;

__attribute__((aligned (4)))static kal_uint8 emDataBuf[4096];


// ----------------------------------------------------------------------------
// Macro function
// ----------------------------------------------------------------------------

#define IS_SPC_APP_USED(app)     ((gSpc.spcAppUsage & (1 << (app))) != 0)
#define SET_SPC_APP_USAGE(app)   (gSpc.spcAppUsage |= (1 << (app)))
#define CLR_SPC_APP_USAGE(app)   (gSpc.spcAppUsage &= (~(1 << (app))))


#define IS_SPC_EM_INIT(emPara)   ((gSpc.spcEmInit& (1 << (emPara))) != 0)
#define SET_SPC_EM_INIT(emPara)    (gSpc.spcEmInit |= (1 << (emPara)))

#define IS_SPC_ID_SPEECH_CUSTOM_DATA_REQUEST_DONE (IS_SPC_EM_INIT(SPC_EM_INIT_COMMON)) // using comm parameter data notify as EM data request ack
// ----------------------------------------------------------------------------
// Internal Init Related
// ----------------------------------------------------------------------------

// following constant inside ./custom/driver/common/aud_common.c
extern const unsigned short Speech_Normal_Mode_Para[16];
extern const unsigned short Speech_Earphone_Mode_Para[16];
extern const unsigned short Speech_LoudSpk_Mode_Para[16];
extern const unsigned short Speech_BT_Earphone_Mode_Para[16];
extern const unsigned short Speech_BT_Cordless_Mode_Para[16];
extern const unsigned short Speech_CARKIT_Mode_Para[16];
extern const unsigned short Speech_AUX1_Mode_Para[16];
extern const unsigned short Speech_AUX2_Mode_Para[16];
#ifdef __AMRWB_LINK_SUPPORT__
extern const unsigned short WB_Speech_Normal_Mode_Para[16];
extern const unsigned short WB_Speech_Earphone_Mode_Para[16];
extern const unsigned short WB_Speech_LoudSpk_Mode_Para[16];
extern const unsigned short WB_Speech_BT_Earphone_Mode_Para[16];
extern const unsigned short WB_Speech_BT_Cordless_Mode_Para[16];
extern const unsigned short WB_Speech_CARKIT_Mode_Para[16];
extern const unsigned short WB_Speech_AUX1_Mode_Para[16];
extern const unsigned short WB_Speech_AUX2_Mode_Para[16];
#endif

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
#ifdef __AMRWB_LINK_SUPPORT__
extern const signed short WB_DMNR_Para[76];
extern const signed short LSpk_WB_DMNR_Para[76];
#endif
extern const signed short DMNR_Para[44];
extern const signed short LSpk_DMNR_Para[44];
#endif


/**

*/
void spc_EmInit(kal_bool isNeedBasic, kal_bool isNeedWb, kal_bool isNeedDmnr, kal_bool isNeedLspkDmnr)
{
	kal_trace(TRACE_INFO, SPC_EM_DEFAULT_INIT, isNeedBasic, isNeedWb, isNeedDmnr, isNeedLspkDmnr);
	
	// ====== parameters from EM =======	
	if(isNeedBasic){
		// common parameter
		uint16 commonP[] = DEFAULT_SPEECH_COMMON_PARA;
		L1SP_LoadCommonSpeechPara(commonP);
	
		// mode parameter
		AUDIO_CUSTOM_PARAM_STRUCT *audio_par;	
		audio_par = (AUDIO_CUSTOM_PARAM_STRUCT *)(&emDataBuf); //buffer reuse
	   memcpy(&(audio_par->speech_mode_para[0]), Speech_Normal_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_para[1]), Speech_Earphone_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_para[2]), Speech_LoudSpk_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_para[3]), Speech_BT_Earphone_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_para[4]), Speech_BT_Cordless_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_para[5]), Speech_CARKIT_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_para[6]), Speech_AUX1_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_para[7]), Speech_AUX2_Mode_Para, 16*sizeof(uint16)) ;	
		l1sp_setAllSpeechModePara((uint16 *)(audio_par->speech_mode_para), 8 * 16);
	
	
		// FIR
		l1sp_setAllSpeechFirCoeff_InputOnly((int16 *)Speech_Input_FIR_Coeff, 6*45);
		l1sp_setAllSpeechFirCoeff_OutputOnly((int16 *)Speech_Output_FIR_Coeff, 6*45);
	}

	if(isNeedWb){
		// WB FIR
#ifdef __AMRWB_LINK_SUPPORT__	
		// in customer folder's Audcoeff.c
		
		AUDIO_CUSTOM_WB_PARAM_STRUCT *audio_par;	
		audio_par = (AUDIO_CUSTOM_WB_PARAM_STRUCT *)(&emDataBuf); //buffer reuse
	   memcpy(&(audio_par->speech_mode_wb_para[0]), WB_Speech_Normal_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_wb_para[1]), WB_Speech_Earphone_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_wb_para[2]), WB_Speech_LoudSpk_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_wb_para[3]), WB_Speech_BT_Earphone_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_wb_para[4]), WB_Speech_BT_Cordless_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_wb_para[5]), WB_Speech_CARKIT_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_wb_para[6]), WB_Speech_AUX1_Mode_Para, 16*sizeof(uint16)) ;
		memcpy(&(audio_par->speech_mode_wb_para[7]), WB_Speech_AUX2_Mode_Para, 16*sizeof(uint16)) ;	
		l1sp_setAllWbSpeechModePara((uint16 *)(audio_par->speech_mode_wb_para), 8 * 16);
		
		extern const signed short WB_Speech_Input_FIR_Coeff[6][90];
		extern const signed short WB_Speech_Output_FIR_Coeff[6][90];
		
		l1sp_setAllWbSpeechFirCoeff_InputOnly((int16 *)WB_Speech_Input_FIR_Coeff, 6*90);
		l1sp_setAllWbSpeechFirCoeff_OutputOnly((int16 *)WB_Speech_Output_FIR_Coeff, 6*90);
#endif // __AMRWB_LINK_SUPPORT__
	}

	if(isNeedDmnr){
		
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
#ifdef __AMRWB_LINK_SUPPORT__
		L1SP_SetWbDMNRPara(WB_DMNR_Para);
#endif
		L1SP_SetDMNRPara(DMNR_Para);
#endif //  defined(__DUAL_MIC_SUPPORT__)|| defined(__SMART_PHONE_MODEM__)
		
	}

	if(isNeedLspkDmnr){ // load param when begin run
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
#ifdef __AMRWB_LINK_SUPPORT__
		L1SP_SetLSpkWbDMNRPara(LSpk_WB_DMNR_Para);
#endif
		L1SP_SetLSpkDMNRPara(LSpk_DMNR_Para);
#endif //  defined(__DUAL_MIC_SUPPORT__)|| defined(__SMART_PHONE_MODEM__)		
	}
	
	// loading!!
	// if(isNeedBasic || isNeedWb) {
	// 	L1SP_LoadSpeechPara();	
	// }
}

/**
	@app: app to be enable
	@return: check result, true for pass, false for fail
*/
bool spc_mainAppOnCheck(MSG_SPC_APP_T app, bool byPassEmDataCheck)
{
	if((!IS_SPC_ID_SPEECH_CUSTOM_DATA_REQUEST_DONE) && (false == byPassEmDataCheck)){ // prevent speech on before EM data sending
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, app, app, 1);
		return false;
	}

	// other related check
	if(SPC_APP_SPEECH_USAGE != app) {
		if(IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) {
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR_CHECK, app, SPC_APP_SPEECH_USAGE, SPC_APP_SPEECH_USAGE, gSpc.spcAppUsage);
			
			ASSERT(0);

			return false;
		}
	}

	if(SPC_APP_ACLOOPBACK_USAGE != app) {
		if(IS_SPC_APP_USED(SPC_APP_ACLOOPBACK_USAGE)) {
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR_CHECK, app, SPC_APP_ACLOOPBACK_USAGE, SPC_APP_ACLOOPBACK_USAGE, gSpc.spcAppUsage);
			
			ASSERT(0);

			return false;
		}
	}
	
	

	if(SPC_APP_HOLD_USAGE != app) {
		if(IS_SPC_APP_USED(SPC_APP_HOLD_USAGE)) {
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR_CHECK, app, SPC_APP_HOLD_USAGE, SPC_APP_HOLD_USAGE, gSpc.spcAppUsage);
			
			ASSERT(0);

			return false;
		}
	}

	if(SPC_APP_HOSTED_USAGE != app) {
		if(IS_SPC_APP_USED(SPC_APP_HOSTED_USAGE)) {
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR_CHECK, app, SPC_APP_HOSTED_USAGE, SPC_APP_HOSTED_USAGE, gSpc.spcAppUsage);
			
			ASSERT(0);

			return false;
		}
	}

	if(SPC_APP_PCMROUTER_USAGE != app) {
		if(IS_SPC_APP_USED(SPC_APP_PCMROUTER_USAGE)) {
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR_CHECK, app, SPC_APP_PCMROUTER_USAGE, SPC_APP_PCMROUTER_USAGE, gSpc.spcAppUsage);
			
			ASSERT(0);

			return false;
		}
	}

	return true;
}

// ----------------------------------------------------------------------------
// Phone Call Related
// ----------------------------------------------------------------------------

void Spc_SpeechOn( kal_uint8 RAT_Mode )
{
#if defined(SPH_CHIP_BACK_PHONECALL_USE)

#else

	if(!IS_SPC_ID_SPEECH_CUSTOM_DATA_REQUEST_DONE){ // prevent speech on before EM data sending
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_SPEECH_USAGE, SPC_APP_SPEECH_USAGE, 1);
		return;
	}
#endif		
	
	ASSERT(RAT_Mode <= RAT_3G324M_MODE);

#ifdef CONNECT_WM8904
	Config_WM8904(MIC_8K_LONGSYNC_PHONE_CALL); //Config_WM8904(-1); MIC_8K_LONGSYNC_PHONE_CALL == 2
#endif	

	// checking speech useage parameter. if Not, use the default value. 
	spc_EmInit(!IS_SPC_EM_INIT(SPC_EM_INIT_COMMON), 
		!IS_SPC_EM_INIT(SPC_EM_INIT_WB),!IS_SPC_EM_INIT(SPC_EM_INIT_DMNR),
		!IS_SPC_EM_INIT(SPC_EM_INIT_LSPK_DMNR));

	// rate setting
#if defined(__UMTS_RAT__)
	if( RAT_Mode != RAT_3G324M_MODE )
		RAT_Mode = RAT_3G_MODE; // Force initial 3G
#else
		RAT_Mode = RAT_2G_MODE;
#endif

	// 
   kal_trace( TRACE_INFO, SPC_SPEECH_ON, RAT_Mode);

	// set sidetone solution ver before application start
	SIDETONE_SetSolutionVer(SMART_PHONE_SIDETONE_SOLUTION_VER);
  
	L1SP_Speech_On( RAT_Mode );

	SET_SPC_APP_USAGE(SPC_APP_SPEECH_USAGE);

	// enable sidetone update
	//SIDETONE_UpdateStart();


}

void Spc_SpeechOff( void )
{   
	kal_trace( TRACE_INFO, SPC_SPEECH_OFF);


	// [TODO] REMOVE
	ASSERT(0==IS_SPC_APP_USED(SPC_APP_PCMNWAY_USAGE));
	ASSERT(0==IS_SPC_APP_USED(SPC_APP_RECORD_USAGE));
	ASSERT(0==IS_SPC_APP_USED(SPC_APP_PCM_REC_USAGE));
	ASSERT(0==IS_SPC_APP_USED(SPC_APP_VM_REC_USAGE));
	ASSERT(0==IS_SPC_APP_USED(SPC_APP_BGSND_USAGE));

	if(!IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)){
		// just leave log and return
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_SPEECH_USAGE, SPC_APP_SPEECH_USAGE, 0);
		return; 
	} 
	
	// disalbe sidetone update
	//SIDETONE_UpdateStop();

	// close speech 
	L1SP_Speech_Off();

	CLR_SPC_APP_USAGE(SPC_APP_SPEECH_USAGE);

	// reset sieton solution ver after application stop
	SIDETONE_ResetSolutionVer();
}


void Spc_SetSpeechMode_Adaptation( uint8 mode )
{
   int16 totalModeNum;

	kal_trace( TRACE_INFO, SPC_SET_SPEECHMODE_ADAPT, mode);

	//[REMIND] For MT6589, idle recording function are implement in AP side, 
	// so record mode information is not existing in MD side
   totalModeNum = (SPH_MODE_UNDEFINED-1); // + l1sp_getNumOfRecordMode();
   if (mode >= totalModeNum) {
      ASSERT(0);
   }

#if defined(__DUAL_TALK_MODEM_SUPPORT__)      
	//only for this project. Because we don't have bt task to do this, l1audio do it by myself
#define BTRADIO_PCM_GPIO_ENABLE   (0x01)
#define BTRADIO_PCM_GPIO_DISABLE  (0x00)
			 
	if(mode == SPH_MODE_BT_EARPHONE){
		BtRadio_PCM_GPIOSetup(BTRADIO_PCM_GPIO_ENABLE);
	}else{
		BtRadio_PCM_GPIOSetup(BTRADIO_PCM_GPIO_DISABLE);
	}
#endif

   // [REMIND] Because Smart phone only has 8 speech mode, which is different from l1audio.h's definition. 
   //As the result, we need to mapping the mode into the correct one. 
   L1SP_SetSpeechEnhanceAndFir(mode, SPH_ENH_AND_FIR_UPDATE_TYPE_ALL);

}

/**
	@return: result of existing compile option related to speech function
		bit 0: __DUAL_MIC_SUPPORT__
		bit 1: __AMRWB_LINK_SUPPORT__
		bit 2 ~ 15: reserve for future use
*/
kal_uint16 spc_QueryMdCapability(void)
{
	kal_uint16 result = 0;

	// bit 0
	#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
	result |= (1<<0);
	#endif // __DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)

	// bit 1
	#if defined(__AMRWB_LINK_SUPPORT__)
	result |= (1<<1);
	#endif // __AMRWB_LINK_SUPPORT__

	// bit 2 (for future use)
	//
	
	return result;
}

void spc_DebugPrint(void)
{
	// TODO:
}


//AUDL task
void spc_notify_rf_info(void)
{
//TO DO 

	uint16 rf_info = 0x0;
	uint16 rf_2g, rf_3g, rf_4g;	
//at default there exists 2G in the system
#if 0   
/* under construction !*/
#if defined( __UMTS_RAT__ ) 
#if defined( __UMTS_TDD128_MODE__ )
/* under construction !*/
#else
/* under construction !*/
#endif   
#else   
/* under construction !*/
#endif
#if defined( __VOLTE_SUPPORT__ ) 
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
  rf_info = 0xFFFF;
	kal_trace(TRACE_INFO, SPC_NOTIFY_RF_INFO, rf_info, rf_2g, rf_3g, rf_4g);
	SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_RF_INFO_NOTIFY, (kal_uint16)rf_info, 0);
}

//AUDL task
void spc_notify_network_status(void)
{
	kal_bool isWB = AM_IsSpeechWB();
	uint32 RAT = AM_GetNetworkRate();
	
	uint16 tmp = (kal_uint16)((isWB & 0x1) << 3 | (RAT & 0x7));
	kal_trace(TRACE_INFO, SPC_NOTIFY_NETWORK_STATUS, tmp & 0xFF, isWB, RAT);
	SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_NETWORK_STATUS_NOTIFY, (kal_uint16)tmp, 0);
}

//AUDIO task
void spc_send_network_status_notify(void)
{
	 SpcIO_MsgQueuePut(SPC_ID_NETWORK_STATUS_NOTIFY, 0, 0, 2);
}

/**
	@isGen: true for trun on, false for turn off
*/
void spc_SpeechOnForCallHold(kal_bool isGen)
{

	
	if(isGen){ // turn on

		if(!IS_SPC_ID_SPEECH_CUSTOM_DATA_REQUEST_DONE){ // prevent call hold on before EM data sending
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_HOLD_USAGE, SPC_APP_HOLD_USAGE, 3);
			return;
		}
		
		if(IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) {
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_HOLD_USAGE, SPC_APP_HOLD_USAGE, 1);

			// [TODO] REMOVE
			ASSERT(0);

			return;
		}	

		// turn on speech and mute
		L1SP_Speech_On(RAT_3G_MODE);
		SP_MuteUlFromDiffPos(true, SP_MIC_MUTE_POS_FROM_SPC);//L1SP_MuteMicrophone(true);

		SET_SPC_APP_USAGE(SPC_APP_HOLD_USAGE);
	} else { // turn off
	
		if(!IS_SPC_APP_USED(SPC_APP_HOLD_USAGE)) { // sid generation not in use
			// just leave the log and return
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_HOLD_USAGE, SPC_APP_HOLD_USAGE, 0);			
			return;
		}

		if(IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) { // phone call 
			// just leave the log and return
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_HOLD_USAGE, SPC_APP_HOLD_USAGE, 2);			

			// [TODO] REMOVE
			ASSERT(0);

			return;
		}

		// turn off 
		SP_MuteUlFromDiffPos(false, SP_MIC_MUTE_POS_FROM_SPC); // L1SP_MuteMicrophone(false);
		L1SP_Speech_Off();
		CLR_SPC_APP_USAGE(SPC_APP_HOLD_USAGE);
	}
	
}

// ----------------------------------------------------------------------------
// Loopback
// ----------------------------------------------------------------------------
#define ACLOOPBACK_USING_P2W 0

#define ACLOOPBACK_FRAME_BUF_NO (64) // REMIND: should be pow of 2 
#define ACLOOPBACK_NB_FRAME_SIZE   (160)
#define ACLOOPBACK_DELAY 12 // unit is 20ms 

#if ACLOOPBACK_USING_P2W
static uint16 gSpc_acLoopback_PCM_BUF[ACLOOPBACK_FRAME_BUF_NO][ACLOOPBACK_NB_FRAME_SIZE];
#else
// static uint16 gSpc_acLoopback_PCM_UL_BUF[ACLOOPBACK_FRAME_BUF_NO][ACLOOPBACK_NB_FRAME_SIZE];
static uint16 gSpc_acLoopback_PCM_UL_BUF[ACLOOPBACK_NB_FRAME_SIZE];
static uint16 gSpc_acLoopback_PCM_DL_BUF[ACLOOPBACK_FRAME_BUF_NO][ACLOOPBACK_NB_FRAME_SIZE];
#endif 

typedef struct 
{
	uint32 delay;
#if ACLOOPBACK_USING_P2W	
	uint32 tmp_w;
	uint32 tmp_r;
#else	
	// uint32 UL_tmp_w;
	// uint32 UL_tmp_r;
	uint32 DL_tmp_w;
	uint32 DL_tmp_r;
#endif

} _SPC_ACOUSTIC_LOOPBACK_T;

static _SPC_ACOUSTIC_LOOPBACK_T gSpc_acLoopback;

#if ACLOOPBACK_USING_P2W
void AcousticLoopback_PCM2WAY_UL_HisrHdl()
#else
void AcousticLoopback_PCM4WAY_UL_HisrHdl()
#endif
{

#if ACLOOPBACK_USING_P2W

	/*	P2W */
   if( (gSpc_acLoopback.tmp_w - gSpc_acLoopback.tmp_r) < ACLOOPBACK_FRAME_BUF_NO ){        
      PCM2WAY_GetFromMic((uint16*)gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)]);
      kal_dev_trace( TRACE_INFO,SPC_AC_LOOPBACK_FROM_MIC, 
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][0],
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][1],
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][2],
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][3]);         
      (gSpc_acLoopback.tmp_w)++;            
   }else{
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_SKIP_MIC); 
   }
	
#else
	/* P4W UL with delay
	if( (gSpc_acLoopback.UL_tmp_w - gSpc_acLoopback.UL_tmp_r) < ACLOOPBACK_FRAME_BUF_NO ){        
      PCM4WAY_GetFromMic((uint16*)gSpc_acLoopback_PCM_UL_BUF[gSpc_acLoopback.UL_tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)]);
      kal_dev_trace( TRACE_INFO,SPC_AC_LOOPBACK_FROM_MIC, 
                       gSpc_acLoopback_PCM_UL_BUF[gSpc_acLoopback.UL_tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][0],
                       gSpc_acLoopback_PCM_UL_BUF[gSpc_acLoopback.UL_tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][1],
                       gSpc_acLoopback_PCM_UL_BUF[gSpc_acLoopback.UL_tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][2],
                       gSpc_acLoopback_PCM_UL_BUF[gSpc_acLoopback.UL_tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][3]);         
      (gSpc_acLoopback.UL_tmp_w)++;            
   }else{
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_SKIP_MIC); 
   }

   if( (gSpc_acLoopback.UL_tmp_w - gSpc_acLoopback.UL_tmp_r) >= gSpc_acLoopback.delay ){
      PCM4WAY_PutToSE(gSpc_acLoopback_PCM_UL_BUF[gSpc_acLoopback.UL_tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)]);   
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_TO_SE, 
                       gSpc_acLoopback_PCM_UL_BUF[gSpc_acLoopback.UL_tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][0],
                       gSpc_acLoopback_PCM_UL_BUF[gSpc_acLoopback.UL_tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][1],
                       gSpc_acLoopback_PCM_UL_BUF[gSpc_acLoopback.UL_tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][2],
                       gSpc_acLoopback_PCM_UL_BUF[gSpc_acLoopback.UL_tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][3]);               
      (gSpc_acLoopback.UL_tmp_r)++;
   }else{
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_FILL_SE); 
      PCM4WAY_FillSE(0);
   }
   */

	// P4W UL without delay
	PCM4WAY_GetFromMic(gSpc_acLoopback_PCM_UL_BUF);
   kal_dev_trace( TRACE_INFO,SPC_AC_LOOPBACK_FROM_MIC, 
                    gSpc_acLoopback_PCM_UL_BUF[0],
                    gSpc_acLoopback_PCM_UL_BUF[1],
                    gSpc_acLoopback_PCM_UL_BUF[2],
                    gSpc_acLoopback_PCM_UL_BUF[3]); 
	
	PCM4WAY_PutToSE(gSpc_acLoopback_PCM_UL_BUF); 
	kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_TO_SE, 
                    gSpc_acLoopback_PCM_UL_BUF[0],
                    gSpc_acLoopback_PCM_UL_BUF[1],
                    gSpc_acLoopback_PCM_UL_BUF[2],
                    gSpc_acLoopback_PCM_UL_BUF[3]);  
   
#endif
}

#if ACLOOPBACK_USING_P2W
void AcousticLoopback_PCM2WAY_DL_HisrHdl()
#else
void AcousticLoopback_PCM4WAY_DL_HisrHdl()
#endif
{
#if ACLOOPBACK_USING_P2W
	/* P2W */
	if( (gSpc_acLoopback.tmp_w - gSpc_acLoopback.tmp_r) >= gSpc_acLoopback.delay){		
      PCM2WAY_PutToSpk(gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)]);  
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_TO_SPK, 
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][0],
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][1],
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][2],
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][3]);         
      (gSpc_acLoopback.tmp_r)++;   
	}else{
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_FILL_SPK); 
      PCM2WAY_FillSpk(0);   
   }
	
	kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_UL_DL_INDEX, 
		gSpc_acLoopback.tmp_w, gSpc_acLoopback.tmp_r, 0, 0);
#else


   if( (gSpc_acLoopback.DL_tmp_w - gSpc_acLoopback.DL_tmp_r) < ACLOOPBACK_FRAME_BUF_NO ){        
      PCM4WAY_GetFromSD((uint16*)gSpc_acLoopback_PCM_DL_BUF[gSpc_acLoopback.DL_tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)]);
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_FROM_SD, 
                       gSpc_acLoopback_PCM_DL_BUF[gSpc_acLoopback.DL_tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][0],
                       gSpc_acLoopback_PCM_DL_BUF[gSpc_acLoopback.DL_tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][1],
                       gSpc_acLoopback_PCM_DL_BUF[gSpc_acLoopback.DL_tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][2],
                       gSpc_acLoopback_PCM_DL_BUF[gSpc_acLoopback.DL_tmp_w & (ACLOOPBACK_FRAME_BUF_NO - 1)][3]);
      (gSpc_acLoopback.DL_tmp_w)++;            
   }else{
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_SKIP_SD); 
   }

	
   if( (gSpc_acLoopback.DL_tmp_w - gSpc_acLoopback.DL_tmp_r) >= gSpc_acLoopback.delay){
		/* P2W
   if( (gSpc_acLoopback.tmp_w - gSpc_acLoopback.tmp_r) >= gSpc_acLoopback.delay){		
      PCM2WAY_PutToSpk(gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)]);  
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_TO_SPK, 
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][0],
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][1],
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][2],
                       gSpc_acLoopback_PCM_BUF[gSpc_acLoopback.tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][3]);         
      (gSpc_acLoopback.tmp_r)++;          
		*/
		PCM4WAY_PutToSpk(gSpc_acLoopback_PCM_DL_BUF[gSpc_acLoopback.DL_tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)]);  
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_TO_SPK, 
                       gSpc_acLoopback_PCM_DL_BUF[gSpc_acLoopback.DL_tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][0],
                       gSpc_acLoopback_PCM_DL_BUF[gSpc_acLoopback.DL_tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][1],
                       gSpc_acLoopback_PCM_DL_BUF[gSpc_acLoopback.DL_tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][2],
                       gSpc_acLoopback_PCM_DL_BUF[gSpc_acLoopback.DL_tmp_r & (ACLOOPBACK_FRAME_BUF_NO - 1)][3]);         
      (gSpc_acLoopback.DL_tmp_r)++;    
   }else{
      kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_FILL_SPK); 
      // PCM2WAY_FillSpk(0);
      PCM4WAY_FillSpk(0);
   }
	

   kal_dev_trace( TRACE_INFO, SPC_AC_LOOPBACK_UL_DL_INDEX, 
		// gSpc_acLoopback.tmp_w, gSpc_acLoopback.tmp_r, 0, 0);
		// gSpc_acLoopback.DL_tmp_w, gSpc_acLoopback.DL_tmp_r, gSpc_acLoopback.UL_tmp_w, gSpc_acLoopback.UL_tmp_r);
		gSpc_acLoopback.DL_tmp_w, gSpc_acLoopback.DL_tmp_r, 0, 0);
#endif
}

/**
	@uParam:
		Bit 0: 1==Enable/0==Disable
		Bit 1: Pre-condiftion is speech mode equals to SPH_MODE_BT_EARPHONE(3) or SPH_MODE_BT_CCARITE(5). 1== BT Loopback with BT codec / 0 == BT Loopback without BT Codec. Only support (MT6572/MT6582/MT6592/MT6571)
		Bit 2: delay setting for normal loopback, i.e. speech mode is not BT cases. 0==Use modem default delay value/ 1== use AP gives delay value in msgId32 bit[0:7] 
	@extraParam:
		Bit[7:0]: Delay time in uint8. Unit is 20ms. Take effect when msgId16 bit[2] == 1. For example: when bit[7:0] = 0xf, then the delay time is 15*20 == 300 ms.
*/
void Spc_AcousticLoopback(kal_uint8 uParam, kal_uint32 extraParam)
{
    kal_bool enable = uParam & 0x1; // bit(0): on/off   bit(1): disable/enable BT SW codec 

	if(enable){

		// check status
		/*
		if(IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)){
			// just leave log and return
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_ACLOOPBACK_USAGE, SPC_APP_ACLOOPBACK_USAGE, 1);
			return; 
		}
		*/
		if(false == spc_mainAppOnCheck(SPC_APP_ACLOOPBACK_USAGE, true))
			return;

		if(IS_SPC_APP_USED(SPC_APP_PCMNWAY_USAGE)){
			// just leave log and return
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR_CHECK, SPC_APP_ACLOOPBACK_USAGE, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, gSpc.spcAppUsage);
			return; 
		}

		/*
		if(IS_SPC_APP_USED(SPC_APP_HOLD_USAGE)){
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_ACLOOPBACK_USAGE, SPC_APP_ACLOOPBACK_USAGE, 3);		

			// [TODO] REMOVE
			ASSERT(0);
			
			return;
		}
		*/

		// special case for BT loopback 
#if defined(__CVSD_CODEC_SUPPORT__) 
		if( L1SP_GetSpeechMode() == SPH_MODE_BT_EARPHONE || L1SP_GetSpeechMode() == SPH_MODE_BT_CARKIT )
		{  // for SW BT platform, BT loopback does not related to speech and DSP.
		   kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
		   SET_SPC_APP_USAGE(SPC_APP_ACLOOPBACK_USAGE);
		   BT_SCO_Loopback_ON( (uParam& 0x2)>>1 ,is_WB);
		   return; // REMIND!!!
		}
#endif

		// setup 
		gSpc_acLoopback.delay = ACLOOPBACK_DELAY;
		if((uParam & 0x4) !=0) { // using bit [2] for check delay
			kal_uint8 givenDelay = 	(extraParam & 0xFF); //use msg32  bit [7:0] for delay setting
			ASSERT(givenDelay<= ACLOOPBACK_FRAME_BUF_NO);
			gSpc_acLoopback.delay = givenDelay;
		}
#if ACLOOPBACK_USING_P2W		
      gSpc_acLoopback.tmp_w = 0;
		gSpc_acLoopback.tmp_r = 0;
#else		
		// gSpc_acLoopback.UL_tmp_w = 0;
		// gSpc_acLoopback.UL_tmp_r = 0;
		gSpc_acLoopback.DL_tmp_w = 0;
		gSpc_acLoopback.DL_tmp_r = 0;
#endif

		//clean memory
#if ACLOOPBACK_USING_P2W		
      memset(gSpc_acLoopback_PCM_BUF, 0, sizeof(uint16)*ACLOOPBACK_FRAME_BUF_NO*ACLOOPBACK_NB_FRAME_SIZE);
#else
      // memset(gSpc_acLoopback_PCM_UL_BUF, 0, sizeof(uint16)*ACLOOPBACK_FRAME_BUF_NO*ACLOOPBACK_NB_FRAME_SIZE);
      memset(gSpc_acLoopback_PCM_UL_BUF, 0, sizeof(uint16)*ACLOOPBACK_NB_FRAME_SIZE);
      memset(gSpc_acLoopback_PCM_DL_BUF, 0, sizeof(uint16)*ACLOOPBACK_FRAME_BUF_NO*ACLOOPBACK_NB_FRAME_SIZE);
#endif

		SIDETONE_SetSolutionVer(SMART_PHONE_SIDETONE_SOLUTION_VER);
#if ACLOOPBACK_USING_P2W		
		/* P2W */
		Idle_PcmEx_Start(AcousticLoopback_PCM2WAY_DL_HisrHdl, AcousticLoopback_PCM2WAY_UL_HisrHdl, 
				USE_D2M_PATH + DATA_SELECT_AFTER_ENH, // ul1
				USE_D2M_PATH + DATA_SELECT_AFTER_ENH, // ul2
				USE_D2M_PATH + DATA_SELECT_AFTER_ENH, // ul3
				USE_D2M_PATH + DATA_SELECT_AFTER_ENH, // ul4
				USE_M2D_PATH,
				PCMEX_BAND_NB, PCMEX_IDLE_ENH_SETTING_WITH);
#else
		// enable
		L1SP_Speech_On(RAT_2G_MODE);
		L1SP_SpeechLoopBackEnable(KAL_TRUE);
		SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_ACOUSTICLOOPBACK, true);

		Del_PcmEx_Start(AcousticLoopback_PCM4WAY_DL_HisrHdl, AcousticLoopback_PCM4WAY_UL_HisrHdl, 
				USE_D2M_PATH + USE_M2D_PATH + DATA_SELECT_AFTER_ENH,
				USE_D2M_PATH + USE_M2D_PATH + DATA_SELECT_AFTER_ENH,
				USE_D2M_PATH + USE_M2D_PATH + DATA_SELECT_AFTER_ENH,
				USE_D2M_PATH + USE_M2D_PATH + DATA_SELECT_AFTER_ENH,
				USE_D2M_PATH + USE_M2D_PATH);
#endif
		
		SET_SPC_APP_USAGE(SPC_APP_ACLOOPBACK_USAGE);

   } else {

		if(!IS_SPC_APP_USED(SPC_APP_ACLOOPBACK_USAGE)){
			// just leave log and return
			kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_ACLOOPBACK_USAGE, SPC_APP_ACLOOPBACK_USAGE, 0);
			return; 
		}

#if defined(__CVSD_CODEC_SUPPORT__) 
		if( BT_SCO_IS_SPEECH_ON() )
		{  // for SW BT platform, BT loopback does not related to speech and DSP.
		   BT_SCO_Loopback_OFF();
		   CLR_SPC_APP_USAGE(SPC_APP_ACLOOPBACK_USAGE);
		   return;
		}
#endif

		
#if ACLOOPBACK_USING_P2W	
		/* P2W */ 
		// SetSpeechEnhancement(false);
		PcmEx_Stop();
#else
	
      // Extended_PCM4WAY_Stop(P4W_APP_TYPE_UNDER_CALL);
		PcmEx_Stop();
      SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_ACOUSTICLOOPBACK, false);
      L1SP_SpeechLoopBackEnable(KAL_FALSE);     
      L1SP_Speech_Off();      	
		
#endif
		
		CLR_SPC_APP_USAGE(SPC_APP_ACLOOPBACK_USAGE);
      
   }
	
	return; 
}


// ----------------------------------------------------------------------------
// RECORD
// ----------------------------------------------------------------------------

typedef enum
{
	SPC_REC_FORMAT_UNDEF = 0,
	SPC_REC_FORMAT_PCM,
	SPC_REC_FORMAT_VM,
} SPC_REC_FORMAT;

typedef enum
{
	SPC_REC_SAMPLE_RATE_IDX_8K = 0,
	SPC_REC_SAMPLE_RATE_IDX_16K,
	
} SPC_REC_SAMPLE_RATE_IDX;

/*
typedef struct 
{
	uint8    format; //0 undefined, 1: pcm, 2:VM, ref to SPC_REC_FORMAT
	uint8    samplingRateIdx; //0: 8k, 1: 16k, ref to SPC_REC_SAMPLE_RATE_IDX, used in SPC_REC_FORMAT_PCM
	uint8    channelNum; //0: undefined; 1: mono (1ch); 2: stereo (2ch), used in SPC_REC_FORMAT_PCM

	bool     isRecordDataWaiting;
	
} _SPC_RECORD_T;

static _SPC_RECORD_T gSpc_Record;
*/

typedef struct 
{
	uint8    samplingRateIdx; //0: 8k, 1: 16k, ref to SPC_REC_SAMPLE_RATE_IDX, used in SPC_REC_FORMAT_PCM
	uint8    channelNum; //0: undefined; 1: mono (1ch); 2: stereo (2ch), used in SPC_REC_FORMAT_PCM

	bool     isRecordDataWaiting;
	
} _SPC_PCM_RECORD_T;

typedef struct 
{
	bool     isRecordDataWaiting;
	
} _SPC_VM_RECORD_T;

typedef struct 
{
	bool     isRecordDataWaiting;
} _SPC_RAW_PCM_RECORD_T;

static _SPC_PCM_RECORD_T gSpc_PcmRecord;
static _SPC_VM_RECORD_T gSpc_VmRecord;
static _SPC_RAW_PCM_RECORD_T gSpc_RawPcmRecord;
static SPC_REC_FORMAT gSpc_Record_format; // only use under 

/*
static kal_uint16 tempMicData[320]
	// = { 0x4808,0x85, 0x156,0, 0x4,0, 0x146,0x9000, 
	= { 
	0xfff4,0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 
	0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 
	0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 
	0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a78, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa576, 0xfff3, 0x5a79, 0x7fff, 0x5a8b, 
   0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000c, 0xa588, 
   0x8001, 0xa576, 0xfff4, 0x5a79, 0x7fff, 0x5a8b, 0x000d, 0xa587, 0x8001, 0xa575, 	

	0xfff4,0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 
	0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 
	0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 
	0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a78, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa576, 0xfff3, 0x5a79, 0x7fff, 0x5a8b, 
   0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000c, 0xa588, 
   0x8001, 0xa576, 0xfff4, 0x5a79, 0x7fff, 0x5a8b, 0x000d, 0xa587, 0x8001, 0xa575, 

	0xfff4,0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 
	0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 
	0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 
	0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a78, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa576, 0xfff3, 0x5a79, 0x7fff, 0x5a8b, 
   0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000c, 0xa588, 
   0x8001, 0xa576, 0xfff4, 0x5a79, 0x7fff, 0x5a8b, 0x000d, 0xa587, 0x8001, 0xa575, 
   
	0xfff4,0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 
	0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 
	0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 
	0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a78, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa576, 0xfff3, 0x5a79, 0x7fff, 0x5a8b, 
   0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000c, 0xa588, 
   0x8001, 0xa576, 0xfff4, 0x5a79, 0x7fff, 0x5a8b, 0x000d, 0xa587, 0x8001, 0xa575 	

};
*/



void spc_record_sendMicDataDone(void)
{
	
	if(!IS_SPC_APP_USED(SPC_APP_RECORD_USAGE)){		
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 1);
		return;
	}

	if(SPC_REC_FORMAT_PCM == gSpc_Record_format){
		gSpc_PcmRecord.isRecordDataWaiting = false;
	} else if(SPC_REC_FORMAT_VM == gSpc_Record_format){
		gSpc_VmRecord.isRecordDataWaiting = false;
	} else {
		ASSERT(0); // un-know format
	}
}

void spc_pcmRec_sendMicDataDone(void)
{
	if(!IS_SPC_APP_USED(SPC_APP_PCM_REC_USAGE)){		
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_PCM_REC_USAGE, SPC_APP_PCM_REC_USAGE, 1);
		return;
	}

	gSpc_PcmRecord.isRecordDataWaiting = false;
}

void spc_RawPcmRec_sendDataDone(void)
{
	if(!IS_SPC_APP_USED(SPC_APP_RAW_PCM_REC_USAGE)){		
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RAW_PCM_REC_USAGE, SPC_APP_RAW_PCM_REC_USAGE, 1);
		return;
	}

	gSpc_RawPcmRecord.isRecordDataWaiting = false;
}

/**
	run under AUDL/MED, when process message "SPC_ID_AUDIO_STRM_PCMREC_DATA_NOTIFY"
*/
void spc_record_sendPcmData(void)
{
	kal_uint32 add1, add2;
	kal_uint16 len1, len2; 
	spcBufInfo info;
	bool sendResult = true; 

	if((!IS_SPC_APP_USED(SPC_APP_RECORD_USAGE)) && 
		(!IS_SPC_APP_USED(SPC_APP_PCM_REC_USAGE))){ // prevent pcm data sending to AP after record off
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 4);
		return;
	}

	// get data, length is word!!
	PcmRec_GetMicDataBufs(&add1, &len1, &add2, &len2);

	kal_trace(TRACE_INFO, PCMREC_GET_DATA_BUFS, add1, len1, add2, len2);
	
	// change the len to unit of byte 
	len1 <<=1; 
	len2 <<=1; 
	
	if(len1 == 0){
		gSpc_PcmRecord.isRecordDataWaiting = false;
		kal_trace(TRACE_INFO, PCMREC_GET_EMPTY_DATA);
		
	} else {
		info.syncWord = 0x2A2A;
		info.type = AUD_CCCI_STRMBUF_TYPE_PCM_TYPE; 
		info.length = len1 + len2;

		if(IS_SPC_APP_USED(SPC_APP_PCM_REC_USAGE)){ // new from MT6582
			sendResult = SpcIO_WriteDataToAp(&info, sizeof(spcBufInfo), 
				 (void *)add1, len1, (void *)add2, len2,
				 SPCIO_MSG_FROM_SPC_PCM_REC_DATA_NOTIFY);
		} else { // original
			sendResult = SpcIO_WriteDataToAp(&info, sizeof(spcBufInfo), 
				 (void *)add1, len1, (void *)add2, len2,
				 SPCIO_MSG_FROM_SPC_REC_DATA_NOTIFY);
		}		
		/* Testing code
		info.syncWord = 0x2A2A;
		info.type = AUD_CCCI_STRMBUF_TYPE_PCM_TYPE; 
		info.length = 640;
		
		kal_prompt_trace(MOD_L1SP, "prints: %x, %d, %x, %d", add1, len1, add2, len2);
		

		SpcIO_WriteDataToAp(&info, sizeof(spcBufInfo), 
			 tempMicData, 320*sizeof(kal_uint16), NULL, 0,
			 SPCIO_MSG_FROM_SPC_REC_DATA_NOTIFY);

		*/

		if(sendResult == false) {
			gSpc_PcmRecord.isRecordDataWaiting = false;
			kal_trace( TRACE_INFO, SPC_APP_DATA_SEND_FAIL, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 0);
		}
	}
}



/**
	run under AUDL/MED, when process message "SPC_ID_AUDIO_STRM_RAWPCMREC_DATA_NOTIFY"
*/
void spc_record_sendRawPcmData(void)
{
	kal_uint32 add1, add2;
	kal_uint16 len1, len2; 
	spcBufInfo info;
	bool sendResult = true; 

	if( (!IS_SPC_APP_USED(SPC_APP_RAW_PCM_REC_USAGE)) ){ // prevent pcm data sending to AP after record off
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 4);
		return;
	}

	RawPcmRec_GetMicDataBufs(&add1, &len1, &add2, &len2);

	kal_trace(TRACE_INFO, PCMREC_GET_DATA_BUFS, add1, len1, add2, len2);
	
	// change the len to unit of byte 
	len1 <<=1; 
	len2 <<=1; 
	
	if(len1 == 0){
		gSpc_RawPcmRecord.isRecordDataWaiting = false;
		kal_trace(TRACE_INFO, PCMREC_GET_EMPTY_DATA);
	} else {
		info.syncWord = 0x2A2A;
		info.type = AUD_CCCI_STRMBUF_TYPE_RAW_PCM_TYPE; 
		info.length = len1 + len2;

	    kal_prompt_trace(MOD_L1SP, "[spc_record_sendRawPcmData][WriteDataToAp] Start");

		sendResult = SpcIO_WriteDataToAp(&info, sizeof(spcBufInfo), 
             (void *)add1, len1, (void *)add2, len2,
             SPCIO_MSG_FROM_SPC_RAW_PCM_REC_DATA_NOTIFY);

		 kal_prompt_trace(MOD_L1SP, "[spc_record_sendRawPcmData][WriteDataToAp] End");

		if(sendResult == false) {
            gSpc_RawPcmRecord.isRecordDataWaiting = false;
			kal_trace( TRACE_INFO, SPC_APP_DATA_SEND_FAIL, SPC_APP_RAW_PCM_REC_USAGE, SPC_APP_RAW_PCM_REC_USAGE, 0);
		}
	}
}

/**
	Send notification to AUDL/MED, prepare to get the recording data
*/
void spc_pcmRec_handler(void)
{
	if( gSpc_PcmRecord.isRecordDataWaiting == true){
		kal_dev_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 0);
		return;
	}
	
   // Send notification to AUDL to begin data transfer
	SpcIO_MsgQueuePut(SPC_ID_AUDIO_STRM_PCMREC_DATA_NOTIFY, 0, 0, 2);
	
   gSpc_PcmRecord.isRecordDataWaiting = true;
	
	return;
}

void spc_pcmRec_On(uint8 sampleRateIdx, uint8 channelNumIdx)
{
	gSpc_PcmRecord.samplingRateIdx = sampleRateIdx;
	gSpc_PcmRecord.channelNum = channelNumIdx+1; 

	// PCM Record  
	gSpc_PcmRecord.isRecordDataWaiting = false;

	SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_PCMRECORD, true);
	PCMREC_Start(spc_pcmRec_handler, gSpc_PcmRecord.channelNum, (PCM_REC_SAMPLE_RATE_IDX)sampleRateIdx );	
}

void spc_pcmRec_Off(void)
{
	PCMREC_Stop();
	SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_PCMRECORD, false);

	//clean up all inforamtions
	gSpc_PcmRecord.samplingRateIdx = PCM_REC_SAMPLE_RATE_IDX_UNDEF;
	gSpc_PcmRecord.channelNum = 0;
}


void spc_RawPcmRec_handler(void)
{
	if( gSpc_RawPcmRecord.isRecordDataWaiting == true){
		kal_dev_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_RAW_PCM_REC_USAGE, SPC_APP_RAW_PCM_REC_USAGE, 0);
		return;
	}
	
	// Send notification to AUDL to begin data transfer
	SpcIO_MsgQueuePut(SPC_ID_AUDIO_STRM_RAWPCMREC_DATA_NOTIFY, 0, 0, 2);
	
	gSpc_RawPcmRecord.isRecordDataWaiting = true;
	
	return;
}

void spc_RawPcmRec_On(kal_uint8 ULChannelNumIdx)
{
	// RAW PCM Record  
	gSpc_RawPcmRecord.isRecordDataWaiting = false;

	SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_RAWPCMRECORD, true);

	RAWPCMREC_Start(spc_RawPcmRec_handler, ULChannelNumIdx);	
}

void spc_RawPcmRec_Off(void)
{
	RAWPCMREC_Stop();

	SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_RAWPCMRECORD, false);
}

bool spc_RawPcmRec_getDataWaiting(void)
{
    return(gSpc_RawPcmRecord.isRecordDataWaiting);
}

void spc_vmRec_sendMicDataDone(void)
{
	if(!IS_SPC_APP_USED(SPC_APP_VM_REC_USAGE)){		
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_VM_REC_USAGE, SPC_APP_VM_REC_USAGE, 1);
		return;
	}

	gSpc_VmRecord.isRecordDataWaiting = false;
}


/**
	run under AUDL/MED, when process message "SPC_ID_AUDIO_STRM_VMREC_DATA_NOTIFY"
*/
void spc_record_sendVmData(void)
{
	
	kal_uint32 add1, add2;
	kal_uint16 len1, len2; 
	kal_uint16 totalLenInWord;
	spcBufInfo info;
	bool sendResult = true; 

	if((!IS_SPC_APP_USED(SPC_APP_RECORD_USAGE)) && (!IS_SPC_APP_USED(SPC_APP_VM_REC_USAGE))){ // prevent sening vm data to AP after record off
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 5);
		return;
	}
	
	// get data, length is word!!
	VmRec_GetReadBufs(&add1, &len1, &add2, &len2);
	totalLenInWord = len1+len2;

	kal_prompt_trace(MOD_L1SP, "vm prints: %x, %d, %x, %d", add1, len1, add2, len2);

	// change the len to unit of byte 
	len1 <<= 1;
	len2 <<= 1;
	
	if(len1 == 0){
		gSpc_VmRecord.isRecordDataWaiting = false;
		kal_trace( TRACE_INFO, SPC_APP_DATA_SEND_FAIL, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 1);
		
	} else {
		kal_prompt_trace(MOD_L1SP, "[spc_record_sendRawPcmData][WriteDataToAp] Start");
		
		info.syncWord = 0x2A2A;
		info.type = AUD_CCCI_STRMBUF_TYPE_VM_TYPE; 
		info.length = len1 + len2; 

		if(IS_SPC_APP_USED(SPC_APP_VM_REC_USAGE)){
			sendResult = SpcIO_WriteDataToAp(&info, sizeof(spcBufInfo), 
				(void *)add1, len1, (void *)add2, len2,
				SPCIO_MSG_FROM_SPC_VM_REC_DATA_NOTIFY);
		} else { // original version
			sendResult = SpcIO_WriteDataToAp(&info, sizeof(spcBufInfo), 
				 (void *)add1, len1, (void *)add2, len2,
				 SPCIO_MSG_FROM_SPC_REC_DATA_NOTIFY);
		}
		kal_prompt_trace(MOD_L1SP, "[spc_record_sendRawPcmData][WriteDataToAp] End");

		VmRec_ReadDataDone(totalLenInWord);
		
		if(sendResult == false) {
			gSpc_VmRecord.isRecordDataWaiting = false;
			kal_trace( TRACE_INFO, SPC_APP_DATA_SEND_FAIL, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 2);;
		}
	}
}

void spc_vmRec_handler(void)
{
	if( gSpc_VmRecord.isRecordDataWaiting == true){
		kal_dev_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 1);
		return;
	}

	SpcIO_MsgQueuePut(SPC_ID_AUDIO_STRM_VMREC_DATA_NOTIFY, 0, 0, 2);
	
   gSpc_VmRecord.isRecordDataWaiting = true;
	
	return;
}

void spc_vmRec_On(void)
{
	gSpc_VmRecord.isRecordDataWaiting = false;

	VMREC_Start(spc_vmRec_handler, 0, false);
}

void spc_vmRec_Off(void)
{
	VMREC_Stop(false);
}

/**
	@return: true for pass checking, flase for fail checking
*/
bool spc_recordStartCheck(void)
{
	if(!IS_SPC_ID_SPEECH_CUSTOM_DATA_REQUEST_DONE){ // prevent record on before EM data sending
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 6);
		return false;
	}

	if(IS_SPC_APP_USED(SPC_APP_HOLD_USAGE)){ // under SID generation state, record function is not provided
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 2);		

		ASSERT(0);
		
		return false;
	}

	// system is under idle state, we do not provide record function. 
	if((!IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) 
		&& (!IS_SPC_APP_USED(SPC_APP_ACLOOPBACK_USAGE))
		&& (!IS_SPC_APP_USED(SPC_APP_CTM_USAGE))
		){ 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 3);		

		// REMOVE
		// ASSERT(0);
		
		return false;
	}

	// defualt
	return true;
}


void spc_PcmRecordStart(uint8 sampleRateIdx, uint8 channelNumIdx)
{
	if(true!= spc_recordStartCheck()){
		return;
	}

	// prevent re-entry
	if(IS_SPC_APP_USED(SPC_APP_PCM_REC_USAGE)){ 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_PCM_REC_USAGE, SPC_APP_PCM_REC_USAGE, 2);
		return;
	}

	// It is illegle to use different formats to open record, so force assert.
	if(IS_SPC_APP_USED(SPC_APP_RECORD_USAGE)){ 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_PCM_REC_USAGE, SPC_APP_PCM_REC_USAGE, 3);
		ASSERT(0);
		return;
	}
	
	spc_pcmRec_On(sampleRateIdx, channelNumIdx);
	SET_SPC_APP_USAGE(SPC_APP_PCM_REC_USAGE);
}


void spc_PcmRecordStop(void)
{
	if(!IS_SPC_APP_USED(SPC_APP_PCM_REC_USAGE)){
		// just leave log and return
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_PCM_REC_USAGE, SPC_APP_PCM_REC_USAGE, 0);
		return; 
	}
	
	spc_pcmRec_Off();
	CLR_SPC_APP_USAGE(SPC_APP_PCM_REC_USAGE);
}

void spc_VmRecordStart(void)
{
	if(true!= spc_recordStartCheck()){
		return;
	}

	// prevent re-entry
	if(IS_SPC_APP_USED(SPC_APP_VM_REC_USAGE)){ 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_VM_REC_USAGE, SPC_APP_VM_REC_USAGE, 2);
		return;
	}

	// It is illegle to use different formats to open record, so force assert.
	if(IS_SPC_APP_USED(SPC_APP_RECORD_USAGE)){ 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_VM_REC_USAGE, SPC_APP_VM_REC_USAGE, 3);
		ASSERT(0);
		return;
	}
	
	spc_vmRec_On();

	SET_SPC_APP_USAGE(SPC_APP_VM_REC_USAGE);
}


void spc_VmRecordStop(void)
{
	if(!IS_SPC_APP_USED(SPC_APP_VM_REC_USAGE)){
		// just leave log and return
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_VM_REC_USAGE, SPC_APP_VM_REC_USAGE, 0);
		return; 
	} 
	
	spc_vmRec_Off();
	CLR_SPC_APP_USAGE(SPC_APP_VM_REC_USAGE);
}



/**
	Open RAW PCM record. This can concurrency with VM record (spc_VmRecordStart)
	Only support speech on record!! (Speech on for daca is NOT support)
*/
void spc_RawPcmRecordStart(kal_uint8 ULChannelNumIdx)
{
	if(true != spc_recordStartCheck()){
		return;
	}

	if(IS_SPC_APP_USED(SPC_APP_HOSTED_USAGE)) // PCM record is not allow on DACA
	{
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RAW_PCM_REC_USAGE, SPC_APP_RAW_PCM_REC_USAGE, 4);
		ASSERT(0);
		return;
	}

	// prevent re-entry
	if(IS_SPC_APP_USED(SPC_APP_RAW_PCM_REC_USAGE)){ 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RAW_PCM_REC_USAGE, SPC_APP_RAW_PCM_REC_USAGE, 2);
		return;
	}

	// It is illegle to use different formats to open record, so force assert.
	if((IS_SPC_APP_USED(SPC_APP_RECORD_USAGE)) || (IS_SPC_APP_USED(SPC_APP_PCM_REC_USAGE))){ 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RAW_PCM_REC_USAGE, SPC_APP_RAW_PCM_REC_USAGE, 3);
		ASSERT(0);
		return;
	}

	spc_RawPcmRec_On(ULChannelNumIdx);
	SET_SPC_APP_USAGE(SPC_APP_RAW_PCM_REC_USAGE);
}

void spc_RawPcmRecordStop(void)
{
	if(!IS_SPC_APP_USED(SPC_APP_RAW_PCM_REC_USAGE)){
		// just leave log and return
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RAW_PCM_REC_USAGE, SPC_APP_RAW_PCM_REC_USAGE, 0);
		return; 
	}
	
	spc_RawPcmRec_Off();
	CLR_SPC_APP_USAGE(SPC_APP_RAW_PCM_REC_USAGE);
}

void spc_RecordStart(uint8 format, uint8 sampleRateIdx, uint8 channelNumIdx)
{
/*
	if(!IS_SPC_ID_SPEECH_CUSTOM_DATA_REQUEST_DONE){ // prevent record on before EM data sending
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 6);
		return;
	}

	if(IS_SPC_APP_USED(SPC_APP_HOLD_USAGE)){ // under SID generation state
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 2);		

		ASSERT(0);
		
		return;
	}

	// system is under idle state, We do not provide record function. 
	if((!IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) 
		&& (!IS_SPC_APP_USED(SPC_APP_ACLOOPBACK_USAGE))
		&& (!IS_SPC_APP_USED(SPC_APP_CTM_USAGE))
		){ 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 3);		

		// REMOVE
		// ASSERT(0);
		
		return;
	}
*/
	if(true!= spc_recordStartCheck()){
		return;
	}

	// prevent re-entry
	if(IS_SPC_APP_USED(SPC_APP_RECORD_USAGE)){ 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 7);
		return;
	}

	// It is illegle to use different formats to open record, so force assert.
	if((IS_SPC_APP_USED(SPC_APP_PCM_REC_USAGE)) || (IS_SPC_APP_USED(SPC_APP_VM_REC_USAGE))){ 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 8);
		ASSERT(0);
		return;
	}
	
#ifdef CONNECT_WM8904
  		Config_WM8904(2); //Config_WM8904(-1); MIC_8K_LONGSYNC_PHONE_CALL == 2
#endif  
	switch(format){
		case 0: // PCM
		{
			/*
			gSpc_Record.format = SPC_REC_FORMAT_PCM;
			gSpc_Record.samplingRateIdx = sampleRateIdx;
			gSpc_Record.channelNum = channelNumIdx+1; 
			
			// PCM Record  
         gSpc_Record.isRecordDataWaiting = false;

			PCMREC_Start(spc_pcmRec_handler, gSpc_Record.channelNum, (PCM_REC_SAMPLE_RATE_IDX)sampleRateIdx );			
			*/
			gSpc_Record_format = SPC_REC_FORMAT_PCM;
			spc_pcmRec_On(sampleRateIdx, channelNumIdx);
		}
			break;
		case 1: //VM			
			/*
			gSpc_Record.format = SPC_REC_FORMAT_VM;
			gSpc_Record.samplingRateIdx = PCM_REC_SAMPLE_RATE_IDX_UNDEF;
			gSpc_Record.channelNum = 0;

			gSpc_Record.isRecordDataWaiting = false;

			VMREC_Start(spc_vmRec_handler, 0, false);
			*/
			gSpc_Record_format = SPC_REC_FORMAT_VM;
			spc_vmRec_On();
			break;
		/*
		case 2: //Phase out DMNR calibration
			break;
		
#if defined(__CTM_SUPPORT__)
		case 3: //CTM debug
			break;
#endif
		*/
		default: // illegle format. 
			ASSERT(0);
	}

	SET_SPC_APP_USAGE(SPC_APP_RECORD_USAGE);
}

void spc_RecordStop()
{
	if(!IS_SPC_APP_USED(SPC_APP_RECORD_USAGE)){
		// just leave log and return
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_RECORD_USAGE, SPC_APP_RECORD_USAGE, 0);
		return; 
	} 
	
	switch(gSpc_Record_format){
		case SPC_REC_FORMAT_PCM:
			/*
			PCMREC_Stop();

			//clean up all inforamtions
			gSpc_Record.format = SPC_REC_FORMAT_UNDEF;
			gSpc_Record.samplingRateIdx = PCM_REC_SAMPLE_RATE_IDX_UNDEF;
			gSpc_Record.channelNum = 0;
			*/
			spc_pcmRec_Off();
			break;
		case SPC_REC_FORMAT_VM:
			/*
			VMREC_Stop(false);

			gSpc_Record.format = SPC_REC_FORMAT_UNDEF;
			gSpc_Record.samplingRateIdx = PCM_REC_SAMPLE_RATE_IDX_UNDEF;
			gSpc_Record.channelNum = 0;
			*/
			spc_vmRec_Off();
			break;
		default:
			ASSERT(0);
	}

	gSpc_Record_format = SPC_REC_FORMAT_UNDEF;
	CLR_SPC_APP_USAGE(SPC_APP_RECORD_USAGE);

}

// ----------------------------------------------------------------------------
// PCMNWAY
// ----------------------------------------------------------------------------
#define SPC_PCMNWAY_MAX_SIZE_OF_SE_BUF  320 // unit is 16bit(word)
#define SPC_PCMNWAY_MAX_SIZE_OF_SPK_BUF 320 // unit is 16bit(word), max = 16*20
#define SPC_PCMNWAY_MAX_SIZE_OF_MIC_BUF 642 // unit is 16bit(word), max = 320*2 +2(agc use)
#define SPC_PCMNWAY_MAX_SIZE_OF_SD_BUF  320 // unit is 16bit(word)


#define SPC_PNW_MSG_BUFFER_SE  1 // Bit 0
#define SPC_PNW_MSG_BUFFER_SPK 2 // Bit 1
#define SPC_PNW_MSG_BUFFER_MIC 4 // Bit 2
#define SPC_PNW_MSG_BUFFER_SD  8 // Bit 3

#define SPC_PNW_MSG_BIT_BAND   4

typedef enum
{

	SPC_PCMNWAY_APP_TYPE_NONE = 0,
	SPC_PCMNWAY_APP_TYPE_DMNR_CAL_PLAY_REC,
	SPC_PCMNWAY_APP_TYPE_DMNR_CAL_REC_ONLY,
	
	SPC_PCMNWAY_APP_TYPE_UNSET = 0xffff,	
} SPC_PCMNWAY_APP_TYPE_T;

typedef enum {
  SPC_PCMNWAY_FORMAT_P2W_NORMAL = 0,
  SPC_PCMNWAY_FORMAT_P2W_VOIP,
  SPC_PCMNWAY_FORMAT_P2W_CAL,          //calibration 
  SPC_PCMNWAY_FORMAT_P2W_WB_CAL,       //wb calibration
  SPC_PCMNWAY_FORMAT_P2W_WB_NORMAL,     //normal usage for WB p2w

  SPC_PCMNWAY_FORMAT_UNSET = 0xffff,
}SPC_PCMNWAY_Format;
typedef struct _SPC_PCMNWAY_T_
{
	kal_uint8    pnwBufInfo; //ref to SPC_PNW_MSG_BUFFER_x
	kal_uint8    pnwBand; //0: for narrow band, 1: for wide band
	// kal_uint16   pnwAppType;

	kal_bool     pnwIsMicBufWaiting;
	kal_bool     pnwIsSpkBufWaiting;
	
	kal_uint32   micBufSize; // unit is byte (8bit)
	kal_uint32   spkBufSize; // unit is byte (8bit)
	kal_uint32   seBufSize;
	kal_uint32   sdBufSize;

	
}_SPC_PCMNWAY_T;

static _SPC_PCMNWAY_T gSpc_Pcmnway;
static kal_uint16 gSpc_Pcmnway_seBuf[SPC_PCMNWAY_MAX_SIZE_OF_SE_BUF];
static kal_uint16 gSpc_Pcmnway_spkBuf[SPC_PCMNWAY_MAX_SIZE_OF_SPK_BUF]; 
static kal_uint16 gSpc_Pcmnway_micBuf[SPC_PCMNWAY_MAX_SIZE_OF_MIC_BUF]; 
static kal_uint16 gSpc_Pcmnway_sdBuf[SPC_PCMNWAY_MAX_SIZE_OF_SD_BUF];

/*
__attribute__  ((section ("NONCACHEDZI"))) static kal_uint16 tempUlData[179]
	// = { 0x4808,0x85, 0x156,0, 0x4,0, 0x146,0x9000, 
	= { 0,0, 0,0, 0,0, 0,0, 
	1, 2, 3, 4, 5, 6, 7, 8,
	0x2A2A, 0x2, 0x140, 
	0xfff4,0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 
	0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 
	0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 
	0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a78, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa576, 0xfff3, 0x5a79, 0x7fff, 0x5a8b, 
   0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000c, 0xa588, 
   0x8001, 0xa576, 0xfff4, 0x5a79, 0x7fff, 0x5a8b, 0x000d, 0xa587, 0x8001, 0xa575, 	

	0xfff4,0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 
	0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 
	0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 
	0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a78, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa576, 0xfff3, 0x5a79, 0x7fff, 0x5a8b, 
   0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000c, 0xa588, 
   0x8001, 0xa576, 0xfff4, 0x5a79, 0x7fff, 0x5a8b, 0x000d, 0xa587, 0x8001, 0xa575 	
};
*/

/**
	MD -> AP, Run under AUDL/MED
*/
void spc_pcmNWay_sendUlData(void)
{
    kal_prompt_trace(MOD_L1SP, "[spc_pcmNWay_sendUlData] Enter");
    
	kal_bool sendResultMic = KAL_TRUE;
	kal_bool sendResultSd = KAL_TRUE;
	spcBufInfo info;

	if(!IS_SPC_APP_USED(SPC_APP_PCMNWAY_USAGE)){ // prevent data sending after PCMNWAY is off
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 4);
		return;
	}
	
	if (gSpc_Pcmnway.pnwBufInfo & SPC_PNW_MSG_BUFFER_MIC) {
		info.syncWord = 0x2A2A;
		info.type = AUD_CCCI_STRMBUF_TYPE_PCM_GetFromMic; 
		info.length = gSpc_Pcmnway.micBufSize;

		// FIXME: for debug	
		/*
		sendResultMic = spcIO_sendDataViaCCCI(
			SPCIO_CCCI_MSG_CONSTRCUT_DATA_CMD(MSG_M2A_DATA_NOTIFY_PNW_ULREAD, 326), 
			&(tempUlData[8]), 342);
		*/
				kal_prompt_trace(MOD_L1SP, "[spc_pcmNWay_sendUlData][WriteDataToAp] Start");
				
		sendResultMic = (SpcIO_WriteDataToAp(&info, sizeof(spcBufInfo), 
				gSpc_Pcmnway_micBuf, gSpc_Pcmnway.micBufSize,  NULL, 0,
				SPCIO_MSG_FROM_SPC_PNW_ULDATA_NOTIFY));

		kal_prompt_trace(MOD_L1SP, "[spc_pcmNWay_sendUlData][WriteDataToAp] End");
	
	}
	
	if (gSpc_Pcmnway.pnwBufInfo & SPC_PNW_MSG_BUFFER_SD) {
		info.syncWord = 0x2A2A;
		info.type = AUD_CCCI_STRMBUF_TYPE_PCM_GetfromSD; 
		info.length = gSpc_Pcmnway.sdBufSize;
        
        kal_prompt_trace(MOD_L1SP, "[spc_pcmNWay_sendUlData] info 1, %d %d %d",info.syncWord,info.type,info.length);
		
        sendResultSd = (SpcIO_WriteDataToAp(&info, sizeof(spcBufInfo), 
				gSpc_Pcmnway_sdBuf, gSpc_Pcmnway.sdBufSize, NULL, 0,
				SPCIO_MSG_FROM_SPC_PNW_ULDATA_NOTIFY));		
        
        kal_prompt_trace(MOD_L1SP, "[spc_pcmNWay_sendUlData] info 2, %d %d %d",info.syncWord,info.type,info.length);
	}
	
	if((KAL_TRUE !=  sendResultMic) || (KAL_TRUE !=  sendResultSd)) {
			//clean up the read waiting flag when send fail to prevent blocking. 
			gSpc_Pcmnway.pnwIsMicBufWaiting = KAL_FALSE;
			kal_trace( TRACE_INFO, SPC_APP_DATA_SEND_FAIL, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 0);
	}	
    kal_prompt_trace(MOD_L1SP, "[spc_pcmNWay_sendUlData] Leave");
}

void spc_pcmNWay_sendUlDataDone(void)
{
	
	if(!IS_SPC_APP_USED(SPC_APP_PCMNWAY_USAGE)){		
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 1);
		return;
	}
	gSpc_Pcmnway.pnwIsMicBufWaiting = KAL_FALSE;

}	

/**
	MD -> AP
*/
void spc_pcmNWay_requestDlData(void)
{
	kal_int32 sendResult;

	if(!IS_SPC_APP_USED(SPC_APP_PCMNWAY_USAGE)){ // prevent data sending after PCMNWAY is off
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 5);
		return;
	}
	
	sendResult = SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_PNW_DLDATA_REQUEST, gSpc_Pcmnway.spkBufSize, 0);
	// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_DATA_REQUEST_PNW_DLDATA, gSpc_Pcmnway.spkBufSize));

	if(sendResult<0){ //clean waiting flag of speaker to prevent message blocking
		gSpc_Pcmnway.pnwIsSpkBufWaiting = KAL_FALSE;
		kal_trace( TRACE_INFO, SPC_APP_DATA_SEND_FAIL, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 1);
	}
}

void spc_pcmNWay_writeDlDataDone(kal_uint16 offset, kal_int16 length)
{

	spcBufInfo info;	
	kal_uint16 curOffSet;

	if(!IS_SPC_APP_USED(SPC_APP_PCMNWAY_USAGE)){		
		kal_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 5);
		return;
	}

	ASSERT(length>=sizeof(spcBufInfo));
	curOffSet = SpcIo_GetDataFromAp(offset, sizeof(spcBufInfo), &info);


	//header checking
   ASSERT(info.syncWord == 0xA2A2);
   ASSERT( (info.type == AUD_CCCI_STRMBUF_TYPE_PCM_FillSE) || (info.type == AUD_CCCI_STRMBUF_TYPE_PCM_FillSpk) );
   ASSERT(info.length == (length - sizeof(spcBufInfo)));
   
	if(info.length >0){
		if (info.type == AUD_CCCI_STRMBUF_TYPE_PCM_FillSE) { //SE
			ASSERT(info.length == gSpc_Pcmnway.seBufSize);
			SpcIo_GetDataFromAp(curOffSet, gSpc_Pcmnway.seBufSize, gSpc_Pcmnway_seBuf);
		} else { //SPK
			ASSERT(info.length == gSpc_Pcmnway.spkBufSize);
			SpcIo_GetDataFromAp(curOffSet, gSpc_Pcmnway.spkBufSize, gSpc_Pcmnway_spkBuf);
		}
	}
	
	gSpc_Pcmnway.pnwIsSpkBufWaiting = KAL_FALSE;
}


void spc_pcm4way_handler( void )
{
	// spc_pcm4wayDl_handler();
	if( gSpc_Pcmnway.pnwIsSpkBufWaiting == KAL_TRUE){
		kal_dev_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 4);
		return;
	}		

	// SE buffer
	if (gSpc_Pcmnway.pnwBufInfo & SPC_PNW_MSG_BUFFER_SE) {
      gSpc_Pcmnway.seBufSize = ((PCM4WAY_PutToSE((const uint16*)gSpc_Pcmnway_seBuf) << 1));
   }
	
   // Speaker buffer
   if (gSpc_Pcmnway.pnwBufInfo & SPC_PNW_MSG_BUFFER_SPK) {
      gSpc_Pcmnway.spkBufSize = ((PCM4WAY_PutToSpk((const uint16*)gSpc_Pcmnway_spkBuf)) << 1);
   }

   // Transfer to AUDL
   // Send notification
	SpcIO_MsgQueuePut(SPC_ID_AUDIO_STRM_PNW_DL_DATA_REQUEST, 0, 0, 2);
	
   gSpc_Pcmnway.pnwIsSpkBufWaiting = KAL_TRUE;

	// --------------------------------------------------------------
	// spc_pcm4wayUl_handler();
		if( gSpc_Pcmnway.pnwIsMicBufWaiting == KAL_TRUE){
		kal_dev_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 3);
		return;
	}		

	
   // Microphone buffer
   if (gSpc_Pcmnway.pnwBufInfo & SPC_PNW_MSG_BUFFER_MIC) {
      gSpc_Pcmnway.micBufSize = ((PCM4WAY_GetFromMic((uint16*)gSpc_Pcmnway_micBuf)) << 1);
   }

	// SD buffer
	if (gSpc_Pcmnway.pnwBufInfo & SPC_PNW_MSG_BUFFER_SD) {
      gSpc_Pcmnway.sdBufSize = ((PCM4WAY_GetFromSD((uint16*)gSpc_Pcmnway_sdBuf)) << 1);
   }
	
   // Transfer to AUDL
   // Send notification
	SpcIO_MsgQueuePut(SPC_ID_AUDIO_STRM_PNW_UL_DATA_NOTIFY, 0, 0, 2);
	
   gSpc_Pcmnway.pnwIsMicBufWaiting = KAL_TRUE;
}

void spc_pcm2wayUl_handler( void )
{

	if( gSpc_Pcmnway.pnwIsMicBufWaiting == KAL_TRUE){
		kal_dev_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 1);
		return;
	}		

   // Microphone buffer
   if (gSpc_Pcmnway.pnwBufInfo & SPC_PNW_MSG_BUFFER_MIC) {
      gSpc_Pcmnway.micBufSize = ((PCM2WAY_GetFromMic((uint16*)gSpc_Pcmnway_micBuf)) << 1);
   }

   // Transfer to AUDL
   // Send notification
	SpcIO_MsgQueuePut(SPC_ID_AUDIO_STRM_PNW_UL_DATA_NOTIFY, 0, 0, 2);
	
   gSpc_Pcmnway.pnwIsMicBufWaiting = KAL_TRUE;
}

void spc_pcm2wayDl_handler( void )
{

	if( gSpc_Pcmnway.pnwIsSpkBufWaiting == KAL_TRUE){
		kal_dev_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 2);
		return;
	}		

   // Speaker buffer
   if (gSpc_Pcmnway.pnwBufInfo & SPC_PNW_MSG_BUFFER_SPK) {
      gSpc_Pcmnway.spkBufSize = ((PCM2WAY_PutToSpk((const uint16*)gSpc_Pcmnway_spkBuf)) << 1);
   }


   // Transfer to AUDL
   // Send notification
	SpcIO_MsgQueuePut(SPC_ID_AUDIO_STRM_PNW_DL_DATA_REQUEST, 0, 0, 2);
	
   gSpc_Pcmnway.pnwIsSpkBufWaiting = KAL_TRUE;
}


void spc_pcm2way_handler( void )
{
	spc_pcm2wayDl_handler();
	spc_pcm2wayUl_handler();
}


/**
	@param: 
		[0:3] pcmnway buffer infor, please ref  SPC_PNW_MSG_BUFFER_x
		[4]: band information 
	@format: please reference pcm2way' P2W_Format. If its value is 0xFFFF(undefine), we decide it by band information. 
	@appType: application type using in PCMNWAY.  If its value is 0xFFFF(undefine), we will choose by ourself
*/
void spc_PcmNWayStart(kal_uint32 param, SPC_PCMNWAY_Format format, SPC_PCMNWAY_APP_TYPE_T appType)
{
	uint32 cfgUL1 , cfgUL2, cfgUL3, cfgUL4, cfgDL;
	
	if(IS_SPC_APP_USED(SPC_APP_HOLD_USAGE) || IS_SPC_APP_USED(SPC_APP_HOSTED_USAGE)){
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 3);		
		
		ASSERT(0);

		return;
	}


	gSpc_Pcmnway.pnwBufInfo = (param & 0xf); // i.e.  param & (SPC_PNW_MSG_BUFFER_SE|SPC_PNW_MSG_BUFFER_SPK|SPC_PNW_MSG_BUFFER_MIC|SPC_PNW_MSG_BUFFER_SD)
	gSpc_Pcmnway.pnwBand = ((param >> SPC_PNW_MSG_BIT_BAND) & 0x1);

	ASSERT(gSpc_Pcmnway.pnwBufInfo != 0);

	
	// buffer rest			 			 
	memset( (kal_uint8 *)gSpc_Pcmnway_seBuf, 0, SPC_PCMNWAY_MAX_SIZE_OF_SE_BUF*sizeof(uint16) );
	memset( (kal_uint8 *)gSpc_Pcmnway_spkBuf, 0, SPC_PCMNWAY_MAX_SIZE_OF_SPK_BUF*sizeof(uint16) );
	memset( (kal_uint8 *)gSpc_Pcmnway_micBuf, 0, SPC_PCMNWAY_MAX_SIZE_OF_MIC_BUF*sizeof(uint16) );
	memset( (kal_uint8 *)gSpc_Pcmnway_sdBuf, 0, SPC_PCMNWAY_MAX_SIZE_OF_SD_BUF*sizeof(uint16) );
	gSpc_Pcmnway.micBufSize = 0;
	gSpc_Pcmnway.spkBufSize = 0;
	gSpc_Pcmnway.seBufSize = 0;
	gSpc_Pcmnway.sdBufSize = 0;
			 
	// reset wating 
	gSpc_Pcmnway.pnwIsMicBufWaiting = KAL_FALSE;
	gSpc_Pcmnway.pnwIsSpkBufWaiting = KAL_FALSE;


	// UL1 path
	cfgUL1 =DATA_SELECT_AFTER_ENH;
	if(SPC_PNW_MSG_BUFFER_MIC & gSpc_Pcmnway.pnwBufInfo ) {
		cfgUL1 |= USE_D2M_PATH;
	}
	if(SPC_PNW_MSG_BUFFER_SE & gSpc_Pcmnway.pnwBufInfo ) {
		cfgUL1 |= USE_M2D_PATH;
	}

	//UL2 path
	cfgUL2=DATA_SELECT_AFTER_ENH;
	//UL3 path
	cfgUL3=DATA_SELECT_AFTER_ENH;
	//UL4 path
	cfgUL4=DATA_SELECT_AFTER_ENH;
	
	// DL path
	cfgDL = 0;
	if(SPC_PNW_MSG_BUFFER_SD & gSpc_Pcmnway.pnwBufInfo ) {
		cfgDL |= USE_D2M_PATH;
	}
	if(SPC_PNW_MSG_BUFFER_SPK & gSpc_Pcmnway.pnwBufInfo ) {
		cfgDL |= USE_M2D_PATH;
	}
	
	if (IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) { // in call
		if( (SPC_PNW_MSG_BUFFER_SPK|SPC_PNW_MSG_BUFFER_MIC) == gSpc_Pcmnway.pnwBufInfo)  { // 2way
			Del_PcmEx_Start(spc_pcm2wayDl_handler, spc_pcm2wayUl_handler, 
				cfgUL1, cfgUL2, cfgUL3, cfgUL4, cfgDL);
		} else {
			Del_PcmEx_Start(spc_pcm4way_handler, NULL, 
				cfgUL1, cfgUL2, cfgUL3, cfgUL4, cfgDL);
		}
		
		
	} else {	// idle
	
		PCMEX_BAND band = PCMEX_BAND_UNSET;
		PCMEX_IDLE_ENH_SETTING enhSetting = PCMEX_IDLE_ENH_SETTING_WITH; // default with

		band = ((gSpc_Pcmnway.pnwBufInfo == 0)? PCMEX_BAND_NB : PCMEX_BAND_WB);
		if (SPC_PCMNWAY_APP_TYPE_DMNR_CAL_PLAY_REC == appType) {			
			enhSetting = PCMEX_IDLE_ENH_SETTING_DMNR_CAL;
		} else if (SPC_PCMNWAY_APP_TYPE_DMNR_CAL_REC_ONLY == appType) {
			enhSetting = PCMEX_IDLE_ENH_SETTING_DMNR_REC_ONLY_CAL;
		}
		
		if( (SPC_PNW_MSG_BUFFER_SPK|SPC_PNW_MSG_BUFFER_MIC) == gSpc_Pcmnway.pnwBufInfo)  { // 2way
			Idle_PcmEx_Start(spc_pcm2wayDl_handler, spc_pcm2wayUl_handler, 
				cfgUL1, cfgUL2, cfgUL3, cfgUL4, cfgDL, 
				band, enhSetting);
		} else {
			Idle_PcmEx_Start(spc_pcm4way_handler, NULL, 
				cfgUL1, cfgUL2, cfgUL3, cfgUL4, cfgDL,
				band, enhSetting);
		}		

	}

#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__ENABLE_SPEECH_DVT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // defined(__ENABLE_SPEECH_DVT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__ENABLE_SPEECH_DVT__)
/* under construction !*/
#else // defined(__ENABLE_SPEECH_DVT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // defined(__ENABLE_SPEECH_DVT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

	// record the spc application usage status
	SET_SPC_APP_USAGE(SPC_APP_PCMNWAY_USAGE);
				
}

void spc_PcmNWayStop()
{
	
	if(!IS_SPC_APP_USED(SPC_APP_PCMNWAY_USAGE)){
		// just leave log and return
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_PCMNWAY_USAGE, SPC_APP_PCMNWAY_USAGE, 0);
		return; 
	} 

	PcmEx_Stop();
	/*
	ASSERT((gSpc_Pcmnway.pnwAppType) != 0xFF);	
   if( (SPC_PNW_MSG_BUFFER_SPK|SPC_PNW_MSG_BUFFER_MIC) == gSpc_Pcmnway.pnwBufInfo ){ // PCM2WAY       
      PCM2WAY_Stop(gSpc_Pcmnway.pnwAppType);      
      // Extended_PCM2WAY_Stop(gSpc_Pcmnway.pnwAppType);
   } else {
      PCM4WAY_Stop(gSpc_Pcmnway.pnwAppType);
   } 
	
	gSpc_Pcmnway.pnwAppType = 0xFF;
	*/
	
	// clear buffer
	gSpc_Pcmnway.pnwBufInfo = 0;
	gSpc_Pcmnway.pnwBand = 0;
	gSpc_Pcmnway.micBufSize = 0;
	gSpc_Pcmnway.spkBufSize = 0;
	gSpc_Pcmnway.seBufSize = 0;
	gSpc_Pcmnway.sdBufSize = 0;

	CLR_SPC_APP_USAGE(SPC_APP_PCMNWAY_USAGE);

}

// ----------------------------------------------------------------------------
// Background Sound
// ----------------------------------------------------------------------------
typedef struct _SPC_BGSND_T_
{
	kal_uint8 ulGainLevel;
	kal_uint8 dlGainLevel;

	kal_bool isDataWaiting;
}_SPC_BGSND_T;

static _SPC_BGSND_T gSpc_bgSnd;

/**
	Run under MED/AUDL Thread
*/
void spc_bgSnd_writeDataDone(kal_uint16 offset, kal_uint16 length)
{
	spcBufInfo info;

	if(!IS_SPC_APP_USED(SPC_APP_BGSND_USAGE)){ // prevent data sending after background sound is off
		kal_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_BGSND_USAGE, SPC_APP_BGSND_USAGE, 1);
		return;
   }
	
	SpcIO_GetDataFromAp_inOneTime(offset, length, sizeof(spcBufInfo), &info, emDataBuf);

	//header check
	ASSERT(info.syncWord == 0xA2A2);
   ASSERT(info.type == AUD_CCCI_STRMBUF_TYPE_BGS_TYPE);
   ASSERT(info.length == (length-6));

	if(info.length>0){
		BGSND_WriteData(emDataBuf, (kal_int32) info.length);
	}
	
	gSpc_bgSnd.isDataWaiting = KAL_FALSE;
	// kal_prompt_trace(MOD_L1SP, "[pDebug] length=%d, spc_bgSnd_writeDataDone", info.length);
	
	
}

/**
	Run under MED/AUDL Thread
*/
void spc_bgSnd_requestData(void)
{
	int32 bLen;
            
   if(!IS_SPC_APP_USED(SPC_APP_BGSND_USAGE)){ // prevent data sending after background sound is off
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_BGSND_USAGE, SPC_APP_BGSND_USAGE, 1);
		return;
   }
   
	if(gSpc_bgSnd.isDataWaiting){
		kal_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_BGSND_USAGE, SPC_APP_BGSND_USAGE, 0);
		return;
	}
    
	bLen = BGSND_GetFreeSpace(); //unit is 16bit in BGSND_GetFreeSpace() return
   // bLen &= ~0x1; 

	if( bLen >= BGSND_RB_DEFAULT_THRESHOLD ) {

		// send data request to AP
		SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_BGS_DATA_REQUEST, (bLen<<1) , 0);
		gSpc_bgSnd.isDataWaiting = KAL_TRUE;
		
	}				
	
	
}

/**
	Call back handler from HISR
*/
void spc_bgSnd_handler(void)
{
	if(KAL_FALSE == gSpc_bgSnd.isDataWaiting) {
		if( BGSND_GetFreeSpace() >= BGSND_RB_DEFAULT_THRESHOLD ) {
			SpcIO_MsgQueuePut(SPC_ID_AUDIO_STRM_BGSND_DATA_REQUEST, 0, 0, 2);
		}
	}
}

/**
	Call back handler from AUDIO task when bgSnd is off
*/
void spc_bgSnd_closeHandler(void)
{

	SpcIO_MsgQueuePut(SPC_ID_AUDIO_CONTROL_BGSND_CLOSE, 0, 0, 2);
}

void spc_BgSndStart(void)
{   
#ifdef SPH_CHIP_BACK_PHONECALL_USED
	return;
#endif

	if(!IS_SPC_ID_SPEECH_CUSTOM_DATA_REQUEST_DONE){ // prevent background sound on before EM data sending
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_BGSND_USAGE, SPC_APP_BGSND_USAGE, 4);
		return;
	}
	
	if(!IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)){ // bg sound on without any speech
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_BGSND_USAGE, SPC_APP_BGSND_USAGE, 3);		
		return;
	}

	if(IS_SPC_APP_USED(SPC_APP_HOLD_USAGE)){
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_BGSND_USAGE, SPC_APP_BGSND_USAGE, 2);		

		ASSERT(0);
		
		return;
	}

	gSpc_bgSnd.isDataWaiting = KAL_FALSE;
	BGSND_Start(spc_bgSnd_handler, spc_bgSnd_closeHandler,
		gSpc_bgSnd.ulGainLevel, gSpc_bgSnd.dlGainLevel);
	
	SET_SPC_APP_USAGE(SPC_APP_BGSND_USAGE);
}

void spc_BgSndStop(void)
{
	
	if(!IS_SPC_APP_USED(SPC_APP_BGSND_USAGE)){
		// just leave log and return, 
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_BGSND_USAGE, SPC_APP_BGSND_USAGE, 0);
		
		SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_BGSND_OFF_ACK, 0, 0);
		return; 
	} 

	// to avoid to many data request 
	gSpc_bgSnd.isDataWaiting = KAL_TRUE; 	
	BGSND_Stop();
	
}

void spc_BgSndClose(void)
{


	BGSND_Close();
	CLR_SPC_APP_USAGE(SPC_APP_BGSND_USAGE);
	SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_BGSND_OFF_ACK, 0, 0);
}
/**
	@ulGainLevel: 0~7 levels, mapping to 0~32767 
	@dlGainLevel: 0~7 levels, mapping to 0~32767
*/
void spc_BgSndConfig(kal_uint8 ulGainLevel, kal_uint8 dlGainLevel)
{
	gSpc_bgSnd.ulGainLevel = ulGainLevel;
	gSpc_bgSnd.dlGainLevel = dlGainLevel;

	// when application is running, update hte gain directly
	if(IS_SPC_APP_USED(SPC_APP_BGSND_USAGE)){
		BGSND_ConfigULMixer(KAL_TRUE, gSpc_bgSnd.ulGainLevel);
		BGSND_ConfigDLMixer(KAL_TRUE, gSpc_bgSnd.dlGainLevel);
	}
}
// ----------------------------------------------------------------------------
// CTM
// ----------------------------------------------------------------------------

#ifdef __CTM_SUPPORT__

#define SPC_CTM_DUMP_DEBUG_BUF_SIZE 652 // 163 *4 

typedef struct _SPC_CTM_T_
{
	kal_bool isDumpDebugFile;
	kal_bool isDumpDataWaiting;
	kal_uint16 dumpDebugBuf[SPC_CTM_DUMP_DEBUG_BUF_SIZE]; 
	kal_uint16 dumpDebugBufPtr;
}_SPC_CTM_T;


#define SPC_CTM_BUFFER_SIZE 16392
__attribute__((aligned (4)))static kal_uint8 gSpc_Ctm_buf[SPC_CTM_BUFFER_SIZE];

static _SPC_CTM_T gSpc_ctm;


void spc_ctm_sendDumpDebugData(void)
{
	kal_bool sendResult;

	if(!IS_SPC_APP_USED(SPC_APP_CTM_USAGE)){ // prevent data sending after CTM is off
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_CTM_USAGE, SPC_APP_CTM_USAGE, 1);
		return;
	}
	
	

	sendResult = (SpcIO_WriteDataToAp(NULL, 0, 
				gSpc_ctm.dumpDebugBuf, ((gSpc_ctm.dumpDebugBufPtr)<<1), NULL, 0, 
				SPCIO_MSG_FROM_SPC_CTM_DEBUG_DATA_NOTIFY));		
	
	if(KAL_TRUE !=  sendResult) {
			//clean up the read waiting flag when send fail to prevent blocking. 
			gSpc_ctm.dumpDebugBufPtr = 0;
			gSpc_ctm.isDumpDataWaiting = KAL_FALSE;
			
	}	
}

void spc_ctm_sendDumpDebugDataDone(void)
{
	if(!IS_SPC_APP_USED(SPC_APP_CTM_USAGE)){		
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_CTM_USAGE, SPC_APP_CTM_USAGE, 2);
		return;
	}
	gSpc_ctm.dumpDebugBufPtr = 0;
	gSpc_ctm.isDumpDataWaiting = false;
}
	
static void spc_ctm_handler(L1Ctm_Event event, void *param)
{

}

/**
	This function is running under L1audioTask, as a callback function
	@length: length of buffer unit in 16bit. 
*/
void spc_Ctm_DebugCallback(uint16 pos, uint16 *buffer, uint16 length, bool isDone)
{

	if(gSpc_ctm.isDumpDebugFile == false)
	{
		return; 
	}


	if(true == isDone ){
		
		if( KAL_TRUE == gSpc_ctm.isDumpDataWaiting){
			kal_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_CTM_USAGE, SPC_APP_CTM_USAGE, 1);
			return;
		}
		
		// send request to MED
		SpcIO_MsgQueuePut(SPC_ID_AUDIO_STRM_CTM_DUMP_DATA_NOTIFY, 0, 0, 2);	
	   gSpc_ctm.isDumpDataWaiting = KAL_TRUE;
		
	} else {
		spcBufInfo info; 
		
		if( KAL_TRUE == gSpc_ctm.isDumpDataWaiting){
			kal_trace( TRACE_INFO, SPC_M2A_DROP, SPC_APP_CTM_USAGE, SPC_APP_CTM_USAGE, 0);
			return;
		}
	
		info.syncWord = 0x2A2A;
		info.length = length*sizeof(uint16);
		
		switch(pos){		
			case UL_IN_WRITE_FILE_REQUEST:
				info.type = AUD_CCCI_STRMBUF_TYPE_CTM_UL_IN;
				break;
			case DL_IN_WRITE_FILE_REQUEST:
				info.type = AUD_CCCI_STRMBUF_TYPE_CTM_DL_IN;
				break;
			case UL_OUT_WRITE_FILE_REQUEST:
				info.type = AUD_CCCI_STRMBUF_TYPE_CTM_UL_OUT;
				break;
			case DL_OUT_WRITE_FILE_REQUEST:
				info.type = AUD_CCCI_STRMBUF_TYPE_CTM_DL_OUT;
				break;
			default:
				ASSERT(0);
		}
		
		memcpy((uint8 *)(&(gSpc_ctm.dumpDebugBuf[gSpc_ctm.dumpDebugBufPtr])), &info, sizeof(spcBufInfo));
		gSpc_ctm.dumpDebugBufPtr += 3; // header= sizeof(spcBufInfo)
		memcpy((uint8 *)(&(gSpc_ctm.dumpDebugBuf[gSpc_ctm.dumpDebugBufPtr])), buffer, length*sizeof(uint16));
		gSpc_ctm.dumpDebugBufPtr +=length; 

		ASSERT(gSpc_ctm.dumpDebugBufPtr <= SPC_CTM_DUMP_DEBUG_BUF_SIZE); // overflow protection
	}
}

/**
	@mode: 0: DIRECT_MODE, 1: BAUDOT_MODE
*/
void spc_CtmStart(kal_uint16 mode)
{
	if(!IS_SPC_ID_SPEECH_CUSTOM_DATA_REQUEST_DONE){ // prevent ctm on before EM data sending
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_CTM_USAGE, SPC_APP_CTM_USAGE, 3);
		return;
	}

	if (L1Ctm_GetMemReq() > SPC_CTM_BUFFER_SIZE)
		ASSERT(0);

	gSpc_ctm.isDumpDataWaiting = false;
	memset(gSpc_ctm.dumpDebugBuf, 0, sizeof(uint16)*SPC_CTM_DUMP_DEBUG_BUF_SIZE);
	gSpc_ctm.dumpDebugBufPtr=0;
	
   L1Ctm_Open( mode, spc_ctm_handler, gSpc_Ctm_buf, SPC_CTM_BUFFER_SIZE, spc_Ctm_DebugCallback);
	SET_SPC_APP_USAGE(SPC_APP_CTM_USAGE);
}

void spc_CtmStop(void)
{
	if(!IS_SPC_APP_USED(SPC_APP_CTM_USAGE)){
		// just leave log and return
		kal_trace( TRACE_INFO, SPC_ILLEGAL_SPC_APP_BEHAVIOR, SPC_APP_CTM_USAGE, SPC_APP_CTM_USAGE, 0);
		return; 
	} 
	
	L1Ctm_Close();

	CLR_SPC_APP_USAGE(SPC_APP_CTM_USAGE);
}

/*
[REMIND] This function "L1Ctm_StartNegotiation" is not called from AP side. 
The actual user is L1D in modem. So phase it out. 

void spc_CtmNegotiation(void)
{
	L1Ctm_StartNegotiation();
}
*/

void spc_CtmDebugConfig(kal_bool turnOn)
{
	gSpc_ctm.isDumpDebugFile = turnOn;
}

#endif // __CTM_SUPPORT__

// ----------------------------------------------------------------------------
// Parameter Setting like EM
// ----------------------------------------------------------------------------

void spc_ReceiveEMParameter_common(const kal_uint16 offset, const kal_uint16 length)
{
	spcBufInfo info;
	AUDIO_CUSTOM_PARAM_STRUCT *audio_par;
	
	audio_par = (AUDIO_CUSTOM_PARAM_STRUCT *)(&emDataBuf); //buffer reuse
	
	SpcIO_GetDataFromAp_inOneTime(offset, length, sizeof(spcBufInfo), 
		&info, audio_par);

	//header checking
   ASSERT(info.syncWord == 0xA2A2);
   ASSERT((info.type & 0xF) == AUD_CCCI_STRMBUF_TYPE_EM_PARAM); //just use the bit[0:3] to inidicate the type. 
   ASSERT(info.length == (length-6));
	
	// common parameter
	L1SP_LoadCommonSpeechPara(audio_par->speech_common_para);
	// mode parameter
   l1sp_setAllSpeechModePara((uint16 *)(audio_par->speech_mode_para), 8 * 16);

	// [History] useless
   // memcpy(SPH_VOL_PAR , audio_par->speech_volume_para, sizeof(uint16) * 4);

	// set Debug Info
	L1Audio_SetDebugInfo(audio_par->debug_info);
	VMREC_ConfigEpl();
	
	// FIR
   l1sp_setAllSpeechFirCoeff_InputOnly((int16 *)(audio_par->sph_in_fir), 6 * 45);
   l1sp_setAllSpeechFirCoeff_OutputOnly((int16 *)(audio_par->sph_out_fir), 6 * 45);
	
	SET_SPC_EM_INIT(SPC_EM_INIT_COMMON);
	
	// loading!!
	L1SP_LoadSpeechPara();
}

void spc_ReceiveDmnrParameter(const kal_uint16 offset, const kal_uint16 length)
{
	spcBufInfo info;
	AUDIO_CUSTOM_DMNR_PARAM_STRUCT *dmnrPar;

	dmnrPar = (AUDIO_CUSTOM_DMNR_PARAM_STRUCT *)(&emDataBuf);

	SpcIO_GetDataFromAp_inOneTime(offset, length, sizeof(spcBufInfo), &info, dmnrPar);

	//header checking
   ASSERT(info.syncWord == 0xA2A2);
   ASSERT((info.type & 0xF) == AUD_CCCI_STRMBUF_TYPE_EM_PARAM); //just use the bit[0:3] to inidicate the type. 
   ASSERT(info.length == (length-6));
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	L1SP_SetDMNRPara(dmnrPar->DMNR_para);
	
#if defined(__AMRWB_LINK_SUPPORT__)
	L1SP_SetWbDMNRPara(dmnrPar->WB_DMNR_para);
#endif // defined(__AMRWB_LINK_SUPPORT__)
#endif // __DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	

	SET_SPC_EM_INIT(SPC_EM_INIT_DMNR);

	if(info.length>(NUM_DMNR_PARAM + NUM_WB_DMNR_PARAM)) { // [NEW] calibration data for loud speaker mode DMNR
	
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)		
	L1SP_SetLSpkDMNRPara(dmnrPar->LSpk_DMNR_para);
#if defined(__AMRWB_LINK_SUPPORT__)		
	L1SP_SetLSpkWbDMNRPara(dmnrPar->LSpk_WB_DMNR_para);
#endif // defined(__AMRWB_LINK_SUPPORT__)
#endif // __DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	

	SET_SPC_EM_INIT(SPC_EM_INIT_LSPK_DMNR);
	}

}

void spc_ReceiveEMParameter_wb(const kal_uint16 offset, const kal_uint16 length)
{
	spcBufInfo info;
	AUDIO_CUSTOM_WB_PARAM_STRUCT *wbPar;
	
	wbPar = (AUDIO_CUSTOM_WB_PARAM_STRUCT *)(&emDataBuf); //buffer reuse
	
	SpcIO_GetDataFromAp_inOneTime(offset, length, sizeof(spcBufInfo), &info, wbPar);

	//header checking
   ASSERT(info.syncWord == 0xA2A2);
   ASSERT((info.type & 0xF) == AUD_CCCI_STRMBUF_TYPE_EM_PARAM); //just use the bit[0:3] to inidicate the type. 
   ASSERT(info.length == (length-6));

#ifdef SPC_MSG_ORG_VER	
	l1sp_setAllWbSpeechModePara((uint16 *)wbPar->speech_mode_wb_para, 8 * 16 );
	if( wbPar->input_out_fir_flag == 0 ){//input
		l1sp_setAllWbSpeechFirCoeff_InputOnly((int16 *)(wbPar->sph_wb_fir),  6 * 90);
	}else if( wbPar->input_out_fir_flag == 1 ){//output
		l1sp_setAllWbSpeechFirCoeff_OutputOnly((int16 *)(wbPar->sph_wb_fir), 6 * 90);
	}else {
		ASSERT(0);
	} 
#else 
	l1sp_setAllWbSpeechModePara((uint16 *)wbPar->speech_mode_wb_para, 8 * 16 );
	l1sp_setAllWbSpeechFirCoeff_InputOnly((int16 *)(wbPar->sph_wb_in_fir),  6 * 90);
	l1sp_setAllWbSpeechFirCoeff_OutputOnly((int16 *)(wbPar->sph_wb_out_fir), 6 * 90);
#endif

	SET_SPC_EM_INIT(SPC_EM_INIT_WB);
}

void spc_ReceiveHacParameter(const kal_uint16 offset, const kal_uint16 length)
{
	spcBufInfo info;
	AUDIO_CUSTOM_HAC_PARAM_STRUCT *hacParam; //buffer reuse
	
	hacParam = (AUDIO_CUSTOM_HAC_PARAM_STRUCT *)(&emDataBuf); //buffer reuse

	//get data
	SpcIO_GetDataFromAp_inOneTime(offset, length, sizeof(spcBufInfo), &info, hacParam);
	
	//header checking
	ASSERT(info.syncWord == 0xA2A2);
	ASSERT(info.type== AUD_CCCI_STRMBUF_TYPE_HAC_PARAM);
	ASSERT(info.length == (length-6));
	
	spe_setHacSpeechModePara(hacParam->speech_hac_mode_nb_para, 16);
	spe_setHacSpeechFirCoeff_InputOnly(hacParam->sph_hac_in_fir, 45);
	spe_setHacSpeechFirCoeff_OutputOnly(hacParam->sph_hac_out_fir, 45);

	spe_setHacWbSpeechModePara(hacParam->speech_hac_mode_wb_para, 16);
	spe_setHacWbSpeechFirCoeff_InputOnly(hacParam->sph_hac_wb_in_fir, 90);
	spe_setHacWbSpeechFirCoeff_OutputOnly(hacParam->sph_hac_wb_out_fir, 90);

	spe_setHacModeNeeded(true);
}	


void spc_ReceiveViberationSpkParameter(const kal_uint16 offset, const kal_uint16 length)
{
	spcBufInfo info;
	AUDIO_VIBSPK_PARAMETER_STRUCT *vibSpkParam; //buffer reuse
	
	vibSpkParam = (AUDIO_VIBSPK_PARAMETER_STRUCT *)(&emDataBuf); //buffer reuse

	//get data
	SpcIO_GetDataFromAp_inOneTime(offset, length, sizeof(spcBufInfo), &info, vibSpkParam);
	
	//header checking
	ASSERT(info.syncWord == 0xA2A2);
	ASSERT(info.type== AUD_CCCI_STRMBUF_TYPE_VIBSPK_PARAM); //just use the bit[0:3] to inidicate the type. 
	ASSERT(info.length == (length-6));
	

	// copy coefficient
	l1sp_setNotchFilterParam(vibSpkParam->notch_filter_para, vibSpkParam->is2In1Spk);

	
}

void spc_ReceiveNxpSmartPaParameter(const kal_uint16 offset, const kal_uint16 length)
{
	spcBufInfo info;
	AUDIO_NXP_SMARTPA_PARAMETER_STRUCT *nxpPaParam; //buffer reuse
	
	nxpPaParam = (AUDIO_NXP_SMARTPA_PARAMETER_STRUCT *)(&emDataBuf); //buffer reuse

	//get data
	SpcIO_GetDataFromAp_inOneTime(offset, length, sizeof(spcBufInfo), &info, nxpPaParam);
	
	//header checking
	ASSERT(info.syncWord == 0xA2A2);
	ASSERT(info.type== AUD_CCCI_STRMBUF_TYPE_NXP_SMARTPA_PARAM); //just use the bit[0:3] to inidicate the type. 
	ASSERT(info.length == (length-6));
	

	SPE_SetAgcInfo(nxpPaParam->isNxpFeatureOptOn, nxpPaParam->mic_index, nxpPaParam->chip_delay_with_switch);
}	


// ----------------------------------------------------------------------------
// Volume Setting 
// ----------------------------------------------------------------------------
/**
	@digiGain: unit is 0.25 dB
*/
void spc_gain_DlDigiGainSet(kal_uint16 digiGain)
{
	l1sp_digiOnly_SetOutputVolume((kal_int16)digiGain);
}

/**
	@refDigiGain: unit is 0.25 dB
*/
void spc_gain_DlEnhRefDigiGainSet(kal_uint16 refDigiGain)
{
	l1sp_digiOnly_SetEnhRefOutputVolume((kal_int16)refDigiGain);
}

void spc_gain_UlDigiGainSet(kal_uint16 digiGain)
{
	l1sp_digiOnly_SetMicrophoneVolume((kal_int16)digiGain);
}

/**
	@on: 1 for turn on mute, 0 for turn off mute
*/
void spc_gain_UlMuteSet(kal_bool on)
{
	if(IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) {
		gSpc.spcMuteUl = on;
		SP_MuteUlFromDiffPos(on, SP_MIC_MUTE_POS_FROM_SPC); // L1SP_MuteMicrophone(on);
	} else {
		kal_trace(TRACE_STATE, SPC_SET_DROP_UL_MUTE);
	}
}

void spc_gain_DlMuteSet(kal_bool on)
{
	if(IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) {
		gSpc.spcMuteDl = on;
		L1SP_MuteSpeaker(on);		
	} else {
		kal_trace(TRACE_STATE, SPC_SET_DROP_DL_MUTE);
	}
}

void spc_gain_UlEnhResultMuteSet(kal_bool on)
{
	if(IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) {
		gSpc.spcMuteUlEnhResult = on;
		SP_MuteUlEnhResult(on);	
	} else {
		kal_trace(TRACE_STATE, SPC_SET_DROP_UL_ENH_RESULT_MUTE);
	}
}

void spc_gain_UlSourceMuteSet(kal_bool on)
{
	if(IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) {
		gSpc.spcMuteUlSource = on;
		SP_MuteUlSource(on);	
	} else {
		kal_trace(TRACE_STATE, SPC_SET_DROP_UL_SOURCE_MUTE);
	}
}

// ----------------------------------------------------------------------------
// Device Related Setting 
// ----------------------------------------------------------------------------

void spc_dev_SamplingRateSet(kal_uint16 sampleRate)
{
	kal_prompt_trace(MOD_L1SP, "[msbc]spc_dev_SamplingRateSet, sampleRate: %d, ", sampleRate);

	switch(sampleRate){

		case 8000:
			AFE_SetVoice8KMode(0);
			break;
		case 16000:
			AFE_SetVoice8KMode(1);
			break;
		default:			
			ASSERT(0);
	} 
}

// ----------------------------------------------------------------------------
// AUDL running functions Related
// ----------------------------------------------------------------------------

void spc_A2M_MsgHandler(kal_uint32 ccciMsg, kal_uint32 ccciResv)
{
	kal_uint16 cmd, msgData16;
	kal_uint16 msgData32; 

	cmd = SPCIO_CCCI_MSG_CMD(ccciMsg);
	msgData16 = SPCIO_CCCI_MSG_DATA16(ccciMsg);
	msgData32 = ccciResv;

	switch(cmd){		
		case MSG_A2M_SPH_DL_DIGIT_VOLUME: 
			spc_gain_DlDigiGainSet(msgData16);
			break;
		case MSG_A2M_SPH_UL_DIGIT_VOLUME: 
			spc_gain_UlDigiGainSet(msgData16);
			break;
		case MSG_A2M_MUTE_SPH_UL: 
			spc_gain_UlMuteSet( (kal_bool)(msgData16&1) );
			break;
		case MSG_A2M_MUTE_SPH_DL: 
			spc_gain_DlMuteSet( (kal_bool)(msgData16&1) );
			break;
		case MSG_A2M_SIDETONE_VOLUME: 
			SIDETONE_SetExtStVolume(msgData16);
			break;
		case MSG_A2M_SPH_DL_ENH_REF_DIGIT_VOLUME:
			spc_gain_DlEnhRefDigiGainSet(msgData16);
			break;
		case MSG_A2M_SIDETONE_CONFIG:
			// TODO:
			break;
		case MSG_A2M_MUTE_SPH_UL_ENH_RESULT:
			spc_gain_UlEnhResultMuteSet((kal_bool)(msgData16&1));
			break;
		case MSG_A2M_MUTE_SPH_UL_SOURCE:
			spc_gain_UlSourceMuteSet((kal_bool)(msgData16&1));
			break;
			
		// --------- [0x10] device related -----------
		case MSG_A2M_SET_SAMPLE_RATE: 
			spc_dev_SamplingRateSet(msgData16);
			break;
		case MSG_A2M_SET_DUAL_MIC: break;


		// --------- [0x20] speech control -----------
		case MSG_A2M_SPH_ON: 
		{
			Spc_SpeechOn((kal_uint8) msgData16);
         SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SPH_ON_ACK, msgData16, 0);
				// SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_SPH_ON_ACK, msgData16));
      }
			break;
		case MSG_A2M_SPH_OFF: 
		{
			Spc_SpeechOff();
         SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SPH_OFF_ACK, 0, 0);
				// SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_SPH_OFF_ACK, 0));			
		}
			break;
		case MSG_A2M_SET_SPH_MODE: 
		{
			Spc_SetSpeechMode_Adaptation( (kal_uint8) msgData16 );
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SET_SPH_MODE_ACK, msgData16, 0);
		}
			break;
		case MSG_A2M_CTRL_SPH_ENH: 
		{
			L1SP_EnableSpeechEnhancement((msgData16!=0));
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_CTRL_SPH_ENH_ACK, msgData16, 0);
		}		
			break; 
		case MSG_A2M_CONFIG_SPH_ENH: 
		{
			/*
			@msgData16: as following define. mask define is sync with AP using SPH_ENH_MASK_XX in media.h
			This is the power on/off setting of enhancement. Most of the case, it should be totally on. 
			#define SPH_ENH_MASK_ES    (1<<0)
			#define SPH_ENH_MASK_AEC   (1<<1)
			#define SPH_ENH_MASK_EES   (1<<2)
			#define SPH_ENH_MASK_ULNR  (1<<3)
			#define SPH_ENH_MASK_DLNR  (1<<4)
			#define SPH_ENH_MASK_TDDNC (1<<5)
			#define SPH_ENH_MASK_DMNR  (1<<6)
			#define SPH_ENH_MASK_SIDETONE (1 << 7)

			@msgData32[15:0]: as following define. This is the dynamic switch to decided the enhancment output. 
			typedef enum{
		                                        // ==> SAL_ENH_DYNAMIC_MUTE_UL, bit 0. Please DO NOT use it
				SPE_DYNAMIC_MASK_DMNR = 0x1, // ==> SAL_ENH_DYNAMIC_DMNR_MUX, bit 1
				SPE_DYNAMIC_MASK_VCE  = 0x2, // ==> SAL_ENH_DYNAMIC_VCE_MUX, bit 2
				SPE_DYNAMIC_MASK_BWE  = 0x4, // ==> SAL_ENH_DYNAMIC_BWE_MUX, bit 3
				SPE_DYNAMIC_MASK_DLNR  = 0x8, // ==> SAL_ENH_DYNAMIC_DLNR_MUX, bit 4  
				SPE_DYNAMIC_MASK_ULNR  = 0x10, // ==> SAL_ENH_DYNAMIC_DLNR_MUX, bit 5 
				SPE_DYNAMIC_MASK_LSPK_DMNR  = 0x20, // ==> SAL_ENH_DYNAMIC_SIDEKEYCTRL_DGAIN_MUX, bit 6
				SPE_DYNAMIC_MASK_SIDEKEYCTRL_DGAIN = 0x40, // ==> SAL_ENH_DYNAMIC_SIDEKEYCTRL_DGAIN_MUX, bit 7
				SPE_DYNAMIC_MASK_DLNR_INIT_CTRL = 0x80, // ==> SAL_ENH_DYNAMIC_DL_NR_INIT_CTRL_MUX, bit 8
				SPE_DYNAMIC_MASK_AEC = 0x100, // ==> SAL_ENH_DYNAMIC_AEC_MUX, bit 9
			}SPE_SUB_MASK_T;
			*/
			l1sp_updateSpeUsrMaskWithWholeValue(msgData16); 
			l1sp_updateSpeUsrSubMaskWithWholeValue((kal_uint16)(msgData32&0xffff));			
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_CONFIG_SPH_ENH_ACK, msgData16, 0);
		}
			break; 
		case MSG_A2M_SET_ACOUSTIC_LOOPBACK: 
		{
			Spc_AcousticLoopback((kal_uint8) msgData16, msgData32 );
         SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SET_ACOUSTIC_LOOPBACK_ACK, msgData16, msgData32);
      } 
			break;			
		case MSG_A2M_PRINT_SPH_COEFF: 
		{
			spc_DebugPrint();
			// ack is: SPCIO_MSG_FROM_SPC_PRINT_SPH_COEFF_ACK --> MSG_M2A_PRINT_SPH_COEFF_ACK
		}	
			break;
		case MSG_A2M_SPH_ON_FOR_HOLD_CALL: 
		{
			// [REMIND] No application can be on under this application
			spc_SpeechOnForCallHold((msgData16 == 1)); // bit 0, 0 for off, 1 for on
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SPH_ON_FOR_HOLD_CALL_ACK, 0, 0);
		}
			break;
		/* Phase out from MT6589
		case MSG_A2M_QUERY_MD_CAPABILITY: 
		{
		 	kal_uint16 cap;
		 	cap = spc_QueryMdCapability();
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_QUERY_MD_CAPABILITY_ACK, 0, 0);
				// SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_QUERY_MD_CAPABILITY_ACK, cap));
			break;
		}
		case MSG_A2M_SET_MD_CAPABILITY: 
		{
		 	// Due to HD_RECORD is implemented in AP side, this msg is keep for future used. 
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SET_MD_CAPABILITY_ACK, 0, 0); 
				//SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_SET_MD_CAPABILITY_ACK, msgData16));
		}
			break;
			*/
		
		// --------- [0x30] speech control -----------
		case MSG_A2M_PNW_ON:  // normal use always narrow band/decided by network
		{
			spc_PcmNWayStart(msgData16, SPC_PCMNWAY_FORMAT_UNSET, SPC_PCMNWAY_APP_TYPE_UNSET);
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_PNW_ON_ACK, msgData16, 0);
				// SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_PNW_ON_ACK, msgData16));
		}
			break;
		case MSG_A2M_PNW_OFF: 
		{
			spc_PcmNWayStop();
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_PNW_OFF_ACK, msgData16, 0);
				// SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_PNW_OFF_ACK, msgData16));				
		}
			break;
		case MSG_A2M_RECORD_ON: 
		{
			spc_RecordStart((kal_uint8)(msgData16&0xF), (kal_uint8)((msgData16>>4)&0xF), (kal_uint8)((msgData16>>8)&0xF));
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_RECORD_ON_ACK, msgData16, 0);
				// SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_RECORD_ON_ACK, msgData16));
		}
			break;
		case MSG_A2M_RECORD_OFF: 
		{
			spc_RecordStop();
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_RECORD_OFF_ACK, msgData16, 0);
				// SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_RECORD_OFF_ACK, msgData16));
		}				
			break;
		case MSG_A2M_DMNR_RECPLAY_ON: 
		{
			spc_PcmNWayStart((SPC_PNW_MSG_BUFFER_SPK|SPC_PNW_MSG_BUFFER_MIC), 
					(SPC_PCMNWAY_Format)msgData16, SPC_PCMNWAY_APP_TYPE_DMNR_CAL_PLAY_REC);
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_DMNR_RECPLAY_ON_ACK, msgData16, 0);
				// SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_DMNR_RECPLAY_ON_ACK, msgData16));
		}
			break;
		case MSG_A2M_DMNR_RECPLAY_OFF: 
		{
			spc_PcmNWayStop();
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_DMNR_RECPLAY_OFF_ACK, msgData16, 0);
				//SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_DMNR_RECPLAY_OFF_ACK, msgData16));				
		}
			break;
		case MSG_A2M_DMNR_REC_ONLY_ON: 
		{
			spc_PcmNWayStart((SPC_PNW_MSG_BUFFER_SPK|SPC_PNW_MSG_BUFFER_MIC), 
				(SPC_PCMNWAY_Format)msgData16, SPC_PCMNWAY_APP_TYPE_DMNR_CAL_REC_ONLY);
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_DMNR_REC_ONLY_ON_ACK, msgData16, 0);
				// SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_DMNR_REC_ONLY_ON_ACK, msgData16));
		}
			break;
		case MSG_A2M_DMNR_REC_ONLY_OFF: 
		{
			spc_PcmNWayStop();
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_DMNR_REC_ONLY_OFF_ACK, msgData16, 0);
				// SPCIO_CCCI_MSG_CONSTRCUT_CMD(MSG_M2A_DMNR_REC_ONLY_OFF_ACK, msgData16));				
		}
			break;

		case MSG_A2M_PCM_REC_ON:
		{
			spc_PcmRecordStart((kal_uint8)(msgData16&0xF), (kal_uint8)((msgData16>>4)&0xF));
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_PCM_REC_ON_ACK, msgData16, 0);
		}
			break;
		case MSG_A2M_PCM_REC_OFF:
		{
			spc_PcmRecordStop();
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_PCM_REC_OFF_ACK, msgData16, 0);
		}
			break;
		case MSG_A2M_VM_REC_ON:
		{
			spc_VmRecordStart();
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_VM_REC_ON_ACK, msgData16, 0);
		}
			break;			
		case MSG_A2M_VM_REC_OFF:
		{
			spc_VmRecordStop();                                   
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_VM_REC_OFF_ACK, msgData16, 0);
		}
			break;
         case MSG_A2M_RECORD_RAW_PCM_ON:
		{
			spc_RawPcmRecordStart((kal_uint8)(msgData16&0xF));
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_RECORD_RAW_PCM_ON_ACK, msgData16, 0);
		}
		break;
        case MSG_A2M_RECORD_RAW_PCM_OFF:
		{
			spc_RawPcmRecordStop();
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_RECORD_RAW_PCM_OFF_ACK, msgData16, 0);
		}
		break;
		// --------- [0x40] other control function -----------
#ifdef __CTM_SUPPORT__				
		case MSG_A2M_CTM_ON: 
			spc_CtmStart(msgData16);
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_CTM_ON_ACK, msgData16, 0);
			break;
		case MSG_A2M_CTM_OFF: 
			spc_CtmStop();
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_CTM_OFF_ACK, msgData16, 0);
			break;
		case MSG_A2M_CTM_DUMP_DEBUG_FILE: 
			spc_CtmDebugConfig(msgData16!=0);
			break; // ack is SPCIO_MSG_FROM_SPC_CTM_DUMP_DEBUG_FILE_ACK-- > MSG_M2A_CTM_DUMP_DEBUG_FILE_ACK
#endif // __CTM_SUPPORT__					

		case MSG_A2M_BGSND_ON:
			spc_BgSndStart();
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_BGSND_ON_ACK, msgData16, 0);
			break;
		case MSG_A2M_BGSND_OFF: 
			spc_BgSndStop();
			// SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_BGSND_OFF_ACK, msgData16, 0); 
			break;
		case MSG_A2M_BGSND_CONFIG: 
			// msgData16, [15:8] ulGainLevel from 0 ~ 255, [7:0] dlGainLevel from 0 ~ 255
			// we mapping the value into 0~7 levels. so right shift 5 
			// spc_BgSndConfig((msgData16>>8)>>5, (msgData16&0xff)>>5);
			spc_BgSndConfig((msgData16>>13), ((msgData16&0xff)>>5));
			break; // SPCIO_MSG_FROM_SPC_BGSND_CONFIG_ACK-- > MSG_M2A_BGSND_CONFIG_ACK

		// --------- [0x50] Recevie DATA notify  -----------
		case MSG_A2M_PNW_DLDATA_NOTIFY: 
			spc_pcmNWay_writeDlDataDone((kal_uint16)msgData32, msgData16);
			break;
		case MSG_A2M_BGSND_DATA_NOTIFY: 
			spc_bgSnd_writeDataDone( (kal_uint16)msgData32, msgData16);
			break;
		case MSG_A2M_CTM_DATA_NOTIFY: break;

		// --------- [0x60] Send DATA Ack  ---------------
		case MSG_A2M_PNW_ULDATA_READ_ACK: 
			spc_pcmNWay_sendUlDataDone();
			break;
		case MSG_A2M_REC_DATA_READ_ACK: 
			spc_record_sendMicDataDone();
			break;
		case MSG_A2M_CTM_DEBUG_DATA_READ_ACK:
			spc_ctm_sendDumpDebugDataDone();
			break;
		case MSG_A2M_PCM_REC_DATA_READ_ACK:
			spc_pcmRec_sendMicDataDone();
			break;
		case MSG_A2M_VM_REC_DATA_READ_ACK:
			spc_vmRec_sendMicDataDone();
			break;
		case MSG_A2M_RAW_PCM_REC_DATA_READ_ACK:
            spc_RawPcmRec_sendDataDone();
			break;

		// --------- [0x70] EM related --------------------
		case MSG_A2M_EM_INCALL: 
			spc_ReceiveEMParameter_common( (kal_uint16)msgData32, msgData16 );
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_EM_INCALL_ACK, 0, 0 );
			break;
		case MSG_A2M_EM_DMNR: 
			spc_ReceiveDmnrParameter((kal_uint16)msgData32, msgData16);
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_EM_DMNR_ACK, 0, 0 );
			break;
		case MSG_A2M_EM_WB: 
			spc_ReceiveEMParameter_wb((kal_uint16)msgData32, msgData16);
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_EM_WB_ACK, 0, 0 );
			break;
		case MSG_A2M_NETWORK_STATUS_ACK:        
	      break;		
		case MSG_A2M_QUERY_RF_INFO:
		   spc_notify_rf_info();	
         break;
		case MSG_A2M_EM_HAC: 
			spc_ReceiveHacParameter((kal_uint16)msgData32, msgData16);
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_EM_HAC_ACK, 0, 0 );
			break;
		// --------- [0x80] New feature data related --------------------
		case MSG_A2M_VIBSPK_PARAMETER:
			spc_ReceiveViberationSpkParameter((kal_uint16)msgData32, msgData16);
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_VIBSPK_PARAMETER_ACK, 0, 0 );
			break;

		case MSG_A2M_NXP_SMARTPA_PARAMETER: 
			spc_ReceiveNxpSmartPaParameter((kal_uint16)msgData32, msgData16);
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_NXP_SMARTPA_PARAMETER_ACK, 0, 0 );
			break;
		default: 
			kal_trace(TRACE_INFO, SPCIO_INVALID_MSG, SPC_ID_AUDIO_A2M_CCCI, ccciMsg, ccciResv);
		
	}
}


//=============================================================================
//=================original version of ccci msg from MT6575/MT6573=============
//=============================================================================

#ifdef SPC_MSG_ORG_VER	

/**
	CCCI 0x20 beging (MSG_TYPE_SPEECH_CTRL)
*/
void spc_Speech_Control(kal_uint32 ccciMsg)
{
   kal_uint32 func, param;

   func = SPCIO_CCCI_MSG_ORG_TYPE_AND_FUNC1(ccciMsg); // bit [31:24]
   param = SPCIO_CCCI_MSG_ORG_PARAM1(ccciMsg); // bit [23:0]

   switch (func) {
      case MSG_SPH_CTRL_SPH_ON:
         {
				Spc_SpeechOn((kal_uint8) param);
            SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SPH_ON_ACK, param, 0);
					// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_SPH_CTRL_SPH_ON_ACK,param));
         }   
         break;
      case MSG_SPH_CTRL_SPH_OFF:
         {
				Spc_SpeechOff();
				
         	SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SPH_OFF_ACK, 0, 0);
					// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_SPH_CTRL_SPH_OFF_ACK, 0));			
      	}
         break;
        
      case MSG_SPH_CTRL_SET_SPH_MODE:
   		{
				Spc_SetSpeechMode_Adaptation( (uint8)param );
				SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SPH_OFF_ACK, 0, 0);
					// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_SPH_CTRL_SET_SPH_MODE_ACK,param));
      	}
         break;
      
		/* 
		case MSG_SPH_CTRL_SET_ENH_INDIVIDUAL:
			break;
		*/
		case MSG_SPH_CTRL_SET_ENH:
			{
				L1SP_EnableSpeechEnhancement((param!=0));
				SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_CTRL_SPH_ENH_ACK, param, 0);
			}	
			break;

      case MSG_SPH_CTRL_SET_ACOUSTIC_LOOPBACK:
			{
			Spc_AcousticLoopback(param, ACLOOPBACK_DELAY);

         }     
         SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SET_ACOUSTIC_LOOPBACK_ACK, 0, 0);
         break;     
			
      case MSG_SPH_CTRL_GET_MD_CAPABILITY: //Query the compile option in the modem side. 
         {
		 	kal_uint16 cap;
		 	cap = spc_QueryMdCapability();
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_QUERY_MD_CAPABILITY_ACK, cap, 0); 
				// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_SPH_CTRL_GET_MD_CAPABILITY_ACK, cap));//( ccciMsg | 0x80000000 | cap);
         }
         break;
		case MSG_SPH_CTRL_SET_MD_CAPABILITY: //set the feature enable in the modem side
			{
		 	// Due to HD_RECORD is implemented in AP side, this msg is keep for future used. 
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_SET_MD_CAPABILITY_ACK, 0, 0);
				// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_SPH_CTRL_SET_MD_CAPABILITY_ACK, param));//( ccciMsg | 0x80000000 | param);
			}
			break;
		case MSG_SPH_CTRL_ENH_LOG_PRINT:
			{
			spc_DebugPrint();
			}
			break;
			
      default: {
         kal_trace(TRACE_INFO, SPCIO_INVALID_MSG, SPC_ID_AUDIO_A2M_CCCI, ccciMsg, 0);
      }

   }
}

/**
	CCCI 0x30 beging (MSG_TYPE_DATA_TRANSFER_CTRL)
*/
void spc_Data_Transfer_Control(kal_uint32 ccciMsg)
{
	kal_uint32 func, param;

   // funcType = (ccciMsg<<4)>>28;
   // param    = (ccciMsg<<12)>>12;

   func = SPCIO_CCCI_MSG_ORG_TYPE_AND_FUNC1(ccciMsg); // bit [31:24]
   param = SPCIO_CCCI_MSG_ORG_PARAM1(ccciMsg); // bit [23:0]

   switch (func) {
		case MSG_DATA_TRANSFER_PCM_ON: // 0x30: pcmnway on
			{
				spc_PcmNWayStart(param, SPC_PCMNWAY_FORMAT_UNSET, SPC_PCMNWAY_APP_TYPE_UNSET);
				SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_PNW_ON_ACK, param, 0);
					// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_DATA_TRANSFER_PCM_ON_ACK, param));
			}
			break;
		case MSG_DATA_TRANSFER_PCM_OFF: // 0x31: pcmnway off
			{
				spc_PcmNWayStop();
				SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_PNW_OFF_ACK, param, 0);
					// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_DATA_TRANSFER_PCM_OFF_ACK, param));				
			}
			break;
      case MSG_DATA_TRANSFER_RECORD_ON:
			{
				// param [11:0] format, [12:15] sampline rate index, [16:19] channel number
				spc_RecordStart((kal_uint8)(param&0xfff), (kal_uint8)((param >> 12)& 0xF), (kal_uint8)((param >> 16) & 0xF));
				SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_RECORD_ON_ACK, param, 0);
			}
			break;
		case MSG_DATA_TRANSFER_RECORD_OFF:
			{
				spc_RecordStop();
				SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_RECORD_OFF_ACK, param, 0);
					// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_DATA_TRANSFER_RECORD_ON_ACK, param));
			}
			break;

		case MSG_DATA_TRANSFER_DMRN_RECPLAY_ON: //0x35: pcm2way for calibration record play on 
			{
				spc_PcmNWayStart((SPC_PNW_MSG_BUFFER_SPK|SPC_PNW_MSG_BUFFER_MIC), 
					(P2W_Format)param, SPC_PCMNWAY_APP_TYPE_DMNR_CAL_PLAY_REC);
				SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_DMNR_RECPLAY_ON_ACK, param, 0);
					// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_DATA_TRANSFER_DMRN_RECPLAY_ON_ACK, param));
			}
			break;
		case MSG_DATA_TRANSFER_DMRN_RECPLAY_OFF: // 0x36:
			{
				spc_PcmNWayStop();
				SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_DMNR_RECPLAY_OFF_ACK, param, 0);
					// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_DATA_TRANSFER_DMRN_RECPLAY_OFF_ACK, param));				
			}
			break;
		case MSG_DATA_TRANSFER_DMRN_REC_ONLY_ON: // 0x37: pcm2way for calibration record only on 
			{
				spc_PcmNWayStart((SPC_PNW_MSG_BUFFER_SPK|SPC_PNW_MSG_BUFFER_MIC), 
					(P2W_Format)param, SPC_PCMNWAY_APP_TYPE_DMNR_CAL_REC_ONLY);
				SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_DMNR_REC_ONLY_ON_ACK, param, 0);
					// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_DATA_TRANSFER_DMRN_REC_ONLY_ON_ACK, param));
			}
			break;
		case MSG_DATA_TRANSFER_DMRN_REC_ONLY_OFF: // 0x38: 
			{
				spc_PcmNWayStop();
				SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_DMNR_REC_ONLY_OFF_ACK, param, 0);
					// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_DATA_TRANSFER_DMRN_REC_ONLY_OFF_ACK, param));				
			}
			break;
		default:
			kal_trace(TRACE_INFO, SPCIO_INVALID_MSG, SPC_ID_AUDIO_A2M_CCCI, ccciMsg, 0);

   }
}



/**
	CCCI 0x40 beging (MSG_TYPE_OTHER_API_HANDLER)
*/
void spcIo_Other_Api_Handler(kal_uint32 ccciMsg)
{
	kal_uint32 func, param;

   func = SPCIO_CCCI_MSG_ORG_TYPE_AND_FUNC1(ccciMsg); // bit [31:24]
   param = SPCIO_CCCI_MSG_ORG_PARAM1(ccciMsg); // bit [23:0]

	switch (func) {
#ifdef __CTM_SUPPORT__		
		case MSG_AP_CTM_ON:
			spc_CtmStart(param);
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_CTM_ON_ACK, param, 0);
				
			break;
		case MSG_AP_CTM_OFF:
			spc_CtmStop();
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_CTM_OFF_ACK, param, 0);				
			break;

		case MSG_AP_START_NEGOTIATION: // unused in CTM
			// spc_CtmNegotiation();
			// ack is SPCIO_MSG_FROM_SPC_CTM_NEGOTIATION_ACK--> MSG_M2A_AP_START_NEGOTIATION_ACK,			
			break;
#endif

		case MSG_AP_BGSND_ON:
			spc_BgSndStart();
			SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_BGSND_ON_ACK, param, 0);
				// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_AP_BGSND_ON_ACK, param) );
			break;
		case MSG_AP_BGSND_OFF:
			spc_BgSndStop();
			//SpcIO_SendMsgToAp( SPCIO_MSG_FROM_SPC_BGSND_OFF_ACK, param, 0);
				// SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(MSG_M2A_AP_BGSND_OFF_ACK, param) );
			break;
		case MSG_AP_BGSND_CONFIG:	
			{
			int32 gainUL, gainDL;
         uint8 ULlevel, DLlevel;
         

         gainUL = (int32)(param<<8)>>20;
         gainUL = gainUL/12;
         gainDL = (int32)(param<<20)>>20;
         gainDL = gainDL/12;

         if (gainUL > 0) {
            ULlevel = 7;
         } else if (gainUL < -7)
            ULlevel = 0;
         else
            ULlevel = 7+gainUL;

         if (gainDL > 0) {
            DLlevel = 7;
         } else if (gainDL < -7)
            DLlevel = 0;
         else
            DLlevel = 7+gainDL;

			   spc_BgSndConfig(ULlevel, DLlevel);
			}
			//ack is SPCIO_MSG_FROM_SPC_BGSND_CONFIG_ACK -- > MSG_M2A_AP_BGSND_CONFIG_ACK
			break;
		default:
			ASSERT(0);
			
	}
		
}

/**
	CCCI 0x50 begin
*/
void spc_Data_Notify(kal_uint32 ccciMsg, kal_uint32 ccciMsgRev)
{
	kal_uint32 func;
 	kal_uint16 offset; 
	kal_uint16 length;
	
	// funcType = (ccciMsg<<4)>>28;
	func = SPCIO_CCCI_MSG_ORG_TYPE_AND_FUNC2(ccciMsg); // bit [31:26]

	offset = SPCIO_CCCI_MSG_ORG_PARAM2_OFFSET(ccciMsg); // bit[25:13]
	length = SPCIO_CCCI_MSG_ORG_PARAM2_LENGTH(ccciMsg); // bit [12:0]
	
 	switch (func) {
		case MSG_DATA_NOTIFY_PNW_DLDATA:
		{
			spc_pcmNWay_writeDlDataDone(offset, length);

		}	
			break;
		case MSG_DATA_NOTIFY_BGS_NOTIFY:
		{
			spc_bgSnd_writeDataDone(offset, length);
		}
			break;
		default:
		ASSERT(0);
 	}
}

 
 
 /**
 	CCCI 0x60 begin
 */
 void spc_AckFromAP(kal_uint32 ccciMsg, kal_uint32 ccciMsgRev)
 {
	 kal_uint32 func;
	 // kal_uint16 offset; 
	 // kal_uint16 length;
	 
	 // funcType = (ccciMsg<<4)>>30;
	 func = SPCIO_CCCI_MSG_ORG_TYPE_AND_FUNC2(ccciMsg); // bit [31:26]
 
	 // offset = SPCIO_CCCI_MSG_ORG_PARAM2_OFFSET(ccciMsg); // bit[25:13]
	 // length = SPCIO_CCCI_MSG_ORG_PARAM2_LENGTH(ccciMsg); // bit [12:0]
	 
	 switch (func) {
		 case MSG_DATA_NOTIFY_PNW_ULREAD_ACK:
		 {
			 spc_pcmNWay_sendUlDataDone(); // read done!
	 
		 }
			 break;
		 case MSG_DATA_NOTIFY_REC_READ_ACK: 		 
		 {
			 spc_record_sendMicDataDone();
		 }
			 break;
		 default:
			 // leave log
			ASSERT(0);
	 }
 }

 /**
	 CCCI 0x70 begin
 */
 void spc_Misc_Control(kal_uint32 ccciMsg, kal_uint32 ccciMsgRev)
 {
	kal_uint16 func;
 	kal_uint16 offset; 
	kal_uint16 length;
	
	// funcType = (ccciMsg<<4)>>30;
	func = SPCIO_CCCI_MSG_ORG_TYPE_AND_FUNC2(ccciMsg); // bit [31:26]

	offset = SPCIO_CCCI_MSG_ORG_PARAM2_OFFSET(ccciMsg); // bit [25:13]
	length = SPCIO_CCCI_MSG_ORG_PARAM2_LENGTH(ccciMsg); // bit [12:0]
	
 	switch (func) {
		case MSG_MISC_EM_INCALL:
		
		{			
			spc_ReceiveEMParameter_common( offset, length );

			// send ack
// 			SpcIO_SendMsgToAp((ccciMsg & 0xFC001FFF)| 0x80000000 );
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_EM_INCALL_ACK, 0, 0 );


		} 
		break;
		case MSG_MISC_EM_DMNR:
		{

//			SpcIO_SendMsgToAp((ccciMsg & 0xFC001FFF)| 0x80000000, 0 );

			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_EM_DMNR_ACK, 0, 0 );

		}
		break;
		case MSG_MISC_EM_WB:
		{
			spc_ReceiveEMParameter_wb(offset,length);

//			SpcIO_SendMsgToAp((ccciMsg & 0xFC001FFF)| 0x80000000 );
			SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_EM_WB_ACK, 0, 0 );

		}
		break;
		case 0:
		{
			// unused message. you can seperate bit [24:25] into 4 CCCI mesage
		}
			break;
		default:
			ASSERT(0);
 	}
 }


void spc_AP_Command_Handler(kal_uint32 ccciMsg, kal_uint32 ccciMsgRev)
{
	if( SPCIO_CCCI_MSG_IS_EXTEND_A2M(ccciMsg) ) {
		spc_A2M_MsgHandler(ccciMsg, ccciMsgRev);		
	} 	
	else { // original version's handler 
	
		kal_uint32 msgType;
	
		/* Convert CCCI message to SPC message */
		// bit31 ~ bit28: message type
		// bit27 ~ bit24: function type
		// bit23 ~ bit12: offset (buffer)
		// bit11 ~ bit0 : length (buffer)
		// bit15 ~ bit0 : paramter

		msgType = SPCIO_CCCI_MSG_ORG_TYPE(ccciMsg);
		
		switch (msgType) {
			case MSG_TYPE_VOLUME_CTRL: //0:
				// spc_Volume_Control(ccciMsg);
				break;
			case MSG_TYPE_SET_DEVICE: //1:
				// spc_Set_Device(ccciMsg);
				break;		
			case MSG_TYPE_SPEECH_CTRL: //2:
				spc_Speech_Control(ccciMsg);
				break;

			case MSG_TYPE_DATA_TRANSFER_CTRL: //3:
				spc_Data_Transfer_Control(ccciMsg);
				break;						 

			case MSG_TYPE_OTHER_API_HANDLER: //4:
				spcIo_Other_Api_Handler(ccciMsg);

				break;

			case MSG_TYPE_NOTIFICATION: //5:
				spc_Data_Notify(ccciMsg, ccciMsgRev);
				break;

			case MSG_TYPE_ACK_FROM_AP: //6:
				spc_AckFromAP(ccciMsg, ccciMsgRev);
				break;

			case MSG_TYPE_MISC_CTRL: //7: //EM Setting
				spc_Misc_Control(ccciMsg, ccciMsgRev);
				break;

			default:
				kal_trace(TRACE_INFO, SPC_INVALID_MSG, ccciMsg);
		}	
		kal_trace(TRACE_INFO, SPC_M2A_DONE, ccciMsg);
	}
}

#endif //#ifdef SPC_MSG_ORG_VER	

// ----------------------------------------------------------------------------
// Init Related
// ----------------------------------------------------------------------------

// extern unsigned short L1D_Audio_ChkDspInitDone();

void Spc_Init(void)
{	
	/*
	while( 0 == L1D_Audio_ChkDspInitDone()){
		kal_sleep_task(1);
	}
	*/
	
	// all data inside gSpc are 0 when boot up 
	gSpc.spcGetEpofTimes = 0;
	// ====== Initial needed by other application =======
	//background sound
	gSpc_bgSnd.ulGainLevel = 5;
	gSpc_bgSnd.dlGainLevel = 5;

	SIDETONE_Init();
}

#if defined(MT6580)
#include "init.h"
#endif //#if defined(MT6580)
#include "drv_sap.h"
#include "audio_msgid.h"

void Spc_ForceEndAllApp(void) // AP send ETOF to MD L4C. L4C will send ILM to MED and invoke this function
{
	(gSpc.spcGetEpofTimes)++;
	
	kal_trace(TRACE_INFO, SPC_EPOF_NOTIFY, gSpc.spcAppUsage);

#if defined(MT6580)
	{

		// [Rainier] sends AP EPOF_NOTIFY  then closes all applications
		SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC_EPOF_NOTIFY, (kal_uint16)0, 0);
		kal_prompt_trace(MOD_L1SP, "[SPC] [EPOF]Spc_ForceEndAllApp notify AP");
        
        // internal tone stop
        TONE_Stop();
        KT_Stop();
        
        if(IS_SPC_APP_USED(SPC_APP_PCMNWAY_USAGE)) {
            spc_PcmNWayStop();
        }

        if(IS_SPC_APP_USED(SPC_APP_RECORD_USAGE)) {
            spc_RecordStop();
        }
        
        if(IS_SPC_APP_USED(SPC_APP_BGSND_USAGE)) {
		
            spc_BgSndStop();  
            spc_BgSndClose();  

        }

        #ifdef __CTM_SUPPORT__	
        if(IS_SPC_APP_USED(SPC_APP_CTM_USAGE)) {
            spc_CtmStop();
        }
        #endif

        if(IS_SPC_APP_USED(SPC_APP_PCM_REC_USAGE)) {
            spc_PcmRecordStop();
        }
        
        if(IS_SPC_APP_USED(SPC_APP_VM_REC_USAGE)) {
            spc_VmRecordStop();
        }

        if(IS_SPC_APP_USED(SPC_APP_RAW_PCM_REC_USAGE)) {
            spc_RawPcmRecordStop();
        }
        
        kal_prompt_trace(MOD_L1SP, "[Spc_ForceEndAllApp] am.state = %d", AM_GetAmState());
        // main app 
        if(IS_SPC_APP_USED(SPC_APP_SPEECH_USAGE)) {
            Spc_SpeechOff();
        }

	
	}
#else //#if defined(MT6580)
        // other ICs do nothing and send L4C an ack
        msg_send6(MOD_MED, MOD_L4C, AUDIO_SAP, MSG_ID_AUDIO_L4C_EPOF_ACK, (local_para_struct *)NULL, NULL);
        kal_prompt_trace(MOD_L1SP, "SPC [EPOF]Spc_ForceEndAllApp notify L4C done");
#endif //#if defined(MT6580)
	
}

kal_uint16 get_spcGetEpofTimes(void)
{
	return(gSpc.spcGetEpofTimes);
}
