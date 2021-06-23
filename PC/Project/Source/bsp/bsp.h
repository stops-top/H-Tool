
/*
*********************************************************************************************************
*
*	模块名称 : 指纹命令模块
*	文件名称 : bsp_finger.h
*	版    本 : V1.0
*	说    明 : 头文件
*
*	Copyright (C), 2015-2016, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/
#ifndef __BSP_H
#define __BSP_H

#include <vcl.h>
#include "string.h"
#include "bsp_user_lib.h"
#include "bsp_timer.h"
#include "bsp_dso_ctrl.h"
#include "bsp_dac_ctrl.h"
#include "bsp_param.h"

#include "stdio.h"

/* Signed integer types  */
#if 0
typedef   char     int8_t;
typedef   signed short    int16_t;
typedef   signed int     int32_t;
typedef   signed long long    int64_t;

/* Unsigned integer types  */
typedef unsigned char     uint8_t;
typedef unsigned short    uint16_t;
typedef unsigned int     uint32_t;
#else
typedef unsigned int     uint32_t;
#endif

#define DISABLE_INT()
#define ENABLE_INT()

#define BUFFER_SIZE  256



void bsp_Idle(void);

void RS485_SendBuf1(uint8_t *_buf, uint8_t _len);
uint8_t comGetChar(uint8_t *_pData);

void bsp_ClearLog(void);
void bsp_AddLog(const char *_log);
AnsiString bsp_GetLog(void);

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/

