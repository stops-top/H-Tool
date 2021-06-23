object FormCalib: TFormCalib
  Left = 0
  Top = 0
  Caption = #27169#25311#37327#26657#20934
  ClientHeight = 498
  ClientWidth = 942
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
    942
    498)
  PixelsPerInch = 96
  TextHeight = 13
  object X: TPageControl
    Left = 8
    Top = 8
    Width = 473
    Height = 482
    ActivePage = TabSheet1
    TabOrder = 0
    object TabSheetDC: TTabSheet
      Caption = 'CH1'#30005#21387
      object GroupBox10: TGroupBox
        Left = 9
        Top = 16
        Width = 443
        Height = 321
        Caption = #31034#27874#22120'CH1'#30005#21387
        Color = 15529451
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object Label8: TLabel
          Left = 127
          Top = 21
          Width = 57
          Height = 13
          Caption = #38646#20301'ADC'#20540
        end
        object Label31: TLabel
          Left = 6
          Top = 48
          Width = 36
          Height = 13
          Caption = #177'13.8V'
        end
        object Label32: TLabel
          Left = 57
          Top = 20
          Width = 62
          Height = 13
          Caption = #38646#20301#30005#21387'(V)'
        end
        object Label33: TLabel
          Left = 14
          Top = 21
          Width = 24
          Height = 13
          Caption = #37327#31243
        end
        object Label34: TLabel
          Left = 248
          Top = 21
          Width = 62
          Height = 13
          Caption = #28385#20301#30005#21387'(V)'
        end
        object Label35: TLabel
          Left = 323
          Top = 21
          Width = 57
          Height = 13
          Caption = #28385#20301'ADC'#20540
        end
        object Label6: TLabel
          Left = 12
          Top = 84
          Width = 30
          Height = 13
          Caption = #177'6.4V'
        end
        object Label36: TLabel
          Left = 11
          Top = 119
          Width = 30
          Height = 13
          Caption = #177'3.2V'
        end
        object Label37: TLabel
          Left = 12
          Top = 150
          Width = 30
          Height = 13
          Caption = #177'1.6V'
        end
        object Label38: TLabel
          Left = 8
          Top = 184
          Width = 40
          Height = 13
          Caption = #177'800mV'
        end
        object Label39: TLabel
          Left = 8
          Top = 217
          Width = 40
          Height = 13
          Caption = #177'400mV'
        end
        object Label40: TLabel
          Left = 7
          Top = 252
          Width = 40
          Height = 13
          Caption = #177'200mV'
        end
        object Label41: TLabel
          Left = 7
          Top = 285
          Width = 40
          Height = 13
          Caption = #177'100mV'
        end
        object ButtonCH1_R1_2: TButton
          Left = 388
          Top = 37
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 0
          OnClick = ButtonCH1_R1_2Click
        end
        object EditCH1R1Volt1: TEdit
          Left = 58
          Top = 39
          Width = 60
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object EditCH1R1VoltAdc1: TEdit
          Left = 125
          Top = 39
          Width = 60
          Height = 21
          TabOrder = 2
          Text = '0'
        end
        object EditCH1R1Volt2: TEdit
          Left = 249
          Top = 40
          Width = 60
          Height = 21
          TabOrder = 3
          Text = '0'
        end
        object EditCH1R1VoltAdc2: TEdit
          Left = 318
          Top = 40
          Width = 60
          Height = 21
          TabOrder = 4
          Text = '0'
        end
        object Button1: TButton
          Tag = 1
          Left = 388
          Top = 72
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 5
          OnClick = ButtonCH1_R1_2Click
        end
        object EditCH1R2Volt1: TEdit
          Left = 58
          Top = 73
          Width = 60
          Height = 21
          TabOrder = 6
          Text = '0'
        end
        object EditCH1R2VoltAdc1: TEdit
          Left = 125
          Top = 73
          Width = 60
          Height = 21
          TabOrder = 7
          Text = '0'
        end
        object EditCH1R2Volt2: TEdit
          Left = 249
          Top = 74
          Width = 60
          Height = 21
          TabOrder = 8
          Text = '0'
        end
        object EditCH1R2VoltAdc2: TEdit
          Left = 318
          Top = 74
          Width = 60
          Height = 21
          TabOrder = 9
          Text = '0'
        end
        object Button2: TButton
          Tag = 2
          Left = 388
          Top = 106
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 10
          OnClick = ButtonCH1_R1_2Click
        end
        object EditCH1R3Volt1: TEdit
          Left = 58
          Top = 107
          Width = 60
          Height = 21
          TabOrder = 11
          Text = '0'
        end
        object EditCH1R3VoltAdc1: TEdit
          Left = 125
          Top = 107
          Width = 60
          Height = 21
          TabOrder = 12
          Text = '0'
        end
        object EditCH1R3Volt2: TEdit
          Left = 249
          Top = 108
          Width = 60
          Height = 21
          TabOrder = 13
          Text = '0'
        end
        object EditCH1R3VoltAdc2: TEdit
          Left = 318
          Top = 108
          Width = 60
          Height = 21
          TabOrder = 14
          Text = '0'
        end
        object Button3: TButton
          Tag = 3
          Left = 388
          Top = 140
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 15
          OnClick = ButtonCH1_R1_2Click
        end
        object EditCH1R4Volt1: TEdit
          Left = 58
          Top = 142
          Width = 60
          Height = 21
          TabOrder = 16
          Text = '0'
        end
        object EditCH1R4VoltAdc1: TEdit
          Left = 125
          Top = 141
          Width = 60
          Height = 21
          TabOrder = 17
          Text = '0'
        end
        object EditCH1R4Volt2: TEdit
          Left = 249
          Top = 142
          Width = 60
          Height = 21
          TabOrder = 18
          Text = '0'
        end
        object EditCH1R4VoltAdc2: TEdit
          Left = 318
          Top = 142
          Width = 60
          Height = 21
          TabOrder = 19
          Text = '0'
        end
        object Button10: TButton
          Tag = 4
          Left = 388
          Top = 175
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 20
          OnClick = ButtonCH1_R1_2Click
        end
        object EditCH1R5Volt1: TEdit
          Left = 58
          Top = 176
          Width = 60
          Height = 21
          TabOrder = 21
          Text = '0'
        end
        object EditCH1R5VoltAdc1: TEdit
          Left = 125
          Top = 176
          Width = 60
          Height = 21
          TabOrder = 22
          Text = '0'
        end
        object EditCH1R5Volt2: TEdit
          Left = 249
          Top = 176
          Width = 60
          Height = 21
          TabOrder = 23
          Text = '0'
        end
        object EditCH1R5VoltAdc2: TEdit
          Left = 318
          Top = 176
          Width = 60
          Height = 21
          TabOrder = 24
          Text = '0'
        end
        object Button41: TButton
          Tag = 5
          Left = 388
          Top = 209
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 25
          OnClick = ButtonCH1_R1_2Click
        end
        object EditCH1R6Volt1: TEdit
          Left = 58
          Top = 211
          Width = 60
          Height = 21
          TabOrder = 26
          Text = '0'
        end
        object EditCH1R6VoltAdc1: TEdit
          Left = 125
          Top = 210
          Width = 60
          Height = 21
          TabOrder = 27
          Text = '0'
        end
        object EditCH1R6Volt2: TEdit
          Left = 249
          Top = 210
          Width = 60
          Height = 21
          TabOrder = 28
          Text = '0'
        end
        object EditCH1R6VoltAdc2: TEdit
          Left = 318
          Top = 210
          Width = 60
          Height = 21
          TabOrder = 29
          Text = '0'
        end
        object Button42: TButton
          Tag = 6
          Left = 388
          Top = 243
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 30
          OnClick = ButtonCH1_R1_2Click
        end
        object EditCH1R7Volt1: TEdit
          Left = 58
          Top = 245
          Width = 60
          Height = 21
          TabOrder = 31
          Text = '0'
        end
        object EditCH1R7VoltAdc1: TEdit
          Left = 125
          Top = 244
          Width = 60
          Height = 21
          TabOrder = 32
          Text = '0'
        end
        object EditCH1R7Volt2: TEdit
          Left = 249
          Top = 244
          Width = 60
          Height = 21
          TabOrder = 33
          Text = '0'
        end
        object EditCH1R7VoltAdc2: TEdit
          Left = 318
          Top = 244
          Width = 60
          Height = 21
          TabOrder = 34
          Text = '0'
        end
        object Button43: TButton
          Tag = 7
          Left = 388
          Top = 278
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 35
          OnClick = ButtonCH1_R1_2Click
        end
        object EditCH1R8Volt1: TEdit
          Left = 58
          Top = 279
          Width = 60
          Height = 21
          TabOrder = 36
          Text = '0'
        end
        object EditCH1R8VoltAdc1: TEdit
          Left = 125
          Top = 279
          Width = 60
          Height = 21
          TabOrder = 37
          Text = '0'
        end
        object EditCH1R8Volt2: TEdit
          Left = 249
          Top = 279
          Width = 60
          Height = 21
          TabOrder = 38
          Text = '0'
        end
        object EditCH1R8VoltAdc2: TEdit
          Left = 318
          Top = 279
          Width = 60
          Height = 21
          TabOrder = 39
          Text = '0'
        end
        object ButtonCH1_R1_1: TButton
          Left = 193
          Top = 37
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 40
          OnClick = ButtonCH1_R1_1Click
        end
        object Button45: TButton
          Tag = 1
          Left = 193
          Top = 70
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 41
          OnClick = ButtonCH1_R1_1Click
        end
        object Button46: TButton
          Tag = 2
          Left = 193
          Top = 106
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 42
          OnClick = ButtonCH1_R1_1Click
        end
        object Button47: TButton
          Tag = 3
          Left = 193
          Top = 140
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 43
          OnClick = ButtonCH1_R1_1Click
        end
        object Button48: TButton
          Tag = 4
          Left = 193
          Top = 175
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 44
          OnClick = ButtonCH1_R1_1Click
        end
        object Button49: TButton
          Tag = 5
          Left = 193
          Top = 209
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 45
          OnClick = ButtonCH1_R1_1Click
        end
        object Button50: TButton
          Tag = 6
          Left = 193
          Top = 243
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 46
          OnClick = ButtonCH1_R1_1Click
        end
        object Button51: TButton
          Tag = 7
          Left = 193
          Top = 278
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 47
          OnClick = ButtonCH1_R1_1Click
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'CH2'#30005#21387
      ImageIndex = 5
      object GroupBox11: TGroupBox
        Left = 10
        Top = 15
        Width = 443
        Height = 321
        Caption = #31034#27874#22120'CH2'#30005#21387
        Color = 16313321
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object Label42: TLabel
          Left = 127
          Top = 21
          Width = 57
          Height = 13
          Caption = #38646#20301'ADC'#20540
        end
        object Label43: TLabel
          Left = 6
          Top = 48
          Width = 36
          Height = 13
          Caption = #177'13.8V'
        end
        object Label44: TLabel
          Left = 62
          Top = 20
          Width = 48
          Height = 13
          Caption = #38646#20301#30005#21387
        end
        object Label45: TLabel
          Left = 14
          Top = 21
          Width = 24
          Height = 13
          Caption = #37327#31243
        end
        object Label46: TLabel
          Left = 256
          Top = 21
          Width = 48
          Height = 13
          Caption = #28385#20301#30005#21387
        end
        object Label47: TLabel
          Left = 323
          Top = 21
          Width = 57
          Height = 13
          Caption = #28385#20301'ADC'#20540
        end
        object Label48: TLabel
          Left = 12
          Top = 84
          Width = 30
          Height = 13
          Caption = #177'6.4V'
        end
        object Label49: TLabel
          Left = 11
          Top = 119
          Width = 30
          Height = 13
          Caption = #177'3.2V'
        end
        object Label50: TLabel
          Left = 12
          Top = 150
          Width = 30
          Height = 13
          Caption = #177'1.6V'
        end
        object Label51: TLabel
          Left = 8
          Top = 184
          Width = 40
          Height = 13
          Caption = #177'800mV'
        end
        object Label52: TLabel
          Left = 8
          Top = 217
          Width = 40
          Height = 13
          Caption = #177'400mV'
        end
        object Label53: TLabel
          Left = 7
          Top = 252
          Width = 40
          Height = 13
          Caption = #177'200mV'
        end
        object Label54: TLabel
          Left = 7
          Top = 285
          Width = 40
          Height = 13
          Caption = #177'100mV'
        end
        object ButtonCH2_R1_2: TButton
          Left = 387
          Top = 39
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 0
          OnClick = ButtonCH2_R1_2Click
        end
        object EditCH2R1Volt1: TEdit
          Left = 54
          Top = 41
          Width = 60
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object EditCH2R1VoltAdc1: TEdit
          Left = 123
          Top = 41
          Width = 60
          Height = 21
          TabOrder = 2
          Text = '0'
        end
        object EditCH2R1Volt2: TEdit
          Left = 253
          Top = 41
          Width = 60
          Height = 21
          TabOrder = 3
          Text = '0'
        end
        object EditCH2R1VoltAdc2: TEdit
          Left = 319
          Top = 41
          Width = 60
          Height = 21
          TabOrder = 4
          Text = '0'
        end
        object Button52: TButton
          Tag = 1
          Left = 388
          Top = 72
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 5
          OnClick = ButtonCH2_R1_2Click
        end
        object EditCH2R2Volt1: TEdit
          Left = 54
          Top = 75
          Width = 60
          Height = 21
          TabOrder = 6
          Text = '0'
        end
        object EditCH2R2VoltAdc1: TEdit
          Left = 123
          Top = 75
          Width = 60
          Height = 21
          TabOrder = 7
          Text = '0'
        end
        object EditCH2R2Volt2: TEdit
          Left = 253
          Top = 75
          Width = 60
          Height = 21
          TabOrder = 8
          Text = '0'
        end
        object EditCH2R2VoltAdc2: TEdit
          Left = 319
          Top = 75
          Width = 60
          Height = 21
          TabOrder = 9
          Text = '0'
        end
        object Button53: TButton
          Tag = 2
          Left = 388
          Top = 106
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 10
          OnClick = ButtonCH2_R1_2Click
        end
        object EditCH2R3Volt1: TEdit
          Left = 54
          Top = 109
          Width = 60
          Height = 21
          TabOrder = 11
          Text = '0'
        end
        object EditCH2R3VoltAdc1: TEdit
          Left = 123
          Top = 109
          Width = 60
          Height = 21
          TabOrder = 12
          Text = '0'
        end
        object EditCH2R3Volt2: TEdit
          Left = 253
          Top = 109
          Width = 60
          Height = 21
          TabOrder = 13
          Text = '0'
        end
        object EditCH2R3VoltAdc2: TEdit
          Left = 319
          Top = 109
          Width = 60
          Height = 21
          TabOrder = 14
          Text = '0'
        end
        object Button54: TButton
          Tag = 3
          Left = 388
          Top = 140
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 15
          OnClick = ButtonCH2_R1_2Click
        end
        object EditCH2R4Volt1: TEdit
          Left = 54
          Top = 143
          Width = 60
          Height = 21
          TabOrder = 16
          Text = '0'
        end
        object EditCH2R4VoltAdc1: TEdit
          Left = 123
          Top = 143
          Width = 60
          Height = 21
          TabOrder = 17
          Text = '0'
        end
        object EditCH2R4Volt2: TEdit
          Left = 253
          Top = 143
          Width = 60
          Height = 21
          TabOrder = 18
          Text = '0'
        end
        object EditCH2R4VoltAdc2: TEdit
          Left = 319
          Top = 143
          Width = 60
          Height = 21
          TabOrder = 19
          Text = '0'
        end
        object Button55: TButton
          Tag = 4
          Left = 388
          Top = 175
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 20
          OnClick = ButtonCH2_R1_2Click
        end
        object EditCH2R5Volt1: TEdit
          Left = 54
          Top = 177
          Width = 60
          Height = 21
          TabOrder = 21
          Text = '0'
        end
        object EditCH2R5VoltAdc1: TEdit
          Left = 123
          Top = 177
          Width = 60
          Height = 21
          TabOrder = 22
          Text = '0'
        end
        object EditCH2R5Volt2: TEdit
          Left = 253
          Top = 177
          Width = 60
          Height = 21
          TabOrder = 23
          Text = '0'
        end
        object EditCH2R5VoltAdc2: TEdit
          Left = 319
          Top = 177
          Width = 60
          Height = 21
          TabOrder = 24
          Text = '0'
        end
        object Button56: TButton
          Tag = 5
          Left = 388
          Top = 209
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 25
          OnClick = ButtonCH2_R1_2Click
        end
        object EditCH2R6Volt1: TEdit
          Left = 54
          Top = 211
          Width = 60
          Height = 21
          TabOrder = 26
          Text = '0'
        end
        object EditCH2R6VoltAdc1: TEdit
          Left = 123
          Top = 211
          Width = 60
          Height = 21
          TabOrder = 27
          Text = '0'
        end
        object EditCH2R6Volt2: TEdit
          Left = 253
          Top = 211
          Width = 60
          Height = 21
          TabOrder = 28
          Text = '0'
        end
        object EditCH2R6VoltAdc2: TEdit
          Left = 319
          Top = 211
          Width = 60
          Height = 21
          TabOrder = 29
          Text = '0'
        end
        object Button57: TButton
          Tag = 6
          Left = 388
          Top = 243
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 30
          OnClick = ButtonCH2_R1_2Click
        end
        object EditCH2R7Volt1: TEdit
          Left = 54
          Top = 245
          Width = 60
          Height = 21
          TabOrder = 31
          Text = '0'
        end
        object EditCH2R7VoltAdc1: TEdit
          Left = 123
          Top = 245
          Width = 60
          Height = 21
          TabOrder = 32
          Text = '0'
        end
        object EditCH2R7Volt2: TEdit
          Left = 253
          Top = 245
          Width = 60
          Height = 21
          TabOrder = 33
          Text = '0'
        end
        object EditCH2R7VoltAdc2: TEdit
          Left = 319
          Top = 245
          Width = 60
          Height = 21
          TabOrder = 34
          Text = '0'
        end
        object Button58: TButton
          Tag = 7
          Left = 388
          Top = 278
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 35
          OnClick = ButtonCH2_R1_2Click
        end
        object EditCH2R8Volt1: TEdit
          Left = 54
          Top = 280
          Width = 60
          Height = 21
          TabOrder = 36
          Text = '0'
        end
        object EditCH2R8VoltAdc1: TEdit
          Left = 123
          Top = 280
          Width = 60
          Height = 21
          TabOrder = 37
          Text = '0'
        end
        object EditCH2R8Volt2: TEdit
          Left = 253
          Top = 280
          Width = 60
          Height = 21
          TabOrder = 38
          Text = '0'
        end
        object EditCH2R8VoltAdc2: TEdit
          Left = 319
          Top = 280
          Width = 60
          Height = 21
          TabOrder = 39
          Text = '0'
        end
        object ButtonCH2_R1_1: TButton
          Left = 193
          Top = 39
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 40
          OnClick = ButtonCH2_R1_1Click
        end
        object Button60: TButton
          Tag = 1
          Left = 193
          Top = 74
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 41
          OnClick = ButtonCH2_R1_1Click
        end
        object Button61: TButton
          Tag = 2
          Left = 193
          Top = 107
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 42
          OnClick = ButtonCH2_R1_1Click
        end
        object Button62: TButton
          Tag = 3
          Left = 193
          Top = 141
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 43
          OnClick = ButtonCH2_R1_1Click
        end
        object Button63: TButton
          Tag = 4
          Left = 193
          Top = 175
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 44
          OnClick = ButtonCH2_R1_1Click
        end
        object Button64: TButton
          Tag = 5
          Left = 193
          Top = 209
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 45
          OnClick = ButtonCH2_R1_1Click
        end
        object Button65: TButton
          Tag = 6
          Left = 193
          Top = 243
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 46
          OnClick = ButtonCH2_R1_1Click
        end
        object Button66: TButton
          Tag = 7
          Left = 193
          Top = 277
          Width = 44
          Height = 25
          Caption = #20889#20837
          TabOrder = 47
          OnClick = ButtonCH2_R1_1Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = '  '#39640#20391#30005#21387','#30005#27969'  '
      ImageIndex = 3
      object GroupBox7: TGroupBox
        Left = 16
        Top = 9
        Width = 433
        Height = 105
        Caption = #39640#20391#30005#21387
        Color = 14941437
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object Label7: TLabel
          Left = 21
          Top = 21
          Width = 62
          Height = 13
          Caption = #23454#27979#30005#21387'(V)'
        end
        object Label28: TLabel
          Left = 143
          Top = 22
          Width = 33
          Height = 13
          Caption = 'ADC'#20540
        end
        object Button4: TButton
          Left = 233
          Top = 36
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 0
          OnClick = Button4Click
        end
        object EditLoadVolt1: TEdit
          Left = 17
          Top = 40
          Width = 60
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object Button5: TButton
          Left = 233
          Top = 65
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 2
          OnClick = Button5Click
        end
        object EditLoadVolt2: TEdit
          Left = 17
          Top = 67
          Width = 60
          Height = 21
          TabOrder = 3
          Text = '10.0'
        end
        object EditLoadVoltAdc1: TEdit
          Left = 130
          Top = 40
          Width = 60
          Height = 21
          TabOrder = 4
          Text = '0'
        end
        object EditLoadVoltAdc2: TEdit
          Left = 130
          Top = 67
          Width = 60
          Height = 21
          TabOrder = 5
          Text = '0'
        end
      end
      object GroupBox8: TGroupBox
        Left = 16
        Top = 125
        Width = 433
        Height = 154
        Caption = #39640#20391#30005#27969#65288'120mA'#26723#65289
        Color = 16508902
        ParentBackground = False
        ParentColor = False
        TabOrder = 1
        object Label9: TLabel
          Left = 18
          Top = 18
          Width = 71
          Height = 13
          Caption = #23454#27979#30005#27969'(mA)'
        end
        object Label26: TLabel
          Left = 143
          Top = 19
          Width = 33
          Height = 13
          Caption = 'ADC'#20540
        end
        object Button6: TButton
          Left = 233
          Top = 34
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 0
          OnClick = Button6Click
        end
        object EditLoadCurrLow1: TEdit
          Left = 17
          Top = 37
          Width = 60
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object Button7: TButton
          Left = 233
          Top = 62
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 2
          OnClick = Button7Click
        end
        object EditLoadCurrLow2: TEdit
          Left = 17
          Top = 64
          Width = 60
          Height = 21
          TabOrder = 3
          Text = '10.0'
        end
        object Button30: TButton
          Left = 233
          Top = 90
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 4
          OnClick = Button30Click
        end
        object EditLoadCurrLow3: TEdit
          Left = 17
          Top = 91
          Width = 60
          Height = 21
          TabOrder = 5
          Text = '0'
        end
        object Button31: TButton
          Left = 233
          Top = 118
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 6
          OnClick = Button31Click
        end
        object EditLoadCurrLow4: TEdit
          Left = 17
          Top = 119
          Width = 60
          Height = 21
          TabOrder = 7
          Text = '10.0'
        end
        object EditLoadCurrLowAdc1: TEdit
          Left = 130
          Top = 37
          Width = 60
          Height = 21
          TabOrder = 8
          Text = '0'
        end
        object EditLoadCurrLowAdc2: TEdit
          Left = 130
          Top = 64
          Width = 60
          Height = 21
          TabOrder = 9
          Text = '0'
        end
        object EditLoadCurrLowAdc4: TEdit
          Left = 130
          Top = 119
          Width = 60
          Height = 21
          TabOrder = 10
          Text = '0'
        end
        object EditLoadCurrLowAdc3: TEdit
          Left = 130
          Top = 91
          Width = 60
          Height = 21
          TabOrder = 11
          Text = '0'
        end
      end
      object GroupBox9: TGroupBox
        Left = 16
        Top = 292
        Width = 433
        Height = 154
        Caption = #39640#20391#30005#27969#65288'1.2A'#26723#65289
        Color = 15463917
        ParentBackground = False
        ParentColor = False
        TabOrder = 2
        object Label29: TLabel
          Left = 18
          Top = 18
          Width = 71
          Height = 13
          Caption = #23454#27979#30005#27969'(mA)'
        end
        object Label30: TLabel
          Left = 143
          Top = 19
          Width = 33
          Height = 13
          Caption = 'ADC'#20540
        end
        object Button32: TButton
          Left = 232
          Top = 34
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 0
          OnClick = Button32Click
        end
        object EditLoadCurrHigh1: TEdit
          Left = 16
          Top = 38
          Width = 60
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object Button33: TButton
          Left = 232
          Top = 61
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 2
          OnClick = Button33Click
        end
        object EditLoadCurrHigh2: TEdit
          Left = 16
          Top = 65
          Width = 61
          Height = 21
          TabOrder = 3
          Text = '10.0'
        end
        object Button34: TButton
          Left = 232
          Top = 89
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 4
          OnClick = Button34Click
        end
        object Button35: TButton
          Left = 232
          Top = 117
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 5
          OnClick = Button35Click
        end
        object EditLoadCurrHigh4: TEdit
          Left = 16
          Top = 120
          Width = 61
          Height = 21
          TabOrder = 6
          Text = '10.0'
        end
        object EditLoadCurrHigh3: TEdit
          Left = 16
          Top = 92
          Width = 61
          Height = 21
          TabOrder = 7
          Text = '0'
        end
        object EditLoadCurrHighAdc1: TEdit
          Left = 130
          Top = 38
          Width = 60
          Height = 21
          TabOrder = 8
          Text = '0'
        end
        object EditLoadCurrHighAdc2: TEdit
          Left = 130
          Top = 65
          Width = 60
          Height = 21
          TabOrder = 9
          Text = '0'
        end
        object EditLoadCurrHighAdc3: TEdit
          Left = 130
          Top = 92
          Width = 60
          Height = 21
          TabOrder = 10
          Text = '0'
        end
        object EditLoadCurrHighAdc4: TEdit
          Left = 130
          Top = 119
          Width = 60
          Height = 21
          TabOrder = 11
          Text = '0'
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = ' TVCC '
      ImageIndex = 4
      object GroupBox4: TGroupBox
        Left = 15
        Top = 131
        Width = 434
        Height = 100
        Caption = 'TVCC'#26816#27979#30005#21387
        Color = 15790065
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object Label11: TLabel
          Left = 20
          Top = 19
          Width = 62
          Height = 13
          Caption = #23454#27979#30005#21387'(V)'
        end
        object Label4: TLabel
          Left = 133
          Top = 18
          Width = 33
          Height = 13
          Caption = 'ADC'#20540
        end
        object Button8: TButton
          Left = 209
          Top = 30
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 0
          OnClick = Button8Click
        end
        object EditTVCCVolt1: TEdit
          Left = 18
          Top = 34
          Width = 60
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object Button9: TButton
          Left = 209
          Top = 58
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 2
          OnClick = Button9Click
        end
        object EditTVCCVolt2: TEdit
          Left = 18
          Top = 61
          Width = 60
          Height = 21
          TabOrder = 3
          Text = '10.0'
        end
        object EditTVCCVoltAdc1: TEdit
          Left = 121
          Top = 35
          Width = 60
          Height = 21
          TabOrder = 4
          Text = '0'
        end
        object EditTVCCVoltAdc2: TEdit
          Left = 121
          Top = 61
          Width = 60
          Height = 21
          TabOrder = 5
          Text = '10.0'
        end
      end
      object GroupBox6: TGroupBox
        Left = 15
        Top = 251
        Width = 434
        Height = 150
        Caption = 'TVCC'#26816#27979#30005#27969'(mA)'
        Color = 14805247
        ParentBackground = False
        ParentColor = False
        TabOrder = 1
        object Label12: TLabel
          Left = 20
          Top = 17
          Width = 71
          Height = 13
          Caption = #23454#27979#30005#27969'(mA)'
        end
        object Label18: TLabel
          Left = 133
          Top = 17
          Width = 33
          Height = 13
          Caption = 'ADC'#20540
        end
        object Button28: TButton
          Left = 209
          Top = 30
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 0
          OnClick = Button28Click
        end
        object EditTVCCCurr1: TEdit
          Left = 20
          Top = 35
          Width = 60
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object Button29: TButton
          Left = 209
          Top = 58
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 2
          OnClick = Button29Click
        end
        object EditTVCCCurr2: TEdit
          Left = 20
          Top = 62
          Width = 60
          Height = 21
          TabOrder = 3
          Text = '10.0'
        end
        object Button36: TButton
          Left = 209
          Top = 86
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 4
          OnClick = Button36Click
        end
        object Button37: TButton
          Left = 209
          Top = 114
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 5
          OnClick = Button37Click
        end
        object EditTVCCCurr4: TEdit
          Left = 19
          Top = 116
          Width = 61
          Height = 21
          TabOrder = 6
          Text = '10.0'
        end
        object EditTVCCCurr3: TEdit
          Left = 20
          Top = 89
          Width = 60
          Height = 21
          TabOrder = 7
          Text = '0'
        end
        object EditTVCCCurrAdc1: TEdit
          Left = 122
          Top = 35
          Width = 60
          Height = 21
          TabOrder = 8
          Text = '10.0'
        end
        object EditTVCCCurrAdc2: TEdit
          Left = 122
          Top = 62
          Width = 60
          Height = 21
          TabOrder = 9
          Text = '10.0'
        end
        object EditTVCCCurrAdc3: TEdit
          Left = 122
          Top = 89
          Width = 60
          Height = 21
          TabOrder = 10
          Text = '10.0'
        end
        object EditTVCCCurrAdc4: TEdit
          Left = 122
          Top = 116
          Width = 60
          Height = 21
          TabOrder = 11
          Text = '10.0'
        end
      end
      object GroupBox1: TGroupBox
        Left = 17
        Top = 17
        Width = 432
        Height = 94
        Caption = 'TVCC'#35774#32622'(0-127)'#30005#21387
        Color = 15333609
        ParentBackground = False
        ParentColor = False
        TabOrder = 2
        object Label3: TLabel
          Left = 20
          Top = 3
          Width = 3
          Height = 13
        end
        object Label13: TLabel
          Left = 14
          Top = 36
          Width = 30
          Height = 13
          Caption = #31532'1'#28857
        end
        object Label14: TLabel
          Left = 15
          Top = 68
          Width = 30
          Height = 13
          Caption = #31532'2'#28857
        end
        object Label27: TLabel
          Left = 188
          Top = 14
          Width = 62
          Height = 13
          Caption = #23454#27979#30005#21387'(V)'
        end
        object Button15: TButton
          Left = 103
          Top = 29
          Width = 62
          Height = 25
          Caption = #35774#32622'TVCC'
          TabOrder = 0
          OnClick = Button15Click
        end
        object EditTVCC_Y1: TEdit
          Left = 188
          Top = 33
          Width = 60
          Height = 21
          TabOrder = 1
          Text = '1.26'
        end
        object ButtonWriteCalibTVCC: TButton
          Left = 285
          Top = 24
          Width = 64
          Height = 51
          Caption = #20889#20837
          TabOrder = 2
          OnClick = ButtonWriteCalibTVCCClick
        end
        object Button18: TButton
          Left = 103
          Top = 60
          Width = 62
          Height = 25
          Caption = #35774#32622'TVCC'
          TabOrder = 3
          OnClick = Button18Click
        end
        object EditTVCC_Y2: TEdit
          Left = 188
          Top = 61
          Width = 60
          Height = 21
          TabOrder = 4
          Text = '4.44'
        end
        object EditTVCC_X1: TEdit
          Left = 58
          Top = 33
          Width = 34
          Height = 21
          Enabled = False
          TabOrder = 5
          Text = '127'
        end
        object EditTVCC_X2: TEdit
          Left = 58
          Top = 63
          Width = 34
          Height = 21
          Enabled = False
          TabOrder = 6
          Text = '36'
        end
      end
    end
    object TabSheet1: TTabSheet
      Caption = ' DAC '
      object GroupBox2: TGroupBox
        Left = 16
        Top = 16
        Width = 432
        Height = 149
        Caption = 'DAC(0-4095)'#36755#20986#30005#21387'('#27491#36127'10V)'
        Color = 15397623
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object Label16: TLabel
          Left = 16
          Top = 60
          Width = 30
          Height = 13
          Caption = #31532'2'#28857
        end
        object Label17: TLabel
          Left = 16
          Top = 31
          Width = 30
          Height = 13
          Caption = #31532'1'#28857
        end
        object Label22: TLabel
          Left = 16
          Top = 120
          Width = 30
          Height = 13
          Caption = #31532'4'#28857
        end
        object Label23: TLabel
          Left = 17
          Top = 91
          Width = 30
          Height = 13
          Caption = #31532'3'#28857
        end
        object Label5: TLabel
          Left = 178
          Top = 11
          Width = 78
          Height = 13
          Caption = #23454#27979#30005#21387#65288'mV)'
        end
        object Button19: TButton
          Left = 103
          Top = 24
          Width = 62
          Height = 25
          Caption = #35774#32622'DAC'
          TabOrder = 0
          OnClick = Button19Click
        end
        object EditDACVolt_Y1: TEdit
          Left = 186
          Top = 29
          Width = 60
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object ButtonDACVolt: TButton
          Left = 285
          Top = 58
          Width = 64
          Height = 51
          Caption = #20889#20837
          TabOrder = 2
          OnClick = ButtonDACVoltClick
        end
        object Button21: TButton
          Left = 103
          Top = 56
          Width = 62
          Height = 25
          Caption = #35774#32622'DAC'
          TabOrder = 3
          OnClick = Button21Click
        end
        object EditDACVolt_Y2: TEdit
          Left = 186
          Top = 58
          Width = 60
          Height = 21
          TabOrder = 4
          Text = '0'
        end
        object EditDACVolt_X1: TEdit
          Left = 58
          Top = 28
          Width = 34
          Height = 21
          TabOrder = 5
          Text = '500'
        end
        object EditDACVolt_X2: TEdit
          Left = 58
          Top = 57
          Width = 34
          Height = 21
          TabOrder = 6
          Text = '1500'
        end
        object Button23: TButton
          Left = 103
          Top = 85
          Width = 62
          Height = 25
          Caption = #35774#32622'DAC'
          TabOrder = 7
          OnClick = Button23Click
        end
        object EditDACVolt_Y3: TEdit
          Left = 186
          Top = 88
          Width = 60
          Height = 21
          TabOrder = 8
          Text = '0'
        end
        object Button25: TButton
          Left = 103
          Top = 115
          Width = 62
          Height = 25
          Caption = #35774#32622'DAC'
          TabOrder = 9
          OnClick = Button25Click
        end
        object EditDACVolt_Y4: TEdit
          Left = 186
          Top = 118
          Width = 60
          Height = 21
          TabOrder = 10
          Text = '0'
        end
        object EditDACVolt_X3: TEdit
          Left = 58
          Top = 88
          Width = 34
          Height = 21
          TabOrder = 11
          Text = '2500'
        end
        object EditDACVolt_X4: TEdit
          Left = 58
          Top = 116
          Width = 34
          Height = 21
          TabOrder = 12
          Text = '3500'
        end
      end
      object GroupBox3: TGroupBox
        Left = 16
        Top = 180
        Width = 432
        Height = 156
        Caption = 'DAC(0-4095)'#36755#20986#30005#27969#65288'0-20mA)'
        Color = 16573668
        ParentBackground = False
        ParentColor = False
        TabOrder = 1
        object Label19: TLabel
          Left = 180
          Top = 14
          Width = 72
          Height = 13
          Caption = #23454#27979#30005#27969' (uA)'
        end
        object Label20: TLabel
          Left = 14
          Top = 68
          Width = 30
          Height = 13
          Caption = #31532'2'#28857
        end
        object Label21: TLabel
          Left = 15
          Top = 36
          Width = 30
          Height = 13
          Caption = #31532'1'#28857
        end
        object Label24: TLabel
          Left = 14
          Top = 130
          Width = 30
          Height = 13
          Caption = #31532'4'#28857
        end
        object Label25: TLabel
          Left = 14
          Top = 99
          Width = 30
          Height = 13
          Caption = #31532'3'#28857
        end
        object Button22: TButton
          Left = 103
          Top = 29
          Width = 62
          Height = 25
          Caption = #35774#32622'DAC'
          TabOrder = 0
          OnClick = Button22Click
        end
        object EditDACCurr_Y1: TEdit
          Left = 186
          Top = 34
          Width = 60
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object ButtonDACCurr: TButton
          Left = 281
          Top = 55
          Width = 64
          Height = 51
          Caption = #20889#20837
          TabOrder = 2
          OnClick = ButtonDACCurrClick
        end
        object Button24: TButton
          Left = 103
          Top = 62
          Width = 62
          Height = 25
          Caption = #35774#32622'DAC'
          TabOrder = 3
          OnClick = Button24Click
        end
        object EditDACCurr_Y2: TEdit
          Left = 186
          Top = 66
          Width = 60
          Height = 21
          TabOrder = 4
          Text = '0'
        end
        object EditDACCurr_X1: TEdit
          Left = 56
          Top = 32
          Width = 34
          Height = 21
          TabOrder = 5
          Text = '300'
        end
        object EditDACCurr_X2: TEdit
          Left = 55
          Top = 65
          Width = 34
          Height = 21
          TabOrder = 6
          Text = '800'
        end
        object Button26: TButton
          Left = 103
          Top = 94
          Width = 62
          Height = 25
          Caption = #35774#32622'DAC'
          TabOrder = 7
          OnClick = Button26Click
        end
        object EditDACCurr_Y3: TEdit
          Left = 186
          Top = 94
          Width = 60
          Height = 21
          TabOrder = 8
          Text = '0'
        end
        object Button27: TButton
          Left = 103
          Top = 124
          Width = 62
          Height = 25
          Caption = #35774#32622'DAC'
          TabOrder = 9
          OnClick = Button27Click
        end
        object EditDACCurr_Y4: TEdit
          Left = 186
          Top = 123
          Width = 60
          Height = 21
          TabOrder = 10
          Text = '0'
        end
        object EditDACCurr_X3: TEdit
          Left = 55
          Top = 96
          Width = 34
          Height = 21
          TabOrder = 11
          Text = '2500'
        end
        object EditDACCurr_X4: TEdit
          Left = 56
          Top = 126
          Width = 34
          Height = 21
          TabOrder = 12
          Text = '3500'
        end
      end
    end
    object NTC电阻: TTabSheet
      Caption = ' NTC'#30005#38459' '
      ImageIndex = 2
      object GroupBox5: TGroupBox
        Left = 12
        Top = 13
        Width = 439
        Height = 164
        Caption = 'NTC'#26631#23450#30005#38459'(K'#937')'
        Color = 16514276
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object Label10: TLabel
          Left = 12
          Top = 18
          Width = 98
          Height = 13
          Caption = #26631#23450#30005#38459#20540#65288'K'#937#65289
        end
        object Label15: TLabel
          Left = 136
          Top = 18
          Width = 33
          Height = 13
          Caption = 'ADC'#20540
        end
        object EditNTCRes1: TEdit
          Left = 21
          Top = 37
          Width = 60
          Height = 21
          TabOrder = 0
          Text = '0'
        end
        object Button16: TButton
          Left = 212
          Top = 35
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 1
          OnClick = Button16Click
        end
        object EditNTCRes2: TEdit
          Left = 21
          Top = 67
          Width = 60
          Height = 21
          TabOrder = 2
          Text = '0.02'
        end
        object Button11: TButton
          Left = 212
          Top = 66
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 3
          OnClick = Button11Click
        end
        object EditNTCRes3: TEdit
          Left = 21
          Top = 95
          Width = 60
          Height = 21
          TabOrder = 4
          Text = '10'
        end
        object Button39: TButton
          Left = 212
          Top = 94
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 5
          OnClick = Button39Click
        end
        object EditNTCRes4: TEdit
          Left = 21
          Top = 124
          Width = 60
          Height = 21
          TabOrder = 6
          Text = '100.0'
        end
        object Button40: TButton
          Left = 212
          Top = 121
          Width = 64
          Height = 25
          Caption = #20889#20837
          TabOrder = 7
          OnClick = Button40Click
        end
        object EditNTCResAdc1: TEdit
          Left = 124
          Top = 37
          Width = 60
          Height = 21
          TabOrder = 8
          Text = '0'
        end
        object EditNTCResAdc2: TEdit
          Left = 124
          Top = 67
          Width = 60
          Height = 21
          TabOrder = 9
          Text = '0.02'
        end
        object EditNTCResAdc3: TEdit
          Left = 124
          Top = 96
          Width = 60
          Height = 21
          TabOrder = 10
          Text = '10'
        end
        object EditNTCResAdc4: TEdit
          Left = 124
          Top = 123
          Width = 60
          Height = 21
          TabOrder = 11
          Text = '100.0'
        end
      end
    end
  end
  object Memo1: TMemo
    Left = 487
    Top = 32
    Width = 447
    Height = 458
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Button12: TButton
    Left = 487
    Top = 3
    Width = 91
    Height = 25
    Caption = #35835#26657#20934#21442#25968
    TabOrder = 2
    OnClick = Button12Click
  end
  object ButtonClear: TButton
    Left = 584
    Top = 3
    Width = 45
    Height = 25
    Caption = #28165#23631
    TabOrder = 3
    OnClick = ButtonClearClick
  end
  object ButtonSaveCalib: TButton
    Left = 665
    Top = 3
    Width = 64
    Height = 25
    Caption = #22791#20221
    TabOrder = 4
    OnClick = ButtonSaveCalibClick
  end
  object ButtonLoadCalib: TButton
    Left = 737
    Top = 3
    Width = 64
    Height = 25
    Caption = #24674#22797
    TabOrder = 5
    OnClick = ButtonLoadCalibClick
  end
  object CheckBoxCalibEnable: TCheckBox
    Left = 858
    Top = 8
    Width = 76
    Height = 17
    Caption = #26657#20934#20351#33021
    TabOrder = 6
    OnClick = CheckBoxCalibEnableClick
  end
  object OpenDialog1: TOpenDialog
    Left = 848
    Top = 40
  end
end
