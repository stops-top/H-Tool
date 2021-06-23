//---------------------------------------------------------------------------
// 串口控件演示程序，Copyright © Victor Chen

#pragma hdrstop

#include "UnitTsData.h"
#include <DateUtils.hpp>
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

unsigned long CRC32(unsigned long c, void *s, int n)
{
  unsigned long i, b;
  for(int k=0; k<n; k++)
   {
     b=(((unsigned char*)s)[k]);
     for(i=0; i<8; i++)
      {
        c = ((b^c) & 0x0001) ? (c>>1)^0xedb88320ui32 : (c>>1);
        b>>=1;
      }
   }
  return c;
}
//---------------------------------------------------------------------------
int MakePercent(unsigned long lPos, unsigned long lCount)
{
  unsigned long lPercent = 0;

  if(lCount)
   {
     if(lCount>10000)
      {
        lPercent = lCount/100;
        lPercent = lPos/lPercent;
      }
     else
      {
        lPercent = lPos*100;
        lPercent/= lCount;
      }
     if(lPercent>100)
      {
        lPercent=100;
      }
   }

  return(int)lPercent;
}
//---------------------------------------------------------------------------
long long SeekFile(HANDLE hFile, long long llDistanceToMove, DWORD dwMoveMethod) // 文件长度和读写位置指针都是64位整数
{
  if(hFile!=INVALID_HANDLE_VALUE)
   {
     LARGE_INTEGER mv, pt;
     mv.QuadPart = llDistanceToMove;
     pt.QuadPart = 0;

     if(SetFilePointerEx(hFile, mv, &pt, dwMoveMethod))
       return pt.QuadPart;
   }
  return 0;
}
//---------------------------------------------------------------------------
DWORD ReadFileData(HANDLE hFile, void *ptr, DWORD n)
{
  if(hFile!=INVALID_HANDLE_VALUE)
   {
     DWORD r = 0;
     if(ReadFile(hFile, ptr, n, &r, NULL))
       return r;
   }
  return 0;
}
//--------------------------------------------------------------------------
DWORD WriteFileData(HANDLE hFile, const void *ptr, DWORD n)
{
  if(hFile!=INVALID_HANDLE_VALUE)
   {
     DWORD w = 0;
     if(WriteFile(hFile, ptr, n, &w, NULL))
       return w;
   }
  return 0;
}
//--------------------------------------------------------------------------
TDateTime GetFileModifiedTime(HANDLE hFile)
{
  TDateTime dtFileTime;
  if(hFile!=INVALID_HANDLE_VALUE)
   {
     FILETIME ftCreate, ftAccess, ftWrite;
     if(GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite))
      {
        FILETIME lcft;
        FileTimeToLocalFileTime(&ftWrite, &lcft);

        SYSTEMTIME st;
        FileTimeToSystemTime(&lcft, &st);

        dtFileTime = EncodeDateTime(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
      }
   }
  return dtFileTime;
}
//--------------------------------------------------------------------------
void SetFileModifiedTime(HANDLE hFile, TDateTime t)
{
  if(hFile!=INVALID_HANDLE_VALUE)
   {
     SYSTEMTIME st;
     memset(&st, 0, sizeof(SYSTEMTIME));
     DecodeDateTime(t, st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

     FILETIME lcft;
     SystemTimeToFileTime(&st, &lcft);

     FILETIME ft;
     LocalFileTimeToFileTime(&lcft, &ft);

     SetFileTime(hFile, NULL, NULL, &ft);
   }
}
//--------------------------------------------------------------------------
