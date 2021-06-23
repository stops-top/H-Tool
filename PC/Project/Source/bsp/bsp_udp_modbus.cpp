/*
*********************************************************************************************************
*
*	模块名称 : UDP MODBUS驱动程序
*	文件名称 : bsp_udp_modbus.c
*	版    本 : V1.0
*	说    明 : MODBUS地址域的字段由6字节MAC地址替代  支持 03H, 06H, 10H指令。 返回数据略有变化，带寄存器地址和
*				数量
*
*	Copyright (C), 2014-2015, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#include "bsp.h"
#include "bsp_udp_modbus.h"
#include "UnitMain.h"
#include "UnitThread.h"
#include "UnitSet.h"

AnsiString g_udp_ip = "255.255.255.255";
int g_udp_port = 30010;

uint8_t MAC_FF[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
//uint16_t g_RegAddr;
//uint16_t g_RegNum;
//uint8_t g_RxOk;

MODBUS_CMD_T g_tCmd;
uint8_t s_TxBuf[TX_BUF_SIZE];
uint16_t s_TxLen;

/*
*********************************************************************************************************
*	函 数 名: H7_WriteRegisters
*	功能说明: 写寄存器。发送06指令写单个寄存器（不等待应答）
*	形    参: _reg_addr：寄存器地址
			  _reg_value：寄存器值
*	返 回 值: 无
*********************************************************************************************************
*/
void H7_WriteRegister(uint16_t _reg_addr, uint16_t _reg_value)
{
	g_tCmd.UserRegAddr = _reg_addr;
	g_tCmd.UserRegValue = _reg_value;
	g_tCmd.UserCmdStatus = CMDS_SEND_06H;
	g_tCmd.UserReq = 1;
	g_tCmd.CmdStatus = 0;
}

/*
*********************************************************************************************************
*	函 数 名: H7_WriteMutiRegister
*	功能说明: 写多个寄存器
*	形    参:  _reg_addr：寄存器地址
			 _reg_num：寄存器个数
			 _buf : 寄存器值数组，每个寄存器2字节
*	返 回 值: 无
*********************************************************************************************************
*/
void H7_WriteMutiRegisters(uint16_t _reg_addr, uint16_t _reg_num, uint16_t *_buf)
{
	uint16_t i;

	g_tCmd.UserRegAddr = _reg_addr;

	for (i = 0; i < _reg_num; i++)
	{
		g_tCmd.UserRegValueBuf[i] = _buf[i];
	}
	g_tCmd.UserRegNum = _reg_num;
	g_tCmd.UserCmdStatus = CMDS_SEND_10H;
	g_tCmd.UserReq = 1;
}

/*
*********************************************************************************************************
*	函 数 名: H7_ReadRegisters
*	功能说明: 读寄存器。发送03指令写单个寄存器（不等待应答）
*	形    参: _reg_addr：寄存器地址
			  _reg_num：寄存器个数
*	返 回 值: 无
*********************************************************************************************************
*/
void H7_ReadRegisters(uint16_t _reg_addr, uint16_t _reg_num)
{
	g_tCmd.UserRegAddr = _reg_addr;
	g_tCmd.UserRegNum = _reg_num;
	g_tCmd.UserCmdStatus = CMDS_SEND_03H;
	g_tCmd.UserReq = 1;
}

