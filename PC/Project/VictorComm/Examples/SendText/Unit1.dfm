object Form1: TForm1
  Left = 420
  Top = 427
  Caption = 'Form1'
  ClientHeight = 244
  ClientWidth = 542
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
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 449
    Height = 233
    HideSelection = False
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 0
    WordWrap = False
  end
  object ButtonSend1: TButton
    Left = 464
    Top = 200
    Width = 75
    Height = 41
    Caption = 'ButtonSend1'
    TabOrder = 2
    OnClick = ButtonSend1Click
  end
  object ButtonSet1: TButton
    Left = 456
    Top = 107
    Width = 33
    Height = 25
    Caption = 'Set'
    TabOrder = 1
    OnClick = ButtonSet1Click
  end
  object ButtonClear: TButton
    Left = 495
    Top = 107
    Width = 39
    Height = 25
    Caption = 'Clear'
    TabOrder = 3
    OnClick = ButtonClearClick
  end
  object PanelTextEncoding: TPanel
    Left = 463
    Top = 138
    Width = 76
    Height = 56
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 4
    object RadioBtnUTF8: TRadioButton
      Left = 8
      Top = 8
      Width = 65
      Height = 17
      Caption = 'UTF8'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioBtnANSI: TRadioButton
      Left = 8
      Top = 31
      Width = 65
      Height = 17
      Caption = 'ANSI'
      TabOrder = 1
    end
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 480
    Top = 8
  end
  object YbCommDevice1: TYbCommDevice
    PortNo = 1
    PortName = 'COM1'
    Left = 480
    Top = 48
  end
end
