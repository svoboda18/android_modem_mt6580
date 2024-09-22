#ifndef L1TRC_UL1D_THIRD_DEF_H
#define L1TRC_UL1D_THIRD_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_MBD_CS12(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_FREE_RUN_SCHDL(v1)  (unsigned char)(v1+2)
#define UL1D_TRC_STR_MEAS_SCHDL_STATE(v1)  (unsigned char)(v1+4)
#define UL1D_TRC_STR_CELL_STATE(v1)  (unsigned char)(v1+10)
#define UL1D_TRC_STR_ADV_RTD(v1)  (unsigned char)(v1+15)
#define UL1D_TRC_STR_RX_TX_TIME_DIFF_SOURCE(v1)  (unsigned char)(v1+17)
#define UL1D_TRC_STR_WGG_ACTIVE_3G_CHANNEL(v1)  (unsigned char)(v1+19)
#define UL1D_TRC_STR_WGG_MEAS_RTB_REQ_STATE(v1)  (unsigned char)(v1+26)
#define UL1D_TRC_STR_DD_MODE(v1)  (unsigned char)(v1+30)
#define UL1D_TRC_STR_DD_SRC_MODE(v1)  (unsigned char)(v1+35)
#define UL1D_TRC_STR_WGG_MEAS_EVENT(v1)  (unsigned char)(v1+38)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_SCHDL_STATE_REQ(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0012, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_SCHDL_STATE_REQ(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_SCHDL_STATE_REQ_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0012, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_SCHDL_SCHEDULING(v1, v2, v3, v4, v5) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0112, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_SCHDL_SCHEDULING(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_MEAS_SCHDL_SCHEDULING_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0112, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_MPS_START(v1, v2, v3, v4, v5) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0212, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MPS_START(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_MEAS_MPS_START_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0212, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_MEAS_START(v1, v2, v3, v4, v5) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0312, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_START(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_MEAS_MEAS_START_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0312, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_MEAS_CELL_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0412, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_CELL_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_MEAS_MEAS_CELL_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0412, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_RPT_CELL_INFO(v1, v2, v3, v4) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0512, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_RPT_CELL_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MEAS_RPT_CELL_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0512, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_MEAS_FINISH(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0612, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_FINISH(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_MEAS_FINISH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0612, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_CS3_START(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0712, (char)(v1), (char)(v2)), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_CS3_START(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_CS3_START_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0712, (char)(v1), (char)(v2)), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_CM_AVAIL_TIME(v1) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0812, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_CM_AVAIL_TIME(v1)
#endif
#define UL1D_TRC_MEAS_CM_AVAIL_TIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0812, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_CAL_RSCP(v1, v2, v3, v4, v5) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0912, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_CAL_RSCP(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_MEAS_CAL_RSCP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0912, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_REQUEST_BITS(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0A12, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_REQUEST_BITS(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MEAS_REQUEST_BITS_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0A12, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_CS_IRQ_INT(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B12, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_CS_IRQ_INT(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_CS_IRQ_INT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B12, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_MPS_CALLBACK(v1) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C12, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MPS_CALLBACK(v1)
#endif
#define UL1D_TRC_MEAS_MPS_CALLBACK_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C12, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_RF_CONTROL(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D12, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_RF_CONTROL(v1, v2)
#endif
#define UL1D_TRC_MEAS_RF_CONTROL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D12, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_RF_CENTRAL_CONTROL_REG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E12, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_RF_CENTRAL_CONTROL_REG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MEAS_RF_CENTRAL_CONTROL_REG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E12, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_DRX_MASK(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0F12, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_DRX_MASK(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_DRX_MASK_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0F12, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_SCHDL_MASK(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1012, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_SCHDL_MASK(v1, v2)
#endif
#define UL1D_TRC_MEAS_SCHDL_MASK_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1012, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_SET_CALLBACK(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1112, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_SET_CALLBACK(v1, v2)
#endif
#define UL1D_TRC_MEAS_SET_CALLBACK_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1112, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_MEAS_TID_START_LOCATION(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1212, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_TID_START_LOCATION(v1, v2)
#endif
#define UL1D_TRC_MEAS_MEAS_TID_START_LOCATION_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1212, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_RSSI_ERROR(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1312, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_RSSI_ERROR(v1, v2)
#endif
#define UL1D_TRC_MEAS_RSSI_ERROR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1312, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CAL_AVAIL_TIME(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1412, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v5), (unsigned char)(v7)));\
	} while(0)
