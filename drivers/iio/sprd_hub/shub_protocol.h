/*
 * File:shub_protocol.h
 * Author:bao.yue@spreadtrum.com
 * Created:2015-10-21
 * Description:Spreadtrum Sensor Hub Driver protocol header file
 *
 * Copyright (C) 2015 Spreadtrum Communications Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 */

#ifndef SHUB_PROTOCOL_INCLUDE_H
#define SHUB_PROTOCOL_INCLUDE_H

/* The Data format between the HOST and  device
*------------------------------------------------------
*|Magic Number| Type   |Subtype|Length   | CRC   |  DATA |
*|~~~~        | 1 Byte |1 Byte | 2 Byte | 2 Byte|   n bytes  |
*------------------------------------------------------
*/

/* define encode and decode */
#define  SHUB_MAGIC_NUMBER_LEN   (4)
#define  SHUB_MAX_DATA_CRC       (2)
#define  SHUB_MAGIC_NUMBER       (0x7E)
#define  SHUB_MAX_HEAD_LEN       (10)
#define SHUB_MEMDUMP_DATA_SUBTYPE              (0x0D)
#define SHUB_MEMDUMP_CODE_SUBTYPE              (0x0E)

#define SHUB_GET_HIGH_BYTE(D) (unsigned char)((D) >> 8)
#define SHUB_GET_LOW_BYTE(D)  (unsigned char)(D)
#define TRUE 1
#define FALSE 0

#define  SHUB_FLASH_BLOCK_SIZE  4096
#define  MAX_MSG_BUFF_SIZE                        (1536)
#define  MAX_RETRANSFER_TIMES			   (1)
#define  RESPONSE_WAIT_TIMEOUT_MS		   (300)
#define  THIRDALGO_START_SUBTYPE                0xC2
#define  THIRDALGO_END_SUBTYPE                  0xFE

enum shub_subtype_id {
	/* Android define */
	SHUB_SET_ENABLE_SUBTYPE,
	SHUB_SET_DISABLE_SUBTYPE,
	SHUB_SET_BATCH_SUBTYPE,
	SHUB_SET_FLUSH_SUBTYPE,
	/* pls add other android define here */
	/* Sprd define */
	SHUB_DATA_SUBTYPE,
	SHUB_LOG_SUBTYPE,
	SHUB_DOWNLOAD_OPCODE_SUBTYPE,
	SHUB_DOWNLOAD_CALIBRATION_SUBTYPE,
	SHUB_RESPONSE_SUBTYPE,
	/* read command begin */
	SHUB_GET_SENSORINFO_SUBTYPE,
	SHUB_SEND_MAG_CALIBRATION_FLAG,
	SHUB_SEND_DEBUG_DATA,
	SHUB_GET_MAG_OFFSET,
	/* other sprd define */
	/* 3rdAlgo define */
	SHUB_SET_CALIBRATION_DATA_SUBTYPE        = THIRDALGO_START_SUBTYPE,
	SHUB_SET_CALIBRATION_CMD_SUBTYPE,
	SHUB_SET_TIMESYNC_SUBTYPE,
	SHUB_SET_HOST_STATUS_SUBTYPE,
	SHUB_GET_CALIBRATION_DATA_SUBTYPE,
	SHUB_GET_ENABLE_LIST_SUBTYPE,
	SHUB_GET_ACCELERATION_RAWDATA_SUBTYPE,
	SHUB_GET_MAGNETIC_RAWDATA_SUBTYPE,
	SHUB_GET_GYROSCOPE_RAWDATA_SUBTYPE,
	SHUB_GET_LIGHT_RAWDATA_SUBTYPE,
	SHUB_GET_PROXIMITY_RAWDATA_SUBTYPE,
	SHUB_GET_FWVERSION_SUBTYPE,
	SHUB_CWM_END_SUBTYPE                   = THIRDALGO_END_SUBTYPE,
	SHUB_END_SUBTYPE,
};

enum cmd_resp_status {
	RESPONSE_SUCCESS = 0,
	RESPONSE_FAIL = 1,
	RESPONSE_TIMEOUT = 2,
};

/* define encode and decode struct union  begin */
struct cmd_data {
	unsigned char  type;
	unsigned char  subtype;
	unsigned short length;
	unsigned char  buff[MAX_MSG_BUFF_SIZE];
};

enum shub_recv_state {
	SHUB_RECV_SEARCH_FLAG,
	SHUB_RECV_COLLECT_HEAD,
	SHUB_RECV_DATA,
	SHUB_RECV_Complete,
	SHUB_RECV_ERROR,
};

struct shub_data_processor {
	enum shub_recv_state state;
	unsigned short head_size; /* receive head len */
	unsigned short received_data_len;
	unsigned short data_len;
	unsigned short error_num;
	unsigned char cur_header[SHUB_MAX_HEAD_LEN];
	struct cmd_data  cmd_data;
};
/* define encode and decode struct union  end */

struct sent_cmd {
	unsigned char  type;
	unsigned char  sub_type;
	bool condition;
	enum cmd_resp_status status;
};

extern struct shub_data_processor shub_stream_processor;
extern struct shub_data_processor shub_stream_processor_nwu;
/*function define */
void  shub_init_parse_packet(struct shub_data_processor *stream);
void shub_fill_head(struct cmd_data *in_data, unsigned char *out_data);
int shub_encode_one_packet(
			struct cmd_data *in_data,
			unsigned char *out_data,
			unsigned short out_len);
int shub_parse_one_packet(
	struct shub_data_processor *stream,
	unsigned char *data,
	unsigned short len);
extern void  shub_dispatch(struct cmd_data *packet);
extern  void debuginfor(void *src, int len);
#endif