/*
*********************************************************************************************************
*	函 数 名: H7_WriteRelay
*	功能说明: 写多个输出寄存器（控制D0-D7)输出
*	形    参:  _reg_addr：寄存器地址
			   _reg_num：寄存器个数. 不是字节个数
			   _buf : 寄存器值数组， 每个字节表示8个IO。
*	返 回 值: 无
*********************************************************************************************************
*/
void H7_WriteRelay(uint16_t _reg_addr, uint16_t _reg_num, uint8_t *_buf)
{
	uint16_t i;
	uint8_t bytes;

	bytes = (_reg_num + 7) / 8;
	g_tCmd.UserRegAddr = _reg_addr;

	for (i = 0; i < bytes; i++)
	{
		g_tCmd.UserRegValueBuf[i] = _buf[i];
	}
	g_tCmd.UserRegNum = _reg_num;
	g_tCmd.UserCmdStatus = CMDS_SEND_0FH;
	g_tCmd.UserReq = 1;
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
void Series_SendBuf(uint8_t *_buf, uint16_t _len)
{
	AnsiString s;
	uint16_t  i;

	//TFT485_ClearRxFifo();
	try
	{
		if (Form1->YbCommDevice1->Active == true)
		{
			Form1->YbCommDevice1->Write((const void *)_buf, _len);
		}
	}
	catch (Exception &e)
	{
	}
}

// 从指定串口读取1个字节
uint8_t comGetChar(uint8_t *_pData)
{
	uint8_t buf[10]; //收到的字节数不会超过串口缓存的容量, 所以分配一个缓存容量相同的Buf
	int n;

	try
	{
		if (Form1->YbCommDevice1->Active == false)
			return 0;

		n = Form1->YbCommDevice1->Read(buf, 1); //收 1 个字节
		if (n == 1)
		{
			*_pData = buf[0];
			return 1;
		}
		else
		{
			return 0;
		}
	}
	catch (Exception &e)
	{
		return 0;
	}
}


/*
*********************************************************************************************************
*	函 数 名: udp_SendBuf
*	功能说明: 发送数据。 通信线程以外调用
*	形    参: _buf : 缓冲区;    _len : 数据长度
*	返 回 值: 无
*********************************************************************************************************
*/
static void udp_SendBuf(uint8_t *_buf, uint16_t _len)
{
	if (FormSet->EditScanPort == NULL)
	{
		return;
	}

	// 发送到UDP服务端
	if (g_tIniParam.CommInterface == 1)     /* USB虚拟串口 */
	{
		Series_SendBuf(_buf,  _len);
	}
	else       /* 网口和WIFI , TCP UDP协议 */
	{
		TByteDynArray buf;

		g_udp_port = StrToInt(FormSet->EditScanPort->Text);

		buf = RawToBytes(_buf, _len);
		FormTcp->UDP1->SendBuffer(FormSet->EditH7IPAddr->Text, g_udp_port, buf);

		//Form1->Memo_AddLine(_buf,  _len);
	}
}

/*
*********************************************************************************************************
*	函 数 名: udp_SendBuf_mac
*	功能说明: 发送数据
*	形    参: _buf : 缓冲区;    _len : 数据长度
*	返 回 值: 无
*********************************************************************************************************
*/
static void udp_SendBuf_mac(uint8_t *_buf, uint16_t _len)
{
	// 发送到UDP服务端
	{
		TByteDynArray buf;

		g_udp_port = StrToInt(FormSet->EditScanPort->Text);

		buf = RawToBytes(_buf, _len);
		//Form1->UDP1->SendBuffer("255.255.255.255", g_udp_port, buf);
		//Form1->UDP1->SendBuffer("192.168.1.211", g_udp_port, buf);
		Form1->Memo_AddLine(_buf,  _len);

		FormTcp->UDP1->Broadcast(buf,  g_udp_port,   "255.255.255.255");
	}
}

/*
*********************************************************************************************************
*	函 数 名: MODBUS_Send06H
*	功能说明: 发送06指令写单个寄存器（不等待应答）
*	形    参: _addr : 从机的485地址
			  _reg_addr：寄存器地址
			 _reg_value：寄存器个数
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send06H(uint16_t _reg_addr, uint16_t _reg_value)
{
	uint8_t txbuf[32];
	uint8_t pos = 0;
	uint16_t crc;

	g_tCmd.RegAddr = _reg_addr;
	g_tCmd.RegValue =  _reg_value;
	g_tCmd.RxOk = 0;

	//memcpy(txbuf,  _mac, 6);
	pos = 0;
	txbuf[pos++] = 1;
	txbuf[pos++] = 0x06;			/* 功能码 10*/
	txbuf[pos++] = _reg_addr >> 8;			/* 地址寄存器 ：00 70 */
	txbuf[pos++] = _reg_addr;
	txbuf[pos++] = _reg_value >> 8;
	txbuf[pos++] = _reg_value;
	crc = CRC16_Modbus(txbuf, pos);
	txbuf[pos++] = crc >> 8;
	txbuf[pos++] = crc;
	udp_SendBuf(txbuf,  pos);
}

