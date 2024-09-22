# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

# *************************************************************************
# Common definitions
# *************************************************************************
include make/buildConfig.mak

L1S_BASIC=FALSE
ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  L1S_BASIC=TRUE
endif

L1_UMTS=FALSE
ifeq ($(strip $(L1_WCDMA)),TRUE)
  L1_UMTS=TRUE
endif
ifeq ($(strip $(L1_TDD128)),TRUE)
  L1_UMTS=TRUE
endif


# *************************************************************************
# Components list
# *************************************************************************
ifeq ($(strip $(RTOS)),NUCLEUS)
COMPLIST       =  nucleus nucleus_int nucleus_ctrl_code nucleus_critical_data
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
COMPLIST       =  nucleus_v2 nucleus_v2_int nucleus_v2_ctrl_code nucleus_v2_critical_data
endif

ifeq ($(strip $(RTOS)),THREADX)
COMPLIST       =  threadx threadx_ctrl_code threadx_ctrl_data
endif

ifeq ($(strip $(RTOS_DEBUG)),TRUE)
  ifeq ($(strip $(RTOS)),NUCLEUS)
    COMPLIST    += nucleus_debug
  endif
  ifeq ($(strip $(RTOS)),NUCLEUS_V2)
    COMPLIST    += nucleus_v2_debug
  endif
  ifeq ($(strip $(RTOS)),THREADX)
    COMPLIST    += threadx_debug
  endif
endif

ifeq ($(strip $(L1S_BASIC)),TRUE)
  COMPLIST       += md_drv
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    COMPLIST       += dummyps
    ifeq ($(strip $(NVRAM_SUPPORT)),TRUE)
      COMPLIST  += nvram nvram_sec 
    endif
    ifneq ($(strip $(L1_UMTS)),TRUE)
      ifeq ($(strip $(L1_GPRS)),TRUE)
        COMPLIST       += gl1 l1_ext md_drv       # GPRS classb
      else
        COMPLIST       += gl1 l1_ext md_drv                     # GSM only
      endif
    else
    endif
  endif

else

  # For PS team developers add component module here.
  COMPLIST       += nvram nvram_sec cc l4misc ciss sms data

  COMPLIST       += sim
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  ifeq ($(strip $(L1_GPRS)),TRUE)
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      ifeq ($(strip $(L1_3GSOLUTION)),MTK_UL1_FDD)
        COMPLIST       += gl1 l1_ext md_drv dummyps dummyups ll1      # DM (EGPRS + 3G) or DM (GPRS + 3G)
      endif
    endif
  endif

  ifeq ($(strip $(L1_GPRS)),TRUE)
    ifeq ($(strip $(L1_WCDMA)),FALSE)
      COMPLIST       += gl1 l1_ext md_drv dummyps                       # 2G Only (EGPRS) or 2G Only (GPRS)
    endif
  endif

  ifeq ($(strip $(L1_GPRS)),FALSE)
    ifeq ($(strip $(L1_EGPRS)),FALSE)
      ifeq ($(strip $(L1_WCDMA)),FALSE)
        COMPLIST       += gl1 l1_ext md_drv dummyps                                     # 2G Only (GSM)
      endif
    endif
  endif

  ifeq ($(strip $(L1_GPRS)),FALSE)
    ifeq ($(strip $(L1_EGPRS)),TRUE)
      $(error: Not support EDGE wihtout GPRS)
    endif
  endif

  ifeq ($(strip $(L1_GPRS)),FALSE)
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      $(error: Not support WCDMA wihtout GPRS)
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
     COM_DEFS += __MTK_3G_MRAT_ARCH__
  endif
endif

ifndef SMART_PHONE_CORE
  SMART_PHONE_CORE = NONE
endif

ifneq ($(filter NONE MODEM_ONLY,$(SMART_PHONE_CORE)),)
  COMPLIST += fs
endif

COMPLIST       += config kal \
                  custom bmt \
                  sst fdm \
                  mtkdebug

ifeq ($(filter BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COMPLIST += ft ftc audio media
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
  COMPLIST += meut
endif

ifndef AST_SUPPORT
  AST_SUPPORT = NONE
endif

ifeq ($(strip $(UTRAN_MODE_SUPPORT)),UTRAN_TDD128_MODE)
  ifdef L1_TDD128
    ifeq ($(strip $(L1_TDD128)),TRUE)
      ifeq ($(strip $(L1_3GSOLUTION)),MTK_TL1_TDD)
        COMPLIST       += tl1 ll1      # DM (EGPRS + TD) or DM (GPRS + TD)
      endif

      ifeq ($(strip $(L1_3GSOLUTION)),AST_TL1_TDD)
        ifeq ($(strip $(AST_SUPPORT)),AST1001)
          COMPLIST       += ast_l1_ast1001 ll1    # DM (EGPRS + 3G) or DM (GPRS + 3G)
          COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001)
          COMPLIST       += ast_l1_ast2001 ll1     # DM (EGPRS + 3G) or DM (GPRS + 3G)
          COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001FPGA)
          COMPLIST       += ast_l1_ast2001 ll1    # DM (EGPRS + 3G) or DM (GPRS + 3G)
          COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST3001)
          COMPLIST       += ast_l1_ast3001 ll1     # DM (EGPRS + 3G) or DM (GPRS + 3G)
          COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST3002)
          COMPLIST       += ast_l1_ast3002 ll1     # DM (EGPRS + 3G) or DM (GPRS + 3G)
          COMPLIST       += fta
        endif
      endif 
    endif
  endif
endif

UL1_PLATFORM    = MT6268 MT6268A MT6268T
UL1_HS_PLATFORM = MT6268H MT6270A MT6276 MT6573 MT6575 MT6577
UL1_HS_PLUS_PLATFORM = TK6280 MT6280 MT6589 MT6571 MT6572 MT6582 MT6592 MT6580 MT6570
ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
  UL1_SUPPORT = TRUE
