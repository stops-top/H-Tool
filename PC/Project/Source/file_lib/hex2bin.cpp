/*
*********************************************************************************************************
*
*	模块名称 : HEX格式转为bin格式
*	文件名称 : hex2bin.c
*	版    本 : V1.0
*	说    明 : 安富莱电子原创
*   修改记录 :
* 			V1.0  2020-06-07  首版
*
*********************************************************************************************************
*/

#include "bsp.h"

/* hex范例
:02 0000 04 0802 F0
:10 0000 00 A8FF0724AD0202087DE00308F1160208 EC
:10 0010 00 79E0030833260208E5E1040821010000 25
:10 26D0 00 01FF01FF01FF01FF01FF01FF01FF01FF FA
:04 26E0 00 01180000DD
:04 0000 05 08020299 52
:00 0000 01 FF

 - 第1个字节 0x02表示本行数据的长度；
 - 第2、3字节 0x00 0x00表示起始地址；
 - 第4字节 0x04表示数据类型:
	'00' Data Rrecord：用来记录数据，HEX文件的大部分记录都是数据记录
	'01' End of File Record: 用来标识文件结束，放在文件的最后，标识HEX文件的结尾
	'02' Extended Segment Address Record: 用来标识扩展段地址的记录
	'03' Start Segment Address Record:开始段地址记录
	'04' Extended Linear Address Record: 用来标识扩展线性地址的记录
	'05' Start Linear Address Record:开始线性地址记录

 - 数据0802
 - F0为校验和。检验和 = 0x100 - 累加和
*/

static unsigned char AsciiToBin(char _Asc);
static short TwoAsciiToBin(char _Asc1, char _Asc2);
static int HexSumOk(char *_HexBuf, unsigned int _Bytes);
static void HexBufToBinBuf(char *_hex, unsigned char *_out, unsigned short _binlen);
static int AddHexLine(unsigned char *_hex, unsigned short _len, unsigned char *_bin, unsigned int _BinBufSize);

int s_status = 0;
uint32_t s_pos = 0;
uint32_t g_StartAddress = 0;
static uint32_t s_StartAddress = 0;
static uint32_t s_BaseAddress = 0;

