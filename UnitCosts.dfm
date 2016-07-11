object FormCosts: TFormCosts
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1056#1072#1089#1093#1086#1076#1099
  ClientHeight = 384
  ClientWidth = 822
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnMouseDown = FormMouseDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 5
    Top = 361
    Width = 64
    Height = 13
    Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100
  end
  object Label2: TLabel
    Left = 284
    Top = 362
    Width = 26
    Height = 13
    Caption = #1044#1072#1090#1072
  end
  object Label3: TLabel
    Left = 495
    Top = 362
    Width = 53
    Height = 13
    Caption = #1057#1088#1077#1076#1089#1090#1074#1072':'
  end
  object Label4: TLabel
    Left = 552
    Top = 362
    Width = 6
    Height = 13
    Caption = '0'
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 34
    Width = 801
    Height = 319
    BorderStyle = bsNone
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clDefault
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [dgTitles, dgColLines, dgRowLines, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgMultiSelect, dgTitleHotTrack]
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDrawColumnCell = DBGrid1DrawColumnCell
    OnMouseDown = FormMouseDown
    Columns = <
      item
        Expanded = False
        FieldName = #1053#1072#1079#1074#1072#1085#1080#1077
        Width = 234
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1057#1090#1086#1080#1084#1086#1089#1090#1100
        Width = 92
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1055#1077#1088#1080#1086#1076#1080#1095#1085#1086#1089#1090#1100
        Width = 202
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1044#1072#1090#1072
        Width = 268
        Visible = True
      end>
  end
  object ComboBox1: TComboBox
    Left = 341
    Top = 5
    Width = 194
    Height = 22
    Style = csOwnerDrawFixed
    ItemIndex = 0
    TabOrder = 1
    Text = #1054#1076#1085#1086#1088#1072#1079#1086#1074#1099#1081
    Items.Strings = (
      #1054#1076#1085#1086#1088#1072#1079#1086#1074#1099#1081
      #1045#1078#1077#1084#1077#1089#1103#1095#1085#1099#1081
      #1045#1078#1077#1085#1077#1076#1077#1083#1100#1085#1099#1081)
  end
  object Button1: TButton
    Left = 746
    Top = 3
    Width = 65
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 5
    Top = 5
    Width = 233
    Height = 21
    TabOrder = 3
  end
  object Edit2: TEdit
    Left = 244
    Top = 5
    Width = 89
    Height = 21
    TabOrder = 4
    OnKeyPress = Edit2KeyPress
  end
  object DateTimePicker1: TDateTimePicker
    Left = 541
    Top = 5
    Width = 116
    Height = 21
    Hint = #1044#1072#1090#1072' '#1074#1099#1095#1080#1090#1072#1085#1080#1103' '#1088#1072#1089#1093#1086#1076#1072', '#1077#1089#1083#1080' '#1091#1089#1090#1072#1085#1086#1074#1083#1077#1085' '#1085#1077' '#1086#1076#1085#1086#1088#1072#1079#1086#1074#1099#1081' '#1088#1072#1089#1093#1086#1076'.'
    Date = 42313.653817106480000000
    Time = 42313.653817106480000000
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
  end
  object ComboBox2: TComboBox
    Left = 80
    Top = 359
    Width = 201
    Height = 21
    TabOrder = 6
    Text = #1042#1089#1077' '#1088#1072#1089#1093#1086#1076#1099
    OnChange = ComboBox2Change
    Items.Strings = (
      #1042#1089#1077' '#1088#1072#1089#1093#1086#1076#1099
      #1054#1076#1085#1086#1088#1072#1079#1086#1074#1099#1081
      #1045#1078#1077#1075#1086#1076#1085#1099#1081
      #1045#1078#1077#1084#1077#1089#1103#1095#1085#1099#1081
      #1045#1078#1077#1085#1077#1076#1077#1083#1100#1085#1099#1081)
  end
  object Button2: TButton
    Left = 731
    Top = 356
    Width = 75
    Height = 25
    Caption = #1054#1082
    TabOrder = 7
    OnClick = Button2Click
  end
  object Edit3: TEdit
    Left = 316
    Top = 359
    Width = 173
    Height = 21
    Hint = 
      #1044#1072#1090#1072' '#1091#1082#1072#1079#1099#1074#1072#1077#1090#1089#1103' '#1044#1044'.'#1052#1052'.'#1043#1043#1043#1043'. '#1045#1089#1083#1080' '#1087#1086#1083#1077' '#1086#1089#1090#1072#1074#1080#1090#1100' '#1087#1091#1089#1090#1099#1084', '#1090#1086' '#1076#1072#1090#1072' ' +
      #1073#1091#1076#1077#1090' '#1083#1102#1073#1086#1081'. '#1055#1086#1089#1083#1077' '#1074#1074#1086#1076#1072' '#1076#1072#1090#1099' '#1085#1072#1078#1084#1080#1090#1077' Enter.'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 8
    OnKeyPress = Edit3KeyPress
  end
  object Button3: TButton
    Left = 650
    Top = 356
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 9
    OnClick = Button3Click
  end
  object CheckBox1: TCheckBox
    Left = 664
    Top = 7
    Width = 76
    Height = 17
    Hint = 
      #1045#1089#1083#1080' '#1092#1083#1072#1078#1086#1082' '#1074#1082#1083#1102#1095#1077#1085', '#1090#1086' '#1076#1086#1073#1072#1074#1083#1077#1085#1099#1081' '#1088#1072#1089#1093#1086#1076' '#1073#1091#1076#1077#1090' '#1074#1099#1095#1080#1090#1072#1090#1100#1089#1103' '#1080#1089#1093#1086#1076 +
      #1103' '#1080#1079' '#1087#1077#1088#1080#1086#1076#1080#1095#1085#1086#1089#1090#1080' '#1088#1072#1089#1093#1086#1076#1072'.'
    Caption = #1042#1099#1095#1080#1090#1072#1090#1100'?'
    Checked = True
    ParentShowHint = False
    ShowHint = True
    State = cbChecked
    TabOrder = 10
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 757
    Top = 304
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = Form1.ADOConnection2
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM Costs')
    Left = 685
    Top = 304
  end
  object ADOQuery2: TADOQuery
    Active = True
    Connection = Form1.ADOConnection2
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM Costs')
    Left = 613
    Top = 304
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 552
    Top = 304
  end
end
