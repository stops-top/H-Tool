object FormProg: TFormProg
  Left = 0
  Top = 0
  Anchors = []
  BorderStyle = bsNone
  Caption = #28903#24405#22120#37197#32622
  ClientHeight = 868
  ClientWidth = 560
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  DesignSize = (
    560
    868)
  PixelsPerInch = 96
  TextHeight = 14
  object Label36: TLabel
    Left = 37
    Top = 182
    Width = 27
    Height = 14
    Caption = 'A0'#65306
  end
  object PanelProg: TPanel
    Left = 0
    Top = 0
    Width = 560
    Height = 868
    Align = alClient
    BevelOuter = bvNone
    Color = 14411007
    ParentBackground = False
    TabOrder = 0
    object Label11: TLabel
      Left = 14
      Top = 499
      Width = 72
      Height = 14
      Caption = #36755#20986#25991#20214#22841#65306
    end
    object Label12: TLabel
      Left = 14
      Top = 531
      Width = 72
      Height = 14
      Caption = #36755#20986#25991#20214#21517#65306
    end
    object Label4: TLabel
      Left = 228
      Top = 568
      Width = 84
      Height = 14
      Caption = #20020#26102#25968#25454#25991#20214#65306
    end
    object Label3: TLabel
      Left = 384
      Top = 5
      Width = 36
      Height = 12
      Caption = #22120#20214#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
    end
    object LabelSerial: TLabel
      Left = 202
      Top = 5
      Width = 36
      Height = 12
      Caption = #31995#21015#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 12
      Top = 4
      Width = 66
      Height = 12
      Caption = #21378#21830'/'#20998#31867#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      OnClick = Label1Click
    end
    object LabelDeviceLuaFileName: TLabel
      Left = 121
      Top = 49
      Width = 74
      Height = 13
      Caption = 'STM32F0XX.lua'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LabelDeviceType: TLabel
      Left = 13
      Top = 49
      Width = 23
      Height = 13
      Caption = 'SWD'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LabelPCNote: TLabel
      Left = 253
      Top = 49
      Width = 293
      Height = 13
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Button5: TButton
      Left = 434
      Top = 490
      Width = 114
      Height = 28
      Caption = '1.'#29983#25104#37197#32622#25991#20214
      TabOrder = 0
      OnClick = Button5Click
    end
    object ButtonSelectFold: TButton
      Left = 389
      Top = 494
      Width = 36
      Height = 23
      Caption = '...'
      TabOrder = 1
      OnClick = ButtonSelectFoldClick
    end
    object MemoOutputDir: TMemo
      Left = 87
      Top = 495
      Width = 295
      Height = 21
      Enabled = False
      Lines.Strings = (
        'MemoOutputFolder')
      TabOrder = 2
    end
    object EditOutFileName: TEdit
      Left = 86
      Top = 526
      Width = 244
      Height = 22
      TabOrder = 3
      Text = 'demo'
    end
    object Button6: TButton
      Left = 435
      Top = 560
      Width = 113
      Height = 28
      Hint = #19979#36733#21040'H7-TOOL'#20869#23384#65292#24182#25191#34892#19968#27425#28903#24405
      Caption = '3.'#28903#24405#27979#35797
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      OnClick = Button6Click
    end
    object ComboBoxTempDataFile: TComboBox
      Left = 319
      Top = 563
      Width = 106
      Height = 22
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 5
      Text = #22266#20214#25991#20214
      Items.Strings = (
        #22266#20214#25991#20214
        '128.bin'
        '256.bin'
        '512.bin'
        '1K.bin'
        '2K.bin'
        '4K.bin'
        '8K_5A.bin'
        '8K_55.bin'
        '16K_5A.bin'
        '16K_55.bin'
        '32K_5A.bin'
        '32K_55.bin'
        '64K_5A.bin'
        '64K_55.bin'
        '128K_5A.bin'
        '128K_55.bin'
        '256K_5A.bin'
        '256K_55.bin'
        '512K_5A.bin'
        '512K_55.bin'
        '1M_5A.bin'
        '1M_55.bin'
        '2M_5A.bin'
        '2M_55.bin')
    end
    object Button7: TButton
      Left = 434
      Top = 525
      Width = 114
      Height = 28
      Caption = '2.'#20256#36865#21040'H7-TOOL'
      TabOrder = 6
      OnClick = Button7Click
    end
    object ComboBoxDevice: TComboBox
      Left = 384
      Top = 23
      Width = 162
      Height = 20
      Style = csDropDownList
      DropDownCount = 20
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnChange = ComboBoxDeviceChange
    end
    object ComboBoxSerial: TComboBox
      Left = 201
      Top = 23
      Width = 177
      Height = 20
      Style = csDropDownList
      DropDownCount = 20
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnChange = ComboBoxSerialChange
    end
    object ComboBoxManufacturer: TComboBox
      Left = 11
      Top = 22
      Width = 185
      Height = 20
      Style = csDropDownList
      DropDownCount = 20
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnChange = ComboBoxManufacturerChange
    end
    object Button17: TButton
      Left = 13
      Top = 559
      Width = 75
      Height = 28
      Caption = #25509#32447#35828#26126
      TabOrder = 10
      OnClick = Button17Click
    end
    object BitBtn1: TBitBtn
      Left = 349
      Top = 528
      Width = 76
      Height = 23
      Caption = #25171#24320#25991#20214#22841
      TabOrder = 11
      OnClick = BitBtn1Click
    end
    object Panel1: TPanel
      Left = 12
      Top = 606
      Width = 537
      Height = 123
      BevelOuter = bvNone
      Color = 14728954
      ParentBackground = False
      TabOrder = 12
      object Label39: TLabel
        Left = 19
        Top = 14
        Width = 36
        Height = 14
        Caption = #22522#22320#22336
      end
      object Label64: TLabel
        Left = 32
        Top = 45
        Width = 24
        Height = 14
        Caption = #20559#31227
      end
      object Label78: TLabel
        Left = 122
        Top = 46
        Width = 14
        Height = 14
        Caption = 'KB'
      end
      object Label79: TLabel
        Left = 336
        Top = 15
        Width = 48
        Height = 14
        Caption = #25991#20214#22823#23567
      end
      object Label80: TLabel
        Left = 497
        Top = 15
        Width = 14
        Height = 14
        Caption = 'KB'
      end
      object Label91: TLabel
        Left = 8
        Top = 69
        Width = 175
        Height = 14
        Caption = #20808#25191#34892#19979#36733'lua '#25165#33021#25191#34892#20854#20182#25805#20316
        Font.Charset = ANSI_CHARSET
        Font.Color = clGray
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object EditReadAddr: TEdit
        Left = 63
        Top = 10
        Width = 99
        Height = 22
        TabOrder = 0
        Text = '0x08000000'
      end
      object EditReadOffset: TEdit
        Left = 63
        Top = 41
        Width = 54
        Height = 22
        TabOrder = 1
        Text = '0'
      end
      object ButtonReadFlash: TButton
        Left = 170
        Top = 9
        Width = 60
        Height = 25
        Caption = #35835#21462'1K'
        TabOrder = 2
        OnClick = ButtonReadFlashClick
      end
      object Button4: TButton
        Left = 238
        Top = 8
        Width = 60
        Height = 26
        Caption = #19978#19968#39029
        TabOrder = 3
        OnClick = Button4Click
      end
      object Button13: TButton
        Left = 239
        Top = 40
        Width = 60
        Height = 26
        Caption = #19979#19968#39029
        TabOrder = 4
        OnClick = Button13Click
      end
      object Button3: TButton
        Left = 170
        Top = 41
        Width = 60
        Height = 26
        Caption = #20559#31227'0'
        TabOrder = 5
        OnClick = Button3Click
      end
      object EditReadFlashSize: TEdit
        Left = 394
        Top = 11
        Width = 97
        Height = 22
        TabOrder = 6
        Text = '1'
      end
      object Button14: TButton
        Left = 334
        Top = 39
        Width = 104
        Height = 27
        Caption = #35835#25968#25454#21040#25991#20214
        TabOrder = 7
        OnClick = Button14Click
      end
      object Button18: TButton
        Left = 124
        Top = 86
        Width = 60
        Height = 26
        Caption = #25481#30005#22797#20301
        TabOrder = 8
        OnClick = Button18Click
      end
      object Button21: TButton
        Left = 196
        Top = 86
        Width = 72
        Height = 26
        Caption = #25830#38500'FLASH'
        TabOrder = 9
        OnClick = Button21Click
      end
      object Button22: TButton
        Left = 280
        Top = 86
        Width = 72
        Height = 26
        Caption = #35299#38500#35835#20445#25252
        TabOrder = 10
        OnClick = Button22Click
      end
      object Button1: TButton
        Left = 7
        Top = 85
        Width = 102
        Height = 28
        Hint = #21482#19979#36733#21040'H7-TOOL'#20869#23384#65292#19981#25191#34892#28903#24405
        Caption = #19979#36733'lua('#19981#28903#24405')'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 11
        OnClick = Button1Click
      end
      object Button23: TButton
        Left = 368
        Top = 86
        Width = 72
        Height = 26
        Caption = #20351#33021#35835#20445#25252
        TabOrder = 12
        OnClick = Button23Click
      end
      object BitBtn2: TBitBtn
        Left = 444
        Top = 39
        Width = 73
        Height = 27
        Caption = #25171#24320#25991#20214#22841
        TabOrder = 13
        OnClick = BitBtn2Click
      end
      object Button24: TButton
        Left = 453
        Top = 86
        Width = 72
        Height = 26
        Caption = #35835#36873#39033#23383
        TabOrder = 14
        OnClick = Button24Click
      end
    end
  end
  object PageControl1: TPageControl
    Left = 12
    Top = 70
    Width = 539
    Height = 416
    ActivePage = TabSheet1
    Anchors = [akLeft, akTop, akRight]
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #22522#26412#37197#32622
      object Label10: TLabel
        Left = 18
        Top = 368
        Width = 60
        Height = 13
        Caption = #31243#24207#27880#37322#65306
      end
      object GroupBox3: TGroupBox
        Left = 18
        Top = 19
        Width = 498
        Height = 120
        Caption = #22522#26412#21442#25968
        TabOrder = 0
        object Label5: TLabel
          Left = 233
          Top = 58
          Width = 60
          Height = 13
          Caption = #26657#39564#26041#24335#65306
        end
        object Label6: TLabel
          Left = 17
          Top = 23
          Width = 62
          Height = 13
          Caption = 'TVCC'#30005#21387#65306
        end
        object Label7: TLabel
          Left = 134
          Top = 23
          Width = 54
          Height = 13
          Caption = '(1.2~5.0V)'
        end
        object Label60: TLabel
          Left = 233
          Top = 91
          Width = 48
          Height = 13
          Caption = #36873#39033#23383#65306
        end
        object Label56: TLabel
          Left = 233
          Top = 23
          Width = 52
          Height = 13
          Caption = #22797#20301#27169#24335':'
        end
        object ComboBoxVerifyMode: TComboBox
          Left = 310
          Top = 52
          Width = 142
          Height = 21
          Style = csDropDownList
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ItemIndex = 1
          ParentFont = False
          TabOrder = 0
          Text = '1-'#35835#22238#26657#39564
          Items.Strings = (
            '0-FLM_CRC'#25110#35835#22238#26657#39564
            '1-'#35835#22238#26657#39564
            '2-'#36719#20214'CRC'
            '3-STM32'#30828#20214'CRC')
        end
        object CheckBoxRemoveProtect: TCheckBox
          Left = 19
          Top = 56
          Width = 121
          Height = 17
          Caption = #33258#21160#35299#38500#35835#20889#20445#25252
          Checked = True
          State = cbChecked
          TabOrder = 1
        end
        object CheckBoxAtfterAuotReset: TCheckBox
          Left = 19
          Top = 87
          Width = 121
          Height = 17
          Caption = #28903#24405#23436#27605#33258#21160#22797#20301
          Checked = True
          State = cbChecked
          TabOrder = 2
        end
        object EditTVCC: TEdit
          Left = 84
          Top = 18
          Width = 38
          Height = 21
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Text = '3.3'
        end
        object ComboBoxOB: TComboBox
          Left = 310
          Top = 83
          Width = 142
          Height = 21
          Style = csDropDownList
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ItemIndex = 0
          ParentFont = False
          TabOrder = 4
          Text = '0-'#19981#20889#36873#39033#23383
          Items.Strings = (
            '0-'#19981#20889#36873#39033#23383
            '1-'#20889#26080#20445#25252#20540
            '2-'#20889#26377#20445#25252#20540)
        end
        object ComboBoxResetMode: TComboBox
          Left = 310
          Top = 17
          Width = 142
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 5
          Text = '0-'#33258#21160#27169#24335'('#36719#20214')'
          Items.Strings = (
            '0-'#33258#21160#27169#24335'('#36719#20214')'
            '1-'#36719#20214#22797#20301
            '2-'#30828#20214#22797#20301)
        end
      end
      object EditNote1: TEdit
        Left = 84
        Top = 362
        Width = 316
        Height = 21
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = #28436#31034#31243#24207
      end
      object PageControl2: TPageControl
        Left = 18
        Top = 163
        Width = 498
        Height = 193
        ActivePage = TabSheet8
        TabOrder = 2
        object TabSheet8: TTabSheet
          Caption = #22266#20214#25991#20214'1-5'
          object Label13: TLabel
            Left = 244
            Top = 8
            Width = 48
            Height = 13
            Caption = #28903#24405#22320#22336
          end
          object Label14: TLabel
            Left = 323
            Top = 8
            Width = 48
            Height = 13
            Caption = #31639#27861#36873#25321
          end
          object Label15: TLabel
            Left = 44
            Top = 7
            Width = 36
            Height = 13
            Caption = #25991#20214#21517
          end
          object Label69: TLabel
            Left = 439
            Top = 10
            Width = 48
            Height = 13
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            Caption = #25972#29255#25830#38500
          end
          object EditDataFile1: TEdit
            Left = 44
            Top = 30
            Width = 164
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            Text = 'DataFile1.bin'
          end
          object CheckBoxDataEnable1: TCheckBox
            Left = 5
            Top = 33
            Width = 34
            Height = 17
            Caption = '#1'
            Checked = True
            Enabled = False
            State = cbChecked
            TabOrder = 1
          end
          object CheckBoxDataEnable2: TCheckBox
            Left = 5
            Top = 58
            Width = 34
            Height = 17
            Caption = '#2'
            TabOrder = 2
          end
          object EditDataFile2: TEdit
            Left = 45
            Top = 56
            Width = 164
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            Text = 'DataFile2.bin'
          end
          object CheckBoxDataEnable3: TCheckBox
            Left = 5
            Top = 85
            Width = 36
            Height = 17
            Caption = '#3'
            TabOrder = 4
          end
          object EditDataFile3: TEdit
            Left = 45
            Top = 83
            Width = 164
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 5
            Text = 'DataFile3.bin'
          end
          object ButtonFile1: TButton
            Left = 213
            Top = 25
            Width = 28
            Height = 25
            Caption = '...'
            TabOrder = 6
            OnClick = ButtonFile1Click
          end
          object ButtonFile2: TButton
            Left = 212
            Top = 55
            Width = 28
            Height = 22
            Caption = '...'
            TabOrder = 7
            OnClick = ButtonFile1Click
          end
          object EditDataAddress1: TEdit
            Left = 244
            Top = 29
            Width = 72
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 8
            Text = '0'
          end
          object EditDataAddress2: TEdit
            Left = 244
            Top = 56
            Width = 72
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 9
            Text = '0'
          end
          object EditDataAddress3: TEdit
            Left = 243
            Top = 82
            Width = 72
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 10
            Text = '0'
          end
          object ComboBoxDataAlgo1: TComboBox
            Left = 322
            Top = 28
            Width = 119
            Height = 21
            DoubleBuffered = True
            DropDownCount = 12
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentDoubleBuffered = False
            ParentFont = False
            TabOrder = 11
            Text = 'AlgoFile_FLASH'
            Items.Strings = (
              'AlgoFile_FLASH'
              'AlgoFile_EEPROM'
              'AlgoFile_QSPI'
              'AlgoFile_OTP'
              'AlgoFile_AP'
              'AlgoFile_LD'
              'AlgoFile_CFG'
              'AlgoFile_DAT')
          end
          object ComboBoxDataAlgo2: TComboBox
            Left = 322
            Top = 55
            Width = 119
            Height = 21
            DoubleBuffered = True
            DropDownCount = 12
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentDoubleBuffered = False
            ParentFont = False
            TabOrder = 12
            Text = 'AlgoFile_FLASH'
            Items.Strings = (
              'AlgoFile_FLASH'
              'AlgoFile_EEPROM'
              'AlgoFile_QSPI'
              'AlgoFile_OTP')
          end
          object ComboBoxDataAlgo3: TComboBox
            Left = 322
            Top = 84
            Width = 119
            Height = 21
            DoubleBuffered = True
            DropDownCount = 12
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentDoubleBuffered = False
            ParentFont = False
            TabOrder = 13
            Text = 'AlgoFile_FLASH'
            Items.Strings = (
              'AlgoFile_FLASH'
              'AlgoFile_EEPROM'
              'AlgoFile_QSPI'
              'AlgoFile_OTP')
          end
          object ButtonFile3: TButton
            Left = 212
            Top = 82
            Width = 28
            Height = 22
            Caption = '...'
            TabOrder = 14
            OnClick = ButtonFile1Click
          end
          object CheckBoxDataEnable4: TCheckBox
            Left = 5
            Top = 115
            Width = 34
            Height = 17
            Caption = '#4'
            TabOrder = 15
          end
          object EditDataFile4: TEdit
            Left = 45
            Top = 112
            Width = 164
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 16
            Text = 'DataFile2.bin'
          end
          object CheckBoxDataEnable5: TCheckBox
            Left = 5
            Top = 142
            Width = 36
            Height = 17
            Caption = '#5'
            TabOrder = 17
          end
          object EditDataFile5: TEdit
            Left = 45
            Top = 139
            Width = 164
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 18
            Text = 'DataFile3.bin'
          end
          object ButtonFile4: TButton
            Left = 212
            Top = 112
            Width = 28
            Height = 22
            Caption = '...'
            TabOrder = 19
            OnClick = ButtonFile1Click
          end
          object EditDataAddress4: TEdit
            Left = 244
            Top = 111
            Width = 72
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 20
            Text = '0'
          end
          object EditDataAddress5: TEdit
            Left = 243
            Top = 138
            Width = 72
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 21
            Text = '0'
          end
          object ComboBoxDataAlgo4: TComboBox
            Left = 322
            Top = 111
            Width = 119
            Height = 21
            DropDownCount = 12
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 22
            Text = 'AlgoFile_FLASH'
            Items.Strings = (
              'AlgoFile_FLASH'
              'AlgoFile_EEPROM'
              'AlgoFile_QSPI'
              'AlgoFile_OTP')
          end
          object ComboBoxDataAlgo5: TComboBox
            Left = 322
            Top = 138
            Width = 119
            Height = 21
            DropDownCount = 12
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 23
            Text = 'AlgoFile_FLASH'
            Items.Strings = (
              'AlgoFile_FLASH'
              'AlgoFile_EEPROM'
              'AlgoFile_QSPI'
              'AlgoFile_OTP')
          end
          object ButtonFile5: TButton
            Left = 212
            Top = 138
            Width = 28
            Height = 22
            Caption = '...'
            TabOrder = 24
            OnClick = ButtonFile1Click
          end
          object CheckBoxEraseChip_1: TCheckBox
            Left = 454
            Top = 29
            Width = 17
            Height = 17
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            Checked = True
            State = cbChecked
            TabOrder = 25
          end
          object CheckBoxEraseChip_2: TCheckBox
            Left = 454
            Top = 57
            Width = 17
            Height = 17
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            TabOrder = 26
          end
          object CheckBoxEraseChip_3: TCheckBox
            Left = 454
            Top = 88
            Width = 17
            Height = 17
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            TabOrder = 27
          end
          object CheckBoxEraseChip_4: TCheckBox
            Left = 454
            Top = 114
            Width = 17
            Height = 17
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            TabOrder = 28
          end
          object CheckBoxEraseChip_5: TCheckBox
            Left = 454
            Top = 139
            Width = 17
            Height = 17
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            TabOrder = 29
          end
        end
        object TabSheet9: TTabSheet
          Caption = #22266#20214#25991#20214'6-10'
          ImageIndex = 1
          object Label65: TLabel
            Left = 243
            Top = 10
            Width = 48
            Height = 13
            Caption = #28903#24405#22320#22336
          end
          object Label66: TLabel
            Left = 322
            Top = 10
            Width = 48
            Height = 13
            Caption = #31639#27861#36873#25321
          end
          object Label67: TLabel
            Left = 43
            Top = 9
            Width = 36
            Height = 13
            Caption = #25991#20214#21517
          end
          object Label68: TLabel
            Left = 434
            Top = 13
            Width = 48
            Height = 13
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            Caption = #25972#29255#25830#38500
          end
          object EditDataFile6: TEdit
            Left = 42
            Top = 32
            Width = 164
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            Text = 'DataFile1.bin'
          end
          object CheckBoxDataEnable6: TCheckBox
            Left = 5
            Top = 34
            Width = 34
            Height = 17
            Caption = '#6'
            TabOrder = 1
          end
          object CheckBoxDataEnable7: TCheckBox
            Left = 5
            Top = 60
            Width = 34
            Height = 17
            Caption = '#7'
            TabOrder = 2
          end
          object EditDataFile7: TEdit
            Left = 42
            Top = 58
            Width = 164
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            Text = 'DataFile2.bin'
          end
          object CheckBoxDataEnable8: TCheckBox
            Left = 4
            Top = 88
            Width = 36
            Height = 17
            Caption = '#8'
            TabOrder = 4
          end
          object EditDataFile8: TEdit
            Left = 42
            Top = 85
            Width = 164
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 5
            Text = 'DataFile3.bin'
          end
          object ButtonFile6: TButton
            Left = 209
            Top = 29
            Width = 28
            Height = 25
            Caption = '...'
            TabOrder = 6
            OnClick = ButtonFile1Click
          end
          object ButtonFile7: TButton
            Left = 209
            Top = 59
            Width = 28
            Height = 22
            Caption = '...'
            TabOrder = 7
            OnClick = ButtonFile1Click
          end
          object EditDataAddress6: TEdit
            Left = 243
            Top = 32
            Width = 72
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 8
            Text = '0'
          end
          object EditDataAddress7: TEdit
            Left = 243
            Top = 59
            Width = 72
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 9
            Text = '0'
          end
          object EditDataAddress8: TEdit
            Left = 242
            Top = 84
            Width = 72
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 10
            Text = '0'
          end
          object ComboBoxDataAlgo6: TComboBox
            Left = 321
            Top = 32
            Width = 119
            Height = 21
            DropDownCount = 12
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 11
            Text = 'AlgoFile_FLASH'
            Items.Strings = (
              'AlgoFile_FLASH'
              'AlgoFile_EEPROM'
              'AlgoFile_QSPI'
              'AlgoFile_OTP'
              'AlgoFile_AP'
              'AlgoFile_LD'
              'AlgoFile_CFG'
              'AlgoFile_DAT')
          end
          object ComboBoxDataAlgo7: TComboBox
            Left = 321
            Top = 57
            Width = 119
            Height = 21
            DropDownCount = 12
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 12
            Text = 'AlgoFile_FLASH'
            Items.Strings = (
              'AlgoFile_FLASH'
              'AlgoFile_EEPROM'
              'AlgoFile_QSPI'
              'AlgoFile_OTP')
          end
          object ComboBoxDataAlgo8: TComboBox
            Left = 321
            Top = 86
            Width = 119
            Height = 21
            DropDownCount = 12
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 13
            Text = 'AlgoFile_FLASH'
            Items.Strings = (
              'AlgoFile_FLASH'
              'AlgoFile_EEPROM'
              'AlgoFile_QSPI'
              'AlgoFile_OTP')
          end
          object ButtonFile8: TButton
            Left = 209
            Top = 87
            Width = 28
            Height = 22
            Caption = '...'
            TabOrder = 14
            OnClick = ButtonFile1Click
          end
          object CheckBoxEraseChip_6: TCheckBox
            Left = 453
            Top = 33
            Width = 17
            Height = 17
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            TabOrder = 15
          end
          object CheckBoxEraseChip_7: TCheckBox
            Left = 453
            Top = 60
            Width = 17
            Height = 17
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            TabOrder = 16
          end
          object CheckBoxEraseChip_8: TCheckBox
            Left = 453
            Top = 86
            Width = 17
            Height = 17
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            TabOrder = 17
          end
          object CheckBoxDataEnable9: TCheckBox
            Left = 5
            Top = 115
            Width = 34
            Height = 17
            Caption = '#9'
            TabOrder = 18
          end
          object EditDataFile9: TEdit
            Left = 42
            Top = 113
            Width = 164
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 19
            Text = 'DataFile2.bin'
          end
          object CheckBoxDataEnable10: TCheckBox
            Left = 4
            Top = 143
            Width = 36
            Height = 17
            Caption = '#10'
            TabOrder = 20
          end
          object EditDataFile10: TEdit
            Left = 42
            Top = 142
            Width = 164
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 21
            Text = 'DataFile3.bin'
          end
          object ButtonFile9: TButton
            Left = 209
            Top = 115
            Width = 28
            Height = 22
            Caption = '...'
            TabOrder = 22
            OnClick = ButtonFile1Click
          end
          object EditDataAddress9: TEdit
            Left = 243
            Top = 113
            Width = 72
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 23
            Text = '0'
          end
          object EditDataAddress10: TEdit
            Left = 243
            Top = 141
            Width = 72
            Height = 21
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 24
            Text = '0'
          end
          object ComboBoxDataAlgo9: TComboBox
            Left = 321
            Top = 113
            Width = 119
            Height = 21
            DropDownCount = 12
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 25
            Text = 'AlgoFile_FLASH'
            Items.Strings = (
              'AlgoFile_FLASH'
              'AlgoFile_EEPROM'
              'AlgoFile_QSPI'
              'AlgoFile_OTP')
          end
          object ComboBoxDataAlgo10: TComboBox
            Left = 321
            Top = 140
            Width = 119
            Height = 21
            DropDownCount = 12
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 26
            Text = 'AlgoFile_FLASH'
            Items.Strings = (
              'AlgoFile_FLASH'
              'AlgoFile_EEPROM'
              'AlgoFile_QSPI'
              'AlgoFile_OTP')
          end
          object ButtonFile10: TButton
            Left = 208
            Top = 141
            Width = 28
            Height = 22
            Caption = '...'
            TabOrder = 27
            OnClick = ButtonFile1Click
          end
          object CheckBoxEraseChip_9: TCheckBox
            Left = 453
            Top = 113
            Width = 17
            Height = 17
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            TabOrder = 28
          end
          object CheckBoxEraseChip_10: TCheckBox
            Left = 453
            Top = 142
            Width = 17
            Height = 17
            Hint = #25171#38057#34920#31034#28903#24405#26412#25991#20214#26102#65292#21516#26102#20889#20837#28378#30721#21644'UID'#21152#23494#25968#25454
            TabOrder = 29
          end
        end
      end
      object Button2: TButton
        Left = 461
        Top = 161
        Width = 34
        Height = 20
        Caption = #24110#21161
        TabOrder = 3
        OnClick = Button2Click
      end
    end
    object TabSheet6: TTabSheet
      Caption = ' '#39640#32423#37197#32622' '
      ImageIndex = 1
      object Label2: TLabel
        Left = 21
        Top = 162
        Width = 84
        Height = 13
        Caption = #20854#20182#37197#32622#21442#25968#65306
      end
      object GroupBox15: TGroupBox
        Left = 18
        Top = 20
        Width = 495
        Height = 125
        Caption = #36873#39033#23383#37197#32622#65288'OB = Option bytes'#65289
        TabOrder = 0
        object Label57: TLabel
          Left = 18
          Top = 27
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label58: TLabel
          Left = 16
          Top = 62
          Width = 48
          Height = 13
          Caption = #26080#20445#25252#65306
        end
        object Label59: TLabel
          Left = 15
          Top = 96
          Width = 48
          Height = 13
          Caption = #26377#20445#25252#65306
        end
        object EditOBAddr: TEdit
          Left = 75
          Top = 24
          Width = 333
          Height = 21
          Color = clInactiveCaption
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          ParentShowHint = False
          ReadOnly = True
          ShowHint = True
          TabOrder = 0
        end
        object EditSecureOff: TEdit
          Left = 74
          Top = 60
          Width = 399
          Height = 21
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
        object EditSecureOn: TEdit
          Left = 75
          Top = 93
          Width = 398
          Height = 21
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
        end
        object ButtonOBhelp: TButton
          Left = 421
          Top = 22
          Width = 52
          Height = 25
          Caption = #24110#21161
          TabOrder = 3
          OnClick = ButtonOBhelpClick
        end
      end
      object ValueListEditor1: TValueListEditor
        Left = 18
        Top = 181
        Width = 495
        Height = 180
        DisplayOptions = [doColumnTitles, doKeyColFixed]
        FixedColor = clWindow
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goThumbTracking]
        Strings.Strings = (
          #21333#36335#27169#24335#26102#38047#24310#36831'=0'
          #22810#36335#27169#24335#26102#38047#24310#36831'=0'
          #35835#20869#23384#25351#20196#38388#24310#36831'(us)=0'
          #30828#20214#22797#20301#21518#24310#36831'(ms)=0'
          #35299#38500#20445#25252#21518#26029#30005#22797#20301'=0 --'#20851#38381
          #35299#38500#20445#25252#26102#24310#36831#26029#30005'(ms)=0'
          #35299#38500#20445#25252#26029#30005#26102#38271'(ms)=200'
          #37325#26032#19978#30005#21518#30340#24310#36831'(ms)=20'
          'SPI'#20018#34892'Flash'#35835#27169#24335'=0 --'#21333#32447#27169#24335
          ''
          ''
          '')
        TabOrder = 1
        TitleCaptions.Strings = (
          #21442#25968#21517#31216
          #21442#25968#20540)
        OnGetPickList = ValueListEditor1GetPickList
        ColWidths = (
          250
          222)
      end
    end
    object TabSheet2: TTabSheet
      Caption = ' '#28378#30721' '
      ImageIndex = 1
      object GroupBox4: TGroupBox
        Left = 13
        Top = 3
        Width = 519
        Height = 162
        Caption = #28378#30721
        TabOrder = 0
        object Label17: TLabel
          Left = 11
          Top = 72
          Width = 48
          Height = 13
          Caption = #21021#22987#20540#65306
        end
        object Label18: TLabel
          Left = 156
          Top = 75
          Width = 60
          Height = 13
          Caption = #23384#20648#22320#22336#65306
        end
        object Label23: TLabel
          Left = 321
          Top = 75
          Width = 36
          Height = 13
          Caption = #26684#24335#65306
        end
        object Label22: TLabel
          Left = 10
          Top = 46
          Width = 60
          Height = 13
          Caption = #28378#30721#31867#22411#65306
        end
        object Label28: TLabel
          Left = 397
          Top = 45
          Width = 60
          Height = 13
          Caption = #28378#30721#38271#24230#65306
        end
        object Label26: TLabel
          Left = 29
          Top = 133
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label41: TLabel
          Left = 201
          Top = 134
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label48: TLabel
          Left = 355
          Top = 133
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label70: TLabel
          Left = 9
          Top = 23
          Width = 60
          Height = 13
          Caption = #28378#30721#21551#29992#65306
        end
        object Label42: TLabel
          Left = 6
          Top = 110
          Width = 60
          Height = 13
          Caption = #24037#21378#20195#30721#65306
        end
        object Label44: TLabel
          Left = 178
          Top = 108
          Width = 60
          Height = 13
          Caption = #24037#20855#32534#21495#65306
        end
        object Label77: TLabel
          Left = 350
          Top = 108
          Width = 60
          Height = 13
          Caption = #28903#24405#36890#36947#65306
        end
        object ComboBoxSNEndain: TComboBox
          Left = 365
          Top = 73
          Width = 140
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 0
          Text = '0-'#20108#36827#21046#23567#31471
          Items.Strings = (
            '0-'#20108#36827#21046#23567#31471
            '1-'#20108#36827#21046#22823#31471
            '2-ASCII'#23383#31526#20018)
        end
        object EditSNInitValue: TEdit
          Left = 62
          Top = 69
          Width = 57
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object EditSNAddr: TEdit
          Left = 218
          Top = 71
          Width = 77
          Height = 21
          TabOrder = 2
          Text = '0x08000000'
        end
        object ComboBoxSNType: TComboBox
          Left = 76
          Top = 42
          Width = 258
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 3
          Text = '0-'#26222#36890#28378#30721','#39034#24207#21152'1'
          Items.Strings = (
            '0-'#26222#36890#28378#30721','#39034#24207#21152'1'
            '1-1970'#24180#22522#20934#31186#25968', 4-8'#23383#33410)
        end
        object ComboBoxSNLen: TComboBox
          Left = 464
          Top = 42
          Width = 40
          Height = 21
          Style = csDropDownList
          ItemIndex = 4
          TabOrder = 4
          Text = '4'
          Items.Strings = (
            '0'
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
            '11'
            '12'
            '13'
            '14'
            '15'
            '16')
        end
        object EditToolFactoryAddr: TEdit
          Left = 62
          Top = 130
          Width = 94
          Height = 21
          TabOrder = 5
          Text = '0x08000000'
        end
        object EditToolSnAddr: TEdit
          Left = 237
          Top = 131
          Width = 94
          Height = 21
          TabOrder = 6
          Text = '0x08000000'
        end
        object EditToolChannelAddr: TEdit
          Left = 412
          Top = 131
          Width = 93
          Height = 21
          TabOrder = 7
          Text = '0x08000000'
        end
        object ComboBoxSNEnable: TComboBox
          Left = 75
          Top = 15
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 8
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
        object ComboBoxToolFactory: TComboBox
          Left = 62
          Top = 103
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 9
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
        object ComboBoxToolSn: TComboBox
          Left = 237
          Top = 105
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 10
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
        object ComboBoxToolChannel: TComboBox
          Left = 416
          Top = 104
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 11
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
      end
      object GroupBox5: TGroupBox
        Left = 13
        Top = 171
        Width = 519
        Height = 128
        Caption = #24120#37327#20540' '#65288'HEX'#65289
        TabOrder = 1
        object Label20: TLabel
          Left = 386
          Top = 19
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label19: TLabel
          Left = 386
          Top = 46
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label21: TLabel
          Left = 386
          Top = 73
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label24: TLabel
          Left = 386
          Top = 100
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label71: TLabel
          Left = 10
          Top = 21
          Width = 42
          Height = 13
          Caption = #24120#37327'1'#65306
        end
        object Label72: TLabel
          Left = 11
          Top = 48
          Width = 42
          Height = 13
          Caption = #24120#37327'2'#65306
        end
        object Label73: TLabel
          Left = 10
          Top = 75
          Width = 42
          Height = 13
          Caption = #24120#37327'3'#65306
        end
        object Label74: TLabel
          Left = 11
          Top = 102
          Width = 42
          Height = 13
          Caption = #24120#37327'4'#65306
        end
        object EditConstAddr_1: TEdit
          Left = 423
          Top = 16
          Width = 70
          Height = 21
          TabOrder = 0
          Text = '0x08000000'
        end
        object EditConstValue_1: TEdit
          Left = 152
          Top = 16
          Width = 221
          Height = 21
          TabOrder = 1
          Text = '44 9E F9'
        end
        object EditConstAddr_2: TEdit
          Left = 423
          Top = 42
          Width = 70
          Height = 21
          TabOrder = 2
          Text = '0x08000000'
        end
        object EditConstValue_2: TEdit
          Left = 152
          Top = 44
          Width = 221
          Height = 21
          TabOrder = 3
          Text = '44 9E F9'
        end
        object EditConstAddr_3: TEdit
          Left = 423
          Top = 69
          Width = 70
          Height = 21
          TabOrder = 4
          Text = '0x08000000'
        end
        object EditConstValue_3: TEdit
          Left = 152
          Top = 70
          Width = 221
          Height = 21
          TabOrder = 5
          Text = '44 9E F9'
        end
        object EditConstAddr_4: TEdit
          Left = 422
          Top = 95
          Width = 70
          Height = 21
          TabOrder = 6
          Text = '0x08000000'
        end
        object EditConstValue_4: TEdit
          Left = 152
          Top = 97
          Width = 221
          Height = 21
          TabOrder = 7
          Text = '44 9E F9'
        end
        object ComboBoxConstEnable_1: TComboBox
          Left = 52
          Top = 17
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 8
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
        object ComboBoxConstEnable_2: TComboBox
          Left = 53
          Top = 44
          Width = 93
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 9
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
        object ComboBoxConstEnable_3: TComboBox
          Left = 52
          Top = 71
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 10
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
        object ComboBoxConstEnable_4: TComboBox
          Left = 52
          Top = 98
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 11
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
      end
      object GroupBox6: TGroupBox
        Left = 13
        Top = 305
        Width = 519
        Height = 72
        Caption = #29983#20135#26085#26399
        TabOrder = 2
        object Label27: TLabel
          Left = 341
          Top = 24
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label25: TLabel
          Left = 12
          Top = 47
          Width = 60
          Height = 13
          Caption = #26085#26399#26684#24335#65306
        end
        object Label75: TLabel
          Left = 11
          Top = 20
          Width = 60
          Height = 13
          Caption = #29983#20135#26085#26399#65306
        end
        object EditDateAddr: TEdit
          Left = 383
          Top = 16
          Width = 70
          Height = 21
          TabOrder = 0
          Text = '0x08000000'
        end
        object ComboBoxDateType: TComboBox
          Left = 78
          Top = 43
          Width = 375
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 1
          Text = '0-'#26102#38388'ASCII'#30721',14'#23383#33410',YYYY MM DD hh mm ss'
          Items.Strings = (
            '0-'#26102#38388'ASCII'#30721',14'#23383#33410',YYYY MM DD hh mm ss'
            '1-1970'#24180#22522#20934#31186#25968', 4'#23383#33410','#23567#31471
            '2-1970'#24180#22522#20934#31186#25968', 4'#23383#33410','#22823#31471
            '3-1970'#24180#22522#20934#31186#25968', 8'#23383#33410','#23567#31471
            '4-1970'#24180#22522#20934#31186#25968', 8'#23383#33410','#22823#31471)
        end
        object ComboBoxDate: TComboBox
          Left = 78
          Top = 15
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 2
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = ' UID'#21152#23494' '
      ImageIndex = 2
      object GroupBox7: TGroupBox
        Left = 16
        Top = 8
        Width = 150
        Height = 372
        Caption = #31639#27861#20844#24335
        TabOrder = 0
        object Label30: TLabel
          Left = 15
          Top = 321
          Width = 96
          Height = 13
          Caption = #36873#25321#31639#27861#38543#26426#25968#65306
        end
        object ComboBoxAlgoLua: TComboBox
          Left = 15
          Top = 19
          Width = 121
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 0
          Text = 'encrypt_001.lua'
          Items.Strings = (
            'encrypt_001.lua'
            'encrypt_002.lua'
            'encrypt_003.lua'
            'encrypt_004.lua'
            'encrypt_005.lua'
            'encrypt_006.lua'
            'encrypt_007.lua'
            'encrypt_008.lua'
            'encrypt_009.lua'
            'encrypt_010.lua'
            'encrypt_011.lua'
            'encrypt_012.lua'
            'encrypt_013.lua'
            'encrypt_014.lua'
            'encrypt_015.lua'
            'encrypt_016.lua'
            'encrypt_017.lua'
            'encrypt_018.lua'
            'encrypt_019.lua'
            'encrypt_020.lua'
            'encrypt_021.lua'
            'encrypt_022.lua'
            'encrypt_023.lua'
            'encrypt_024.lua'
            'encrypt_025.lua'
            'encrypt_026.lua'
            'encrypt_027.lua'
            'encrypt_028.lua'
            'encrypt_029.lua'
            'encrypt_030.lua'
            'encrypt_031.lua'
            'encrypt_032.lua'
            'encrypt_033.lua'
            'encrypt_034.lua'
            'encrypt_035.lua'
            'encrypt_036.lua'
            'encrypt_037.lua'
            'encrypt_038.lua'
            'encrypt_039.lua'
            'encrypt_040.lua'
            'encrypt_041.lua'
            'encrypt_042.lua'
            'encrypt_043.lua'
            'encrypt_044.lua'
            'encrypt_045.lua'
            'encrypt_046.lua'
            'encrypt_047.lua'
            'encrypt_048.lua'
            'encrypt_049.lua'
            'encrypt_050.lua'
            'encrypt_051.lua'
            'encrypt_052.lua'
            'encrypt_053.lua'
            'encrypt_054.lua'
            'encrypt_055.lua'
            'encrypt_056.lua'
            'encrypt_057.lua'
            'encrypt_058.lua'
            'encrypt_059.lua'
            'encrypt_060.lua'
            'encrypt_061.lua'
            'encrypt_062.lua'
            'encrypt_063.lua'
            'encrypt_064.lua'
            'encrypt_065.lua'
            'encrypt_066.lua'
            'encrypt_067.lua'
            'encrypt_068.lua'
            'encrypt_069.lua'
            'encrypt_070.lua'
            'encrypt_071.lua'
            'encrypt_072.lua'
            'encrypt_073.lua'
            'encrypt_074.lua'
            'encrypt_075.lua'
            'encrypt_076.lua'
            'encrypt_077.lua'
            'encrypt_078.lua'
            'encrypt_079.lua'
            'encrypt_080.lua'
            'encrypt_081.lua'
            'encrypt_082.lua'
            'encrypt_083.lua'
            'encrypt_084.lua'
            'encrypt_085.lua'
            'encrypt_086.lua'
            'encrypt_087.lua'
            'encrypt_088.lua'
            'encrypt_089.lua'
            'encrypt_090.lua'
            'encrypt_091.lua'
            'encrypt_092.lua'
            'encrypt_093.lua'
            'encrypt_094.lua'
            'encrypt_095.lua'
            'encrypt_096.lua'
            'encrypt_097.lua'
            'encrypt_098.lua'
            'encrypt_099.lua'
            'encrypt_100.lua'
            'encrypt_101.lua'
            'encrypt_102.lua'
            'encrypt_103.lua'
            'encrypt_104.lua'
            'encrypt_105.lua'
            'encrypt_106.lua'
            'encrypt_107.lua'
            'encrypt_108.lua'
            'encrypt_109.lua'
            'encrypt_110.lua'
            'encrypt_111.lua'
            'encrypt_112.lua'
            'encrypt_113.lua'
            'encrypt_114.lua'
            'encrypt_115.lua'
            'encrypt_116.lua'
            'encrypt_117.lua'
            'encrypt_118.lua'
            'encrypt_119.lua'
            'encrypt_120.lua'
            'encrypt_121.lua'
            'encrypt_122.lua'
            'encrypt_123.lua'
            'encrypt_124.lua'
            'encrypt_125.lua'
            'encrypt_126.lua'
            'encrypt_127.lua'
            'encrypt_128.lua'
            'encrypt_129.lua'
            'encrypt_130.lua'
            'encrypt_131.lua'
            'encrypt_132.lua'
            'encrypt_133.lua'
            'encrypt_134.lua'
            'encrypt_135.lua'
            'encrypt_136.lua'
            'encrypt_137.lua'
            'encrypt_138.lua'
            'encrypt_139.lua'
            'encrypt_140.lua'
            'encrypt_141.lua'
            'encrypt_142.lua'
            'encrypt_143.lua'
            'encrypt_144.lua'
            'encrypt_145.lua'
            'encrypt_146.lua'
            'encrypt_147.lua'
            'encrypt_148.lua'
            'encrypt_149.lua'
            'encrypt_150.lua'
            'encrypt_151.lua'
            'encrypt_152.lua'
            'encrypt_153.lua'
            'encrypt_154.lua'
            'encrypt_155.lua'
            'encrypt_156.lua'
            'encrypt_157.lua'
            'encrypt_158.lua'
            'encrypt_159.lua'
            'encrypt_160.lua'
            'encrypt_161.lua'
            'encrypt_162.lua'
            'encrypt_163.lua'
            'encrypt_164.lua'
            'encrypt_165.lua'
            'encrypt_166.lua'
            'encrypt_167.lua'
            'encrypt_168.lua'
            'encrypt_169.lua'
            'encrypt_170.lua'
            'encrypt_171.lua'
            'encrypt_172.lua'
            'encrypt_173.lua'
            'encrypt_174.lua'
            'encrypt_175.lua'
            'encrypt_176.lua'
            'encrypt_177.lua'
            'encrypt_178.lua'
            'encrypt_179.lua'
            'encrypt_180.lua'
            'encrypt_181.lua'
            'encrypt_182.lua'
            'encrypt_183.lua'
            'encrypt_184.lua'
            'encrypt_185.lua'
            'encrypt_186.lua'
            'encrypt_187.lua'
            'encrypt_188.lua'
            'encrypt_189.lua'
            'encrypt_190.lua'
            'encrypt_191.lua'
            'encrypt_192.lua'
            'encrypt_193.lua'
            'encrypt_194.lua'
            'encrypt_195.lua'
            'encrypt_196.lua'
            'encrypt_197.lua'
            'encrypt_198.lua'
            'encrypt_199.lua'
            'encrypt_200.lua')
        end
        object ValueListEditorA: TValueListEditor
          Left = 12
          Top = 46
          Width = 125
          Height = 269
          Options = [goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goAlwaysShowEditor, goThumbTracking]
          Strings.Strings = (
            'A1=1'
            'A2=2'
            'A3=3'
            'A4=4'
            'A5=5'
            'A6=6'
            'A7=7'
            'A8=8'
            'A9=9'
            'A10=10'
            'A11=11'
            'A12=12'
            'A13=13'
            'A14=14'
            'A15=15'
            'A16=16')
          TabOrder = 1
          TitleCaptions.Strings = (
            #21442#25968#21517
            #21442#25968#20540)
          ColWidths = (
            53
            49)
        end
        object ComboBoxInitValue: TComboBox
          Left = 12
          Top = 340
          Width = 123
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 2
          Text = '0-'#20351#29992#24120#37327
          Items.Strings = (
            '0-'#20351#29992#24120#37327
            '1-'#20351#29992#38543#26426#25968'#1'
            '2-'#20351#29992#38543#26426#25968'#2'
            '3-'#20351#29992#38543#26426#25968'#3'
            '4-'#20351#29992#38543#26426#25968'#4')
        end
      end
      object GroupBox8: TGroupBox
        Left = 187
        Top = 84
        Width = 325
        Height = 149
        Caption = #38543#26426#25968
        TabOrder = 1
        object Label32: TLabel
          Left = 268
          Top = 14
          Width = 36
          Height = 13
          Caption = #38271#24230#65306
        end
        object Label31: TLabel
          Left = 192
          Top = 14
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label43: TLabel
          Left = 19
          Top = 37
          Width = 54
          Height = 13
          Caption = #38543#26426#25968'1'#65306
        end
        object Label35: TLabel
          Left = 19
          Top = 67
          Width = 54
          Height = 13
          Caption = #38543#26426#25968'2'#65306
        end
        object Label37: TLabel
          Left = 19
          Top = 93
          Width = 54
          Height = 13
          Caption = #38543#26426#25968'3'#65306
        end
        object Label38: TLabel
          Left = 19
          Top = 123
          Width = 54
          Height = 13
          Caption = #38543#26426#25968'4'#65306
        end
        object EditAlgoRndAddr1: TEdit
          Left = 185
          Top = 32
          Width = 70
          Height = 21
          TabOrder = 0
          Text = '0x08000000'
        end
        object ComboBoxRndLen1: TComboBox
          Left = 262
          Top = 33
          Width = 52
          Height = 21
          Style = csDropDownList
          ItemIndex = 3
          TabOrder = 1
          Text = '4'
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
            '11'
            '12'
            '13'
            '14'
            '15'
            '16'
            '17'
            '18'
            '19'
            '20'
            '21'
            '22'
            '23'
            '24'
            '25'
            '26'
            '27'
            '28'
            '29'
            '30'
            '31'
            '32'
            '33'
            '34'
            '35'
            '36'
            '37'
            '38'
            '39'
            '40'
            '41'
            '42'
            '43'
            '44'
            '45'
            '46'
            '47'
            '48'
            '49'
            '50'
            '51'
            '52'
            '53'
            '54'
            '55'
            '56'
            '57'
            '58'
            '59'
            '60'
            '61'
            '62'
            '63'
            '64'
            '65'
            '66'
            '67'
            '68'
            '69'
            '70'
            '71'
            '72'
            '73'
            '74'
            '75'
            '76'
            '77'
            '78'
            '79'
            '80'
            '81'
            '82'
            '83'
            '84'
            '85'
            '86'
            '87'
            '88'
            '89'
            '90'
            '91'
            '92'
            '93'
            '94'
            '95'
            '96'
            '97'
            '98'
            '99'
            '100'
            '101'
            '102'
            '103'
            '104'
            '105'
            '106'
            '107'
            '108'
            '109'
            '110'
            '111'
            '112'
            '113'
            '114'
            '115'
            '116'
            '117'
            '118'
            '119'
            '120'
            '121'
            '122'
            '123'
            '124'
            '125'
            '126'
            '127'
            '128'
            '129'
            '130'
            '131'
            '132'
            '133'
            '134'
            '135'
            '136'
            '137'
            '138'
            '139'
            '140'
            '141'
            '142'
            '143'
            '144'
            '145'
            '146'
            '147'
            '148'
            '149'
            '150'
            '151'
            '152'
            '153'
            '154'
            '155'
            '156'
            '157'
            '158'
            '159'
            '160'
            '161'
            '162'
            '163'
            '164'
            '165'
            '166'
            '167'
            '168'
            '169'
            '170'
            '171'
            '172'
            '173'
            '174'
            '175'
            '176'
            '177'
            '178'
            '179'
            '180'
            '181'
            '182'
            '183'
            '184'
            '185'
            '186'
            '187'
            '188'
            '189'
            '190'
            '191'
            '192'
            '193'
            '194'
            '195'
            '196'
            '197'
            '198'
            '199'
            '200'
            '201'
            '202'
            '203'
            '204'
            '205'
            '206'
            '207'
            '208'
            '209'
            '210'
            '211'
            '212'
            '213'
            '214'
            '215'
            '216'
            '217'
            '218'
            '219'
            '220'
            '221'
            '222'
            '223'
            '224'
            '225'
            '226'
            '227'
            '228'
            '229'
            '230'
            '231'
            '232'
            '233'
            '234'
            '235'
            '236'
            '237'
            '238'
            '239'
            '240'
            '241'
            '242'
            '243'
            '244'
            '245'
            '246'
            '247'
            '248'
            '249'
            '250'
            '251'
            '252'
            '253'
            '254'
            '255'
            '256'
            '257'
            '258'
            '259'
            '260'
            '261'
            '262'
            '263'
            '264'
            '265'
            '266'
            '267'
            '268'
            '269'
            '270'
            '271'
            '272'
            '273'
            '274'
            '275'
            '276'
            '277'
            '278'
            '279'
            '280'
            '281'
            '282'
            '283'
            '284'
            '285'
            '286'
            '287'
            '288'
            '289'
            '290'
            '291'
            '292'
            '293'
            '294'
            '295'
            '296'
            '297'
            '298'
            '299'
            '300'
            '301'
            '302'
            '303'
            '304'
            '305'
            '306'
            '307'
            '308'
            '309'
            '310'
            '311'
            '312'
            '313'
            '314'
            '315'
            '316'
            '317'
            '318'
            '319'
            '320'
            '321'
            '322'
            '323'
            '324'
            '325'
            '326'
            '327'
            '328'
            '329'
            '330'
            '331'
            '332'
            '333'
            '334'
            '335'
            '336'
            '337'
            '338'
            '339'
            '340'
            '341'
            '342'
            '343'
            '344'
            '345'
            '346'
            '347'
            '348'
            '349'
            '350'
            '351'
            '352'
            '353'
            '354'
            '355'
            '356'
            '357'
            '358'
            '359'
            '360'
            '361'
            '362'
            '363'
            '364'
            '365'
            '366'
            '367'
            '368'
            '369'
            '370'
            '371'
            '372'
            '373'
            '374'
            '375'
            '376'
            '377'
            '378'
            '379'
            '380'
            '381'
            '382'
            '383'
            '384'
            '385'
            '386'
            '387'
            '388'
            '389'
            '390'
            '391'
            '392'
            '393'
            '394'
            '395'
            '396'
            '397'
            '398'
            '399'
            '400'
            '401'
            '402'
            '403'
            '404'
            '405'
            '406'
            '407'
            '408'
            '409'
            '410'
            '411'
            '412'
            '413'
            '414'
            '415'
            '416'
            '417'
            '418'
            '419'
            '420'
            '421'
            '422'
            '423'
            '424'
            '425'
            '426'
            '427'
            '428'
            '429'
            '430'
            '431'
            '432'
            '433'
            '434'
            '435'
            '436'
            '437'
            '438'
            '439'
            '440'
            '441'
            '442'
            '443'
            '444'
            '445'
            '446'
            '447'
            '448'
            '449'
            '450'
            '451'
            '452'
            '453'
            '454'
            '455'
            '456'
            '457'
            '458'
            '459'
            '460'
            '461'
            '462'
            '463'
            '464'
            '465'
            '466'
            '467'
            '468'
            '469'
            '470'
            '471'
            '472'
            '473'
            '474'
            '475'
            '476'
            '477'
            '478'
            '479'
            '480'
            '481'
            '482'
            '483'
            '484'
            '485'
            '486'
            '487'
            '488'
            '489'
            '490'
            '491'
            '492'
            '493'
            '494'
            '495'
            '496'
            '497'
            '498'
            '499'
            '500'
            '501'
            '502'
            '503'
            '504'
            '505'
            '506'
            '507'
            '508'
            '509'
            '510'
            '511'
            '512'
            '513'
            '514'
            '515'
            '516'
            '517'
            '518'
            '519'
            '520'
            '521'
            '522'
            '523'
            '524'
            '525'
            '526'
            '527'
            '528'
            '529'
            '530'
            '531'
            '532'
            '533'
            '534'
            '535'
            '536'
            '537'
            '538'
            '539'
            '540'
            '541'
            '542'
            '543'
            '544'
            '545'
            '546'
            '547'
            '548'
            '549'
            '550'
            '551'
            '552'
            '553'
            '554'
            '555'
            '556'
            '557'
            '558'
            '559'
            '560'
            '561'
            '562'
            '563'
            '564'
            '565'
            '566'
            '567'
            '568'
            '569'
            '570'
            '571'
            '572'
            '573'
            '574'
            '575'
            '576'
            '577'
            '578'
            '579'
            '580'
            '581'
            '582'
            '583'
            '584'
            '585'
            '586'
            '587'
            '588'
            '589'
            '590'
            '591'
            '592'
            '593'
            '594'
            '595'
            '596'
            '597'
            '598'
            '599'
            '600'
            '601'
            '602'
            '603'
            '604'
            '605'
            '606'
            '607'
            '608'
            '609'
            '610'
            '611'
            '612'
            '613'
            '614'
            '615'
            '616'
            '617'
            '618'
            '619'
            '620'
            '621'
            '622'
            '623'
            '624'
            '625'
            '626'
            '627'
            '628'
            '629'
            '630'
            '631'
            '632'
            '633'
            '634'
            '635'
            '636'
            '637'
            '638'
            '639'
            '640'
            '641'
            '642'
            '643'
            '644'
            '645'
            '646'
            '647'
            '648'
            '649'
            '650'
            '651'
            '652'
            '653'
            '654'
            '655'
            '656'
            '657'
            '658'
            '659'
            '660'
            '661'
            '662'
            '663'
            '664'
            '665'
            '666'
            '667'
            '668'
            '669'
            '670'
            '671'
            '672'
            '673'
            '674'
            '675'
            '676'
            '677'
            '678'
            '679'
            '680'
            '681'
            '682'
            '683'
            '684'
            '685'
            '686'
            '687'
            '688'
            '689'
            '690'
            '691'
            '692'
            '693'
            '694'
            '695'
            '696'
            '697'
            '698'
            '699'
            '700'
            '701'
            '702'
            '703'
            '704'
            '705'
            '706'
            '707'
            '708'
            '709'
            '710'
            '711'
            '712'
            '713'
            '714'
            '715'
            '716'
            '717'
            '718'
            '719'
            '720'
            '721'
            '722'
            '723'
            '724'
            '725'
            '726'
            '727'
            '728'
            '729'
            '730'
            '731'
            '732'
            '733'
            '734'
            '735'
            '736'
            '737'
            '738'
            '739'
            '740'
            '741'
            '742'
            '743'
            '744'
            '745'
            '746'
            '747'
            '748'
            '749'
            '750'
            '751'
            '752'
            '753'
            '754'
            '755'
            '756'
            '757'
            '758'
            '759'
            '760'
            '761'
            '762'
            '763'
            '764'
            '765'
            '766'
            '767'
            '768'
            '769'
            '770'
            '771'
            '772'
            '773'
            '774'
            '775'
            '776'
            '777'
            '778'
            '779'
            '780'
            '781'
            '782'
            '783'
            '784'
            '785'
            '786'
            '787'
            '788'
            '789'
            '790'
            '791'
            '792'
            '793'
            '794'
            '795'
            '796'
            '797'
            '798'
            '799'
            '800'
            '801'
            '802'
            '803'
            '804'
            '805'
            '806'
            '807'
            '808'
            '809'
            '810'
            '811'
            '812'
            '813'
            '814'
            '815'
            '816'
            '817'
            '818'
            '819'
            '820'
            '821'
            '822'
            '823'
            '824'
            '825'
            '826'
            '827'
            '828'
            '829'
            '830'
            '831'
            '832'
            '833'
            '834'
            '835'
            '836'
            '837'
            '838'
            '839'
            '840'
            '841'
            '842'
            '843'
            '844'
            '845'
            '846'
            '847'
            '848'
            '849'
            '850'
            '851'
            '852'
            '853'
            '854'
            '855'
            '856'
            '857'
            '858'
            '859'
            '860'
            '861'
            '862'
            '863'
            '864'
            '865'
            '866'
            '867'
            '868'
            '869'
            '870'
            '871'
            '872'
            '873'
            '874'
            '875'
            '876'
            '877'
            '878'
            '879'
            '880'
            '881'
            '882'
            '883'
            '884'
            '885'
            '886'
            '887'
            '888'
            '889'
            '890'
            '891'
            '892'
            '893'
            '894'
            '895'
            '896'
            '897'
            '898'
            '899'
            '900'
            '901'
            '902'
            '903'
            '904'
            '905'
            '906'
            '907'
            '908'
            '909'
            '910'
            '911'
            '912'
            '913'
            '914'
            '915'
            '916'
            '917'
            '918'
            '919'
            '920'
            '921'
            '922'
            '923'
            '924'
            '925'
            '926'
            '927'
            '928'
            '929'
            '930'
            '931'
            '932'
            '933'
            '934'
            '935'
            '936'
            '937'
            '938'
            '939'
            '940'
            '941'
            '942'
            '943'
            '944'
            '945'
            '946'
            '947'
            '948'
            '949'
            '950'
            '951'
            '952'
            '953'
            '954'
            '955'
            '956'
            '957'
            '958'
            '959'
            '960'
            '961'
            '962'
            '963'
            '964'
            '965'
            '966'
            '967'
            '968'
            '969'
            '970'
            '971'
            '972'
            '973'
            '974'
            '975'
            '976'
            '977'
            '978'
            '979'
            '980'
            '981'
            '982'
            '983'
            '984'
            '985'
            '986'
            '987'
            '988'
            '989'
            '990'
            '991'
            '992'
            '993'
            '994'
            '995'
            '996'
            '997'
            '998'
            '999'
            '1000'
            '1001'
            '1002'
            '1003'
            '1004'
            '1005'
            '1006'
            '1007'
            '1008'
            '1009'
            '1010'
            '1011'
            '1012'
            '1013'
            '1014'
            '1015'
            '1016'
            '1017'
            '1018'
            '1019'
            '1020'
            '1021'
            '1022'
            '1023'
            '1024')
        end
        object EditAlgoRndAddr2: TEdit
          Left = 186
          Top = 60
          Width = 70
          Height = 21
          TabOrder = 2
          Text = '0x08000000'
        end
        object ComboBoxRndLen2: TComboBox
          Left = 262
          Top = 61
          Width = 52
          Height = 21
          Style = csDropDownList
          ItemIndex = 3
          TabOrder = 3
          Text = '4'
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
            '11'
            '12'
            '13'
            '14'
            '15'
            '16'
            '17'
            '18'
            '19'
            '20'
            '21'
            '22'
            '23'
            '24'
            '25'
            '26'
            '27'
            '28'
            '29'
            '30'
            '31'
            '32'
            '33'
            '34'
            '35'
            '36'
            '37'
            '38'
            '39'
            '40'
            '41'
            '42'
            '43'
            '44'
            '45'
            '46'
            '47'
            '48'
            '49'
            '50'
            '51'
            '52'
            '53'
            '54'
            '55'
            '56'
            '57'
            '58'
            '59'
            '60'
            '61'
            '62'
            '63'
            '64'
            '65'
            '66'
            '67'
            '68'
            '69'
            '70'
            '71'
            '72'
            '73'
            '74'
            '75'
            '76'
            '77'
            '78'
            '79'
            '80'
            '81'
            '82'
            '83'
            '84'
            '85'
            '86'
            '87'
            '88'
            '89'
            '90'
            '91'
            '92'
            '93'
            '94'
            '95'
            '96'
            '97'
            '98'
            '99'
            '100'
            '101'
            '102'
            '103'
            '104'
            '105'
            '106'
            '107'
            '108'
            '109'
            '110'
            '111'
            '112'
            '113'
            '114'
            '115'
            '116'
            '117'
            '118'
            '119'
            '120'
            '121'
            '122'
            '123'
            '124'
            '125'
            '126'
            '127'
            '128'
            '129'
            '130'
            '131'
            '132'
            '133'
            '134'
            '135'
            '136'
            '137'
            '138'
            '139'
            '140'
            '141'
            '142'
            '143'
            '144'
            '145'
            '146'
            '147'
            '148'
            '149'
            '150'
            '151'
            '152'
            '153'
            '154'
            '155'
            '156'
            '157'
            '158'
            '159'
            '160'
            '161'
            '162'
            '163'
            '164'
            '165'
            '166'
            '167'
            '168'
            '169'
            '170'
            '171'
            '172'
            '173'
            '174'
            '175'
            '176'
            '177'
            '178'
            '179'
            '180'
            '181'
            '182'
            '183'
            '184'
            '185'
            '186'
            '187'
            '188'
            '189'
            '190'
            '191'
            '192'
            '193'
            '194'
            '195'
            '196'
            '197'
            '198'
            '199'
            '200'
            '201'
            '202'
            '203'
            '204'
            '205'
            '206'
            '207'
            '208'
            '209'
            '210'
            '211'
            '212'
            '213'
            '214'
            '215'
            '216'
            '217'
            '218'
            '219'
            '220'
            '221'
            '222'
            '223'
            '224'
            '225'
            '226'
            '227'
            '228'
            '229'
            '230'
            '231'
            '232'
            '233'
            '234'
            '235'
            '236'
            '237'
            '238'
            '239'
            '240'
            '241'
            '242'
            '243'
            '244'
            '245'
            '246'
            '247'
            '248'
            '249'
            '250'
            '251'
            '252'
            '253'
            '254'
            '255'
            '256'
            '257'
            '258'
            '259'
            '260'
            '261'
            '262'
            '263'
            '264'
            '265'
            '266'
            '267'
            '268'
            '269'
            '270'
            '271'
            '272'
            '273'
            '274'
            '275'
            '276'
            '277'
            '278'
            '279'
            '280'
            '281'
            '282'
            '283'
            '284'
            '285'
            '286'
            '287'
            '288'
            '289'
            '290'
            '291'
            '292'
            '293'
            '294'
            '295'
            '296'
            '297'
            '298'
            '299'
            '300'
            '301'
            '302'
            '303'
            '304'
            '305'
            '306'
            '307'
            '308'
            '309'
            '310'
            '311'
            '312'
            '313'
            '314'
            '315'
            '316'
            '317'
            '318'
            '319'
            '320'
            '321'
            '322'
            '323'
            '324'
            '325'
            '326'
            '327'
            '328'
            '329'
            '330'
            '331'
            '332'
            '333'
            '334'
            '335'
            '336'
            '337'
            '338'
            '339'
            '340'
            '341'
            '342'
            '343'
            '344'
            '345'
            '346'
            '347'
            '348'
            '349'
            '350'
            '351'
            '352'
            '353'
            '354'
            '355'
            '356'
            '357'
            '358'
            '359'
            '360'
            '361'
            '362'
            '363'
            '364'
            '365'
            '366'
            '367'
            '368'
            '369'
            '370'
            '371'
            '372'
            '373'
            '374'
            '375'
            '376'
            '377'
            '378'
            '379'
            '380'
            '381'
            '382'
            '383'
            '384'
            '385'
            '386'
            '387'
            '388'
            '389'
            '390'
            '391'
            '392'
            '393'
            '394'
            '395'
            '396'
            '397'
            '398'
            '399'
            '400'
            '401'
            '402'
            '403'
            '404'
            '405'
            '406'
            '407'
            '408'
            '409'
            '410'
            '411'
            '412'
            '413'
            '414'
            '415'
            '416'
            '417'
            '418'
            '419'
            '420'
            '421'
            '422'
            '423'
            '424'
            '425'
            '426'
            '427'
            '428'
            '429'
            '430'
            '431'
            '432'
            '433'
            '434'
            '435'
            '436'
            '437'
            '438'
            '439'
            '440'
            '441'
            '442'
            '443'
            '444'
            '445'
            '446'
            '447'
            '448'
            '449'
            '450'
            '451'
            '452'
            '453'
            '454'
            '455'
            '456'
            '457'
            '458'
            '459'
            '460'
            '461'
            '462'
            '463'
            '464'
            '465'
            '466'
            '467'
            '468'
            '469'
            '470'
            '471'
            '472'
            '473'
            '474'
            '475'
            '476'
            '477'
            '478'
            '479'
            '480'
            '481'
            '482'
            '483'
            '484'
            '485'
            '486'
            '487'
            '488'
            '489'
            '490'
            '491'
            '492'
            '493'
            '494'
            '495'
            '496'
            '497'
            '498'
            '499'
            '500'
            '501'
            '502'
            '503'
            '504'
            '505'
            '506'
            '507'
            '508'
            '509'
            '510'
            '511'
            '512'
            '513'
            '514'
            '515'
            '516'
            '517'
            '518'
            '519'
            '520'
            '521'
            '522'
            '523'
            '524'
            '525'
            '526'
            '527'
            '528'
            '529'
            '530'
            '531'
            '532'
            '533'
            '534'
            '535'
            '536'
            '537'
            '538'
            '539'
            '540'
            '541'
            '542'
            '543'
            '544'
            '545'
            '546'
            '547'
            '548'
            '549'
            '550'
            '551'
            '552'
            '553'
            '554'
            '555'
            '556'
            '557'
            '558'
            '559'
            '560'
            '561'
            '562'
            '563'
            '564'
            '565'
            '566'
            '567'
            '568'
            '569'
            '570'
            '571'
            '572'
            '573'
            '574'
            '575'
            '576'
            '577'
            '578'
            '579'
            '580'
            '581'
            '582'
            '583'
            '584'
            '585'
            '586'
            '587'
            '588'
            '589'
            '590'
            '591'
            '592'
            '593'
            '594'
            '595'
            '596'
            '597'
            '598'
            '599'
            '600'
            '601'
            '602'
            '603'
            '604'
            '605'
            '606'
            '607'
            '608'
            '609'
            '610'
            '611'
            '612'
            '613'
            '614'
            '615'
            '616'
            '617'
            '618'
            '619'
            '620'
            '621'
            '622'
            '623'
            '624'
            '625'
            '626'
            '627'
            '628'
            '629'
            '630'
            '631'
            '632'
            '633'
            '634'
            '635'
            '636'
            '637'
            '638'
            '639'
            '640'
            '641'
            '642'
            '643'
            '644'
            '645'
            '646'
            '647'
            '648'
            '649'
            '650'
            '651'
            '652'
            '653'
            '654'
            '655'
            '656'
            '657'
            '658'
            '659'
            '660'
            '661'
            '662'
            '663'
            '664'
            '665'
            '666'
            '667'
            '668'
            '669'
            '670'
            '671'
            '672'
            '673'
            '674'
            '675'
            '676'
            '677'
            '678'
            '679'
            '680'
            '681'
            '682'
            '683'
            '684'
            '685'
            '686'
            '687'
            '688'
            '689'
            '690'
            '691'
            '692'
            '693'
            '694'
            '695'
            '696'
            '697'
            '698'
            '699'
            '700'
            '701'
            '702'
            '703'
            '704'
            '705'
            '706'
            '707'
            '708'
            '709'
            '710'
            '711'
            '712'
            '713'
            '714'
            '715'
            '716'
            '717'
            '718'
            '719'
            '720'
            '721'
            '722'
            '723'
            '724'
            '725'
            '726'
            '727'
            '728'
            '729'
            '730'
            '731'
            '732'
            '733'
            '734'
            '735'
            '736'
            '737'
            '738'
            '739'
            '740'
            '741'
            '742'
            '743'
            '744'
            '745'
            '746'
            '747'
            '748'
            '749'
            '750'
            '751'
            '752'
            '753'
            '754'
            '755'
            '756'
            '757'
            '758'
            '759'
            '760'
            '761'
            '762'
            '763'
            '764'
            '765'
            '766'
            '767'
            '768'
            '769'
            '770'
            '771'
            '772'
            '773'
            '774'
            '775'
            '776'
            '777'
            '778'
            '779'
            '780'
            '781'
            '782'
            '783'
            '784'
            '785'
            '786'
            '787'
            '788'
            '789'
            '790'
            '791'
            '792'
            '793'
            '794'
            '795'
            '796'
            '797'
            '798'
            '799'
            '800'
            '801'
            '802'
            '803'
            '804'
            '805'
            '806'
            '807'
            '808'
            '809'
            '810'
            '811'
            '812'
            '813'
            '814'
            '815'
            '816'
            '817'
            '818'
            '819'
            '820'
            '821'
            '822'
            '823'
            '824'
            '825'
            '826'
            '827'
            '828'
            '829'
            '830'
            '831'
            '832'
            '833'
            '834'
            '835'
            '836'
            '837'
            '838'
            '839'
            '840'
            '841'
            '842'
            '843'
            '844'
            '845'
            '846'
            '847'
            '848'
            '849'
            '850'
            '851'
            '852'
            '853'
            '854'
            '855'
            '856'
            '857'
            '858'
            '859'
            '860'
            '861'
            '862'
            '863'
            '864'
            '865'
            '866'
            '867'
            '868'
            '869'
            '870'
            '871'
            '872'
            '873'
            '874'
            '875'
            '876'
            '877'
            '878'
            '879'
            '880'
            '881'
            '882'
            '883'
            '884'
            '885'
            '886'
            '887'
            '888'
            '889'
            '890'
            '891'
            '892'
            '893'
            '894'
            '895'
            '896'
            '897'
            '898'
            '899'
            '900'
            '901'
            '902'
            '903'
            '904'
            '905'
            '906'
            '907'
            '908'
            '909'
            '910'
            '911'
            '912'
            '913'
            '914'
            '915'
            '916'
            '917'
            '918'
            '919'
            '920'
            '921'
            '922'
            '923'
            '924'
            '925'
            '926'
            '927'
            '928'
            '929'
            '930'
            '931'
            '932'
            '933'
            '934'
            '935'
            '936'
            '937'
            '938'
            '939'
            '940'
            '941'
            '942'
            '943'
            '944'
            '945'
            '946'
            '947'
            '948'
            '949'
            '950'
            '951'
            '952'
            '953'
            '954'
            '955'
            '956'
            '957'
            '958'
            '959'
            '960'
            '961'
            '962'
            '963'
            '964'
            '965'
            '966'
            '967'
            '968'
            '969'
            '970'
            '971'
            '972'
            '973'
            '974'
            '975'
            '976'
            '977'
            '978'
            '979'
            '980'
            '981'
            '982'
            '983'
            '984'
            '985'
            '986'
            '987'
            '988'
            '989'
            '990'
            '991'
            '992'
            '993'
            '994'
            '995'
            '996'
            '997'
            '998'
            '999'
            '1000'
            '1001'
            '1002'
            '1003'
            '1004'
            '1005'
            '1006'
            '1007'
            '1008'
            '1009'
            '1010'
            '1011'
            '1012'
            '1013'
            '1014'
            '1015'
            '1016'
            '1017'
            '1018'
            '1019'
            '1020'
            '1021'
            '1022'
            '1023'
            '1024')
        end
        object EditAlgoRndAddr3: TEdit
          Left = 185
          Top = 89
          Width = 70
          Height = 21
          TabOrder = 4
          Text = '0x08000000'
        end
        object ComboBoxRndLen3: TComboBox
          Left = 261
          Top = 88
          Width = 52
          Height = 21
          Style = csDropDownList
          ItemIndex = 3
          TabOrder = 5
          Text = '4'
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
            '11'
            '12'
            '13'
            '14'
            '15'
            '16'
            '17'
            '18'
            '19'
            '20'
            '21'
            '22'
            '23'
            '24'
            '25'
            '26'
            '27'
            '28'
            '29'
            '30'
            '31'
            '32'
            '33'
            '34'
            '35'
            '36'
            '37'
            '38'
            '39'
            '40'
            '41'
            '42'
            '43'
            '44'
            '45'
            '46'
            '47'
            '48'
            '49'
            '50'
            '51'
            '52'
            '53'
            '54'
            '55'
            '56'
            '57'
            '58'
            '59'
            '60'
            '61'
            '62'
            '63'
            '64'
            '65'
            '66'
            '67'
            '68'
            '69'
            '70'
            '71'
            '72'
            '73'
            '74'
            '75'
            '76'
            '77'
            '78'
            '79'
            '80'
            '81'
            '82'
            '83'
            '84'
            '85'
            '86'
            '87'
            '88'
            '89'
            '90'
            '91'
            '92'
            '93'
            '94'
            '95'
            '96'
            '97'
            '98'
            '99'
            '100'
            '101'
            '102'
            '103'
            '104'
            '105'
            '106'
            '107'
            '108'
            '109'
            '110'
            '111'
            '112'
            '113'
            '114'
            '115'
            '116'
            '117'
            '118'
            '119'
            '120'
            '121'
            '122'
            '123'
            '124'
            '125'
            '126'
            '127'
            '128'
            '129'
            '130'
            '131'
            '132'
            '133'
            '134'
            '135'
            '136'
            '137'
            '138'
            '139'
            '140'
            '141'
            '142'
            '143'
            '144'
            '145'
            '146'
            '147'
            '148'
            '149'
            '150'
            '151'
            '152'
            '153'
            '154'
            '155'
            '156'
            '157'
            '158'
            '159'
            '160'
            '161'
            '162'
            '163'
            '164'
            '165'
            '166'
            '167'
            '168'
            '169'
            '170'
            '171'
            '172'
            '173'
            '174'
            '175'
            '176'
            '177'
            '178'
            '179'
            '180'
            '181'
            '182'
            '183'
            '184'
            '185'
            '186'
            '187'
            '188'
            '189'
            '190'
            '191'
            '192'
            '193'
            '194'
            '195'
            '196'
            '197'
            '198'
            '199'
            '200'
            '201'
            '202'
            '203'
            '204'
            '205'
            '206'
            '207'
            '208'
            '209'
            '210'
            '211'
            '212'
            '213'
            '214'
            '215'
            '216'
            '217'
            '218'
            '219'
            '220'
            '221'
            '222'
            '223'
            '224'
            '225'
            '226'
            '227'
            '228'
            '229'
            '230'
            '231'
            '232'
            '233'
            '234'
            '235'
            '236'
            '237'
            '238'
            '239'
            '240'
            '241'
            '242'
            '243'
            '244'
            '245'
            '246'
            '247'
            '248'
            '249'
            '250'
            '251'
            '252'
            '253'
            '254'
            '255'
            '256'
            '257'
            '258'
            '259'
            '260'
            '261'
            '262'
            '263'
            '264'
            '265'
            '266'
            '267'
            '268'
            '269'
            '270'
            '271'
            '272'
            '273'
            '274'
            '275'
            '276'
            '277'
            '278'
            '279'
            '280'
            '281'
            '282'
            '283'
            '284'
            '285'
            '286'
            '287'
            '288'
            '289'
            '290'
            '291'
            '292'
            '293'
            '294'
            '295'
            '296'
            '297'
            '298'
            '299'
            '300'
            '301'
            '302'
            '303'
            '304'
            '305'
            '306'
            '307'
            '308'
            '309'
            '310'
            '311'
            '312'
            '313'
            '314'
            '315'
            '316'
            '317'
            '318'
            '319'
            '320'
            '321'
            '322'
            '323'
            '324'
            '325'
            '326'
            '327'
            '328'
            '329'
            '330'
            '331'
            '332'
            '333'
            '334'
            '335'
            '336'
            '337'
            '338'
            '339'
            '340'
            '341'
            '342'
            '343'
            '344'
            '345'
            '346'
            '347'
            '348'
            '349'
            '350'
            '351'
            '352'
            '353'
            '354'
            '355'
            '356'
            '357'
            '358'
            '359'
            '360'
            '361'
            '362'
            '363'
            '364'
            '365'
            '366'
            '367'
            '368'
            '369'
            '370'
            '371'
            '372'
            '373'
            '374'
            '375'
            '376'
            '377'
            '378'
            '379'
            '380'
            '381'
            '382'
            '383'
            '384'
            '385'
            '386'
            '387'
            '388'
            '389'
            '390'
            '391'
            '392'
            '393'
            '394'
            '395'
            '396'
            '397'
            '398'
            '399'
            '400'
            '401'
            '402'
            '403'
            '404'
            '405'
            '406'
            '407'
            '408'
            '409'
            '410'
            '411'
            '412'
            '413'
            '414'
            '415'
            '416'
            '417'
            '418'
            '419'
            '420'
            '421'
            '422'
            '423'
            '424'
            '425'
            '426'
            '427'
            '428'
            '429'
            '430'
            '431'
            '432'
            '433'
            '434'
            '435'
            '436'
            '437'
            '438'
            '439'
            '440'
            '441'
            '442'
            '443'
            '444'
            '445'
            '446'
            '447'
            '448'
            '449'
            '450'
            '451'
            '452'
            '453'
            '454'
            '455'
            '456'
            '457'
            '458'
            '459'
            '460'
            '461'
            '462'
            '463'
            '464'
            '465'
            '466'
            '467'
            '468'
            '469'
            '470'
            '471'
            '472'
            '473'
            '474'
            '475'
            '476'
            '477'
            '478'
            '479'
            '480'
            '481'
            '482'
            '483'
            '484'
            '485'
            '486'
            '487'
            '488'
            '489'
            '490'
            '491'
            '492'
            '493'
            '494'
            '495'
            '496'
            '497'
            '498'
            '499'
            '500'
            '501'
            '502'
            '503'
            '504'
            '505'
            '506'
            '507'
            '508'
            '509'
            '510'
            '511'
            '512'
            '513'
            '514'
            '515'
            '516'
            '517'
            '518'
            '519'
            '520'
            '521'
            '522'
            '523'
            '524'
            '525'
            '526'
            '527'
            '528'
            '529'
            '530'
            '531'
            '532'
            '533'
            '534'
            '535'
            '536'
            '537'
            '538'
            '539'
            '540'
            '541'
            '542'
            '543'
            '544'
            '545'
            '546'
            '547'
            '548'
            '549'
            '550'
            '551'
            '552'
            '553'
            '554'
            '555'
            '556'
            '557'
            '558'
            '559'
            '560'
            '561'
            '562'
            '563'
            '564'
            '565'
            '566'
            '567'
            '568'
            '569'
            '570'
            '571'
            '572'
            '573'
            '574'
            '575'
            '576'
            '577'
            '578'
            '579'
            '580'
            '581'
            '582'
            '583'
            '584'
            '585'
            '586'
            '587'
            '588'
            '589'
            '590'
            '591'
            '592'
            '593'
            '594'
            '595'
            '596'
            '597'
            '598'
            '599'
            '600'
            '601'
            '602'
            '603'
            '604'
            '605'
            '606'
            '607'
            '608'
            '609'
            '610'
            '611'
            '612'
            '613'
            '614'
            '615'
            '616'
            '617'
            '618'
            '619'
            '620'
            '621'
            '622'
            '623'
            '624'
            '625'
            '626'
            '627'
            '628'
            '629'
            '630'
            '631'
            '632'
            '633'
            '634'
            '635'
            '636'
            '637'
            '638'
            '639'
            '640'
            '641'
            '642'
            '643'
            '644'
            '645'
            '646'
            '647'
            '648'
            '649'
            '650'
            '651'
            '652'
            '653'
            '654'
            '655'
            '656'
            '657'
            '658'
            '659'
            '660'
            '661'
            '662'
            '663'
            '664'
            '665'
            '666'
            '667'
            '668'
            '669'
            '670'
            '671'
            '672'
            '673'
            '674'
            '675'
            '676'
            '677'
            '678'
            '679'
            '680'
            '681'
            '682'
            '683'
            '684'
            '685'
            '686'
            '687'
            '688'
            '689'
            '690'
            '691'
            '692'
            '693'
            '694'
            '695'
            '696'
            '697'
            '698'
            '699'
            '700'
            '701'
            '702'
            '703'
            '704'
            '705'
            '706'
            '707'
            '708'
            '709'
            '710'
            '711'
            '712'
            '713'
            '714'
            '715'
            '716'
            '717'
            '718'
            '719'
            '720'
            '721'
            '722'
            '723'
            '724'
            '725'
            '726'
            '727'
            '728'
            '729'
            '730'
            '731'
            '732'
            '733'
            '734'
            '735'
            '736'
            '737'
            '738'
            '739'
            '740'
            '741'
            '742'
            '743'
            '744'
            '745'
            '746'
            '747'
            '748'
            '749'
            '750'
            '751'
            '752'
            '753'
            '754'
            '755'
            '756'
            '757'
            '758'
            '759'
            '760'
            '761'
            '762'
            '763'
            '764'
            '765'
            '766'
            '767'
            '768'
            '769'
            '770'
            '771'
            '772'
            '773'
            '774'
            '775'
            '776'
            '777'
            '778'
            '779'
            '780'
            '781'
            '782'
            '783'
            '784'
            '785'
            '786'
            '787'
            '788'
            '789'
            '790'
            '791'
            '792'
            '793'
            '794'
            '795'
            '796'
            '797'
            '798'
            '799'
            '800'
            '801'
            '802'
            '803'
            '804'
            '805'
            '806'
            '807'
            '808'
            '809'
            '810'
            '811'
            '812'
            '813'
            '814'
            '815'
            '816'
            '817'
            '818'
            '819'
            '820'
            '821'
            '822'
            '823'
            '824'
            '825'
            '826'
            '827'
            '828'
            '829'
            '830'
            '831'
            '832'
            '833'
            '834'
            '835'
            '836'
            '837'
            '838'
            '839'
            '840'
            '841'
            '842'
            '843'
            '844'
            '845'
            '846'
            '847'
            '848'
            '849'
            '850'
            '851'
            '852'
            '853'
            '854'
            '855'
            '856'
            '857'
            '858'
            '859'
            '860'
            '861'
            '862'
            '863'
            '864'
            '865'
            '866'
            '867'
            '868'
            '869'
            '870'
            '871'
            '872'
            '873'
            '874'
            '875'
            '876'
            '877'
            '878'
            '879'
            '880'
            '881'
            '882'
            '883'
            '884'
            '885'
            '886'
            '887'
            '888'
            '889'
            '890'
            '891'
            '892'
            '893'
            '894'
            '895'
            '896'
            '897'
            '898'
            '899'
            '900'
            '901'
            '902'
            '903'
            '904'
            '905'
            '906'
            '907'
            '908'
            '909'
            '910'
            '911'
            '912'
            '913'
            '914'
            '915'
            '916'
            '917'
            '918'
            '919'
            '920'
            '921'
            '922'
            '923'
            '924'
            '925'
            '926'
            '927'
            '928'
            '929'
            '930'
            '931'
            '932'
            '933'
            '934'
            '935'
            '936'
            '937'
            '938'
            '939'
            '940'
            '941'
            '942'
            '943'
            '944'
            '945'
            '946'
            '947'
            '948'
            '949'
            '950'
            '951'
            '952'
            '953'
            '954'
            '955'
            '956'
            '957'
            '958'
            '959'
            '960'
            '961'
            '962'
            '963'
            '964'
            '965'
            '966'
            '967'
            '968'
            '969'
            '970'
            '971'
            '972'
            '973'
            '974'
            '975'
            '976'
            '977'
            '978'
            '979'
            '980'
            '981'
            '982'
            '983'
            '984'
            '985'
            '986'
            '987'
            '988'
            '989'
            '990'
            '991'
            '992'
            '993'
            '994'
            '995'
            '996'
            '997'
            '998'
            '999'
            '1000'
            '1001'
            '1002'
            '1003'
            '1004'
            '1005'
            '1006'
            '1007'
            '1008'
            '1009'
            '1010'
            '1011'
            '1012'
            '1013'
            '1014'
            '1015'
            '1016'
            '1017'
            '1018'
            '1019'
            '1020'
            '1021'
            '1022'
            '1023'
            '1024')
        end
        object EditAlgoRndAddr4: TEdit
          Left = 185
          Top = 115
          Width = 70
          Height = 21
          TabOrder = 6
          Text = '0x08000000'
        end
        object ComboBoxRndLen4: TComboBox
          Left = 261
          Top = 114
          Width = 53
          Height = 21
          Style = csDropDownList
          ItemIndex = 3
          TabOrder = 7
          Text = '4'
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
            '11'
            '12'
            '13'
            '14'
            '15'
            '16'
            '17'
            '18'
            '19'
            '20'
            '21'
            '22'
            '23'
            '24'
            '25'
            '26'
            '27'
            '28'
            '29'
            '30'
            '31'
            '32'
            '33'
            '34'
            '35'
            '36'
            '37'
            '38'
            '39'
            '40'
            '41'
            '42'
            '43'
            '44'
            '45'
            '46'
            '47'
            '48'
            '49'
            '50'
            '51'
            '52'
            '53'
            '54'
            '55'
            '56'
            '57'
            '58'
            '59'
            '60'
            '61'
            '62'
            '63'
            '64'
            '65'
            '66'
            '67'
            '68'
            '69'
            '70'
            '71'
            '72'
            '73'
            '74'
            '75'
            '76'
            '77'
            '78'
            '79'
            '80'
            '81'
            '82'
            '83'
            '84'
            '85'
            '86'
            '87'
            '88'
            '89'
            '90'
            '91'
            '92'
            '93'
            '94'
            '95'
            '96'
            '97'
            '98'
            '99'
            '100'
            '101'
            '102'
            '103'
            '104'
            '105'
            '106'
            '107'
            '108'
            '109'
            '110'
            '111'
            '112'
            '113'
            '114'
            '115'
            '116'
            '117'
            '118'
            '119'
            '120'
            '121'
            '122'
            '123'
            '124'
            '125'
            '126'
            '127'
            '128'
            '129'
            '130'
            '131'
            '132'
            '133'
            '134'
            '135'
            '136'
            '137'
            '138'
            '139'
            '140'
            '141'
            '142'
            '143'
            '144'
            '145'
            '146'
            '147'
            '148'
            '149'
            '150'
            '151'
            '152'
            '153'
            '154'
            '155'
            '156'
            '157'
            '158'
            '159'
            '160'
            '161'
            '162'
            '163'
            '164'
            '165'
            '166'
            '167'
            '168'
            '169'
            '170'
            '171'
            '172'
            '173'
            '174'
            '175'
            '176'
            '177'
            '178'
            '179'
            '180'
            '181'
            '182'
            '183'
            '184'
            '185'
            '186'
            '187'
            '188'
            '189'
            '190'
            '191'
            '192'
            '193'
            '194'
            '195'
            '196'
            '197'
            '198'
            '199'
            '200'
            '201'
            '202'
            '203'
            '204'
            '205'
            '206'
            '207'
            '208'
            '209'
            '210'
            '211'
            '212'
            '213'
            '214'
            '215'
            '216'
            '217'
            '218'
            '219'
            '220'
            '221'
            '222'
            '223'
            '224'
            '225'
            '226'
            '227'
            '228'
            '229'
            '230'
            '231'
            '232'
            '233'
            '234'
            '235'
            '236'
            '237'
            '238'
            '239'
            '240'
            '241'
            '242'
            '243'
            '244'
            '245'
            '246'
            '247'
            '248'
            '249'
            '250'
            '251'
            '252'
            '253'
            '254'
            '255'
            '256'
            '257'
            '258'
            '259'
            '260'
            '261'
            '262'
            '263'
            '264'
            '265'
            '266'
            '267'
            '268'
            '269'
            '270'
            '271'
            '272'
            '273'
            '274'
            '275'
            '276'
            '277'
            '278'
            '279'
            '280'
            '281'
            '282'
            '283'
            '284'
            '285'
            '286'
            '287'
            '288'
            '289'
            '290'
            '291'
            '292'
            '293'
            '294'
            '295'
            '296'
            '297'
            '298'
            '299'
            '300'
            '301'
            '302'
            '303'
            '304'
            '305'
            '306'
            '307'
            '308'
            '309'
            '310'
            '311'
            '312'
            '313'
            '314'
            '315'
            '316'
            '317'
            '318'
            '319'
            '320'
            '321'
            '322'
            '323'
            '324'
            '325'
            '326'
            '327'
            '328'
            '329'
            '330'
            '331'
            '332'
            '333'
            '334'
            '335'
            '336'
            '337'
            '338'
            '339'
            '340'
            '341'
            '342'
            '343'
            '344'
            '345'
            '346'
            '347'
            '348'
            '349'
            '350'
            '351'
            '352'
            '353'
            '354'
            '355'
            '356'
            '357'
            '358'
            '359'
            '360'
            '361'
            '362'
            '363'
            '364'
            '365'
            '366'
            '367'
            '368'
            '369'
            '370'
            '371'
            '372'
            '373'
            '374'
            '375'
            '376'
            '377'
            '378'
            '379'
            '380'
            '381'
            '382'
            '383'
            '384'
            '385'
            '386'
            '387'
            '388'
            '389'
            '390'
            '391'
            '392'
            '393'
            '394'
            '395'
            '396'
            '397'
            '398'
            '399'
            '400'
            '401'
            '402'
            '403'
            '404'
            '405'
            '406'
            '407'
            '408'
            '409'
            '410'
            '411'
            '412'
            '413'
            '414'
            '415'
            '416'
            '417'
            '418'
            '419'
            '420'
            '421'
            '422'
            '423'
            '424'
            '425'
            '426'
            '427'
            '428'
            '429'
            '430'
            '431'
            '432'
            '433'
            '434'
            '435'
            '436'
            '437'
            '438'
            '439'
            '440'
            '441'
            '442'
            '443'
            '444'
            '445'
            '446'
            '447'
            '448'
            '449'
            '450'
            '451'
            '452'
            '453'
            '454'
            '455'
            '456'
            '457'
            '458'
            '459'
            '460'
            '461'
            '462'
            '463'
            '464'
            '465'
            '466'
            '467'
            '468'
            '469'
            '470'
            '471'
            '472'
            '473'
            '474'
            '475'
            '476'
            '477'
            '478'
            '479'
            '480'
            '481'
            '482'
            '483'
            '484'
            '485'
            '486'
            '487'
            '488'
            '489'
            '490'
            '491'
            '492'
            '493'
            '494'
            '495'
            '496'
            '497'
            '498'
            '499'
            '500'
            '501'
            '502'
            '503'
            '504'
            '505'
            '506'
            '507'
            '508'
            '509'
            '510'
            '511'
            '512'
            '513'
            '514'
            '515'
            '516'
            '517'
            '518'
            '519'
            '520'
            '521'
            '522'
            '523'
            '524'
            '525'
            '526'
            '527'
            '528'
            '529'
            '530'
            '531'
            '532'
            '533'
            '534'
            '535'
            '536'
            '537'
            '538'
            '539'
            '540'
            '541'
            '542'
            '543'
            '544'
            '545'
            '546'
            '547'
            '548'
            '549'
            '550'
            '551'
            '552'
            '553'
            '554'
            '555'
            '556'
            '557'
            '558'
            '559'
            '560'
            '561'
            '562'
            '563'
            '564'
            '565'
            '566'
            '567'
            '568'
            '569'
            '570'
            '571'
            '572'
            '573'
            '574'
            '575'
            '576'
            '577'
            '578'
            '579'
            '580'
            '581'
            '582'
            '583'
            '584'
            '585'
            '586'
            '587'
            '588'
            '589'
            '590'
            '591'
            '592'
            '593'
            '594'
            '595'
            '596'
            '597'
            '598'
            '599'
            '600'
            '601'
            '602'
            '603'
            '604'
            '605'
            '606'
            '607'
            '608'
            '609'
            '610'
            '611'
            '612'
            '613'
            '614'
            '615'
            '616'
            '617'
            '618'
            '619'
            '620'
            '621'
            '622'
            '623'
            '624'
            '625'
            '626'
            '627'
            '628'
            '629'
            '630'
            '631'
            '632'
            '633'
            '634'
            '635'
            '636'
            '637'
            '638'
            '639'
            '640'
            '641'
            '642'
            '643'
            '644'
            '645'
            '646'
            '647'
            '648'
            '649'
            '650'
            '651'
            '652'
            '653'
            '654'
            '655'
            '656'
            '657'
            '658'
            '659'
            '660'
            '661'
            '662'
            '663'
            '664'
            '665'
            '666'
            '667'
            '668'
            '669'
            '670'
            '671'
            '672'
            '673'
            '674'
            '675'
            '676'
            '677'
            '678'
            '679'
            '680'
            '681'
            '682'
            '683'
            '684'
            '685'
            '686'
            '687'
            '688'
            '689'
            '690'
            '691'
            '692'
            '693'
            '694'
            '695'
            '696'
            '697'
            '698'
            '699'
            '700'
            '701'
            '702'
            '703'
            '704'
            '705'
            '706'
            '707'
            '708'
            '709'
            '710'
            '711'
            '712'
            '713'
            '714'
            '715'
            '716'
            '717'
            '718'
            '719'
            '720'
            '721'
            '722'
            '723'
            '724'
            '725'
            '726'
            '727'
            '728'
            '729'
            '730'
            '731'
            '732'
            '733'
            '734'
            '735'
            '736'
            '737'
            '738'
            '739'
            '740'
            '741'
            '742'
            '743'
            '744'
            '745'
            '746'
            '747'
            '748'
            '749'
            '750'
            '751'
            '752'
            '753'
            '754'
            '755'
            '756'
            '757'
            '758'
            '759'
            '760'
            '761'
            '762'
            '763'
            '764'
            '765'
            '766'
            '767'
            '768'
            '769'
            '770'
            '771'
            '772'
            '773'
            '774'
            '775'
            '776'
            '777'
            '778'
            '779'
            '780'
            '781'
            '782'
            '783'
            '784'
            '785'
            '786'
            '787'
            '788'
            '789'
            '790'
            '791'
            '792'
            '793'
            '794'
            '795'
            '796'
            '797'
            '798'
            '799'
            '800'
            '801'
            '802'
            '803'
            '804'
            '805'
            '806'
            '807'
            '808'
            '809'
            '810'
            '811'
            '812'
            '813'
            '814'
            '815'
            '816'
            '817'
            '818'
            '819'
            '820'
            '821'
            '822'
            '823'
            '824'
            '825'
            '826'
            '827'
            '828'
            '829'
            '830'
            '831'
            '832'
            '833'
            '834'
            '835'
            '836'
            '837'
            '838'
            '839'
            '840'
            '841'
            '842'
            '843'
            '844'
            '845'
            '846'
            '847'
            '848'
            '849'
            '850'
            '851'
            '852'
            '853'
            '854'
            '855'
            '856'
            '857'
            '858'
            '859'
            '860'
            '861'
            '862'
            '863'
            '864'
            '865'
            '866'
            '867'
            '868'
            '869'
            '870'
            '871'
            '872'
            '873'
            '874'
            '875'
            '876'
            '877'
            '878'
            '879'
            '880'
            '881'
            '882'
            '883'
            '884'
            '885'
            '886'
            '887'
            '888'
            '889'
            '890'
            '891'
            '892'
            '893'
            '894'
            '895'
            '896'
            '897'
            '898'
            '899'
            '900'
            '901'
            '902'
            '903'
            '904'
            '905'
            '906'
            '907'
            '908'
            '909'
            '910'
            '911'
            '912'
            '913'
            '914'
            '915'
            '916'
            '917'
            '918'
            '919'
            '920'
            '921'
            '922'
            '923'
            '924'
            '925'
            '926'
            '927'
            '928'
            '929'
            '930'
            '931'
            '932'
            '933'
            '934'
            '935'
            '936'
            '937'
            '938'
            '939'
            '940'
            '941'
            '942'
            '943'
            '944'
            '945'
            '946'
            '947'
            '948'
            '949'
            '950'
            '951'
            '952'
            '953'
            '954'
            '955'
            '956'
            '957'
            '958'
            '959'
            '960'
            '961'
            '962'
            '963'
            '964'
            '965'
            '966'
            '967'
            '968'
            '969'
            '970'
            '971'
            '972'
            '973'
            '974'
            '975'
            '976'
            '977'
            '978'
            '979'
            '980'
            '981'
            '982'
            '983'
            '984'
            '985'
            '986'
            '987'
            '988'
            '989'
            '990'
            '991'
            '992'
            '993'
            '994'
            '995'
            '996'
            '997'
            '998'
            '999'
            '1000'
            '1001'
            '1002'
            '1003'
            '1004'
            '1005'
            '1006'
            '1007'
            '1008'
            '1009'
            '1010'
            '1011'
            '1012'
            '1013'
            '1014'
            '1015'
            '1016'
            '1017'
            '1018'
            '1019'
            '1020'
            '1021'
            '1022'
            '1023'
            '1024')
        end
        object ComboBoxAlgoRnd1: TComboBox
          Left = 79
          Top = 33
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 8
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
        object ComboBoxAlgoRnd2: TComboBox
          Left = 79
          Top = 60
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 9
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
        object ComboBoxAlgoRnd3: TComboBox
          Left = 79
          Top = 89
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 10
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
        object ComboBoxAlgoRnd4: TComboBox
          Left = 79
          Top = 116
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 11
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
      end
      object GroupBox9: TGroupBox
        Left = 187
        Top = 239
        Width = 327
        Height = 84
        Caption = 'UID'#21152#23494#21551#29992
        TabOrder = 2
        object Label33: TLabel
          Left = 173
          Top = 55
          Width = 84
          Height = 13
          Caption = #38271#24230#65288#23383#33410#65289#65306
        end
        object Label46: TLabel
          Left = 13
          Top = 56
          Width = 36
          Height = 13
          Caption = #22320#22336#65306
        end
        object Label76: TLabel
          Left = 13
          Top = 25
          Width = 54
          Height = 13
          Caption = 'UID'#21152#23494#65306
        end
        object ComboBoxEncryptResultLen: TComboBox
          Left = 263
          Top = 49
          Width = 52
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 0
          Text = '4'
          Items.Strings = (
            '4'
            '8'
            '12'
            '16')
        end
        object EditEncryptSaveAddr: TEdit
          Left = 56
          Top = 52
          Width = 70
          Height = 21
          TabOrder = 1
          Text = '0x08000000'
        end
        object ComboBoxEncryptEnable: TComboBox
          Left = 75
          Top = 21
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 2
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
      end
      object GroupBox13: TGroupBox
        Left = 187
        Top = 8
        Width = 327
        Height = 70
        Caption = #24120#37327
        TabOrder = 3
        object Label34: TLabel
          Left = 13
          Top = 19
          Width = 91
          Height = 13
          Caption = #24120#37327#20540#65288'HEX'#65289#65306
        end
        object EditEncryptConst: TEdit
          Left = 13
          Top = 41
          Width = 292
          Height = 21
          TabOrder = 0
          Text = '01 02 03 04 05 06 07 08'
        end
        object ComboBox1: TComboBox
          Left = 110
          Top = 14
          Width = 94
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 1
          Text = #19981#21551#29992
          Items.Strings = (
            #19981#21551#29992
            #20889#20837'#1'#21306
            #20889#20837'#2'#21306
            #20889#20837'#3'#21306
            #20889#20837'#4'#21306
            #20889#20837'#5'#21306
            #20889#20837'#6'#21306
            #20889#20837'#7'#21306
            #20889#20837'#8'#21306
            #20889#20837'#9'#21306
            #20889#20837'#10'#21306)
        end
      end
      object Button15: TButton
        Left = 297
        Top = 344
        Width = 118
        Height = 25
        Caption = #26174#31034' Lua '#31639#27861#25991#20214
        TabOrder = 4
        OnClick = Button15Click
      end
      object Button16: TButton
        Left = 421
        Top = 344
        Width = 97
        Height = 25
        Caption = #20351#29992#35828#26126
        TabOrder = 5
        OnClick = Button16Click
      end
    end
    object TabSheet5: TTabSheet
      Caption = ' '#28903#24405#38480#21046
      ImageIndex = 3
      object GroupBox11: TGroupBox
        Left = 16
        Top = 314
        Width = 497
        Height = 60
        Caption = #26085#26399#38480#23450
        TabOrder = 0
        object Label50: TLabel
          Left = 195
          Top = 24
          Width = 84
          Height = 13
          Caption = #28903#24405#25130#27490#26085#26399#65306
        end
        object Label49: TLabel
          Left = 282
          Top = 41
          Width = 139
          Height = 13
          Caption = #26684#24335#65306'2020-01-01 00:00:00'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object CheckBoxDeadline: TCheckBox
          Left = 16
          Top = 26
          Width = 100
          Height = 17
          Caption = #21551#29992#26085#26399#38480#23450
          TabOrder = 0
        end
        object EditDeadlineDate: TEdit
          Left = 285
          Top = 15
          Width = 168
          Height = 20
          Font.Charset = GB2312_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = #23435#20307
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = '2030-12-31 23:59:00'
        end
      end
      object GroupBox12: TGroupBox
        Left = 16
        Top = 93
        Width = 497
        Height = 207
        Caption = 'UID'#33539#22260#26816#26597
        TabOrder = 1
        object Label52: TLabel
          Left = 68
          Top = 51
          Width = 51
          Height = 13
          Caption = #25513#34109'MASK'
        end
        object Label51: TLabel
          Left = 211
          Top = 50
          Width = 102
          Height = 13
          Caption = #27491#30830#32467#26524' VALUE_OK'
        end
        object Label53: TLabel
          Left = 233
          Top = 28
          Width = 134
          Height = 13
          Caption = 'UID && MASK ==  VALUE_OK'
        end
        object Label54: TLabel
          Left = 175
          Top = 28
          Width = 52
          Height = 13
          Caption = #21028#26029#26465#20214':'
        end
        object CheckBoxCheckUid: TCheckBox
          Left = 20
          Top = 25
          Width = 116
          Height = 17
          Caption = #21551#29992'UID'#33539#22260#26816#26597
          TabOrder = 0
        end
        object MemoUID: TMemo
          Left = 16
          Top = 69
          Width = 406
          Height = 116
          Font.Charset = GB2312_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = #23435#20307
          Font.Style = []
          Lines.Strings = (
            '"FFFFFFFF 00000000 00000000", "24001C00 00000000 00000000",'
            '"FFFFFFFF 00000000 00000000", "29004100 00000000 00000000",')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 1
        end
      end
      object GroupBox16: TGroupBox
        Left = 16
        Top = 17
        Width = 497
        Height = 60
        Caption = #28903#24405#27425#25968
        TabOrder = 2
        object Label16: TLabel
          Left = 21
          Top = 27
          Width = 134
          Height = 13
          Caption = #27425#25968#38480#21046#65288'0='#19981#38480#21046#65289#65306
        end
        object EditProgrammedLimit: TEdit
          Left = 160
          Top = 23
          Width = 70
          Height = 21
          TabOrder = 0
          Text = '0'
        end
      end
    end
    object TabSheet10: TTabSheet
      Caption = ' '#26426#21488#25509#21475' '
      ImageIndex = 7
      object Label81: TLabel
        Left = 17
        Top = 68
        Width = 174
        Height = 13
        Caption = #26631#20934#20449#21495' OK, NG '#25345#32493#26102#38388#65288'ms'#65289
      end
      object Label82: TLabel
        Left = 17
        Top = 87
        Width = 78
        Height = 13
        Caption = '0'#34920#31034#19968#30452#25345#32493
        Font.Charset = ANSI_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label83: TLabel
        Left = 237
        Top = 63
        Width = 129
        Height = 13
        Caption = 'EOT'#20449#21495#27874#24418#26102#24207#65288'ms'#65289
      end
      object Label84: TLabel
        Left = 14
        Top = 9
        Width = 96
        Height = 13
        Caption = #36873#25321#26426#21488#20449#21495#31867#22411
      end
      object Label85: TLabel
        Left = 210
        Top = 10
        Width = 72
        Height = 13
        Caption = #20986#38169#32456#27490#31574#30053
      end
      object Label86: TLabel
        Left = 210
        Top = 35
        Width = 74
        Height = 13
        Caption = #32456#27490#26102'NG'#31574#30053
      end
      object PageControl3: TPageControl
        Left = 3
        Top = 126
        Width = 524
        Height = 259
        ActivePage = 标准信号波形
        TabOrder = 0
        object 标准信号波形: TTabSheet
          Caption = #26631#20934#20449#21495#27874#24418
          object Image1: TImage
            Left = 0
            Top = 0
            Width = 516
            Height = 231
            Align = alClient
            Picture.Data = {
              0954506E67496D61676589504E470D0A1A0A0000000D49484452000001F40000
              00C908020000005A27571A000000097048597300000B1300000B1301009A9C18
              00003A0B4944415478DAED9D0758154717863F7A478A288A285245B117C48E62
              6F51142C58628B35B1C61E7B8DBDC59258B1C68AD84B34F68A5D0101A5884A11
              905EFF39405089FE2010AE2CE77DF29865EFDEBD33F7EEBE73E6ECEC8E5C5A5A
              1A188661186921C772671886911E2C7786611809C27267188691202C77866118
              09C27267188691202C7786611809C27267188691205F947B7878784C4C8CAC8B
              975BCA952B27272797CF9D040404C8BA1E4CDE515757D7D7D7CFE74EC2C2C262
              6363655D1586F90A4A952AA5A2A2F2EFF59F97FBF5EBD7FBF5EBE7E7E727EB62
              E70A7979F9FEFDFB2F5CB8504747276F7B48494959B76EDD840913D2D2917585
              98AF461C03A6A6A67BF6ECA956AD5A9E77F2E0C1831E3D7AF8FAFAA6A6A6CABA
              420C935B1C1C1CD6AF5F5FBE7CF96CEB3F2FF773E7CEF5EAD5EBEDDBB7B22EF6
              5770FBF6EDDAB56BE7EDBD717171868686515151B2AE04932F860F1FBE76EDDA
              3CBF7DC48811A28D97752518E6EBB0B5B5757575353737CFB6FE8B691911B647
              4646CABAD839131C1CDCB16347117A7B7878D4A851236F3B898F8F175F4D5050
              D0F2E5CB9B356B26EB3A315FCDB871E3CE9F3F2FFE5DB264499E77327EFCF8A5
              4B97366FDE5CFC2BEB0A314C6E313131F96CD2A2C85F500D0B0B134177727272
              81C8FDF4E9D32D5BB694759D98AFC6D9D979DFBE7D0522772727A7BD7BF7CABA
              420C935F8ABCDCFDFDFDCDCCCC0A4AEE478E1CE9D4A993ACEBC47C358E8E8E07
              0F1E2C10B977EDDAF5C08103B2AE10C3E417963BC1722FEAB0DC19261BB9927B
              545C94B69AB6AC8BFA7958EE0C58EEF9E7E5234487A08A3D2DC747435E01D1EF
              101B093939E89685FAA7A7FFFDD330304159CBEC3B79179CF916420E0A8A4849
              06D20D939A0AF512D02B0B219CC458A4A4404985FE4B8CC3C51D286582CA4DE9
              CFCFE2750D2A9AA850358F554B4DA1EA7C8C2843BE474E7FFBFC3FB9C725C6FD
              76FAB70B0F2F44C64696D02CB17AC0EA88D8886507964105F272F2F41525A769
              696A8D6E3FDAACB499F833283C68F6FED90E551DBADB75CFDAC9CAE32BEF3DBF
              97A69026FC5BCFB2DED09643951595F75FDF7FF4CA51395539B19FD4B45424C2
              C6DC6664EB91AACAAA5F5B01963B03967BDEB87D94C45BB723C439B86D3C0C2A
              40550B5E5749B89087A2121950A7341AF640856A08F1476C045932291EEE2B60
              521375DA2329110A0A28511A5AE977189CDF0CAF1BC20E484D437202A242A065
              40CA9697A72D2D6DD17208FC1FE3C41AA86942590D3D6623311ED7F7E3D15FF4
              F656C3605E871622DEE0CA1E08C988E6415E91361082CEB04A4A22350CD51C50
              DE2687DA894A3D3C87A797D17A38D52283D7CF717A03C283605A1BAD87424583
              56C644E0F86A7A49D4A2ED489436CDCB9719F4144F2EC1FE7BFADEBE0DBE2877
              E1DC19FB66ECB9B26740D301FADAFA973D2F4FE834414F53EFD8AD63496949F3
              0FCDB72863D1AF493F2545A556355A95D22E25DEB2FEF4FA612B8635AAD3E8EC
              F4B32AE98DB0D8B9DD543B4579C561AD86FDF5F8AFFD37F68FED30769AE3B4BB
              BE77EFF9DC0B781730FBC0ECE1AD87D731A9535AAF74CB6A2D9514BEFA7B61B9
              3360B9E781D0006C198D0E6360DD086F7C70603E9C6662EB58727D85EAF8DB15
              BA6560D70D4AAA1471C745E1F71F911407550D8AC1DFF8D24A614CE15961F03A
              1DD1FE47DAA790F2CBFB14D40B71BFF5C5FEF9E83A118616D41EBC7C002B3BEA
              048816C5E324DA0CC7A145E83C0E8F2FD1AEC2FCA16B88DA1D51824C02EF1BD8
              3D0DB68E48884174380CCD919C88C810327BE98AB87B12355BA3F980FF573B51
              42F7E5F0B943CB63F6C0207D0CF8FB306C1A8E3296B0B1C7F15530AB03C7A9D4
              066CFF993EC5BE3F2EEF465C24466CA15A7F2DA2CBB2650C6CBBD0B7F16DF045
              B98BB05D78B95DAD76F37BCEFFF7ABADE7B6AE6F597F96D3ACAC35094909CE2B
              9C4BA897B8E6796DE30F1B9B556986F416C261B6839DA5DDBC9EF3C49F53774F
              3D72E7C88DB9373454A9C1F47BEB673FCB7EDB886D4D458F2CAFB0DC19B0DCBF
              1671D61F5A409AEE368DFE3CF22B2D779988D5FDD07D3AC954C4E08ACA68E292
              B97DC84B6C1E83E19B28B64D49C6EEA9B06C807A9DE9A5339B2810769E49CB42
              C1BBA690CD5BFD80B040925DBF25D4211071F1F39B18BA09A26B2ECC7EE7189A
              F5A108DA7916829E51EFE1E2360AEAAD1BE3FA01CACF8886E1C276D4ED84170F
              E07B873C2EFA101E27101B45F1FBB3CBD03742CB1FE8E31E9C45C59AD40E6523
              E009FC3CA8D370713B06ACA2B48FE0EA9FB8BC0B3FB952C0FEF03C764DC5B4E3
              D4C86D1A8951DBA8D978F71A2B7AD13720EC1FF0185A25298324EA2E9A01554D
              043E4678307562325A2041DC7BBCB8475F5DF92AB4B128D8F9ADE8BF2C7B164B
              467C39724F4D1DB979E4E9FBA777FDB4AB9E79BD8F5F4A4C4A6CBFB0BD5899A1
              EC0C2E3FBBFCC3C61FF68FDB3FF7C05C1D759DB583E85E920CB9D7B3A8B7B0D7
              42F1E74F5B7F0A890AD93E62BBA2E86D019E419EADE6B5FA63E81F0EA2939557
              58EE0C58EE5F4BCC3B6C1C86964361D38CF4B47600DA8E42F3EFB1D205B5DAC1
              A4066E1CA084494367A42441C710720AD83894C252A1B0A4045CFB13652C6069
              47F9748F53D02945217006FE0FB06D02BA4DA76079DB78F4598C606FEC9F8DBE
              4B6191AE91877FC1ED5798D642E01338CD40E45B0AA54FAD87961E149411F008
              2E0BA9A320E42BC27FFFC778F58C3E57B434628D08E4ABB6406A324A99A26A73
              EA3788F0FCC57DD46C83FA5D69FB6CF8DCC69E1918BC3653EE3BA750817B2FA0
              6551AA35FD317C337DE2F92D18BB87F42D64B8A237AAB5408B81D83482DC5DD2
              18CF6FC1A8122C6CA924BE77A1A084012BA9C5127D9193EBA8603111A8D90A8D
              5D9010473D03D16ED93497F50F4CFCBF9CBB7F98FFF08DC31FF83CE862D7655A
              F76906DA0619EB4590DE6161876C729FB473526078A0EB2857D11E8CDE3AFAEC
              2F67CBEA96153B6FB7A05D6068A07D157BAF375EAA4AAA737ACCA96A9C7961E4
              59D0B3D6F35AFF3EF4F796D5F23EB49CE5CE80E5FEB5043FA7BC478F59945FDE
              3915DED749EE0DBA639933E52E74CA20F235A94A282C293E5D9DDDB0CA05FAC6
              D0D021DD0BC7699782617A6EFAE543546A80AE533EECFCFA41BCF642A35ED835
              9D7A0357F7C1B23EED240311B63FBB828E63B0751C9AF7C78D233034A3ACC8C5
              1DA8D309DDA620C333897178FB027E7729C122DA1BC8C1EB3AC95D6C234C9D75
              E95588DED783E271E1B17A5D60569B1C9D8578CB9F733EC8FDF791D0D4A3443F
              D23348BF0D42A77178ED43EDCDC83FA0A842299AD5FD615A93B2558BBB92B8BF
              5F81F7A1B4A528D5D08DF4C6D57DA94B21BEAE7DB3A83B327E3FBD4B347862CF
              E29B119D15F3BA68D64FD63F3091F36899BD57F72E3FB43C493E69EF98BDE686
              7487EBBFE51E1E1D6E37D5AEBE657D475BC7C0B0C019FB662CEDBBB46FD3BEE2
              A5B6F3DB068706D736AB7DD4E3E874C7E9A3C497F20F2C77A6A060B97F1D5E37
              707419A5594448EE738B82533D23BA70BAF67BB41B4591FBA37378708E825C1A
              58224F8997ED1330E28FCC2B90BBA6C0AA116AB7A3E5BFB621D49F5219B191B4
              DBA4384A530835C747E3CA5ECADA6BEA42599DB614316F253BCA835F3B8026BD
              71EA37CA9088985D5D9B521FE737933D6DEC334BF8F46FB82D43592BF2B888EE
              E515282394104BF9969E7348E2D938B6926AD467211AF6FCA89A9FCAFD8F51D0
              D4CFCC20891AAD1B445D87C0A77870263DCFAE42955DF33D5DD46D3B92DA398B
              FAD4080977AFEA031192769D94B9135112A7999411DA3B13B5DB53A6A8CC3FB7
              FE8B8E82B2CA274D9DECC8D550C8E884E8E6339BD732ADB57EF07A7C4EEE876E
              1EEAB3BA4FE57295151514E5E4E4BC5E79D959DAB94D74132FD9CFB46F56A5D9
              8CEE746D76F4B6D17F8EF9B3B175E38C77B1DC998282E5FE75089B1F5C8021BF
              650E2339BB293DC3DE87E4DE712C4CAAE38D1F0ECD4F8F55D3870C86BFC2BA01
              949AD0D0A5F8F4F105E895837165B2A1F70D1AB8E23815D161B875949C2E242E
              F626ECE97112355A43BF1C25C75392C99E768E94CB3E309FD232C1DE18BB972E
              E136EA89277FD38559B1E75EF333A3F2FBA729A9926149513C0313544FB7C4A6
              91D43058D965564498F79527AEEDA7485CEC53B40DA52A7EA86636B9EF9E4EB1
              7FFF65B42CDEB57620C6ECA65EC8A975F8F91054D4A93A4B9DA9900D9D296953
              B9319A0FA4613FBFFD407BB64F8FC7458145909E71ADC2F31A5D1B78EB4B6D40
              8DF4AEC9AE69D0D046E79F65FD03135F947B7C62BCE72B4FABB256AACAAA62B9
              DD8276E50DCA6F1DBE159F93FB778BBFD354D35CDE6F796A5AAA90FBF987E7A7
              EC9A7268C2A1EA26D59BCF6A5EC7ACCE6297C562B3A19B86DEF3BB77EE977319
              175459EE4C41C172FF3ADEBE80EBCFA44E93F453E6F47A0AAE9BB860DD40749D
              4CF28A0AC5D1A5E8341E4656242F25351A5A53A11ABD949440430C4B96A73F85
              8EE5E428AF22DC2DE4ABF8D140F5373ED83E112EF329A5FE31B7DD290BE43004
              8717517EE3961B7ACDA3E47585AA7874811A1B214AD13C789CC0D34BE4FAD414
              CC6D436334454B23BCB161280D6B31AF4B7D0861F6136BE07915560D51BF0B65
              8DB2914DEE629F479660C4664A37898E82687B44D7212C80A275F141D68D682C
              E39FB331740365AB56F7A3350E83D3E53E842EF3B6481F9FB3650C45EE42EEF1
              EFA95482B503909C849F76D0BF5B7E42E526D407FA06F8A2DCC3DE8709836BAA
              6A9AE89B3C0C7A98989CB8F1878D754C6914AA907BB399CD1A583658DA8F9EAF
              74EFC5BDF60BDAAF1BBCAE739DCE19EF4D4A4EAA36A19A435587D50356D79B5C
              CFD6C2562C88F5FEA1FE4D6734756AE8B4A8D722F1E7E380C78D7E69B4EBC75D
              6D6BB6CD730558EE0C58EE5F4B422C36FC402173ADF4D44AA6DC7B93D10CCD29
              CDDD760405CE420E76DDB0E7177CBF9C561A57A1148D58B96302AC9B909A3310
              C1FBFE7918ED8A8F6F7514DB6FFF192E0BE8D2EBC7FCB5952E54B6194631B29A
              1625FA6BB5A7FC867543185953BCDCF2075AF9CA8B427B4B5B1C5B452511BA17
              6510CE156D838A1A85DB6D8667B601A28DF9385AFF986797B1731A466ECE1CBA
              9E1847C9A59017285F952EC3761893D91B101F71FD00F506C4CAFA5D49E82929
              58DE83AE36B71941725FE14217725B0FA58D45EBA26D40A921D1AE8406D0D5E6
              87E729D8174D4E5C14360C43FB5194CFF906F8A2DCC5FADB3EB76FFBDE0E0C0D
              AC58BAA2BD8D7DC69D4A481F4873CDFB9AAE866EE57295C59F0161019E419E0D
              2A3550CFC8ACA573F3F94D11C5D7B7A87FC5F38A8EBA4E157158A473C7F74E78
              747846A8FE3EFEFD35CF6B352AD6C818269F3758EE0C58EE79E0DC66BCF040DF
              5F694CF7F155E4E5EAADE8AAA96E59185B536EDAAA010D455756257FF59AF7C9
              7BCF6CA48CB3453D4AAF230D7EF7606C836E533FD926D88B464FF65F42CACE42
              44FA5BC7D11B95D5707A238D8217A214DD88ABFBD07A187DA2FF036A3F84AC9F
              5EC6F33B743D40DF08ED7EC299F5D457B0694EE5111B8B8E459F4594FCF9FF44
              8753FAA542754AB964101F4D577423DF52CAC5E41F5D88CEC1FDD3D49C883555
              D287650B2BFA79D0001E0313EA1F880A8A685DC4FB02FF87D441296B4983381F
              FF4DEAB7AC9F7EEF951C2EEDA29B695D167DF83899C2CF962158EE451D96FB57
              2334F7C78F14728AC0F9C621CA745773203709158A80DA6D096A7720EB5DDE4D
              11BAA5DD27EF1581FFBD539488A79B5153E90ED51AADE85EA48F090BC489B568
              3314252B7CF246B143E3CAB8739C32F8753A50542E3EDDD08CBA115963193DAF
              E2D86A9431A3FE4195F4C712BCBC4F313BC92A8D3EB171AFEC1D029923BE8D9D
              93D161348DBBFF3660B9132CF7A20ECB3D2F043EA101EF560D655D8E7F919A4C
              1EFFFAFBD56589E87F88F6CCBA91ACCBF101963BC1722FEAB0DC19261B2C7782
              E55ED461B9334C36A423F7478F1E55A952256F3B494D4DAD50A142606020CBBD
              889221F79F7FFE79D1A24579DEC9C48913172F5ECC7267A48174E4FEF7DF7FE7
              79E67B11B9D7AC5933383898E55E44C990FBC89123E7CE9D9BE79D4C9B366DCD
              9A352C77461A1479B9FBF9F9999AD220566D6D6D4545C5BCED447C09111111E2
              DF7DFBF675EFDE3D6F3B616448CB962DCF9E3DABA2A2A2A1A191E79DC4C4C424
              24243838389C397346D6156298FC52E4E51E19193970E0C00209B56AD7AEBD73
              E74E2B2B2B59D789F96A5C5D5DFBF7EF9F929292CFFD2828286CDDBAD5C5C525
              9FFB61189953E4E58EF4A4CAB56BD7E88E868CA9B39213E9A177FAE5E8BE8C8C
              B9B45253E9EE097905BAB9406C236A2CFE4D8AA7879ABE7D4193C2A43F884E68
              BD6CD9B2B2AE0D9347AE5FBF1E171747E3E7E4699A30FAD183BDE9DE13ED9299
              5B88435D1C1B72F2741888832163AE35B126318E6E359457845E193535B5FAF5
              BF89DB0B19269F4841EEFF9082C4F7F4FFB828EC9F43CFF1A9E6907ED7831C94
              B568DA30B181DF2DBAA34C9CDEA929285719EAA5707219DD7460659FDF0F67BE
              1D9222E9774F49C681792857090D7A644EE3A9AC01A40F9D0EB883B8686A03C4
              6150CA043A26B8B499EEDCA9C31939463A4848EEDB7FA61B8533C23411888973
              BB74453AA963DED133869C7EA139124FAEA3B35A41811E7ED4C0899E31ED3A99
              1E1F6AD74DD6A5670A88830BE879847AE5A8D316F996265230B4A0963D3E969E
              46DB732EDD99E9BE92A6725654A2C3A06A737A60D691C5D4CF6B3554D6A56798
              02432A72175A5FEA8C7623418F36FBE7DEB694240ADBFD1FD24C2B83D742E1D3
              CBADCF2ED3492E44A0A143330F8888BEF980CC070931459775E2476C4DB7CED3
              61A048BDB4E4443A0CDE05E1C0027ADE7789D29F6C1FE4897D33111E480F0CD1
              37A669D5EA7541A36FE2A97E0C931F2423F7342CEB01EB0630B4CCCCB367F1C6
              8F9E2137743DDE87D3A32D94D528A817DE17117DF82B9AC3C5B201CC6AD1B390
              C442CBC1B2AE09933F360CA5075D59D8663F0CDE87D2F34C441B2F5E888DA0C3
              203595BC2F7A72916F706537E567AAB5A4673F691B643EAD9B618A325291BB60
              71178AD4F4CB5314FFA17EF28809A7AB6A7D97E0C6419A912BD49F52379AFAD4
              73B7ED8CBD3350AF2BAA34A10904740D7398529DF9F6593F841EF151CE3AFD81
              85FF200E83F868CAB00F5E03CFEBF48C5611C82BA9D15577756D34ED43CFC92A
              57050D9DA88D17ADFE7713655D0D86C92F92917B1A56F645879F50B1160D83A1
              81109915A4203D319E26018889A02725B92DA5B966CA58D2F53465557AFE72DB
              91F40CD2DD5329396BDF5FD61561F2C7C66134F359ADF63406E6E3C340985DF8
              5D1C06F131647FD1A83771A1871D8A0D44DBBF69245D80A9DB89A66A4B4DFE46
              66D26198FC2015B927C4D26CE58D7A90BE85DC155591512F39399A3045A83C23
              8B7A751F6D200CEEFF88D2B26F5F60DB380C5907EDD2D839116675F9CA6AD146
              FCE89B86D328A9A8109AE8594523337E178741420C99BD597FBA8EFAF4123D66
              B6D35878DDA4C91984EED7F4A759402B54C3A185F4E8DAD6C3645D1386C92F52
              91FBEBE7344CA2514F5CD88AC6BD29EB9A919C11FDF187E748E283D690F45D27
              53E2454B8F26421CF21BEE9DC6938BB490920CD749A8D410B65D645D13261F44
              BFA3D6BAA1334DCD2C2271D1A8A7A5DFD624A700BFBB34F3E7A0B534E471D714
              9AF6C1B23E4D9FD663168D9C39BD01C37EA7297EF6CFA59C7BAB1F645D1386C9
              2F5291FBFD33B87D94E609136775BF25E4F42C9E5CC26D379A71E6D84ADC3C84
              8EE328ACBBBC9B4EFE606F3AC91B38D166BF8FA458BE661B59D784C9072FEED3
              A442AD86D27551C7A91F6E5F12043F87FB720C5849C7C9C1F9343BA868D1AFEE
              45C51A94B5D33342FB9F68B35D5351D60ACDFACABA260C935F2421777196EE9C
              4CD32456694AB9D44A8D691ADF4CD2A7CB12E1DBF72B699AC4877FA15405EA77
              2B28D25C8EA52AA2CF621A4721BAF04716D324B915F2F8E831E61B208DA63F8E
              8B86C3208ACD8DABD035F32C5E7B53076EC4161A027B790F0CCAD361A0AE8D8B
              3BE8DE66217DA1F8C438EC9B4D036AAB39C8BA2E0C935F2421F7B0409AB3FCBB
              899460DDF133CCEA4053E7C3AB2F1F669EBD721F0D8E8B7C831D1369F6DBB216
              D8FD0B8D76AFDC04ED467D12F233458BD8288ABB1BF7A4493B370EA5CBE37A65
              3EBCFAC68FEE691A9C9E96C9222981A6ABAFD501B5DAD234D041CF50BE1ABA4C
              A42BED0C53C49184DC93E229D9AA531A4989888DA4858F494BA5B35AC7F09395
              09318889845E59BA04F72E988652E81B671F19CD142D529268DEE48C548C58D0
              2D937D03F1439728454F95C92239918E0DFDF4005FB4F7227217CBF2797CB628
              C37C534842EE0CC330CCA7B0DC1986612408CB9D61184682B0DC1986612408CB
              9D61184682B0DC1986612408CB9D611846827C51EE627DFEA71B2E341415796C
              725E484E4E9675110A0C0505053939BE55213B52FA8999CFF225FB7D5EEEDEDE
              DEC3860DF3F1F19175B1738538A5070F1E3C7AF4683535355997A5C810111131
              69D2A4D3A74F4BA3EB268E017373F32D5BB6181919C9BA2CDF0AF1F1F12B57AE
              DCB06183347E62E64BB469D366CE9C39254B96CCB6FEF3723F74E850F7EEDD8B
              50E42EB87BF76ECD9A35655D8A22C3EEDDBB7BF5EA25EB521430A2815FBE7CB9
              AC4BF1ADF0E8D1A3AA55ABCABA14CC7F8EA9A9E99123476C6C6CB2ADFF625AE6
              D2A54B6FDEBC9175B17326343474E4C891A21DF2F0F0A851A386AC8B5364D8B3
              674FCF9E3D0D0D0D57AD5A25816CC692254B6EDCB83176ECD8A54B97CABA2CDF
              0A8F1F3F1627BCF871D7AC5953AA5429591787F9AF10DE13DDD67FAF2FF21754
              A3A2A2F4F5F593939359EE5FC5DEBD7B7BF4E8616161E1E5E525EBB21400A2A1
              12CDD5B871E384E5655D966F852CB9878585E9EAEACABA384C6153E4E5EEEFEF
              6F6666C672FF5A32E42EBE3A217779F922FF2C4C4747C783070F16BCDC93E269
              8A3E25155A4E49A6078B7EFCDCB1BC919A428F175651FBAF1F419A25771F1F9F
              8A152BFEA79FC57C83B0DC734D6800D434A1A14B0F928C0A81AA2654D43FB3D9
              C7D3737FCC67CFE4E877888BA449BD0B5DAF2CF75C71713B99BD81332DDF3946
              3F62ADB6B49C944053ADAA68D043259F5E4672023D563A39099F9C4D69505082
              A52D4A96FF649F014F70C99526F2D52A99FB82E401967B3187E59E6B764E8655
              03D4E948CB27D6C2D08CA66D12768E0EA373BEB4297CEEE2F611C82B4149991E
              1EFB3122E8130D43C31E30A8F0C9FA5B6E787086260C512EEC713E2CF75C7160
              2EFD341DC7D113FFCF6CA407BE37EA85D017147A2BA9D204004F2F61EF2C9AE3
              2531161A3AA4F80FC8C1F30A1C8664CEDF9B8590FB9EE9F871C7E783838283E5
              5ECC61B9E702118C0B7D6F1903EB86A8DB198F2FE2DCEF34ABB27523FA372509
              4695D0AC1FADF43809735B7A6E78C5EA14B565224751DEDFAEE8320936F69FEC
              F9E6619AF56DE8268EDCF349C1CB3D2A14818F69066D4185AAF07F88B02078DF
              80951DFDEE9ED7A8A5B7ED02EFEBD4A88B359776C26966F646FACC067A407CAD
              F674CCF8DC42C68C01E2F0F0BA86EAADA9F3270E2D6555546D8E72950BFC3B61
              B917737296BBD8203A3E3A36213615A925D44AA8FF136E24242524A7246BA86A
              646D29B651905750C94850022F435E7A057B69AA685637A92EDEF52EFA9D969A
              96A242E6787BF1DE98849812EA25F25981C290FB8BFB746E073D8596018566A9
              E923443D4EA06E279AA8EFE611380C84696DEA9ECBC95187FDB61B9C674351E9
              C31EC4977C650F4DC05DD60A871621F009C57D6263110F46BC2177C82B5274AF
              AC8256C3E8CFFF1E967B0E8405D29CAB947E49A5B659F4AEC4B17A76131D0CA5
              2BD2AC4F959BD05C7D252BD0ABE2A7DF360116F5A0F051465E44F7B5DA523420
              8CFFFB2884BFA286415E01A12FE17D0BD59A435D87E42E020211DA3B0C2EF0EF
              84E55ECCC959EE2151216DE6B5914B91535251525556EDDDA877BFA6FD941495
              96BB2F3F79FFE4B1C9C714FF99B9C665B54B5DD3BA3FB5FF292E316EEE81B907
              6E1C28A15AE26DC8DBAE4DBA2EE9B7A4F9ACE6D52B545FD66F997C7AF6F967D7
              9F83DF05EF18B5239F15280CB9073CA62EB9389FC5A95EAE12BAFF4222DE370B
              2FEE91DC85B2C569AF531A2635C8D7C756D2ECACC695699B0CC4372C04D16134
              C5776279452F9A94D9AC2E89E0D105F8DD458B41D4434F88C3F93FA8179F91D5
              FD8F61B9E7407222AEEDA7797775CB52D6A5624DFAA54403FFF42A65D8FA2DA1
              D65DD8B9CD70DAD86D292243D0C80989091FF62082007118644CE7EB3A999AFF
              06DD68591C36A2811FB4065AFAF4E7FE79342358F3EF0BFC3B61B9177372967B
              6058A0C31C87295DA70871EFBEB2FB57B75F2FCDBE54C7ACCEECFDB30FDD3C74
              6BE1AD2CB9B79DDFB6A155C3698ED3B65DDC3675F7D4550356D99ADB3E0D7A2A
              366856A5D9A6739B26BA4EBC38EB62D5F255C5CA4E8B3A2DEDBBB4539D4EF9AC
              4061C83D318EC2ABCBBB61618BB29608F5C71B5F0AC1DEF8D144DB2D87D024CB
              0D9D51A3350DAED83A169676A8D381EC90415AFAD554ED92A47E11E58920AEF9
              0098D7A597EEB8535AE6870D995B6E1D871AAD683FFF3D2CF79C1176DE3B83A6
              E4B5AC8FE3ABA1A5872ACDA06D801B87A8BD17741A4FC7833883D6F4879A36AA
              B648FFB13348A39F5BAB24BD5741295DEEB5D0A03BBDC272670A859CE51E1016
              D07951E70D3F6CA86B56D7E38547DB796DDD27B90BB9CF3B38CFEDB6DB95B957
              B2E42E7C6D676937B9CB64F1D2F68BDB1F2F7FACF8D174945171514D67346D5B
              B3EDFC9EF3C76E1BEBF3C6E7F084C3F9BF7DA6F02EA8FE318AFACEE21CBEE44A
              D32857A84A299A9B47F0E83C255BBA4DA3DE777418D60DA6DEBA41850F032732
              723586E6B0EB86B4146C184EF91CD14347BADC1F9C43EFF9F4DEE424EC9B8D7A
              9DC9EFFF3D2CF75CE13A896C2EBA56E73691AF53D3E8DFA4444AC7AB6AC17926
              F4D29F76207A60916FD32F9C64FCE872B4EC7387D26E0356415D9B9AFCB0406A
              2744331F1E08EF9BA8D602AADAA201C1A3BFD0C089DAFB8286E55ECCC959EEAF
              DEBD7298EDD0AB61AFCA4695775EDD29E26E119B0B6BFF1FB93F0A78D4F5D7AE
              D665AC67F59C55C3E4837037FFB579D1E1458B5C16CD3F387FD5F7ABEA8BA026
              DF149EDC9774477507546F83536B294523942D4E5411AA8BFF740C29579371FD
              E0B50F45FA1F0644A6B75ED7F6D1A5D7FECBD2F7E344E97811F189D83FF029C2
              FC61D518CACA4888A7EB6C8E533872CF03FF4DE49E8A3F46C2FF1106ACA4ABA9
              E247D4D0A1718D0FCF53965CC8DDA6191D0951219903E1B34E25F14621F4575E
              74F5C56511D4B4E0BE82D68B035EFCE82F1FE2DA9F68330CDAA549EE774FC0BC
              0EF2DD85FD372CF7624ECE727F13F9A6FE94FA726972BAEABAA1B1A1835A0C1A
              D37E8CA6AAE6DC83738FDE3EFAB1DC45806F6B693BA5CB14B17CDDFBFAD2434B
              2F785DE8DFB4BFD0BD5E7AE6313236B2CB922E4F9F3FEDD2A4CBBA41EB0AA402
              8524F7C837D83492322DDDA6522FFBC45A0ABD85C19F5D41DB917475B4B4293C
              AF52A49671C139EB4B156F11717DC023BC7D41819EE0FC161859A1B4190577B7
              DCF0F8028DB250D5A0C8FDC11998D743799B3C16F26B60B9E7CCEBE738F707A9
              3936122E0BB16B3A75B9740D717429BE5F49A939D121F3BD437D2F65D5CC565C
              FC23A740C3DE2B54878E01BC6EA0D73C3A3CE2A3E9DF8CD1047E1E38BC0803D7
              50A64E90244201B9F43D14302CF7624EAE72EEED16B49BDE6DBA7D157BCF579E
              C37E1FD6AF69BF711DC6AD3CB172F7A5DDD7E65F9343666AA5C3C20E0D2C1B4C
              E93A25E34FB1E7C3B70E0FD930C4B981B388D3330CB2F6D4DA99BB66BA4D7513
              317E8154A090E47EE7185EDEA71E7A5C34A547774EA19336E819EE9F81D32FF4
              AF460904795294F7CF60218AEB45849E184FD75183BDE9F4EE3229FB6E6F1EC6
              DD6310EDDCC7436B0A05967B0E8896FBE43A4447A0F3381A2B25547EF308466C
              A6F6FBD0220CF90D4716D330C77A5D9010837F4E010ADE539268411C061777E0
              7D181D27D9728FCF6FC16D09BE5F01DD32FFE977C2722FE6E44AEE1D17755C33
              704D43AB86E2CF01BF0DF00FF53F3BFDEC9FD7FE9CBA67EAD5B9574BA6DF68F7
              2EE65D93194D267F37B957A34F9E35E8FAB7EBF4BDD3CFCF385FB1141D5E6EB7
              DDA6EF9B7E64FC11935226055281C2907BDC7B6C9F40B72CD5E948A3184FAD27
              CB8B30FCE9255CD88E1EB3E99E14FBFE34F0F9E32F33318EC64A0BC58BB3FDC0
              3C1ACBDCC425FB9EAF1FC0DDE318B8FABFBE9FE5DFB0DC73E07D380E2F44E3DE
              30A98E9B8770F857D2B48D3DDDACB479348D81897C8B8E6350FED371ABA2093F
              BD9E22FD9464043F478731A8D420FB9EBDAED3BD513F6CC8CCD7FF67B0DC8B39
              B9927B8BD92D2677992C62EDE31EC7E71F9C3FC571CA98766302C303DBCE6B6B
              636C33CD719AAAB2EA32F765E71E9E3BFBCBD9727AE5F65DDB97989CD8D4BA69
              446CC4D2A34B9FBD7A767CCA713D0DCACC1CB87E403409EE13DDCDCB98E7AA80
              395118721771B75070F301943CD93713AF9E63E02AEA53C74460F77472B75816
              51B9AAE627EF7AE383632B90984899192D3D384E83E6BF1EDE74751F5D531DB2
              9EE59E4F0A5EEE4909880ECF0CAE1FFD451915EBC6992F8928DEF70E5D21AFF8
              AF474C8B16FDC945C44451CECDC82ABBFA3378FB02F74E51D63EDF3779FC7F58
              EEC59C9CE51E1A15DA6E413BA4405555352E29CEB1BEE3E876A35595284578E1
              C98509DB27A425A7D1AD498AF8D5E5D7C6E927C0AA13ABD69E5CABA7AE979C92
              5C42B3C46CE7D90DAC32E397131E277E75FB75F3B0CD452972A78EB61C9DDEA2
              AB1EE4099D32D0D4C97C29E61D420351AA028DA2C98638CF435E52265DBCD1A0
              3C3D87E4DFBCF5A347D6882F47A1B0679262B94B1E967B31271777A8222D2E21
              2E2E312E352D555D455DE35349C527C57B0679A6A6A6562A5749ED9F7BAFC596
              11D1119EC19E7A9A7A26062659F7AC0A52525344502FD6C817D023F1F8A99079
              83E52E7958EEC51C7EB64C3185E52E7958EEC51C967B3185E52E7958EEC51CE9
              C8FDC58B17152A54C8FF0E8B09274E9C68D7AE9DC4E43E6DDAB43973E6C8BA2C
              DF0AAF5EBD32323262B9175B8ABCDC5FBE7C6962622216441C6A606020EBE214
              19BCBDBD4F9E3C696C6C2C1A4509C8BD63C78EEEEEEE356BD66CD4A891ACCBF2
              AD101616B66BD72EB120E46E6A6A2AEBE230854D9197BB084F6AD4A811121222
              EB8214496C6D6DAF5EBD2A01B90F1D3A74C3860DF9DF8FF4D0D7D7F7F0F010AD
              B8AC0BC21436455EEEA2FCD7AE5D5BB3668DAC0B5224993F7F7E46BFA7A8131F
              1F3F6EDCB877EFDEC9BA20DF1CC3860D13BD99FC3FA18F29721479B9330CC330
              FF86E5CE300C234158EE0CC3301284E5CE300C234158EE0CC3301284E5CE300C
              234158EE0CC3301284E5CE300C234158EE0CC3301284E5CE300C234158EE0CC3
              301284E5CE300C234158EE0CC3301284E5CE300C234158EE0CC3301284E5CE30
              0C234158EE0CC3301284E5CE300C234158EE0CC3301284E5CE300C234158EE0C
              C3301284E5CE300C234158EE0CC3301284E5CE300C234158EE0CC3301284E5CE
              300C234158EE0CC3301284E5CE300C234158EE0CC3301284E5CE300C234158EE
              0CC3301284E5CE300C2341A420F77BF7EE6DDCB851D6A52892FCF2CB2F868686
              B22E4501909292327DFAF4888808591784610A9B162D5A74E9D2455E5E3EDBFA
              222FF7E0E0E07AF5EA050606CABA204592A64D9B9E3F7FFEDF874591E3A79F7E
              5AB56A95AC4BC13032404747E7ECD9B3B56BD7CEB6BEC8CBFDE5CB9726262662
              A15DBB76BABABAB22E4E91417C6F972F5F363232F2F7F79780DCDBB76F7FFCF8
              716B6BEB5AB56AC9BA2C0C53A8B46CD9B277EFDE8A8A8AD9D61779B90B379999
              99252727FBFAFA56AC5851D6C529321C3B76AC43870EE2ABF3F2F29280DC1D1D
              1D0F1E3C3875EAD4B973E7CABA2C0CF34D201DB97B7878D4A85143D6C52932EC
              DDBBB7478F1E1293FBB871E3962C5922EBB230CC3741AEE42EB671BBED76C7E7
              4E5C425CB58AD53AD6E9A8A3AE43EB9176F1F1456D75ED5A15A92FFCEADDAB33
              0FCE34B7696EAC6F5C681560B9E78DDCCAFDDA0198D642E98A484DC183B3103F
              7409834F368889C0BB60C8C989630969A99FBE390D4AAA28690C05A5ECBB7DE3
              8B606F943643C043D4680B65D5CF7C74C46B3CFA0B76DDA1A0889C60B9334C36
              72967BE8FBD0519B4779F87934B66AACA4A074C5EB4A19DD32AB07ACB6286391
              9A96DA614107EB72D64BFB2E8D4B8CEBB9A267547CD4F611DBCBE9972BB40AB0
              DCF3466EE5BEA2375A0E469566488AC7AE69286F03EB46E4E5A850E89645B516
              B8B413E737A38C25D93F1B4989888DC0805530289FB9461C6C72E90BF74EE3E6
              117CF7334EAC865649749D8CF7A1F0BE493B9193474A322CEA212901DBC661C2
              81DC5487E5CE30D9C841EEE2D5B1DBC61EF3387670FC411B631BB126242AC465
              958B96BAD6AE1F77292B2A3B2F77AE5CAEF28CEE33C66E1F7BF9E9E543130E19
              E91915660558EE792367B9C7BCA3A8DC6D19EA7D07554D3CBB8C47E711F106D5
              1CA0A58FA810D46A47D23FB60A31E1A8500DC1CFD166C487B70B8927C462CB18
              384E45396B785EC5F35B5054A1705E04F2AF3CE1FF88F62CDA0CB15CB733750E
              FEDE099F3BF45ED15494B5843890CE6E24EF2B2A435E017A6551A2F497AAC372
              67986CE42077FF507FFB99F6633B8C1DF1D1797BDDFB7A975FBB1CF9F9483DF3
              7A42EE352BD634D03258717CC5EED1BB331A80C284E59E377296FBE30BB8ED4E
              5655D5406C249A0FA0B8FBEC2698D7456A325E3C40131794AB4C391925650AC3
              EF9D846D176446E6E988D05BC4EC22D257D5C2915F111A40364F4BA5D8FC8D2F
              3C4EA0491F689480BC227D84692DF2BEFB0A2427A2C318FC39072F1F20E425F5
              1584DCFDEEA16A73F4FBA2B859EE0C938D1CE47EEED1B9E1BF0F3F30EEC0C7D6
              0E8E08AE3BA9EEB2BECB9C1A380D5837E0A6CF4D4579C5F543D6D7B7A85FF815
              60B9E78D9CE52EFC7B7C15DEF841539722EB5A6D49E8A77EC3E38BA8DE025D26
              E3F26E546E4AEE166C1D8BD8281859223929F3EDE2B04A4946DBE1D04ECFD1BB
              2DA1B0BDF53088CF1272174DC2CE2918BA118A4A7876851A0C6170C189D5888F
              419749F4DEE737E9E306AFA5C4FDF1D5D4577059F8A5EAB0DC19261B39C8DDFD
              AEFB98AD63DC27B95B95B5CA5AF93AE27583690D16BB2CEE56BFDBF7EBBE7FE4
              FF2836297646B7194E764E855F01967BDEC859EE223C7FE58D7DB3D0793C09F7
              F21EB27CA586888984E715E81BE3F573749F0E830A781F86E53DD16220CCEB21
              ED9FCCBB38AC84AF4560AE5E82FE3CBA02D7F6A19409A2DFC1B832E56AFEF809
              43D691D9FFDA8261BF434D8B3613CD89F8ACAE936959741D6E1CC28095B47C66
              2322DFA2DBB42F5587E5CE30D9C841EE5EC15E6DE6B599E33CA777E3DE592BEF
              FADE755CEA7860FC815A156B392F77AE6E52BD42C90A135D27EE18B5C3DEC6BE
              902BC072CF1BB9BDA0FADB10384EA6EB9CB7DD615489B2340A8A942479729144
              DF712CAD897987FDF3A0A2066575641D4E62B380C730AD8DF63FD29F0745D09D
              8A46BDF1FC066EB961E456FC3E12F6FD29CF63D9000E0333DF45917B2CBA4CA4
              E5BF5D11E4899E7368F9D84AC4BD67B9334CEEC941EEC929C9BD56F50A080D10
              C1BBBE96BE58139310D37B656FA1835D3FED525154E9B1A2877539EB99DD674E
              DA39C9F592EBA969A7AA94AB52981560B9E78D5CC93D2A14ABFA90C41B389185
              85D345E89D1043C974E32A3426B2C5601A0499964A599494247C7C2C29AB91A9
              1362E13C8BFEDC3111D68D51A703BC6FE0FC16FCB01E0717C0EB2AD4F528F1A2
              A699F9AE63AB6804A45D378AF745445FB23C5A0EA1F58716404E8146D77C0196
              3BC36423E7A190DEAFBDFBAEE99B9894E858CF51415EC1ED8E5B526AD21F43FF
              A85ABE6A6A5A6AFB05ED85DC97F55D26F6E3BCC2F98ECF9D233F1FB1295F7897
              5559EE79235772F7BC860BDB10178526BD6960CC1F3FC26926AD7CE343D73CDF
              8750F6FCEF9D78EB472AFF98E444D46C83601F5AF86E02AD113D00119E5BD8E2
              F651789C24A19FFA0DC7D760D45698D5A64190DA25F1E4123C8E232C0826D551
              BE2A8DCF110D43190B7ABBDB524AF2B41BF5A5EAB0DC19261BB9BA8929242A64
              DDE9759E019E6263AB7256835A0CCA18C92EFEDCF1F70E036D83B635DB666CB6
              F8C8E2C6D68D3BD5E954681560B9E78D5CC9FDF062A868D0D5CEC8379472B9B6
              0F3F6CC0F503E4DFF63F62F754D4EE0005654487236B0F42F7C2C2A9A93034A5
              ABA08616E4F4C0A7383017AD8651D8EEEB81FA5D616806D789A4FE61BF93D637
              8F469D8EF0BD4B0322C5C789A36BEB38D27A46F25DB06F264A18A2F5D02F5587
              E5CE30D9E0C70F14537296FB6B1FEC9D41696EA34AB8B61F27D6C27906C5EF8F
              2EE0E236D468833BC7E0B200D96E6B888DC08373E477D11EDC3D01A71934047E
              FF3C1A21D9B40F2E6C87591DCAE11C5F09FBEF295F7FF71834F5297BF3C3FAF4
              DB5C81F020EC9C4CD76387ACA3CC7E54182582C4AEBA4FA30BB65F80E5CE30D9
              60B9175372967BF82B4ABF5837A6B48CFB0A1AD26ED78DD62726E0922BBD64D3
              82EE50CD46C80B9C5E0FC8D37099AA2DE88E27C195BDA4F872D699DB3CBD4CE3
              266BB7A3E5739B71C71DED46C2A679E6AB0FCF5142A6DD8FD0D0A55E82F74D92
              7EA58614DA7F19963BC36483E55E4CF98A0787D13303E472BB5F19C17267986C
              B0DC8B29FC54488691362CF7620ACB9D61A40DCBBD98C27267186953E4E51E11
              11616060C072FF5A32E46E616121E42EEBB21400A22EA2462C7786C9E28B72BF
              77EF5E585898AC8B97336FDFBEEDD3A74F4A4A0ACBFDABC8907BD9B265B76EDD
              2A81C87DE6CC99972F5F1E3B76ECD2A54B655D1686F926F8BCDC8F1D3BE6E4E4
              141B1B2BEBE27D0577EEDCE1C99173CFCE9D3B5D5C5C645D8A0266D4A851AB56
              AD92752918E69BE0F3727FF4E8D18001037C7D7D655DBCDCD5414E6EF0E0C153
              A64CD1D4D4CCFFDE8A09212121A3478F3E7DFA7451CFCB65208E01737373D162
              999A9ACABA2C0CF34DF0C5B44C7C7C7C6262A2AC8B975BB4B5B5655D84A2476A
              6A6A7474B4AC4B5160282B2BABAAAAE67F3F0C230D8AFC0555866118E6DFB0DC
              1986612408CB9D61184682B0DC1986612408CB9D61184682B0DC1986612408CB
              9D61184682B0DC1986612408CB9D61184682B0DC1986612408CB9D61184682B0
              DC1986612408CB9D61184682B0DC1986612408CB9D61184682B0DC1986612408
              CB9D61184682B0DC1986612408CB9D61184682B0DC1986612408CB9D61184682
              B0DC1986612408CB9D61184682B0DC1986612408CB9D61184682B0DC19866124
              08CB9D61184682B0DC1986612408CB9D61184682B0DC1986612408CB9D611846
              827C51EE77EFDE0D09099175F11886C9178D1A35D2D0D09075291819F079B9BB
              BBBB3B3939C5C5C5C9BA780CC3E48B8E1D3B6EDBB64D575757D605610A9BCFCB
              FDF1E3C783060DF2F5F59575F11886C923C9C9C9E1E1E162C1DBDBDBDCDC5CD6
              C5610A9B2FA66512D39175F11886C9234F9F3EAD57AF9E9C9C9C8F8F4FC58A15
              FFDFA669A99093133628C88F27B1A4414E3EC7ED0AF873997FE00BAA0C234DBC
              BCBCACACAC72967B6A324EAD47CD763034454A12AEED47157BE81A7EB24D6800
              82BD20AF48B216DB7F8C10889A164CAA435199FE7C1F86B8F7286502DFBBF0BA
              0E874199EBB310EB63DEA5EF27158666B4E5E53D30AD85B296B2FEC2A406CB9D
              61A4C9E3C78F6D6C6C7296BB30C05227749904B3DA080BC0BED930AE02D39A78
              ED439A16CEADD916EECB71D38DD627C54145FDA337CB212106614118B1197A65
              69C5D1E55052469B11B87D147FEFC2A8AD5052F9B0794A3296F7847A09689744
              C063583746BB51B4A6FB2F30B2A2C6233505CAAAB988F7999C61B9338C34C995
              DC435E222A047F6D876D67C4BE27E1FADC2459DB76815649BCF645E39EA85803
              C7569291D534F1EE35DA8EFC640F4909D83A16DFFD0C830A781F8E859DA05B06
              D68DF0E23E82BD61634FB216DB68EAC1BE3F9454B16E203AFF4CD998970F10EA
              0FAB06D83F17B5DA51874094A48C25ECBAD1C64CBE61B9338C34C995DCEF9E80
              C771C829405189CCDB710C89F8C862185923FE3D126251A30DC5D489715054C5
              B11578F237893B0B618FE444D4ED0CB35A5050A600DFCF837C2D22F4A067D472
              546F999E8149A1B6A17E578AE2B78C816D57785E456953043E457438DE87C271
              1A829EE2D22EF49E8F3216541226DFB0DC19469AE44AEE6F7C70F677BCB88732
              9550AB0D09D7EF1E6E1C84D70DD4694F21B6107DD33E30AF4712FFE347E89743
              B9CAB49C491A5D10CDB0B608C3DD96C0791634D2875D3EBA807BA7E0B2E0938F
              4B88C6D6F1A8EF88E73749E2A737507E46590D23B7E2D915DC72439F45B2FEDA
              A443CE72BFE17D23F05DA0838D4309D1F6A6E319ECF936E26D63EBC659DB3C78
              F9E0F2B3CB416141467A46554DAAD633ABA7F271A28D6198422757724F4BA58B
              A53BA7925545EC7CFD00CA5AD005D59877B87914F2F23492A5DB7468E890BB57
              B8C06120654EF08F34843D1495A15B16FA46087802DFDB2859016929D415787C
              112FEF53F25D2E7D304C4A12F48CA8F1D83216768EF0BE8192C67876159DC651
              8760C04A5C3F8410BFF48C0D5330E42CF7EECBBAEF77DF3F63D88C99DD6766AC
              997768DE498F9397665FCAF873A9FBD24D6737591B5997D22A151E1B2E7EF7F9
              BDE65B8866996118D991DB0BAAC9495837003DE722360A778F93734560AEA048
              0977BF3BA8DC141D46536A253612E736434101F24A1FE42E2F247E0116B6B48D
              58F0BE090525B2B978FBDD13887C83463D684D6A0A12E3E9226D9566D83C1A75
              3A22E02174CA50DEC66906764E4183EE7401D6A0029AF593F5D7261D7296FBC0
              DF069EF538ABA2A6B263E40E5BF12BA6DBFCEC83B327A69C10CBAE975CC76C1D
              B36EF0BAAEF5BA2AC82B88BDBD8E78ADA3A1A326BA5A0CC3C88EDCCAFDAD1FD6
              7E8FCA4DD0B837AEFE4911B7596DBA702A626DCBFA3426B26E6744BFA334BA7C
              7AF63C0B11F56BEAE1E83228A9E1BB09E9299A7499889640587BFB04C44490BB
              2B35A42D33D627C460D774DAADFF431AFEF8C69722F7ABFB70EF3454D4D0693C
              F99D292072967B8F153DB4D4B44A6A95BCEA75F5D4D453AA4AAA59728F8E8BB6
              9F6DDFA67A9B393DE6C8BA220CC37C426EE52EA2F50767111B817A5D61D38C86
              BEF45F8E5B47E85267DB9108F224A75F74A5B48CF247D73945789E9440D973BF
              BBD02C89D6433FBC24627C6176E32A30AB83B39BD07532CA5A65BE949A8C377E
              78700E17B7D3A898A67DA06D80C8B798D618CDFAC271AAACBF334991B3DC9D96
              3BE96AE82EE8B5A0E9CCA6FD9BF51FD761DC32F765671E9C1172F77DE36B3FCB
              7EDB886DCDAA348B4F8CBFF8F462486488A6AAA69DA55D699DD2B2AE1AC3146B
              7225771189EF9808F3BAA8581311C1347CE5ED0BB82CC485ED345AA6CD08AC1F
              823623E936251174670D3F1766A7E53468E961F72F342446583E03AF1B38BA04
              BA4634EE45451D7F6DC5D5BD68D8038D7A66DECD1416883DBF50DAFDEE496A4B
              6A77C0915FF1E42225EB450B21DA03A680C895DCD594D584C1F75FDF3F65F714
              F749EE7F3DFAEBF0ADC342EE4F039FB69CDB72EF98BD0DAD1A86BD0F1BBD75F4
              3DCF7B815181AEA35DDBD76A2FEBAA314CB1265772F7F3A0DB537BCE4509031A
              EB72EF1406ADA51B971E5DC0F9CD9439097A8ABEBF424DFB93778505D08DACCA
              EA087F85B7BEE8350F25CBE3E5431A7813F48C86D9380C465662F6FE199CD940
              83299BF583A51D764EA27B975A0D4578108D7D7CF9805A8EEEBFE0C9259CFF83
              E4DE693C5DBF65F2CD57C85D6C3970FDC0B8C4B83AA6752E3EB9E836D1ED4DC4
              9B06D31BCC769ADDBB716FB165724A72405840D3194D97F45DE264E724EBAA31
              4CB12657728F7C4B09993296343C46A8D6C28E46AC237D70CB9DE308F3874D0B
              1857CEFE2E11DDDF3C44C1BB8222AA36A741F14897F8B3CB68E04409996CC4BD
              A7E195FAE5E8A5A75750BF4B6627E0F26EC445A1C520BA302BF0BD035F0F4AD7
              B0DC0B82AF90BB580E0A0FFAEED7EF446FCCB8A4F1C1F10785CD45B47EDDEBFA
              9189478CF48CC4062151217526D559ECB2D8B981B3ACABC630C59ADCE6DC1989
              92B3DCDBCE6FABA6A27670DCC18C3F0FDC38D06D5637DB1AB6D7E75F177F0686
              07BAAC721121BCB39DB3B181F18527170EDD38B47FFCFE36D5DBC8BA6A0C53AC
              61B917737296FBC6731B951594FB37EB9FB566D69FB334D534C7751897F16744
              4CC4FA33EBEFF9DE7B17F3AEB46EE916362DBAD975D350E1C95F184696B0DC8B
              3905F9F881F8A478557E2804C37C1BB0DC8B39FC6C198691262CF7620ECB9D61
              A44996DC5FBE7C696C6C2CEBE230850DCB9D61A44996DC9F3E7D6A626222EBE2
              30FF152A2A9F7F4A23CB9D61A4C9FDFBF76BD4A821160C0D0D151515655D1CE6
              BFA275EBD6F3E7CF2F55AA54B6F52C77869126AF5FBF767272BA74E992AC0BC2
              FCB7989B9B1F3E7CB84A95ECF78EB1DC1946B28485855DB97245D6A560FE5BAA
              56ADFAD90BE62C7786611809C27267188691202C7786611809C2726718869120
              2C7786611809C2726718869120FF0358A2BC13A13817900000000049454E44AE
              426082}
            Stretch = True
            ExplicitLeft = -5
            ExplicitTop = 25
            ExplicitWidth = 518
            ExplicitHeight = 203
          end
        end
        object PageControl4: TTabSheet
          Caption = 'EOT'#20449#21495#27874#24418
          ImageIndex = 1
          object Image2: TImage
            Left = 0
            Top = 0
            Width = 516
            Height = 231
            Align = alClient
            Picture.Data = {
              0954506E67496D61676589504E470D0A1A0A0000000D49484452000001F40000
              00C908020000005A27571A000000097048597300000B1300000B1301009A9C18
              000021EF4944415478DAED9D0B5414D7FDC72F08BA9A88C4C4AAD51C31A9564D
              4FC5AA115B3168515031E2032B9856B031A0262A51312A1C447C0535E02322F1
              F84A0A9880880F226A82A2F52FE671C0A601131F90138C18AA45139528D0FFF7
              326458D74560218E3B7C3F87B36776EE9DCBDCDD9DCFFDCD6FEEEED8FCEF7FFF
              13841042F4850DE54E0821FA83722784101D42B91342880EA1DC0921448750EE
              8410A24328774208D121943B2184E810CA9D10427408E54E08213A8472278410
              1DF220B9FFF7BFFFCDCECEB6B3B3D37A276BA7BCBCBC7BF7EE9D3A756A4823D7
              AF5FCFC9C9912F8A8D8DD61D22F5A3A2A2E2F1C71FEFD7AF5F03DBF9ECB3CF7E
              FCF1475B5B5BAD3B44482D28EA767575ADE9E35AA3DC6FDDBAF5D7BFFE352525
              45EB2ED4157777F777DE79A76BD7AE966D0EB3CF9D3B77DBB66D3C95B1523A76
              EC181F1F3F64C8108B5B387AF4E8E4C9932F5FBEAC755708A92BCB972F5FB468
              91D9A21AE57EF3E6CD050B16BCF7DE7B6DDAB479947D8751ABACACECBBEFBEC3
              F2FBEFBF3F71E244CBDAC9CBCB7BFEF9E711B5FDEA57BF32180C8804B5EE19A9
              2BF6F6F6454545B76FDF9E3163C6DB6FBF6D713B3367CEDCB46953CB962D3B74
              E870F7EE5DADBB45C88380A360E688888869D3A699AD504BCEFDC2850BCD9B37
              7F94E56E6363F3EDB7DFBEF4D24B0505057BF7EE1D3D7AB465ED9C3F7F7ED0A0
              41DF7FFFFDBE7DFB7AF7EEFD2877999880013E3030F0C30F3FC4B9D79A356B2C
              6E079BBFF5D65B23478E8C8B8BE3E84E1E7DA0A92E5DBAD454AA870BAA858585
              43870E3D77EE1CBCDC40B95FB972252B2B6BC080015AF789D40F9CB125252535
              50EEF3E6CD5BBB76AD8F8FCF071F7CA075870869287A903BBCECE9E989938C46
              917B6666E6E0C183B5EE13A91FE3C78F4F49496914B98F1B376EF7EEDD5A7788
              908642B9573742B95B2F943B212650EED58D50EED60BE54E8809947B752394BB
              F542B9136242ED722FB959B2EBFF761DCA395472ABC4606F38B8E8E08E633B76
              66EE34AED3C1B143E2EC4465B9A0B8206053C04ABF952EDD5CD40ABEEB7C8B4A
              8AB0E0ECE4FC973FFE45295A95BAEAD09943C6EDA0347A4A747DFB40B913CA9D
              10136A97FBC0C5031D1F739C3D72362C9F999B193B2D16FA2EF8BE40542A7BC1
              980530B2A1B94155F992A4257147E23C9D3DB7CFD8AE36D27566D7497F9AE4D1
              DB0336DF7C64338ABCFB7B9FBD7416C6C71FDAC1D8801102FF08ADD5B70F943B
              A1DC0931A116B943E84F043C911D956DD6B9503634EDF69C9BF1CA8EAF7444D8
              3E7DCBF4CBEF5C86ACD59AE13EE1FE6EFE58461184BE67FE1EA50843054AF3DF
              CE776AE764591F287742B9136242ED917BCFE09E3D7EDD23714EA2C1DE605274
              BFDCD373D2837706E745E721DE9FE236256858905A5395FB8815233054600050
              8A2877D2702877424CA85DEE390539BEEB7C11C243C78A9D55EE973B6AFEF6D7
              BF5DE2B324262DE6FDFF7BFFD4F2536A4D08BDB753EFCCDC4C3CC556AACA2977
              D2702877424CA8EB6C99CD4736472445B8747351D329E23EB96300E8F84AC7D8
              69B1D0B492494708DFA3530FF1B3DC1D1F734CFD34357176A2A7B3A7DA08E54E
              1A0EE54E8809F5980A090BF709E9B367DE1ED5E62672570600C5E6E0ECA5B388
              F495F48B9A9681DC03360540FA1D1C3BA8CD52EEA48150EE8498508BDC4BEF96
              221E57448C6558387A4AF4A43F4D524A4DE46E9267DF757257F0CEE0CBEF5C16
              F7E6DCC7AE1E6B686E309E3A49B9930642B91362422D7257A2754F674F98373D
              271D6B8E861F359E03A3CA1D713A6A1ACF90C160D0F1958E4A12C658EE452545
              78BA67FE1E253943B9938643B9136242ED6999AC7359D03A8277B75E6E6ACA45
              2DEAF1EB1E8ACDA16C68DAF88B4BA2F2622C4A616DD4C4A39A8AC17A83BD4169
              0D6340D6D7592EDD5DEE9F8D5347287742B91362027F7EA0BA11CADD7AA1DC09
              318172AF6E8472B75E2877424CD089DC3D3C3CF2F3F3333232DCDCDC2C6BE4FB
              EFBFEFD3A7CF77DF7D47B95B238ADC172D5AB47CF9728B1B59BC78F18A152B28
              77A20FF420F773E7CE21722F282878E38D379C9D9D2DB8419AADAD2DE48E63FB
              FAF5EBC78E1D7BE18517B4EE13A91F63C68CC1799B979797BFBF7F595999052D
              D8D9D9EDD8B1E3C081032FBEF8E2DEBD7BB5EE10210D4527721F356A141E1BDE
              148E7084FFAEAEAE5AF789D48FC99327272424344A537E7E7EF1F1F15A778890
              86A207B9979797BFFBEEBB1B366CB02C645341FCEEEDEDBD60C182962D5B6ADD
              27523FCE9F3F3F6DDAB46BD7AEE1BCCDC6C6C682167020E003D0B66DDB2D5BB6
              FCE637BFD1BA438434143DC85D010736FA62D981AD80B1E1C9279F6CD6AC99D6
              5D21965052528261BE211F007C7EF0EE3B3A3A6ADD15421A01FDC8FD1E4E250B
              8776E2B93AA4CE0B7345D66E31214CEB3D268DCA99C3223F477887D45EF346B1
              488A147F5FAFF51E13D2C8E848EE5F67C93F852B17E5B2AB5F75E9C009E2C9CE
              62EB2C79302BC0FE38A4512D6D9D084ED47AEF4983C1389D73B86AB9F407713C
              5E0C0FAA2E751E2E3AF712876245EEF1EA9578DFAF168A685FB1EC84D67B4F48
              23A323B91F8811E74E8B6E03CC142136FFDB6AD1DDC5743DCC6E1CB9DBB7105D
              FB68DD0D6229385DFBFCC03D425739BC59F4F59203BC0919DBC4B54B72C32101
              556BBCE668DD0D421A077DC95DD4707022341B35DB8CDCB1098E6DF8FDF7C364
              AC87B88F119CF502476374C7287E3FEFCE97A37E4D72C7FBEE325E3EC5395C6C
              BED6DD20A471D097DC11833FD9D94C11F41D18275A39549FB62BE054FDD68DAA
              B81EA7E71BFD45F8475A7783580AE49E1A253A3C6BA6A8E882CCBFE3EDFE78DB
              3DEB31DE3BB41389A15579B9E95D2977A21BF42577FB16C263BA99221CF6388C
              6FDF90722FC89142EF55F91D541CED5F67891BFF91473EE48EF88EC977EB05EF
              32DE5CDF65668ACE1C96A37EFB67457EB6FC3B73A4EA5A2B5662E0FFEC40D505
              55CA9DE8081DC93D39523839CB8B66EA255363BAF691EA173FA76810DF216403
              88DA70C2DE6FB43CC8932229772B26639B1CB6074E90E3F4FD3CDD4BB474900B
              5B67897E5EF2F380A7F8481C8A958F43A7CAA2593DC4FAB35A778390C6414772
              47DCED325EE65840DB4EF7141DDD2E16A5C9300DA7E7DB66C9E515A3C4D4F552
              F151E3644E060B9C3663EDE0D40D6F31CC7E294F74EA794F917A451D033FDEF1
              F08FE4A0DE7B98E83D5CC4058A417E72D62C4EEC968FE24517A21B74247784E4
              3880216828DEE4DA69A8ABB4368E7C0C00CA218D5378286078908870176BCFC8
              3A90FB8904CE77B6629490FCDB5CF9469B5C3B55AFA8A7460987A7649CAE9CA8
              05C58925EE62719A3C8DE39C48A22FF42277E388AC26B92BA19952949F2D1F11
              AF393957A5E9CF1C96A958B3732DC8A3CFDD9FE4BB0C4D1F8FAF51EE4FF7120B
              9EAF4ADCA1BEA8CCD5E0A9927FC7591DA2785E51277A412F724F8E14AD9F929A
              466C8EA04CC9AEAA40E5386871CC233C57B3ED08E2F03424456A1DE1DEBF8EC8
              C9CEF7CF9623568132A97142984CCE7C7EA0EA2D5651A64B615C87C1D5E934D8
              04E76A8BD264E99799F2CB4DBD06739E3BD10D7A91FBA158E9651CD258403C8E
              70CC189CB0FB84991EF008F170B4E350C7810DFB63A19F8537FA20DA8337B14D
              3BF9BE9BFDE5098CFD389F33F9546093560EF2CAAAF2D5567E0088BED08BDC09
              21841841B91342880EA1DC0921448750EE8410A24328774208D121943B2184E8
              10CA9D104274C883E47EF1E2C53D7BF634E4A694C4DA7172721A376E5C435AF8
              F1C71FFFF18F7FDCBA754BEBAE10FDD3A2458BA953A736F006F7A9A9A9509FD6
              5DA913767676AFBCF28AC160305B5AA3DCAF5FBFEEE1E171FAF469ADF79F6889
              BDBDFDA64D9B5E7EF965CB36FFE9A79F828383636363B5EE07692A0405056DDC
              B8D1E2DBDCEFD8B1233030F0CE9D3B5AF7A3AECC9E3D3B2626C66C518D722F2B
              2B4B4C4CDCB061439B366D98BA696A28A76BFFFEF7BF8B8A8AE6CE9DBB66CD1A
              CBDA292D2D1D366CD83FFFF9CF9E3D7B76EEDCB9A2A242EB9E117D626B6B5B58
              58989797E7E2E272E2C40984B496B5B370E1C255AB56B56FDFFE77BFFB9DD67D
              AA051C4D30338ECDBE7DFB9AADC09C3BA991975E7A293E3E3E2C2C6CE9D2A596
              B580C87DCC9831870E1D42F83F7DFA74CB1A21A42E6CDEBC199F317777F7F4F4
              748B23777CD4C3C3C37D7D7D131212B4EE5043A1DC8979E0E5C99327EFDEBDBB
              51E4BE7AF5EA79F3E669DD27A267D6AE5D8BCF58A3C87DDCB871BB76EDB2B7B7
              D7BA4F0D827227E6292D2D45E44EB9136BA171E58EC8BD458B165AF7A94150EE
              C43C943BB12E2877131A2AF7D2BBA5595F67393B393B3EE6A8755F486342B913
              EB827237A176B9171417749DD9557DEAEFE6BF7DC6762C1495148D5D3D36EB5C
              568F4E3DCE5E3AEBF69C5BE2ECC40E8E1D4CEA2B1C0D3F8A0A5A77B6B1516EF2
              A0DCC8293F5BFE29F75936062B959BFE98A59583E98F8C8B1A7E7CFCA143B913
              EB827237A1AE72CF7F3BDFA99D93BA12013B56C2D710BDC1DE80A7019B0210C2
              E7C5E4E1A9526749D2926F8ABF5146027DF27556D59D97C1ED1BF23E7FBECBE4
              2DDC8A2EC81BB44E0893F77E0A75958F66C1262D1DCCDC925BBDE1A7A650EEC4
              BAA0DC4DB050EEAB5257ADFB701D56AA2A57741FEE131E342C4859A373B99F4A
              96D686DCFB7A8973A7E5BDFA10A177ED23DA3F231F216EE5B63E90FBB213D2FB
              3E6172BD31181BD2D655DDDCF5DBDCEAF52691BBD9E8FE97877227D605E56E42
              5DE5AEA45CF0B447A71E5818BB7A2C1656FAAD34AE89E01D8FAACD752EF777E7
              CB9B6B17E488AB8522284EC6E085B922215478044965C3CEBD8757C5EC90FEDC
              DE326363D7FC9E16606D258D03CB43E8BF1F56B51E0306C2F6B69DE472E90FD2
              FBF747F7BF3C943BB12E287713EA2A77976E2E86E632485F306681A7B367CFE0
              9E58F077F337AE099B9F3E77FAE0A283EA533DCBFD78BCC83B2EEC5AC83C0CE4
              9B9F2DF3EF87370BFB16627E8A7C84FD152943FA589E1066DA02EA28B1BC717A
              47DC9B96C1C8A1B6F370A1DC897541B99B60615A66C48A1103BA0D58E2B3C4B8
              262277C7C71CA3A7442B4F752EF7DB37A4CD738F4B29478D93417AAFC1D2C847
              B78B4FF7CB0A10F4E0C97221639BAC363CC84C23903B144FB913D2602877132C
              943BC4BDF7D3BDD951D9EA1A25E71E3B2DD6BBBFB75A47CF721795D6CECF117F
              5F6F3A2506DEBF5E2C9E7BA12A2D732A59BAFB7EB055F847B20ED332843418CA
              DD8406CD96F174F684CD0DF686A29222DF75BEA5774A4F2D3FA5D6D1BFDC53A3
              A4DF4352A49DF32B93EF08DEA166E7E1C2D05A0AFAC1335E425DA5B52977421A
              03CADD847ACF73777BCEED68F8515139CF3D7867F0AE93BBB00CBFFBBBF9AFF4
              5B69FC5526FDCB7DA3BF9C2A7374BB4CB21F8A959A1E38412655FEB65A38B4AB
              9A137978B3F96D7DC2C4067FF1E627668A38159290FA43B99BC09F1FB094C25C
              B139504E733C10239D1E17285EDD219DAEC8FDF60D39672630AEC6CD952934EB
              CF9A29A2DC09A93F94BB0994BBA56C9D259330D0FAD54269F6DF0F135E73AAD6
              238487FA517AFF17564F25CBFAE0CA45D1A69D992934827227C4122877132877
              4B81BE95EF16E567CBF40B2CAF00779F392CA7BDF71B2D67C2988022E5FB4A18
              009C87CB6AF7C39F1F20A4FE50EE2650EEC43C943BB12E2877132877621E55EE
              4B962CC1C7DDB2462A2A2ABCBCBC0E1E3C48B9935F1A45EEC3870F4730617123
              CB972F0F0D0DA5DC899E51E58ECFFA1B6FBC61D9E7E4EEDDBBBEBEBE8CDCC943
              4091FBB061C39293936D6D6D2D68C1C6C666CD9A358866C68F1F1F1F1F4FB913
              7D72EBD6AD891327A6A5A53DF3CC33DDBB772F2B2BAB6F0BCA5DB63FFFFCF36B
              D7AE4546466290D0BA4F44CFAC58B162F1E2C56DDBB6EDDFBF7F7979B9052D34
              6BD6ECDCB973172F5E1C3162444A4A8AC160D0BA4F0D827227E681CD57AD5A15
              11116181D64D68D7AEDDD6AD5B478F1EAD759F889E4120121010505C5CDCC076
              A0F8F0F0F0850B17DAD9D969DDA70641B9931AF9E1871FF6EEDD5B525262F1E5
              29519999E9D6AD9B8787876567CA84D4918A8A8AF4F47484DECD9B37B7B81184
              FC8E8E8E2FBEF8A2838383C58D3C2250EE8410A24328774208D121943B2184E8
              10CA9D10427408E54E08213A84722784101D42B91342880EA1DC0921448750EE
              8410A24328774208D121947B5325635BF58DA24E2557DF6CA4815C2D94F7FBEE
              375A5CB9F0A0FB8D18FF7742C82F00E5DE540975953780558870172129F2B650
              4517E47DBDED5B88AE7DE4FAE4C8AAFB4699D06BB0F0986EBE59983D6D9DF8FB
              7A79835954F39A236F276BDC488767E59D668DFF3B21E41780726F7AC0B660F9
              2811FE918CAF730E8B1309720DB4DBCA4174EA296FDFFA803BB842DF59BBE54D
              C0D5A7F853B976493E75192F972FE5C95BCB3EDD4B244556DD39F6C9CE627890
              78EE05CA9D905F1ACABDE9712A59FA3D63BBBC0DF7958B32BE46281D172816A5
              C922883B38B1EAEEAFCA5313B06DE75ED5723F1023258E2141A1F407395A2872
              17953657123EA80610C843EB8AE85550416D8D10D24850EE4D8FA20B626F947C
              84A3E17704EC378AC5BBF365F20431B54F98480815DE21D2CB663189DC616DD5
              E0E0EE4F6245E53981A8CCBFAB8DA87257D647FB5645EE183FCE9DA6DC096974
              28F7260994AA64C6E1592C204EEFEB250AF3E4D3EE2E22375346F1F0AF5910B9
              5F2F964302C273381DD6FEFC808CFDC1D3BDC4843031B7B7587B4614E68AADB3
              643BCA4980B1DC31AE602C0949A9DA13FC53653D21A4F1A0DC9B2408D5A3C6C9
              D8F946E56D6B1435832F33457EB69CEB02778BCA392D58564AE17A0C00832757
              554305252A4F8E943919581E8E86B2831365E265719A5C86FD7B0FAF6AD958EE
              670E8BCF0EC8A1051C8F97FB40B913D2D850EE4D1284D5CB4789577748B166ED
              9642EFDA47DA195136548E3FC5BC4A80EF1D22150FB963ABF929B2FE67FB6522
              45B9E88AF0DCD54F2EA334354AB6191728DA3F2B2FD506C655FF4755EE08FCD1
              66EBA7AAE6DB184B9F10D27850EE4D1284DEFF4C9049F6F08FAA12EE88B84DB2
              E70A28CD392CCA7E12678EC80100B13C827198DDFEE71BC343FA788A0DD55C3C
              EAC0F2212932A75F74411661F080D03178C0EC6342E4324A95C01FFF14638972
              424008693C28F7260982EB417EF24A66FB67E45325EBADCA7DA3BF8CDCAF17CB
              08FDF303D2E32EE3A5DC47CD96D74BB12DFC3E3440BA1EB20E759503035A80D9
              BB0D909B6F0E944E5FF2919C38BFE079D9145C8FD01EA5CFBD20071234A29C19
              0014611F1AEB2B5484909FA1DC9B1E85B9D2BF88D9616D84F089A13297D2E159
              19715FBB243DAE5C0885E2A16325FFAECC8141540EA123963FBC59E6CA95EBB1
              D804E304860104E0CFF4912DA385D21F64515F2F697C34AE921C29CF0316A7C9
              914349F7E3BF2BCD12421A15CABDE9919F2D658D501A7177D438E968E5770260
              DBA448F9A87CCF480596477D3511AF806A580335239C57AFC79E4A968F4A180E
              8F63E440536A548ED2CF2BAFA322A2C74082530100AD7B8768FD8A10A2432877
              4208D121943B2184E810CA9D10427408E54E08213A84722784101D42B9134288
              0EA1DC0921448750EE8410A2437422F78A8A8A2B57AEE8A32F0F0DBC686DDAB4
              69DDBAB5D63B22B97CF932F6C7C6C646EB1D21C46A80F13A75EA5453A91EE47E
              E7CE9DB8B8B8989898BB77EFEAA03B0F8D66CD9AF5EDDB77E3C68D1D3B76D470
              37CACBCBDF7BEFBDA54B97969595F1ED23A4EEE0108E8A8A9A3871A2D9523DC8
              FDABAFBE1A3162447E7EBED63B6295AC5DBBF6F5D75FD770078A8B8B5D5C5C2E
              5EBCA8F52B4188F5111A1A1A191969B6480F723F7FFEBCA7A727E4BE6CD9B27E
              FDFAE1EC5EEB3D7AD4B1B1B1C1E90E3E1667CE9C59B76EDDAC59B334DC99AB57
              AF0E1A34E8ECD9B3F88C0E1830806F1F217501EAC6C13272E4C89A2AE844EE1E
              1E1E90FBC71F7F3C64C810AD77C76A707777C72BB67EFDFAD75E7B4DC3DD80DC
              5D5D5DF3F2F2D2D3D3F13E6AFDAA10A21374227744EE172E5CD8B76FDFE8D1A3
              B5DE1DEBE0C68D1B5E5E5E274E9C7874E4FEC1071FF8F8F868FDC210A21328F7
              26CA2328F7A4A4A4091378D70E421A07CABD8942B913A26F28F7260AE54E88BE
              A993DC8B4A8AA66F999E5390830597EE2E0BC62CF074F6548A023605E071FB8C
              ED784485818B0726CE49F4EEEFFD30FB40B95B00E54E88BEA95DEE05C5057D42
              FA4CFAE3A4C06181067BC3B1DC630B1316AEF45B19342C4818C91DDE87D9678F
              9C3D67D49C87DC07CADD02287742F44DED721FBB7A2C1EF7CCDFA3AE49FD3415
              817CFEDBF970BD22F7D869B143960C41501F3D25FAE1F78172B700CA9D107D53
              BBDC5B4E6E7974C951976E2E66572A722FBD5B5A7AA7D47800789850EE1640B9
              13A26F6A917B417141D7995D6FC7DF46906EBC1E2BC37DC2FDDDFC21F7F49C74
              C83D7F63BEE3638E9AF48172B700CA9D107D538BDC4B6E963C11F0445E745E8F
              4E3D8CD763E5C1450795C81D662F2A29726CE5C8C8DD8AA0DC09D137B5A76510
              A49B5C265566C55C7EE7324275252D133D255A5E74FDD3A4957E2B1F7E1F2877
              0BA0DC09D137B5CB3D262D2622394289D345E5B4C8112B46783A7B2A1E5767CB
              9CBD747660E8407516CDC38472B700CA9D107D53BBDC4BEF96462445AC4A5D05
              B91B9A1B8E7D790C513C24AE64E18DE7B9A7E7A4C3FB1806D459F00F07CADD02
              287742F44D5DBFA18A801DB139169C7EE5E4D4CE495DAFAC5433F2390539180C
              4CA6D6FCD250EE1640B913A26FF8F3034D14CA9D107D43B93751287742F40DE5
              DE44A1DC09D1377A907B717131ECF0D5575F51EE754795FBD6AD5BA74E9DAAE1
              9E949595FDE10F7FF8E28B2F2877421A9107C9FD9B6FBED9BF7F7FEBD6AD1FE5
              01C0D6D6F63FFFF9CF9B6FBE09C5EFD9B367CC98315AEF917500B98F1C39F2E4
              C99353A64C717777876135D90D1B1B9BDBB76F2F5BB6ECD2A54BEFBFFF7E4DF7
              712784D4971AE5AE1EFC5AEF615D69DEBC7972723223F73A72FDFAF571E3C665
              646468BD23D5ECDEBD1BBBA4F55E10A2136A947B4545C5860D1B76EEDC89D0F8
              518EDC4565F407468D1A151212D2AA552BAD77C73AC07BFAF1C71F474646DEBC
              7953F3F7176FDFD0A143C3C2C2709AA8F50B43884EA8EDB7654A4AECEDED353F
              F86B054311BC004768BD235606CC8E974EF3D7ADBCBC1C6F1FC208AD5F0F42F4
              831E2EA81242083181722784101D42B91342880EA1DC0921448750EE8410A243
              28774208D121943B2184E810CA9D10427408E54E08B112BECC14378AC5C0CA5F
              973B952C5A3988DEC34DEBDCBE21BECD35BF79D73EC2BE45F5D3A20BA2C3B372
              213952B88C179D7BDD5319FF08158CB7C59A1309C23B44EB57A1AE50EE84102B
              0142BF5A28BCE6C8E5FC6C7178B3181220D7E0AF2047BCBA43AE2FCC15499166
              B6C5FA4569E2C9CE554F61EA0877B1EA13A9FB685F316AB6E8EE62FABFD2D655
              D587E54352E49AB23B943B2184342AC7E3A588E1F1A77B89DCE3E2EBACAA28BE
              F55332006FE9606A671360F0BFADAE967B62A86CA1AF975CCEDA2DB76DDBA9AA
              08EDE384401948B01EE70719DBA5FDD10276C0A15D55B55E8385C774AD5F9407
              41B91342AC81A871327972ED92C8CD943138C8D826AE5C14ED9FA9CA9640C450
              BCA8F4F8FD1847EE58466B43A70ABBE6F2E903E40EB0C9B9D3C2C9598E078BD3
              64F6E6408C5C39F051BFF700E54E08B1069223C5F562B900B1228E46DCFDAF23
              329C47D81E92229F229CF75D56E3E6C6913B348D785F49EF8015A3649149CEDD
              44EECAF2D000E9FD77E70B573F99857FB4A1DC0921D6C08D62A972A8B6DF6899
              2E47ACDD6BB07C846A615E940627CA4BA908C3556EDF904526D67E75871C0980
              7A7175EB2CE113569D6F1195C17BCEE17BE4DE7B98B06B21437E8FE9729CF8FB
              FA7BEA3F9250EE84102B011EEFDC53A653143BAB28167EEE0529DC2F33C5D1ED
              3212C732AA6DF417E11F4941E7674BEF4F0893C687CD55EEFE248B10FE1BCB1A
              AEC73881664B7F9009199C13E05C415486FC81717268597642EBD7A276287742
              889500532B135710C2239A6EE5203AF5942A1F12204B9D875705E9CA44175443
              E5B840D1FE5919E063258C8F01C0848C6DE2CC1119F82F4ABB67A2A49296B972
              51A6624E2448B9638458314AF4AA6CC11AE6CC50EE84102B016EEDEB25850B4D
              C3DA102E6C1EEA2AE368C4E388C1D5E81B6A86FDB106D676192FF3F5AFEE3093
              252FCC159B03AB468B6B9764B32AD8109B47FBCA36958992503FAAA129FCBB47
              3E2723287742887570E6B0CCAB04C6C9C92A8327CBE92E4A6E44913B6C0EE9F7
              1E26A3EC2F33A58BB10C0523840F4E9452DE1B254702E58AA80236498D92D973
              650E253CDEE15919922B536E940AFF3A2206F949A16300B875439E3AE071E004
              46EE8410D248C0E63E6132FACECF96497344D3CA644484F343026472664C884C
              D4145D90575C5107B17CEE71197D2BF1389E7EBCAD2AEAFF6CBF1C030096952F
              A92A646C93EBF12F94D9388737CB78FFC9CE72B44083CA844B34BE6D96FC2F58
              BEFFFBB18F12943B21C41A507F2D006A4670AD66CFB11E41BD328B46A530574E
              770188F14D5228D03D22F15E83CDAB19A508D8316CA04D585E993A89812129B2
              2AEDAE00DDDBB7A8E56B535A43B91342880EA1DC0921448750EE8410A2432877
              4208D121943B2184E810CA9D10427408E54E08213A84722784101D42B9134288
              0EA1DC092144873C48EE274F9EDCBF7FBFC160E0004008D1968A8A8A366DDACC
              9831A355AB561AEE467979797272F2175F7CD1AC5933AD5F12F99ABCFCF2CB5D
              BA74315B5AA3DC4B4B4B870F1F7EE28415FC263D21A489B074E9D2B0B0300D77
              60DFBE7D53A64C292929D1FA95A862EEDCB96BD6AC315B54A3DCCBCACA929292
              76EDDAD5BA756B46EE8410ADB0B1B1B1B3B3FBE4934FF2F2F2468F1E0DBD6AB8
              3330E9FCF9F3DBB56BF7E73FFFD9DEDE1E81BC567B82B01D6686DCFBF7EF6FB6
              422D3977ECBAADADAD567B4F08210A0B172E7CF3CD37FDFCFCE2E3E335DC8D8D
              1B37BEF6DA6B6E6E6EA9A9A90E0E0E0D6FD06214753FC0CFBCA04A08B102E6CD
              9BB776ED5A5F5FDF8484040D774391FBE0C183F7EFDFAFADDC6B857227845801
              73E7CE7DEBADB71E11B9BBBABAEEDDBBF789279ED0FA557910943B21C40AA0DC
              EB0BE54E08B10228F7FA42B91342AC00CABDBE50EE84102B8072AF2FB5C8DD66
              A28DA7B3E7C14507D5354322864C79618ABF9BBFF234EB5C564452447A4E3A96
              9D9D9CFFF2C7BFBCE1FD86D69D2284E80DCABDBED42E7783BD21765AAC6A7363
              B9A77E9A3A7DCBF4709F70EFFEDE1D1C3B1CFBF2585149D1A43F4DD2BA538410
              BD41B9D797DAE5BED26FE5BA0FD765476543DFC248EEF078CFE09EDB676C87D9
              B5EE052144E750EEF5A576B9E7BF9DBF306121961367270A23B9EF3AB92B7867
              F0E5772E6BDD054288FEA1DCEB4B9DE46EB037A841BA2AF725494B3273338F86
              1F45B59C821C881E0B88EE95318010421A11CABDBED449EE4EED9C761CDB81F8
              3D2F3A6FEC9AB18ADC63D2627666EECC8ECA46B582E20254F8A6F89B635F1E43
              7DAD3B4508D11B947B7DA9ABDC456542060BF0B82277787CC48A117931794A29
              C09A804D01943B21A4D1A1DCEB4B3DE40EADF79CD3D3F131C7957E2B95D932BE
              EB7C0BBE2FD8337F8F72AD95722784FC4250EEF5A51E7207316931C13B83B7CF
              D8AEC8BDE466099EEE38B6C3D9C919CBA5774BBDFB7BC74E8BD5BA538410BD41
              B9D7975AE48E60DCA5BB8BC1DE60BCA647A71E4AA8AE00ADE714E4600DD66BDD
              1D42883EA1DCEB0B7F7E8010620550EEF58572278458018ADC35BF13D3A64D9B
              66CE9C49B9134248E3F0FAEBAF4747472372DFB973A756D6B2B1B1D9B2650BE5
              4E08218D465050505C5C5C9B366DBA74E9525151A1C93ED8DADA5EBB76ADB0B0
              B06FDFBEE9E9E94F3DF594D6AFCA83A0DC092156C0AE5DBBA64E9D7AFBF66DAD
              77443267CE9CC8C8C8C71F7F5CEB1D7910943B21C43AC8C8C8B87AF5AAD67B21
              5AB468E1EEEEDEAA552BAD77A41628774208D121943B2184E810CA9D10427408
              E54E08213A84722784101D42B91342880EF97FB42C01B97E6AEED30000000049
              454E44AE426082}
            Stretch = True
            ExplicitLeft = -5
            ExplicitTop = 28
            ExplicitWidth = 518
            ExplicitHeight = 203
          end
        end
      end
      object EditStdOkDelay: TEdit
        Left = 126
        Top = 84
        Width = 55
        Height = 21
        TabOrder = 1
        Text = '0'
      end
      object EditEOT_T2: TEdit
        Left = 283
        Top = 84
        Width = 40
        Height = 21
        TabOrder = 2
        Text = '90'
      end
      object EditEOT_T1: TEdit
        Left = 239
        Top = 85
        Width = 37
        Height = 21
        TabOrder = 3
        Text = '50'
      end
      object EditEOT_T3: TEdit
        Left = 332
        Top = 84
        Width = 38
        Height = 21
        TabOrder = 4
        Text = '50'
      end
      object ComboBoxMachineIF: TComboBox
        Left = 14
        Top = 28
        Width = 168
        Height = 21
        Style = csDropDownList
        ItemIndex = 0
        TabOrder = 5
        Text = '0-'#19981#21551#29992
        Items.Strings = (
          '0-'#19981#21551#29992
          '1-'#26631#20934#20449#21495
          '2-EOT'#20449#21495)
      end
      object ButtonMachineHelp: TButton
        Left = 424
        Top = 95
        Width = 104
        Height = 25
        Caption = #26597#30475#24341#33050#23450#20041
        TabOrder = 6
        OnClick = ButtonMachineHelpClick
      end
      object ComboBoxAbortOnError: TComboBox
        Left = 291
        Top = 5
        Width = 168
        Height = 21
        Style = csDropDownList
        ItemIndex = 1
        TabOrder = 7
        Text = '1-'#31435#21363#32456#27490#28903#24405#20219#21153
        Items.Strings = (
          '0-'#32487#32493#28903#24405#21097#20313#36890#36947
          '1-'#31435#21363#32456#27490#28903#24405#20219#21153)
      end
      object ComboBoxAbortNG: TComboBox
        Left = 291
        Top = 32
        Width = 168
        Height = 21
        Style = csDropDownList
        ItemIndex = 0
        TabOrder = 8
        Text = '0-'#25152#26377#36890#36947#22343#21457'NG'#20449#21495
        Items.Strings = (
          '0-'#25152#26377#36890#36947#22343#21457'NG'#20449#21495
          '1-'#20165#20986#38169#36890#36947#21457'NG'#20449#21495)
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = '*.*|*.*|*.hex|*.hex|*.bin|*.bin'
    Left = 458
    Top = 441
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.lua'
    Filter = '*.lua|*.lua|*.*|*.*'
    Left = 303
    Top = 463
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 217
    Top = 448
  end
  object OpenDialog2: TOpenDialog
    Left = 168
    Top = 448
  end
end
