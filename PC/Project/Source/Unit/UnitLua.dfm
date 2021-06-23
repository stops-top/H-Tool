object FormLua: TFormLua
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'FormLua'
  ClientHeight = 729
  ClientWidth = 560
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  OnCreate = FormCreate
  DesignSize = (
    560
    729)
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 76
    Width = 544
    Height = 657
    ActivePage = TabSheet1
    Anchors = [akLeft, akTop, akRight, akBottom]
    DoubleBuffered = False
    MultiLine = True
    ParentDoubleBuffered = False
    ScrollOpposite = True
    Style = tsButtons
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #24555#25463#25351#20196
      object PanelLua2: TPanel
        Left = 0
        Top = 0
        Width = 536
        Height = 629
        Align = alClient
        BevelEdges = []
        BevelOuter = bvNone
        TabOrder = 0
        DesignSize = (
          536
          629)
        object Label63: TLabel
          Left = 8
          Top = 24
          Width = 12
          Height = 13
          Caption = '01'
        end
        object Label64: TLabel
          Left = 8
          Top = 54
          Width = 12
          Height = 13
          Caption = '02'
        end
        object Label65: TLabel
          Left = 8
          Top = 85
          Width = 12
          Height = 13
          Caption = '03'
        end
        object Label66: TLabel
          Left = 8
          Top = 115
          Width = 12
          Height = 13
          Caption = '04'
        end
        object Label67: TLabel
          Left = 8
          Top = 146
          Width = 12
          Height = 13
          Caption = '05'
        end
        object Label68: TLabel
          Left = 8
          Top = 176
          Width = 12
          Height = 13
          Caption = '06'
        end
        object Label69: TLabel
          Left = 8
          Top = 207
          Width = 12
          Height = 13
          Caption = '07'
        end
        object Label70: TLabel
          Left = 8
          Top = 237
          Width = 12
          Height = 13
          Caption = '08'
        end
        object Label61: TLabel
          Left = 29
          Top = 3
          Width = 24
          Height = 13
          Caption = #27880#37322
        end
        object Label62: TLabel
          Left = 185
          Top = 4
          Width = 41
          Height = 13
          Caption = 'Lua'#31243#24207
        end
        object Label71: TLabel
          Left = 8
          Top = 268
          Width = 12
          Height = 13
          Caption = '09'
        end
        object Label72: TLabel
          Left = 8
          Top = 299
          Width = 12
          Height = 13
          Caption = '10'
        end
        object Label73: TLabel
          Left = 8
          Top = 329
          Width = 12
          Height = 13
          Caption = '11'
        end
        object Label74: TLabel
          Left = 7
          Top = 359
          Width = 12
          Height = 13
          Caption = '12'
        end
        object Label75: TLabel
          Left = 8
          Top = 390
          Width = 12
          Height = 13
          Caption = '13'
        end
        object Label76: TLabel
          Left = 8
          Top = 420
          Width = 12
          Height = 13
          Caption = '14'
        end
        object Label77: TLabel
          Left = 8
          Top = 451
          Width = 12
          Height = 13
          Caption = '15'
        end
        object Label78: TLabel
          Left = 9
          Top = 482
          Width = 12
          Height = 13
          Caption = '16'
        end
        object EditLua1: TEdit
          Left = 185
          Top = 23
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 0
          Text = 'test_gpio()'
        end
        object ButtonDoLua1: TButton
          Left = 473
          Top = 20
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 1
          OnClick = ButtonDoLua1Click
        end
        object EditLua2: TEdit
          Left = 185
          Top = 52
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 2
          Text = 'test_ledout()'
        end
        object ButtonDoLua2: TButton
          Left = 473
          Top = 51
          Width = 50
          Height = 23
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 3
          OnClick = ButtonDoLua1Click
        end
        object EditLua3: TEdit
          Left = 185
          Top = 80
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 4
          Text = 'test_swd()'
        end
        object ButtonDoLua3: TButton
          Left = 473
          Top = 77
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 5
          OnClick = ButtonDoLua1Click
        end
        object EditLua4: TEdit
          Left = 185
          Top = 110
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 6
          Text = 'test_analog()'
        end
        object ButtonDoLua4: TButton
          Left = 473
          Top = 108
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 7
          OnClick = ButtonDoLua1Click
        end
        object EditLua5: TEdit
          Left = 185
          Top = 141
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 8
        end
        object ButtonDoLua5: TButton
          Left = 473
          Top = 139
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 9
          OnClick = ButtonDoLua1Click
        end
        object EditLua6: TEdit
          Left = 185
          Top = 171
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 10
        end
        object ButtonDoLua6: TButton
          Left = 472
          Top = 168
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 11
          OnClick = ButtonDoLua1Click
        end
        object EditLua7: TEdit
          Left = 185
          Top = 202
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 12
        end
        object ButtonDoLua7: TButton
          Left = 473
          Top = 198
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 13
          OnClick = ButtonDoLua1Click
        end
        object EditLua8: TEdit
          Left = 185
          Top = 232
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 14
        end
        object ButtonDoLua8: TButton
          Left = 473
          Top = 231
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 15
          OnClick = ButtonDoLua1Click
        end
        object EditLuaNote1: TEdit
          Left = 29
          Top = 23
          Width = 150
          Height = 21
          TabOrder = 16
          Text = #27979#35797'GPIO'#21151#33021
        end
        object EditLuaNote2: TEdit
          Left = 29
          Top = 52
          Width = 150
          Height = 21
          TabOrder = 17
          Text = #27979#35797#36716#25509#26495
        end
        object EditLuaNote3: TEdit
          Left = 29
          Top = 80
          Width = 150
          Height = 21
          TabOrder = 18
          Text = #27979#35797'SWD'#25509#21475
        end
        object EditLuaNote4: TEdit
          Left = 29
          Top = 110
          Width = 150
          Height = 21
          TabOrder = 19
          Text = #27979#35797#27169#25311#30005#36335
        end
        object EditLuaNote5: TEdit
          Left = 29
          Top = 141
          Width = 150
          Height = 21
          TabOrder = 20
        end
        object EditLuaNote6: TEdit
          Left = 29
          Top = 171
          Width = 150
          Height = 21
          TabOrder = 21
        end
        object EditLuaNote7: TEdit
          Left = 29
          Top = 202
          Width = 150
          Height = 21
          TabOrder = 22
        end
        object EditLuaNote8: TEdit
          Left = 29
          Top = 232
          Width = 150
          Height = 21
          TabOrder = 23
        end
        object EditLua9: TEdit
          Left = 185
          Top = 263
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 24
        end
        object ButtonDoLua9: TButton
          Left = 473
          Top = 259
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 25
          OnClick = ButtonDoLua1Click
        end
        object EditLua10: TEdit
          Left = 185
          Top = 293
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 26
        end
        object ButtonDoLua10: TButton
          Left = 473
          Top = 292
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 27
          OnClick = ButtonDoLua1Click
        end
        object EditLua11: TEdit
          Left = 185
          Top = 324
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 28
        end
        object ButtonDoLua11: TButton
          Left = 473
          Top = 322
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 29
          OnClick = ButtonDoLua1Click
        end
        object EditLua12: TEdit
          Left = 185
          Top = 354
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 30
        end
        object ButtonDoLua12: TButton
          Left = 473
          Top = 353
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 31
          OnClick = ButtonDoLua1Click
        end
        object EditLua13: TEdit
          Left = 185
          Top = 385
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 32
        end
        object ButtonDoLua13: TButton
          Left = 473
          Top = 384
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 33
          OnClick = ButtonDoLua1Click
        end
        object EditLua14: TEdit
          Left = 185
          Top = 415
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 34
        end
        object ButtonDoLua14: TButton
          Left = 473
          Top = 415
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 35
          OnClick = ButtonDoLua1Click
        end
        object EditLua15: TEdit
          Left = 185
          Top = 446
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 36
        end
        object ButtonDoLua15: TButton
          Left = 473
          Top = 446
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 37
          OnClick = ButtonDoLua1Click
        end
        object EditLua16: TEdit
          Left = 185
          Top = 477
          Width = 282
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 38
        end
        object ButtonDoLua16: TButton
          Left = 473
          Top = 476
          Width = 50
          Height = 25
          Anchors = [akTop, akRight]
          Caption = #25191#34892
          TabOrder = 39
          OnClick = ButtonDoLua1Click
        end
        object EditLuaNote9: TEdit
          Left = 29
          Top = 263
          Width = 150
          Height = 21
          TabOrder = 40
        end
        object EditLuaNote10: TEdit
          Left = 29
          Top = 293
          Width = 150
          Height = 21
          TabOrder = 41
        end
        object EditLuaNote11: TEdit
          Left = 29
          Top = 324
          Width = 150
          Height = 21
          TabOrder = 42
        end
        object EditLuaNote12: TEdit
          Left = 29
          Top = 354
          Width = 150
          Height = 21
          TabOrder = 43
        end
        object EditLuaNote13: TEdit
          Left = 29
          Top = 385
          Width = 150
          Height = 21
          TabOrder = 44
        end
        object EditLuaNote14: TEdit
          Left = 29
          Top = 415
          Width = 150
          Height = 21
          TabOrder = 45
        end
        object EditLuaNote15: TEdit
          Left = 29
          Top = 446
          Width = 150
          Height = 21
          TabOrder = 46
        end
        object EditLuaNote16: TEdit
          Left = 29
          Top = 477
          Width = 150
          Height = 21
          TabOrder = 47
        end
        object ButtonSetClock: TButton
          Left = 29
          Top = 523
          Width = 67
          Height = 31
          Caption = #21516#27493#26102#38047
          TabOrder = 48
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Lua'#36755#20837#31383#21475'1,2'
      DesignSize = (
        536
        629)
      object PanelLua1: TPanel
        Left = -6
        Top = 1
        Width = 539
        Height = 625
        Anchors = [akLeft, akTop, akRight, akBottom]
        BevelEdges = []
        BevelOuter = bvNone
        TabOrder = 0
        object Splitter1: TSplitter
          Left = 0
          Top = 251
          Width = 539
          Height = 8
          Cursor = crVSplit
          Align = alTop
          Color = clBtnFace
          ParentColor = False
          ExplicitTop = 273
          ExplicitWidth = 536
        end
        object PanelLua1_1: TPanel
          Left = 0
          Top = 0
          Width = 539
          Height = 251
          Align = alTop
          BevelEdges = []
          BevelOuter = bvNone
          Color = 14811105
          ParentBackground = False
          TabOrder = 0
          DesignSize = (
            539
            251)
          object Label1: TLabel
            Left = 100
            Top = 229
            Width = 206
            Height = 13
            Caption = #21246#36873'UDP'#30417#21548#31471#21475'777'#25165#33021#30475#21040#25191#34892#32467#26524
          end
          object MemoLuaTemp1: TMemo
            Left = 9
            Top = 5
            Width = 523
            Height = 212
            TabStop = False
            Align = alCustom
            Anchors = [akLeft, akTop, akRight, akBottom]
            Font.Charset = GB2312_CHARSET
            Font.Color = clBlack
            Font.Height = -13
            Font.Name = #26032#23435#20307
            Font.Style = []
            Lines.Strings = (
              'print("test beep1")'
              'beep()'
              'delayms(200)'
              ''
              'print("test beep2")'
              'beep()'
              'delayus(200000)'
              ''
              'beep()'
              'print("test beep3")')
            ParentFont = False
            ScrollBars = ssBoth
            TabOrder = 0
            WantTabs = True
          end
          object ButtonDoLuaTemp: TButton
            Tag = 1
            Left = 9
            Top = 223
            Width = 73
            Height = 26
            Anchors = [akLeft, akBottom]
            Caption = #25191#34892
            TabOrder = 1
            OnClick = ButtonDoLuaTempClick
          end
        end
        object PanelLua1_2: TPanel
          Left = 0
          Top = 259
          Width = 539
          Height = 366
          Align = alClient
          BevelEdges = []
          BevelOuter = bvNone
          Caption = 'PanelLua1_2'
          Color = clAqua
          ParentBackground = False
          TabOrder = 1
          DesignSize = (
            539
            366)
          object MemoLuaTemp2: TMemo
            Left = 9
            Top = 8
            Width = 523
            Height = 314
            TabStop = False
            Anchors = [akLeft, akTop, akRight, akBottom]
            Font.Charset = GB2312_CHARSET
            Font.Color = clBlack
            Font.Height = -13
            Font.Name = #26032#23435#20307
            Font.Style = []
            Lines.Strings = (
              'print("test beep1")'
              'beep()'
              'delayms(200)'
              ''
              'print("test beep2")'
              'beep()'
              'delayus(200000)'
              ''
              'beep()'
              'print("test beep3")')
            ParentFont = False
            ScrollBars = ssBoth
            TabOrder = 0
            WantTabs = True
          end
          object Button63: TButton
            Tag = 2
            Left = 9
            Top = 328
            Width = 73
            Height = 25
            Anchors = [akLeft, akBottom]
            Caption = #25191#34892
            TabOrder = 1
            OnClick = ButtonDoLuaTempClick
          end
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Lua'#36755#20837#31383#21475'3,4'
      ImageIndex = 2
      object Splitter2: TSplitter
        Left = 0
        Top = 251
        Width = 536
        Height = 13
        Cursor = crVSplit
        Align = alTop
        Color = clBtnFace
        ParentColor = False
        ExplicitLeft = -3
        ExplicitTop = 255
        ExplicitWidth = 539
      end
      object Panel2: TPanel
        Left = 0
        Top = 264
        Width = 536
        Height = 365
        Align = alClient
        BevelEdges = []
        BevelOuter = bvNone
        Caption = 'PanelLua1_2'
        Color = clAqua
        ParentBackground = False
        TabOrder = 0
        DesignSize = (
          536
          365)
        object MemoLuaTemp4: TMemo
          Left = 9
          Top = 8
          Width = 523
          Height = 314
          TabStop = False
          Anchors = [akLeft, akTop, akRight, akBottom]
          Font.Charset = GB2312_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = #26032#23435#20307
          Font.Style = []
          Lines.Strings = (
            'print("test beep1")'
            'beep()'
            'delayms(200)'
            ''
            'print("test beep2")'
            'beep()'
            'delayus(200000)'
            ''
            'beep()'
            'print("test beep3")')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          WantTabs = True
        end
        object Button1: TButton
          Tag = 4
          Left = 9
          Top = 328
          Width = 73
          Height = 25
          Anchors = [akLeft, akBottom]
          Caption = #25191#34892
          TabOrder = 1
          OnClick = ButtonDoLuaTempClick
        end
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 536
        Height = 251
        Align = alTop
        BevelEdges = []
        BevelOuter = bvNone
        Color = 14811105
        ParentBackground = False
        TabOrder = 1
        DesignSize = (
          536
          251)
        object MemoLuaTemp3: TMemo
          Left = 7
          Top = 5
          Width = 523
          Height = 212
          TabStop = False
          Align = alCustom
          Anchors = [akLeft, akTop, akRight, akBottom]
          Font.Charset = GB2312_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = #26032#23435#20307
          Font.Style = []
          Lines.Strings = (
            'print("test beep1")'
            'beep()'
            'delayms(200)'
            ''
            'print("test beep2")'
            'beep()'
            'delayus(200000)'
            ''
            'beep()'
            'print("test beep3")')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          WantTabs = True
        end
        object Button2: TButton
          Tag = 3
          Left = 9
          Top = 223
          Width = 73
          Height = 26
          Anchors = [akLeft, akBottom]
          Caption = #25191#34892
          TabOrder = 1
          OnClick = ButtonDoLuaTempClick
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Lua'#36755#20837#31383#21475'5,6'
      ImageIndex = 3
      object Splitter3: TSplitter
        Left = 0
        Top = 251
        Width = 536
        Height = 10
        Cursor = crVSplit
        Align = alTop
        Color = clBtnFace
        ParentColor = False
        ExplicitLeft = 3
        ExplicitTop = 260
      end
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 536
        Height = 251
        Align = alTop
        BevelEdges = []
        BevelOuter = bvNone
        Color = 14811105
        ParentBackground = False
        TabOrder = 0
        DesignSize = (
          536
          251)
        object MemoLuaTemp5: TMemo
          Left = 9
          Top = 5
          Width = 523
          Height = 212
          TabStop = False
          Align = alCustom
          Anchors = [akLeft, akTop, akRight, akBottom]
          Font.Charset = GB2312_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = #26032#23435#20307
          Font.Style = []
          Lines.Strings = (
            'print("test beep1")'
            'beep()'
            'delayms(200)'
            ''
            'print("test beep2")'
            'beep()'
            'delayus(200000)'
            ''
            'beep()'
            'print("test beep3")')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          WantTabs = True
        end
        object Button3: TButton
          Tag = 5
          Left = 7
          Top = 223
          Width = 73
          Height = 26
          Anchors = [akLeft, akBottom]
          Caption = #25191#34892
          TabOrder = 1
          OnClick = ButtonDoLuaTempClick
        end
      end
      object Panel5: TPanel
        Left = 0
        Top = 261
        Width = 536
        Height = 368
        Align = alClient
        BevelEdges = []
        BevelOuter = bvNone
        Caption = 'PanelLua1_2'
        Color = clAqua
        ParentBackground = False
        TabOrder = 1
        DesignSize = (
          536
          368)
        object MemoLuaTemp6: TMemo
          Left = 9
          Top = 8
          Width = 523
          Height = 314
          TabStop = False
          Anchors = [akLeft, akTop, akRight, akBottom]
          Font.Charset = GB2312_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = #26032#23435#20307
          Font.Style = []
          Lines.Strings = (
            'print("test beep1")'
            'beep()'
            'delayms(200)'
            ''
            'print("test beep2")'
            'beep()'
            'delayus(200000)'
            ''
            'beep()'
            'print("test beep3")')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          WantTabs = True
        end
        object Button4: TButton
          Tag = 6
          Left = 9
          Top = 328
          Width = 73
          Height = 25
          Anchors = [akLeft, akBottom]
          Caption = #25191#34892
          TabOrder = 1
          OnClick = ButtonDoLuaTempClick
        end
      end
    end
  end
  object MemoLua: TMemo
    Left = 573
    Top = 46
    Width = 110
    Height = 120
    Font.Charset = GB2312_CHARSET
    Font.Color = clGray
    Font.Height = -13
    Font.Name = #26032#23435#20307
    Font.Style = []
    Lines.Strings = (
      'printf("start lua\r\n")')
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 1
    Visible = False
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 560
    Height = 73
    Align = alTop
    Caption = 'Panel1'
    Color = clGradientActiveCaption
    ParentBackground = False
    TabOrder = 2
    object Label26: TLabel
      Left = 8
      Top = 3
      Width = 77
      Height = 13
      Caption = 'Lua'#25991#20214#36335#24452#65306
    end
    object RichEditFileName: TMemo
      Left = 8
      Top = 22
      Width = 459
      Height = 42
      Lines.Strings = (
        '---')
      TabOrder = 0
    end
    object Button32: TButton
      Left = 473
      Top = 5
      Width = 80
      Height = 32
      Caption = #25171#24320#25991#20214
      TabOrder = 1
      OnClick = Button32Click
    end
    object ButtonDownLuaFile: TButton
      Left = 473
      Top = 36
      Width = 81
      Height = 34
      Caption = #19979#36733'Lua'#31243#24207
      TabOrder = 2
      OnClick = ButtonDownLuaFileClick
    end
  end
end
