object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1059#1095#1077#1090' '#1076#1077#1085#1077#1078#1085#1099#1093' '#1089#1088#1077#1076#1089#1090#1074' '#1080' '#1074#1077#1097#1077#1081
  ClientHeight = 430
  ClientWidth = 1167
  Color = clGradientInactiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = Form2.MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 512
    Top = 2
    Width = 172
    Height = 19
    Caption = #1059#1095#1077#1090' '#1076#1077#1085#1077#1078#1085#1099#1093' '#1089#1088#1077#1076#1089#1090#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
    OnContextPopup = Label7ContextPopup
    OnMouseDown = FormMouseDown
  end
  object Label2: TLabel
    Left = 179
    Top = 168
    Width = 31
    Height = 13
    Caption = 'Label2'
    Color = clGradientInactiveCaption
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    Transparent = True
    StyleElements = [seClient, seBorder]
    OnMouseDown = FormMouseDown
  end
  object Label3: TLabel
    Left = 736
    Top = 168
    Width = 62
    Height = 13
    Caption = #1057#1088#1077#1076#1089#1090#1074#1072': 0'
    Color = clGradientInactiveCaption
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Touch.ParentTabletOptions = False
    Touch.TabletOptions = [toPressAndHold]
    Transparent = True
    StyleElements = [seClient, seBorder]
    OnMouseDown = FormMouseDown
  end
  object ScrollBox1: TScrollBox
    Left = 1
    Top = 22
    Width = 1230
    Height = 523
    BorderStyle = bsNone
    Color = clWhite
    ParentColor = False
    TabOrder = 0
    OnMouseDown = FormMouseDown
    OnMouseWheel = ScrollBox1MouseWheel
    object DBGrid1: TDBGrid
      Left = 430
      Top = 259
      Width = 695
      Height = 137
      DataSource = DataSource1
      Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      Visible = False
    end
  end
  object ComboBox1: TComboBox
    Left = 1
    Top = 0
    Width = 177
    Height = 21
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 1
    Text = #1042#1089#1077' '#1082#1072#1090#1077#1075#1086#1088#1080#1080
    OnChange = ComboBox1Change
    Items.Strings = (
      #1042#1089#1077' '#1082#1072#1090#1077#1075#1086#1088#1080#1080)
  end
  object Button1: TButton
    Left = 184
    Top = 1
    Width = 65
    Height = 20
    Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1086#1074#1091#1102' '#1074#1077#1097#1100
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    Visible = False
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 255
    Top = 1
    Width = 122
    Height = 20
    Caption = #1042#1099#1076#1077#1083#1080#1090#1100' '#1085#1077#1089#1082#1086#1083#1100#1082#1086
    TabOrder = 3
    Visible = False
    OnClick = Button2Click
  end
  object ButtonDelete: TButton
    Left = 383
    Top = 1
    Width = 66
    Height = 20
    Caption = #1091#1076#1072#1083#1080#1090#1100
    TabOrder = 4
    Visible = False
    OnClick = ButtonDeleteClick
  end
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source=ODBS_' +
      '5;'
    KeepConnection = False
    LoginPrompt = False
    Provider = 'MSDASQL.1'
    Left = 8
    Top = 344
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection2
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM things;')
    Left = 8
    Top = 288
  end
  object PopupMenu1: TPopupMenu
    Left = 8
    Top = 184
    object Delete: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnClick = DeleteClick
    end
  end
  object ADOConnection2: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\'#1059#1095#1077#1073#1072'\C++ Projec' +
      't\DB Things\Win32\Release\DBThings.mdb;Persist Security Info=Fal' +
      'se'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 8
    Top = 400
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 8
    Top = 240
  end
  object ADOQuery2: TADOQuery
    Connection = ADOConnection2
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM things;')
    Left = 8
    Top = 128
  end
end