/*
*********************************************************************************************************
*	函 数 名: MODBUS_Send06H
*	功能说明: 发送06指令写单个寄存器（不等待应答）
*	形    参: _addr : 从机的485地址
			  _reg_addr：寄存器地址
			 _reg_value：寄存器个数
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send06H_MAC(uint8_t *_mac, uint16_t _reg_addr, uint16_t _reg_value)
{
	uint8_t txbuf[32];
	uint8_t pos = 0;
	uint16_t crc;

	g_tCmd.RegAddr = _reg_addr;
	g_tCmd.RegValue =  _reg_value;
	g_tCmd.RxOk = 0;

	memcpy(txbuf,  _mac, 6);
	pos = 6;
	txbuf[pos++] = 1;
	txbuf[pos++] = 0x06;			/* 功能码 10*/
	txbuf[pos++] = _reg_addr >> 8;			/* 地址寄存器 ：00 70 */
	txbuf[pos++] = _reg_addr;
	txbuf[pos++] = _reg_value >> 8;
	txbuf[pos++] = _reg_value;
	crc = CRC16_Modbus(&txbuf[6], pos - 6);
	txbuf[pos++] = crc >> 8;
	txbuf[pos++] = crc;
	udp_SendBuf_mac(txbuf,  pos);
}

/*
*********************************************************************************************************
*	函 数 名: MODBUS_Send10H
*	功能说明: 发送03指令（读数字输入）（不等待应答）
*	形    参: _addr : 从机的485地址
			  _reg_addr：寄存器地址
			 _reg_num：寄存器个数
			 _buf : 寄存器值数组，每个寄存器2字节
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send10H(uint16_t _reg_addr, uint16_t _reg_num, uint16_t *_buf)
{
	uint8_t txbuf[2048];
	uint16_t pos = 0;
	int i;
	uint16_t crc;

	g_tCmd.RegAddr = _reg_addr;
	g_tCmd.RegNum =  _reg_num;
	for (i = 0; i < _reg_num; i++)
	{
		g_tCmd.RegValueBuf[i] = _buf[i];
	}
	g_tCmd.RxOk = 0;

	pos = 0;
	txbuf[pos++] = 1;
	txbuf[pos++] = 0x10;			/* 功能码 10*/
	txbuf[pos++] = _reg_addr >> 8;			/* 地址寄存器 ：00 70 */
	txbuf[pos++] = _reg_addr;
	txbuf[pos++] = _reg_num >> 8;
	txbuf[pos++] = _reg_num;
	txbuf[pos++] = _reg_num * 2;    /* 字节数 */
	for (i = 0; i < _reg_num; i++)
	{
		txbuf[pos++] = _buf[i] >> 8;
		txbuf[pos++] = _buf[i];
	}
	crc = CRC16_Modbus(txbuf, pos);
	txbuf[pos++] = crc >> 8;
	txbuf[pos++] = crc;
	udp_SendBuf(txbuf,  pos);
}

/*
*********************************************************************************************************
*	函 数 名: udp_Send10H_MAC
*	功能说明: 发送10指令,
*	形    参: _addr : 从机的485地址
			  _reg_addr：寄存器地址
			 _reg_num：寄存器个数
			 _buf : 寄存器值数组，每个寄存器2字节
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send10H_MAC(uint8_t *_mac, uint16_t _reg_addr, uint16_t _reg_num, uint16_t *_buf)
{
	uint8_t txbuf[256];
	uint8_t pos = 0;
	int i;
	uint16_t crc;

	g_tCmd.RegAddr = _reg_addr;
	g_tCmd.RegNum =  _reg_num;
	for (i = 0; i < _reg_num; i++)
	{
		g_tCmd.RegValueBuf[i] = _buf[i];
	}
	g_tCmd.RxOk = 0;

	memcpy(txbuf,  _mac, 6);
	pos = 6;
	txbuf[pos++] = 1;
	txbuf[pos++] = 0x10;			/* 功能码 10*/
	txbuf[pos++] = _reg_addr >> 8;			/* 地址寄存器 ：00 70 */
	txbuf[pos++] = _reg_addr;
	txbuf[pos++] = _reg_num >> 8;
	txbuf[pos++] = _reg_num;
	txbuf[pos++] = _reg_num * 2;    /* 字节数 */
	for (i = 0; i < _reg_num; i++)
	{
		txbuf[pos++] = _buf[i] >> 8;
		txbuf[pos++] = _buf[i];
	}
	crc = CRC16_Modbus(&txbuf[6], pos - 6);
	txbuf[pos++] = crc >> 8;
	txbuf[pos++] = crc;
	udp_SendBuf_mac(txbuf,  pos);
}


