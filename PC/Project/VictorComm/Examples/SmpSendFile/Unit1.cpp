//---------------------------------------------------------------------------
// 控件演示程序，Copyright © Victor Chen

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "YbCommDevice"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
  FileReceived = NULL;

  YbCommDevice1->FrameSettings->FrameHead = 0xdb; //数据包头
  YbCommDevice1->FrameSettings->FrameTail = 0xde; //数据包尾
  YbCommDevice1->FrameSettings->FrameCtrl = 0xdc; //数据控制符

  try
   {
     YbCommDevice1->Active = true;
   }
  catch(Exception &e)
   {
     ShowMessage("YbCommDevice1: "+e.Message);
     if(!YbCommDevice1->SettingsDialog(this,true))
       Application->Terminate();
   }

  YbCommDevice1->PackageSize = 4096; //最大可发送 4096 个字节的数据包
  YbCommDevice1->PackageType = cptFrameHeadTail;
  YbCommDevice1->UsePackage = true; //启动数据包 (可以随时启动和停止, 与 Active 属性无关)
}
//---------------------------------------------------------------------------
#pragma argsused // 参数 Sender 不使用
void __fastcall TForm1::ButtonSetClick(TObject *Sender)
{
  YbCommDevice1->SettingsDialog(this,true);
}
//---------------------------------------------------------------------------
#pragma argsused // 参数 Sender 不使用
void __fastcall TForm1::ButtonSendClick(TObject *Sender)
{
  try
   {
     ButtonSend->Enabled = false;

     char Buf[4096];
     long FromPos, FileSize;

     UnicodeString sFile = L"d:\\topladv.gif";
     FILE *f = _wfopen(sFile.w_str(),L"rb"); //要发送的档案名
     if(!f)throw Exception(L"不能打开文件: "+sFile);
     fseek(f, 0, SEEK_END);
     FileSize = ftell(f); //档案长度
     fseek(f, 0, SEEK_SET);

     Buf[0] = 0x01; //规定用 0x01 表示档案名
     *(long*)(Buf+1) = FileSize; //档案长度 (Bytes)
     wcscpy((wchar_t*)(Buf+5), sFile.w_str());
     while(!YbCommDevice1->WritePackage(Buf,sFile.Length()*2+7)) // 0x01, LEN[4], FILENAME[LEN*2], L'\0'
      {
        Application->ProcessMessages(); //等候发送
        Sleep(10);
      }

     FromPos = 0; //从档案第 0 个位元组开始发送
     while(FromPos<FileSize)
      {
        long BytesRemain = FileSize - FromPos;
        long BytesToRead = BytesRemain<2000?BytesRemain:2000;

        fseek(f, FromPos, SEEK_SET); //从档案的第 FromPos 个位元组开始读取
        Buf[0] = 0x02; //规定用 0x02 表示档案内容
        *(long*)(Buf+1) = FromPos;
        *(long*)(Buf+5) = fread(Buf+9,1,BytesToRead,f);
        while(!YbCommDevice1->WritePackage(Buf,BytesToRead+9))
         {
           Application->ProcessMessages(); //等候发送
           Sleep(10);
         }

        FromPos += BytesToRead;
      }
   }
  __finally
   {
     ButtonSend->Enabled = true;
   }
}
//---------------------------------------------------------------------------
#pragma argsused // 参数 Sender 和 NotifyType 都不使用
void __fastcall TForm1::YbCommDevice1Package(TObject *Sender, int NotifyType)
{
  try
   {
     char Buf[4096];
     UnicodeString sRecvFileName;
     while(YbCommDevice1->ReadPackage(Buf,4096)>0)
      {
        if(Buf[0]==0x01) //档案名
         {
           if(FileReceived)
            {
              fclose(FileReceived);
              FileReceived = NULL;
            }

           ReceivedFileSize = *(long*)(Buf+1);
           sRecvFileName = ExtractFileDir(Application->ExeName)+L"\\"+ExtractFileName((wchar_t*)(Buf+5));
           FileReceived = _wfopen(sRecvFileName.w_str(),L"wb");
           if(!FileReceived)throw Exception(L"无法创建文件: "+sRecvFileName);
         }
        else if(Buf[0]==0x02) //档案内容
         {
           if(FileReceived)
            {
              long FromPos = *(long*)(Buf+1);
              long DataSize = *(long*)(Buf+5);
              fseek(FileReceived, FromPos, SEEK_SET);
              fwrite(Buf+9,1,DataSize,FileReceived);

              if(FromPos+DataSize>=ReceivedFileSize) //接收完成
               {
                 fclose(FileReceived);
                 FileReceived = NULL;
               }
            }
         }
      }
   }
  catch(Exception &e)
   {
     Memo1->Lines->Add(e.Message);
   }
}
//---------------------------------------------------------------------------