else
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    UL1_SUPPORT = TRUE
  endif
endif

ifeq ($(strip $(UL1_SUPPORT)),TRUE)
  ifdef L1_3GSOLUTION
    ifneq ($(strip $(L1_3GSOLUTION)),NONE)
      COMPLIST += ll1
    endif
  endif
  ifdef L1_WCDMA
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      ifeq ($(strip $(L1_3GSOLUTION)),MTK_UL1_FDD)
        ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
          UMTS_FDD_PLATFORM = FALSE
          ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLUS_PLATFORM)),)
            COMPLIST       += ul1_hs_plus ul1_hs_plus_ext       # DM (EGPRS + 3G) or DM (GPRS + 3G)
            COM_DEFS       +=   __UL1_HS_PLUS_PLATFORM__ 
            UMTS_FDD_PLATFORM = TRUE
          endif          
          ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
            COMPLIST       += ul1_hs ul1_hs_ext       # DM (EGPRS + 3G) or DM (GPRS + 3G)
            COM_DEFS       +=   __UL1_HS_PLATFORM__ 
            UMTS_FDD_PLATFORM = TRUE
          endif
          ifneq ($(filter $(strip $(PLATFORM)),$(UL1_PLATFORM)),)
#           COMPLIST       += ul1_w ul1_ext          # DM (EGPRS + 3G) or DM (GPRS + 3G
            COM_DEFS       +=   __UL1_PLATFORM__
            UMTS_FDD_PLATFORM = TRUE
          endif
          ifneq ($(strip $(UMTS_FDD_PLATFORM)),TRUE)
            $(warning ERROR: PLATFORM $(strip $(PLATFORM)) is not vaild UMTS_FDD_MODE_SUPPORT platform.) 
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifdef BYTECOPY_SUPPORT
    ifeq ($(strip $(BYTECOPY_SUPPORT)),TRUE)
      COM_DEFS  += __IS_BYTECOPY_SUPPORT__
      COMPLIST  += bytecopy
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COMPLIST += gl1 l1_ext md_drv mm l4 gas ratcm asn1_common
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    COMPLIST += ratdm ratdm_sec uas fsm sndcp sm llc
    ifeq ($(strip $(UTRAN_MODE_SUPPORT)),UTRAN_FDD_MODE)
      COMPLIST += ul2
    endif
  else
    ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
      COMPLIST +=  ratdm ratdm_sec sndcp sm llc
    endif
  endif
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  COMPLIST += fsm
endif

ifeq ($(strip $(MCD_SUPPORT)),TRUE)
  ifeq ($(strip $(L1S_BASIC)),FALSE)
    COMPLIST += mcd
  endif
else
  ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
    COMPLIST += peer_classb
  endif
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
      COMPLIST += email emlst
  endif
endif

ifeq ($(strip $(TST_SUPPORT)),TRUE)
   COMPLIST    += tst
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  COMPLIST    += usb
endif

#ifdef DRM_SUPPORT
#  ifneq ($(strip $(DRM_SUPPORT)),NONE)
#     COMPLIST    	+= drm
#  endif
#endif

ifeq ($(strip $(XML_SUPPORT)),TRUE)
	COMPLIST    += xmlp
endif

#ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
#       COMPLIST    += imps
#endif

ifdef SDP_SUPPORT
  ifneq ($(strip $(SDP_SUPPORT)),FALSE)
     COMPLIST    	+= sdp
  endif   
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
			   COMPLIST          += btadp btprofiles btstack 
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
     COMPLIST    	+= dt
  endif   
endif

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
    COMPLIST         += xdm
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     COMPLIST    	+= iperf
  endif   
endif

