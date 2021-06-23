//---------------------------------------------------------------------------
// 串口控件演示程序，Copyright © Victor Chen

#include <vcl.h>
#pragma hdrstop

#include "UnitTsData.h"
#include "UnitSendFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "YbCommDevice"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
  PkgID = 0;
  hsf = INVALID_HANDLE_VALUE;
  hdf = INVALID_HANDLE_VALUE;
  nSendFileSize = 0;
  nBytesToReceive = 0;
  dtReceiveFileTime = 0;
  bUploading = false;
  iReceivingCounter = 0;

  dlpath = ExtractFileDir(Application->ExeName)+L"\\download";
  _wmkdir(dlpath.c_str());
  dlpath += L"\\";

  YbCommDevice1->PackageType = cptFrameHeadTail;
  YbCommDevice1->PackageSize = 9000; //最大允许发送9000字节的数据包
  YbCommDevice1->UsePackage  = true;

  YbCommDevice1->FrameSettings->FrameHead = 0xdb; //数据包头
  YbCommDevice1->FrameSettings->FrameTail = 0xde; //数据包尾
  YbCommDevice1->FrameSettings->FrameCtrl = 0xdc; //数据控制符

  try
   {
     YbCommDevice1->Active = true;
   }
  catch(Exception &e)
   {
     if(!YbCommDevice1->SettingsDialog(this,true))
       Application->Terminate();
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ShowInfo(UnicodeString s)
{
  Memo1->Lines->Add(FormatDateTime(L"yyyy-mm-dd hh:nn:ss ",Now())+s);
}
//---------------------------------------------------------------------------
#pragma argsused // 参数 Sender 不使用
void __fastcall TForm1::FileOpen1Accept(TObject *Sender)
{
  try
   {
     bUploading = true;
     int nCode = UploadReq(FileOpen1->Dialog->FileName);
     if(nCode==0x88)nCode = UploadFileData();

     switch(nCode)
      {
        case 0x88: ShowInfo(L"发送成功！"); break;
        case 0xee: ShowInfo(L"发送文件错误！"); break;
        default  : ShowInfo(L"超时，对方电脑没有反应。");break;
      }
   }
  __finally
   {
     bUploading = false;
     if(hsf!=INVALID_HANDLE_VALUE)
      {
        CloseHandle(hsf); //关闭文件
        hsf = INVALID_HANDLE_VALUE;
      }
   }
}
//---------------------------------------------------------------------------
int __fastcall TForm1::UploadReq(UnicodeString fname)
{
  if(hsf!=INVALID_HANDLE_VALUE)
   {
     CloseHandle(hsf); //关闭文件
     hsf = INVALID_HANDLE_VALUE;
   }

  hsf = CreateFile(fname.c_str(), GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  if(hsf==INVALID_HANDLE_VALUE)throw Exception(L"不能打开文件: "+fname);

  TMyFinfoPkg finf; //发送文件信息数据包

  finf.cmd  = mpcUpload;
  finf.id = PkgID++;
  wcscpy(finf.name,ExtractFileName(fname).c_str());

  nSendFileSize = SeekFile(hsf,0,FILE_END); // SeekFile 的返回值是64位整数
  finf.size = nSendFileSize;                // 文件长度其实是64位整数，这里我们不处理大文件，所以只定义了32位的整数
  SeekFile(hsf,0,FILE_BEGIN);

  finf.time = GetFileModifiedTime(hsf);
  finf.CRC = ~CRC32(-1, &finf, sizeof(TMyFinfoPkg)-4);

  YbCommDevice1->WritePackage(&finf, sizeof(TMyFinfoPkg));
  ShowInfo(L"发送文件: "+fname);
  return WaitforAnswer(finf.cmd, finf.id);
}
//---------------------------------------------------------------------------
int __fastcall TForm1::UploadFileData(void)
{
  TMyFdataPkg fdata; //发送文件内容数据包
  long nTries;
  fdata.cmd = mpcFileData; //发送文件数据
  fdata.from = 0; //从文件第0个字节开始发送

  while((fdata.size=ReadFileData(hsf,fdata.data,DataSize))>0)
   {
     fdata.id = PkgID++;
     fdata.CRC = ~CRC32(-1, &fdata, sizeof(TMyFdataPkg)-4);

     for(nTries=2; nTries>0; nTries--)
      {
        YbCommDevice1->WritePackage(&fdata,sizeof(TMyFdataPkg));
        if(WaitforAnswer(fdata.cmd, fdata.id)==0x88)
          break;
      }
     if(!nTries)
      {
        return 0xee;
      }

     fdata.from += fdata.size;
     ProgressBar1->Position = MakePercent(fdata.from, nSendFileSize);
   }
  return 0x88;
}
//---------------------------------------------------------------------------
int __fastcall TForm1::WaitforAnswer(unsigned char Cmd, unsigned char id)
{
  TMyStatusPkg AnsPkg; //对方电脑回应的数据包
  int tm_start=timeGetTime(), tm_out=2000;
  while((int)(timeGetTime()-tm_start)<tm_out)
   {
     if(YbCommDevice1->ReadPackage(&AnsPkg,sizeof(TMyStatusPkg))==sizeof(TMyStatusPkg))
      if((AnsPkg.cmd==mpcStatus) && (AnsPkg.id==id) && (AnsPkg.anscmd==Cmd))
       {
         if(AnsPkg.status == 0x88)
           return 0x88; //ok
         return 0xee; //error
       }
     Application->ProcessMessages();
     Sleep(1);
   }
  return 0; //timeout
}
//---------------------------------------------------------------------------
#pragma argsused // 参数 Sender 不使用
void __fastcall TForm1::YbCommDevice1Package(TObject *Sender, int NotifyType)
{
  if((NotifyType&EV_RXCHAR) && !bUploading)
   {
     typedef union
      {
        TMyFinfoPkg finfo; //文件信息数据包
        TMyFdataPkg fdata; //文件内容数据包
        unsigned char cmd;  //无论哪种数据包，第一个字节都是命令字节
      } TMyPackage;
     TMyPackage recv; //收到的数据包可能是文件信息或者文件内容
     TMyStatusPkg send; //发送回应状态数据包
     int nReceived; //收到的字节数
     UnicodeString sDestFileName;

     while((nReceived=YbCommDevice1->ReadPackage(&recv,sizeof(TMyPackage)))>4) //数据包的长度都大于4
      {
        if(recv.cmd==mpcUpload)
         {
           send.cmd    = mpcStatus;
           send.id     = recv.finfo.id;
           send.anscmd = recv.finfo.cmd;
           send.status = (recv.finfo.CRC == ~CRC32(-1, &recv, nReceived-4))?0x88:0xee;
           send.CRC = ~CRC32(-1, &send, sizeof(TMyStatusPkg)-4);

           if(send.status==0x88) //数据 CRC 校验正确
            {
              iReceivingCounter = 5; //超过5秒没有数据，认为超时，中断接收
              nBytesToReceive = recv.finfo.size;
              dtReceiveFileTime = recv.finfo.time;

              if(hdf!=INVALID_HANDLE_VALUE)
               {
                 CloseHandle(hdf);
                 hdf = INVALID_HANDLE_VALUE;
               }

              sDestFileName = dlpath + recv.finfo.name;
              hdf = CreateFile(sDestFileName.c_str(), GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
              ShowInfo(L"接收文件: "+sDestFileName);
              if(hdf==INVALID_HANDLE_VALUE)throw Exception(L"无法创建文件: "+sDestFileName);

              if(nBytesToReceive<=0)
               {
                 SetFileModifiedTime(hdf,dtReceiveFileTime);
                 CloseHandle(hdf);
                 hdf = INVALID_HANDLE_VALUE;

                 ShowInfo(L"接收完成！");
               }
            }
           YbCommDevice1->WritePackage(&send,sizeof(TMyStatusPkg));
         }
        else if(recv.cmd==mpcFileData)
         {
           send.cmd    = mpcStatus;
           send.id     = recv.fdata.id;
           send.anscmd = recv.fdata.cmd;
           send.status = recv.fdata.CRC == ~CRC32(-1, &recv, nReceived-4)?0x88:0xee;
           send.CRC    = ~CRC32(-1, &send, sizeof(TMyStatusPkg)-4);

           if((send.status==0x88) && (hdf!=INVALID_HANDLE_VALUE)) //数据 CRC 校验正确
            {
              iReceivingCounter = 5; //超过5秒没有数据，认为超时，中断接收
              SeekFile(hdf, recv.fdata.from, FILE_BEGIN);
              WriteFileData(hdf, recv.fdata.data, recv.fdata.size);
              if(recv.fdata.from+recv.fdata.size>=nBytesToReceive)
               {
                 SetFileModifiedTime(hdf,dtReceiveFileTime);
                 CloseHandle(hdf);
                 hdf = INVALID_HANDLE_VALUE;

				 ShowInfo(L"接收完成！");
               }
              ProgressBar1->Position = MakePercent(recv.fdata.from+recv.fdata.size,nBytesToReceive);
            }
           YbCommDevice1->WritePackage(&send,sizeof(TMyStatusPkg));
         }
      }
   }
}
//---------------------------------------------------------------------------
#pragma argsused // 参数 Sender 不使用
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  if(iReceivingCounter>0)
   if(--iReceivingCounter==0)
    {
      if(hdf!=INVALID_HANDLE_VALUE)
       {
         SetFileModifiedTime(hdf,dtReceiveFileTime);
         CloseHandle(hdf);
         hdf = INVALID_HANDLE_VALUE;

		 ShowInfo(L"超时，接收中断。");
       }
    }
}
//---------------------------------------------------------------------------
#pragma argsused
void __fastcall TForm1::ButtonSetClick(TObject *Sender)
{
  YbCommDevice1->SettingsDialog(this,true);
}
//---------------------------------------------------------------------------
