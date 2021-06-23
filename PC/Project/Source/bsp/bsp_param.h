
/*
*********************************************************************************************************
*
*	模块名称 : 参数结构
*	文件名称 : bsp_param.h
*	版    本 : V1.0
*	说    明 : 头文件
*
*	Copyright (C), 2015-2016, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/
#ifndef __BSP_PARAM_H
#define __BSP_PARAM_H

//#define APPLICATION_ADDRESS		0x08100000
#define APPLICATION_ADDRESS		0x08020000

/* IO功能选择 */
typedef enum
{
	ES_GPIO_IN  = 0,		/* GPIO 输入， FMC输入 */
	ES_GPIO_OUT = 1,		/* GPIO 输出， FMC输入 */
	ES_FMC_OUT  = 2,		/* GPIO 输入， FMC输出 */

	ES_FMC_NOE	= 3,		/* D8专用，FMC_D8和FMC_NOE并联 */
	ES_FMC_NWE	= 4,		/* D9专用，FMC_D9和FMC_NWE并联 */

	ES_GPIO_UART  = 5,		/* 作为GPIO串口功能 */
	ES_GPIO_CAN = 6,		/* CAN功能 */
}EIO_SELECT_E;

typedef struct
{
	uint8_t CpuID[12];	/* CPU ID */
	uint16_t HardVer;
	uint16_t SoftVer;
	uint8_t Mac[6];
	uint8_t LocalIP[4];
	uint8_t NetMask[4];
	uint8_t GateWay[4];
	uint16_t LocalPort;
	uint8_t SysIP[4];
	uint16_t SysPort;
}PARAM_T;

/* 全局变量 */
typedef struct
{
	uint16_t X15_00;
	uint16_t X31_16;
	uint16_t Y15_00;
	uint16_t Y31_16;

	float CH1Volt;
	float CH2Volt;
	float HighSideVolt;
	float HighSideCurr;
	float TVCCVolt;		/* TVCC实测电压 */
	float TVCCCurr;		/* TVCC实测电压 */
	float NTCRes;		/* NTC电阻 */
	float NTCTemp;		/* NTC温度 */
	float USBPowerVolt;
	float ExtPowerVolt;

	float ADC_CH1Volt;
	float ADC_CH2Volt;
	float ADC_HighSideVolt;
	float ADC_HighSideCurr;
	float ADC_TVCCVolt;		/* TVCC实测电压 */
	float ADC_TVCCCurr;		/* TVCC实测电压 */
	float ADC_NTCRes;		/* NTC电阻 */
	//float NTCTemp;			/* NTC温度 */
	float ADC_USBPowerVolt;
	float ADC_ExtPowerVolt;
}AI_T;

/* 校准参数结构，适用于ADC, DAC */
typedef struct
{
	float x1;
	float y1;
	float x2;
	float y2;
}
AN_CALIB_T;

/* 校准参数结构，多点校准，解决DAC电路非线性不好的问题 */
typedef struct
{
	int16_t x1;
	int16_t y1;
	int16_t x2;
	int16_t y2;
	int16_t x3;
	int16_t y3;
	int16_t x4;
	int16_t y4;
}
AN_CALIB_DAC_T;

/* 校准参数结构，多点校准，解决电流非线性不好的问题 */
typedef struct
{
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;
	float x4;
	float y4;
}
AN_CALIB_ADC_T;

/* 模拟量校准参数 */
typedef struct
{
	uint32_t CalibVer;		/* 校准参数版本. 用于升级 */
	AN_CALIB_T CH1[8];		/* CH1 示波器通道ADC校准参数, 对应8档硬件增益 */
	AN_CALIB_T CH2[8];		/* CH1 示波器通道ADC校准参数, 对应8档硬件增益 */

	AN_CALIB_T LoadVolt;		/* 负载电压校准参数 */
	AN_CALIB_ADC_T LoadCurr[2];		/* 负载电流校准参数，2个量程  */

	AN_CALIB_T TVCCVolt;	/* TVCC监视电压 */
	AN_CALIB_ADC_T TVCCCurr;	/* TVCC电流 */

	AN_CALIB_ADC_T NtcRes;		/* NTC测温接口参考电阻阻值 */

	AN_CALIB_T TVCCSet;		/* TVCC输出设置电压 */

	AN_CALIB_DAC_T Dac10V;		/* DAC电压通道校准参数，正负10V */
	AN_CALIB_DAC_T Dac20mA;		/* DAC电流通道校准参数，20mA */

	AN_CALIB_T USBVolt;			/* USB供电电压 */
	AN_CALIB_T ExtPowerVlot;	/* 外部供电电压 */
}CALIB_T;

/* 模拟量校准参数 */
typedef struct
{
	int ReadOk;
	/* IP参数 */
	int CommInterface;	/* 通信接口：0-以太网，1-WiFi，2-USB */
	AnsiString IPAddr;			/* 目标IP地址 */
	int UDPPort;		/* UDP端口号 */
	int SerialPortNo;		/* 串口号 */
}INI_PARAM_T;

extern CALIB_T g_tCalib;
extern AI_T g_tAI;
extern INI_PARAM_T g_tIniParam;

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/

