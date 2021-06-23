//#include "lauxlib.h"
//#include "lualib.h"
//#include "time.h"
#include "bsp.h"
#include "lua_if.h"

//#include "elf_file.h"
//#include "file_lib.h"
//#include "prog_if.h"
//#include "target_reset.h"
//#include "target_config.h"
//#include "swd_host.h"
//#include "swd_host_multi.h"
//#include "Systick_Handler.h"
//#include "main.h"
//#include "target_family.h"
//#include "stm8_flash.h"
//#include "stm8_swim.h"
//#include "swd_flash.h"
//#include "SW_DP_Multi.h"

/* 为了避免和DAP驱动中的函数混淆，本模块函数名前缀用 h7swd */

static int h7swd_Init(lua_State* L);
static int h7swd_ReadID(lua_State* L);
static int h7swd_WriteMemory(lua_State* L);
static int h7swd_ReadMemory(lua_State* L);

static int h7swd_Write32(lua_State* L);
static int h7swd_Read32(lua_State* L);
static int h7swd_Write16(lua_State* L);
static int h7swd_Read16(lua_State* L);
static int h7swd_Write8(lua_State* L);
static int h7swd_Read8(lua_State* L);

static int h7_LoadAlgoFile(lua_State* L);
static int h7_ProgFile(lua_State* L);
static int h7_ProgBuf(lua_State* L);
static int h7_ProgBuf_OB(lua_State* L);
static int h7_Read_OptionBytes(lua_State* L);
static int h7_reset(lua_State* L);
static int h7_DetectIC(lua_State* L);
static int h7_PrintText(lua_State* L);
static int h7_EraseChip(lua_State* L);
static int h7_EraseSector(lua_State* L);

static int h7_Read_ProductSN(lua_State* L);
static int h7_Write_ProductSN(lua_State* L);
static int h7_ReloadLuaVar(lua_State* L);
static int h7_ReadCVar(lua_State* L);

static int h7swd_ReadExtID(lua_State* L);


/*
*********************************************************************************************************
*    函 数 名: lua_swd_RegisterFun
*    功能说明: 注册lua C语言接口函数
*    形    参: 无
*    返 回 值: 无
*********************************************************************************************************
*/
void lua_swd_RegisterFun(void)
{
    lua_register(g_Lua, "pg_init", h7swd_Init);    
    lua_register(g_Lua, "pg_get_chip_id", h7swd_ReadID);    
    lua_register(g_Lua, "pg_write_mem", h7swd_WriteMemory); 	
    lua_register(g_Lua, "pg_read_mem", h7swd_ReadMemory);  

    lua_register(g_Lua, "pg_write32", h7swd_Write32);    
    lua_register(g_Lua, "pg_read32", h7swd_Read32);  
    lua_register(g_Lua, "pg_write16", h7swd_Write16);    
    lua_register(g_Lua, "pg_read16", h7swd_Read16);  
    lua_register(g_Lua, "pg_write8", h7swd_Write8);    
    lua_register(g_Lua, "pg_read8", h7swd_Read8);
    
    lua_register(g_Lua, "pg_get_ext_id", h7swd_ReadExtID);     
        
	lua_register(g_Lua, "pg_load_algo_file", h7_LoadAlgoFile);
	lua_register(g_Lua, "pg_prog_file", h7_ProgFile);
	lua_register(g_Lua, "pg_prog_buf", h7_ProgBuf);
	lua_register(g_Lua, "pg_prog_buf_ob", h7_ProgBuf_OB);
	lua_register(g_Lua, "pg_read_ob", h7_Read_OptionBytes);
	lua_register(g_Lua, "pg_reset", h7_reset);
    lua_register(g_Lua, "pg_detect_ic", h7_DetectIC);
    lua_register(g_Lua, "pg_erase_chip", h7_EraseChip);   
    lua_register(g_Lua, "pg_erase_sector", h7_EraseSector);       
    
    lua_register(g_Lua, "pg_print_text", h7_PrintText);
    lua_register(g_Lua, "pg_read_sn", h7_Read_ProductSN);
    lua_register(g_Lua, "pg_write_sn", h7_Write_ProductSN);
    
    lua_register(g_Lua, "pg_reload_var", h7_ReloadLuaVar);
    
    lua_register(g_Lua, "pg_read_c_var", h7_ReadCVar);
}

