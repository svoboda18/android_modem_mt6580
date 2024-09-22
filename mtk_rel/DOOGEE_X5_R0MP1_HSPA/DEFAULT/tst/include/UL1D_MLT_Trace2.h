#ifndef L1TRC_UL1D_MLT_SET2_DEF_H
#define L1TRC_UL1D_MLT_SET2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_DETECT_METHOD(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_CM_PURPOSE(v1)  (unsigned char)(v1+6)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_PREPROCESSOR_DEFAULT(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x000F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_PREPROCESSOR_DEFAULT(v1)
#endif
#define UL1D_TRC_MLT_PREPROCESSOR_DEFAULT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x000F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_CLTD_DEFAULT(v1, v2, v3, v4) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x010F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MLT_CLTD_DEFAULT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MLT_CLTD_DEFAULT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x010F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_SIREST_DEFAULT(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x020F, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_SIREST_DEFAULT(v1)
#endif
#define UL1D_TRC_MLT_SIREST_DEFAULT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x020F, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MLT_DPC_DEFAULT(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x030F, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_DPC_DEFAULT(v1)
#endif
#define UL1D_TRC_MLT_DPC_DEFAULT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x030F, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_TPC_CMB_DEFAULT(v1, v2, v3, v4, v5) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x040F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MLT_TPC_CMB_DEFAULT(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_MLT_TPC_CMB_DEFAULT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x040F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_AICH_DEFAULT(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x050F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MLT_AICH_DEFAULT(v1)
#endif
#define UL1D_TRC_MLT_AICH_DEFAULT_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x050F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_PICH_DEFAULT(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x060F, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_PICH_DEFAULT(v1)
#endif
#define UL1D_TRC_MLT_PICH_DEFAULT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x060F, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_RXBRP_DEFAULT(v1, v2, v3, v4, v5) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x070F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_DEFAULT(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_MLT_RXBRP_DEFAULT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x070F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_PICH_POWER_OFFSET(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x080F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_PICH_POWER_OFFSET(v1)
#endif
#define UL1D_TRC_MLT_PICH_POWER_OFFSET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x080F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MLT_DQE_TPC_SIR_LTA(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x090F, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_DQE_TPC_SIR_LTA(v1)
#endif
#define UL1D_TRC_MLT_DQE_TPC_SIR_LTA_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x090F, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_DQE_LNK_EST_IND(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A0F, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_DQE_LNK_EST_IND(v1)
#endif
#define UL1D_TRC_MLT_DQE_LNK_EST_IND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A0F, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_DQE_SYNC_STATUS(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B0F, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_DQE_SYNC_STATUS(v1)
#endif
#define UL1D_TRC_MLT_DQE_SYNC_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B0F, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_DPC_TARGET_SIR(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0C0F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_MLT_DPC_TARGET_SIR(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_MLT_DPC_TARGET_SIR_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0C0F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_DPC_TARGET_SIR_2(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0D0F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_MLT_DPC_TARGET_SIR_2(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_MLT_DPC_TARGET_SIR_2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0D0F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_DPC_DPDCH_SIR_LTA(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E0F, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_DPC_DPDCH_SIR_LTA(v1)
#endif
#define UL1D_TRC_MLT_DPC_DPDCH_SIR_LTA_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E0F, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_DPC_TARGET_BLER(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F0F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_DPC_TARGET_BLER(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_MLT_DPC_TARGET_BLER_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F0F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_AGC_M_N_E(v1, v2, v3, v4) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x100F, (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_MLT_AGC_M_N_E(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MLT_AGC_M_N_E_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x100F, (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_PAC_DISTANCE(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x110F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_PAC_DISTANCE(v1)
#endif
#define UL1D_TRC_MLT_PAC_DISTANCE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x110F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_DESPRD_CFG(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x120F, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_DESPRD_CFG(v1)
#endif
#define UL1D_TRC_MLT_DESPRD_CFG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x120F, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_TRK_THRESHOLD_CFG(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x130F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MLT_TRK_THRESHOLD_CFG(v1)
#endif
#define UL1D_TRC_MLT_TRK_THRESHOLD_CFG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x130F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_SPEST_ACC_FRAME(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x140F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_SPEST_ACC_FRAME(v1)
#endif
#define UL1D_TRC_MLT_SPEST_ACC_FRAME_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x140F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_SPEST_LPF1(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x150F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MLT_SPEST_LPF1(v1)
#endif
#define UL1D_TRC_MLT_SPEST_LPF1_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x150F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_SPEST_LPF2(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x160F, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_SPEST_LPF2(v1)
#endif
#define UL1D_TRC_MLT_SPEST_LPF2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x160F, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_SPEST_HPF1(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x170F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MLT_SPEST_HPF1(v1)
#endif
#define UL1D_TRC_MLT_SPEST_HPF1_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x170F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_SPEST_HPF2(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x180F, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_SPEST_HPF2(v1)
#endif
#define UL1D_TRC_MLT_SPEST_HPF2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x180F, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_FOE_THR1(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x190F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MLT_FOE_THR1(v1)
#endif
#define UL1D_TRC_MLT_FOE_THR1_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x190F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_FOE_THR2(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1A0F, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_FOE_THR2(v1)
#endif
#define UL1D_TRC_MLT_FOE_THR2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1A0F, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_FOE_CON(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B0F, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_FOE_CON(v1)
#endif
#define UL1D_TRC_MLT_FOE_CON_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B0F, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_AFC_SWT_HYST(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C0F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_AFC_SWT_HYST(v1)
#endif
#define UL1D_TRC_MLT_AFC_SWT_HYST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C0F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_AFC_SWT_THRE(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D0F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MLT_AFC_SWT_THRE(v1)
#endif
#define UL1D_TRC_MLT_AFC_SWT_THRE_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D0F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_CHEST_CFG(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E0F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MLT_CHEST_CFG(v1)
#endif
#define UL1D_TRC_MLT_CHEST_CFG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E0F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_AFC_INITIAL_FREQ(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1F0F, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_AFC_INITIAL_FREQ(v1)
#endif
#define UL1D_TRC_MLT_AFC_INITIAL_FREQ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1F0F, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_SPEST_RESET(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x200F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_SPEST_RESET(v1)
#endif
#define UL1D_TRC_MLT_SPEST_RESET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x200F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_RTR_RAKECON(v1, v2, v3, v4) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x210F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RTR_RAKECON(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MLT_RTR_RAKECON_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x210F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_TM_ADV_RET_ADJUST(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x220F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_TM_ADV_RET_ADJUST(v1)
#endif
#define UL1D_TRC_MLT_TM_ADV_RET_ADJUST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x220F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_TM_PAC_EVENT(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x230F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MLT_TM_PAC_EVENT(v1)
#endif
#define UL1D_TRC_MLT_TM_PAC_EVENT_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x230F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_PAC_CON(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x240F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MLT_PAC_CON(v1)
#endif
#define UL1D_TRC_MLT_PAC_CON_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x240F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_CG_RLN_PSC_SSC(v1, v2, v3) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x250F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_MLT_CG_RLN_PSC_SSC(v1, v2, v3)
#endif
#define UL1D_TRC_MLT_CG_RLN_PSC_SSC_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x250F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_CG_RL6_PSC(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x260F, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_CG_RL6_PSC(v1)
#endif
#define UL1D_TRC_MLT_CG_RL6_PSC_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x260F, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_RXBRP_CCN_TFCI(v1, v2, v3) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x270F, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_CCN_TFCI(v1, v2, v3)
#endif
#define UL1D_TRC_MLT_RXBRP_CCN_TFCI_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x270F, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MLT_RXBRP_CCN_RECFG_FLAG(v1, v2, v3) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x280F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_CCN_RECFG_FLAG(v1, v2, v3)
#endif
#define UL1D_TRC_MLT_RXBRP_CCN_RECFG_FLAG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x280F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_RXBRP_CCN_DATA_TFI(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x290F, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_CCN_DATA_TFI(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MLT_RXBRP_CCN_DATA_TFI_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x290F, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_RXBRP_CCN_CFN(v1, v2) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A0F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_CCN_CFN(v1, v2)
#endif
#define UL1D_TRC_MLT_RXBRP_CCN_CFN_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A0F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_RXBRP_CC1_CM_TYPE(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B0F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_CC1_CM_TYPE(v1)
#endif
#define UL1D_TRC_MLT_RXBRP_CC1_CM_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B0F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_RXBRP_CC1_CM_PURPOSE(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C0F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_CC1_CM_PURPOSE(v1)
#endif
#define UL1D_TRC_MLT_RXBRP_CC1_CM_PURPOSE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C0F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_RXBRP_CC1_NFIRST(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D0F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_CC1_NFIRST(v1)
#endif
#define UL1D_TRC_MLT_RXBRP_CC1_NFIRST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D0F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_RXBRP_CC1_NLAST(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E0F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_CC1_NLAST(v1)
#endif
#define UL1D_TRC_MLT_RXBRP_CC1_NLAST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E0F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_RXBRP_CCN_U_PhCHCnt(v1, v2, v3) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F0F, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_CCN_U_PhCHCnt(v1, v2, v3)
#endif
#define UL1D_TRC_MLT_RXBRP_CCN_U_PhCHCnt_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F0F, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MLT_RXBRP_BCH_SFN(v1, v2, v3) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x300F, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_BCH_SFN(v1, v2, v3)
#endif
#define UL1D_TRC_MLT_RXBRP_BCH_SFN_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x300F, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_RXBRP_BCH_MD_BOFF_RCRC(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x310F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_BCH_MD_BOFF_RCRC(v1)
#endif
#define UL1D_TRC_MLT_RXBRP_BCH_MD_BOFF_RCRC_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x310F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MLT_RXBRP_BCH_ENABLE(v1) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x320F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_BCH_ENABLE(v1)
#endif
#define UL1D_TRC_MLT_RXBRP_BCH_ENABLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x320F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MLT_RXBRP_BCH_CRC(v1, v2) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x330F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_BCH_CRC(v1, v2)
#endif
#define UL1D_TRC_MLT_RXBRP_BCH_CRC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x330F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MLT_RXBRP_BCH_CMB_TICK(v1, v2) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x340F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_BCH_CMB_TICK(v1, v2)
#endif
#define UL1D_TRC_MLT_RXBRP_BCH_CMB_TICK_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x340F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_RXBRP_BTFD_PASS(v1, v2, v3) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x350F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_BTFD_PASS(v1, v2, v3)
#endif
#define UL1D_TRC_MLT_RXBRP_BTFD_PASS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x350F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_RXBRP_TRCH_ID(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x360F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_TRCH_ID(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1D_TRC_MLT_RXBRP_TRCH_ID_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x360F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MLT_RXBRP_TRCH_DONE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x370F, (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v9), TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v8), (unsigned long)(v11));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_TRCH_DONE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define UL1D_TRC_MLT_RXBRP_TRCH_DONE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x370F, (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v9), TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v8), (unsigned long)(v11))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_RXBRP_REMOVE_CRC(v1, v2) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x380F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_REMOVE_CRC(v1, v2)
#endif
#define UL1D_TRC_MLT_RXBRP_REMOVE_CRC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x380F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_RXBRP_FRAME_SCF(v1, v2) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x390F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_FRAME_SCF(v1, v2)
#endif
#define UL1D_TRC_MLT_RXBRP_FRAME_SCF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x390F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MLT_RXBRP_CCN_ENABLE(v1, v2) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A0F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXBRP_CCN_ENABLE(v1, v2)
#endif
#define UL1D_TRC_MLT_RXBRP_CCN_ENABLE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A0F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MLT_RXSRP_RESET(v1, v2) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B0F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_RXSRP_RESET(v1, v2)
#endif
#define UL1D_TRC_MLT_RXSRP_RESET_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B0F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MLT_FORGERY_SFN_RESULT(v1, v2, v3, v4, v5) do {\
		if(UL1D_MLT_SET2_Trace_Filter[0]==1 && (UL1D_MLT_SET2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C0F, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MLT_FORGERY_SFN_RESULT(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_MLT_FORGERY_SFN_RESULT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C0F, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_MLT_SET2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_MLT_PREPROCESSOR_DEFAULT(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_CLTD_DEFAULT(unsigned short v1, unsigned char v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_MLT_SIREST_DEFAULT(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MLT_DPC_DEFAULT(char v1);
void L1TRC_Send_UL1D_TRC_MLT_TPC_CMB_DEFAULT(unsigned short v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_MLT_AICH_DEFAULT(unsigned long v1);
void L1TRC_Send_UL1D_TRC_MLT_PICH_DEFAULT(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_DEFAULT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_MLT_PICH_POWER_OFFSET(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_DQE_TPC_SIR_LTA(short v1);
void L1TRC_Send_UL1D_TRC_MLT_DQE_LNK_EST_IND(char v1);
void L1TRC_Send_UL1D_TRC_MLT_DQE_SYNC_STATUS(char v1);
void L1TRC_Send_UL1D_TRC_MLT_DPC_TARGET_SIR(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_UL1D_TRC_MLT_DPC_TARGET_SIR_2(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_UL1D_TRC_MLT_DPC_DPDCH_SIR_LTA(short v1);
void L1TRC_Send_UL1D_TRC_MLT_DPC_TARGET_BLER(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_MLT_AGC_M_N_E(char v1, long v2, long v3, short v4);
void L1TRC_Send_UL1D_TRC_MLT_PAC_DISTANCE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_DESPRD_CFG(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MLT_TRK_THRESHOLD_CFG(unsigned long v1);
void L1TRC_Send_UL1D_TRC_MLT_SPEST_ACC_FRAME(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_SPEST_LPF1(unsigned long v1);
void L1TRC_Send_UL1D_TRC_MLT_SPEST_LPF2(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MLT_SPEST_HPF1(unsigned long v1);
void L1TRC_Send_UL1D_TRC_MLT_SPEST_HPF2(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MLT_FOE_THR1(unsigned long v1);
void L1TRC_Send_UL1D_TRC_MLT_FOE_THR2(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MLT_FOE_CON(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MLT_AFC_SWT_HYST(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_AFC_SWT_THRE(unsigned long v1);
void L1TRC_Send_UL1D_TRC_MLT_CHEST_CFG(unsigned long v1);
void L1TRC_Send_UL1D_TRC_MLT_AFC_INITIAL_FREQ(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MLT_SPEST_RESET(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_RTR_RAKECON(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_MLT_TM_ADV_RET_ADJUST(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_TM_PAC_EVENT(unsigned long v1);
void L1TRC_Send_UL1D_TRC_MLT_PAC_CON(unsigned long v1);
void L1TRC_Send_UL1D_TRC_MLT_CG_RLN_PSC_SSC(unsigned short v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_MLT_CG_RL6_PSC(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_CCN_TFCI(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_CCN_RECFG_FLAG(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_CCN_DATA_TFI(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_CCN_CFN(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_CC1_CM_TYPE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_CC1_CM_PURPOSE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_CC1_NFIRST(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_CC1_NLAST(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_CCN_U_PhCHCnt(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_BCH_SFN(unsigned short v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_BCH_MD_BOFF_RCRC(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_BCH_ENABLE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_BCH_CRC(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_BCH_CMB_TICK(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_BTFD_PASS(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_TRCH_ID(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_TRCH_DONE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned char v6, unsigned char v7, unsigned long v8, unsigned char v9, short v10, unsigned long v11);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_REMOVE_CRC(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_FRAME_SCF(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_MLT_RXBRP_CCN_ENABLE(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_MLT_RXSRP_RESET(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_MLT_FORGERY_SFN_RESULT(unsigned char v1, unsigned char v2, short v3, short v4, short v5);

void Set_UL1D_MLT_SET2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_MLT_SET2()	(UL1D_MLT_SET2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()	(ChkL1ModFltr_UL1D_MLT_SET2()&&((UL1D_MLT_SET2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()	(ChkL1ModFltr_UL1D_MLT_SET2()&&((UL1D_MLT_SET2_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_H()	(ChkL1ModFltr_UL1D_MLT_SET2()&&((UL1D_MLT_SET2_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_MLT_SET2_SDRAM_L()	(ChkL1ModFltr_UL1D_MLT_SET2()&&((UL1D_MLT_SET2_Trace_Filter[1]&0x08)!=0))
#define ChkL1MsgFltr_UL1D_TRC_MLT_PREPROCESSOR_DEFAULT()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_CLTD_DEFAULT()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_SIREST_DEFAULT()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_DPC_DEFAULT()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_H()
#define ChkL1MsgFltr_UL1D_TRC_MLT_TPC_CMB_DEFAULT()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_AICH_DEFAULT()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_PICH_DEFAULT()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_DEFAULT()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_PICH_POWER_OFFSET()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_DQE_TPC_SIR_LTA()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_H()
#define ChkL1MsgFltr_UL1D_TRC_MLT_DQE_LNK_EST_IND()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_DQE_SYNC_STATUS()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_DPC_TARGET_SIR()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_DPC_TARGET_SIR_2()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_DPC_DPDCH_SIR_LTA()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_DPC_TARGET_BLER()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_AGC_M_N_E()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_PAC_DISTANCE()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_DESPRD_CFG()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_TRK_THRESHOLD_CFG()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_SPEST_ACC_FRAME()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_SPEST_LPF1()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_SPEST_LPF2()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_SPEST_HPF1()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_SPEST_HPF2()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_FOE_THR1()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_FOE_THR2()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_FOE_CON()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_AFC_SWT_HYST()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_AFC_SWT_THRE()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_CHEST_CFG()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_AFC_INITIAL_FREQ()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_SPEST_RESET()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RTR_RAKECON()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_TM_ADV_RET_ADJUST()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_TM_PAC_EVENT()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_PAC_CON()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_CG_RLN_PSC_SSC()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_CG_RL6_PSC()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_CCN_TFCI()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_CCN_RECFG_FLAG()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_H()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_CCN_DATA_TFI()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_CCN_CFN()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_CC1_CM_TYPE()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_CC1_CM_PURPOSE()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_CC1_NFIRST()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_CC1_NLAST()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_CCN_U_PhCHCnt()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_BCH_SFN()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_H()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_BCH_MD_BOFF_RCRC()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_BCH_ENABLE()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_H()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_BCH_CRC()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_H()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_BCH_CMB_TICK()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_H()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_BTFD_PASS()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_TRCH_ID()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_TRCH_DONE()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_H()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_REMOVE_CRC()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_FRAME_SCF()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXBRP_CCN_ENABLE()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_L()
#define ChkL1MsgFltr_UL1D_TRC_MLT_RXSRP_RESET()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_M()
#define ChkL1MsgFltr_UL1D_TRC_MLT_FORGERY_SFN_RESULT()	ChkL1ClsFltr_UL1D_MLT_SET2_RX_Mod_H()


#endif
