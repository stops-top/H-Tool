object Form1: TForm1
  Left = 480
  Top = 415
  Caption = 'Form1'
  ClientHeight = 265
  ClientWidth = 482
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
    Top = 16
    Width = 28
    Height = 13
    Caption = 'Send:'
  end
  object Label3: TLabel
    Left = 8
    Top = 40
    Width = 49
    Height = 13
    Caption = 'Received:'
  end
  object ButtonSend1: TButton
    Left = 368
    Top = 16
    Width = 75
    Height = 25
    Caption = 'ButtonSend1'
    TabOrder = 1
    OnClick = ButtonSend1Click
  end
  object ButtonSet1: TButton
    Left = 368
    Top = 56
    Width = 33
    Height = 25
    Caption = 'Set'
    TabOrder = 0
    OnClick = ButtonSet1Click
  end
  object Edit1: TEdit
    Left = 56
    Top = 16
    Width = 297
    Height = 21
    TabOrder = 2
    Text = '12 5a e3 45 aa 23 45 57 99 df'
  end
  object Memo1: TMemo
    Left = 56
    Top = 40
    Width = 297
    Height = 217
    HideSelection = False
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 3
    WordWrap = False
  end
  object YbCommDevice1: TYbCommDevice
    PortNo = 1
    PortName = 'COM1'
    OnCommNotify = YbCommDevice1CommNotify
    Left = 384
    Top = 112
  end
end