/*
*********************************************************************************************************
*	函 数 名: udp_Send0FH
*	功能说明: 发送0F指令（控制继电器输出）（不等待应答）
*	形    参:
			  _reg_addr：寄存器地址
			 _reg_num：寄存器个数
			 _buf : 寄存器值数组，每个寄存器2字节
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send0FH(uint16_t _reg_addr, uint16_t _reg_num, uint16_t *_buf)
{
	uint8_t txbuf[2048];
	uint16_t pos = 0;
	int i;
	uint16_t crc;
	uint16_t bytes;

	bytes = (_reg_num + 7) / 8;

	g_tCmd.RegAddr = _reg_addr;
	g_tCmd.RegNum =  _reg_num;
	for (i = 0; i < bytes; i++)
	{
		g_tCmd.RegValueBuf[i] = _buf[i];
	}
	g_tCmd.RxOk = 0;

	pos = 0;
	txbuf[pos++] = 1;
	txbuf[pos++] = 0x0F;			/* 功能码 */
	txbuf[pos++] = _reg_addr >> 8;			/* 地址寄存器 ：00 70 */
	txbuf[pos++] = _reg_addr;
	txbuf[pos++] = _reg_num >> 8;
	txbuf[pos++] = _reg_num;
	txbuf[pos++] = bytes;    /* 字节数 */
	for (i = 0; i < bytes; i++)
	{
		txbuf[pos++] = _buf[i];
	}
	crc = CRC16_Modbus(txbuf, pos);
	txbuf[pos++] = crc >> 8;
	txbuf[pos++] = crc;
	udp_SendBuf(txbuf,  pos);
}

/*
*********************************************************************************************************
*	函 数 名: udp_Send03H
*	功能说明: 发送03指令，读取寄存器数据
*	形    参: _mac : 从机的mac地址
*			  _reg_addr：寄存器地址
*			 _reg_num：寄存器个数
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send03H(uint16_t _reg_addr, uint16_t _reg_num)
{
	uint8_t txbuf[32];
	uint8_t pos = 0;
	uint16_t crc;

	g_tCmd.RegAddr = _reg_addr;
	g_tCmd.RegNum =  _reg_num;
	g_tCmd.RxOk = 0;

	pos = 0;
	txbuf[pos++] = 1;
	txbuf[pos++] = 0x03;			/* 功能码 10*/
	txbuf[pos++] = _reg_addr >> 8;	/* 地址寄存器 ：00 70 */
	txbuf[pos++] = _reg_addr;
	txbuf[pos++] = _reg_num >> 8;
	txbuf[pos++] = _reg_num;
	crc = CRC16_Modbus(txbuf, pos);
	txbuf[pos++] = crc >> 8;
	txbuf[pos++] = crc;

	udp_SendBuf(txbuf,  pos);
}

