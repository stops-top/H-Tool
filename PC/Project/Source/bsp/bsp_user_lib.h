/*
*********************************************************************************************************
*
*	模块名称 : 字符串操作\数值转换
*	文件名称 : bsp_user_lib.h
*	版    本 : V1.2
*	说    明 : 头文件
*
*********************************************************************************************************
*/

#ifndef __BSP_USER_LIB_H
#define __BSP_USER_LIB_H

/* Signed integer types  */


int str_len(char *_str);
void str_cpy(char *_tar, char *_src);
int str_cmp(char * s1, char * s2);
void mem_set(char *_tar, char _data, int _len);

void int_to_str(int _iNumber, char *_pBuf, unsigned char _len);
int str_to_int(char *_pStr);
int str_to_int2(char *_pStr);


uint8_t str_to_hex(char *_pStr, char *_pBuf);

uint16_t BEBufToUint16(uint8_t *_pBuf);
uint16_t LEBufToUint16(uint8_t *_pBuf);

uint32_t BEBufToUint32(uint8_t *_pBuf);
uint32_t LEBufToUint32(uint8_t *_pBuf);

uint16_t CRC16_Modbus(uint8_t *_pBuf, uint16_t _usLen) ;
int32_t  CaculTwoPoint(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x);

float LEBufToFloat(uint8_t *_pBuf);
double BEBufToFloat(uint8_t *_pBuf);

void FloatToLEBuf(float _f, uint8_t *_pBuf);
void FloatToBEBuf(float _f, uint8_t *_pBuf);

void Uint16ToBEBuf(uint16_t _value, uint8_t *_pBuf);
void Uint16ToLEBuf(uint16_t _value, uint8_t *_pBuf);
void Uint32ToBEBuf(uint32_t _value, uint8_t *_pBuf);
void Uint32ToLEBuf(uint32_t _value, uint8_t *_pBuf);

int __fastcall 	MyStrToInt(const System::UnicodeString S);
float __fastcall MyStrToFloat(const System::UnicodeString S);

AnsiString __fastcall  MyFloatToStr(float f, const char *fmt);
uint8_t HexToAscii(uint8_t _hex);
void HexBufToAscii(uint8_t *_pHex, char *_pAscii, uint16_t _BinBytes);
AnsiString AnsiStringToLuaSting(AnsiString s_in);

unsigned short RGB888ToRGB565(unsigned int n888Color);
unsigned int RGB565ToRGB888(unsigned short n565Color);

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
