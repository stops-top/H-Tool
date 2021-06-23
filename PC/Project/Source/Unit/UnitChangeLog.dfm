object FormChangeLog: TFormChangeLog
  Left = 0
  Top = 0
  Caption = #36719#20214#26356#26032#35760#24405
  ClientHeight = 463
  ClientWidth = 619
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  DesignSize = (
    619
    463)
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 536
    Top = 431
    Width = 75
    Height = 25
    Caption = #36864' '#20986
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TRichEdit
    Left = 8
    Top = 8
    Width = 603
    Height = 417
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #24494#36719#38597#40657
    Font.Style = []
    Lines.Strings = (
      'Memo1')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
    WantTabs = True
    Zoom = 100
  end
end
