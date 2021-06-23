object Form1: TForm1
  Left = 519
  Top = 402
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 278
  ClientWidth = 474
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
  object BitBtn1: TBitBtn
    Left = 208
    Top = 248
    Width = 75
    Height = 25
    Action = FileOpen1
    Caption = #21457#36865#25991#20214
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 0
  end
  object ProgressBar1: TProgressBar
    Left = 8
    Top = 216
    Width = 457
    Height = 24
    Smooth = True
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 457
    Height = 201
    HideSelection = False
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 2
  end
  object ButtonSet: TButton
    Left = 432
    Top = 248
    Width = 34
    Height = 25
    Caption = 'Set'
    TabOrder = 3
    OnClick = ButtonSetClick
  end
  object YbCommDevice1: TYbCommDevice
    PortNo = 2
    PortName = 'COM2'
    OnPackage = YbCommDevice1Package
    Left = 8
    Top = 248
  end
  object ActionList1: TActionList
    Left = 40
    Top = 248
    object FileOpen1: TFileOpen
      Category = 'File'
      Caption = #21457#36865#25991#20214
      Dialog.Title = #36873#25321#35201#21457#36865#30340#25991#20214
      Hint = 'Open|Opens an existing file'
      ImageIndex = 7
      ShortCut = 16463
      OnAccept = FileOpen1Accept
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 72
    Top = 248
  end
end
