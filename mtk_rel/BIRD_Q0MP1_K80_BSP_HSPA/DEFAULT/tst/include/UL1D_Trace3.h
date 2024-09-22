#ifndef L1TRC_UL1D_FOURTH_DEF_H
#define L1TRC_UL1D_FOURTH_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_RFM_STATE(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_FINGER_STATUS(v1)  (unsigned char)(v1+2)
#define UL1D_TRC_STR_RFM_THR_MODE(v1)  (unsigned char)(v1+6)
#define UL1D_TRC_STR_PS_EVENT(v1)  (unsigned char)(v1+10)
#define UL1D_TRC_STR_CS_SM(v1)  (unsigned char)(v1+19)
#define UL1D_TRC_STE_CS_STATE(v1)  (unsigned char)(v1+22)
#define UL1D_TRC_STR_TXRF_CH(v1)  (unsigned char)(v1+32)
#define UL1D_TRC_STR_CS_READY_FLAG(v1)  (unsigned char)(v1+35)
#define UL1D_TRC_STR_SRCHR_INTERFACE(v1)  (unsigned char)(v1+42)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1D_TRC_RFM_ADD_RL(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0013, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_RFM_ADD_RL(v1)
#endif
#define UL1D_TRC_RFM_ADD_RL_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0013, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RFM_DELETE_RL(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0113, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_RFM_DELETE_RL(v1)
#endif
#define UL1D_TRC_RFM_DELETE_RL_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0113, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FINGER_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0213, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FINGER_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_FINGER_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0213, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FINGER_INFO1(v1, v2, v3, v4) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0313, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FINGER_INFO1(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FINGER_INFO1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0313, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FINGER_ASSIGN(v1, v2, v3, v4) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0413, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FINGER_ASSIGN(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FINGER_ASSIGN_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0413, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MPS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0513, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_1S2C((unsigned short)(v12), (char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_MPS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define UL1D_TRC_MPS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0513, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_1S2C((unsigned short)(v12), (char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_STATE(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0613, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_STATE(v1, v2)
#endif
#define UL1D_TRC_RFM_STATE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0613, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_THR_MODE(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0713, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_THR_MODE(v1)
#endif
#define UL1D_TRC_RFM_THR_MODE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0713, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_REFERENCE_CELL_ID(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0813, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_REFERENCE_CELL_ID(v1)
#endif
#define UL1D_TRC_REFERENCE_CELL_ID_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0813, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RFM_REFERENCE_PAC_ADDR(v1, v2, v3) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0913, (unsigned short)(v1)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_RFM_REFERENCE_PAC_ADDR(v1, v2, v3)
#endif
#define UL1D_TRC_RFM_REFERENCE_PAC_ADDR_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0913, (unsigned short)(v1)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RFM_MAX_DELAY_PATH(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A13, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_MAX_DELAY_PATH(v1, v2)
#endif
#define UL1D_TRC_RFM_MAX_DELAY_PATH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A13, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RFM_ACTIVE_FRAMES(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B13, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_ACTIVE_FRAMES(v1, v2)
#endif
#define UL1D_TRC_RFM_ACTIVE_FRAMES_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B13, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RFM_RL_FRAMES(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C13, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_RL_FRAMES(v1, v2)
#endif
#define UL1D_TRC_RFM_RL_FRAMES_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C13, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RFM_ROUNDROBIN_LIST(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D13, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_ROUNDROBIN_LIST(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_RFM_ROUNDROBIN_LIST_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D13, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RFM_ROUND_ROBIN_CHANGE(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E13, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_ROUND_ROBIN_CHANGE(v1, v2)
#endif
#define UL1D_TRC_RFM_ROUND_ROBIN_CHANGE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E13, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RFM_All_RL_FRAMES(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0F13, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_All_RL_FRAMES(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_RFM_All_RL_FRAMES_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0F13, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RFM_SCHEDULE_FRAME_CNT(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1013, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_SCHEDULE_FRAME_CNT(v1, v2)
#endif
#define UL1D_TRC_RFM_SCHEDULE_FRAME_CNT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1013, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RFM_START_FOR_RL(v1, v2, v3) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1113, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_START_FOR_RL(v1, v2, v3)
#endif
#define UL1D_TRC_RFM_START_FOR_RL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1113, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RFM_STOP_FOR_RL(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1213, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_STOP_FOR_RL(v1, v2)
#endif
#define UL1D_TRC_RFM_STOP_FOR_RL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1213, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PS_EVENT(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1313, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PS_EVENT(v1)
#endif
#define UL1D_TRC_PS_EVENT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1313, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PS_DONE(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1413, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_PS_DONE(v1)
#endif
#define UL1D_TRC_PS_DONE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1413, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PS_MIX_FB_PREFER(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1513, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PS_MIX_FB_PREFER(v1, v2)
#endif
#define UL1D_TRC_PS_MIX_FB_PREFER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1513, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PS_SORTED_LIST(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1613, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PS_SORTED_LIST(v1, v2)
#endif
#define UL1D_TRC_PS_SORTED_LIST_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1613, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PS_RSSI(v1, v2, v3, v4) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1713, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_PS_RSSI(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PS_RSSI_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1713, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PS_TRIGGER(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1813, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_PS_TRIGGER(v1)
#endif
#define UL1D_TRC_PS_TRIGGER_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1813, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PS_RANGE(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1913, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PS_RANGE(v1)
#endif
#define UL1D_TRC_PS_RANGE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1913, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PS_LIST(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A13, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PS_LIST(v1)
#endif
#define UL1D_TRC_PS_LIST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A13, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PS_RSSISNIFFER(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B13, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PS_RSSISNIFFER(v1)
#endif
#define UL1D_TRC_PS_RSSISNIFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B13, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PS_RSSISNIFFER_REF(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C13, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PS_RSSISNIFFER_REF(v1, v2)
#endif
#define UL1D_TRC_PS_RSSISNIFFER_REF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C13, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PS_STAGE2_START(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1D13, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_PS_STAGE2_START(v1)
#endif
#define UL1D_TRC_PS_STAGE2_START_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1D13, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PS_ESTIMATE_FINISH(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E13, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PS_ESTIMATE_FINISH(v1)
#endif
#define UL1D_TRC_PS_ESTIMATE_FINISH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E13, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PS_ESTIMATE_START(v1, v2, v3) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F13, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PS_ESTIMATE_START(v1, v2, v3)
#endif
#define UL1D_TRC_PS_ESTIMATE_START_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F13, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PS_SUSPEND(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2013, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PS_SUSPEND(v1)
#endif
#define UL1D_TRC_PS_SUSPEND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2013, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PS_INVALID_RSSI(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2113, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_PS_INVALID_RSSI(v1)
#endif
#define UL1D_TRC_PS_INVALID_RSSI_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2113, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PS_FullBand(v1, v2, v3, v4) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2213, (short)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_PS_FullBand(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PS_FullBand_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2213, (short)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_STATE(v1, v2, v3, v4) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2313, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_STATE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_CS_STATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2313, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_ST_MASK(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2413, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_ST_MASK(v1, v2)
#endif
#define UL1D_TRC_CS_ST_MASK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2413, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ICS_STATE(v1, v2, v3) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2513, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_ICS_STATE(v1, v2, v3)
#endif
#define UL1D_TRC_ICS_STATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2513, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_START_MULTI_FREQ(v1, v2, v3) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2613, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_START_MULTI_FREQ(v1, v2, v3)
#endif
#define UL1D_TRC_CS_START_MULTI_FREQ_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2613, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_START_FREQ(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2713, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_START_FREQ(v1, v2)
#endif
#define UL1D_TRC_CS_START_FREQ_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2713, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_CS4_FREQ_OFFSET(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2813, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_CS_CS4_FREQ_OFFSET(v1)
#endif
#define UL1D_TRC_CS_CS4_FREQ_OFFSET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2813, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_CELL_FOUND1(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2913, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_CELL_FOUND1(v1, v2)
#endif
#define UL1D_TRC_CS_CELL_FOUND1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2913, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_CELL_FOUND2(v1, v2, v3) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A13, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_CS_CELL_FOUND2(v1, v2, v3)
#endif
#define UL1D_TRC_CS_CELL_FOUND2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A13, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_INTERFACE(v1, v2, v3, v4, v5) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B13, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_INTERFACE(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_CS_INTERFACE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B13, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_CFE_BIN_INI(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C13, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_CFE_BIN_INI(v1, v2)
#endif
#define UL1D_TRC_CS_CFE_BIN_INI_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C13, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_CFE_BIN(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D13, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_CFE_BIN(v1, v2)
#endif
#define UL1D_TRC_CS_CFE_BIN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D13, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_AFC_DAC(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E13, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_CS_AFC_DAC(v1)
#endif
#define UL1D_TRC_CS_AFC_DAC_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E13, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_RXON(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2F13, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)));\
	} while(0)