ifeq ($(filter BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COMPLIST += event_info
endif

COMPLIST       += verno

# *************************************************************************
# Components Object Files
# *************************************************************************
COMPOBJS			=



# *************************************************************************
# L1 TMD Files
# *************************************************************************

ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
  ifeq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    L1_TMD_FILES = $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c2_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_cs_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_ps_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1sc_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_csd_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D_Trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D2_Trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D_EDGE_Trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_egprs_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_egprs_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_amr_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1t_amr_trace.tmd
  endif
endif

ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_GSM_MODE)
    L1_TMD_FILES    =  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_trace.tmd \
                       $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1sc_trace.tmd \
                       $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_cs_trace.tmd \
                       $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D_Trace.tmd \
                       $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_csd_trace.tmd \
                       $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D2_Trace.tmd \
                       $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_amr_trace.tmd \
                       $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1t_amr_trace.tmd 
endif
                     
ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    L1_TMD_FILES  =  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_trace.tmd \
                     $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1sc_trace.tmd \
                     $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_cs_trace.tmd \
                     $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D_Trace.tmd \
                     $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_csd_trace.tmd \
                     $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D2_Trace.tmd \
                     $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_amr_trace.tmd \
                     $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1t_amr_trace.tmd \
                     $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D_EDGE_Trace.tmd
                     
    ifeq ($(strip $(L1_GPRS)),TRUE)
      L1_TMD_FILES += $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_ps_trace.tmd
      L1_TMD_FILES += $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_egprs_trace.tmd \
                      $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_egprs_trace.tmd \
                      $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c2_trace.tmd
    endif  
    ifeq ($(strip $(L1_UMTS)),TRUE)
        L1_TMD_FILES  +=   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D3_Trace.tmd
        L1_TMD_FILES  +=   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1_AFC_Trace.tmd
        ifeq ($(strip $(L1_WCDMA)),TRUE)
           ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
              ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R8_SUPPORT)
                 L1_TMD_FILES += $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace1.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace2.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace3.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace4.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_MLT_Trace1.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_MLT_Trace2.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace1.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace2.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace3.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace4.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace5.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace6.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1TST_Trace1.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace1.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace2.tmd \
                                 $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_PLUS_Trace1.tmd \
                                 $(strip $(MODEM_FOLDER))/md_sm/common/ul1sm/UL1SM_Trace1.tmd
              else
                 ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R7_SUPPORT)
                    L1_TMD_FILES += $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace1.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace2.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace3.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace4.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_MLT_Trace1.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_MLT_Trace2.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace1.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace2.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace3.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace4.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace5.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace6.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1TST_Trace1.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace1.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace2.tmd \
                                    $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_PLUS_Trace1.tmd \
                                    $(strip $(MODEM_FOLDER))/md_sm/common/ul1sm/UL1SM_Trace1.tmd
                 else
                    ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
                       L1_TMD_FILES += $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1C_Trace1.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1C_Trace2.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1C_Trace3.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1C_Trace4.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_MLT_Trace1.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_MLT_Trace2.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace1.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace2.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace3.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace4.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace5.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace6.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1TST_Trace1.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_HSPA_Trace.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_HSPA_Trace1.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_HSPA_Trace2.tmd
                       L1_TMD_FILES += $(strip $(MODEM_FOLDER))/md_sm/common/ul1sm/UL1SM_Trace1.tmd
                    else
                       L1_TMD_FILES += $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1C_Trace1.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1C_Trace2.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1C_Trace3.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1C_Trace4.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_MLT_Trace1.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_MLT_Trace2.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace1.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace2.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace3.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace4.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace5.tmd \
                                       $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1TST_Trace1.tmd
                       L1_TMD_FILES += $(strip $(MODEM_FOLDER))/md_sm/common/ul1sm/UL1SM_Trace1.tmd
                    endif
                 endif
              endif
           endif
        endif
        ifeq ($(strip $(L1_GPRS)),TRUE)
            L1_TMD_FILES  +=   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1dm_trace.tmd
        endif
    endif
endif

ifeq ($(strip $(L1_UMTS)),TRUE)
   L1_TMD_FILES  = $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c2_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_cs_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_ps_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1sc_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_csd_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D_Trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D2_Trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D_EDGE_Trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_egprs_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c_egprs_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1i_amr_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1t_amr_trace.tmd \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1dm_trace.tmd
   ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R8_SUPPORT)
         L1_TMD_FILES += $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_MLT_Trace1.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_MLT_Trace2.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace1.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace2.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace3.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace4.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace5.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace6.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace1.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace2.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_PLUS_Trace1.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace1.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace2.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace3.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace4.tmd \
                         $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1TST_Trace1.tmd \
                         $(strip $(MODEM_FOLDER))/md_sm/common/ul1sm/UL1SM_Trace1.tmd
      else
         ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R7_SUPPORT)
            L1_TMD_FILES += $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_MLT_Trace1.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_MLT_Trace2.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace1.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace2.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace3.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace4.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace5.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_Trace6.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace1.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_HSPA_Trace2.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_public/UL1D_PLUS_Trace1.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace1.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace2.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace3.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1C_Trace4.tmd \
                            $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common/UL1TST_Trace1.tmd \
                            $(strip $(MODEM_FOLDER))/md_sm/common/ul1sm/UL1SM_Trace1.tmd
         else
            ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
               L1_TMD_FILES += $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_MLT_Trace1.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_MLT_Trace2.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace1.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace2.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace3.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace4.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace5.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_Trace6.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1C_Trace1.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1C_Trace2.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1C_Trace3.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1C_Trace4.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1TST_Trace1.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_HSPA_Trace.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_HSPA_Trace1.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common/UL1D_HSPA_Trace2.tmd
               L1_TMD_FILES += $(strip $(MODEM_FOLDER))/md_sm/common/ul1sm/UL1SM_Trace1.tmd
            else
               L1_TMD_FILES += $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_MLT_Trace1.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_MLT_Trace2.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace1.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace2.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace3.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace4.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1D_Trace5.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1C_Trace1.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1C_Trace2.tmd
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1C_Trace3.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1C_Trace4.tmd \
                               $(strip $(MODEM_FOLDER))/ul1/ul1_w/common/UL1TST_Trace1.tmd
               L1_TMD_FILES += $(strip $(MODEM_FOLDER))/md_sm/common/ul1sm/UL1SM_Trace1.tmd
            endif
         endif
      endif
   endif
endif

ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    ifneq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
      L1_TMD_FILES += $(strip $(MODEM_FOLDER))/uas/ul2/urlc/common/urlc_lisr_trace.tmd
    endif
  endif
endif

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  ifneq ($(strip $(UE_SIMULATOR)),TRUE)
    L1_TMD_FILES    += driver/audio/src/v2/l1audio_trace.tmd
  endif
else
  ifneq ($(strip $(UE_SIMULATOR)),TRUE)
    L1_TMD_FILES    += driver/audio/src/v1/l1audio_trace.tmd
  endif
endif

# *************************************************************************
# Component trace definition header files
# *************************************************************************
ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  COMP_TRACE_DEFS_MODEM = service/tst/local_inc/tst_trace.h
endif
ifeq ($(filter UDVT,$(TEST_LOAD_TYPE)),)
  COMP_TRACE_DEFS_MODEM = service/tst/local_inc/tst_trace.h
endif