/*
*********************************************************************************************************
*	函 数 名: udp_Send03H_MAC
*	功能说明: 发送03指令，读取寄存器数据
*	形    参: _mac : 从机的mac地址
*			  _reg_addr：寄存器地址
*			 _reg_num：寄存器个数
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send03H_MAC(uint8_t * _mac, uint16_t _reg_addr, uint16_t _reg_num)
{
	uint8_t txbuf[32];
	uint8_t pos = 0;
	uint16_t crc;

	g_tCmd.RegAddr = _reg_addr;
	g_tCmd.RegNum =  _reg_num;
	g_tCmd.RxOk = 0;

	memcpy(txbuf,  _mac, 6);
	pos = 6;
	txbuf[pos++] = 1;
	txbuf[pos++] = 0x03;			/* 功能码 10*/
	txbuf[pos++] = _reg_addr >> 8;	/* 地址寄存器 ：00 70 */
	txbuf[pos++] = _reg_addr;
	txbuf[pos++] = _reg_num >> 8;
	txbuf[pos++] = _reg_num;
	crc = CRC16_Modbus(&txbuf[6], pos - 6);
	txbuf[pos++] = crc >> 8;
	txbuf[pos++] = crc;

	udp_SendBuf_mac(txbuf,  pos);
}

/*
*********************************************************************************************************
*	函 数 名: udp_Send64H
*	功能说明: 发送64h指令，下载Lua程序
*	形    参: _
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send64H(uint16_t _Func, uint32_t _TotalLen, uint32_t _Offset, uint32_t _Len, uint8_t *_DataBuf)
{
/*
	0100 0000 ; 小程序总长度 4字节
	0000 0000 : 小程序偏移地址 4字节
	0020 0000 : 本包程序长度 4字节 必须是偶数
*/
	uint8_t pos = 0;
	uint16_t crc;
	uint32_t i;

	if (_Len > TX_BUF_SIZE - 16)
	{
		return;
	}

	g_tCmd.RxOk = 0;

	s_TxLen = 0;
	s_TxBuf[s_TxLen++] = 1;
	s_TxBuf[s_TxLen++] = 0x64;			/* 功能码 */
	s_TxBuf[s_TxLen++] = _Func >> 8;
	s_TxBuf[s_TxLen++] = _Func >> 0;

	s_TxBuf[s_TxLen++] = _TotalLen >> 24;
	s_TxBuf[s_TxLen++] = _TotalLen >> 16;
	s_TxBuf[s_TxLen++] = _TotalLen >> 8;
	s_TxBuf[s_TxLen++] = _TotalLen >> 0;

	s_TxBuf[s_TxLen++] = _Offset >> 24;
	s_TxBuf[s_TxLen++] = _Offset >> 16;
	s_TxBuf[s_TxLen++] = _Offset >> 8;
	s_TxBuf[s_TxLen++] = _Offset >> 0;

	s_TxBuf[s_TxLen++] = _Len >> 24;
	s_TxBuf[s_TxLen++] = _Len >> 16;
	s_TxBuf[s_TxLen++] = _Len >> 8;
	s_TxBuf[s_TxLen++] = _Len >> 0;

	for (i = 0; i < _Len; i++)
	{
		s_TxBuf[s_TxLen++] = _DataBuf[i];
	}

	crc = CRC16_Modbus(s_TxBuf, s_TxLen);
	s_TxBuf[s_TxLen++] = crc >> 8;
	s_TxBuf[s_TxLen++] = crc;

	udp_SendBuf(s_TxBuf,  s_TxLen);

	// DEBUG
	#if 0
		//;_Func, uint32_t _TotalLen, uint32_t _Offset, uint32_t _Len, uint8_t *_DataBuf
		{
			AnsiString s;

			s.sprintf("_Func = %X, _TotalLen = %d, _Offset = %d(%X), _Len = %d",
				_Func, _TotalLen, _Offset, _Offset, _Len);
			Form1->MemoLuaOut->Lines->Add(s);
		}
	#endif
}

/*
*********************************************************************************************************
*	函 数 名: udp_Send65H
*	功能说明: 发送65h指令，下载临时Lua程序
*	形    参:
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send65H(char *_LuaStr, uint32_t _LuaLen)
{
/*
	01
	65
	00 18
	xxxxxxx
	CRC
*/
	uint8_t pos = 0;
	uint16_t crc;
	uint32_t i;

	if (_LuaLen > TX_BUF_SIZE - 16)
	{
		return;
	}

	g_tCmd.RxOk = 0;

	s_TxLen = 0;
	s_TxBuf[s_TxLen++] = 1;
	s_TxBuf[s_TxLen++] = 0x65;			/* 功能码 */
	s_TxBuf[s_TxLen++] = _LuaLen >> 8;
	s_TxBuf[s_TxLen++] = _LuaLen >> 16;

	for (i = 0; i < _LuaLen; i++)
	{
		s_TxBuf[s_TxLen++] =  _LuaStr[i];
	}
	s_TxBuf[s_TxLen++] = 0;

	crc = CRC16_Modbus(s_TxBuf, s_TxLen);
	s_TxBuf[s_TxLen++] = crc >> 8;
	s_TxBuf[s_TxLen++] = crc;

	udp_SendBuf(s_TxBuf,  s_TxLen);
}


