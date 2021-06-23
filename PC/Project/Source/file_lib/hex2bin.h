/*
*********************************************************************************************************
*
*	模块名称 : hex转bin文件
*	文件名称 : hex2bin.h
*
*********************************************************************************************************
*/

#ifndef __HEX2BIN_H
#define __HEX2BIN_H

int MyHexToBin(char *_HexBuf, int _HexBufSize, char *_BinBuf, int _BinBufSize,
	unsigned char _InitValue, unsigned int *_StartAddress);

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