/*
*********************************************************************************************************
*    函 数 名: h7_ReloadLuaVar
*    功能说明: lua通知程序更新变量
*    形    参: 无
*    返 回 值: 无
*********************************************************************************************************
*/
extern uint8_t PG_LuaUidSnUsr(void);
static int h7_ReloadLuaVar(lua_State* L)
{
    return 0;
}

/*
*********************************************************************************************************
*    函 数 名: h7_ReadCVar
*    功能说明: lua读取c全局变量
*    形    参: 无
*    返 回 值: 无
*********************************************************************************************************
*/
static int h7_ReadCVar(lua_State* L)
{
	lua_pushnumber(L, 0);
    return 1;
}
/*
*********************************************************************************************************
*    函 数 名: h7swd_Init
*    功能说明: 初始化swd
*    形    参: 无
*    返 回 值: 无
*********************************************************************************************************
*/
static int h7swd_Init(lua_State* L)
{
	return 0;
}

/*
*********************************************************************************************************
*    函 数 名: h7swd_ReadID
*    功能说明: 读芯片ID
*    形    参: 无
*    返 回 值: 无
*********************************************************************************************************
*/
static int h7swd_ReadID(lua_State* L)
{
	lua_pushnumber(L, 0);
	return 1;
}

/*
*********************************************************************************************************
*    函 数 名: h7swd_WriteMemory
*    功能说明: 写CPU内存（或寄存器）
*    形    参: addr : 目标地址
*                data : 数据缓冲区，含长度
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7swd_WriteMemory(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
    return 1;
}

/*
*********************************************************************************************************
*    函 数 名: h7swd_ReadMemory
*    功能说明: 读CPU内存（或寄存器）
*    形    参: addr : 目标地址
*                data : 数据缓冲区，含长度
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7swd_ReadMemory(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 长度溢出，出错 */
	return 1;
}

/*
*********************************************************************************************************
*    函 数 名: h7swd_Write32
*    功能说明: 写CPU内存（或寄存器）
*    形    参: addr : 目标地址
*              data : 数据
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7swd_Write32(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
	return 1;
}

/*
*********************************************************************************************************
*    函 数 名: h7swd_Write16
*    功能说明: 写CPU内存（或寄存器）
*    形    参: addr : 目标地址
*              data : 数据
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7swd_Write16(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
	return 1;
}

/*
*********************************************************************************************************
*    函 数 名: h7swd_Write8
*    功能说明: 写CPU内存（或寄存器）
*    形    参: addr : 目标地址
*              data : 数据
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7swd_Write8(lua_State* L)
{
   lua_pushnumber(L, 0);    /* 出错 */
	return 1;
}

/*
*********************************************************************************************************
*    函 数 名: h7swd_Read32
*    功能说明: 读CPU内存（或寄存器）
*    形    参: addr : 目标地址
*              data : 数据缓冲区，含长度
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7swd_Read32(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
	lua_pushnumber(L, 0);    /* 出错 */
	return 2;
}

/*
*********************************************************************************************************
*    函 数 名: h7swd_Read16
*    功能说明: 读CPU内存（或寄存器）
*    形    参: addr : 目标地址
*              data : 数据缓冲区，含长度
*    返 回 值: 读回的数据。出错也返回0
*********************************************************************************************************
*/
static int h7swd_Read16(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
	lua_pushnumber(L, 0);    /* 出错 */
	return 2;
}

/*
*********************************************************************************************************
*    函 数 名: h7swd_Read8
*    功能说明: 读CPU内存（或寄存器）
*    形    参: addr : 目标地址
*              data : 数据缓冲区，含长度
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7swd_Read8(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
	lua_pushnumber(L, 0);    /* 出错 */
	return 2;
}