ifeq ($(strip $(L1S_BASIC)),TRUE)
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/smt/l1s/dummyps/include/internal/dps_trc.h \
                       driver/peripheral/inc/bmt_trc.h \
                       $(strip $(MODEM_FOLDER))/sim/include/sim_trc.h

  endif

  COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1a_trace.h

  ifeq ($(strip $(L1_WCDMA)),TRUE)
    ifneq ($(strip $(TEST_LOAD_TYPE)),UDVT)
      COMP_TRACE_DEFS_MODEM  += $(strip $(MODEM_FOLDER))/interface/l1/inner/udps_trc.h
    endif
  endif
    
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifeq ($(strip $(NVRAM_SUPPORT)),TRUE)
      COMP_TRACE_DEFS_MODEM    += service/nvram/include/nvram_trc.h
    endif
  endif
  
  ifeq ($(strip $(L1_GPRS)),TRUE)
    ifeq ($(strip $(L1_WCDMA)),TRUE)

          COMP_TRACE_DEFS_MODEM  += $(strip $(MODEM_FOLDER))/interface/l1/inner/ul1a_trc.h
      
    endif
  endif
  
  ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    COMP_TRACE_DEFS_MODEM   += $(strip $(MODEM_FOLDER))/sim/include/sim_trc.h
    COMP_TRACE_DEFS_MODEM    += driver/peripheral/inc/bmt_trc.h
  endif

else

  ifneq ($(strip $(L1_UMTS)),TRUE)
    COMP_TRACE_DEFS_MODEM  +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1a_trace.h \
                         $(strip $(MODEM_FOLDER))/nas/mm/common/include/mm_trc.h \
                         $(strip $(GAS_FOLDER))/common/include/rr_trc.h \
                         $(strip $(GAS_FOLDER))/lapdm/include/lapdm_trc.h \
                         $(strip $(GAS_FOLDER))/rlc/include/rlc_trc.h \
                         $(strip $(GAS_FOLDER))/mac/include/mac_trc.h \
                         $(strip $(MODEM_FOLDER))/nas/ratcm/include/ratcm_trc.h \
                         $(strip $(MODEM_FOLDER))/nas/ratdm/include/ratdm_trc.h
    ifdef GEMINI
      ifneq ($(strip $(GEMINI)),FALSE)
        COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/common/rsva/rsvas/include/rsvas_trc.h
      endif
    endif
  else
    ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
      COMP_TRACE_DEFS_MODEM  +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1a_trace.h \
                           $(strip $(MODEM_FOLDER))/nas/mm/common/include/mm_trc.h \
                           $(strip $(GAS_FOLDER))/common/include/rr_trc.h \
                           $(strip $(GAS_FOLDER))/lapdm/include/lapdm_trc.h \
                           $(strip $(GAS_FOLDER))/rlc/include/rlc_trc.h \
                           $(strip $(GAS_FOLDER))/mac/include/mac_trc.h \
                           $(strip $(MODEM_FOLDER))/nas/ratcm/include/ratcm_trc.h \
                           $(strip $(MODEM_FOLDER))/nas/ratdm/include/ratdm_trc.h
    else
      COMP_TRACE_DEFS_MODEM  +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1a_trace.h \
                           $(strip $(MODEM_FOLDER))/mm/common/include/mm_trc.h \
                           $(strip $(GAS_FOLDER))/include/rr_trc.h \
                           $(strip $(GAS_FOLDER))/lapdm/include/lapdm_trc.h \
                           $(strip $(GAS_FOLDER))/rlc/include/rlc_trc.h \
                           $(strip $(GAS_FOLDER))/mac/include/mac_trc.h \
                           $(strip $(GAS_FOLDER))/rrm/include/rrm_trc.h
    endif
  endif

 
  COMP_TRACE_DEFS_MODEM   += $(strip $(MODEM_FOLDER))/sim/include/sim_trc.h
  COMP_TRACE_DEFS_MODEM    += service/nvram/include/nvram_trc.h \
                       $(strip $(MODEM_FOLDER))/l4/smsal/include/smsal_trc.h \
                       $(strip $(MODEM_FOLDER))/l4/phb/include/phb_trc.h \
                       $(strip $(MODEM_FOLDER))/l4/smu/include/smu_trc.h \
                       $(strip $(MODEM_FOLDER))/nas/cc-ss/ss/include/ciss_trc.h \
                       $(strip $(MODEM_FOLDER))/nas/cc-ss/cc/include/cc_trc.h \
                       $(strip $(MODEM_FOLDER))/l4/csm/csm_trc.h \
                       $(strip $(MODEM_FOLDER))/interface/l4misc/l4_trc.h \
                       $(strip $(MODEM_FOLDER))/nas/sms/include/sms_trc.h \
                       $(strip $(MODEM_FOLDER))/l4/uem/include/uem_trc.h \
                       $(strip $(MODEM_FOLDER))/l4/rac/include/rac_trc.h \
                       $(strip $(MODEM_FOLDER))/l4/tcm/common/tcm_trc.h \
                       $(strip $(PPP_FOLDER))/include/ppp_trc.h \
                       middleware/media/common/include/med_trc.h \
                       $(strip $(MODEM_FOLDER))/nas/data/l2r/include/l2r_trc.h \
                       $(strip $(MODEM_FOLDER))/nas/data/tdt/include/tdt_trc.h \
                       $(strip $(MODEM_FOLDER))/nas/data/rlp/include/rlp_trc.h \
                       $(strip $(MODEM_FOLDER))/nas/data/t30/include/t30_trc.h \
                       $(strip $(MODEM_FOLDER))/nas/data/fa/include/fa_trc.h \
                       driver/peripheral/inc/bmt_trc.h

  ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
    COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/nas/llc/include/llc_trc.h \
                             $(strip $(MODEM_FOLDER))/nas/sndcp/include/snd_trc.h \
                             $(strip $(MODEM_FOLDER))/nas/sm/include/sm_trc.h
    ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
      COMP_TRACE_DEFS_MODEM += $(strip $(UAS_FOLDER))/ul2/bmc/include/bmc_trc.h \
                               $(strip $(UAS_FOLDER))/ul2/common/include/ul2_trc.h \
                               $(strip $(UAS_FOLDER))/ul2/csr/include/csr_trc.h \
                               $(strip $(UAS_FOLDER))/ul2/pdcp/include/pdcp_trc.h \
                               $(strip $(UAS_FOLDER))/ul2/rabm/include/rabm_trc.h \
                               $(strip $(UAS_FOLDER))/ul2/umac/include/umac_trc.h \
                               $(strip $(UAS_FOLDER))/ul2/urlc/include/urlc_trc.h \
                               $(strip $(UAS_FOLDER))/urr/common/include/adr_trc.h \
                               $(strip $(UAS_FOLDER))/urr/cise/include/csce_trc.h \
                               $(strip $(UAS_FOLDER))/urr/cise/include/cse_trc.h \
                               $(strip $(UAS_FOLDER))/urr/cise/include/sibe_trc.h \
                               $(strip $(UAS_FOLDER))/urr/cise/include/usime_trc.h \
                               $(strip $(UAS_FOLDER))/urr/common/include/urr_trc.h \
                               $(strip $(UAS_FOLDER))/urr/dbme/include/dbme_trc.h \
                               $(strip $(UAS_FOLDER))/urr/meme/include/meme_trc.h \
                               $(strip $(UAS_FOLDER))/urr/rrce/include/rrce_trc.h \
                               $(strip $(UAS_FOLDER))/urr/slce/include/slce_trc.h

      ifeq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
        ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
          COMP_TRACE_DEFS_MODEM += $(strip $(UAS_FOLDER))/l2hwaccsim/common/include/l2_hw_acc_sim_trc.h
        endif
      endif
      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/interface/l1/inner/ul1a_trc.h
      endif

      ifdef GEMINI
        ifneq ($(strip $(GEMINI)),FALSE)
          COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/common/rsva/rsvas/include/rsvas_trc.h \
                             $(strip $(MODEM_FOLDER))/common/rsva/rsvak/include/rsvak_trc.h \
                             $(strip $(MODEM_FOLDER))/common/rsva/rsvau/include/rsvau_trc.h \
                             $(strip $(MODEM_FOLDER))/common/rsva/rsvag/include/rsvag_trc.h
        endif
      endif
    endif
  endif