/*
*********************************************************************************************************
*	函 数 名: MyHexToBin
*	功能说明: 将Hex格式的数据_Hex转换为bin格式的数据_Bin,
*	形    参: __BinMaxLen : _BinBuf size
*	返 回 值: 10 错误, > 1表示bin长度
*********************************************************************************************************
*/
int MyHexToBin(char *_HexBuf, int _HexBufSize, char *_BinBuf, int _BinBufSize,
	unsigned char _InitValue, unsigned int *_StartAddress)
{
	char *p1, *p2;
	unsigned char LineBuf[1024];
	unsigned short LineLen;
	unsigned char ch;
	int result = 0;

	p1 = _HexBuf;
	p2 = p1;

	*_StartAddress = 0;

	memset(_BinBuf, _InitValue, _BinBufSize);	/* 填充缺省值，0xFF或0x00 */
	s_status = 0;
	s_pos = 0;
	s_StartAddress = 0;
	s_BaseAddress = 0;
	while (_HexBufSize)
	{
		ch = *p2;
		if (ch == 0x0D || ch == 0x0A || ch == 0x00)
		{
			if ( p2 > p1)
			{
				if (HexSumOk(p1, p2 - p1))
				{
					if (p2 - p1 > sizeof(LineBuf) * 2)
					{
						return 0;	/* 行长度太长 */
					}
					HexBufToBinBuf(p1 + 1, LineBuf, p2 - p1 - 1);
					LineLen = (p2 - p1) / 2 - 1;

					result = AddHexLine(LineBuf, LineLen, _BinBuf, _BinBufSize);
					if (result == 0)   	/* 正常 */
					{
						;
					}
					else if (result == 1)  /* 解析结束 */
					{
						break;
					}
					else if (result == 2) /* 格式异常 */
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			
			if (ch == 0)
			{
				break;
			}

			p1 = p2 + 1;
		}
		p2++;
		_HexBufSize--;
	}
	*_StartAddress = g_StartAddress;
	return s_pos;
}

/*
	0=正常  1=解析结束  2=格式异常
*/
static int AddHexLine(unsigned char *_hex, unsigned short _len, unsigned char *_bin,
	unsigned int _BinBufSize)
{
//	:02 0000 04 0802 F0
//	:10 0000 00 A8FF0724AD0202087DE00308F1160208 EC
	uint8_t len;
	uint16_t offset;
	uint8_t DataType;

	uint8_t ret = 0;
	static uint32_t s_LastPos = 0;

	int i;

	len = _hex[0];
	offset = _hex[1] * 256 + _hex[2];
	DataType = _hex[3];
//	'00' Data Rrecord：用来记录数据，HEX文件的大部分记录都是数据记录
//	'01' End of File Record: 用来标识文件结束，放在文件的最后，标识HEX文件的结尾
//	'02' Extended Segment Address Record: 用来标识扩展段地址的记录
//	'03' Start Segment Address Record:开始段地址记录
//	'04' Extended Linear Address Record: 用来标识扩展线性地址的记录
//	'05' Start Linear Address Record:开始线性地址记录
	switch (DataType)
	{
		case 0x00:
			if (s_status == 0)
			{
				s_status = 1;

				s_StartAddress = s_BaseAddress + offset;

				g_StartAddress = s_StartAddress;
			}

			s_pos = s_BaseAddress + offset - s_StartAddress;
			for (i = 0; i < len; i++)
			{
				_bin[s_pos++] = _hex[4 + i];
			}
			break;

		case 0x01:
			ret = 1;    	/* hex文件正常结束 */
			break;

		case 0x02:
			break;

		case 0x03:
			break;

		case 0x04:
			s_BaseAddress = (_hex[4] << 24) + (_hex[5] << 16);
			break;

		case 0x05:			/* */
			break;

		default:
            ret = 2;
			break;
	}
	return ret;
}

static void HexBufToBinBuf(char *_hex, unsigned char *_out, unsigned short _hexlen)
{
	int i;

	for (i = 0; i < _hexlen / 2; i++)
	{
		_out[i] = TwoAsciiToBin(_hex[2 * i], _hex[2 * i + 1]);
	}
}

/*
*********************************************************************************************************
*	函 数 名: AsciiToBin
*	功能说明: 1字节ASCII字符，转换为1字节二进制 0-F
*	形    参: 无
*	返 回 值: 0x00-0x0F， 0xFF表示异常
*********************************************************************************************************
*/
static unsigned char AsciiToBin(char _Asc)
{
	if (_Asc >= '0' && _Asc <= '9')
	{
		return _Asc - '0';
	}
	else if (_Asc >= 'a' && _Asc <= 'f')
	{
		return _Asc - 'a' + 0x0A;
	}
	else if (_Asc >= 'A' && _Asc <= 'F')
	{
		return _Asc - 'A' + 0x0A;
	}
	else
	{
		return 0xFF;	/* 异常值 */
	}
}

/*
*********************************************************************************************************
*	函 数 名: AsciiToBin
*	功能说明: 2字节ASCII字符，转换为二进制
*	形    参: 无
*	返 回 值: 0 OK，其他值表示错误
*********************************************************************************************************
*/
static short TwoAsciiToBin(char _Asc1, char _Asc2)
{
	unsigned char c1,c2;

	c1 = AsciiToBin(_Asc1);
	c2 = AsciiToBin(_Asc2);
	if (c1 == 0xFF || c2 == 0xFF)
	{
		return -1;
	}

	return ((c1 << 4) | c2);
}

/*
*********************************************************************************************************
*	函 数 名: BEBufToFloat
*	功能说明: 将Hex格式的数据_Hex转换为bin格式的数据_Bin,
*	形    参: __BinMaxLen : _BinBuf size
*	返 回 值: 1 OK，0 错误
*********************************************************************************************************
*/
static int HexSumOk(char *_HexBuf, unsigned int _Bytes)
{
	unsigned char sum = 0;
	int i;
	unsigned char c1, c2;
	unsigned short cc;
	unsigned char endch;

	if (_Bytes == 0)
	{
		return 1;	/* 空行返回OK */
	}

	//:00 0000 01 FF
	if (_HexBuf[0] != ':' || _Bytes < 11 || ((_Bytes % 2) == 0))
	{
	   return 0;	/* 格式错误 */
	}

	for (i = 0; i < _Bytes / 2 - 1; i++)
	{
		cc = TwoAsciiToBin(_HexBuf[2 * i + 1], _HexBuf[2 * i + 2]);
		if (cc < 0)
		{
			return 0;
		}
		sum += cc;
	}
	endch = TwoAsciiToBin(_HexBuf[2 * i + 1], _HexBuf[2 * i + 2]);

	sum = 0x100 - sum;
	if (endch == sum)
	{
		return 1;	/* 校验通过 */
	}
	return 0;
}

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
