object FormLuaApi: TFormLuaApi
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = 'Lua API'#23567#21161#25163
  ClientHeight = 469
  ClientWidth = 471
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  DesignSize = (
    471
    469)
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 457
    Height = 194
    ActivePage = TabSheet1
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #26631#20934#35821#21477
      object Label7: TLabel
        Left = 16
        Top = 16
        Width = 84
        Height = 13
        Caption = #23383#31526#20018#30456#20851#20989#25968
      end
      object ComboBoxStringFunc: TComboBox
        Left = 16
        Top = 35
        Width = 273
        Height = 21
        Style = csDropDownList
        DropDownCount = 20
        ItemIndex = 0
        TabOrder = 0
        Text = 'string.byte '#23383#31526#36716#25442#25104'ascii'#25968#23383
        OnClick = ComboBoxStringFuncClick
        Items.Strings = (
          'string.byte '#23383#31526#36716#25442#25104'ascii'#25968#23383
          'string.char Ascii'#25968#20540#36716#25442#25104#23383#31526
          'string.sub '#25130#21462#23383#31526#20018
          'string.find '#23383#31526#20018#26597#25214#20989#25968
          'string.match '#23383#31526#20018#26597#25214#20989#25968
          'string.gsub '#23383#31526#20018#26367#25442
          'string.format '#23383#31526#20018#26684#24335#21270#31867#22411
          'string.len '#36820#22238#23383#31526#20018#38271#24230'=#s'
          'string.rep '#23383#31526#20018#37325#22797'n'#27425#24182#25340#25509#36820#22238
          'string.lower '#36716#23567#20889
          'string.upper '#36716#22823#20889
          'string.reverse '#21453#36716#23383#31526#20018)
      end
      object Button13: TButton
        Left = 16
        Top = 102
        Width = 75
        Height = 25
        Caption = #21464#37327
        TabOrder = 1
        OnClick = Button13Click
      end
      object Button14: TButton
        Left = 16
        Top = 71
        Width = 75
        Height = 25
        Caption = #27880#37322
        TabOrder = 2
        OnClick = Button14Click
      end
      object Button15: TButton
        Left = 16
        Top = 133
        Width = 75
        Height = 25
        Caption = #26465#20214#35821#21477
        TabOrder = 3
        OnClick = Button15Click
      end
      object Button16: TButton
        Left = 112
        Top = 71
        Width = 75
        Height = 25
        Caption = #24490#29615
        TabOrder = 4
        OnClick = Button16Click
      end
      object Button17: TButton
        Left = 112
        Top = 102
        Width = 75
        Height = 25
        Caption = #20989#25968
        TabOrder = 5
        OnClick = Button17Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #27169#25311#37327
      ImageIndex = 1
      object GroupBox1: TGroupBox
        Left = 0
        Top = 3
        Width = 430
        Height = 143
        Caption = #22810#36335'ADC'#20302#36895#37319#38598#37197#32622
        TabOrder = 0
        object Label3: TLabel
          Left = 178
          Top = 28
          Width = 72
          Height = 13
          Caption = #27169#25311#36890#36947#23450#20041
        end
        object Label1: TLabel
          Left = 359
          Top = 83
          Width = 50
          Height = 13
          Caption = '(1.2-5.0V)'
        end
        object Label2: TLabel
          Left = 158
          Top = 93
          Width = 14
          Height = 13
          Caption = 'mV'
        end
        object Label4: TLabel
          Left = 158
          Top = 118
          Width = 13
          Height = 13
          Caption = 'uA'
        end
        object ComboBoxAiCh: TComboBox
          Left = 255
          Top = 25
          Width = 137
          Height = 21
          ItemIndex = 0
          TabOrder = 0
          Text = '0 - CH1'#30005#21387
          Items.Strings = (
            '0 - CH1'#30005#21387
            '1 - CH2'#30005#21387'    '
            '2 - '#39640#20391#36127#36733#30005#21387
            '3 - '#39640#31471#36127#36733#30005#27969
            '4 - TVCC'#30005#21387
            '5 - TVCC'#30005#27969
            '6 - NTC'#28909#25935#30005#38459#38459#20540
            '7 - '#22806#37096#20379#30005#30005#21387
            '8 -  USB'#20379#30005#30005#21387)
        end
        object Button3: TButton
          Left = 11
          Top = 23
          Width = 118
          Height = 25
          Caption = #37197#32622'ADC'#37319#38598
          TabOrder = 1
          OnClick = Button3Click
        end
        object ButtonReadAdc: TButton
          Left = 178
          Top = 52
          Width = 89
          Height = 25
          Caption = #35835'ADC'#20540
          TabOrder = 2
          OnClick = ButtonReadAdcClick
        end
        object Button1: TButton
          Left = 303
          Top = 52
          Width = 89
          Height = 25
          Caption = #35835#27169#25311#37327#20540
          TabOrder = 3
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 11
          Top = 81
          Width = 72
          Height = 25
          Caption = #24320#21551'DAC'
          TabOrder = 4
          OnClick = Button2Click
        end
        object Button4: TButton
          Left = 11
          Top = 112
          Width = 72
          Height = 25
          Caption = #20851#38381'DAC'
          TabOrder = 5
          OnClick = Button4Click
        end
        object Button5: TButton
          Left = 178
          Top = 83
          Width = 89
          Height = 25
          Caption = #35774#32622'DAC'#30005#21387
          TabOrder = 6
          OnClick = Button5Click
        end
        object Button6: TButton
          Left = 178
          Top = 111
          Width = 89
          Height = 25
          Caption = #35774#32622'DAC'#30005#27969
          TabOrder = 7
          OnClick = Button6Click
        end
        object Button7: TButton
          Left = 303
          Top = 107
          Width = 89
          Height = 25
          Caption = #35774#32622'TVCC'#30005#21387
          TabOrder = 8
          OnClick = Button7Click
        end
        object EditTVCC: TEdit
          Left = 306
          Top = 83
          Width = 47
          Height = 21
          TabOrder = 9
          Text = '3.3'
        end
        object EditMV: TEdit
          Left = 108
          Top = 85
          Width = 47
          Height = 21
          TabOrder = 10
          Text = '3300'
        end
        object EditUA: TEdit
          Left = 107
          Top = 112
          Width = 47
          Height = 21
          TabOrder = 11
          Text = '4000'
        end
      end
    end
    object GPIO: TTabSheet
      Caption = 'GPIO'
      ImageIndex = 2
      object Label5: TLabel
        Left = 19
        Top = 12
        Width = 49
        Height = 13
        Caption = #36873#25321'GPIO'
      end
      object Label6: TLabel
        Left = 144
        Top = 12
        Width = 61
        Height = 13
        Caption = 'GPIO'#27169#24335#65306
      end
      object Button8: TButton
        Left = 271
        Top = 28
        Width = 75
        Height = 25
        Caption = #37197#32622'GPIO'
        TabOrder = 0
        OnClick = Button8Click
      end
      object ComboBoxGpioMode: TComboBox
        Left = 151
        Top = 31
        Width = 114
        Height = 21
        DropDownCount = 20
        ItemIndex = 1
        TabOrder = 1
        Text = '1-GPIO_OUT'
        Items.Strings = (
          '0-GPIO_IN'
          '1-GPIO_OUT'
          '2-FMC_OUT'
          '3-FMC_NOE'
          '4-FMC_NWE'
          '5-UART'
          '6-CAN    '
          '7-I2C    '
          '8-SWD_OUT    '
          '9-SPI')
      end
      object ComboBoxGpioId: TComboBox
        Left = 18
        Top = 31
        Width = 95
        Height = 21
        DropDownCount = 20
        ItemIndex = 0
        TabOrder = 2
        Text = 'D0'
        Items.Strings = (
          'D0'
          'D1'
          'D2'
          'D3'
          'D4'
          'D5'
          'D6'
          'D7'
          'D8'
          'D9')
      end
      object Button9: TButton
        Left = 18
        Top = 68
        Width = 95
        Height = 25
        Caption = 'GPIO'#35774#32622#20026'1'
        TabOrder = 3
        OnClick = Button9Click
      end
      object Button10: TButton
        Left = 18
        Top = 99
        Width = 95
        Height = 25
        Caption = 'GPIO'#35774#32622#20026'0'
        TabOrder = 4
        OnClick = Button10Click
      end
      object Button11: TButton
        Left = 144
        Top = 67
        Width = 105
        Height = 25
        Caption = #35835#21333#20010'GPIO'#29366#24577
        TabOrder = 5
        OnClick = Button11Click
      end
      object Button12: TButton
        Left = 144
        Top = 98
        Width = 105
        Height = 25
        Caption = #35835#25972#20307'GPIO'#29366#24577
        TabOrder = 6
        OnClick = Button12Click
      end
    end
    object GUI: TTabSheet
      Caption = 'GUI'
      ImageIndex = 3
      object Button18: TButton
        Left = 3
        Top = 14
        Width = 41
        Height = 25
        Caption = #39068#33394
        TabOrder = 0
        OnClick = Button18Click
      end
      object EditColorRGB: TEdit
        Left = 50
        Top = 16
        Width = 135
        Height = 21
        TabOrder = 1
        Text = '0x0000'
      end
      object EditColorHex: TEdit
        Left = 191
        Top = 16
        Width = 65
        Height = 21
        TabOrder = 2
        Text = '0x0000'
      end
      object Button19: TButton
        Left = 3
        Top = 54
        Width = 91
        Height = 25
        Caption = 'API'#20989#25968#21015#34920
        TabOrder = 3
        OnClick = Button19Click
      end
      object Button20: TButton
        Left = 120
        Top = 54
        Width = 91
        Height = 25
        Caption = #23383#31526#34920
        TabOrder = 4
        OnClick = Button20Click
      end
    end
  end
  object Memo11: TMemo
    Left = 369
    Top = 208
    Width = 76
    Height = 270
    TabStop = False
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    Lines.Strings = (
      'Memo11')
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 1
    Visible = False
    WantTabs = True
    WordWrap = False
  end
  object CheckBoxClear: TCheckBox
    Left = 367
    Top = 9
    Width = 97
    Height = 17
    Caption = #27599#27425#28165#23631
    Checked = True
    State = cbChecked
    TabOrder = 2
  end
  object MemoTemp: TMemo
    Left = 241
    Top = 197
    Width = 185
    Height = 89
    TabOrder = 3
    Visible = False
  end
  object Memo1: TRichEdit
    Left = 8
    Top = 216
    Width = 455
    Height = 245
    TabStop = False
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = GB2312_CHARSET
    Font.Color = clNavy
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 4
    WantTabs = True
    Zoom = 100
  end
  object ColorDialog1: TColorDialog
    Left = 396
    Top = 40
  end
end