endif

COMP_TRACE_DEFS_MODEM    += service/sst/include/ex_trc.h

COMP_TRACE_DEFS_MODEM    += service/sst/include/SST_trc.h

COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/l4/include/atci_trc.h

ifeq ($(strip $(USB_SUPPORT)),TRUE)
        COMP_TRACE_DEFS_MODEM    += driver/connectivity/usb_class/include/usb_trc.h
endif

#ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
#  COMP_TRACE_DEFS_FP += plutommi/mmi/inc/MMI_trc.h
#else
#  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
#    COMP_TRACE_DEFS_FP += plutommi/mmi/inc/MMI_trc.h
#  else
#    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
#      COMP_TRACE_DEFS_FP += lcmmi/mmi/inc/MMI_trc.h \
#                         lcmmi/mmi/inc/MMI_fw_trc.h \
#                         lcmmi/mmi/inc/MMI_common_app_trc.h \
#                         lcmmi/mmi/inc/MMI_media_app_trc.h
#    else
#      ifeq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
#        COMP_TRACE_DEFS_FP += lcmmi/mmi/inc/MMI_trc.h \
#                           lcmmi/mmi/inc/MMI_fw_trc.h \
#                           lcmmi/mmi/inc/MMI_common_app_trc.h \
#                           lcmmi/mmi/inc/MMI_media_app_trc.h
#      else
#        ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
#          COMP_TRACE_DEFS_FP += external_mmi/wise/bal/common/include/ws_trc.h \
#                             external_mmi/wise/bal/common/include/ws_ps_trc.h 
#        endif
#      endif
#    endif
#  endif
#endif

ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
  #COMP_TRACE_DEFS_MODEM	+= inet_ps\imps\include\imps_trc.h
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COMP_TRACE_DEFS_MODEM    += interface/service/event_info/ul1_event_info_trc.h \
  interface/service/event_info/gas_event_info_trc.h \
  interface/service/event_info/ul2_event_info_trc.h \
  interface/service/event_info/uas_event_info_trc.h \
  interface/service/event_info/cc_event_info_trc.h \
  interface/service/event_info/mm_event_info_trc.h \
  interface/service/event_info/ratdm_event_info_trc.h \
  interface/service/event_info/sm_event_info_trc.h \
  interface/service/event_info/sms_event_info_trc.h \
  interface/service/event_info/llc_event_info_trc.h \
  interface/service/event_info/sndcp_event_info_trc.h \
  interface/service/event_info/l4_event_info_trc.h \
  interface/service/event_info/ppp_event_info_trc.h
endif

# *************************************************************************
# Common include path
# *************************************************************************
COMMINCDIRS    +=    interface/service/stacklib \
                     interface/driver/hwdrv \
                     interface/modem/l1/gsm/external interface/modem/l1/fdd/external interface/modem/l1/tdd \
                     $(BUILD_TSTDIR)/include

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
COMMINCDIRS      +=  $(strip $(CUS_MTK_REL))/tst/include
endif

