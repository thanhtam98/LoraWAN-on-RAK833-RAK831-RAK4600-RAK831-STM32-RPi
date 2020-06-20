#ifndef __PARAM_H__
#define __PARAM_H__

#include <stdio.h>
#include <stdint.h>
#include  "epprom.h"

/**
 *
 *
 *
 * */
/* Salve parameters---*/
#define NODE_HAVE_PARAM_ADR			0
#define NODE_ID_ADR					1
/* Modbus salve parameters---*/
#define NODE_MB_ID_ADR				2
#define NODE_MB_SERCFG_ADR 			3
#define NODE_MB_MODE_ADR			4  //RTU OR ASCII
#define NODE_MB_BAUD_ADR			5
#define NODE_MB_DATABITS_ADR		6
#define NODE_MB_PARTITY_ADR			7
#define NODE_MB_STOPBITS_ADR		8
#define NODE_MB_DEFAULT_LEN			9
//#define NODE_MB_
/**/
#define NODE_LRWAN_BASE 			20

#define NODE_LRWAN_MODE_ADR			NODE_LRWAN_BASE + 0
#define NODE_LRWAN_MODE_LEN			1

#define NODE_LRWAN_DEVEUI_ADR		NODE_LRWAN_MODE_ADR + NODE_LRWAN_MODE_LEN
#define NODE_LRWAN_DEVEUI_LEN		8

#define NODE_LRWAN_APPKEY_ADR		NODE_LRWAN_DEVEUI_ADR + NODE_LRWAN_DEVEUI_LEN
#define NODE_LRWAN_APPKEY_LEN 		16

#define NODE_LRWAN_APPEUI_ADR		NODE_LRWAN_APPKEY_ADR + NODE_LRWAN_APPKEY_LEN
#define NODE_LRWAN_APPEUI_LEN 		16

typedef struct
{
	uint8_t uAdr;
	uint8_t uLen;
} uParam_t;

/*
 *
 * */

#define PARAM_MAX_SIZE 			96
#define PARAM_LOAD_ALL			0xFFFF



extern uint8_t PARAM[EEP_MAX_SIZE];


uint8_t u_mem_get(uint16_t usAdr);
void u_mem_set(uint16_t usAdr, uint8_t uVal);
void v_epr_load(uint16_t usAdr);
void v_epr_save(uint16_t usAdr);

#endif

