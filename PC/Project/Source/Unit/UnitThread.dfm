object FormTcp: TFormTcp
  Left = 0
  Top = 0
  Caption = #36890#20449#32447#31243
  ClientHeight = 150
  ClientWidth = 291
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Thread1: TIdThreadComponent
    Active = False
    Loop = True
    Priority = tpNormal
    StopMode = smSuspend
    OnRun = Thread1Run
    Left = 36
    Top = 18
  end
  object UDP1: TIdUDPClient
    Active = True
    BufferSize = 32768
    Port = 30010
    ReceiveTimeout = 200
    ReuseSocket = rsFalse
    Left = 119
    Top = 18
  end
  object TimerUDP: TTimer
    Enabled = False
    Interval = 1
    Left = 184
    Top = 16
  end
  object IdThreadComponent1: TIdThreadComponent
    Active = False
    Loop = False
    Priority = tpNormal
    StopMode = smTerminate
    Left = 248
    Top = 128
  end
end