COMMINCDIRS    += interface/service/tst \
                     $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext \
                     interface/middleware/general \
                     interface/service/nvram \
                     interface/driver/sleep_drv \
                     interface/service/fs \
                     driver/connectivity/usb_driver/inc \
                     driver/connectivity/usb_driver/src \
                     interface/driver/connectivity/usb_driver \
                     interface/driver/storage \
                     interface/modem/general \
                     interface/modem/mcd \
                     $(strip $(PROJDIR))/modem \
                     $(strip $(PROJDIR))/modem/rrc_asn \
                     $(strip $(PROJDIR))/modem/dbme \
                     $(strip $(PROJDIR))/modem/scsi \
                     $(strip $(PROJDIR))/modem/mcd \
                     $(strip $(PROJDIR))/modem/mcddll \
                     $(strip $(GEN_L4DIR))/mcd \
                     $(strip $(GEN_MMIDIR))/mcd

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
COMMINCDIRS      +=  $(strip $(REL_L4DIR))/mcd \
                     $(strip $(REL_MMIDIR))/mcd
endif

COMMINCDIRS    += interface/driver/drv_sw_def \
                     driver/drv_def \
                     interface/driver/sys_drv \
                     interface/service/sys_svc \
                     driver/sys_drv/cirq/inc \
                     driver/sys_drv/counter/inc \
                     driver/sys_drv/dcm/inc \
                     driver/sys_drv/dma/inc \
                     driver/sys_drv/emi/inc \
                     driver/sys_drv/init/inc \
                     driver/sys_drv/ipc/inc \
                     driver/sys_drv/pdn/inc \
                     driver/sys_drv/pll/inc \
                     driver/sys_drv/regbase/inc \
                     driver/storage/flash/fdm/inc \
                     driver/cipher/include \
                     driver/connectivity/usb_driver/inc \
                     driver/storage/flash/mtd/inc \
                     driver/drv/include \
                     interface/sap \
                     interface/sap/md \
                     interface/sap/mw \
                     interface/sap/drv \
                     interface/sap/svc

COMMINCDIRS += $(strip $(GEN_SSDIR))
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  COMMINCDIRS += $(strip $(REL_SSDIR))
endif

BSP_AP_INCDIRS    += hal/camera/cal/inc \
                     hal/mdp/include \
                     hal/camera/isp/inc \
                     hal/camera/mdp_cam_if/inc \
                     hal/graphics/jpeg/exif/inc
                     


ifeq ($(strip $(L1_UMTS)),TRUE)
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      COMMINCDIRS += interface/modem/l1/gsm/external interface/modem/l1/fdd/external
    endif
  endif
endif

COMMINCDIRS += $(BUILD_TST_DB)/pstrace_db
ifeq ($(strip $(L1_UMTS)),TRUE)
  ifeq ($(strip $(L1_TDD128)),TRUE)
    COMMINCDIRS    += interface/modem/tl1interface
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
       COMMINCDIRS += interface/modem/l1/gsm/external interface/modem/l1/fdd/external
    endif
  endif
else
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        COMMINCDIRS += interface/modem/l1/gsm/external interface/modem/l1/fdd/external 
      endif
    else
      ifeq ($(strip $(L1_TDD128)),TRUE)
        COMMINCDIRS += interface/modem/tl1interface
      endif
    endif
  endif
endif


ifeq ($(strip $(L1_UMTS)),TRUE)
  ifdef L1_WCDMA
    ifeq ($(strip $(L1_WCDMA)),TRUE)

        ifeq ($(strip $(L1_3GSOLUTION)),MTK_UL1_FDD)
          COMMINCDIRS    += driver/drv/include
        endif
     
    endif
  endif

  ifdef L1_TDD128
    ifeq ($(strip $(L1_TDD128)),TRUE)
      ifeq ($(strip $(L1_3GSOLUTION)),AST_TL1_TDD)
        COMMINCDIRS    += interface/modem/tl1interface
      else
        ifeq ($(strip $(L1_3GSOLUTION)),MTK_TL1_TDD)
          COMMINCDIRS    += driver/drv/include
        endif
      endif
    endif
  endif
endif


COMMINCDIRS       += interface/service/fs \
                     interface/middleware/media \
                     interface/common 

# Poying: There should be some feature option defining __UGTCM__
UGTCM = TRUE

COMMINCDIRS    +=  custom/modem/l1_rf/$(RF_MODULE)

COMMINCDIRS    += interface/service/config

ifeq ($(strip $(L1_WCDMA)),TRUE)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT) 
    COMMINCDIRS += custom/modem/ul1_rf/$(UMTS_RF_MODULE)
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
    COMMINCDIRS += interface/modem/l1/gsm/external interface/modem/l1/fdd/external
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    COMMINCDIRS += interface/modem/l1/gsm/external interface/modem/l1/fdd/external
  endif
endif

ifeq ($(strip $(L1_TDD128)),TRUE)
  COMMINCDIRS += custom/modem/tl1_rf/$(UMTS_TDD128_RF_MODULE)
  ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
    COMMINCDIRS    += interface/modem/tl1interface
  endif
endif

COMMINCDIRS       +=   \
                       \
                      $(call CUSTOM_FLD_MAPPING,custom/modem/ps) \
                      custom/modem/common/ps \
                      custom/service/nvram \
                      custom/service/flc2 \
                      custom/driver/common \
                      custom/middleware/common \
                      custom/modem/common




ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
#  COMMINCDIRS  +=	inet_ps\imps\include
endif

ifneq ($(strip $(SDP_SUPPORT)),FALSE)  
#  COMMINCDIRS += inet_ps\sdp\include
endif


ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COMMINCDIRS    += interface/service/event_info
endif

# *************************************************************************
# Common preprocessor definitions
# *************************************************************************