#else
	#define UL1D_TRC_CAL_AVAIL_TIME(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_CAL_AVAIL_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1412, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v5), (unsigned char)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_GAP_MASK(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1512, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v6)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_GAP_MASK(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MEAS_GAP_MASK_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1512, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v6)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CELL_STATE_CHANGE(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1612, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CELL_STATE_CHANGE(v1, v2)
#endif
#define UL1D_TRC_CELL_STATE_CHANGE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1612, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_RXD_STATUS(v1) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1712, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_RXD_STATUS(v1)
#endif
#define UL1D_TRC_MEAS_RXD_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1712, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_RXD_DETECT_DBG(v1, v2, v3, v4, v5) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1812, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_RXD_DETECT_DBG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_MEAS_RXD_DETECT_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1812, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_RXD_DETECTION_CHECK(v1, v2, v3, v4) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1912, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_RXD_DETECTION_CHECK(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MEAS_RXD_DETECTION_CHECK_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1912, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_RXD_DETECTION_FINAL_RESULT(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A12, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_RXD_DETECTION_FINAL_RESULT(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_RXD_DETECTION_FINAL_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A12, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DD_STOP_PARAM(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B12, (unsigned short)(v2)), (long)(v1), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DD_STOP_PARAM(v1, v2, v3)
#endif
#define UL1D_TRC_DD_STOP_PARAM_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B12, (unsigned short)(v2)), (long)(v1), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DD_PARAM(v1, v2, v3, v4) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C12, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DD_PARAM(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DD_PARAM_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C12, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_IDLE_RFM_FRAMES(v1) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1D12, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_IDLE_RFM_FRAMES(v1)
#endif
#define UL1D_TRC_IDLE_RFM_FRAMES_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1D12, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_IDLE_FREE_RUN_SCHDL(v1, v2, v3, v4, v5) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1E12, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_IDLE_FREE_RUN_SCHDL(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_IDLE_FREE_RUN_SCHDL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1E12, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_IDLE_FREE_RUNNING(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F12, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_IDLE_FREE_RUNNING(v1, v2)
#endif
#define UL1D_TRC_IDLE_FREE_RUNNING_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F12, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DD_RSSI(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2012, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DD_RSSI(v1, v2)
#endif
#define UL1D_TRC_DD_RSSI_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2012, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FA_CELL_CORRECT(v1, v2, v3, v4) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2112, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_FA_CELL_CORRECT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FA_CELL_CORRECT_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2112, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MS3_STATUS(v1) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2212, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MS3_STATUS(v1)
#endif
#define UL1D_TRC_MS3_STATUS_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2212, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PROHIBIT_INTER_MEAS(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2312, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PROHIBIT_INTER_MEAS(v1, v2, v3)
#endif
#define UL1D_TRC_PROHIBIT_INTER_MEAS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2312, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_START(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2412, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_START(v1, v2)
#endif
#define UL1D_TRC_MEAS_START_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2412, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_HW_IN_USE(v1) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2512, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_CS_HW_IN_USE(v1)
#endif
#define UL1D_TRC_CS_HW_IN_USE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2512, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_CHECK_CS_TIME(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2612, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_CHECK_CS_TIME(v1, v2)
#endif
#define UL1D_TRC_MEAS_CHECK_CS_TIME_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2612, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_IDLE_FLAG(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2712, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_IDLE_FLAG(v1, v2)
#endif
#define UL1D_TRC_MEAS_IDLE_FLAG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2712, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CELL_STATE_DBG1(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2812, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_CELL_STATE_DBG1(v1, v2)
#endif
#define UL1D_TRC_CELL_STATE_DBG1_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2812, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_REPORT_FROM_SIB_RFM(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2912, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_REPORT_FROM_SIB_RFM(v1, v2)
#endif
#define UL1D_TRC_MEAS_REPORT_FROM_SIB_RFM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2912, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_MEAS_RESULT1(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A12, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_RESULT1(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_MEAS_RESULT1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A12, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_MEAS_RESULT2(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B12, (short)(v2)), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_RESULT2(v1, v2)
#endif
#define UL1D_TRC_MEAS_MEAS_RESULT2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B12, (short)(v2)), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_MEAS_MPS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2C12, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)), TRC_MERGE_4C((unsigned char)(v10), (unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_MPS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define UL1D_TRC_MEAS_MEAS_MPS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2C12, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)), TRC_MERGE_4C((unsigned char)(v10), (unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TX_TIMING_OFFSET(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D12, (short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TX_TIMING_OFFSET(v1, v2, v3)
#endif
#define UL1D_TRC_TX_TIMING_OFFSET_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D12, (short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TIMING_TRACKING(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2E12, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_TIMING_TRACKING(v1, v2, v3)
#endif
#define UL1D_TRC_TIMING_TRACKING_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2E12, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DD_RSSIDBRG(v1, v2, v3, v4) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F12, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_DD_RSSIDBRG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DD_RSSIDBRG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F12, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MBD_PATH_PWR_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3012, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MBD_PATH_PWR_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MBD_PATH_PWR_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3012, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MBD_PATH_POS_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3112, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MBD_PATH_POS_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MBD_PATH_POS_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3112, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_WIN_TRK_TAIL_HEAD(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3212, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WIN_TRK_TAIL_HEAD(v1, v2, v3)
#endif
#define UL1D_TRC_WIN_TRK_TAIL_HEAD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3212, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_WIN_TRK_PAC_ADDR(v1, v2, v3, v4) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3312, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v4)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WIN_TRK_PAC_ADDR(v1, v2, v3, v4)
#endif
#define UL1D_TRC_WIN_TRK_PAC_ADDR_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3312, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v4)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_WIN_TRK_ADV_RTD(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3412, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WIN_TRK_ADV_RTD(v1, v2, v3)
#endif
#define UL1D_TRC_WIN_TRK_ADV_RTD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3412, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_UL_TFC_STATUS(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3512, (short)(v2)), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_UL_TFC_STATUS(v1, v2)
#endif
#define UL1D_TRC_UL_TFC_STATUS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3512, (short)(v2)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_UL_TFC_BETA(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3612, (short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8)));\
	} while(0)
