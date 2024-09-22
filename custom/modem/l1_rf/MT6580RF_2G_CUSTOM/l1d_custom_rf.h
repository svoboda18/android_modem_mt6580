/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   l1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6580
 *
 * Description:
 * ------------
 *   MT6580RF 2G RF constance definition
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* --------------------------------------------------------------------------- */

#if !defined(MT6580RF_2G_RF)
   #error "rf files mismatch with compile option!"
#endif

#if IS_BPI_V2_PT3A_SUPPORT
/*--------------------------------------------------------*/
/*   Event Timing Define                                  */
/*--------------------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ #define  QB_SR1               166
/*MT6580RF*/ #define  QB_SR2               45   /* SR2 should be larger  than (QB_RX_FENA_2_FSYNC+8QB)*/
/*MT6580RF*/ #define  QB_SR2M              39
/*MT6580RF*/ #define  QB_SR3               3    /* SR3 should be larger than (QB_RX_FSYNC_2_FENA+2QB) */
/*MT6580RF*/ #define  QB_PR1               167  /* QB_PR1>QB_SR1 to prevent RF conflict among 2/3G    */
/*MT6580RF*/ #define  QB_PR2               50
/*MT6580RF*/ #define  QB_PR3               7
/*MT6580RF*/ #define  QB_ST1               280
/*MT6580RF*/ #define  QB_ST2B              33   /* ST2B should be larger  than (QB_TX_FENA_2_FSYNC+8QB)*/
/*MT6580RF*/ #define  QB_ST3               38   /* ST3  should be larger  than (QB_TX_FSYNC_2_FENA+7QB)*/
/*MT6580RF*/ #define  QB_PT1               282  /* QB_PT1>QB_ST1 to prevent RF conflict among 2/3G     */
/*MT6580RF*/ #define  QB_PT2               56
/*MT6580RF*/ #define  QB_PT2B              6
/*MT6580RF*/ #define  QB_PT3               33
/*MT6580RF*/ #define  QB_PT3A              46
/*MT6580RF*/ #define  QB_ST2M_G8           15
/*MT6580RF*/ #define  QB_ST2M_8G           15
/*MT6580RF*/ #define  QB_PT2M1_G8          -1
/*MT6580RF*/ #define  QB_PT2M2_G8          -3
/*MT6580RF*/ #define  QB_PT2M1_8G          10
/*MT6580RF*/ #define  QB_PT2M2_8G          4
/*MT6580RF*/
/*MT6580RF*/
/*MT6580RF*/ #define  QB_APCON             14 //OH:11
/*MT6580RF*/ #define  QB_APCMID            20 //OH:18
/*MT6580RF*/ #define  QB_APCOFF            6  //56: 6
/*MT6580RF*/ #define  QB_APCDACON          18 //0
/*MT6580RF*/ #define  TX_PROPAGATION_DELAY 47 //56:47 / OH:46
/*MT6580RF*/
/*MT6580RF*/
/*MT6580RF*/ /*--------------------------------------------------*/
/*MT6580RF*/ /*   define  BPI data for MT6580RF                  */
/*MT6580RF*/ /*--------------------------------------------------*/
/*MT6580RF*/ /*  PRCB : bit   pin                                */
/*MT6580RF*/ /*          0    ASM_VCTRL_A                        */
/*MT6580RF*/ /*          1    ASM_VCTRL_B                        */
/*MT6580RF*/ /*          2    ASM_VCTRL_C                        */
/*MT6580RF*/ /*          3    ASM_VCTRL_D/WG_GGE_PA_EN           */
/*MT6580RF*/ /*         12    SP3T_A_V1                          */
/*MT6580RF*/ /*         13    SP3T_B_V2                          */
/*MT6580RF*/ /*         16    ANTENNA_CONFLICT_2G                */
/*MT6580RF*/ /*         17    SPI_SWITCH_TO_2G                   */
/*MT6580RF*/ /*         18    GSM_ERR_DET_ID                     */
/*MT6580RF*/ /*         20    M23G_PA_INDICATOR                  */
/*MT6580RF*/ /*--------------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ /*------------------------------------------------------*/
/*MT6580RF*/ /*  GSM_ERR_DET_ID(Pin:18) has no dedicate output pin,  */
/*MT6580RF*/ /*  and it is mapped to bit "18" for SW control.        */
/*MT6580RF*/ /*  For accurate RF conflict detection, this value must */
/*MT6580RF*/ /*  set "18" and is unchangable.                        */
/*MT6580RF*/ /*------------------------------------------------------*/
/*MT6580RF*/ #define  GSM_ERR_DET_ID         (               18) /* For accurate RF conflict detection(2G/FDD), this value must set "18" */
/*MT6580RF*/                                                     /* and is unchangable.                                                  */
/*MT6580RF*/ #define  PDATA_GSM_ERR_DET      (1<<GSM_ERR_DET_ID)
/*MT6580RF*/
/*MT6580RF*/ #define  PDATA_GMSK              0x000000
/*MT6580RF*/ #define  PDATA_8PSK              0x000004
/*MT6580RF*/ 
/*MT6580RF*/ #define  PDATA_GSM850_PR1       (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PR2       (0x000002           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PR3       (0x000000                             )
/*MT6580RF*/ #define  PDATA_GSM_PR1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PR2          (0x000002           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PR3          (0x000000                             )
/*MT6580RF*/ #define  PDATA_DCS_PR1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PR2          (0x000001           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PR3          (0x000000                             )
/*MT6580RF*/ #define  PDATA_PCS_PR1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PR2          (0x000001           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PR3          (0x000000                             )
/*MT6580RF*/ #define  PDATA_GSM850_PT1       (0x000000           |PDATA_GSM_ERR_DET) 
/*MT6580RF*/ #define  PDATA_GSM850_PT2       (0x000001           |PDATA_GSM_ERR_DET) 
/*MT6580RF*/ #define  PDATA_GSM850_PT2B      (0x000009           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PT3       (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PT3A      (0x000000                             )
/*MT6580RF*/ #define  PDATA_GSM850_PT2M1_G8  (0x000009|PDATA_8PSK|PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PT2M2_G8  (0x000009|PDATA_8PSK|PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PT2M1_8G  (0x000001           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PT2M2_8G  (0x000009           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT2          (0x000001           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT2B         (0x000009           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT3          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT3A         (0x000000                             )
/*MT6580RF*/ #define  PDATA_GSM_PT2M1_G8     (0x000009|PDATA_8PSK|PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT2M2_G8     (0x000009|PDATA_8PSK|PDATA_GSM_ERR_DET) 
/*MT6580RF*/ #define  PDATA_GSM_PT2M1_8G     (0x000001           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT2M2_8G     (0x000009           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT2          (0x000003           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT2B         (0x00000B           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT3          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT3A         (0x000000                             )
/*MT6580RF*/ #define  PDATA_DCS_PT2M1_G8     (0x00000B|PDATA_8PSK|PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT2M2_G8     (0x00000B|PDATA_8PSK|PDATA_GSM_ERR_DET) 
/*MT6580RF*/ #define  PDATA_DCS_PT2M1_8G     (0x000003           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT2M2_8G     (0x00000B           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT2          (0x000003           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT2B         (0x00000B           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT3          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT3A         (0x000000                             )
/*MT6580RF*/ #define  PDATA_PCS_PT2M1_G8     (0x00000B|PDATA_8PSK|PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT2M2_G8     (0x00000B|PDATA_8PSK|PDATA_GSM_ERR_DET) 
/*MT6580RF*/ #define  PDATA_PCS_PT2M1_8G     (0x000003           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT2M2_8G     (0x00000B           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_INIT             (0x000000                             )
/*MT6580RF*/ #define  PDATA_IDLE             (0x000000                             )
#else
/*--------------------------------------------------------*/
/*   Event Timing Define                                  */
/*--------------------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ #define  QB_SR1               166
/*MT6580RF*/ #define  QB_SR2               45   /* SR2 should be larger  than (QB_RX_FENA_2_FSYNC+8QB)*/
/*MT6580RF*/ #define  QB_SR2M              22
/*MT6580RF*/ #define  QB_SR3               3    /* SR3 should be larger than (QB_RX_FSYNC_2_FENA+2QB) */
/*MT6580RF*/ #define  QB_PR1               167  /* QB_PR1>QB_SR1 to prevent RF conflict among 2/3G    */
/*MT6580RF*/ #define  QB_PR2               50
/*MT6580RF*/ #define  QB_PR3               7
/*MT6580RF*/ #define  QB_ST1               280
/*MT6580RF*/ #define  QB_ST2B              33   /* ST2B should be larger  than (QB_TX_FENA_2_FSYNC+8QB)*/
/*MT6580RF*/ #define  QB_ST3               38   /* ST3  should be larger  than (QB_TX_FSYNC_2_FENA+7QB)*/
/*MT6580RF*/ #define  QB_PT1               282  /* QB_PT1>QB_ST1 to prevent RF conflict among 2/3G     */
/*MT6580RF*/ #define  QB_PT2               56
/*MT6580RF*/ #define  QB_PT2B              6
/*MT6580RF*/ #define  QB_PT3               46
/*MT6580RF*/ #define  QB_ST2M_G8           15
/*MT6580RF*/ #define  QB_ST2M_8G           15
/*MT6580RF*/ #define  QB_PT2M1_G8          -1
/*MT6580RF*/ #define  QB_PT2M2_G8          -3
/*MT6580RF*/ #define  QB_PT2M1_8G          10
/*MT6580RF*/ #define  QB_PT2M2_8G          4
/*MT6580RF*/
/*MT6580RF*/
/*MT6580RF*/ #define  QB_APCON             14 //OH:11
/*MT6580RF*/ #define  QB_APCMID            20 //OH:18
/*MT6580RF*/ #define  QB_APCOFF            6  //56: 6
/*MT6580RF*/ #define  QB_APCDACON          18 //0
/*MT6580RF*/ #define  TX_PROPAGATION_DELAY 47 //56:47 / OH:46
/*MT6580RF*/
/*MT6580RF*/
/*MT6580RF*/ /*--------------------------------------------------*/
/*MT6580RF*/ /*   define  BPI data for MT6580RF                  */
/*MT6580RF*/ /*--------------------------------------------------*/
/*MT6580RF*/ /*  PRCB : bit   pin                                */
/*MT6580RF*/ /*          0    ASM_VCTRL_A                        */
/*MT6580RF*/ /*          1    ASM_VCTRL_B                        */
/*MT6580RF*/ /*          2    ASM_VCTRL_C                        */
/*MT6580RF*/ /*          3    ASM_VCTRL_D/WG_GGE_PA_EN           */
/*MT6580RF*/ /*         12    SP3T_A_V1                          */
/*MT6580RF*/ /*         13    SP3T_B_V2                          */
/*MT6580RF*/ /*         16    ANTENNA_CONFLICT_2G                */
/*MT6580RF*/ /*         17    SPI_SWITCH_TO_2G                   */
/*MT6580RF*/ /*         18    GSM_ERR_DET_ID                     */
/*MT6580RF*/ /*         20    M23G_PA_INDICATOR                  */
/*MT6580RF*/ /*--------------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ /*------------------------------------------------------*/
/*MT6580RF*/ /*  GSM_ERR_DET_ID(Pin:18) has no dedicate output pin,  */
/*MT6580RF*/ /*  and it is mapped to bit "18" for SW control.        */
/*MT6580RF*/ /*  For accurate RF conflict detection, this value must */
/*MT6580RF*/ /*  set "18" and is unchangable.                        */
/*MT6580RF*/ /*------------------------------------------------------*/
/*MT6580RF*/ #define  GSM_ERR_DET_ID         (               18) /* For accurate RF conflict detection(2G/FDD), this value must set "18" */
/*MT6580RF*/                                                     /* and is unchangable.                                                  */
/*MT6580RF*/ #define  PDATA_GSM_ERR_DET      (1<<GSM_ERR_DET_ID)
/*MT6580RF*/
/*MT6580RF*/ #define  PDATA_GMSK              0x000000
/*MT6580RF*/ #define  PDATA_8PSK              0x000004
/*MT6580RF*/ 
/*MT6580RF*/ #define  PDATA_GSM850_PR1       (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PR2       (0x000002           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PR3       (0x000000                             )
/*MT6580RF*/ #define  PDATA_GSM_PR1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PR2          (0x000002           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PR3          (0x000000                             )
/*MT6580RF*/ #define  PDATA_DCS_PR1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PR2          (0x000001           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PR3          (0x000000                             )
/*MT6580RF*/ #define  PDATA_PCS_PR1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PR2          (0x000001           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PR3          (0x000000                             )
/*MT6580RF*/ #define  PDATA_GSM850_PT1       (0x000000           |PDATA_GSM_ERR_DET) 
/*MT6580RF*/ #define  PDATA_GSM850_PT2       (0x000001           |PDATA_GSM_ERR_DET) 
/*MT6580RF*/ #define  PDATA_GSM850_PT2B      (0x000009           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PT3       (0x000000                             )
/*MT6580RF*/ #define  PDATA_GSM850_PT2M1_G8  (0x000009|PDATA_8PSK|PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PT2M2_G8  (0x000009|PDATA_8PSK|PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PT2M1_8G  (0x000001           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM850_PT2M2_8G  (0x000009           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT2          (0x000001           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT2B         (0x000009           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT3          (0x000000                             )
/*MT6580RF*/ #define  PDATA_GSM_PT2M1_G8     (0x000009|PDATA_8PSK|PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT2M2_G8     (0x000009|PDATA_8PSK|PDATA_GSM_ERR_DET) 
/*MT6580RF*/ #define  PDATA_GSM_PT2M1_8G     (0x000001           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_GSM_PT2M2_8G     (0x000009           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT2          (0x000003           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT2B         (0x00000B           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT3          (0x000000                             )
/*MT6580RF*/ #define  PDATA_DCS_PT2M1_G8     (0x00000B|PDATA_8PSK|PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT2M2_G8     (0x00000B|PDATA_8PSK|PDATA_GSM_ERR_DET) 
/*MT6580RF*/ #define  PDATA_DCS_PT2M1_8G     (0x000003           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_DCS_PT2M2_8G     (0x00000B           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT1          (0x000000           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT2          (0x000003           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT2B         (0x00000B           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT3          (0x000000                             )
/*MT6580RF*/ #define  PDATA_PCS_PT2M1_G8     (0x00000B|PDATA_8PSK|PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT2M2_G8     (0x00000B|PDATA_8PSK|PDATA_GSM_ERR_DET) 
/*MT6580RF*/ #define  PDATA_PCS_PT2M1_8G     (0x000003           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_PCS_PT2M2_8G     (0x00000B           |PDATA_GSM_ERR_DET)
/*MT6580RF*/ #define  PDATA_INIT             (0x000000                             )
/*MT6580RF*/ #define  PDATA_IDLE             (0x000000                             )
#endif
/*MT6580RF*/
/*MT6580RF*//*----------------------------------------------*/
/*MT6580RF*//*   APC Compensate Thresholds                  */
/*MT6580RF*//*----------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ #define    SECONDS2FRAME(n)                     ((int)((n)*1000/4.615))
/*MT6580RF*/ #define    VOLT2UVOLT(n)                        ((int)((n)*1000000))
/*MT6580RF*/ #define    TEMP2MTEMP(n)                        ((int)((n)*1000))
/*MT6580RF*/
/*MT6580RF*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD_SECOND     180
/*MT6580RF*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(BAT_VOLTAGE_SAMPLE_PERIOD_SECOND)
/*MT6580RF*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*MT6580RF*/ #define    BAT_LOW_VOLTAGE_TRHESHOLD            (3.5)
/*MT6580RF*/ #define    BAT_HIGH_VOLTAGE_TRHESHOLD           (4.0)
/*MT6580RF*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(BAT_LOW_VOLTAGE_TRHESHOLD)
/*MT6580RF*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(BAT_HIGH_VOLTAGE_TRHESHOLD)
/*MT6580RF*/
/*MT6580RF*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND 180
/*MT6580RF*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND)
/*MT6580RF*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*MT6580RF*/ #define    BAT_LOW_TEMPERATURE_TRHESHOLD        (0)
/*MT6580RF*/ #define    BAT_HIGH_TEMPERATURE_TRHESHOLD       (50)
/*MT6580RF*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(BAT_LOW_TEMPERATURE_TRHESHOLD)
/*MT6580RF*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(BAT_HIGH_TEMPERATURE_TRHESHOLD)
/*MT6580RF*/
/*MT6580RF*/ #define    RF_TEMPERATURE_SAMPLE_PERIOD_SECOND  1
/*MT6580RF*/ #define    RF_TEMPERATURE_SAMPLE_PERIOD         SECONDS2FRAME(RF_TEMPERATURE_SAMPLE_PERIOD_SECOND)
/*MT6580RF*/ #define    RF_TEMPERATURE_AVERAGE_COUNT         1
/*MT6580RF*/
/*MT6580RF*//*----------------------------------------------*/
/*MT6580RF*//*   Voltage Compensate Parameter               */
/*MT6580RF*//*----------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ #define    MINUTES2FRAME(n)                     ((int)((n)*13000))
/*MT6580RF*/ #define    AP_UPDATE_VOLTINFO_PERIOD            MINUTES2FRAME(5)
/*MT6580RF*/
/*MT6580RF*//*----------------------------------------------*/
/*MT6580RF*//*   Crystal parameter                          */
/*MT6580RF*//*----------------------------------------------*/
/*MT6580RF*/ #if  IS_AFC_VCXO_SUPPORT
/*MT6580RF*/ #define Custom_RF_XO_CapID   155 /* RF SOP, Range:0~255 */
/*MT6580RF*/ #else
/*MT6580RF*/ #define Custom_RF_XO_CapID   0   /* For MT6580RF with VCTCXO */
/*MT6580RF*/ #endif
/*MT6580RF*/
/*MT6580RF*/ /********************************************/
/*MT6580RF*/ /* Define your band mode selection on       */
/*MT6580RF*/ /* High Band and Low Band receivers         */
/*MT6580RF*/ /*        LNA_1 : 2GHB                      */
/*MT6580RF*/ /*        LNA_2 : 2GLB                      */
/*MT6580RF*/ /*        LNA_3 : B40                       */
/*MT6580RF*/ /*        LNA_4 : B1                        */
/*MT6580RF*/ /*        LNA_5 : B5                        */
/*MT6580RF*/ /*        LNA_6 : B2                        */
/*MT6580RF*/ /*        LNA_7 : B8                        */
/*MT6580RF*/ /********************************************/
/*MT6580RF*/
/*MT6580RF*/ #define GSM850_PATH_SEL LNA_2
/*MT6580RF*/ #define GSM_PATH_SEL    LNA_2
/*MT6580RF*/ #define DCS_PATH_SEL    LNA_1
/*MT6580RF*/ #define PCS_PATH_SEL    LNA_1
/*MT6580RF*/
/*MT6580RF*//*======================================================================================== */
/*MT6580RF*/
/*MT6580RF*/ /*----------------------------------------------*/
/*MT6580RF*/ /*   TX Power Control (TXPC) Support            */
/*MT6580RF*/ /*----------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ #define IS_BSI_CLOSED_LOOP_TXPC_ON      0
/*MT6580RF*/
/*MT6580RF*/ #define TXPC_EPSK_TP_SLOPE_LB          ((26<<8)+22) /* Unit: degree/dB. Temperature increment that causes 1-dB EPSK TX power drop */
/*MT6580RF*/ #define TXPC_EPSK_TP_SLOPE_HB          ((27<<8)+22) /* Two slope method : [( temp<20:slpoe1)<<8 + (temp>=20:slpoe2)], slope must < 256 */
/*MT6580RF*/
/*MT6580RF*/ /*----------------------------------------------*/
/*MT6580RF*/ /*   DCXO LPM parameter                         */
/*MT6580RF*/ /*----------------------------------------------*/
/*MT6580RF*/ #define CUSTOM_CLOAD_FREQ_OFFSET   88940 /*in unit of Hz*/
/*MT6580RF*/
/*MT6580RF*/ /*----------------------------------------------------*/
/*MT6580RF*/ /*   Enable or disable the clock1, 2, 3, and 4 output */
/*MT6580RF*/ /*   1 : Enable                                       */
/*MT6580RF*/ /*   0 : Disable                                      */
/*MT6580RF*/ /*----------------------------------------------------*/
/*MT6580RF*/ /*Clock buffer setting is controlled by HW in Rainier, so the following settings are no use */
/*MT6580RF*/ #define CLK1_EN                         1 /* CLK1 is enabled for BB */
/*MT6580RF*/ #define CLK2_EN                         1
/*MT6580RF*/ #define CLK3_EN                         1
/*MT6580RF*/ #define CLK4_EN                         1
/*MT6580RF*/
/*MT6580RF*/ /*----------------------------------------------*/
/*MT6580RF*/ /*   TX power rollback parameter                */
/*MT6580RF*/ /*----------------------------------------------*/
/*MT6580RF*/ /*Unit: 1/8 dB*/
/*MT6580RF*/ /*GSM850 GMSK*/
/*MT6580RF*/ #define GSM850_TX_ROLLBACK_2T_GMSK      8
/*MT6580RF*/ #define GSM850_TX_ROLLBACK_3T_GMSK     24
/*MT6580RF*/ #define GSM850_TX_ROLLBACK_4T_GMSK     32
/*MT6580RF*/ #define GSM850_TX_ROLLBACK_5T_GMSK     40
/*MT6580RF*/ 
/*MT6580RF*/ /*GSM GMSK*/
/*MT6580RF*/ #define GSM_TX_ROLLBACK_2T_GMSK         8
/*MT6580RF*/ #define GSM_TX_ROLLBACK_3T_GMSK        24
/*MT6580RF*/ #define GSM_TX_ROLLBACK_4T_GMSK        32
/*MT6580RF*/ #define GSM_TX_ROLLBACK_5T_GMSK        40
/*MT6580RF*/ 
/*MT6580RF*/ /*DCS GMSK*/
/*MT6580RF*/ #define DCS_TX_ROLLBACK_2T_GMSK         8
/*MT6580RF*/ #define DCS_TX_ROLLBACK_3T_GMSK        24
/*MT6580RF*/ #define DCS_TX_ROLLBACK_4T_GMSK        32
/*MT6580RF*/ #define DCS_TX_ROLLBACK_5T_GMSK        40
/*MT6580RF*/ 
/*MT6580RF*/ /*PCS GMSK*/
/*MT6580RF*/ #define PCS_TX_ROLLBACK_2T_GMSK         8
/*MT6580RF*/ #define PCS_TX_ROLLBACK_3T_GMSK        24
/*MT6580RF*/ #define PCS_TX_ROLLBACK_4T_GMSK        32
/*MT6580RF*/ #define PCS_TX_ROLLBACK_5T_GMSK        40
/*MT6580RF*/ 
/*MT6580RF*/ /*GSM850 EPSK*/
/*MT6580RF*/ #define GSM850_TX_ROLLBACK_2T_EPSK      8
/*MT6580RF*/ #define GSM850_TX_ROLLBACK_3T_EPSK     24
/*MT6580RF*/ #define GSM850_TX_ROLLBACK_4T_EPSK     32
/*MT6580RF*/ #define GSM850_TX_ROLLBACK_5T_EPSK     40
/*MT6580RF*/ 
/*MT6580RF*/ /*GSM EPSK*/
/*MT6580RF*/ #define GSM_TX_ROLLBACK_2T_EPSK         8
/*MT6580RF*/ #define GSM_TX_ROLLBACK_3T_EPSK        24
/*MT6580RF*/ #define GSM_TX_ROLLBACK_4T_EPSK        32
/*MT6580RF*/ #define GSM_TX_ROLLBACK_5T_EPSK        40
/*MT6580RF*/ 
/*MT6580RF*/ /*DCS EPSK*/
/*MT6580RF*/ #define DCS_TX_ROLLBACK_2T_EPSK         8
/*MT6580RF*/ #define DCS_TX_ROLLBACK_3T_EPSK        24
/*MT6580RF*/ #define DCS_TX_ROLLBACK_4T_EPSK        32
/*MT6580RF*/ #define DCS_TX_ROLLBACK_5T_EPSK        40
/*MT6580RF*/ 
/*MT6580RF*/ /*PCS EPSK*/
/*MT6580RF*/ #define PCS_TX_ROLLBACK_2T_EPSK         8
/*MT6580RF*/ #define PCS_TX_ROLLBACK_3T_EPSK        24
/*MT6580RF*/ #define PCS_TX_ROLLBACK_4T_EPSK        32
/*MT6580RF*/ #define PCS_TX_ROLLBACK_5T_EPSK        40
/*MT6580RF*/ /*============================================================================== */
/*MT6580RF*/
/*MT6580RF*/ /*----------------------------------------------*/
/*MT6580RF*/ /*   One-bin Support Definition                 */
/*MT6580RF*/ /*----------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ #define L1D_CUSTOM_DYNAMIC_SUPPORT        (L1D_CUSTOM_GPIO_ENABLE|L1D_CUSTOM_ADC_ENABLE|L1D_CUSTOM_BARCODE_ENABLE)
/*MT6580RF*/
/*MT6580RF*/ /* Constants to enable "Dynamic Initialization RF parameters" mechanism                 */
/*MT6580RF*/ #define L1D_CUSTOM_GPIO_ENABLE            0
/*MT6580RF*/ #define L1D_CUSTOM_ADC_ENABLE             0
/*MT6580RF*/ #define L1D_CUSTOM_BARCODE_ENABLE         0
/*MT6580RF*/
/*MT6580RF*/ /* Constants to define number of sets can be represented by each mechanism respectively */
/*MT6580RF*/ #define L1D_CUSTOM_GPIO_SET_NUMS          2
/*MT6580RF*/ #define L1D_CUSTOM_ADC_SET_NUMS           2
/*MT6580RF*/ #define L1D_CUSTOM_BARCODE_SET_NUMS       2
/*MT6580RF*/
/*MT6580RF*/ /* Constants to first, second, and third index for the representation in configuration  */
/*MT6580RF*/ /* set index table                                                                      */
/*MT6580RF*/
/*MT6580RF*/ /* The value can be set:                                                                */
/*MT6580RF*/ /* L1D_CUSTOM_GPIO_DETECTION_ID                                                         */
/*MT6580RF*/ /* L1D_CUSTOM_ADC_DETECTION_ID                                                          */
/*MT6580RF*/ /* L1D_CUSTOM_BARCODE_DETECTION_ID                                                      */
/*MT6580RF*/ /* L1D_CUSTOM_NULL_ACTION                                                               */
/*MT6580RF*/ /* Note:                                                                                */
/*MT6580RF*/ /* 1. Should not define L1D_CUSTOM_FIRST_INDEX to L1D_CUSTOM_NULL_ACTION                */
/*MT6580RF*/ /*    while L1D_CUSTOM_SECOND_INDEX or L1D_CUSTOM_THIRD_INDEX is not L1D_CUSTOM_NULL_ACTION */
/*MT6580RF*/ /* 2. Should not define L1D_CUSTOM_SECOND_INDEX or L1D_CUSTOM_FIRST_INDEX to            */
/*MT6580RF*/ /*    L1D_CUSTOM_NULL_ACTION while L1D_CUSTOM_THIRD_INDEX is not L1D_CUSTOM_NULL_ACTION */
/*MT6580RF*/ #define L1D_CUSTOM_FIRST_INDEX            L1D_CUSTOM_NULL_ACTION
/*MT6580RF*/ #define L1D_CUSTOM_SECOND_INDEX           L1D_CUSTOM_NULL_ACTION
/*MT6580RF*/ #define L1D_CUSTOM_THIRD_INDEX            L1D_CUSTOM_NULL_ACTION
/*MT6580RF*/
/*MT6580RF*/ /* For trace output to debug ( L1D_CustomDynamicDebug() )                               */
/*MT6580RF*/ #define L1D_CUSTOM_DEBUG_ENABLE           0
/*MT6580RF*/
/*MT6580RF*/ /*------*/
/*MT6580RF*/ /* GPIO */
/*MT6580RF*/ /*------*/
/*MT6580RF*/ /* Customization constant to be used for customer to determine the number of GPIO       */
/*MT6580RF*/ /* detection pins in use                                                                */
/*MT6580RF*/ #define L1D_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE    1
/*MT6580RF*/ /*--------------------------------------------------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ /*-----*/
/*MT6580RF*/ /* ADC */
/*MT6580RF*/ /*-----*/
/*MT6580RF*/ /*Customization constant to be used for customer to determine the bits of ADC in use    */
/*MT6580RF*/ #define L1D_CUSTOM_ADC_BITS                          12      // ADC is 12 bit (1/4096) per step
/*MT6580RF*/
/*MT6580RF*/ /* Constant to be used to determine the maximum input voltage on the board              */
/*MT6580RF*/ /* (in micro volt unit)                                                                 */
/*MT6580RF*/ #define L1D_CUSTOM_ADC_MAX_INPUT_VOLTAGE             1500000 // uV
/*MT6580RF*/
/*MT6580RF*/ /* Customization constant to be used for customer to determine the inaccuracy margin    */
/*MT6580RF*/ /* on the board (in micro volt unit)                                                    */
/*MT6580RF*/ #define L1D_CUSTOM_ADC_INACCURACY_MARGIN             25000   // uV uint
/*MT6580RF*/
/*MT6580RF*/ /* Constant to be used to determine the each step level of ADC voltage to level         */
/*MT6580RF*/ /* look-up table on the board (in micro volt unit)                                      */
/*MT6580RF*/ /* L1D_CUSTOM_ADC_VOLT_LVL_RESOLUTION_THRESHOLD - two times inaccuracy margin           */
/*MT6580RF*/ /* L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE            - step size of consecutive levels       */
/*MT6580RF*/ /* L1D_CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP         - the first level upper bound to 0 volt */
/*MT6580RF*/ #define L1D_CUSTOM_ADC_VOLT_LVL_RESOLUTION_THRESHOLD (L1D_CUSTOM_ADC_INACCURACY_MARGIN * 2)
/*MT6580RF*/ #define L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE            ((L1D_CUSTOM_ADC_MAX_INPUT_VOLTAGE) / (L1D_CUSTOM_ADC_LEVEL_TOTAL-1))
/*MT6580RF*/ #define L1D_CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP         (L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE / 2)
/*MT6580RF*/
/*MT6580RF*/ /* Sample of ADC votlage to level look-up table                                         */
/*MT6580RF*/
/*MT6580RF*/ /* ADC levels - 4                                                                       */
/*MT6580RF*/ /* Level   Upper(uV)       Lower(uV)                                                    */
/*MT6580RF*/ /* 0       250000          0                                                            */
/*MT6580RF*/ /* 1       750000          250000                                                       */
/*MT6580RF*/ /* 2       1250000         750000                                                       */
/*MT6580RF*/ /* 3       1500000         1250000                                                      */
/*MT6580RF*/
/*MT6580RF*/ /* Customization constant to be used for customer to determine number of ADC levels to  */
/*MT6580RF*/ /* be used to distinguish between the RF HW configurations                              */
/*MT6580RF*/
/*MT6580RF*/ #define L1D_CUSTOM_ADC_LEVEL_TOTAL        4
/*MT6580RF*/
/*MT6580RF*/ /* Customization constant to be used for customer to determine number of ADC channel    */
/*MT6580RF*/ /* measurement counts (in 2's order) ex: 7 => 2^7 = 128                                 */
/*MT6580RF*/ #define L1D_CUSTOM_ADC_MEAS_COUNT_2_ORDER 7 //2^7 = 128
/*MT6580RF*/
/*MT6580RF*/ #define L1D_CUSTOM_ADC_LVL0               (L1D_CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP)
/*MT6580RF*/ #define L1D_CUSTOM_ADC_LVL1               (L1D_CUSTOM_ADC_LVL0 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6580RF*/ #define L1D_CUSTOM_ADC_LVL2               (L1D_CUSTOM_ADC_LVL1 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6580RF*/ #define L1D_CUSTOM_ADC_LVL3               (L1D_CUSTOM_ADC_LVL2 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6580RF*/ #define L1D_CUSTOM_ADC_LVL4               (L1D_CUSTOM_ADC_LVL3 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6580RF*/ #define L1D_CUSTOM_ADC_LVL5               (L1D_CUSTOM_ADC_LVL4 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6580RF*/ #define L1D_CUSTOM_ADC_LVL6               (L1D_CUSTOM_ADC_LVL5 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6580RF*/ /*--------------------------------------------------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ /*---------*/
/*MT6580RF*/ /* BarCode */
/*MT6580RF*/ /*---------*/
/*MT6580RF*/ /* Customization constant to be used for customer to determine the n-th digit of        */
/*MT6580RF*/ /* UE barcode to detect the RF configurations; n starts from 0                          */
/*MT6580RF*/ #define L1D_CUSTOM_BARCODE_READ_DIGIT_NUM 0
/*MT6580RF*/
/*MT6580RF*/ /* Customization constant to be used for customer to determine at most three (for now)  */
/*MT6580RF*/ /* kinds of ASM representation barcode digit number (in ASCII) to detect the RF         */
/*MT6580RF*/ /* configurations                                                                       */
/*MT6580RF*/ #define L1D_CUSTOM_BARCODE_DIGIT_VALUE_1  0
/*MT6580RF*/ #define L1D_CUSTOM_BARCODE_DIGIT_VALUE_2  1
/*MT6580RF*/ #define L1D_CUSTOM_BARCODE_DIGIT_VALUE_3  2
/*MT6580RF*/ /*--------------------------------------------------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ /* Constants for the second and third index base to be calculated */
/*MT6580RF*/ #if L1D_CUSTOM_GPIO_ENABLE
/*MT6580RF*/ #define L1D_CUSTOM_GPIO_NUMS_IN_CALC      L1D_CUSTOM_GPIO_SET_NUMS
/*MT6580RF*/ #else
/*MT6580RF*/ #define L1D_CUSTOM_GPIO_NUMS_IN_CALC      1
/*MT6580RF*/ #endif
/*MT6580RF*/
/*MT6580RF*/ #if L1D_CUSTOM_ADC_ENABLE
/*MT6580RF*/ #define L1D_CUSTOM_ADC_NUMS_IN_CALC       L1D_CUSTOM_ADC_SET_NUMS
/*MT6580RF*/ #else
/*MT6580RF*/ #define L1D_CUSTOM_ADC_NUMS_IN_CALC       1
/*MT6580RF*/ #endif
/*MT6580RF*/
/*MT6580RF*/ #if L1D_CUSTOM_BARCODE_ENABLE
/*MT6580RF*/ #define L1D_CUSTOM_BARCODE_NUMS_IN_CALC   L1D_CUSTOM_BARCODE_SET_NUMS
/*MT6580RF*/ #else
/*MT6580RF*/ #define L1D_CUSTOM_BARCODE_NUMS_IN_CALC   1
/*MT6580RF*/ #endif
/*MT6580RF*/
/*MT6580RF*/ #define L1D_CUSTOM_TOTAL_SET_NUMS         L1D_CUSTOM_GPIO_NUMS_IN_CALC*L1D_CUSTOM_ADC_NUMS_IN_CALC*L1D_CUSTOM_BARCODE_NUMS_IN_CALC
/*MT6580RF*/
/*MT6580RF*/ /* Customization constant to be used for customer to determine if the AuxADC calibration*/
/*MT6580RF*/ /* is enabled or not                                                                    */
/*MT6580RF*/ #define L1D_CUSTOM_ADC_CALIBRATE_ENABLE   0
#endif

