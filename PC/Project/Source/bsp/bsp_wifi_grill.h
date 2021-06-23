/*
*********************************************************************************************************
*
*	模块名称 : 烤炉状态的常量定义（用于解码）
*	文件名称 : bsp_wifi_grill.h
*	版    本 : V1.2
*	说    明 : 头文件
*
*********************************************************************************************************
*/

#ifndef __BSP_WIFI_GRILL_H
#define __BSP_WIFI_GRILL_H

enum POWER_MODE_EN
{
	POWER_MODE_OFF = 0,		/* 关闭模式 */
	POWER_MODE_ON,
	POWER_MODE_FAN,
	POWER_MODE_REMAIN,
};

// 0:待机  1:成功   2：点火之0步，3：点火之1步， 4:点火之2步，5:点火之3步，6：点火失败；7,吹风之中
enum FIRE_STATE_EN
{
	FIRE_STATE_OFF = 0,
	FIRE_STATE_ON,
	FIRE_STATE_STEP_0,
	FIRE_STATE_STEP_1,
	FIRE_STATE_STEP_2,
	FIRE_STATE_STEP_3,
	FIRE_STATE_FAIL,
	FIRE_STATE_FAN,
};

enum FIRE_STATE_EN2
{
	FIRE2_STATE_DEFAULT = 0,
	FIRE2_STATE_OFF,
	FIRE2_STATE_STARTUP,
	FIRE2_STATE_RUNNING,
	FIRE2_STATE_COOLDOWN,
	FIRE2_STATE_FAIL,
};


#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
