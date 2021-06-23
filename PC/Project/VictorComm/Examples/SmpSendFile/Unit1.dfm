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
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object ButtonSend: TButton
    Left = 72
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Send'
    TabOrder = 1
    OnClick = ButtonSendClick
  end
  object ButtonSet: TButton
    Left = 16
    Top = 8
    Width = 33
    Height = 25
    Caption = 'Set'
    TabOrder = 0
    OnClick = ButtonSetClick
  end
  object Memo1: TMemo
    Left = 16
    Top = 48
    Width = 449
    Height = 217
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object YbCommDevice1: TYbCommDevice
    PortNo = 1
    PortName = 'COM1'
    OnPackage = YbCommDevice1Package
    Left = 168
    Top = 8
  end
end
