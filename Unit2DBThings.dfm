object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 427
  ClientWidth = 656
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 168
    Width = 332
    Height = 215
    Stretch = True
    OnMouseDown = FormMouseDown
  end
  object DescriptionLabel: TLabel
    Left = 462
    Top = 70
    Width = 57
    Height = 16
    Alignment = taCenter
    Caption = #1054#1087#1080#1089#1072#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object Label1: TLabel
    Left = 56
    Top = 330
    Width = 31
    Height = 13
    Caption = 'Label1'
    Visible = False
    OnContextPopup = ImageFaceContextPopup
  end
  object Label2: TLabel
    Left = 8
    Top = 51
    Width = 167
    Height = 16
    Caption = #1044#1072#1090#1072' '#1087#1086#1082#1091#1087#1082#1080'/'#1087#1088#1080#1086#1073#1088#1077#1090#1077#1085#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 225
    Top = 56
    Width = 60
    Height = 16
    Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object DescriptionMemo: TMemo
    Left = 352
    Top = 92
    Width = 286
    Height = 291
    TabOrder = 0
  end
  object ButtonSave: TButton
    Left = 482
    Top = 389
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 1
    OnClick = ButtonSaveClick
  end
  object Button2: TButton
    Left = 563
    Top = 389
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 2
    OnClick = Button2Click
  end
  object ThingName: TLabeledEdit
    Left = 129
    Top = 21
    Width = 428
    Height = 24
    Alignment = taCenter
    EditLabel.Width = 57
    EditLabel.Height = 16
    EditLabel.Caption = #1053#1072#1079#1074#1072#1085#1080#1077
    EditLabel.Font.Charset = DEFAULT_CHARSET
    EditLabel.Font.Color = clWindowText
    EditLabel.Font.Height = -13
    EditLabel.Font.Name = 'Tahoma'
    EditLabel.Font.Style = []
    EditLabel.ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object ThingShop: TLabeledEdit
    Left = 8
    Top = 122
    Width = 211
    Height = 24
    Alignment = taCenter
    EditLabel.Width = 115
    EditLabel.Height = 16
    EditLabel.Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1084#1072#1075#1072#1079#1080#1085#1072
    EditLabel.Font.Charset = DEFAULT_CHARSET
    EditLabel.Font.Color = clWindowText
    EditLabel.Font.Height = -13
    EditLabel.Font.Name = 'Tahoma'
    EditLabel.Font.Style = []
    EditLabel.ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object ThingCost: TLabeledEdit
    Left = 225
    Top = 122
    Width = 115
    Height = 24
    Alignment = taCenter
    EditLabel.Width = 62
    EditLabel.Height = 16
    EditLabel.Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
    EditLabel.Font.Charset = DEFAULT_CHARSET
    EditLabel.Font.Color = clWindowText
    EditLabel.Font.Height = -13
    EditLabel.Font.Name = 'Tahoma'
    EditLabel.Font.Style = []
    EditLabel.ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnKeyPress = ThingCostKeyPress
  end
  object Button3: TButton
    Left = 247
    Top = 389
    Width = 93
    Height = 25
    Hint = #1044#1086#1075#1088#1091#1079#1080#1090#1100' '#1092#1086#1090#1086#1075#1088#1072#1092#1080#1080
    Caption = #1054#1073#1079#1086#1088'...'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
    OnClick = Button3Click
  end
  object ThingDOB: TDateTimePicker
    Left = 8
    Top = 73
    Width = 163
    Height = 24
    Date = 42307.746046192130000000
    Time = 42307.746046192130000000
    ParentShowHint = False
    ShowHint = True
    TabOrder = 7
  end
  object ButtonClear: TButton
    Left = 159
    Top = 389
    Width = 82
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 8
    OnClick = ButtonClearClick
  end
  object CheckBox1: TCheckBox
    Left = 409
    Top = 389
    Width = 67
    Height = 17
    Hint = #1042#1099#1095#1077#1089#1090#1100' '#1089#1090#1086#1080#1084#1086#1089#1090#1100' '#1076#1072#1085#1085#1086#1081' '#1074#1077#1097#1080' '#1080#1079' '#1076#1086#1093#1086#1076#1086#1074
    Caption = #1042#1099#1095#1077#1089#1090#1100
    Checked = True
    ParentShowHint = False
    ShowHint = True
    State = cbChecked
    TabOrder = 9
  end
  object ThingCategory: TComboBox
    Left = 177
    Top = 75
    Width = 163
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    PopupMenu = PopupMenu2
    TabOrder = 10
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Options = [ofReadOnly, ofHideReadOnly, ofEnableSizing]
    Left = 88
    Top = 344
  end
  object PopupMenu1: TPopupMenu
    Left = 24
    Top = 344
    object FaceImage: TMenuItem
      Caption = #1057#1076#1077#1083#1072#1090#1100' '#1083#1080#1094#1077#1074#1099#1084
      OnClick = FaceImageClick
    end
  end
  object MainMenu1: TMainMenu
    Left = 88
    Top = 280
    object MenuAdd: TMenuItem
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      object MenuAddThing: TMenuItem
        Caption = #1042#1077#1097#1100
      end
      object NewCategory: TMenuItem
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1102
        OnClick = NewCategoryClick
      end
    end
    object MenuResource: TMenuItem
      Caption = #1056#1077#1089#1091#1088#1089#1099
      object N2: TMenuItem
        Caption = #1044#1086#1093#1086#1076#1099
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1056#1072#1089#1093#1086#1076#1099
        OnClick = N3Click
      end
      object Calc: TMenuItem
        Caption = #1056#1072#1089#1095#1077#1090#1099
        OnClick = CalcClick
      end
    end
    object N1: TMenuItem
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
      object MenuSelect: TMenuItem
        Caption = #1042#1099#1076#1077#1083#1080#1090#1100
      end
      object MenuWSelect: TMenuItem
        Caption = #1057' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1084#1080':'
        Enabled = False
      end
      object MenuDelete: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100
        Enabled = False
      end
    end
    object MenuOptions: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      OnClick = MenuOptionsClick
    end
    object MenuHelp: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      OnClick = MenuHelpClick
    end
    object MenuExit: TMenuItem
      Caption = #1042#1099#1093#1086#1076
      OnClick = MenuExitClick
    end
  end
  object PopupMenu2: TPopupMenu
    Left = 24
    Top = 280
  end
end
