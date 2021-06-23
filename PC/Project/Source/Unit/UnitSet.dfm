object FormSet: TFormSet
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'FormSet'
  ClientHeight = 658
  ClientWidth = 560
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 10
    Width = 545
    Height = 640
    ActivePage = TabSheet2
    DoubleBuffered = False
    MultiLine = True
    ParentDoubleBuffered = False
    ScrollOpposite = True
    Style = tsButtons
    TabOrder = 0
    object TabSheet2: TTabSheet
      Caption = '   '#36890#20449#25509#21475'   '
      ImageIndex = 1
      ExplicitLeft = 0
      object Label25: TLabel
        Left = 378
        Top = 520
        Width = 144
        Height = 13
        Caption = #65288#19981#21253#25324#27169#25311#37327#26657#20934#21442#25968#65289
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object GroupBox3: TGroupBox
        Left = 6
        Top = 115
        Width = 522
        Height = 268
        Caption = #20197#22826#32593#21644'WiFi'#25628#32034
        Color = clGradientInactiveCaption
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object Label2: TLabel
          Left = 10
          Top = 153
          Width = 58
          Height = 13
          Caption = 'MAC'#22320#22336#65306
        end
        object Label11: TLabel
          Left = 9
          Top = 178
          Width = 60
          Height = 13
          Caption = #30828#20214#29256#26412#65306
        end
        object Label10: TLabel
          Left = 226
          Top = 179
          Width = 60
          Height = 13
          Caption = #36719#20214#29256#26412#65306
        end
        object Label12: TLabel
          Left = 237
          Top = 152
          Width = 46
          Height = 13
          Caption = 'CPU ID'#65306
        end
        object Label1: TLabel
          Left = 204
          Top = 120
          Width = 80
          Height = 13
          Caption = 'UDP'#25195#25551#31471#21475#65306
          Enabled = False
        end
        object Label4: TLabel
          Left = 21
          Top = 208
          Width = 46
          Height = 13
          Caption = 'IP'#22320#22336#65306
        end
        object Label5: TLabel
          Left = 234
          Top = 238
          Width = 48
          Height = 13
          Caption = #31471#21475#21495#65306
        end
        object Label6: TLabel
          Left = 226
          Top = 210
          Width = 60
          Height = 13
          Caption = #23376#32593#25513#30721#65306
        end
        object Label7: TLabel
          Left = 8
          Top = 238
          Width = 60
          Height = 13
          Caption = #32593#20851#22320#22336#65306
        end
        object Label8: TLabel
          Left = 9
          Top = 265
          Width = 70
          Height = 13
          Caption = #31649#29702#31995#32479'IP'#65306
          Enabled = False
          Visible = False
        end
        object Label9: TLabel
          Left = 219
          Top = 263
          Width = 84
          Height = 13
          Caption = #31649#29702#31995#32479#31471#21475#65306
          Enabled = False
          Visible = False
        end
        object Label14: TLabel
          Left = 143
          Top = 9
          Width = 376
          Height = 13
          Caption = #25628#32034#37319#29992'UDP'#24191#25773#26426#21046#65292#22914#26524#26377#22810#32593#21345#65288#27604#22914#34394#25311#26426#12289'WiFi'#65289#38656#35201#20808#31105#27490
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label15: TLabel
          Left = 437
          Top = 183
          Width = 67
          Height = 13
          Caption = 'USB'#21475#20063#21487#20197
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label17: TLabel
          Left = 438
          Top = 198
          Width = 58
          Height = 13
          Caption = #20462#25913'IP'#21442#25968
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object EditMac: TEdit
          Left = 81
          Top = 147
          Width = 121
          Height = 21
          Enabled = False
          ReadOnly = True
          TabOrder = 0
        end
        object EditHardVer: TEdit
          Left = 81
          Top = 175
          Width = 121
          Height = 21
          Enabled = False
          ReadOnly = True
          TabOrder = 1
        end
        object Button2: TButton
          Left = 11
          Top = 112
          Width = 73
          Height = 25
          Caption = #25628#32034#35774#22791
          TabOrder = 2
          OnClick = Button2Click
        end
        object EditSoftVer: TEdit
          Left = 304
          Top = 175
          Width = 121
          Height = 21
          Enabled = False
          ReadOnly = True
          TabOrder = 3
        end
        object EditCpuID: TEdit
          Left = 304
          Top = 148
          Width = 207
          Height = 21
          Enabled = False
          ReadOnly = True
          TabOrder = 4
        end
        object EditScanPort: TEdit
          Left = 291
          Top = 116
          Width = 41
          Height = 21
          Enabled = False
          TabOrder = 5
          Text = '30010'
        end
        object Button3: TButton
          Left = 102
          Top = 113
          Width = 39
          Height = 25
          Caption = #28165#23631
          TabOrder = 6
          OnClick = Button3Click
        end
        object EditLocalIP: TEdit
          Left = 81
          Top = 206
          Width = 121
          Height = 21
          TabOrder = 7
          Text = '192.168.1.213'
        end
        object EditJkxPort: TEdit
          Left = 304
          Top = 233
          Width = 121
          Height = 21
          Enabled = False
          TabOrder = 8
          Text = '30010'
        end
        object EditNetMask: TEdit
          Left = 304
          Top = 206
          Width = 121
          Height = 21
          TabOrder = 9
          Text = '255.255.255.0'
        end
        object EditGateWay: TEdit
          Left = 81
          Top = 233
          Width = 121
          Height = 21
          TabOrder = 10
          Text = '192.168.1.1'
        end
        object EditSysIP: TEdit
          Left = 82
          Top = 260
          Width = 121
          Height = 21
          Enabled = False
          TabOrder = 11
          Text = '192.168.1.213'
          Visible = False
        end
        object EditSysPort: TEdit
          Left = 306
          Top = 260
          Width = 120
          Height = 21
          Enabled = False
          TabOrder = 12
          Text = '30000'
          Visible = False
        end
        object Button1: TButton
          Left = 431
          Top = 214
          Width = 83
          Height = 39
          Caption = #20462#25913'IP'#21442#25968
          TabOrder = 13
          OnClick = Button1Click
        end
        object ListBox1: TListBox
          Left = 7
          Top = 28
          Width = 509
          Height = 79
          ItemHeight = 13
          TabOrder = 14
          OnClick = ListBox1Click
        end
        object Button4: TButton
          Left = 352
          Top = 113
          Width = 73
          Height = 25
          Caption = #26597#30475#30005#33041'IP'
          TabOrder = 15
          OnClick = Button4Click
        end
        object Button5: TButton
          Left = 431
          Top = 113
          Width = 82
          Height = 25
          Caption = 'ping H7-TOOL'
          TabOrder = 16
          OnClick = Button5Click
        end
        object Button8: TButton
          Left = 154
          Top = 113
          Width = 38
          Height = 25
          Caption = #24110#21161
          TabOrder = 17
          OnClick = Button8Click
        end
      end
      object GroupBox1: TGroupBox
        Left = 6
        Top = 17
        Width = 230
        Height = 82
        Caption = #36890#20449#25509#21475#35774#32622
        Color = clSkyBlue
        ParentBackground = False
        ParentColor = False
        TabOrder = 1
        object Label48: TLabel
          Left = 20
          Top = 24
          Width = 60
          Height = 13
          Caption = #36890#20449#25509#21475#65306
        end
        object Label16: TLabel
          Left = 11
          Top = 48
          Width = 93
          Height = 13
          Caption = 'H7-TOOL IP'#22320#22336#65306
        end
        object ComboBoxCommMode: TComboBox
          Left = 102
          Top = 18
          Width = 116
          Height = 21
          ItemIndex = 0
          TabOrder = 0
          Text = '0-'#20197#22826#32593
          OnChange = ComboBoxCommModeChange
          Items.Strings = (
            '0-'#20197#22826#32593
            '1-USB')
        end
        object EditH7IPAddr: TEdit
          Left = 102
          Top = 45
          Width = 115
          Height = 21
          TabOrder = 1
          Text = '192.168.1.211'
          OnChange = EditH7IPAddrChange
          OnExit = EditH7IPAddrExit
        end
      end
      object GroupBox4: TGroupBox
        Left = 245
        Top = 17
        Width = 283
        Height = 82
        Caption = #35774#32622#20018#21475
        Color = clSkyBlue
        ParentBackground = False
        ParentColor = False
        TabOrder = 2
        object LabelPort: TLabel
          Left = 13
          Top = 56
          Width = 24
          Height = 13
          Caption = '------'
        end
        object Button92: TButton
          Left = 13
          Top = 21
          Width = 86
          Height = 29
          Cursor = crHandPoint
          Caption = #35774#32622#20018#21475
          TabOrder = 0
          OnClick = Button92Click
        end
        object Button101: TButton
          Left = 105
          Top = 22
          Width = 75
          Height = 29
          Cursor = crHandPoint
          Caption = #25171#24320#20018#21475
          TabOrder = 1
          OnClick = Button101Click
        end
        object Button102: TButton
          Left = 186
          Top = 23
          Width = 80
          Height = 29
          Cursor = crHandPoint
          Caption = #20851#38381#20018#21475
          TabOrder = 2
          OnClick = Button102Click
        end
      end
      object GroupBox5: TGroupBox
        Left = 6
        Top = 405
        Width = 519
        Height = 66
        Caption = #39537#21160#23433#35013
        Color = clCream
        ParentBackground = False
        ParentColor = False
        TabOrder = 3
        object Button6: TButton
          Left = 14
          Top = 21
          Width = 108
          Height = 29
          Cursor = crHandPoint
          Caption = #26597#30475'Windows'#29256#26412
          TabOrder = 0
          OnClick = Button6Click
        end
        object Button7: TButton
          Left = 153
          Top = 21
          Width = 124
          Height = 29
          Cursor = crHandPoint
          Caption = #23433#35013'USB'#39537#21160#35828#26126
          TabOrder = 1
          OnClick = Button7Click
        end
        object Button10: TButton
          Left = 306
          Top = 21
          Width = 124
          Height = 29
          Cursor = crHandPoint
          Caption = #25171#24320#39537#21160#25991#20214#22841
          TabOrder = 2
          OnClick = Button10Click
        end
      end
      object Button9: TButton
        Left = 128
        Top = 483
        Width = 108
        Height = 31
        Caption = #26522#20030' HID '#35774#22791
        TabOrder = 4
        OnClick = Button9Click
      end
      object ButtonSetClock: TButton
        Left = 26
        Top = 483
        Width = 67
        Height = 31
        Caption = #21516#27493#26102#38047
        TabOrder = 5
        OnClick = ButtonSetClockClick
      end
      object ButtonInitBaseParam: TButton
        Left = 381
        Top = 483
        Width = 141
        Height = 31
        Caption = #24674#22797#22522#26412#21442#25968#21040#20986#21378#20540
        TabOrder = 6
        OnClick = ButtonInitBaseParamClick
      end
    end
    object TabSheet1: TTabSheet
      Caption = '   '#22266#20214#21319#32423'   '
      ImageIndex = 1
      object GroupBox6: TGroupBox
        Left = 8
        Top = 241
        Width = 517
        Height = 214
        Caption = 'H7-TOOL EMMC'#25991#20214#31649#29702
        Color = 13161200
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object Shape1: TShape
          Left = 17
          Top = 61
          Width = 489
          Height = 3
          Pen.Color = clSilver
        end
        object Shape2: TShape
          Left = 16
          Top = 126
          Width = 490
          Height = 3
          Pen.Color = clSilver
        end
        object Label19: TLabel
          Left = 17
          Top = 177
          Width = 293
          Height = 13
          Caption = 'H7-TOOL '#30340' USB '#30913#30424#21367#26631#24517#39035#26159' EMMC '#25165#20250#34987#33258#21160#35782#21035'  '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label20: TLabel
          Left = 13
          Top = 195
          Width = 308
          Height = 13
          Caption = #36827#20837'EMMC'#30913#30424#27169#24335#21518#65292#24517#39035#22312'H7-TOOL'#19978#38271#25353'C'#38190#25165#33021#36864#20986
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Button19: TButton
          Left = 16
          Top = 21
          Width = 137
          Height = 29
          Caption = #36827#20837'U'#30424#27169#24335
          TabOrder = 0
          OnClick = Button19Click
        end
        object Button11: TButton
          Left = 200
          Top = 142
          Width = 175
          Height = 29
          Caption = #27983#35272' H7-TOOL '#30340' EMMC '#30913#30424
          TabOrder = 1
          OnClick = Button11Click
        end
        object ButtonBackup: TButton
          Left = 183
          Top = 21
          Width = 174
          Height = 29
          Caption = #24320#22987#22791#20221#65288'H7-TOOL --> PC'#65289
          TabOrder = 2
          OnClick = ButtonBackupClick
        end
        object ButtonOpenBakupFolder: TButton
          Left = 386
          Top = 20
          Width = 120
          Height = 29
          Caption = #27983#35272#22791#20221#25991#20214#22841
          TabOrder = 3
          OnClick = ButtonOpenBakupFolderClick
        end
        object CheckBoxDelNoModif: TCheckBox
          Left = 206
          Top = 98
          Width = 275
          Height = 17
          Caption = #24378#21046#35206#30422#26410#26356#26032#30340#25991#20214#65288#20462#25913#26102#38388#30456#21516#30340#25991#20214#65289
          TabOrder = 4
        end
        object CheckBoxDelSync: TCheckBox
          Left = 206
          Top = 75
          Width = 267
          Height = 17
          Caption = #38236#20687#27169#24335#65288#20250#21024#38500'PC'#26426#19978#24050#32463#19981#23384#22312#30340#25991#20214#65289
          TabOrder = 5
        end
        object ButtonUpdate: TButton
          Left = 16
          Top = 78
          Width = 174
          Height = 29
          Caption = #24320#22987#26356#26032#65288'PC --> H7-TOOL'#65289
          TabOrder = 6
          OnClick = ButtonUpdateClick
        end
        object Button13: TButton
          Left = 15
          Top = 142
          Width = 175
          Height = 29
          Caption = #27983#35272' PC '#26426#19978#30340' EMMC '#25991#20214#22841
          TabOrder = 7
          OnClick = Button13Click
        end
        object ButtonQuiEmmc: TButton
          Left = 386
          Top = 148
          Width = 122
          Height = 57
          Caption = #36864#20986'U'#30424#27169#24335
          TabOrder = 8
          Visible = False
          OnClick = ButtonQuiEmmcClick
        end
      end
      object GroupBox2: TGroupBox
        Left = 8
        Top = 15
        Width = 517
        Height = 116
        Caption = #21319#32423' APP '#22266#20214#65288#20165#38480'USB'#36890#20449#25509#21475#65289
        Color = clMoneyGreen
        ParentBackground = False
        ParentColor = False
        TabOrder = 1
        object LabelUpgrade: TLabel
          Left = 15
          Top = 90
          Width = 144
          Height = 13
          Caption = '------------------------------------'
        end
        object LabelUPDTime: TLabel
          Left = 187
          Top = 90
          Width = 28
          Height = 13
          Caption = '-------'
        end
        object Label3: TLabel
          Left = 16
          Top = 54
          Width = 420
          Height = 13
          Caption = #22914#26524#25191#34892' "2.'#36827#20837'BOOT" '#22833#36133#65292#21487#20197#25163#21160#36827#20837' BOOT'#12290#26041#27861#65306#25353#20303'S'#38190#20877#25554#19978'USB'#32447
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label18: TLabel
          Left = 12
          Top = 73
          Width = 372
          Height = 13
          Caption = #36827#20837' BOOT '#21518#65292#31561' PC '#30028#38754#24038#19979#35282' USB '#28783#28857#20142#21518#21518#65292#20877#25191#34892'"3.'#24320#22987#26356#26032'"'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Button103: TButton
          Left = 408
          Top = 18
          Width = 99
          Height = 29
          Caption = '3.'#24320#22987#26356#26032
          TabOrder = 0
          OnClick = Button103Click
        end
        object Button104: TButton
          Left = 281
          Top = 19
          Width = 99
          Height = 29
          Caption = '2.'#36827#20837'BOOT'
          TabOrder = 1
          OnClick = Button104Click
        end
        object Button105: TButton
          Left = 152
          Top = 19
          Width = 97
          Height = 29
          Caption = '1.'#25171#24320#25991#20214
          TabOrder = 2
          OnClick = Button105Click
        end
        object Button106: TButton
          Left = 408
          Top = 73
          Width = 97
          Height = 29
          Caption = #22797#20301' H7-TOOL'
          TabOrder = 3
          OnClick = Button106Click
        end
        object Button15: TButton
          Left = 15
          Top = 19
          Width = 99
          Height = 29
          Caption = #26816#26597' APP '#29256#26412
          TabOrder = 4
          OnClick = Button15Click
        end
      end
      object EditCmd: TEdit
        Left = 7
        Top = 469
        Width = 518
        Height = 21
        TabOrder = 2
        Text = 'ver'
      end
      object Button16: TButton
        Left = 8
        Top = 498
        Width = 139
        Height = 30
        Caption = #25191#34892' Windows cmd '#25351#20196
        TabOrder = 3
        OnClick = Button16Click
      end
      object GroupBox7: TGroupBox
        Left = 8
        Top = 147
        Width = 517
        Height = 78
        Caption = #21319#32423' BOOT '#22266#20214
        Color = 15659945
        ParentBackground = False
        ParentColor = False
        TabOrder = 4
        object Label22: TLabel
          Left = 15
          Top = 54
          Width = 373
          Height = 13
          Caption = #24517#39035#20808#21319#32423#21040#26368#26032#30340' APP '#22266#20214#65292#24182#26356#26032'EMMC'#30913#30424#25991#20214#21518#25165#33021#26356#26032' BOOT'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Button18: TButton
          Left = 14
          Top = 19
          Width = 99
          Height = 29
          Caption = #26816#26597' BOOT '#29256#26412
          TabOrder = 0
          OnClick = Button18Click
        end
        object Button14: TButton
          Left = 152
          Top = 19
          Width = 98
          Height = 29
          Caption = #26356#26032' BOOT'
          TabOrder = 1
          OnClick = Button14Click
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = '  '#25130' '#23631'  '
      ImageIndex = 2
      object Label13: TLabel
        Left = 34
        Top = 440
        Width = 162
        Height = 13
        Caption = '1'#12289#25512#33616#22312#20197#22826#32593#38142#25509#27169#24335#20351#29992
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label21: TLabel
        Left = 34
        Top = 459
        Width = 361
        Height = 13
        Caption = '2'#12289'USB'#27169#24335#24320#21551#33258#21160#21047#23631#21518#65292#21516#26102#25805#20316#23631#24149#25353#38190#65292#20250#20986#29616#19981#31283#23450#29616#35937
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label23: TLabel
        Left = 34
        Top = 478
        Width = 309
        Height = 13
        Caption = '3'#12289#36827#20837'USB'#34394#25311#20018#21475#30028#38754#21644'DAP'#20223#30495#22120#30028#38754#21518#65292#25511#21046#20250#22833#25928
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label24: TLabel
        Left = 34
        Top = 421
        Width = 174
        Height = 13
        Caption = '0'#12289#35813#21151#33021#20027#35201#29992#20110#25130#23631#32534#20889#25945#31243
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object ButtonScreShot: TButton
        Left = 305
        Top = 55
        Width = 97
        Height = 32
        Caption = #21047#23631#19968#27425
        TabOrder = 0
        OnClick = ButtonScreShotClick
      end
      object Button17: TButton
        Left = 104
        Top = 294
        Width = 75
        Height = 43
        Caption = 'S '#38190
        TabOrder = 1
        OnMouseDown = Button17MouseDown
        OnMouseUp = Button17MouseUp
      end
      object Button20: TButton
        Left = 104
        Top = 343
        Width = 75
        Height = 40
        Caption = 'C '#38190
        TabOrder = 2
        OnMouseDown = Button20MouseDown
        OnMouseUp = Button20MouseUp
      end
      object Panel1: TPanel
        Left = 24
        Top = 31
        Width = 259
        Height = 257
        BevelOuter = bvLowered
        Color = clBlue
        ParentBackground = False
        TabOrder = 3
        object Image1: TImage
          Left = 10
          Top = 8
          Width = 240
          Height = 240
          Picture.Data = {
            0954506E67496D61676589504E470D0A1A0A0000000D49484452000000800000
            008008020000004C5CF69C000000097048597300000B1300000B1301009A9C18
            000008084944415478DAED9C5D68145714C7275F9B4F9BDD986814A416410C15
            9380D028888AB41804DB80602D94EA53F5497DAA7D529FAC4FEA53ED93D2172D
            08B182C45AAC11C12A0846B12458C48025C6C6EC6E62924D76B3A6FF386519EF
            BD33736713E7EC64CEFF41E2657776E6FCCE3DF7DC7BCF9D22E3E7418345A722
            06402B06402C06402C06402C06402C06402C06402C06402C06402C06402C0640
            2C06402C06402C06402C06402C06402C06402C06402C06402C06402C06402C06
            402C06402C06402C06402C4A00D148514BACCCDA32999DB9FB2AE3FAC5B6FAB2
            8A92226B4B4F22934CCF585BD6D496365614E777637DA3D383A937FE188112C0
            96A5919B9FC5AC2DFD63D98F3A5FB97EF15947FDCA9A126BCBD6EB89EE97696B
            CBB98D1FEC5D5599DF8DEDBB337AFE69CA1F2330008518808B18C0FCA86001B4
            DF485C1B48E7F75DAF5AB000BE5851DE5257E67AA9F262E3C8DA6A6B0BAE83AB
            F96684050B4053879AAA4EAD5F646D69BD3ADC139FF6CD08A106D05859DCBBB3
            1ED970AEE5F2F3A98EEEA49F46083500F83E7A80B5C567F737C20CA0A5AEF4C1
            8EC5D616FFDDDF083380AE6DB1EDCB23B9FF62128E9FF66D029C5348012047EA
            DC12B5B69CEE9D387CFFB5FF46282C0079AF05790580E0831064FD5D12F7370A
            0D40DEF204A070DCDF082700C1FD21B83FA21F8911420700032F865F6B0B82DE
            86AE389511420700C10721C8DA72E0DEE8D9273E2DBDC92A2C00C9F4CC99BE09
            D72F1E5C53659DBE1ADA00E4DC1FC3EFB24B43C2668E9F2A2C00EF3B0D959748
            2FF64FEEB93D42650123540090B9BED8D520741D3F579E950A110039FB44E28F
            F843F5F8A64204E0C2A6DA2F5756585B08D3FF9CC20200F127B1BB41983F7774
            272F3F9FA27A7C53610100DF470F101A63BFFC4B98FF980A0B801F3FF960FFEA
            77F29FBE91E9A62BC354CF9E535800C8CB0FE79FA6F6DD19A57AF69C420100A9
            6762F712A19176029C53280028D73CFCDF7D542A14008E35D71C5DF74EED09C6
            5E8CC0540F6E1525001851581848A6DF203777FDE2A1A6AA68E49DC25B047487
            F564B9466830952D84F86370793AB91800B11800B11800B11800B11800B11800
            B11800B11800B11800B16C01CCE59CAD55775F6526B35A9B1EDB9747DA1A66CB
            953FAC2E5E595372EBE56C9168FF58F6DAC0D47C556D462345DB9797E3D1F077
            736CF6DF8789D9F5B89E78C6EBD6986C1FCDC25641B600E672C8CD2AD7AABF2D
            4B23079BAA607D61BFD0AA9EF8F499BE89B99C5CDCBFBAF29B55956DF5B6A7C6
            60BE6B03E9938FC7358D28DB47732551102500B8F9A9F58B843A350701C3817B
            A35EBD0CD73FD15A637ABD8E2EF64F1EBEFFDAB5CF051E005CFEC2A6A850A5E3
            2AF8E9817BAFF5BB024C2F1C82D4116EB8E356D279B720D80070655C3FEF6B7E
            FF60EC87C7E3CE9F4140C34F087528FA4AA667F6DC4E3AD46C0518C0BCD4E4BA
            5694C807F0BC0A0C5AAF0EDBC5CFF70EC041335F2F155AF4CFF623EE3FD8B158
            1979BA5FA67F1B48DF1DCA98511E03665B43D9E72BCA9523A7B3751C7AD8E9DE
            09643E3D890C224C6365714BAC14A9975CED6B0A77B2F57A4299C50515805C1D
            9EB38BB2480D9104BE2C549498B23BD408B33EEBA897732A30DB776744D96FE0
            169D9BA342D984F3A30512805C1D6ECAB540413ECF6E6AD9A521395D517ED875
            5C05B00B9B6A65E7C057D0D5E4CF071280D2FD354FE7CA853D86AADFC08E707F
            7402E1933A5588765D4759411D3C00CAEA4C43BB3C44AE6D563EB37284B7F362
            5972019D61131E83074069414F87D35FEC6A905D5BC8B294C98F7E11AE32482A
            F9050F80D2347B6E8F60E6A9F9BBCACC58B8823252792AC2958B8E9457081E00
            4406C407A17143575C7F6941AEAF32A449997C6F5E4F6128EF539ECD040FC09F
            ED757246AF4C63ECA4CCEE8F3F1A3FF670CCFC1B034CEA2BB106D4EB2954653F
            931D257800E4AEEDB53E5039C05A8B9C717DFC8AC30774A4EC673AAF442B7400
            F2103A2F00AC29CA9ADAD2DE9DE210CA00FE97E6E0E620E529176B0852F600AF
            21489989CAB972F0002807374F35E247D6569F68AD111A8559F4DC0761E13D42
            A616C220AC9C067B3A26A7F44D213824762F9197D53CF533043161F746192A83
            0740B944E3E9A0A89CE34F66619A21EB6AE51C312B572394B3C5E001504E32F5
            DF94A49C48CBEFF854629EE352045C443EB5103C0086CD5A826627504E7165D3
            28132143AF13D82DD6365D19EE1B1107AA400250BA273A01BEEEBC20A1DCDA45
            BFC103CBBB25CA2804EBB4FF9194ED9813460E0CBFF254D16EB52A9000ECD68A
            0DFB7E00BB9CDB58ABDCC3514606C3DE911D3664F095CECD51394B36ECF3B440
            02306C42B9293CE7AFFF4C750FA67B1299C6CA9296586973AC140FA904E6B059
            68386E08E33E67B724E3D3183FE0EF307D73AC6CEFAA0A655592759221480680
            1EE9FAE61BB94CCD6F0086CD54D393F0A8704C87A11BD6ECDA1695A71D9EE4BC
            549E5FD1823C9F200090F7DD9B4224D9FA7BDC75FA86D875F3D33AE536AF8EE0
            AAED37120EB3876003306CA6B5AE721D4BADB2DBE675157C1FC1C4B9A435F000
            8CB7C57108D69A458330C7D927A9E38FC6BCBEDF0483C1D175359A2578086BF8
            099D23C40B0180293CC6B7AB9DCA66DF1648A74FFE359EF7AB3D61FDEF3EAE46
            5770808D98F6D3DF13E79F4E6AD6725302781FB2168EE7F4B662796A1EDFE880
            4413188453F683A92C620EC97B8B8DC201105A31006231006231006231006231
            0062310062310062310062310062310062310062310062310062310062310062
            3100623100623100623100623100623100623100623100623100623100623100
            62310062310062310062FD078AD443EAF58F56990000000049454E44AE426082}
        end
      end
      object CheckBoxScreen: TCheckBox
        Left = 305
        Top = 32
        Width = 176
        Height = 17
        Caption = #23450#26102#21047#23631#65288#20250#20851#38381#30417#25511#25195#25551#65289
        TabOrder = 4
        OnClick = CheckBoxScreenClick
      end
      object Button21: TButton
        Left = 305
        Top = 160
        Width = 97
        Height = 32
        Caption = #20445#23384#21040#25991#20214
        TabOrder = 5
        OnClick = Button21Click
      end
      object Button12: TButton
        Left = 305
        Top = 214
        Width = 97
        Height = 32
        Caption = #27983#35272#25991#20214#22841
        TabOrder = 6
        OnClick = Button12Click
      end
      object Button22: TButton
        Left = 305
        Top = 111
        Width = 97
        Height = 32
        Caption = #22797#21046#25645#37197#21098#20999#26495
        TabOrder = 7
        OnClick = Button22Click
      end
      object Button23: TButton
        Left = 305
        Top = 272
        Width = 75
        Height = 25
        Caption = 'Button23'
        TabOrder = 8
        Visible = False
        OnClick = Button23Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 447
    Top = 575
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 300
    OnTimer = Timer1Timer
    Left = 492
    Top = 250
  end
end