/*
*********************************************************************************************************
*	函 数 名: udp_Send66H
*	功能说明: 发送66h指令，SWD
*	形    参:
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send66H(uint16_t _func, uint32_t _addr, uint32_t _len, uint8_t *_buf)
{
    /*
        主机发送: 小程序数据
            01  ; 站号
			66  ; 功能码
            0001  ; 子功能,
				- 0表示读内存 初始
				- 1表示读内存 后续
				- 2表示写内存，未用
            0000 0000 : 偏移地址 4字节
            0020 0000 : 数据长度 4字节
            ... 数据
            CCCC      : CRC16

        从机应答:
            01  ; 从机地址
            66  ; 功能码
            0000  ; 子功能

			00  ; 执行结果，0表示OK  1表示错误
            CCCC : CRC16
	*/
	uint8_t pos = 0;
	uint16_t crc;
	uint32_t i;

	if (_len > TX_BUF_SIZE - 16)
	{
		return;
	}

	g_tCmd.RxOk = 0;

	s_TxLen = 0;
	s_TxBuf[s_TxLen++] = 1;
	s_TxBuf[s_TxLen++] = 0x66;			/* 功能码 */
	s_TxBuf[s_TxLen++] = _func >> 8;
	s_TxBuf[s_TxLen++] = _func >> 16;

	s_TxBuf[s_TxLen++] = _addr >> 24;
	s_TxBuf[s_TxLen++] = _addr >> 16;
	s_TxBuf[s_TxLen++] = _addr >> 8;
	s_TxBuf[s_TxLen++] = _addr >> 0;

	s_TxBuf[s_TxLen++] = _len >> 24;
	s_TxBuf[s_TxLen++] = _len >> 16;
	s_TxBuf[s_TxLen++] = _len >> 8;
	s_TxBuf[s_TxLen++] = _len >> 0;

	if (_func == 2)
	{
		for (i = 0; i < _len; i++)
		{
			s_TxBuf[s_TxLen++] =  _buf[i];
		}

	}

	crc = CRC16_Modbus(s_TxBuf, s_TxLen);
	s_TxBuf[s_TxLen++] = crc >> 8;
	s_TxBuf[s_TxLen++] = crc;

	udp_SendBuf(s_TxBuf,  s_TxLen);
}


/*
*********************************************************************************************************
*	函 数 名: udp_Send15H
*	功能说明: 发送15h指令，下载固件
*	形    参:
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send15H(uint16_t _data_len, uint16_t _record_id, uint16_t _record_Len,
	uint16_t _valid_Len, uint8_t *buf)
{
	uint16_t i;
	uint16_t crc;

	g_tCmd.RxOk = 0;

	s_TxLen = 0;
	s_TxBuf[s_TxLen++] = 1;			/* 485地址 */
	s_TxBuf[s_TxLen++] = 0x15;			/* 功能码 10*/
	s_TxBuf[s_TxLen++] = _data_len;  /* 数据长度*/
	s_TxBuf[s_TxLen++] = 6;               /* 参数类型 */
	s_TxBuf[s_TxLen++] =  1 >> 8;//_file_Hao >> 8;			/* 文件号*/
	s_TxBuf[s_TxLen++] =  1; //_file_Hao;
	s_TxBuf[s_TxLen++] = _record_id >> 8;     /*  记录号*/
	s_TxBuf[s_TxLen++] = _record_id;
	s_TxBuf[s_TxLen++] = _valid_Len >> 8;     /*  记录长度 */
	s_TxBuf[s_TxLen++] = _valid_Len;
	for (i = 0; i < _valid_Len; i++)          /* 发送数据 */
	{
		s_TxBuf[s_TxLen++] = buf[i];
	}
	s_TxLen = _record_Len + 10;			/* 保持每包数据等长 */
	crc = CRC16_Modbus(s_TxBuf, s_TxLen);
	s_TxBuf[s_TxLen++] = crc >> 8;
	s_TxBuf[s_TxLen++] = crc;

	udp_SendBuf(s_TxBuf,  s_TxLen);
}

