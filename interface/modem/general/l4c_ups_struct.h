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
 *	l4c_ups_struct.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for �K.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/



#ifndef _L4C_UPS_STRUCT_H
#define _L4C_UPS_STRUCT_H

#include "kal_general_types.h"
#include "ps_public_struct.h"

#define UPS_KPALIVE_STRING_IPV4_ADDR_LEN	16	// 255.255.255.255 = (3*4)+3 +1(terminating character)= 16
#define UPS_KPALIVE_STRING_IPV6_ADDR_LEN	40	// ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff = (4*8)+7 +1(terminating character) = 40
#define UPS_KPALIVE_STRING_PORT_LEN			6

typedef enum  {
    UPS_KPALIVE_REQ_IPTYPE_INVALID,
    UPS_KPALIVE_REQ_IPTYPE_IPV4,
    UPS_KPALIVE_REQ_IPTYPE_IPV6
} ups_kpalive_req_ip_type_e;

typedef struct l4c_ups_kpalive_activate_req_struct {
    LOCAL_PARA_HDR
	kal_uint8 				src_id;
    //ups_kpalive_at_req_type_e     req_type; // meant for sending query activate and deactivate in same ILM in LR9 design, non needed in WR8 as different ILM maybe used for activate and deactivate
    ups_kpalive_req_ip_type_e     ip_type;
    kal_uint8              	cid;
    kal_char                src_ipv4_addr[UPS_KPALIVE_STRING_IPV4_ADDR_LEN];
    kal_char                dst_ipv4_addr[UPS_KPALIVE_STRING_IPV4_ADDR_LEN];
    kal_char                src_ipv6_addr[UPS_KPALIVE_STRING_IPV6_ADDR_LEN];
    kal_char                dst_ipv6_addr[UPS_KPALIVE_STRING_IPV6_ADDR_LEN];
    kal_uint8               src_port[UPS_KPALIVE_STRING_PORT_LEN];
    kal_uint8               dst_port[UPS_KPALIVE_STRING_PORT_LEN];
    //kal_uint16              idle_time;                              /**< in sec */	  		// used mainly for TCP
    kal_uint16              probe_interval;                         /**< in sec */
    //kal_uint8               retry_cnt;                              /**< retry count */		// used mainly for TCP
    //kal_uint8               conn_id;                                /**< for disable req */
    kal_bool                parsing_result;
} l4c_ups_kpalive_activate_req_struct;

/*
 * Local parameter structure for MSG_ID_L4C_UPS_KPALIVE_ACTIVATE_CNF.
 */
typedef struct {
    LOCAL_PARA_HDR
	kal_uint8 		src_id;
    kal_bool        result;
    //kal_bool        is_ap_disable_rsp; /**< ap requested to disable keep-alive */
    kal_uint8       conn_id;
    kal_uint8       status;
} l4c_ups_kpalive_activate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
	kal_uint8 		src_id;
    kal_uint8       conn_id;
    kal_bool        parsing_result;
} l4c_ups_kpalive_deactivate_req_struct;

typedef struct {
    LOCAL_PARA_HDR
	kal_uint8 		src_id;
    kal_bool        result;
    kal_uint8       conn_id;
    kal_uint8       status;
} l4c_ups_kpalive_deactivate_cnf_struct;


#endif /* l4c_ups_struct.h*/


