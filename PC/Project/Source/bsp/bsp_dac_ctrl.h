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

#ifndef __BSP_DAC_CTRL_H
#define __BSP_DAC_CTRL_H

typedef enum
{
	DAC_WAVE_NO = 0,
	DAC_WAVE_SIN,
	DAC_WAVE_SQUARE,
	DAC_WAVE_TRI
}DAC_WAVE_TYPE_E;

/* 波形控制结构 */
typedef struct
{
	uint8_t Type;
	uint8_t VoltRange;
	int16_t VoltMax;
	int16_t VoltMin;
	uint32_t Freq;
	uint16_t Duty;
	uint32_t CycleCount;
	uint32_t CycleSetting;
	uint8_t Run;
}DAC_WAVE_T;

void dac1_SetWave(DAC_WAVE_T *_pDac);
void dac1_SetCurr(int _value);
void dac1_SetVolt(int _value);

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