/*
*********************************************************************************************************
*	函 数 名: udp_Send60H
*	功能说明: 发送60h指令，读波形, 设置参数
*	形    参:
*	返 回 值: 无
*********************************************************************************************************
*/
void udp_Send60H(uint32_t _ChEn, uint32_t _SampleSize, uint16_t _PackageLen,  uint32_t _Offset)
{
	/*
		PC发送 60H
			01  ; 从机地址
			60  ; 功能码
			00  : 00表示PC下发，01表示设备应答 （仅仅用于人工分析）
			01 00 00 00  : 通道号使能标志 32bit，bit0表示CH1，bit1表示CH2
			00 00 04 00: 每个通道样本个数
			01 00 : 每通信包样本长度. 单位为1个样本。
			00 00 00 00 : 通道数据偏移 （样本单位，用于重发）
			CC CC : CRC16

		从机首先应答: 60H
			01  ; 从机地址
			60  ; 功能码
			01  : 00表示PC下发，01表示设备应答 （仅仅用于人工分析）
			01 00 00 00  : 通道号使能标志 32bit，bit0表示CH1，bit1表示CH2
			00 00 04 00 : 每个通道样本个数
			01 00 : 每通信包样本长度. 单位为1个样本。
			00 00 00 00 : 通道数据偏移 （样本单位，用于重发）
			CCCC : CRC16

		从机应答: （然后开始多包连续应答)
			01  ; 从机地址
			61  ; 功能码
			00  ; 通道号，00表示通道1,01表示通道2,
			00 00 00 00 : 偏移地址（样本单位）
			01 00 : 本包数据长度。样本单位。每个样本4字节。0x100表示1024字节。
			..... : 数据体
			CCCC : CRC16
	*/
	uint16_t i;
	uint16_t crc;

	g_tCmd.RxOk = 0;

	s_TxLen = 0;
	s_TxBuf[s_TxLen++] = 1;			/* 485地址 */
	s_TxBuf[s_TxLen++] = 0x60;			/* 功能码 */
	s_TxBuf[s_TxLen++] = 0;  		   /* 00表示PC下发，01表示设备应答 （仅仅用于人工分析） */
	s_TxBuf[s_TxLen++] = _ChEn >> 24;  /* 通道使能标志 */
	s_TxBuf[s_TxLen++] = _ChEn >> 15;
	s_TxBuf[s_TxLen++] = _ChEn >> 8;
	s_TxBuf[s_TxLen++] = _ChEn >> 0;

	s_TxBuf[s_TxLen++] = _SampleSize >> 24;  /* 每通信包样本长度. 单位为1个样本。 */
	s_TxBuf[s_TxLen++] = _SampleSize >> 15;
	s_TxBuf[s_TxLen++] = _SampleSize >> 8;
	s_TxBuf[s_TxLen++] = _SampleSize >> 0;

	s_TxBuf[s_TxLen++] = _PackageLen >> 8;    /* 每个通道样本个数 */
	s_TxBuf[s_TxLen++] = _PackageLen >> 0;

	s_TxBuf[s_TxLen++] = _Offset >> 24;  /* 通道数据偏移 */
	s_TxBuf[s_TxLen++] = _Offset >> 15;
	s_TxBuf[s_TxLen++] = _Offset >> 8;
	s_TxBuf[s_TxLen++] = _Offset >> 0;

	crc = CRC16_Modbus(s_TxBuf, s_TxLen);
	s_TxBuf[s_TxLen++] = crc >> 8;
	s_TxBuf[s_TxLen++] = crc;

	udp_SendBuf(s_TxBuf,  s_TxLen);
}

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
