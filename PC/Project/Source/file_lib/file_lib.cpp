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
#include "md5.h"
/*
*********************************************************************************************************
*	函 数 名: ReadFileToMem
*	功能说明: 读文件到缓冲区
*	形    参:
*	返 回 值: 0 错误, 1 成功
*********************************************************************************************************
*/
int ReadFileToMem(UnicodeString _FileName, char *_FileBuf, uint32_t _BufSize)
{
	int iFileHandle;
	int iBytesRead;
	int iFileLength = 0;

	iFileHandle = FileOpen(_FileName, fmOpenRead);
	if (iFileHandle > 0)
	{
		iFileLength = FileSeek(iFileHandle, 0, 2);

		if (iFileLength < _BufSize)
		{
			FileSeek(iFileHandle, 0, 0);
			FileRead(iFileHandle, _FileBuf, iFileLength);
		}
		else
		{
			;
		}
		FileClose(iFileHandle);
	}
	return iFileLength;
}

/*
*********************************************************************************************************
*	函 数 名: SaveMemToFile
*	功能说明: 保存到文件
*	形    参:
*	返 回 值: 0 错误, > 1表示bin长度
*********************************************************************************************************
*/
int SaveMemToFile(UnicodeString _FileName, char *_FileBuf, uint32_t _BufSize)
{
	int iFileHandle;
	int iBytesRead;
	int iFileLength = 0;

	iFileHandle = FileCreate(_FileName);
	if (iFileHandle > 0)
	{
		iFileLength = FileWrite(iFileHandle, _FileBuf, _BufSize);
		FileClose(iFileHandle);
	}
	return iFileLength;
}

/*
*********************************************************************************************************
*    函 数 名: GetFileMD5
*    功能说明: 得到文件的MD5码
*    形    参: _Path : 文件名
*              _OutMD5 : 输出结果 16字节
*             _FileSize : 文件大小
*    返 回 值: 文件大小. -1表示打开文件失败
*********************************************************************************************************
*/
uint32_t GetFileMD5(UnicodeString _FileName, char *_OutMD5)
{
    uint32_t bytes;
    uint32_t offset = 0;
    MD5_CTX md5;
	int iFileHandle;
	int iBytesRead;
	int iFileLength = 0;
	char FsReadBuf[32*1024];

    memset(_OutMD5, 0, 16);

	MD5Init(&md5);

	iFileHandle = FileOpen(_FileName, fmOpenRead);
	if (iFileHandle > 0)
	{
		iFileLength = FileSeek(iFileHandle, 0, 2);

		FileSeek(iFileHandle, 0, 0);

		while (1)
		{
			bytes = FileRead(iFileHandle, FsReadBuf, sizeof(FsReadBuf));
			if (bytes > 0)
			{
				MD5Update(&md5, (uint8_t *)FsReadBuf, bytes);
			}
			else
			{
				break;
			}
		}
		FileClose(iFileHandle);
	}
	MD5Final(&md5, (uint8_t *)_OutMD5);
	return iFileLength;
}


/*
*********************************************************************************************************
*    函 数 名: GetFileSums
*    功能说明: 得到文件的累加校验和
*    形    参: _Path : 文件名
*              _OutMD5 : 输出结果 16字节
*             _FileSize : 文件大小
*    返 回 值: 校验和 uint32_t
*********************************************************************************************************
*/
uint32_t GetFileSums(UnicodeString _FileName)
{
    uint32_t bytes;
	uint32_t offset = 0;

	int iFileHandle;
	int iBytesRead;
	int iFileLength = 0;
	char FsReadBuf[32*1024];
	uint32_t sum = 0;
	uint32_t i;

	iFileHandle = FileOpen(_FileName, fmOpenRead);
	if (iFileHandle > 0)
	{
		iFileLength = FileSeek(iFileHandle, 0, 2);

		FileSeek(iFileHandle, 0, 0);

		while (1)
		{
			bytes = FileRead(iFileHandle, FsReadBuf, sizeof(FsReadBuf));
			if (bytes > 0)
			{
				for (i = 0; i < bytes; i++)
				{
					sum += FsReadBuf[i];
				}
			}
			else
			{
				break;
			}
		}
		FileClose(iFileHandle);
	}

	return sum;
}

/*
*********************************************************************************************************
*    函 数 名: AppExePath
*    功能说明: 得到应用程序路径。 windows
*    形    参:  无
*    返 回 值: exe文件路径
*********************************************************************************************************
*/
String AppExePath(void)
{
	AnsiString str;
	int len;
	char *p;
	char *p0;
	char buf[256];

	str = ExtractFilePath(Application->ExeName);

	strcpy(buf, str.c_str());
	p = strstr(buf, "\\..\\");
	if (p > 0)
	{
		p0 = p;
		for (int i = 0; i < 100; i++)
		{
			p0--;
			if (*p0 == '\\')
			{
				strcpy(p0, p+3);
				break;
			}
		}
	}

	len = strlen(buf);
	if (buf[len - 1] == '\\')
	{
		buf[len - 1] = 0;
	}

	str = (AnsiString)buf;

	return str;
}

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
