/*
*********************************************************************************************************
*
*	模块名称 : DSO示波器控制模块
*	文件名称 : bsp_dso_ctrl.c
*	版    本 : V1.0
*	说    明 : 示波器控制
*
*	Copyright (C), 2019-2030, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#ifndef __BSP_DSO_CTRL_H
#define __BSP_DSO_CTRL_H

typedef struct
{
	int VoltDiv;
	int WaveOffset;
	float VoltRMS;
	float VoltAvg;
	float Freq;
	float Duty;
	float VoltMin;
	float VoltMax;
}DSO_CH_T;

typedef struct
{
	DSO_CH_T CH1;
	DSO_CH_T CH2;
	int TimeDiv;
}DSO_T;

AnsiString TimeDivToStr(int div);
AnsiString VoltDivToStr(int _div);

extern DSO_T g_tDSO;

#define TIME_DIV_NUM	22           /* 时间档位个数 */
#define VOLT_DIV_NUM	12           /* 电压档位个数 */
#define FREQ_NUM		17         	/* 采样频率档位 */

#define BUFF_SIZE_NUM  10 			/* 采样深度 */

#define DSO_PACKAGE_SIZE	1024		/* */


extern int TabelTimeDiv[TIME_DIV_NUM];
extern int TabelVoltDiv[VOLT_DIV_NUM];
extern int TabelBufSize[BUFF_SIZE_NUM];
extern int TabelFreq[FREQ_NUM];

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
