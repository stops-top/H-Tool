object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'H7-TOOL'#22810#21151#33021#24320#21457#24037#20855
  ClientHeight = 645
  ClientWidth = 1152
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  DesignSize = (
    1152
    645)
  PixelsPerInch = 96
  TextHeight = 13
  object Panel8: TPanel
    Left = 0
    Top = 0
    Width = 75
    Height = 625
    Align = alLeft
    Color = clCream
    ParentBackground = False
    TabOrder = 1
    object Button86: TButton
      Left = 1
      Top = 3
      Width = 70
      Height = 34
      Caption = #31034#27874#22120
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button86Click
    end
    object Button108: TButton
      Left = 1
      Top = 83
      Width = 70
      Height = 34
      Caption = #24635#32447#25511#21046#22120
      TabOrder = 1
      OnClick = Button108Click
    end
    object Button109: TButton
      Left = 1
      Top = 43
      Width = 70
      Height = 34
      Caption = 'lua'#23567#31243#24207
      TabOrder = 2
      OnClick = Button109Click
    end
    object Button64: TButton
      Left = 1
      Top = 123
      Width = 70
      Height = 35
      Caption = #33073#26426#28903#24405
      TabOrder = 3
      OnClick = Button64Click
    end
    object Button9: TButton
      Left = 0
      Top = 220
      Width = 70
      Height = 35
      Caption = #31995#32479#35774#32622
      TabOrder = 4
      OnClick = Button9Click
    end
    object Button1: TButton
      Left = 1
      Top = 396
      Width = 70
      Height = 25
      Caption = #21551#21160#36319#36394
      TabOrder = 5
      Visible = False
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 1
      Top = 301
      Width = 70
      Height = 25
      Caption = 'Lua'#21161#25163
      TabOrder = 6
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 2
      Top = 427
      Width = 69
      Height = 25
      Caption = #26522#20030#20018#21475
      TabOrder = 7
      Visible = False
      OnClick = Button3Click
    end
    object Button8: TButton
      Left = 1
      Top = 164
      Width = 70
      Height = 35
      Caption = 'RTT Viewer'
      TabOrder = 8
      Visible = False
      OnClick = Button8Click
    end
    object ButtonCheckHttp: TButton
      Left = 1
      Top = 458
      Width = 69
      Height = 25
      Caption = #26816#32034#32593#39029
      TabOrder = 9
      Visible = False
      OnClick = ButtonCheckHttpClick
    end
    object Button10: TButton
      Left = 2
      Top = 489
      Width = 69
      Height = 25
      Caption = #24377#20986'U'#30424
      TabOrder = 10
      Visible = False
    end
  end
  object PanelLua: TPanel
    Left = 149
    Top = 0
    Width = 1077
    Height = 626
    DoubleBuffered = True
    ParentBackground = False
    ParentDoubleBuffered = False
    TabOrder = 0
    Visible = False
    object Splitter3: TSplitter
      Left = 567
      Top = 1
      Width = 10
      Height = 624
    end
    object PanelMemo: TPanel
      Left = 577
      Top = 1
      Width = 499
      Height = 624
      Align = alClient
      Caption = 'PanelMemoOut'
      TabOrder = 0
      DesignSize = (
        499
        624)
      object Button27: TButton
        Left = 6
        Top = 10
        Width = 73
        Height = 31
        Caption = #28165#23631
        TabOrder = 0
        OnClick = Button27Click
      end
      object CheckBoxUDP777: TCheckBox
        Left = 104
        Top = 4
        Width = 141
        Height = 17
        Caption = #25171#24320' UDP '#30417#21548#31471#21475'777'
        TabOrder = 1
        OnClick = CheckBoxUDP777Click
      end
      object CheckBoxLuaWordWrap: TCheckBox
        Left = 104
        Top = 24
        Width = 128
        Height = 17
        Caption = #25171#21360#25991#26412#33258#21160#25442#34892
        Checked = True
        State = cbChecked
        TabOrder = 2
        OnClick = CheckBoxLuaWordWrapClick
      end
      object MemoLuaOut: TMemo
        Left = 6
        Top = 47
        Width = 490
        Height = 572
        Anchors = [akLeft, akTop, akRight, akBottom]
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 3
      end
      object CheckBoxClear: TCheckBox
        Left = 251
        Top = 27
        Width = 86
        Height = 17
        Caption = #25191#34892#21069#28165#23631
        Checked = True
        State = cbChecked
        TabOrder = 4
      end
    end
    object PanelStation: TPanel
      Left = 1
      Top = 1
      Width = 566
      Height = 624
      Align = alLeft
      Color = clCream
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Microsoft YaHei UI Light'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 1
      OnResize = PanelStationResize
    end
  end
  object PanelDSO: TPanel
    Left = 181
    Top = 8
    Width = 1117
    Height = 601
    Color = clCream
    ParentBackground = False
    TabOrder = 2
    DesignSize = (
      1117
      601)
    object Label28: TLabel
      Left = 870
      Top = 18
      Width = 20
      Height = 13
      Anchors = [akTop, akRight]
      Caption = 'CH1'
    end
    object Label27: TLabel
      Left = 896
      Top = 18
      Width = 20
      Height = 13
      Anchors = [akTop, akRight]
      Caption = 'CH2'
    end
    object Panel3: TPanel
      Left = 7
      Top = 6
      Width = 117
      Height = 366
      Anchors = [akLeft, akTop, akBottom]
      BevelOuter = bvNone
      Color = clMoneyGreen
      ParentBackground = False
      TabOrder = 0
      object Label18: TLabel
        Left = 10
        Top = 58
        Width = 44
        Height = 13
        Caption = 'CH2'#30005#21387
      end
      object Label20: TLabel
        Left = 8
        Top = 104
        Width = 48
        Height = 13
        Caption = #36127#36733#30005#21387
      end
      object Label21: TLabel
        Left = 7
        Top = 148
        Width = 48
        Height = 13
        Caption = #36127#36733#30005#27969
      end
      object Label33: TLabel
        Left = 8
        Top = 192
        Width = 50
        Height = 13
        Caption = 'TVCC'#30005#21387
      end
      object Label32: TLabel
        Left = 8
        Top = 236
        Width = 50
        Height = 13
        Caption = 'TVCC'#30005#27969
      end
      object LabelCH1_Adc: TLabel
        Left = 63
        Top = 14
        Width = 18
        Height = 13
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelCH1_Volt: TLabel
        Left = 10
        Top = 33
        Width = 27
        Height = 19
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelCH2_Volt: TLabel
        Left = 10
        Top = 79
        Width = 27
        Height = 19
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelCH2_Adc: TLabel
        Left = 60
        Top = 58
        Width = 18
        Height = 13
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelLoad_Volt: TLabel
        Left = 10
        Top = 123
        Width = 27
        Height = 19
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelLoad_Volt_Adc: TLabel
        Left = 60
        Top = 103
        Width = 18
        Height = 13
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelLoad_Curr: TLabel
        Left = 10
        Top = 167
        Width = 27
        Height = 19
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelLoad_Curr_Adc: TLabel
        Left = 61
        Top = 148
        Width = 18
        Height = 13
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelTVCC_Volt: TLabel
        Left = 8
        Top = 211
        Width = 27
        Height = 19
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelTVCC_Volt_Adc: TLabel
        Left = 64
        Top = 192
        Width = 18
        Height = 13
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelTVCC_Curr: TLabel
        Left = 7
        Top = 251
        Width = 27
        Height = 19
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelTVCC_Curr_Adc: TLabel
        Left = 64
        Top = 236
        Width = 18
        Height = 13
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label50: TLabel
        Left = 12
        Top = 276
        Width = 36
        Height = 13
        Caption = #30005#38459#26723
      end
      object LabelNTC_Res: TLabel
        Left = 9
        Top = 291
        Width = 27
        Height = 19
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelNTC_Adc: TLabel
        Left = 66
        Top = 276
        Width = 18
        Height = 13
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelNTC_Temp: TLabel
        Left = 8
        Top = 309
        Width = 27
        Height = 19
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label53: TLabel
        Left = 13
        Top = 14
        Width = 44
        Height = 13
        Caption = 'CH1'#30005#21387
      end
    end
    object Panel2: TPanel
      Left = 131
      Top = 6
      Width = 734
      Height = 65
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 5789784
      ParentBackground = False
      TabOrder = 1
      object Label13: TLabel
        Left = 11
        Top = 14
        Width = 36
        Height = 13
        Caption = #26368#23567#20540
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label14: TLabel
        Left = 162
        Top = 37
        Width = 30
        Height = 19
        Caption = 'CH2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label15: TLabel
        Left = 163
        Top = 15
        Width = 30
        Height = 19
        Caption = 'CH1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelMin1: TLabel
        Left = 55
        Top = 15
        Width = 18
        Height = 13
        Caption = '100'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clAqua
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelMax1: TLabel
        Left = 55
        Top = 31
        Width = 24
        Height = 13
        Caption = '4095'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clAqua
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelCH1Now: TLabel
        Left = 199
        Top = 12
        Width = 60
        Height = 19
        Caption = '10.000V'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clAqua
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelMin2: TLabel
        Left = 114
        Top = 14
        Width = 18
        Height = 13
        Caption = '100'
        Color = clYellow
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object LabelMax2: TLabel
        Left = 114
        Top = 29
        Width = 24
        Height = 13
        Caption = '4095'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelCH2Now: TLabel
        Left = 199
        Top = 37
        Width = 60
        Height = 19
        Caption = '10.000V'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clYellow
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label49: TLabel
        Left = 11
        Top = 29
        Width = 36
        Height = 13
        Caption = #26368#22823#20540
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelT2: TLabel
        Left = 424
        Top = 40
        Width = 21
        Height = 19
        Caption = 'T2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        OnClick = LabelT2Click
      end
      object LabelT2T1Freq: TLabel
        Left = 625
        Top = 39
        Width = 27
        Height = 19
        Caption = '0Hz'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clLime
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelT2T1Diff: TLabel
        Left = 625
        Top = 14
        Width = 25
        Height = 19
        Caption = '0us'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clLime
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label57: TLabel
        Left = 11
        Top = 45
        Width = 36
        Height = 13
        Caption = #24046'    '#20540
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelDiff1: TLabel
        Left = 54
        Top = 46
        Width = 24
        Height = 13
        Caption = '4095'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clAqua
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelDiff2: TLabel
        Left = 114
        Top = 45
        Width = 24
        Height = 13
        Caption = '4095'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label51: TLabel
        Left = 285
        Top = 14
        Width = 42
        Height = 19
        Caption = #9651'CH1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label52: TLabel
        Left = 284
        Top = 38
        Width = 42
        Height = 19
        Caption = #9651'CH2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelCh1Diff: TLabel
        Left = 333
        Top = 14
        Width = 42
        Height = 19
        Caption = '0.00V'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clAqua
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelCh2Diff: TLabel
        Left = 332
        Top = 39
        Width = 42
        Height = 19
        Caption = '0.00V'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clYellow
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelT1: TLabel
        Left = 424
        Top = 15
        Width = 21
        Height = 19
        Caption = 'T1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        OnClick = LabelT1Click
      end
      object Label56: TLabel
        Left = 558
        Top = 14
        Width = 44
        Height = 19
        Caption = 'T2-T1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label58: TLabel
        Left = 565
        Top = 39
        Width = 37
        Height = 19
        Caption = '1/'#9651'T'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelT1Now: TLabel
        Left = 467
        Top = 13
        Width = 41
        Height = 19
        Caption = '0.000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clLime
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelT2Now: TLabel
        Left = 467
        Top = 38
        Width = 41
        Height = 19
        Caption = '0.000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clLime
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
    end
    object Chart1: TChart
      Left = 131
      Top = 77
      Width = 735
      Height = 306
      Cursor = crCross
      AllowPanning = pmHorizontal
      BackWall.Dark3D = False
      Legend.Visible = False
      MarginBottom = 6
      MarginLeft = 5
      MarginRight = 28
      MarginTop = 11
      MarginUnits = muPixels
      ScrollMouseButton = mbLeft
      SubFoot.Cursor = crHandPoint
      Title.Font.Height = -13
      Title.Text.Strings = (
        'TChart')
      Title.Visible = False
      BottomAxis.Automatic = False
      BottomAxis.AutomaticMaximum = False
      BottomAxis.AutomaticMinimum = False
      BottomAxis.Axis.Color = clWhite
      BottomAxis.Axis.Fill.Gradient.MidColor = clWhite
      BottomAxis.Axis.Fill.Gradient.Visible = True
      BottomAxis.Grid.Color = 10197915
      BottomAxis.Grid.Style = psDot
      BottomAxis.Grid.DrawAlways = True
      BottomAxis.LabelsFormat.Font.Color = clWhite
      BottomAxis.Maximum = 13.895347319551820000
      BottomAxis.Minimum = 10.104652680448210000
      BottomAxis.MinorTickCount = 4
      BottomAxis.MinorTickLength = 7
      BottomAxis.MinorTicks.Fill.Gradient.Balance = 55
      BottomAxis.MinorTicks.Fill.Gradient.Direction = gdBottomTop
      BottomAxis.MinorTicks.Fill.Gradient.EndColor = clNavy
      BottomAxis.MinorTicks.Fill.Gradient.MidColor = 16744576
      BottomAxis.MinorTicks.Fill.Gradient.StartColor = 16777088
      BottomAxis.PositionPercent = -1.000000000000000000
      BottomAxis.PositionUnits = muPixels
      BottomAxis.TickLength = 8
      BottomAxis.Ticks.Color = clWhite
      BottomAxis.Title.Caption = '(us)'
      BottomAxis.Title.Position = tpEnd
      BottomAxis.Title.Visible = False
      BottomAxis.Title.Pen.Color = clWhite
      BottomAxis.Title.Transparency = 13
      BottomAxis.Title.Transparent = False
      BottomAxis.TitleSize = 9
      Chart3DPercent = 1
      ClipPoints = False
      DepthTopAxis.Automatic = False
      DepthTopAxis.AutomaticMinimum = False
      Hover.Visible = False
      LeftAxis.Automatic = False
      LeftAxis.AutomaticMaximum = False
      LeftAxis.AutomaticMinimum = False
      LeftAxis.Axis.Color = 16312833
      LeftAxis.ExactDateTime = False
      LeftAxis.Grid.Color = 10197915
      LeftAxis.Grid.Style = psDot
      LeftAxis.LabelsFormat.Font.Color = 16312833
      LeftAxis.LabelsSeparation = 0
      LeftAxis.Maximum = 10.000000000000000000
      LeftAxis.Minimum = 725.593749999999900000
      LeftAxis.Title.Angle = 0
      LeftAxis.Title.Font.Color = 16312833
      LeftAxis.Title.Position = tpEnd
      LeftAxis.Title.Visible = False
      LeftAxis.TitleSize = 7
      Panning.MouseWheel = pmwNone
      RightAxis.Automatic = False
      RightAxis.AutomaticMaximum = False
      RightAxis.AutomaticMinimum = False
      RightAxis.Axis.Color = clYellow
      RightAxis.Grid.Color = clYellow
      RightAxis.Grid.Visible = False
      RightAxis.Grid.ZZero = True
      RightAxis.LabelsFormat.Font.Color = clYellow
      RightAxis.LabelsSeparation = 0
      RightAxis.Maximum = 10.000000000000000000
      RightAxis.Minimum = -10.000000000000000000
      RightAxis.Title.Angle = 0
      RightAxis.Title.Caption = '(V)'
      RightAxis.Title.Font.Color = 8454143
      RightAxis.Title.Position = tpEnd
      RightAxis.Title.Visible = False
      RightAxis.ZPosition = 0.010000000000000000
      Shadow.Color = clWhite
      TopAxis.Automatic = False
      TopAxis.AutomaticMaximum = False
      TopAxis.AutomaticMinimum = False
      TopAxis.Maximum = 89607.700774634040000000
      TopAxis.Minimum = -89607.700774634040000000
      TopAxis.Title.Caption = 'ka'
      TopAxis.Title.Position = tpEnd
      View3D = False
      View3DOptions.HorizOffset = 14
      View3DOptions.Orthogonal = False
      Zoom.Direction = tzdHorizontal
      Zoom.History = True
      Zoom.KeepAspectRatio = True
      Zoom.MouseButton = mbMiddle
      Zoom.MouseWheel = pmwNormal
      BevelOuter = bvNone
      Color = 3225410
      TabOrder = 2
      Anchors = [akLeft, akTop, akRight, akBottom]
      OnMouseDown = Chart1MouseDown
      OnMouseMove = Chart1MouseMove
      DesignSize = (
        735
        306)
      DefaultCanvas = 'TTeeCanvas3D'
      PrintMargins = (
        15
        29
        15
        29)
      ColorPaletteIndex = 0
      object Button7: TButton
        Left = 702
        Top = 283
        Width = 25
        Height = 17
        Anchors = [akRight, akBottom]
        Caption = 'us'
        TabOrder = 0
      end
      object Button34: TButton
        Left = 704
        Top = 4
        Width = 22
        Height = 17
        Anchors = [akTop, akRight]
        Caption = 'V'
        TabOrder = 1
      end
      object Series1: TLineSeries
        Legend.Picture.Data = {
          07544269746D617036030000424D360300000000000036000000280000001000
          0000100000000100180000000000000300000000000000000000000000000000
          0000AD9484AD9C84AD9C84AD947BAD9C84A5947BAD9484B59C8CB59C8CB59C8C
          B59C8CB5A58CBDA594BDA594BDA594BDA594B59C8CAD9C84AD9C84AD9C84AD9C
          84B5A58CAD9C84AD948CB59C94B59C8CB5A58CB59C8CB5A58CB5A58CBDA594BD
          A594AD9484B5947BAD9C84AD9C84B59C8CBDA594B59C8CB59C8CB59C8CB5A58C
          B5A58CBDA594B59C8CB5A58CBDA594BDA594B59C8CAD947BAD9C84B5A58CB59C
          8CAD9484AD9484B59C8CAD9C84AD9C84B59C8CB59C94BDA594B59C8CB5A58CBD
          A594B59C8CAD9C84B59C8CB59C8CB59C8CAD9C84B59C8CBDA594B59C8CAD9C84
          B59C8CB59C8CB59C8CB5A58CB5A58CBDA594B59C8CB59C8CB59C8CB59C8CAD94
          84AD9C84AD9484BDA594B59C8CB59C8CB59C8CAD9C84B59C8CB59C8CB5A58CBD
          A58CAD9C84B5948CB59C8CB59C8CAD9C84B59C8CB5948CB59C8CAD9C84AD9C84
          B59C8CAD9C84AD9C84B59C8CBDA584BDA584AD9484AD9484AD9484B59C8CB59C
          8CAD9484AD9484AD9C84AD9C84B59C8CB59C8CAD9484B59C8CAD9C84AD9C84AD
          9C84AD9C84AD9C84AD9C84B59C8CAD9484B59C8CB59C8CB59C8CB59C8CAD9484
          AD9484B59C8CB59C8CAD9484AD9484AD9484BDA584BDA584B59C8CAD9C84AD9C
          84B59C8CAD9C84B59C8CAD948CB5948CB59C8CAD9C84B59C8CB59C8CB5948CAD
          9C84BDA58CB5A58CB59C8CB59C8CAD9C84B59C8CB59C8CB59C8CB59C8CAD9484
          AD9C84AD9484B59C8CB59C8CB59C8CB59C8CBDA594B5A58CB5A58CB59C8CB59C
          8CB59C8CAD9C84B59C8CB59C94B59C8CAD9C84B59C8CB59C8CB59C8CAD9C84B5
          9C8CBDA594B5A58CB59C8CBDA594B59C94B59C8CAD9C84B59C8CB59C8CAD9484
          AD9484B59C8CB5A58CAD9C84AD947BB59C8CBDA594BDA594B5A58CB59C8CBDA5
          94B5A58CB5A58CB59C8CB59C8CB59C8CBDA594B59C8CAD9C84AD9C84B5947BAD
          9484BDA594BDA594B5A58CB5A58CB59C8CB5A58CB59C8CAD9484B59C8CAD9C84
          B5A58CAD9C84AD9C84AD9C84AD9C84B59C8CBDA594BDA594BDA594BDA594B5A5
          8CB59C8CB59C8CAD9484AD9484AD9484A5947BAD9C84AD947BAD9C84AD9C84AD
          9484}
        ColorEachLine = False
        Marks.DrawEvery = 100
        SeriesColor = 16312833
        Title = 'WaveCH1'
        Brush.BackColor = clDefault
        Dark3D = False
        DrawStyle = dsCurve
        LineHeight = 1
        Pointer.InflateMargins = True
        Pointer.Style = psRectangle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
        Data = {
          00190000006791ED7C83B8884094438B6CAB2B8840E07A14AEDF38884090ED7C
          3F85CE8840CF22DBF91A9E884081C0CAA13DCF8740C54B3789F9FB8640C776BE
          9FA2BD8740C1F5285CD39E874052E3A59B6C9A8740428B6CE7A7FF8740D378E9
          2641FB8740F0D24D62A4D38740298716D96A848740428B6CE7A7FF8740611058
          39B499884078E926314853884045B6F3FD50C18840894160E50CEE8740D122DB
          F91A9E8840894160E50CEE8740B6F3FDD434618740D34D6210983987404C3789
          41F4B98640713D0AD7CF728740}
      end
      object Series2: TLineSeries
        ColorEachLine = False
        DataSource = Series1
        SeriesColor = 392446
        Title = 'WaveCH2'
        VertAxis = aRightAxis
        Brush.BackColor = clDefault
        Dark3D = False
        Pointer.InflateMargins = True
        Pointer.Style = psRectangle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series3: TPointSeries
        ShowInEditor = False
        Active = False
        Depth = 0
        Marks.AutoPosition = False
        Marks.Callout.Length = 8
        Title = 'CursorT1'
        ClickableLine = False
        Pointer.HorizSize = 8
        Pointer.InflateMargins = False
        Pointer.Pen.Visible = False
        Pointer.Style = psCross
        Pointer.VertSize = 8
        Pointer.Visible = False
        XValues.Name = 'X'
        XValues.Order = loNone
        YValues.Name = 'Y'
        YValues.Order = loNone
        Data = {
          00190000000000000040CA8B406666666666648B406666666666648B40666666
          66A6F8894099999999999E8B403333333373E18A406666666626448840333333
          33B3988A406666666626D08C4066666666E6D28A40CCCCCCCC4C6A8C40666666
          6626D08C409999999959E78B40FFFFFFFFFF128C40CCCCCCCC0CB38C40CCCCCC
          CC4C8D8D4066666666E6F58B406666666626678940CCCCCCCCCCB58A40CCCCCC
          CC4C018940FFFFFFFFBFAC8640FFFFFFFF7FF5864032333333F32C8940989999
          99D9328A4098999999595B8740}
      end
      object Series4: TLineSeries
        Active = False
        SeriesColor = clRed
        Title = 'CursorT2'
        Brush.BackColor = clDefault
        ClickableLine = False
        Pointer.InflateMargins = True
        Pointer.Style = psRectangle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series5: TLineSeries
        Active = False
        Title = 'CursorY1'
        Brush.BackColor = clDefault
        Pointer.InflateMargins = True
        Pointer.Style = psRectangle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series6: TLineSeries
        Active = False
        Title = 'CursorY2'
        Brush.BackColor = clDefault
        Pointer.InflateMargins = True
        Pointer.Style = psRectangle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
    object CH1_Offset: TScrollBar
      Left = 873
      Top = 37
      Width = 17
      Height = 345
      Anchors = [akTop, akRight, akBottom]
      Kind = sbVertical
      PageSize = 0
      Position = 50
      TabOrder = 3
      OnChange = CH1_OffsetChange
    end
    object CH2_Offset: TScrollBar
      Left = 899
      Top = 37
      Width = 17
      Height = 345
      Anchors = [akTop, akRight, akBottom]
      Kind = sbVertical
      PageSize = 0
      Position = 50
      TabOrder = 4
      OnChange = CH2_OffsetChange
    end
    object Button20: TButton
      Left = 820
      Top = 388
      Width = 96
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = #27169#25311#37327#26657#20934
      TabOrder = 5
      OnClick = Button20Click
    end
    object Button6: TButton
      Left = 313
      Top = 388
      Width = 69
      Height = 25
      Anchors = [akLeft, akBottom]
      Caption = #21407#22987#22823#23567
      TabOrder = 6
      OnClick = Button6Click
    end
    object Button5: TButton
      Left = 238
      Top = 388
      Width = 72
      Height = 25
      Anchors = [akLeft, akBottom]
      Caption = #39640#24230#33258#36866#24212
      TabOrder = 7
      OnClick = Button5Click
    end
    object Button31: TButton
      Left = 184
      Top = 388
      Width = 51
      Height = 25
      Anchors = [akLeft, akBottom]
      Caption = #39640#24230'-'
      TabOrder = 8
      OnClick = Button31Click
    end
    object Button30: TButton
      Left = 127
      Top = 389
      Width = 51
      Height = 25
      Anchors = [akLeft, akBottom]
      Caption = #39640#24230'+'
      TabOrder = 9
      OnClick = Button30Click
    end
    object CheckBoxAutoReadWave: TCheckBox
      Left = 21
      Top = 397
      Width = 97
      Height = 17
      Anchors = [akLeft, akBottom]
      Caption = #33258#21160#21047#26032#27874#24418
      TabOrder = 10
    end
    object Panel7: TPanel
      Left = 7
      Top = 420
      Width = 402
      Height = 169
      Anchors = [akLeft, akBottom]
      Color = clSkyBlue
      ParentBackground = False
      TabOrder = 11
      object PageControl2: TPageControl
        Left = 7
        Top = 12
        Width = 389
        Height = 150
        ActivePage = TabSheet4
        TabOrder = 0
        object TabSheet4: TTabSheet
          Caption = #26041#27874'/'#27491#24358'/'#19977#35282
          object LabelDacOff: TLabel
            Left = 198
            Top = 43
            Width = 60
            Height = 13
            Caption = #30452#27969#20559#31227#65306
          end
          object LabelDacVpp: TLabel
            Left = 6
            Top = 42
            Width = 62
            Height = 13
            Caption = #24133#24230'(Vpp)'#65306
          end
          object LabelDacState: TLabel
            Left = 15
            Top = 101
            Width = 48
            Height = 13
            Caption = #36755#20986#20851#38381
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlue
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object Label36: TLabel
            Left = 199
            Top = 13
            Width = 56
            Height = 13
            Caption = #39057#29575'(Hz)'#65306
          end
          object Label37: TLabel
            Left = 197
            Top = 67
            Width = 60
            Height = 13
            Caption = #27874#24418#20010#25968#65306
          end
          object Label38: TLabel
            Left = 6
            Top = 13
            Width = 60
            Height = 13
            Caption = #27874#24418#31867#22411#65306
          end
          object Label39: TLabel
            Left = 16
            Top = 70
            Width = 48
            Height = 13
            Caption = #21344#31354#27604#65306
          end
          object ButtonSqrStart: TButton
            Left = 190
            Top = 91
            Width = 91
            Height = 25
            Caption = #24320#22987#36755#20986
            TabOrder = 0
            OnClick = ButtonSqrStartClick
          end
          object ButtonSqrStop: TButton
            Left = 287
            Top = 91
            Width = 91
            Height = 25
            Caption = #20572#27490#36755#20986
            TabOrder = 1
            OnClick = ButtonSqrStopClick
          end
          object ComboBoxDacVpp: TComboBox
            Left = 86
            Top = 39
            Width = 97
            Height = 21
            ItemIndex = 0
            TabOrder = 2
            Text = '10000'
            OnChange = ComboBoxWaveTypeChange
            Items.Strings = (
              '10000'
              '9500'
              '9000'
              '9500'
              '9500'
              '9500'
              '9500'
              '9500')
          end
          object ComboBoxDacOffset: TComboBox
            Left = 286
            Top = 37
            Width = 92
            Height = 21
            TabOrder = 3
            OnChange = ComboBoxWaveTypeChange
          end
          object ComboBoxSqrFreq: TComboBox
            Left = 261
            Top = 10
            Width = 117
            Height = 21
            TabOrder = 4
            Text = '5'
            OnChange = ComboBoxWaveTypeChange
            Items.Strings = (
              '0.1'
              '0.2'
              '0.5'
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
              '25'
              '50'
              '100'
              '125'
              '200'
              '250'
              '500')
          end
          object ComboBoxSqrCount: TComboBox
            Left = 256
            Top = 64
            Width = 122
            Height = 21
            TabOrder = 5
            Text = #26080#38480#65288#24490#29615#36755#20986#65289
            OnChange = ComboBoxWaveTypeChange
            Items.Strings = (
              #26080#38480#65288#24490#29615#36755#20986#65289
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
              '20'
              '30'
              '40'
              '50'
              '60'
              '70'
              '80'
              '90')
          end
          object ComboBoxWaveType: TComboBox
            Left = 86
            Top = 10
            Width = 97
            Height = 21
            ItemIndex = 1
            TabOrder = 6
            Text = '1-'#27491#24358#27874
            OnChange = ComboBoxWaveTypeChange
            Items.Strings = (
              '0-'#26080#27874#24418
              '1-'#27491#24358#27874
              '2-'#26041#27874
              '3-'#19977#35282#27874)
          end
          object ComboBoxDuty: TComboBox
            Left = 86
            Top = 64
            Width = 97
            Height = 21
            ItemIndex = 0
            TabOrder = 7
            Text = '1'
            OnChange = ComboBoxWaveTypeChange
            Items.Strings = (
              '1'
              '2'
              '3'
              '4'
              '5'
              '6'
              '7')
          end
        end
        object TabSheetDC: TTabSheet
          Caption = #30452#27969#30005#21387#65288'mV'#65289
          ExplicitLeft = 0
          ExplicitTop = 0
          ExplicitWidth = 0
          ExplicitHeight = 0
          object Button4: TButton
            Left = 204
            Top = 34
            Width = 38
            Height = 25
            Caption = '-200'
            TabOrder = 0
            OnClick = ButtonDacVoltClick
          end
          object Button21: TButton
            Left = 326
            Top = 34
            Width = 38
            Height = 25
            Caption = '100'
            TabOrder = 1
            OnClick = ButtonDacVoltClick
          end
          object Button42: TButton
            Left = 83
            Top = 34
            Width = 38
            Height = 25
            Caption = '-2000'
            TabOrder = 2
            OnClick = ButtonDacVoltClick
          end
          object Button43: TButton
            Left = 3
            Top = 65
            Width = 38
            Height = 25
            Caption = '200'
            TabOrder = 3
            OnClick = ButtonDacVoltClick
          end
          object Button44: TButton
            Left = 43
            Top = 65
            Width = 38
            Height = 25
            Caption = '500'
            TabOrder = 4
            OnClick = ButtonDacVoltClick
          end
          object Button45: TButton
            Left = 83
            Top = 65
            Width = 38
            Height = 25
            Caption = '1000'
            TabOrder = 5
            OnClick = ButtonDacVoltClick
          end
          object Button46: TButton
            Left = 123
            Top = 65
            Width = 38
            Height = 25
            Caption = '2000'
            TabOrder = 6
            OnClick = ButtonDacVoltClick
          end
          object Button47: TButton
            Left = 163
            Top = 65
            Width = 38
            Height = 25
            Caption = '3000'
            TabOrder = 7
            OnClick = ButtonDacVoltClick
          end
          object Button48: TButton
            Left = 204
            Top = 65
            Width = 38
            Height = 25
            Caption = '4000'
            TabOrder = 8
            OnClick = ButtonDacVoltClick
          end
          object ButtonDCKey: TButton
            Left = 3
            Top = 34
            Width = 38
            Height = 25
            Caption = '-4000'
            TabOrder = 9
            OnClick = ButtonDacVoltClick
          end
          object Button49: TButton
            Left = 164
            Top = 34
            Width = 38
            Height = 25
            Caption = '-500'
            TabOrder = 10
            OnClick = ButtonDacVoltClick
          end
          object Button50: TButton
            Left = 43
            Top = 34
            Width = 38
            Height = 25
            Caption = '-3000'
            TabOrder = 11
            OnClick = ButtonDacVoltClick
          end
          object ProgressBarVolt: TProgressBar
            Left = 389
            Top = 3
            Width = 17
            Height = 131
            Max = 4095
            Orientation = pbVertical
            Smooth = True
            TabOrder = 12
          end
          object Button51: TButton
            Left = 124
            Top = 34
            Width = 38
            Height = 25
            Caption = '-1000'
            TabOrder = 13
            OnClick = ButtonDacVoltClick
          end
          object Button52: TButton
            Left = 245
            Top = 34
            Width = 38
            Height = 25
            Caption = '-100'
            TabOrder = 14
            OnClick = ButtonDacVoltClick
          end
          object Button53: TButton
            Left = 285
            Top = 34
            Width = 38
            Height = 25
            Caption = '0'
            TabOrder = 15
            OnClick = ButtonDacVoltClick
          end
          object Button54: TButton
            Left = 285
            Top = 3
            Width = 38
            Height = 25
            Caption = '-6000'
            TabOrder = 16
            OnClick = ButtonDacVoltClick
          end
          object Button55: TButton
            Left = 245
            Top = 65
            Width = 38
            Height = 25
            Caption = '5000'
            TabOrder = 17
            OnClick = ButtonDacVoltClick
          end
          object ButtonDacVolt: TButton
            Left = 127
            Top = 3
            Width = 38
            Height = 25
            Caption = '-10000'
            TabOrder = 18
            OnClick = ButtonDacVoltClick
          end
          object Button58: TButton
            Left = 245
            Top = 4
            Width = 38
            Height = 25
            Caption = '-7000'
            TabOrder = 19
            OnClick = ButtonDacVoltClick
          end
          object Button59: TButton
            Left = 204
            Top = 3
            Width = 38
            Height = 25
            Caption = '-8000'
            TabOrder = 20
            OnClick = ButtonDacVoltClick
          end
          object Button60: TButton
            Left = 326
            Top = 3
            Width = 38
            Height = 25
            Caption = '-5000'
            TabOrder = 21
            OnClick = ButtonDacVoltClick
          end
          object Button61: TButton
            Left = 285
            Top = 65
            Width = 38
            Height = 25
            Caption = '6000'
            TabOrder = 22
            OnClick = ButtonDacVoltClick
          end
          object Button62: TButton
            Left = 326
            Top = 65
            Width = 38
            Height = 25
            Caption = '7000'
            TabOrder = 23
            OnClick = ButtonDacVoltClick
          end
          object EditDacInput: TEdit
            Left = 2
            Top = 3
            Width = 54
            Height = 22
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 24
            Text = '0'
          end
          object ButtonDACOut: TButton
            Left = 62
            Top = 3
            Width = 42
            Height = 25
            Caption = #36755#20986
            TabOrder = 25
            OnClick = ButtonDACOutClick
          end
          object Button15: TButton
            Left = 164
            Top = 3
            Width = 38
            Height = 25
            Caption = '-9000'
            TabOrder = 26
            OnClick = ButtonDacVoltClick
          end
          object Button16: TButton
            Left = 3
            Top = 94
            Width = 38
            Height = 25
            Caption = '8000'
            TabOrder = 27
            OnClick = ButtonDacVoltClick
          end
          object Button17: TButton
            Left = 43
            Top = 94
            Width = 38
            Height = 25
            Caption = '9000'
            TabOrder = 28
            OnClick = ButtonDacVoltClick
          end
          object Button18: TButton
            Left = 83
            Top = 94
            Width = 38
            Height = 25
            Caption = '10000'
            TabOrder = 29
            OnClick = ButtonDacVoltClick
          end
          object Button19: TButton
            Left = 163
            Top = 93
            Width = 38
            Height = 25
            Caption = '-12000'
            TabOrder = 30
            OnClick = ButtonDacVoltClick
          end
          object Button68: TButton
            Left = 204
            Top = 93
            Width = 38
            Height = 25
            Caption = '-11000'
            TabOrder = 31
            OnClick = ButtonDacVoltClick
          end
          object Button69: TButton
            Left = 245
            Top = 92
            Width = 38
            Height = 25
            Caption = '11000'
            TabOrder = 32
            OnClick = ButtonDacVoltClick
          end
          object Button70: TButton
            Left = 286
            Top = 92
            Width = 38
            Height = 25
            Caption = '12000'
            TabOrder = 33
            OnClick = ButtonDacVoltClick
          end
        end
        object TabSheet5: TTabSheet
          Caption = #30452#27969#30005#27969#65288'uA'#65289
          ImageIndex = 2
          ExplicitLeft = 0
          ExplicitTop = 0
          ExplicitWidth = 0
          ExplicitHeight = 0
          object Button14: TButton
            Left = 212
            Top = 34
            Width = 38
            Height = 25
            Caption = '2000'
            TabOrder = 0
            OnClick = ButtonDacCurrClick
          end
          object Button57: TButton
            Left = 334
            Top = 34
            Width = 38
            Height = 25
            Caption = '5000'
            TabOrder = 1
            OnClick = ButtonDacCurrClick
          end
          object Button71: TButton
            Left = 91
            Top = 34
            Width = 38
            Height = 25
            Caption = '800'
            TabOrder = 2
            OnClick = ButtonDacCurrClick
          end
          object Button72: TButton
            Left = 9
            Top = 65
            Width = 38
            Height = 25
            Caption = '6000'
            TabOrder = 3
            OnClick = ButtonDacCurrClick
          end
          object Button73: TButton
            Left = 51
            Top = 65
            Width = 38
            Height = 25
            Caption = '7000'
            TabOrder = 4
            OnClick = ButtonDacCurrClick
          end
          object Button74: TButton
            Left = 91
            Top = 65
            Width = 38
            Height = 25
            Caption = '8000'
            TabOrder = 5
            OnClick = ButtonDacCurrClick
          end
          object Button75: TButton
            Left = 132
            Top = 65
            Width = 38
            Height = 25
            Caption = '9000'
            TabOrder = 6
            OnClick = ButtonDacCurrClick
          end
          object Button76: TButton
            Left = 172
            Top = 66
            Width = 38
            Height = 25
            Caption = '10000'
            TabOrder = 7
            OnClick = ButtonDacCurrClick
          end
          object Button77: TButton
            Left = 212
            Top = 65
            Width = 38
            Height = 25
            Caption = '11000'
            TabOrder = 8
            OnClick = ButtonDacCurrClick
          end
          object Button78: TButton
            Left = 10
            Top = 33
            Width = 38
            Height = 25
            Caption = '600'
            TabOrder = 9
            OnClick = ButtonDacCurrClick
          end
          object Button79: TButton
            Left = 172
            Top = 34
            Width = 38
            Height = 25
            Caption = '1000'
            TabOrder = 10
            OnClick = ButtonDacCurrClick
          end
          object Button80: TButton
            Left = 51
            Top = 34
            Width = 38
            Height = 25
            Caption = '700'
            TabOrder = 11
            OnClick = ButtonDacCurrClick
          end
          object Button81: TButton
            Left = 132
            Top = 34
            Width = 38
            Height = 25
            Caption = '900'
            TabOrder = 12
            OnClick = ButtonDacCurrClick
          end
          object Button82: TButton
            Left = 253
            Top = 34
            Width = 38
            Height = 25
            Caption = '3000'
            TabOrder = 13
            OnClick = ButtonDacCurrClick
          end
          object Button83: TButton
            Left = 293
            Top = 34
            Width = 38
            Height = 25
            Caption = '4000'
            TabOrder = 14
            OnClick = ButtonDacCurrClick
          end
          object Button84: TButton
            Left = 293
            Top = 3
            Width = 38
            Height = 25
            Caption = '400'
            TabOrder = 15
            OnClick = ButtonDacCurrClick
          end
          object Button85: TButton
            Left = 253
            Top = 65
            Width = 38
            Height = 25
            Caption = '12000'
            TabOrder = 16
            OnClick = ButtonDacCurrClick
          end
          object ButtonDacCurr: TButton
            Left = 131
            Top = 4
            Width = 38
            Height = 25
            Caption = '0'
            TabOrder = 17
            OnClick = ButtonDacCurrClick
          end
          object Button87: TButton
            Left = 253
            Top = 3
            Width = 38
            Height = 25
            Caption = '300'
            TabOrder = 18
            OnClick = ButtonDacCurrClick
          end
          object Button88: TButton
            Left = 212
            Top = 3
            Width = 38
            Height = 25
            Caption = '200'
            TabOrder = 19
            OnClick = ButtonDacCurrClick
          end
          object Button89: TButton
            Left = 334
            Top = 3
            Width = 38
            Height = 25
            Caption = '500'
            TabOrder = 20
            OnClick = ButtonDacCurrClick
          end
          object Button90: TButton
            Left = 293
            Top = 65
            Width = 38
            Height = 25
            Caption = '13000'
            TabOrder = 21
            OnClick = ButtonDacCurrClick
          end
          object Button91: TButton
            Left = 334
            Top = 65
            Width = 38
            Height = 25
            Caption = '14000'
            TabOrder = 22
            OnClick = ButtonDacCurrClick
          end
          object EditDacCurr: TEdit
            Left = 10
            Top = 3
            Width = 54
            Height = 22
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 23
            Text = '0'
          end
          object ButtonDacCurrOut: TButton
            Left = 70
            Top = 3
            Width = 42
            Height = 25
            Caption = #36755#20986
            TabOrder = 24
            OnClick = ButtonDacCurrOutClick
          end
          object Button93: TButton
            Left = 172
            Top = 3
            Width = 38
            Height = 25
            Caption = '100'
            TabOrder = 25
            OnClick = ButtonDacCurrClick
          end
          object Button94: TButton
            Left = 9
            Top = 93
            Width = 38
            Height = 25
            Caption = '15000'
            TabOrder = 26
            OnClick = ButtonDacCurrClick
          end
          object Button95: TButton
            Left = 50
            Top = 93
            Width = 38
            Height = 25
            Caption = '16000'
            TabOrder = 27
            OnClick = ButtonDacCurrClick
          end
          object Button96: TButton
            Left = 91
            Top = 93
            Width = 38
            Height = 25
            Caption = '17000'
            TabOrder = 28
            OnClick = ButtonDacCurrClick
          end
          object Button97: TButton
            Left = 132
            Top = 93
            Width = 38
            Height = 25
            Caption = '18000'
            TabOrder = 29
            OnClick = ButtonDacCurrClick
          end
          object Button98: TButton
            Left = 172
            Top = 93
            Width = 38
            Height = 25
            Caption = '19000'
            TabOrder = 30
            OnClick = ButtonDacCurrClick
          end
          object Button99: TButton
            Left = 212
            Top = 93
            Width = 38
            Height = 25
            Caption = '20000'
            TabOrder = 31
            OnClick = ButtonDacCurrClick
          end
          object Button100: TButton
            Left = 336
            Top = 93
            Width = 38
            Height = 25
            Caption = '21000'
            TabOrder = 32
            OnClick = ButtonDacCurrClick
          end
        end
      end
    end
    object Panel6: TPanel
      Left = 415
      Top = 420
      Width = 126
      Height = 169
      Anchors = [akLeft, akBottom]
      Color = clSilver
      ParentBackground = False
      TabOrder = 12
      object Label24: TLabel
        Left = 9
        Top = 8
        Width = 60
        Height = 13
        Caption = #27979#37327#27169#24335#65306
      end
      object Label25: TLabel
        Left = 8
        Top = 62
        Width = 60
        Height = 13
        Caption = #30005#27969#37327#31243#65306
      end
      object Label31: TLabel
        Left = 6
        Top = 113
        Width = 116
        Height = 13
        Caption = 'TVCC'#36755#20986#30005#21387#65288'V'#65289#65306
      end
      object ComboBoxDSO_Mode: TComboBox
        Left = 6
        Top = 27
        Width = 89
        Height = 21
        ItemIndex = 0
        TabOrder = 0
        Text = #31034#27874#22120
        OnChange = ComboBoxDSO_ModeChange
        Items.Strings = (
          #31034#27874#22120
          #39640#20391#30005#27969
          #20302#36895#22810#36890#36947)
      end
      object ComboBoxCurrGain: TComboBox
        Left = 5
        Top = 79
        Width = 89
        Height = 21
        ItemIndex = 0
        TabOrder = 1
        Text = '120mA'
        OnChange = ComboBoxCurrGainChange
        Items.Strings = (
          '120mA'
          '1.2A')
      end
      object ComboBoxTVCC: TComboBox
        Left = 8
        Top = 132
        Width = 49
        Height = 21
        ItemIndex = 7
        TabOrder = 2
        Text = '3.3'
        OnSelect = ComboBoxTVCCSelect
        Items.Strings = (
          '0'
          '1.2'
          '1.5'
          '1.8'
          '2.5'
          '2.8'
          '3.0'
          '3.3'
          '3.6'
          '3.9'
          '4.2'
          '4.5'
          '4.8'
          '5.0')
      end
    end
    object Panel4: TPanel
      Left = 547
      Top = 419
      Width = 323
      Height = 169
      Anchors = [akLeft, akBottom]
      Color = 11192063
      ParentBackground = False
      TabOrder = 13
      object ShapeX7: TShape
        Left = 113
        Top = 50
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeX6: TShape
        Left = 138
        Top = 50
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeX5: TShape
        Left = 162
        Top = 50
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeX4: TShape
        Left = 187
        Top = 50
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeX3: TShape
        Left = 212
        Top = 50
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeX2: TShape
        Left = 236
        Top = 50
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeX1: TShape
        Left = 261
        Top = 50
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeX0: TShape
        Left = 286
        Top = 50
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object Label34: TLabel
        Left = 123
        Top = 33
        Width = 13
        Height = 13
        Caption = 'D7'
      end
      object Label35: TLabel
        Left = 148
        Top = 33
        Width = 13
        Height = 13
        Caption = 'D6'
      end
      object Label40: TLabel
        Left = 197
        Top = 33
        Width = 13
        Height = 13
        Caption = 'D4'
      end
      object Label41: TLabel
        Left = 221
        Top = 33
        Width = 13
        Height = 13
        Caption = 'D3'
      end
      object Label42: TLabel
        Left = 246
        Top = 33
        Width = 13
        Height = 13
        Caption = 'D2'
      end
      object Label43: TLabel
        Left = 267
        Top = 33
        Width = 13
        Height = 13
        Caption = 'D1'
      end
      object Label44: TLabel
        Left = 291
        Top = 33
        Width = 13
        Height = 13
        Caption = 'D0'
      end
      object Label45: TLabel
        Left = 173
        Top = 33
        Width = 13
        Height = 13
        Caption = 'D5'
      end
      object SpeedButtonY7: TSpeedButton
        Left = 114
        Top = 131
        Width = 23
        Height = 22
        OnClick = SpeedButtonY7Click
      end
      object SpeedButtonY6: TSpeedButton
        Left = 139
        Top = 131
        Width = 23
        Height = 22
        OnClick = SpeedButtonY7Click
      end
      object SpeedButtonY5: TSpeedButton
        Left = 164
        Top = 131
        Width = 23
        Height = 22
        OnClick = SpeedButtonY7Click
      end
      object SpeedButtonY4: TSpeedButton
        Left = 189
        Top = 131
        Width = 23
        Height = 22
        OnClick = SpeedButtonY7Click
      end
      object SpeedButtonY3: TSpeedButton
        Left = 214
        Top = 131
        Width = 23
        Height = 22
        OnClick = SpeedButtonY7Click
      end
      object SpeedButtonY2: TSpeedButton
        Left = 239
        Top = 131
        Width = 23
        Height = 22
        OnClick = SpeedButtonY7Click
      end
      object SpeedButtonY1: TSpeedButton
        Left = 264
        Top = 131
        Width = 23
        Height = 22
        OnClick = SpeedButtonY7Click
      end
      object SpeedButtonY0: TSpeedButton
        Left = 289
        Top = 131
        Width = 23
        Height = 22
        OnClick = SpeedButtonY7Click
      end
      object ShapeY7: TShape
        Left = 113
        Top = 108
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeY6: TShape
        Left = 138
        Top = 108
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeY5: TShape
        Left = 163
        Top = 108
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeY4: TShape
        Left = 187
        Top = 108
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeY3: TShape
        Left = 212
        Top = 108
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeY2: TShape
        Left = 237
        Top = 108
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeY1: TShape
        Left = 262
        Top = 108
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeY0: TShape
        Left = 287
        Top = 108
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeX9: TShape
        Left = 64
        Top = 50
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeX8: TShape
        Left = 88
        Top = 50
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object Label46: TLabel
        Left = 71
        Top = 33
        Width = 13
        Height = 13
        Caption = 'D9'
      end
      object Label47: TLabel
        Left = 96
        Top = 33
        Width = 13
        Height = 13
        Caption = 'D8'
      end
      object SpeedButtonY9: TSpeedButton
        Left = 65
        Top = 131
        Width = 23
        Height = 22
        OnClick = SpeedButtonY7Click
      end
      object SpeedButtonY8: TSpeedButton
        Left = 89
        Top = 131
        Width = 23
        Height = 22
        OnClick = SpeedButtonY7Click
      end
      object ShapeY9: TShape
        Left = 64
        Top = 108
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object ShapeY8: TShape
        Left = 88
        Top = 108
        Width = 26
        Height = 17
        Shape = stCircle
      end
      object Label59: TLabel
        Left = 7
        Top = 9
        Width = 76
        Height = 14
        Caption = 'GPIO'#25511#21046#38754#26495
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label79: TLabel
        Left = 10
        Top = 51
        Width = 48
        Height = 14
        Caption = #23454#26102#29366#24577
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label80: TLabel
        Left = 9
        Top = 80
        Width = 48
        Height = 14
        Caption = #26041#21521#35774#32622
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label81: TLabel
        Left = 9
        Top = 109
        Width = 48
        Height = 14
        Caption = #36755#20986#29366#24577
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label82: TLabel
        Left = 8
        Top = 135
        Width = 48
        Height = 14
        Caption = #25511#21046#25353#38062
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object CheckBoxD7: TCheckBox
        Left = 118
        Top = 78
        Width = 19
        Height = 17
        TabOrder = 0
        OnClick = CheckBoxD7Click
      end
      object CheckBoxD6: TCheckBox
        Left = 143
        Top = 78
        Width = 19
        Height = 17
        TabOrder = 1
        OnClick = CheckBoxD6Click
      end
      object CheckBoxD5: TCheckBox
        Left = 168
        Top = 78
        Width = 19
        Height = 17
        TabOrder = 2
        OnClick = CheckBoxD5Click
      end
      object CheckBoxD4: TCheckBox
        Left = 192
        Top = 78
        Width = 19
        Height = 17
        TabOrder = 3
        OnClick = CheckBoxD4Click
      end
      object CheckBoxD3: TCheckBox
        Left = 217
        Top = 78
        Width = 19
        Height = 17
        TabOrder = 4
        OnClick = CheckBoxD3Click
      end
      object CheckBoxD2: TCheckBox
        Left = 242
        Top = 78
        Width = 19
        Height = 17
        TabOrder = 5
        OnClick = CheckBoxD2Click
      end
      object CheckBoxD1: TCheckBox
        Left = 267
        Top = 78
        Width = 19
        Height = 17
        TabOrder = 6
        OnClick = CheckBoxD1Click
      end
      object CheckBoxD0: TCheckBox
        Left = 292
        Top = 78
        Width = 19
        Height = 17
        TabOrder = 7
        OnClick = CheckBoxD0Click
      end
      object CheckBoxD9: TCheckBox
        Left = 69
        Top = 78
        Width = 19
        Height = 17
        TabOrder = 8
        OnClick = CheckBoxD9Click
      end
      object CheckBoxD8: TCheckBox
        Left = 93
        Top = 78
        Width = 19
        Height = 17
        TabOrder = 9
        OnClick = CheckBoxD8Click
      end
    end
    object TPanel
      Left = 922
      Top = 6
      Width = 185
      Height = 525
      Anchors = [akTop, akRight]
      BevelInner = bvLowered
      TabOrder = 14
      object Label3: TLabel
        Left = 16
        Top = 21
        Width = 88
        Height = 13
        Caption = #37319#26679#39057#29575'(Hz'#65289#65306
      end
      object Label17: TLabel
        Left = 16
        Top = 48
        Width = 60
        Height = 13
        Caption = #37319#26679#28145#24230#65306
      end
      object Label19: TLabel
        Left = 16
        Top = 75
        Width = 60
        Height = 13
        Caption = #35302#21457#36890#36947#65306
      end
      object Label22: TLabel
        Left = 16
        Top = 102
        Width = 60
        Height = 13
        Caption = #35302#21457#27169#24335#65306
      end
      object Label23: TLabel
        Left = 17
        Top = 154
        Width = 60
        Height = 13
        Caption = #35302#21457#30005#21387#65306
      end
      object LabelTrigLevel: TLabel
        Left = 97
        Top = 155
        Width = 30
        Height = 13
        Caption = '32767'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label29: TLabel
        Left = 17
        Top = 194
        Width = 60
        Height = 13
        Caption = #35302#21457#20301#32622#65306
      end
      object LabelTrigPos: TLabel
        Left = 97
        Top = 195
        Width = 12
        Height = 13
        Caption = '50'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label30: TLabel
        Left = 16
        Top = 131
        Width = 60
        Height = 13
        Caption = #35302#21457#36793#27839#65306
      end
      object ComboBoxFreq: TComboBox
        Left = 110
        Top = 18
        Width = 64
        Height = 21
        ItemIndex = 12
        TabOrder = 0
        Text = '1M'
        OnClick = ComboBoxFreqClick
        Items.Strings = (
          '100'
          '200'
          '500'
          '1K'
          '2K'
          '5K'
          '10K'
          '20K'
          '50K'
          '100K'
          '200K'
          '500K'
          '1M'
          '2M'
          '5M')
      end
      object ComboBoxSampleSize: TComboBox
        Left = 110
        Top = 45
        Width = 64
        Height = 21
        ItemIndex = 0
        TabOrder = 1
        Text = '1K'
        OnChange = ComboBoxSampleSizeChange
        Items.Strings = (
          '1K'
          '2K'
          '4K'
          '8K'
          '16K')
      end
      object Button22: TButton
        Left = 6
        Top = 267
        Width = 25
        Height = 25
        Caption = 'AC'
        TabOrder = 2
        OnClick = Button22Click
      end
      object Button23: TButton
        Left = 37
        Top = 267
        Width = 25
        Height = 25
        Caption = 'DC'
        TabOrder = 3
        OnClick = Button23Click
      end
      object Button24: TButton
        Left = 141
        Top = 267
        Width = 25
        Height = 25
        Caption = 'DC'
        TabOrder = 4
        OnClick = Button24Click
      end
      object Button29: TButton
        Left = 110
        Top = 267
        Width = 25
        Height = 25
        Caption = 'AC'
        TabOrder = 5
        OnClick = Button29Click
      end
      object ButtonStartDSO: TButton
        Left = 6
        Top = 236
        Width = 73
        Height = 25
        Caption = #21551#21160#37319#38598
        TabOrder = 6
        OnClick = ButtonStartDSOClick
      end
      object ButtonStopDSO: TButton
        Left = 103
        Top = 236
        Width = 74
        Height = 25
        Caption = #20572#27490#37319#38598
        TabOrder = 7
        OnClick = ButtonStopDSOClick
      end
      object ComboBoxTrigChan: TComboBox
        Left = 110
        Top = 72
        Width = 64
        Height = 21
        ItemIndex = 0
        TabOrder = 8
        Text = 'CH1'
        OnChange = ComboBoxTrigChanChange
        Items.Strings = (
          'CH1'
          'CH2')
      end
      object ComboBoxTrigMode: TComboBox
        Left = 96
        Top = 99
        Width = 78
        Height = 21
        ItemIndex = 0
        TabOrder = 9
        Text = #33258#21160#35302#21457
        OnChange = ComboBoxTrigModeChange
        Items.Strings = (
          #33258#21160#35302#21457
          #26222#36890#35302#21457
          #21333#27425#35302#21457)
      end
      object ScrollBarTrigLevel: TScrollBar
        Left = -4
        Top = 174
        Width = 163
        Height = 16
        Max = 65535
        PageSize = 0
        Position = 32767
        TabOrder = 10
        OnChange = ScrollBarTrigLevelChange
      end
      object CheckBoxEnCH1: TCheckBox
        Left = 13
        Top = 500
        Width = 56
        Height = 17
        Caption = 'CH1'
        Checked = True
        Enabled = False
        State = cbChecked
        TabOrder = 11
      end
      object CheckBoxEnCH2: TCheckBox
        Left = 112
        Top = 502
        Width = 47
        Height = 17
        Caption = 'CH2'
        Checked = True
        State = cbChecked
        TabOrder = 12
      end
      object ScrollBarTrigPos: TScrollBar
        Left = 6
        Top = 214
        Width = 163
        Height = 16
        PageSize = 0
        Position = 50
        TabOrder = 13
        OnChange = ScrollBarTrigPosChange
      end
      object ComboBoxTrigEdge: TComboBox
        Left = 96
        Top = 128
        Width = 78
        Height = 21
        ItemIndex = 0
        TabOrder = 14
        Text = #19979#38477#27839
        OnChange = ComboBoxTrigEdgeChange
        Items.Strings = (
          #19979#38477#27839
          #19978#21319#27839)
      end
      object Radio_CH1Gain: TRadioGroup
        Left = 7
        Top = 300
        Width = 82
        Height = 196
        Caption = 'CH1'#37327#31243
        Color = clAqua
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clAqua
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ItemIndex = 1
        Items.Strings = (
          #177'13.8V'
          #177'6.4V'
          #177'3.2V'
          #177'1.6V'
          #177'800mV'
          #177'400mV'
          #177'200mV'
          #177'100mV')
        ParentBackground = False
        ParentColor = False
        ParentFont = False
        TabOrder = 15
        OnClick = Radio_CH1GainClick
      end
      object Radio_CH2Gain: TRadioGroup
        Left = 95
        Top = 300
        Width = 83
        Height = 196
        Caption = 'CH2'#37327#31243
        Color = clYellow
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ItemIndex = 1
        Items.Strings = (
          #177'13.8V'
          #177'6.4V'
          #177'3.2V'
          #177'1.6V'
          #177'800mV'
          #177'400mV'
          #177'200mV'
          #177'100mV')
        ParentBackground = False
        ParentColor = False
        ParentFont = False
        TabOrder = 16
        OnClick = Radio_CH2GainClick
      end
    end
  end
  object RadioButton1: TRadioButton
    Left = 265
    Top = 627
    Width = 58
    Height = 17
    Anchors = [akLeft, akBottom]
    Caption = 'USB'
    TabOrder = 3
  end
  object RadioButton2: TRadioButton
    Left = 356
    Top = 627
    Width = 58
    Height = 17
    Anchors = [akLeft, akBottom]
    Caption = #32593#32476
    TabOrder = 4
  end
  object PanelBottom: TPanel
    Left = 0
    Top = 625
    Width = 1152
    Height = 20
    Align = alBottom
    BevelInner = bvSpace
    BevelOuter = bvNone
    TabOrder = 5
    DesignSize = (
      1152
      20)
    object LabelUSBName: TLabel
      Left = 50
      Top = 4
      Width = 19
      Height = 13
      Caption = 'USB'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LabelVer: TLabel
      Left = 989
      Top = 1
      Width = 159
      Height = 13
      Anchors = [akRight, akBottom]
      Caption = #24403#21069#29256#26412#65306'V1.4.1 (2020-12-20)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LabelLedUSB: TLabel
      Left = 30
      Top = 6
      Width = 12
      Height = 12
      Hint = #40736#26631#24038#38190#20999#25442#21040'USB'#65292#21491#38190#20851#38381#20018#21475
      Caption = #9679
      Font.Charset = GB2312_CHARSET
      Font.Color = clGray
      Font.Height = -12
      Font.Name = #40657#20307
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      OnClick = LabelLedUSBClick
      OnMouseDown = LabelLedUSBMouseDown
    end
    object LabelLedRJ45: TLabel
      Left = 135
      Top = 6
      Width = 12
      Height = 12
      Caption = #9679
      Font.Charset = GB2312_CHARSET
      Font.Color = clGray
      Font.Height = -12
      Font.Name = #40657#20307
      Font.Style = []
      ParentFont = False
      OnClick = LabelLedRJ45Click
    end
    object LabelRJ45Name: TLabel
      Left = 153
      Top = 5
      Width = 24
      Height = 13
      Caption = 'RJ45'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LabelCheckVer: TLabel
      Left = 725
      Top = 3
      Width = 160
      Height = 13
      Anchors = [akRight, akBottom]
      Caption = #21457#29616#26032#29256#26412':V1.4.3(2020-12-20)'
    end
    object ProgressBar1: TProgressBar
      Left = 286
      Top = 5
      Width = 368
      Height = 10
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 0
    end
    object CheckBoxMonitorUSB: TCheckBox
      Left = 4
      Top = 0
      Width = 20
      Height = 23
      Hint = #23450#26102#30417#25511'USB'#21644'RJ45'#36830#25509
      Checked = True
      ParentShowHint = False
      ShowHint = True
      State = cbChecked
      TabOrder = 1
      OnClick = CheckBoxMonitorUSBClick
    end
    object ButtonGotoDownload: TButton
      Left = 905
      Top = -1
      Width = 66
      Height = 21
      Anchors = [akTop, akRight]
      Caption = #21435#19979#36733
      TabOrder = 2
      Visible = False
      OnClick = ButtonGotoDownloadClick
    end
  end
  object TimerTCP: TTimer
    Interval = 10
    OnTimer = TimerTCPTimer
    Left = 811
    Top = 152
  end
  object TimerPowerOn: TTimer
    Enabled = False
    Interval = 100
    OnTimer = TimerPowerOnTimer
    Left = 719
    Top = 150
  end
  object MainMenu1: TMainMenu
    Left = 624
    Top = 8
    object N8: TMenuItem
      Caption = #24110#21161
      object N9: TMenuItem
        Caption = #25805#20316#35828#26126
        OnClick = N9Click
      end
      object N10: TMenuItem
        Caption = #24320#28304#32593#22336
        OnClick = N10Click
      end
      object N2: TMenuItem
        Caption = #30005#36335#21407#29702#22270
        OnClick = N2Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object N3: TMenuItem
        Caption = #20462#25913#35760#24405
        OnClick = N3Click
      end
    end
  end
  object ImageList1: TImageList
    Left = 548
    Top = 5
    Bitmap = {
      494C010105000800AC0210001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000E4E4E423BBBBBC7DADADADAAAFB0B0A1C9C9CA5AF5F5F50A0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E5E5
      E526A3A4A5E3AEAFB0FFCACDCEFED1D4D4FED0D3D3FEC1C3C4FFA4A4A6FFB4B4
      B5A3FCFCFC030000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000D0D0D15AA9AA
      ABFFCDD1D1FE858686FE8B8A8AFF939393FF979797FF828282FF9EA0A0FECACD
      CDFEA5A5A6EFF6F6F60A00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000E3E3E433AEAFB1FFADB0
      B0FE8D8D8DFFC4C4C4FFDDDDDDFFBEBEBEFFD5D5D5FFD5D5D5FFB0B0B0FF7A7A
      7AFFCED1D1FEA9AAABEB00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000ACADAEF6BDC0C0FE9494
      94FFD3D3D3FFECECECFFF5F5F5FFF3F3F3FFF6F6F6FFF2F2F2FFE5E5E5FFBFBF
      BFFF797A7AFEC5C8C8FFCACACB83000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E2E2E345C0C3C3FF6C6D6DFFC9C9
      C9FFEAEAEAFFF1F1F1FFF2F2F2FFF3F3F3FFF2F2F2FFF2F2F2FFF0F0F0FFE2E2
      E2FFADADADFF999B9BFEB0B1B2FD000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C3C4C5BDBABCBDFE9F9F9FFFDFDF
      DFFFEFEFEFFFF0F0F0FFF0F0F0FFF1F1F1FFF2F2F2FFEFEFEFFFF0F0F0FFEDED
      EDFFCCCCCCFF7C7C7CFEBEC0C1FFEEEEEF270000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BDBFC0EC9C9D9EFEA3A3A3FFE6E6
      E6FFF0F0F0FFF0F0F0FFF2F2F2FF6E6E6DFF847F9BFFEFEFF0FFF0F0F0FFF0F0
      F0FFCCCCCCFF868686FFC0C3C4FEDBDCDD6C0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C1C3C3F38B8C8CFD909090FFDBDB
      DBFFF0F0F0FFF0F0F0FFF0F0F0FF847DA3FFDEDFDDFFF0F0F0FFF0F0F0FFF0F0
      F0FFCCCCCCFF717171FFBCBEBFFED9DBDB840000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000CACCCCE09C9D9EFEAFAFAFFFE6E6
      E6FFF0F0F0FFEEEEEEFFD6D2E8FFBFBFBFFFC4C4C4FFF3F3F3FFF0F0F0FFEFEF
      EFFFD7D7D7FF878787FFBDBFC0FFEAEBEB4F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000DFE0E091B2B4B5FE929292FFD9D9
      D9FFE5E4E8FFE7E5F2FFB8B9B8FFF4F4F4FFF5F5F5FFBABABAFFF2F2F2FFEAEA
      EAFFC4C4C4FF787878FEC5C7C8FFFBFBFB0C0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FAFAFA14C7CACAFF6C6C6CFEADAC
      B4FFE0DFE5FFF5F5F5FFC2C2C2FFF9F9F9FFF8F8F8FFF3F3F3FFDCDCDCFFDADA
      DAFF9A9A9AFF9A9A9CFED3D6D6E4000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000DDE0E0BCAFB0B1FE7D7D
      7CFFC2C2C2FFEEEEEEFFF8F8F8FFEDEDEDFFF6F6F6FFF7F7F7FFB4B4B4FFAAAA
      AAFF7B7B7BFEC9CCCCFFF7F7F72A000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FEFEFE01D9DCDCF2A7A8
      AAFE747475FEACACACFFE1E1E1FFDADADAFFDADADAFFD2D2D2FF929292FF7C7C
      7DFEC2C4C5FFE9EBEB8800000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FEFEFE04DFE3
      E3DFBFC2C2FF929294FE7E7E7EFE7F7F7FFF818181FE828283FDA2A3A4FED2D6
      D6FFEDEFEF7A0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F4F6F64CE1E5E5E4D7DBDBFFCED1D2FFD1D4D5FFDBDFDFFDE7EAEAB7FCFC
      FC12000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000ECECEC20CACACB71B5B5B6B7AFB0B0D6AEAFB0D7B3B3B5BCC7C7C77AE9E9
      E927FEFEFE010000000000000000000000000000000000000000000000000000
      000000000000E4E4E423BBBBBC7DADADADAAAFB0B0A1C9C9CA5AF5F5F50A0000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000DBDBDB24A3A3A4D19F9FA1FF9F9FA1FFA3A3A5CCDDDDDD220000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000DBDBDB24A3A3A4D19F9FA1FF9F9FA1FFA3A3A5CCDDDDDD220000
      0000000000000000000000000000000000000000000000000000FCFCFC04D8D8
      D855B6B7B8CCB4B6B7FAB2B4B4FFABADAEFFAAACACFFB1B3B3FFB4B6B6FCB5B6
      B7D4D3D3D362FAFAFA070000000000000000000000000000000000000000E5E5
      E526A3A4A5E3AEAFB0FFCACDCEFED1D4D4FED0D3D3FEC1C3C4FFA4A4A6FFB4B4
      B5A3FCFCFC03000000000000000000000000000000000000000000000000E9E9
      E916A1A1A3FFAAACADFDDDE2E2FFE2E6E6FFE2E6E6FFDEE2E2FFA8A9AAFEA1A1
      A3FFEDEDED12000000000000000000000000000000000000000000000000E9E9
      E916A1A1A3FFAAACADFDDDE2E2FFE2E6E6FFE2E6E6FFDEE2E2FFA8A9AAFEA1A1
      A3FFEDEDED1200000000000000000000000000000000FDFDFD02D3D3D369B4B5
      B7EFACAEAFFF989999FFA4A4A4FFA6A6A6FFA2A2A2FFA5A5A5FF999A9AFFA8AA
      ABFFB5B6B7F4CDCDCE7AFBFBFB06000000000000000000000000D0D0D15AA9AA
      ABFFCDD1D1FE858686FE8B8A8AFF939393FF979797FF828282FF9EA0A0FECACD
      CDFEA5A5A6EFF6F6F60A00000000000000000000000000000000CFCFCF30A4A5
      A6FFDBE0E0FF737373FF9D9D9DFFAFAFAFFFAFAFAFFF9C9C9CFF717171FFDBDF
      DFFFA4A5A6FFD7D7D72800000000000000000000000000000000CFCFCF30A4A5
      A6FFDBE0E0FF737373FF9D9D9DFFAFAFAFFFAFAFAFFF9C9C9CFF717171FFDBDF
      DFFFA4A5A6FFD7D7D728000000000000000000000000E2E2E245B7B9BAEAA7A9
      A9FF9A9A9AFFC2C2C2FFE2E2E2FFD9D9D9FFD5D5D5FFE3E3E3FFC7C7C7FF9B9C
      9CFFA3A5A5FFB6B8B9F2DBDCDC570000000000000000E3E3E433AEAFB1FFADB0
      B0FE8D8D8DFFC4C4C4FFDDDDDDFFBEBEBEFFD5D5D5FFD5D5D5FFB0B0B0FF7A7A
      7AFFCED1D1FEA9AAABEB000000000000000000000000FAFAFA05A8A9ABFFCCD0
      D0FD969696FFCACACAFFE4E4E4FFF2F2F2FFE8E8E8FFE4E4E4FFC9C9C9FF9494
      94FFD1D5D5FDA8A9ABFFFCFCFC030000000000000000FAFAFA05A8A9ABFFCCD0
      D0FD969696FFCACACAFFE4E4E4FFF2F2F2FFE8E8E8FFE4E4E4FFC9C9C9FF9494
      94FFD1D5D5FDA8A9ABFFFCFCFC0300000000F7F7F80FC4C5C6B5ACAEAEFF9798
      98FFCECECEFFEBEBEBFFF3F3F3FFF3F3F3FFF2F2F2FFF4F4F4FFECECECFFD2D2
      D2FF9B9B9BFFA7A9A9FFC0C1C2C7F4F4F41900000000ACADAEF6BDC0C0FE9494
      94FFD3D3D3FFECECECFFF5F5F5FFF3F3F3FFF6F6F6FFF2F2F2FFE5E5E5FFBFBF
      BFFF797A7AFEC5C8C8FFCACACB830000000000000000ACADAFFFD2D6D6FF9494
      94FFD4D4D4FFEDEDEDFFF4F4F4FFF6F6F6FFF6F6F6FFF4F4F4FFEDEDEDFFD3D3
      D3FF929292FFD2D6D5FFACADAFFF0000000000000000ACADAFFFD2D6D6FF9494
      94FFD4D4D4FFEDEDEDFFF4F4F4FFF6F6F6FFF6F6F6FFF4F4F4FFEDEDEDFFD3D3
      D3FF929292FFD2D6D5FFACADAFFF00000000E5E5E648BABCBDF0959696FFB9B9
      B9FFE7E7E7FFF0F0F0FFF2F2F2FFF3F3F3FFF4F4F4FFF2F2F2FFF1F1F1FFE9E9
      E9FFC1C1C1FF929292FFB7B9BAF7DEDEDF5EE2E2E345C0C3C3FF6C6D6DFFC9C9
      C9FFEAEAEAFFF1F1F1FFF2F2F2FFF3F3F3FFF2F2F2FFF2F2F2FFF0F0F0FFE2E2
      E2FFADADADFF999B9BFEB0B1B2FD00000000FEFEFE01B1B3B4FE6D6D6DFFC5C5
      C5FFEAEAEAFFF1F1F1FFF2F2F2FFF2F2F2FFF2F2F2FFF2F2F2FFF1F1F1FFE9E9
      E9FFC3C3C3FF696868FFB1B2B3FE00000000FEFEFE01B1B3B4FE6D6D6DFFC5C5
      C5FFEAEAEAFFF1F1F1FFF2F2F2FFF2F2F2FFF2F2F2FFF2F2F2FFF1F1F1FFE9E9
      E9FFC3C3C3FF696868FFB1B2B3FE00000000D7D8D884B1B3B3FE999999FFD5D5
      D5FFEEEEEEFFF0F0F0FFEFEFEFFFDEDFDEFFD5D5D7FFE5E4EBFFF0F0F0FFEFEF
      EFFFD9D9D9FF9C9C9CFFADAEAFFFD0D1D29DC3C4C5BDBABCBDFE9F9F9FFFDFDF
      DFFFEFEFEFFFF0F0F0FFF0F0F0FFF1F1F1FFF2F2F2FFEFEFEFFFF0F0F0FFEDED
      EDFFCCCCCCFF7C7C7CFEBEC0C1FFEEEEEF27CACACA88C8CBCBFF959595FFDBDB
      DBFFEFEFEFFFF0F0F0FFF0F0F0FFF0F0F0FFF0F0F0FFEEEFEDFFF0F0F0FFEFEF
      EFFFDADADAFF929292FFC8CBCBFFD1D2D267CACACA88C8CBCBFF959595FFDBDB
      DBFFEFEFEFFFF0F0F0FFF0F0F0FFF0F0F0FFF0F0F0FFEEEFEDFFF0F0F0FFEFEF
      EFFFDADADAFF929292FFC8CBCBFFD1D2D267D2D3D4A5A8AAABFF8D8D8DFFC8C8
      C8FFF0F0F0FFF0F0F0FFF0F0F0FF9E9DA3FF898699FFE7E6EEFFF0F0F0FFF1F1
      F1FFD8D8D8FF909090FFA1A3A3FFCBCDCDC1BDBFC0EC9C9D9EFEA3A3A3FFE6E6
      E6FFF0F0F0FFF0F0F0FFF2F2F2FF6E6E6DFF847F9BFFEFEFF0FFF0F0F0FFF0F0
      F0FFCCCCCCFF868686FFC0C3C4FEDBDCDD6CBBBDBEFFC3C5C6FF9F9F9FFFE7E7
      E7FFF0F0F0FFF0F0F0FFF0F0F0FF262626FF45415CFFF0F0F0FFF0F0F0FFF0F0
      F0FFE3E3E3FF6C6C6CFFC3C5C6FFBBBDBEFBBBBDBEFFC3C5C6FF9F9F9FFFE7E7
      E7FFF0F0F0FFF0F0F0FFF0F0F0FF262626FF45415CFFF0F0F0FFF0F0F0FFF0F0
      F0FFE3E3E3FF6C6C6CFFC3C5C6FFBBBDBEFBD5D7D7A7A6A7A8FF8A8A8BFFC7C7
      C7FFF0F0F0FFF0F0F0FFEAE9EDFFAFACBCFFB5B4BCFFEEEEEDFFF0F0F0FFF1F1
      F1FFD8D8D8FF8D8D8DFF9EA0A0FFCED0D1C3C1C3C3F38B8C8CFD909090FFDBDB
      DBFFF0F0F0FFF0F0F0FFF0F0F0FF847DA3FFDEDFDDFFF0F0F0FFF0F0F0FFF0F0
      F0FFCCCCCCFF717171FFBCBEBFFED9DBDB84C1C3C4FFBFC1C2FF5C5C5CFFDFDF
      DFFFF0F0F0FFF0F0F0FFF0F0F0FF7364BCFF7E7E7EFFF0F0F0FFF0F0F0FFF0F0
      F0FFE9E9E9FF3F3F3FFFBEC0C1FFC1C3C4FFC1C3C4FFBFC1C2FF5C5C5CFFDFDF
      DFFFF0F0F0FFF0F0F0FFF0F0F0FF7364BCFF7E7E7EFFF0F0F0FFF0F0F0FFF0F0
      F0FFE9E9E9FF3F3F3FFFBEC0C1FFC1C3C4FFE0E1E187ADAFB0FF979797FFD6D6
      D6FFEEEEEEFFE9E8EEFFD7D5E0FFC4C3C5FFE0E0DFFFD8D8D8FFF1F1F1FFEFEF
      EFFFDBDBDBFF9B9B9BFFA7A9AAFFDADBDCA1CACCCCE09C9D9EFEAFAFAFFFE6E6
      E6FFF0F0F0FFEEEEEEFFD6D2E8FFBFBFBFFFC4C4C4FFF3F3F3FFF0F0F0FFEFEF
      EFFFD7D7D7FF878787FFBDBFC0FFEAEBEB4FD0D2D2B8B7B8BAFF9C9C9CFFDEDE
      DEFFF0F0F0FFF0F0F0FFECEAF1FF727272FFF3F3F3FFF5F5F5FFF0F0F0FFF0F0
      F0FFDEDEDEFF999999FFB7B8BAFFD7D8D897D0D2D2B8B7B8BAFF9C9C9CFFDEDE
      DEFFF0F0F0FFF0F0F0FFECEAF1FF727272FFF3F3F3FFF5F5F5FFF0F0F0FFF0F0
      F0FFDEDEDEFF999999FFB7B8BAFFD7D8D897EFF0F04CBEC1C1F28D8E8EFFBFBE
      BFFFDDDBE4FFE7E6F0FFD0D0D1FFDFDFDFFFF6F6F6FFDADADAFFE4E4E4FFECEC
      ECFFC6C6C6FF8C8C8DFFB8BABAF8EAEBEB63DFE0E091B2B4B5FE929292FFD9D9
      D9FFE5E4E8FFE7E5F2FFB8B9B8FFF4F4F4FFF5F5F5FFBABABAFFF2F2F2FFEAEA
      EAFFC4C4C4FF787878FEC5C7C8FFFBFBFB0C00000000BEC1C2FD7A7A7AFFCCCC
      CCFFEAEAEAFFF6F6F5FFE2E2E2FFF5F5F5FFF5F5F5FFC0C0C0FFF5F5F5FFECEC
      ECFFCBCBCBFF767676FFC3C5C5FD0000000000000000BEC1C2FD7A7A7AFFCCCC
      CCFFEAEAEAFFF6F6F5FFE2E2E2FFF5F5F5FFF5F5F5FFC0C0C0FFF5F5F5FFECEC
      ECFFCBCBCBFF767676FFC3C5C5FD00000000FBFCFC11D8DADABC9C9D9DFF9292
      96FFCCCAD2FFEBEBECFFD5D5D5FFF6F6F6FFF9F9F9FFF5F5F5FFD3D3D3FFD1D1
      D1FF9E9E9EFF949596FFD3D5D6CCF9FAFA1CFAFAFA14C7CACAFF6C6C6CFEADAC
      B4FFE0DFE5FFF5F5F5FFC2C2C2FFF9F9F9FFF8F8F8FFF3F3F3FFDCDCDCFFDADA
      DAFF9A9A9AFF9A9A9CFED3D6D6E40000000000000000CFD2D2FFABACADFD9797
      97FFDDDDDDFFF5F5F5FF969696FFF9F9F9FFF9F9F9FFF9F9F9FF8D8D8DFFDDDD
      DDFFA2A2A2FFAEAFB1FECFD2D2FF0000000000000000CFD2D2FFABACADFD9797
      97FFDDDDDDFFF5F5F5FF969696FFF9F9F9FFF9F9F9FFF9F9F9FF8D8D8DFFDDDD
      DDFFA2A2A2FFAEAFB1FECFD2D2FF0000000000000000F2F3F34DC5C8C9EF9090
      91FF9F9F9FFFD2D2D2FFEEEEEEFFEFEFEFFFEEEEEEFFF4F4F4FFCACACAFF8C8C
      8CFF8D8D8EFFC0C3C3F6EEF0F05F0000000000000000DDE0E0BCAFB0B1FE7D7D
      7CFFC2C2C2FFEEEEEEFFF8F8F8FFEDEDEDFFF6F6F6FFF7F7F7FFB4B4B4FFAAAA
      AAFF7B7B7BFEC9CCCCFFF7F7F72A000000000000000000000000D0D3D4FE5B5B
      5BFEACACACFFE2E2E2FFF6F6F6FFC1C1C1FFF5F5F5FFF7F7F7FFE0E0E0FFAFAF
      AFFF595958FDD3D6D7FF00000000000000000000000000000000D0D3D4FE5B5B
      5BFEACACACFFE2E2E2FFF6F6F6FFC1C1C1FFF5F5F5FFF7F7F7FFE0E0E0FFAFAF
      AFFF595958FDD3D6D7FF000000000000000000000000FEFEFE03ECEEEE74C3C6
      C6F4949495FF909090FFB7B7B7FFCACACAFFC9C9C9FFBABABAFF949494FF8C8D
      8EFFBEC0C1F8E9EBEB85FDFEFE070000000000000000FEFEFE01D9DCDCF2A7A8
      AAFE747475FEACACACFFE1E1E1FFDADADAFFDADADAFFD2D2D2FF929292FF7C7C
      7DFEC2C4C5FFE9EBEB8800000000000000000000000000000000DEE0E0CFC7C9
      C9FE7D7D7EFC929292FFD7D7D7FFBABABAFFC7C7C7FFD5D5D5FF909090FF8383
      85FCCBCFCFFEE1E4E4B600000000000000000000000000000000DEE0E0CFC7C9
      C9FE7D7D7EFC929292FFD7D7D7FFBABABAFFC7C7C7FFD5D5D5FF909090FF8383
      85FCCBCFCFFEE1E4E4B600000000000000000000000000000000FEFEFE06F1F2
      F260D5D8D8D7B2B4B5FD9D9D9EFF969798FF959697FF9C9C9DFFB0B1B2FED2D5
      D5DEEFF0F06EFDFDFD0900000000000000000000000000000000FEFEFE04DFE3
      E3DFBFC2C2FF929294FE7E7E7EFE7F7F7FFF818181FE828283FDA2A3A4FED2D6
      D6FFEDEFEF7A000000000000000000000000000000000000000000000000F2F3
      F356DBDFDFFF9E9EA0FF9D9D9FFD6D6D6EFC6F6F6FFB9E9FA0FD9E9D9FFFDBDF
      DFFFF5F6F641000000000000000000000000000000000000000000000000F2F3
      F356DBDFDFFF9E9EA0FF9D9D9FFD6D6D6EFC6F6F6FFB9E9FA0FD9E9D9FFFDBDF
      DFFFF5F6F641000000000000000000000000000000000000000000000000FEFE
      FE01FAFBFB27EDF0F081DEE1E1C8D4D7D7EDD2D6D6EFDEE0E1CDECEEEE8AF9FA
      FA2FFEFEFE020000000000000000000000000000000000000000000000000000
      0000F4F6F64CE1E5E5E4D7DBDBFFCED1D2FFD1D4D5FFDBDFDFFDE7EAEAB7FCFC
      FC12000000000000000000000000000000000000000000000000000000000000
      000000000000E8EBEBA9DDE2E2FFDDE2E2FFDDE2E2FFDDE2E2FFEAEDED9D0000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000E8EBEBA9DDE2E2FFDDE2E2FFDDE2E2FFDDE2E2FFEAEDED9D0000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF00F81F000000000000E007000000000000
      C003000000000000800300000000000080010000000000000001000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000100000000000080010000000000008003000000000000
      C007000000000000F00F000000000000F007F81FF81FF81FC003E007E007E007
      8001C003C003C003800180038001800100008001800180010000000100010001
      0000000000000000000000000000000000000000000000000000000000000000
      0000000080018001000000018001800180018001C003C00380018003C003C003
      C003C007E007E007E007F00FF81FF81F00000000000000000000000000000000
      000000000000}
  end
  object OpenDialog1: TOpenDialog
    Ctl3D = False
    Left = 872
    Top = 165
  end
  object YbCommDevice1: TYbCommDevice
    PortNo = 2
    PortName = 'COM2'
    Baud = br2000000
    SyncEvents = False
    HwInSize = 8192
    HwOutSize = 8192
    PackageType = cptCompatiblePkg
    PackageInterval = 5
    OnPackage = YbCommDevice1Package
    Left = 775
    Top = 207
  end
  object TimerUpgrade: TTimer
    OnTimer = TimerUpgradeTimer
    Left = 809
    Top = 91
  end
  object IdUDPServer1: TIdUDPServer
    Bindings = <>
    DefaultPort = 0
    OnUDPRead = IdUDPServer1UDPRead
    Left = 472
    Top = 8
  end
  object IdHTTP1: TIdHTTP
    AllowCookies = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 705
    Top = 293
  end
  object Timer1: TTimer
    Interval = 5
    OnTimer = Timer1Timer
    Left = 625
    Top = 133
  end
end
