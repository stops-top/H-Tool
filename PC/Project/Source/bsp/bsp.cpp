/*
*********************************************************************************************************
*
*	模块名称 : BSP模块(For STM32F4XX)
*	文件名称 : bsp.c
*	版    本 : V1.0
*	说    明 : 这是硬件底层驱动程序模块的主文件。主要提供 bsp_Init()函数供主程序调用。主程序的每个c文件可以在开
*			  头	添加 #include "bsp.h" 来包含所有的外设驱动模块。
*
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2013-03-01 armfly  正式发布
*
*	Copyright (C), 2013-2014, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#include "UnitMain.h"	// 包含C++ 的窗体 串口控件
#include "bsp.h"

char g_DebugLogText[64 * 1024];

void bsp_ClearLog(void)
{
	g_DebugLogText[0] = 0;
}

AnsiString bsp_GetLog(void)
{
	return (AnsiString)g_DebugLogText;
}

void bsp_AddLog(const char *_log)
{
	int len;
	static uint8_t first = 0;
	static uint32_t last_time = 0;
	static uint32_t first_time = 0;
	if (first == 0)
	{
		first = 1;

		bsp_ClearLog();
		first_time = bsp_GetRunTime();
		sprintf(g_DebugLogText, "%dms\r\n", last_time);
	}

	len = strlen(g_DebugLogText);
	if (len + 1024 < sizeof(g_DebugLogText))
	{
		uint32_t time1;

		time1 = bsp_GetRunTime();
		sprintf(&g_DebugLogText[len], " --(%dms)\r\n%dms : %s\r\n", time1 - last_time, time1 - first_time, _log);
		last_time = time1;
	}

}

/*
*********************************************************************************************************
*	函 数 名: bsp_Init
*	功能说明: 初始化硬件设备。只需要调用一次。该函数配置CPU寄存器和外设的寄存器并初始化一些全局变量。
*			 全局变量。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_Init(void)
{
	 bsp_ClearLog();
}

/*
*********************************************************************************************************
*	函 数 名: bsp_RunPer10ms
*	功能说明: 该函数每隔10ms被Systick中断调用1次。详见 bsp_timer.c的定时中断服务程序。一些处理时间要求不严格的
*			任务可以放在此函数。比如：按键扫描、蜂鸣器鸣叫控制等。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_RunPer10ms(void)
{

}

/*
*********************************************************************************************************
*	函 数 名: bsp_RunPer1ms
*	功能说明: 该函数每隔1ms被Systick中断调用1次。详见 bsp_timer.c的定时中断服务程序。一些需要周期性处理的事务
*			 可以放在此函数。比如：触摸坐标扫描。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_RunPer1ms(void)
{

}

/*
*********************************************************************************************************
*	函 数 名: bsp_Idle
*	功能说明: 空闲时执行的函数。一般主程序在for和while循环程序体中需要插入 CPU_IDLE() 宏来调用本函数。
*			 本函数缺省为空操作。用户可以添加喂狗、设置CPU进入休眠模式的功能。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
//extern void MODBUS_Poll(void);
void bsp_Idle(void)
{
	/* --- 喂狗 */

	/* --- 让CPU进入休眠，由Systick定时中断唤醒或者其他中断唤醒 */

	/* 例如 emWin 图形库，可以插入图形库需要的轮询函数 */
	//GUI_Exec();

	//GT811_Scan();

	//MODBUS_Poll();

	//Application->ProcessMessages();
	//if(

}

/*
*********************************************************************************************************
*	函 数 名: comSendBuf
*	功能说明: 发送串口数据
*	形    参: _port : 串口号
*			  _buf : 待发送的数据缓冲区
*			  _len : 数据长度
*	返 回 值: len ：应答数据长度
*			  0 ：指纹录入失败
*********************************************************************************************************
*/
void RS485_SendBuf1(uint8_t *_buf, uint8_t _len)
{
//	AnsiString s;
//	uint16_t  i;
//	if (Form1->YbCommDevice1->Active == true)
//	{
//		Form1->YbCommDevice1->Write((const void *)_buf, _len);
//	}
}

// 从指定串口读取1个字节
uint8_t comGetChar(uint8_t *_pData)
{
//	uint8_t buf[10]; //收到的字节数不会超过串口缓存的容量, 所以分配一个缓存容量相同的Buf
//	int n;
//
//	if (Form1->YbCommDevice1->Active == false)
//		return 0;
//
//	n = Form1->YbCommDevice1->Read(buf, 1); //收 1 个字节
//	if (n == 1)
//	{
//		*_pData = buf[0];
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
	return 0;
}




/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
