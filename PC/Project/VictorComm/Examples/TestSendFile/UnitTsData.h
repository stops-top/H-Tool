//---------------------------------------------------------------------------
// 串口控件演示程序，Copyright © Victor Chen

#ifndef UnitTsDataH
#define UnitTsDataH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#include <dir.h>
#include <stdio.h>
//---------------------------------------------------------------------------
const int DataSize=4096;
#pragma pack(push,1)
enum TMyPkgCmd
{
  mpcUpload   = 1,
  mpcFileData = 2,
  mpcStatus   = 3,
};

typedef struct
{
  unsigned char cmd;           // 1 (1: upload, 2: filedata, 3:status)
  unsigned char id;
  double        time;          // date & time
  long          size;          // filesize // 文件长度其实是64位整数，这里我们不处理大文件，所以只定义了32位的整数
  wchar_t       name[MAXPATH]; // filename
  unsigned long CRC;
} TMyFinfoPkg;

typedef struct
{
  unsigned char cmd;   // 2 (1: upload, 2: filedata, 3:status)
  unsigned char id;
  long          from;  // 文件长度其实是64位整数，这里我们不处理大文件，所以只定义了32位的整数
  long          size;  // 文件长度其实是64位整数，这里我们不处理大文件，所以只定义了32位的整数
  char          data[DataSize];
  unsigned long CRC;
} TMyFdataPkg;

typedef struct
{
  unsigned char cmd;     // 3
  unsigned char id;
  unsigned char anscmd;
  unsigned char status;  // 0x88: OK
  unsigned long CRC;
} TMyStatusPkg;

#pragma pack(pop)
//---------------------------------------------------------------------------

extern unsigned long CRC32(unsigned long c, void *s, int n);
extern int MakePercent(unsigned long lPos, unsigned long lCount);
//---------------------------------------------------------------------------

extern long long SeekFile(HANDLE hFile, long long llDistanceToMove, DWORD dwMoveMethod); // 文件长度和读写位置指针都是64位整数
extern DWORD ReadFileData(HANDLE hFile, void *ptr, DWORD n);
extern DWORD WriteFileData(HANDLE hFile, const void *ptr, DWORD n);
extern TDateTime GetFileModifiedTime(HANDLE hFile);
extern void SetFileModifiedTime(HANDLE hFile, TDateTime t);
//---------------------------------------------------------------------------

#endif