ifeq ($(strip $(L1S_BASIC)),TRUE)
  CUSTOM_OPTION    +=  __L1_STANDALONE__ __CS_SERVICE__

  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    CUSTOM_OPTION    +=  DUMMY_PROTOCOL __FS_ON__ __MULTI_BOOT__
  endif

  ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
    CUSTOM_OPTION    +=  L1_NOT_PRESENT NVRAM_NOT_PRESENT __MAUI_BASIC__
    ifneq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
      CUSTOM_OPTION     += MTK_SYSSERV_DEBUG 
    endif
  
    ifeq ($(strip $(IC_TEST_TYPE)),IC_MODULE_TEST)
      CUSTOM_OPTION += IC_MODULE_TEST
      CUSTOM_OPTION += DEVDRV_TEST
    endif

    ifeq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
      CUSTOM_OPTION    +=  IC_BURNIN_TEST
      CUSTOM_OPTION += DEVDRV_TEST
    endif
  endif

  ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    CUSTOM_OPTION    +=  L1_NOT_PRESENT __MEUT__ NVRAM_NOT_PRESENT __MAUI_BASIC__
    CUSTOM_OPTION    +=  __UDVT__
  endif

  CUSTOM_OPTION    += L4_NOT_PRESENT MM_NOT_PRESENT CC_NOT_PRESENT CISS_NOT_PRESENT \
                      SMS_NOT_PRESENT SIM_NOT_PRESENT RR_NOT_PRESENT \
                      MMI_NOT_PRESENT SNDCP_NOT_PRESENT SM_NOT_PRESENT REASM_NOT_PRESENT \
                      LLC_NOT_PRESENT DATA_NOT_PRESENT PPP_NOT_PRESENT MED_NOT_PRESENT \
                      WAP_NOT_PRESENT ABM_NOT_PRESENT SOC_NOT_PRESENT TCPIP_NOT_PRESENT \
                      __18V_30V_ME__ MED_V_NOT_PRESENT

  ifdef L1_UMTS
    ifeq ($(strip $(L1_UMTS)),TRUE)
      CUSTOM_OPTION    += RATCM_NOT_PRESENT RATDM_NOT_PRESENT UL2D_NOT_PRESENT UL2_NOT_PRESENT URR_NOT_PRESENT
      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        CUSTOM_OPTION    += __UL1_STANDALONE__
      endif
    endif
  endif

  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S) 
    ifeq ($(strip $(NVRAM_SUPPORT)),TRUE)
      CUSTOM_OPTION  += __MOD_NVRAM__
    else
      CUSTOM_OPTION  += NVRAM_NOT_PRESENT
    endif
  
    ifeq ($(strip $(L1_GPRS)),TRUE)
      ifeq ($(strip $(PLATFORM)),MT6205B)
        $(error: MT6205B not support GPRS)
      endif

      CUSTOM_OPTION    +=  __PS_SERVICE__
    endif
  
    ifeq ($(strip $(L1_EGPRS)),TRUE)

      CUSTOM_OPTION    += __EGPRS_MODE__

      ifeq ($(strip $(L1_EPSK_TX)),TRUE)
        CUSTOM_OPTION    +=  __EPSK_TX__
      endif   
    endif
  
    ifeq ($(strip $(L1D_LOOPBACK)),1)
      COMPLIST         +=  l1d_lp1
      L1_TMD_FILES     +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1DLP_Trace.tmd
      ifneq ($(strip $(L1_UMTS)),TRUE)
        COMMINCDIRS   +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_lp1
      endif
      CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),2)
      COMPLIST         +=  l1d_lp2
      L1_TMD_FILES     +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1DLP_Trace.tmd
      ifneq ($(strip $(L1_UMTS)),TRUE)
        COMMINCDIRS   +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_lp2
      endif
      CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),3)
      COMPLIST         +=  l1d_lp3
      L1_TMD_FILES     +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1DLP3_Trace.tmd
      ifneq ($(strip $(L1_UMTS)),TRUE)
        COMMINCDIRS   +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_lp3
      endif
      CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),5)
       COMPLIST         +=  l1d_lp5
       L1_TMD_FILES     +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1DLP5_Trace.tmd
       COMMINCDIRS   +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_lp5
       CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),6)
       COMPLIST         +=  l1d_lp6
       L1_TMD_FILES     +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1DLP6_Trace.tmd
       COMMINCDIRS   +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_lp6
       CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),7)
       COMPLIST         +=  l1d_lp7
       L1_TMD_FILES     +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1DLP7_Trace.tmd
       COMMINCDIRS   +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_lp7
       CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),8)
       COMPLIST         +=  l1d_lp8
       L1_TMD_FILES     +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1DLP8_Trace.tmd
       COMMINCDIRS   +=  $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_lp8
       CUSTOM_OPTION    +=  L1D_TEST
    endif
  
    ifeq ($(strip $(L1D_COSIM)),TRUE)
      CUSTOM_OPTION    +=  L1D_TEST_COSIM
    endif

    ifeq ($(strip $(ISP_SUPPORT)),TRUE)
      CUSTOM_OPTION    += ISP_SUPPORT
    endif
  endif
else # L1S_BASIC = FALSE

  CUSTOM_OPTION    +=   __MOD_L4C__ __MOD_CSM__ __MOD_RAC__ __MOD_SMU__ __MOD_SMSAL__ \
                       __MOD_PHB__ __MOD_UEM__ __MOD_CC__ __MOD_CISS__ __MOD_SMS__ \
                       __MOD_MM__ __MOD_NVRAM__ __MOD_SIM__ \
                       __SAT__ __EM_MODE__ __CPHS__ __MULTI_BOOT__ \
                       __18V_30V_ME__  __PHB_COMPARE_NUMBER_9_DIGIT__
  ifneq ($(filter NONE MODEM_ONLY,$(SMART_PHONE_CORE)),)
    CUSTOM_OPTION    += __FS_ON__
  endif
endif