#else
	#define UL1D_TRC_RF_RXON(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_RF_RXON_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2F13, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_RXOFF(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3013, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_RXOFF(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RF_RXOFF_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3013, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_TXON(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3113, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_TXON(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RF_TXON_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3113, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_TXOFF(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3213, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_TXOFF(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RF_TXOFF_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3213, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_PROGEVENT_DONE(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3313, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_PROGEVENT_DONE(v1, v2)
#endif
#define UL1D_TRC_RF_PROGEVENT_DONE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3313, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_RX_RECONFIG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3413, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_RX_RECONFIG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RF_RX_RECONFIG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3413, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RF_extend(v1) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3513, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_RF_extend(v1)
#endif
#define UL1D_TRC_RF_extend_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3513, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_TX_RF_POWER(v1, v2, v3) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3613, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TX_RF_POWER(v1, v2, v3)
#endif
#define UL1D_TRC_TX_RF_POWER_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3613, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TX_DAC(v1, v2, v3, v4) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3713, (short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TX_DAC(v1, v2, v3, v4)
#endif
#define UL1D_TRC_TX_DAC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3713, (short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_DBG(v1, v2, v3, v4, v5) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3813, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), (unsigned char)(v5)), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_RF_DBG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RF_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3813, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), (unsigned char)(v5)), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_IMM_DBG(v1, v2, v3, v4) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3913, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_RF_IMM_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RF_IMM_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3913, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_IMM_OFF_DELAY(v1, v2) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A13, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_IMM_OFF_DELAY(v1, v2)
#endif
#define UL1D_TRC_RF_IMM_OFF_DELAY_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A13, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_RXOFF_CANCEL(v1, v2, v3) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B13, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_RF_RXOFF_CANCEL(v1, v2, v3)
#endif
#define UL1D_TRC_RF_RXOFF_CANCEL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B13, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RF_GAIN_SET(v1, v2, v3) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C13, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_RF_GAIN_SET(v1, v2, v3)
#endif
#define UL1D_TRC_RF_GAIN_SET_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C13, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RF_GAIN_SAVE(v1, v2, v3, v4, v5) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D13, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_RF_GAIN_SAVE(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RF_GAIN_SAVE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D13, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_TXCRP_AWAKE(v1, v2, v3) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3E13, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_TXCRP_AWAKE(v1, v2, v3)
#endif
#define UL1D_TRC_TXCRP_AWAKE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3E13, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_RXDCCAL_ON(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_FOURTH_Trace_Filter[0]==1 && (UL1D_FOURTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3F13, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_RXDCCAL_ON(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RF_RXDCCAL_ON_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3F13, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_FOURTH_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_RFM_ADD_RL(long v1);
void L1TRC_Send_UL1D_TRC_RFM_DELETE_RL(long v1);
void L1TRC_Send_UL1D_TRC_FINGER_INFO(unsigned char v1, char v2, unsigned short v3, char v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_FINGER_INFO1(unsigned char v1, char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_FINGER_ASSIGN(unsigned char v1, char v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_MPS(char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12);
void L1TRC_Send_UL1D_TRC_RFM_STATE(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_RFM_THR_MODE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_REFERENCE_CELL_ID(char v1);
void L1TRC_Send_UL1D_TRC_RFM_REFERENCE_PAC_ADDR(unsigned short v1, unsigned long v2, char v3);
void L1TRC_Send_UL1D_TRC_RFM_MAX_DELAY_PATH(unsigned short v1, short v2);
void L1TRC_Send_UL1D_TRC_RFM_ACTIVE_FRAMES(char v1, char v2);
void L1TRC_Send_UL1D_TRC_RFM_RL_FRAMES(char v1, char v2);
void L1TRC_Send_UL1D_TRC_RFM_ROUNDROBIN_LIST(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8, char v9);
void L1TRC_Send_UL1D_TRC_RFM_ROUND_ROBIN_CHANGE(char v1, char v2);
void L1TRC_Send_UL1D_TRC_RFM_All_RL_FRAMES(char v1, char v2, char v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_UL1D_TRC_RFM_SCHEDULE_FRAME_CNT(char v1, char v2);
void L1TRC_Send_UL1D_TRC_RFM_START_FOR_RL(char v1, char v2, char v3);
void L1TRC_Send_UL1D_TRC_RFM_STOP_FOR_RL(char v1, char v2);
void L1TRC_Send_UL1D_TRC_PS_EVENT(unsigned char v1);
void L1TRC_Send_UL1D_TRC_PS_DONE(short v1);
void L1TRC_Send_UL1D_TRC_PS_MIX_FB_PREFER(unsigned short v1, short v2);
void L1TRC_Send_UL1D_TRC_PS_SORTED_LIST(unsigned short v1, short v2);
void L1TRC_Send_UL1D_TRC_PS_RSSI(unsigned short v1, short v2, short v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_PS_TRIGGER(long v1);
void L1TRC_Send_UL1D_TRC_PS_RANGE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_PS_LIST(unsigned char v1);
void L1TRC_Send_UL1D_TRC_PS_RSSISNIFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_PS_RSSISNIFFER_REF(unsigned short v1, short v2);
void L1TRC_Send_UL1D_TRC_PS_STAGE2_START(unsigned short v1);
void L1TRC_Send_UL1D_TRC_PS_ESTIMATE_FINISH(char v1);
void L1TRC_Send_UL1D_TRC_PS_ESTIMATE_START(short v1, short v2, char v3);
void L1TRC_Send_UL1D_TRC_PS_SUSPEND(unsigned char v1);
void L1TRC_Send_UL1D_TRC_PS_INVALID_RSSI(short v1);
void L1TRC_Send_UL1D_TRC_PS_FullBand(unsigned long v1, short v2, unsigned char v3, char v4);
void L1TRC_Send_UL1D_TRC_CS_STATE(short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_CS_ST_MASK(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_ICS_STATE(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_CS_START_MULTI_FREQ(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1D_TRC_CS_START_FREQ(short v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_CS_CS4_FREQ_OFFSET(short v1);
void L1TRC_Send_UL1D_TRC_CS_CELL_FOUND1(short v1, char v2);
void L1TRC_Send_UL1D_TRC_CS_CELL_FOUND2(short v1, short v2, long v3);
void L1TRC_Send_UL1D_TRC_CS_INTERFACE(unsigned char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_CS_CFE_BIN_INI(short v1, short v2);
void L1TRC_Send_UL1D_TRC_CS_CFE_BIN(short v1, short v2);
void L1TRC_Send_UL1D_TRC_CS_AFC_DAC(short v1);
void L1TRC_Send_UL1D_TRC_RF_RXON(unsigned short v1, short v2, short v3, short v4, short v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_UL1D_TRC_RF_RXOFF(unsigned short v1, short v2, short v3, char v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_UL1D_TRC_RF_TXON(unsigned short v1, short v2, short v3, short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_UL1D_TRC_RF_TXOFF(unsigned short v1, short v2, short v3, short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_UL1D_TRC_RF_PROGEVENT_DONE(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_RF_RX_RECONFIG(short v1, unsigned short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_RF_extend(long v1);
void L1TRC_Send_UL1D_TRC_TX_RF_POWER(char v1, char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_TX_DAC(short v1, char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_RF_DBG(unsigned short v1, unsigned char v2, unsigned short v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_RF_IMM_DBG(unsigned short v1, unsigned char v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_RF_IMM_OFF_DELAY(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_RF_RXOFF_CANCEL(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_RF_GAIN_SET(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_RF_GAIN_SAVE(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_TXCRP_AWAKE(unsigned long v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_RF_RXDCCAL_ON(short v1, unsigned short v2, short v3, unsigned short v4, unsigned short v5, unsigned short v6);

void Set_UL1D_FOURTH_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_FOURTH()	(UL1D_FOURTH_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_FOURTH_RFM_L()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_FOURTH_RFM_M()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_FOURTH_RFM_H()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_FOURTH_PS_M()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_FOURTH_PS_H()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_FOURTH_CS_M()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_FOURTH_CS_H()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_FOURTH_RF_L()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_FOURTH_RF_M()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_FOURTH_RF_H()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_FOURTH_TXCRP_H()	(ChkL1ModFltr_UL1D_FOURTH()&&((UL1D_FOURTH_Trace_Filter[2]&0x04)!=0))
#define ChkL1MsgFltr_UL1D_TRC_RFM_ADD_RL()	ChkL1ClsFltr_UL1D_FOURTH_RFM_H()
#define ChkL1MsgFltr_UL1D_TRC_RFM_DELETE_RL()	ChkL1ClsFltr_UL1D_FOURTH_RFM_H()
#define ChkL1MsgFltr_UL1D_TRC_FINGER_INFO()	ChkL1ClsFltr_UL1D_FOURTH_RFM_H()
#define ChkL1MsgFltr_UL1D_TRC_FINGER_INFO1()	ChkL1ClsFltr_UL1D_FOURTH_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_FINGER_ASSIGN()	ChkL1ClsFltr_UL1D_FOURTH_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_MPS()	ChkL1ClsFltr_UL1D_FOURTH_RFM_H()
#define ChkL1MsgFltr_UL1D_TRC_RFM_STATE()	ChkL1ClsFltr_UL1D_FOURTH_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_THR_MODE()	ChkL1ClsFltr_UL1D_FOURTH_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_REFERENCE_CELL_ID()	ChkL1ClsFltr_UL1D_FOURTH_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_REFERENCE_PAC_ADDR()	ChkL1ClsFltr_UL1D_FOURTH_RFM_L()
#define ChkL1MsgFltr_UL1D_TRC_RFM_MAX_DELAY_PATH()	ChkL1ClsFltr_UL1D_FOURTH_RFM_L()
#define ChkL1MsgFltr_UL1D_TRC_RFM_ACTIVE_FRAMES()	ChkL1ClsFltr_UL1D_FOURTH_RFM_H()
#define ChkL1MsgFltr_UL1D_TRC_RFM_RL_FRAMES()	ChkL1ClsFltr_UL1D_FOURTH_RFM_L()
#define ChkL1MsgFltr_UL1D_TRC_RFM_ROUNDROBIN_LIST()	ChkL1ClsFltr_UL1D_FOURTH_RFM_L()
#define ChkL1MsgFltr_UL1D_TRC_RFM_ROUND_ROBIN_CHANGE()	ChkL1ClsFltr_UL1D_FOURTH_RFM_L()
#define ChkL1MsgFltr_UL1D_TRC_RFM_All_RL_FRAMES()	ChkL1ClsFltr_UL1D_FOURTH_RFM_L()
#define ChkL1MsgFltr_UL1D_TRC_RFM_SCHEDULE_FRAME_CNT()	ChkL1ClsFltr_UL1D_FOURTH_RFM_L()
#define ChkL1MsgFltr_UL1D_TRC_RFM_START_FOR_RL()	ChkL1ClsFltr_UL1D_FOURTH_RFM_L()
#define ChkL1MsgFltr_UL1D_TRC_RFM_STOP_FOR_RL()	ChkL1ClsFltr_UL1D_FOURTH_RFM_L()
#define ChkL1MsgFltr_UL1D_TRC_PS_EVENT()	ChkL1ClsFltr_UL1D_FOURTH_PS_H()
#define ChkL1MsgFltr_UL1D_TRC_PS_DONE()	ChkL1ClsFltr_UL1D_FOURTH_PS_H()
#define ChkL1MsgFltr_UL1D_TRC_PS_MIX_FB_PREFER()	ChkL1ClsFltr_UL1D_FOURTH_PS_M()
#define ChkL1MsgFltr_UL1D_TRC_PS_SORTED_LIST()	ChkL1ClsFltr_UL1D_FOURTH_PS_H()
#define ChkL1MsgFltr_UL1D_TRC_PS_RSSI()	ChkL1ClsFltr_UL1D_FOURTH_PS_H()
#define ChkL1MsgFltr_UL1D_TRC_PS_TRIGGER()	ChkL1ClsFltr_UL1D_FOURTH_PS_M()
#define ChkL1MsgFltr_UL1D_TRC_PS_RANGE()	ChkL1ClsFltr_UL1D_FOURTH_PS_H()
#define ChkL1MsgFltr_UL1D_TRC_PS_LIST()	ChkL1ClsFltr_UL1D_FOURTH_PS_H()
#define ChkL1MsgFltr_UL1D_TRC_PS_RSSISNIFFER()	ChkL1ClsFltr_UL1D_FOURTH_PS_H()
#define ChkL1MsgFltr_UL1D_TRC_PS_RSSISNIFFER_REF()	ChkL1ClsFltr_UL1D_FOURTH_PS_H()
#define ChkL1MsgFltr_UL1D_TRC_PS_STAGE2_START()	ChkL1ClsFltr_UL1D_FOURTH_PS_M()
#define ChkL1MsgFltr_UL1D_TRC_PS_ESTIMATE_FINISH()	ChkL1ClsFltr_UL1D_FOURTH_PS_M()
#define ChkL1MsgFltr_UL1D_TRC_PS_ESTIMATE_START()	ChkL1ClsFltr_UL1D_FOURTH_PS_M()
#define ChkL1MsgFltr_UL1D_TRC_PS_SUSPEND()	ChkL1ClsFltr_UL1D_FOURTH_PS_M()
#define ChkL1MsgFltr_UL1D_TRC_PS_INVALID_RSSI()	ChkL1ClsFltr_UL1D_FOURTH_PS_M()
#define ChkL1MsgFltr_UL1D_TRC_PS_FullBand()	ChkL1ClsFltr_UL1D_FOURTH_PS_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_STATE()	ChkL1ClsFltr_UL1D_FOURTH_CS_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_ST_MASK()	ChkL1ClsFltr_UL1D_FOURTH_CS_H()
#define ChkL1MsgFltr_UL1D_TRC_ICS_STATE()	ChkL1ClsFltr_UL1D_FOURTH_CS_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_START_MULTI_FREQ()	ChkL1ClsFltr_UL1D_FOURTH_CS_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_START_FREQ()	ChkL1ClsFltr_UL1D_FOURTH_CS_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_CS4_FREQ_OFFSET()	ChkL1ClsFltr_UL1D_FOURTH_CS_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_CELL_FOUND1()	ChkL1ClsFltr_UL1D_FOURTH_CS_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_CELL_FOUND2()	ChkL1ClsFltr_UL1D_FOURTH_CS_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_INTERFACE()	ChkL1ClsFltr_UL1D_FOURTH_CS_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_CFE_BIN_INI()	ChkL1ClsFltr_UL1D_FOURTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_CFE_BIN()	ChkL1ClsFltr_UL1D_FOURTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_AFC_DAC()	ChkL1ClsFltr_UL1D_FOURTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_RF_RXON()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_RXOFF()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_TXON()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_TXOFF()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_PROGEVENT_DONE()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_RX_RECONFIG()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_extend()	ChkL1ClsFltr_UL1D_FOURTH_RF_M()
#define ChkL1MsgFltr_UL1D_TRC_TX_RF_POWER()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_TX_DAC()	ChkL1ClsFltr_UL1D_FOURTH_RF_M()
#define ChkL1MsgFltr_UL1D_TRC_RF_DBG()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_IMM_DBG()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_IMM_OFF_DELAY()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_RXOFF_CANCEL()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_GAIN_SET()	ChkL1ClsFltr_UL1D_FOURTH_RF_L()
#define ChkL1MsgFltr_UL1D_TRC_RF_GAIN_SAVE()	ChkL1ClsFltr_UL1D_FOURTH_RF_L()
#define ChkL1MsgFltr_UL1D_TRC_TXCRP_AWAKE()	ChkL1ClsFltr_UL1D_FOURTH_TXCRP_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_RXDCCAL_ON()	ChkL1ClsFltr_UL1D_FOURTH_RF_H()


#endif
