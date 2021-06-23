object Form1: TForm1
  Left = 502
  Top = 388
  Caption = 'Form1'
  ClientHeight = 291
  ClientWidth = 481
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 20
    Width = 28
    Height = 13
    Caption = 'Send:'
  end
  object Label2: TLabel
    Left = 8
    Top = 48
    Width = 49
    Height = 13
    Caption = 'Received:'
  end
  object Memo1: TMemo
    Left = 8
    Top = 64
    Width = 465
    Height = 225
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 1
    WordWrap = False
  end
  object Edit1: TEdit
    Left = 48
    Top = 16
    Width = 297
    Height = 21
    TabOrder = 0
    Text = '02 56 77 9a db 33 de 56 aa'
  end
  object ButtonSend: TButton
    Left = 400
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Send'
    TabOrder = 3
    OnClick = ButtonSendClick
  end
  object ButtonSet: TButton
    Left = 360
    Top = 16
    Width = 33
    Height = 25
    Caption = 'Set'
    TabOrder = 2
    OnClick = ButtonSetClick
  end
  object YbCommDevice1: TYbCommDevice
    PortNo = 1
    PortName = 'COM1'
    Left = 296
    Top = 32
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 240
    Top = 32
  end
end