/*
*********************************************************************************************************
*    函 数 名: h7_LoadAlgoFile
*    功能说明: 装载算法文件
*    形    参: file_path 算法文件路径，是相对路径
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7_LoadAlgoFile(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
	return 1;
}

/*
*********************************************************************************************************
*    函 数 名: h7_ProgFile
*    功能说明: 开始编程，从文件读取数据
*    形    参: file_path 数据文件名称, 目标flash地址
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7_ProgFile(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
	return 1;
}

/*
*********************************************************************************************************
*    函 数 名: h7_reset
*    功能说明: 执行硬件复位
*    形    参: 无
*    返 回 值: 无
*********************************************************************************************************
*/
extern void MUL_swd_set_target_reset(uint8_t asserted);
static int h7_reset(lua_State* L)
{
    return 0;
}

/*
*********************************************************************************************************
*    函 数 名: h7_DetectIC
*    功能说明: 检测CPU ID
*    形    参: 无
*    返 回 值: 0 失败   > 0 成功
*********************************************************************************************************
*/
static int h7_DetectIC(lua_State* L)
{
    lua_pushnumber(L, -1);          /* 失败 */
    return 1;
}

/*
*********************************************************************************************************
*    函 数 名: h7_PrintText
*    功能说明: 在LCD显示一串文本
*    形    参: 无
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7_PrintText(lua_State* L)
{
    return 0;
}

/*
*********************************************************************************************************
*    函 数 名: h7_ProgBuf
*    功能说明: 开始编程，从新参读入数据。
*    形    参: Flash地址
*			   数据
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7_ProgBuf(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
    return 1;    
}

/*
*********************************************************************************************************
*    函 数 名: h7_ProgBuf_OB
*    功能说明: 开始编程，从新参读入数据。 用于option bytes
*    形    参: Flash地址
*			   数据
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7_ProgBuf_OB(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
    return 1;    
}

/*
*********************************************************************************************************
*    函 数 名: h7_Read_OptionBytes
*    功能说明: 根据地址列表，读取 option bytes
*    形    参: Flash地址
*			   数据
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
#define MUL_BUF_STEP    (LUA_READ_LEN_MAX / 4)        /* s_lua_read_buf 平分4组存放结果 */
static int h7_Read_OptionBytes(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
	lua_pushnumber(L, 0);    /* 出错 */
	return 2;
}

/*
*********************************************************************************************************
*    函 数 名: h7_EraseChip
*    功能说明: 擦除全片，用于OPTION BYTES编程，去除读保护。
*    形    参: Flash地址
*			   数据
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7_EraseChip(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
    return 1;    
}

/*
*********************************************************************************************************
*    函 数 名: h7_EraseSector
*    功能说明: 擦除扇区
*    形    参: Flash地址
*			   数据
*    返 回 值: 0 失败   1 成功
*********************************************************************************************************
*/
static int h7_EraseSector(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
    return 1;    
}

/*
*********************************************************************************************************
*    函 数 名: h7_Read_ProductSN
*    功能说明: 读产品序号
*    形    参: 无
*    返 回 值: 序号（整数）
*********************************************************************************************************
*/
static int h7_Read_ProductSN(lua_State* L)
{
	lua_pushnumber(L, 0);
    return 1;    
}

/*
*********************************************************************************************************
*    函 数 名: h7_Write_ProductSN
*    功能说明: 写产品序号
*    形    参: 无
*    返 回 值: 序号（整数）
*********************************************************************************************************
*/
static int h7_Write_ProductSN(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
	return 1;
}

/*
*********************************************************************************************************
*    函 数 名: h7swd_ReadExtID
*    功能说明: 读CPU外部芯片的ID
*    形    参: 无
*    返 回 值: 无
*********************************************************************************************************
*/
static int h7swd_ReadExtID(lua_State* L)
{
	lua_pushnumber(L, 0);    /* 出错 */
    return 1;
}


/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