#else
	#define UL1D_TRC_UL_TFC_BETA(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_UL_TFC_BETA_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3612, (short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_UL_TFC_FRAME(v1, v2, v3, v4, v5) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3712, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_UL_TFC_FRAME(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_UL_TFC_FRAME_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3712, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_WGG_MEAS_EVENT(v1) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3812, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WGG_MEAS_EVENT(v1)
#endif
#define UL1D_TRC_WGG_MEAS_EVENT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3812, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_WGG_MEAS_RTB_REQ_STATE(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3912, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_WGG_MEAS_RTB_REQ_STATE(v1, v2)
#endif
#define UL1D_TRC_WGG_MEAS_RTB_REQ_STATE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3912, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_WGG_MEAS_GAP_END(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A12, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_WGG_MEAS_GAP_END(v1, v2, v3)
#endif
#define UL1D_TRC_WGG_MEAS_GAP_END_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A12, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_WGG_3G_CHANNEL_ACTIVE(v1, v2) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B12, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WGG_3G_CHANNEL_ACTIVE(v1, v2)
#endif
#define UL1D_TRC_WGG_3G_CHANNEL_ACTIVE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B12, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_WGG_3G_Channel_Done(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C12, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WGG_3G_Channel_Done(v1, v2, v3)
#endif
#define UL1D_TRC_WGG_3G_Channel_Done_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C12, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_SFN_CELL_INVALID_CM_DATABASE(v1, v2, v3) do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D12, (short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_SFN_CELL_INVALID_CM_DATABASE(v1, v2, v3)
#endif
#define UL1D_TRC_SFN_CELL_INVALID_CM_DATABASE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D12, (short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_SFN_UPDATE_CM_DATABASE() do {\
		if(UL1D_THIRD_Trace_Filter[0]==1 && (UL1D_THIRD_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E12, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SFN_UPDATE_CM_DATABASE()
#endif
#define UL1D_TRC_SFN_UPDATE_CM_DATABASE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E12, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_THIRD_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_MEAS_SCHDL_STATE_REQ(short v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_MEAS_SCHDL_SCHEDULING(short v1, char v2, char v3, unsigned short v4, char v5);
void L1TRC_Send_UL1D_TRC_MEAS_MPS_START(char v1, char v2, char v3, unsigned char v4, char v5);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_START(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_CELL_INFO(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_MEAS_RPT_CELL_INFO(short v1, long v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_FINISH(char v1, char v2, char v3);
void L1TRC_Send_UL1D_TRC_MEAS_CS3_START(char v1, char v2, long v3);
void L1TRC_Send_UL1D_TRC_MEAS_CM_AVAIL_TIME(long v1);
void L1TRC_Send_UL1D_TRC_MEAS_CAL_RSCP(short v1, short v2, unsigned short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_MEAS_REQUEST_BITS(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_MEAS_CS_IRQ_INT(unsigned short v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_MEAS_MPS_CALLBACK(char v1);
void L1TRC_Send_UL1D_TRC_MEAS_RF_CONTROL(unsigned long v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_MEAS_RF_CENTRAL_CONTROL_REG(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_MEAS_DRX_MASK(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_MEAS_SCHDL_MASK(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_MEAS_SET_CALLBACK(char v1, char v2);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_TID_START_LOCATION(char v1, char v2);
void L1TRC_Send_UL1D_TRC_MEAS_RSSI_ERROR(short v1, short v2);
void L1TRC_Send_UL1D_TRC_CAL_AVAIL_TIME(char v1, unsigned short v2, char v3, unsigned short v4, char v5, unsigned short v6, unsigned char v7);
void L1TRC_Send_UL1D_TRC_MEAS_GAP_MASK(short v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5, short v6);
void L1TRC_Send_UL1D_TRC_CELL_STATE_CHANGE(short v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_MEAS_RXD_STATUS(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MEAS_RXD_DETECT_DBG(unsigned char v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_UL1D_TRC_MEAS_RXD_DETECTION_CHECK(unsigned char v1, short v2, short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_MEAS_RXD_DETECTION_FINAL_RESULT(short v1, short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_DD_STOP_PARAM(long v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_DD_PARAM(char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_IDLE_RFM_FRAMES(short v1);
void L1TRC_Send_UL1D_TRC_IDLE_FREE_RUN_SCHDL(unsigned char v1, short v2, unsigned char v3, char v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_IDLE_FREE_RUNNING(char v1, char v2);
void L1TRC_Send_UL1D_TRC_DD_RSSI(char v1, short v2);
void L1TRC_Send_UL1D_TRC_FA_CELL_CORRECT(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_MS3_STATUS(unsigned long v1);
void L1TRC_Send_UL1D_TRC_PROHIBIT_INTER_MEAS(char v1, char v2, char v3);
void L1TRC_Send_UL1D_TRC_MEAS_START(char v1, char v2);
void L1TRC_Send_UL1D_TRC_CS_HW_IN_USE(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MEAS_CHECK_CS_TIME(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_MEAS_IDLE_FLAG(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_CELL_STATE_DBG1(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_MEAS_REPORT_FROM_SIB_RFM(short v1, short v2);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_RESULT1(char v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_RESULT2(long v1, short v2);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_MPS(char v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12);
void L1TRC_Send_UL1D_TRC_TX_TIMING_OFFSET(char v1, short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_TIMING_TRACKING(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_DD_RSSIDBRG(short v1, unsigned char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_MBD_PATH_PWR_DBG(unsigned char v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_UL1D_TRC_MBD_PATH_POS_DBG(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_UL1D_TRC_WIN_TRK_TAIL_HEAD(char v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_WIN_TRK_PAC_ADDR(unsigned short v1, unsigned short v2, char v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_WIN_TRK_ADV_RTD(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1D_TRC_UL_TFC_STATUS(unsigned long v1, short v2);
void L1TRC_Send_UL1D_TRC_UL_TFC_BETA(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, short v9);
void L1TRC_Send_UL1D_TRC_UL_TFC_FRAME(unsigned char v1, unsigned char v2, short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_WGG_MEAS_EVENT(unsigned char v1);
void L1TRC_Send_UL1D_TRC_WGG_MEAS_RTB_REQ_STATE(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_WGG_MEAS_GAP_END(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_WGG_3G_CHANNEL_ACTIVE(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_WGG_3G_Channel_Done(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_SFN_CELL_INVALID_CM_DATABASE(short v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_SFN_UPDATE_CM_DATABASE(void);

void Set_UL1D_THIRD_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_THIRD()	(UL1D_THIRD_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_THIRD_MEAS_L()	(ChkL1ModFltr_UL1D_THIRD()&&((UL1D_THIRD_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_THIRD_MEAS_M()	(ChkL1ModFltr_UL1D_THIRD()&&((UL1D_THIRD_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_THIRD_MEAS_H()	(ChkL1ModFltr_UL1D_THIRD()&&((UL1D_THIRD_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_THIRD_WIN_TRK_L()	(ChkL1ModFltr_UL1D_THIRD()&&((UL1D_THIRD_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_THIRD_WIN_TRK_M()	(ChkL1ModFltr_UL1D_THIRD()&&((UL1D_THIRD_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_THIRD_UL_TFC_STATE_L()	(ChkL1ModFltr_UL1D_THIRD()&&((UL1D_THIRD_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_THIRD_GEMINI_WGG_M()	(ChkL1ModFltr_UL1D_THIRD()&&((UL1D_THIRD_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_THIRD_GEMINI_WGG_H()	(ChkL1ModFltr_UL1D_THIRD()&&((UL1D_THIRD_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_THIRD_SFN_TM_M()	(ChkL1ModFltr_UL1D_THIRD()&&((UL1D_THIRD_Trace_Filter[2]&0x01)!=0))
#define ChkL1MsgFltr_UL1D_TRC_MEAS_SCHDL_STATE_REQ()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_SCHDL_SCHEDULING()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MPS_START()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_START()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_CELL_INFO()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_RPT_CELL_INFO()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_FINISH()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_CS3_START()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_CM_AVAIL_TIME()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_CAL_RSCP()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_REQUEST_BITS()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_CS_IRQ_INT()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MPS_CALLBACK()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_RF_CONTROL()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_RF_CENTRAL_CONTROL_REG()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_DRX_MASK()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_SCHDL_MASK()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_SET_CALLBACK()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_TID_START_LOCATION()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_RSSI_ERROR()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_CAL_AVAIL_TIME()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_GAP_MASK()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_CELL_STATE_CHANGE()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_RXD_STATUS()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_RXD_DETECT_DBG()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_RXD_DETECTION_CHECK()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_RXD_DETECTION_FINAL_RESULT()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_DD_STOP_PARAM()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_DD_PARAM()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_IDLE_RFM_FRAMES()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_IDLE_FREE_RUN_SCHDL()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_IDLE_FREE_RUNNING()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_DD_RSSI()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_FA_CELL_CORRECT()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MS3_STATUS()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_PROHIBIT_INTER_MEAS()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_START()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_HW_IN_USE()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_CHECK_CS_TIME()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_IDLE_FLAG()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_CELL_STATE_DBG1()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_REPORT_FROM_SIB_RFM()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_RESULT1()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_RESULT2()	ChkL1ClsFltr_UL1D_THIRD_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_MPS()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_TX_TIMING_OFFSET()	ChkL1ClsFltr_UL1D_THIRD_MEAS_M()
#define ChkL1MsgFltr_UL1D_TRC_TIMING_TRACKING()	ChkL1ClsFltr_UL1D_THIRD_MEAS_L()
#define ChkL1MsgFltr_UL1D_TRC_DD_RSSIDBRG()	ChkL1ClsFltr_UL1D_THIRD_MEAS_L()
#define ChkL1MsgFltr_UL1D_TRC_MBD_PATH_PWR_DBG()	ChkL1ClsFltr_UL1D_THIRD_MEAS_L()
#define ChkL1MsgFltr_UL1D_TRC_MBD_PATH_POS_DBG()	ChkL1ClsFltr_UL1D_THIRD_MEAS_L()
#define ChkL1MsgFltr_UL1D_TRC_WIN_TRK_TAIL_HEAD()	ChkL1ClsFltr_UL1D_THIRD_WIN_TRK_L()
#define ChkL1MsgFltr_UL1D_TRC_WIN_TRK_PAC_ADDR()	ChkL1ClsFltr_UL1D_THIRD_WIN_TRK_M()
#define ChkL1MsgFltr_UL1D_TRC_WIN_TRK_ADV_RTD()	ChkL1ClsFltr_UL1D_THIRD_WIN_TRK_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_TFC_STATUS()	ChkL1ClsFltr_UL1D_THIRD_UL_TFC_STATE_L()
#define ChkL1MsgFltr_UL1D_TRC_UL_TFC_BETA()	ChkL1ClsFltr_UL1D_THIRD_UL_TFC_STATE_L()
#define ChkL1MsgFltr_UL1D_TRC_UL_TFC_FRAME()	ChkL1ClsFltr_UL1D_THIRD_UL_TFC_STATE_L()
#define ChkL1MsgFltr_UL1D_TRC_WGG_MEAS_EVENT()	ChkL1ClsFltr_UL1D_THIRD_GEMINI_WGG_H()
#define ChkL1MsgFltr_UL1D_TRC_WGG_MEAS_RTB_REQ_STATE()	ChkL1ClsFltr_UL1D_THIRD_GEMINI_WGG_H()
#define ChkL1MsgFltr_UL1D_TRC_WGG_MEAS_GAP_END()	ChkL1ClsFltr_UL1D_THIRD_GEMINI_WGG_H()
#define ChkL1MsgFltr_UL1D_TRC_WGG_3G_CHANNEL_ACTIVE()	ChkL1ClsFltr_UL1D_THIRD_GEMINI_WGG_H()
#define ChkL1MsgFltr_UL1D_TRC_WGG_3G_Channel_Done()	ChkL1ClsFltr_UL1D_THIRD_GEMINI_WGG_H()
#define ChkL1MsgFltr_UL1D_TRC_SFN_CELL_INVALID_CM_DATABASE()	ChkL1ClsFltr_UL1D_THIRD_SFN_TM_M()
#define ChkL1MsgFltr_UL1D_TRC_SFN_UPDATE_CM_DATABASE()	ChkL1ClsFltr_UL1D_THIRD_SFN_TM_M()


#endif