ifneq ($(strip $(L1_UMTS)),TRUE)
  ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_GSM_MODE)
    CUSTOM_OPTION += RATDM_NOT_PRESENT
  endif
  ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
    CUSTOM_OPTION += RATDM_NOT_PRESENT RATCM_NOT_PRESENT
  endif
  CUSTOM_OPTION += __MTK_3G_MRAT_ARCH__ __GSM_RAT__
endif


ifneq ($(strip $(CENTRALIZED_SLEEP_MANAGER)),TRUE)
  CUSTOM_OPTION += __NEW_OS_TICK__
endif


  CUSTOM_OPTION     += FMT_NOT_PRESENT



  CUSTOM_OPTION += __FLIGHT_MODE_SUPPORT__


ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    CUSTOM_OPTION += __CS_SERVICE__ __PS_SERVICE__ __MOD_TCM__
  else
    ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
      CUSTOM_OPTION += __CS_SERVICE__ __PS_SERVICE__ __MOD_TCM__
    else
      CUSTOM_OPTION += __CS_SERVICE__ SNDCP_NOT_PRESENT SM_NOT_PRESENT REASM_NOT_PRESENT LLC_NOT_PRESENT
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    CUSTOM_OPTION += __GSM_RAT__
  endif
endif

ifeq ($(filter BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifdef L1_WCDMA
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      CUSTOM_OPTION    +=  __UMTS_RAT__ __MTK_3G_MRAT_ARCH__ 
      CUSTOM_OPTION  += MAL1_NOT_PRESENT __MTK_UL1_FDD__   
    endif
  endif
  ifdef L1_TDD128
    ifeq ($(strip $(L1_TDD128)),TRUE)
      CUSTOM_OPTION    +=  __UMTS_RAT__ __MTK_3G_MRAT_ARCH__ __TDD_DM_GAP_OPTIMIZATION__
      ifneq ($(strip $(L1_3GSOLUTION)),AST_TL1_TDD)
        CUSTOM_OPTION  += MAL1_NOT_PRESENT __MTK_TL1_TDD__
      else
        ifeq ($(strip $(AST_SUPPORT)),AST1001)
          CUSTOM_OPTION  += __AST1001__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST1001_LIB)
          CUSTOM_OPTION  += __AST1001__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001)
          CUSTOM_OPTION  += __AST2001__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001_LIB)
          CUSTOM_OPTION  += __AST2001__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001FPGA)
          CUSTOM_OPTION  += __AST2001FPGA__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001FPGA_LIB)
          CUSTOM_OPTION  += __AST2001FPGA__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST3001)
          CUSTOM_OPTION  += __AST3001__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST3001_LIB)
          CUSTOM_OPTION  += __AST3001__
        endif
        CUSTOM_OPTION  += __AST_TL1_TDD__ __RACH_FACH_TL1_BITOFFSET__
        CUSTOM_OPTION  += __AST_$(strip $(AST_CHIP_VERSION))__
      endif
    endif
  endif
endif

ifneq ($(strip $(PLATFORM)),MT6251)
  CUSTOM_OPTION += __SYS_INTERN_RAM__
endif

CUSTOM_OPTION += MTK_NEW_API

ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  CUSTOM_OPTION  += __PRODUCTION_RELEASE__
endif

## neptune only
#ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
#ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
#ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
#ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
#ifneq ($(strip $(MMI_VERSION)),BW_MMI)
#  CUSTOM_OPTION    += MED_V_NOT_PRESENT
#  CUSTOM_OPTION    += __SLIM_DATA__
#endif
#endif
#endif
#endif
#endif

ifeq ($(strip $(TST_SUPPORT)),TRUE)
  CUSTOM_OPTION    += __TST_MODULE__
else
  CUSTOM_OPTION    += DRV_DEBUG
endif


ifeq ($(strip $(MCD_SUPPORT)),TRUE)
  ifeq ($(strip $(L1S_BASIC)),FALSE)
    CUSTOM_OPTION    += __MCD__
  endif
endif

# For WISDOM_MMI
#ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
#  CUSTOM_OPTION += $(strip $(MMI_VERSION)) __MMI_FMI__ __MOD_L4A__ EXTERNAL_MMI
#endif


      CUSTOM_OPTION += EMPTY_MMI


#ifeq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
#  CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__  __VENUS_MMI__ NEPTUNE_MMI
#else
#  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
#    CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__  __VENUS_MMI__ $(strip $(MMI_VERSION))
#  endif
#endif

ifeq ($(strip $(SPLIT_SYSTEM)),TRUE)
   CUSTOM_OPTION    += UT_ON_TARGET SPLIT_SYS
endif

ifeq ($(strip $(EMAIL_SUPPORT)),TRUE)
   CUSTOM_OPTION    += __EMAIL__
endif


ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
   CUSTOM_OPTION    += __IRDA_SUPPORT__
endif

ifneq ($(strip $(PHB_SIM_ENTRY)),)
  CUSTOM_OPTION += __PHB_SIM_$(strip $(PHB_SIM_ENTRY))__
endif

ifneq ($(strip $(PHB_PHONE_ENTRY)),)
  CUSTOM_OPTION += __PHB_PHONE_$(strip $(PHB_PHONE_ENTRY))__
endif

ifeq ($(strip $(PMIC)),MT6305)
     CUSTOM_OPTION    += MT6305 __CHARGER_WITH_IMMEDIMATE_ADC__
endif

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  CUSTOM_OPTION    += __DSP_FCORE4__
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  CUSTOM_OPTION    += __IDLE_INTERF_MEAS__ __PKT_EXT_MEAS__
endif

CUSTOM_OPTION += __AMR_WB_WHITE_LIST__
ifeq ($(strip $(UGTCM)),TRUE)
  CUSTOM_OPTION += __UGTCM__
endif
