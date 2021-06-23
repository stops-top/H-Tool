object Form1: TForm1
  Left = 367
  Top = 382
  Caption = 'Form1'
  ClientHeight = 315
  ClientWidth = 487
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
    Top = 64
    Width = 28
    Height = 13
    Caption = 'Send:'
  end
  object Label3: TLabel
    Left = 8
    Top = 88
    Width = 49
    Height = 13
    Caption = 'Received:'
  end
  object Label2: TLabel
    Left = 10
    Top = 19
    Width = 35
    Height = 13
    Caption = 'Tel.No.'
  end
  object Memo1: TMemo
    Left = 57
    Top = 91
    Width = 377
    Height = 217
    HideSelection = False
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 3
    WordWrap = False
  end
  object ButtonSend1: TButton
    Left = 400
    Top = 56
    Width = 75
    Height = 25
    Caption = 'ButtonSend1'
    TabOrder = 1
    OnClick = ButtonSend1Click
  end
  object ButtonSet1: TButton
    Left = 440
    Top = 96
    Width = 33
    Height = 25
    Caption = 'Set'
    TabOrder = 0
    OnClick = ButtonSet1Click
  end
  object Edit1: TEdit
    Left = 56
    Top = 64
    Width = 337
    Height = 21
    TabOrder = 2
    Text = '12 5a e3 45 aa 23 45 57 99 df'
  end
  object Button1: TButton
    Left = 320
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Dial'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 400
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Hang'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 56
    Top = 16
    Width = 241
    Height = 21
    TabOrder = 6
    Text = '17202'
  end
  object YbCommDevice1: TYbCommDevice
    PortNo = 3
    PortName = 'COM3'
    AfterOpen = YbCommDevice1AfterOpen
    Left = 23
    Top = 120
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 23
    Top = 168
  end
end
