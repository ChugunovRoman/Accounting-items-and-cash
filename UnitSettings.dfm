object Form4: TForm4
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 273
  ClientWidth = 632
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label12: TLabel
    Left = 8
    Top = 242
    Width = 169
    Height = 13
    Caption = #1040#1074#1090#1086#1088' '#1087#1088#1086#1075#1088#1072#1084#1084#1099': '#1063#1091#1075#1091#1085#1086#1074' '#1056#1086#1084#1072#1085
  end
  object Label13: TLabel
    Left = 8
    Top = 256
    Width = 141
    Height = 13
    Caption = #1042#1077#1088#1089#1080#1103' '#1087#1088#1086#1075#1088#1072#1084#1084#1099': Beta 1.0'
  end
  object Label14: TLabel
    Left = 233
    Top = 256
    Width = 92
    Height = 13
    Caption = #1044#1079#1077#1088#1078#1080#1085#1089#1082' 2015'#1075'.'
  end
  object Button1: TButton
    Left = 543
    Top = 244
    Width = 75
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object TabControl1: TTabControl
    Left = 3
    Top = 2
    Width = 616
    Height = 239
    TabOrder = 1
    Tabs.Strings = (
      #1057#1090#1080#1083#1100
      #1056#1072#1079#1085#1086#1077
      #1044#1072#1085#1085#1099#1077)
    TabIndex = 0
    OnChange = TabControl1Change
    object GroupBox6: TGroupBox
      Left = 271
      Top = 33
      Width = 332
      Height = 192
      Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1080
      TabOrder = 5
      object Label15: TLabel
        Left = 205
        Top = 19
        Width = 113
        Height = 26
        Alignment = taCenter
        Caption = #1059#1076#1072#1083#1077#1085#1080#1077' '#1074#1099#1073#1088#1072#1085#1085#1099#1093' '#1082#1072#1090#1077#1075#1086#1088#1080#1081
        WordWrap = True
      end
      object CheckListBox1: TCheckListBox
        Left = 17
        Top = 19
        Width = 181
        Height = 158
        ItemHeight = 13
        TabOrder = 0
      end
      object Button8: TButton
        Left = 224
        Top = 55
        Width = 80
        Height = 25
        Caption = #1059#1076#1072#1083#1080#1090#1100
        TabOrder = 1
        OnClick = Button8Click
      end
    end
    object GroupBox5: TGroupBox
      Left = 3
      Top = 33
      Width = 262
      Height = 92
      Caption = #1059#1076#1072#1083#1077#1085#1080#1077' '#1076#1072#1085#1085#1099#1093
      TabOrder = 4
      object Button6: TButton
        Left = 162
        Top = 17
        Width = 87
        Height = 25
        Caption = #1059#1076#1072#1083#1080#1090#1100
        TabOrder = 0
        OnClick = Button6Click
      end
      object ComboBox4: TComboBox
        Left = 12
        Top = 19
        Width = 145
        Height = 22
        Style = csOwnerDrawFixed
        ItemIndex = 0
        TabOrder = 1
        Text = #1042#1077#1097#1080
        Items.Strings = (
          #1042#1077#1097#1080
          #1056#1072#1089#1093#1086#1076#1099
          #1044#1086#1093#1086#1076#1099)
      end
      object Button7: TButton
        Left = 12
        Top = 47
        Width = 145
        Height = 25
        Caption = #1057#1090#1077#1088#1077#1090#1100' '#1074#1089#1077' '#1076#1072#1085#1085#1099#1077
        TabOrder = 2
        OnClick = Button7Click
      end
    end
    object GroupBox1: TGroupBox
      Left = 8
      Top = 32
      Width = 161
      Height = 81
      Caption = #1057#1082#1086#1088#1086#1089#1090#1100' '#1087#1088#1086#1082#1088#1091#1090#1082#1080' '#1074#1077#1097#1077#1081
      TabOrder = 0
      object Label2: TLabel
        Left = 8
        Top = 62
        Width = 43
        Height = 13
        Caption = #1041#1099#1089#1090#1088#1077#1077
      end
      object Label3: TLabel
        Left = 96
        Top = 62
        Width = 57
        Height = 13
        Caption = #1052#1077#1076#1083#1077#1085#1085#1077#1081
      end
      object TrackBar1: TTrackBar
        Left = 16
        Top = 19
        Width = 112
        Height = 45
        Max = 7
        Position = 3
        TabOrder = 0
        TickMarks = tmBoth
      end
    end
    object GroupBox4: TGroupBox
      Left = 242
      Top = 32
      Width = 359
      Height = 193
      Caption = #1062#1074#1077#1090#1072
      TabOrder = 3
      object Label9: TLabel
        Left = 16
        Top = 16
        Width = 143
        Height = 13
        Caption = #1062#1074#1077#1090' '#1074#1099#1076#1077#1083#1080#1090#1077#1083#1100#1085#1086#1081' '#1088#1072#1084#1082#1080
      end
      object Label8: TLabel
        Left = 16
        Top = 38
        Width = 153
        Height = 13
        Caption = #1062#1074#1077#1090' '#1090#1077#1082#1089#1090#1072' '#1074' '#1085#1072#1079#1074#1072#1085#1080#1080' '#1074#1077#1097#1080
      end
      object Shape1: TShape
        Left = 173
        Top = 38
        Width = 16
        Height = 16
      end
      object Label10: TLabel
        Left = 16
        Top = 62
        Width = 135
        Height = 13
        Caption = #1062#1074#1077#1090' '#1092#1086#1085#1072' '#1085#1072#1079#1074#1072#1085#1080#1103' '#1074#1077#1097#1080
      end
      object Shape2: TShape
        Left = 156
        Top = 62
        Width = 16
        Height = 16
      end
      object Label11: TLabel
        Left = 15
        Top = 85
        Width = 177
        Height = 13
        Caption = #1062#1074#1077#1090' '#1092#1086#1085#1072' '#1087#1088#1080' '#1085#1072#1074#1077#1076#1077#1085#1080#1080' '#1082#1091#1088#1089#1086#1088#1072
      end
      object Shape3: TShape
        Left = 197
        Top = 85
        Width = 16
        Height = 16
      end
      object ComboBox3: TComboBox
        Left = 165
        Top = 13
        Width = 148
        Height = 21
        ItemIndex = 0
        TabOrder = 0
        Text = #1057#1074#1077#1090#1083#1086'-'#1057#1080#1085#1080#1081
        Items.Strings = (
          #1057#1074#1077#1090#1083#1086'-'#1057#1080#1085#1080#1081
          #1057#1080#1085#1080#1081
          #1043#1086#1083#1091#1073#1086#1081
          #1053#1077#1073#1077#1089#1085#1099#1081
          #1060#1080#1086#1083#1077#1090#1086#1074#1099#1081
          #1056#1086#1079#1086#1074#1099#1081
          #1057#1077#1088#1099#1081
          #1063#1077#1088#1085#1099#1081
          #1041#1077#1083#1099#1081
          #1050#1088#1072#1089#1085#1099#1081
          #1057#1074#1077#1090#1083#1086'-'#1050#1088#1072#1089#1085#1099#1081
          #1054#1088#1072#1085#1078#1077#1074#1099#1081
          #1046#1077#1083#1090#1099#1081
          #1057#1074#1077#1090#1083#1086'-'#1047#1077#1083#1077#1085#1085#1099#1081
          #1047#1077#1083#1077#1085#1099#1081)
      end
      object Button2: TButton
        Left = 195
        Top = 36
        Width = 62
        Height = 20
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100
        TabOrder = 1
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 178
        Top = 60
        Width = 62
        Height = 20
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100
        TabOrder = 2
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 219
        Top = 83
        Width = 62
        Height = 20
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100
        TabOrder = 3
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 259
        Top = 160
        Width = 91
        Height = 25
        Hint = #1057#1073#1088#1072#1089#1099#1074#1072#1077#1090' '#1094#1074#1077#1090#1072' '#1087#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102
        Caption = #1055#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnClick = Button5Click
      end
    end
    object GroupBox3: TGroupBox
      Left = 3
      Top = 32
      Width = 233
      Height = 64
      Caption = #1057#1082#1080#1085
      TabOrder = 1
      object Label7: TLabel
        Left = 16
        Top = 16
        Width = 156
        Height = 13
        Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1089#1082#1080#1085' '#1076#1083#1103' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
      end
      object ComboBox2: TComboBox
        Left = 16
        Top = 35
        Width = 209
        Height = 21
        TabOrder = 0
        OnChange = ComboBox2Change
      end
    end
    object RadioGroup1: TRadioGroup
      Left = 175
      Top = 32
      Width = 130
      Height = 81
      Caption = #1056#1072#1079#1084#1077#1088' '#1080#1082#1086#1085#1086#1082' '#1074#1077#1097#1077#1081
      ItemIndex = 2
      Items.Strings = (
        #1052#1072#1083#1077#1085#1100#1082#1080#1077
        #1057#1088#1077#1076#1085#1080#1077
        #1041#1086#1083#1100#1096#1080#1077)
      TabOrder = 2
    end
  end
  object ColorDialog1: TColorDialog
    Left = 48
    Top = 184
  end
  object ADOQuery1: TADOQuery
    Connection = Form1.ADOConnection2
    Parameters = <>
    Left = 440
    Top = 240
  end
  object ADOQuery2: TADOQuery
    Connection = Form1.ADOConnection2
    Parameters = <>
    Left = 472
    Top = 240
  end
end
