/*
*********************************************************************************************************
*
*	模块名称 : 文件操作库
*	文件名称 : file_lib.h
*	说    明 : 头文件
*
*********************************************************************************************************
*/

#ifndef __FILE_LIB_H
#define __FILE_LIB_H

int ReadFileToMem(UnicodeString _FileName, char *_FileBuf, uint32_t _BufSize);
int SaveMemToFile(UnicodeString _FileName, char *_FileBuf, uint32_t _BufSize);
uint32_t GetFileMD5(UnicodeString _FileName, char *_OutMD5);
uint32_t GetFileSums(UnicodeString _FileName);

String AppExePath(void);

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
