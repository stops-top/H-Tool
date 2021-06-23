object FormRTT: TFormRTT
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'RTT Viewer'
  ClientHeight = 591
  ClientWidth = 560
  Color = 13105899
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    560
    591)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 536
    Top = 538
    Width = 13
    Height = 13
    Anchors = [akRight, akBottom]
    Caption = 'ms'
  end
  object ButtonStartRTT: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 29
    Caption = #21551#21160' RTT'
    TabOrder = 0
  end
  object ComboBoxTerID: TComboBox
    Left = 152
    Top = 8
    Width = 129
    Height = 27
    Style = csDropDownList
    DropDownCount = 20
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 1
    Text = 'Terminal 0'
    Items.Strings = (
      'Terminal 0'
      'Terminal 1'
      'Terminal 2'
      'Terminal 3'
      'Terminal 4'
      'Terminal 5'
      'Terminal 6'
      'Terminal 7'
      'Terminal 8'
      'Terminal 9'
      'Terminal 10'
      'Terminal 11'
      'Terminal 12'
      'Terminal 13'
      'Terminal 14'
      'Terminal 15')
  end
  object ButtonLeft: TButton
    Left = 104
    Top = 7
    Width = 44
    Height = 29
    Caption = #12298
    TabOrder = 2
    OnClick = ButtonLeftClick
  end
  object ButtonRight: TButton
    Left = 286
    Top = 7
    Width = 44
    Height = 29
    Caption = #12299
    TabOrder = 3
    OnClick = ButtonRightClick
  end
  object RichEdit1: TRichEdit
    Left = 8
    Top = 41
    Width = 460
    Height = 398
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'RichEdit1')
    ParentFont = False
    TabOrder = 4
    Zoom = 100
  end
  object Memo1: TMemo
    Left = 8
    Top = 455
    Width = 460
    Height = 128
    Anchors = [akLeft, akRight, akBottom]
    Lines.Strings = (
      'Memo1')
    TabOrder = 5
  end
  object ButtonSend: TButton
    Left = 474
    Top = 557
    Width = 77
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = #21457#36865
    TabOrder = 6
  end
  object CheckBoxAuto: TCheckBox
    Left = 477
    Top = 45
    Width = 75
    Height = 17
    Anchors = [akTop, akRight]
    Caption = #33258#21160#20999#25442
    TabOrder = 7
  end
  object CheckBox1: TCheckBox
    Left = 477
    Top = 74
    Width = 68
    Height = 17
    Anchors = [akTop, akRight]
    Caption = 'HEX'#26684#24335
    TabOrder = 8
  end
  object CheckBox2: TCheckBox
    Left = 474
    Top = 457
    Width = 78
    Height = 17
    Anchors = [akRight, akBottom]
    Caption = 'HEX'#26684#24335
    TabOrder = 9
  end
  object CheckBox3: TCheckBox
    Left = 474
    Top = 503
    Width = 78
    Height = 17
    Anchors = [akRight, akBottom]
    Caption = #23450#26102#21457#36865
    TabOrder = 10
  end
  object ComboBox1: TComboBox
    Left = 474
    Top = 530
    Width = 56
    Height = 21
    Anchors = [akRight, akBottom]
    ItemIndex = 10
    TabOrder = 11
    Text = '12'
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '25'
      '30'
      '35'
      '40'
      '45'
      '50'
      '60'
      '70'
      '80'
      '90'
      '100'
      '110'
      '120'
      '130'
      '140'
      '150'
      '160'
      '170'
      '180'
      '190'
      '200'
      '250'
      '300'
      '350'
      '400'
      '450'
      '500')
  end
  object Button1: TButton
    Left = 475
    Top = 97
    Width = 67
    Height = 25
    Anchors = [akTop, akRight]
    Caption = #26242#20572#21047#26032
    TabOrder = 12
  end
  object CheckBox4: TCheckBox
    Left = 474
    Top = 480
    Width = 78
    Height = 17
    Anchors = [akRight, akBottom]
    Caption = #21152#22238#36710#25442#34892
    TabOrder = 13
  end
end
