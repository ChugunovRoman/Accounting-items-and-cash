object FormRes: TFormRes
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1076#1086#1093#1086#1076#1072#1084#1080' '#1080' '#1088#1072#1089#1093#1086#1076#1072#1084#1080
  ClientHeight = 363
  ClientWidth = 886
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
  OnMouseDown = FormMouseDown
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object TabControl1: TTabControl
    Left = 0
    Top = 0
    Width = 881
    Height = 513
    TabOrder = 0
    Tabs.Strings = (
      #1044#1086#1093#1086#1076#1099
      #1056#1072#1089#1093#1086#1076#1099
      #1056#1072#1089#1095#1077#1090#1099)
    TabIndex = 0
    OnChange = TabControl1Change
    object GroupBox2: TGroupBox
      Left = 3
      Top = 23
      Width = 878
      Height = 298
      TabOrder = 0
      object Button1: TButton
        Left = 712
        Top = 8
        Width = 75
        Height = 25
        Caption = #1059#1076#1072#1083#1080#1090#1100
        TabOrder = 0
        OnClick = Button1Click
      end
      object ButtonAdd: TButton
        Left = 631
        Top = 8
        Width = 75
        Height = 25
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100
        TabOrder = 1
        OnClick = ButtonAddClick
      end
      object ButtonOk: TButton
        Left = 793
        Top = 8
        Width = 75
        Height = 25
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        TabOrder = 2
        OnClick = ButtonOkClick
      end
      object ComboBox1: TComboBox
        Left = 360
        Top = 10
        Width = 131
        Height = 21
        PopupMenu = Form2.PopupMenu2
        TabOrder = 3
        Text = #1045#1078#1077#1084#1077#1089#1103#1095#1085#1099#1081
        OnChange = ComboBox1Change
        OnKeyPress = ComboBox1KeyPress
        Items.Strings = (
          #1045#1078#1077#1084#1077#1089#1103#1095#1085#1099#1081
          #1045#1078#1077#1085#1077#1076#1077#1083#1100#1085#1099#1081)
      end
      object ComboBox2: TComboBox
        Left = 497
        Top = 10
        Width = 128
        Height = 21
        TabOrder = 4
      end
      object DBGrid1: TDBGrid
        Left = 10
        Top = 39
        Width = 615
        Height = 255
        BorderStyle = bsNone
        DataSource = DataSource1
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [dgTitles, dgColLines, dgRowLines, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgMultiSelect, dgTitleHotTrack]
        ParentFont = False
        TabOrder = 5
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnMouseDown = FormMouseDown
        Columns = <
          item
            Expanded = False
            FieldName = #1053#1072#1079#1074#1072#1085#1080#1077
            Width = 233
            Visible = True
          end
          item
            Expanded = False
            FieldName = #1057#1090#1086#1080#1084#1086#1089#1090#1100
            Width = 113
            Visible = True
          end
          item
            Expanded = False
            FieldName = #1055#1077#1088#1080#1086#1076#1080#1095#1085#1086#1089#1090#1100
            Width = 139
            Visible = True
          end
          item
            Expanded = False
            FieldName = #1044#1072#1090#1072'/'#1044#1077#1085#1100
            Width = 110
            Visible = True
          end>
      end
      object Edit1: TEdit
        Left = 250
        Top = 10
        Width = 103
        Height = 21
        Hint = #1053#1072#1078#1084#1080#1090#1077' Enter, '#1095#1090#1086#1073#1099' '#1089#1086#1093#1088#1072#1085#1080#1090#1100' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1074#1099#1073#1088#1072#1085#1085#1086#1081' '#1079#1072#1087#1080#1089#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 6
        OnKeyPress = Edit1KeyPress
      end
      object GroupBox1: TGroupBox
        Left = 631
        Top = 39
        Width = 237
        Height = 255
        Caption = #1055#1086#1076#1089#1095#1077#1090#1099
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        OnMouseDown = FormMouseDown
        object Label1: TLabel
          Left = 16
          Top = 16
          Width = 53
          Height = 13
          Caption = #1057#1088#1077#1076#1089#1090#1074#1072':'
        end
        object Label3: TLabel
          Left = 74
          Top = 16
          Width = 6
          Height = 13
          Caption = '0'
        end
        object Label4: TLabel
          Left = 9
          Top = 38
          Width = 48
          Height = 13
          Caption = #1048#1079#1084#1077#1085#1080#1090#1100
        end
        object Label5: TLabel
          Left = 16
          Top = 101
          Width = 119
          Height = 13
          Hint = #1056#1072#1089#1093#1086#1076#1099' '#1079#1072' '#1090#1077#1082#1091#1097#1080#1081' '#1084#1077#1089#1103#1094
          Caption = #1045#1078#1077#1084#1077#1089#1103#1095#1085#1099#1077' '#1088#1072#1089#1093#1086#1076#1099':'
          ParentShowHint = False
          ShowHint = True
        end
        object Label6: TLabel
          Left = 140
          Top = 101
          Width = 6
          Height = 13
          Caption = '0'
        end
        object Label7: TLabel
          Left = 16
          Top = 118
          Width = 127
          Height = 13
          Hint = #1056#1072#1089#1093#1086#1076#1099' '#1079#1072' '#1090#1077#1082#1091#1097#1091#1102' '#1085#1077#1076#1077#1083#1102
          Caption = #1045#1078#1077#1085#1077#1076#1077#1083#1100#1085#1099#1077' '#1088#1072#1089#1093#1086#1076#1099':'
          ParentShowHint = False
          ShowHint = True
        end
        object Label8: TLabel
          Left = 147
          Top = 118
          Width = 6
          Height = 13
          Caption = '0'
        end
        object Label10: TLabel
          Left = 99
          Top = 67
          Width = 6
          Height = 13
          Caption = '0'
        end
        object Label11: TLabel
          Left = 16
          Top = 84
          Width = 90
          Height = 13
          Hint = #1042#1089#1077' '#1076#1086#1093#1086#1076#1099' '#1079#1072' '#1085#1077#1076#1077#1083#1102
          Caption = #1044#1086#1093#1076#1099' '#1074' '#1085#1077#1076#1077#1083#1102':'
          ParentShowHint = False
          ShowHint = True
        end
        object Label12: TLabel
          Left = 110
          Top = 84
          Width = 6
          Height = 13
          Caption = '0'
        end
        object Label9: TLabel
          Left = 16
          Top = 67
          Width = 79
          Height = 13
          Hint = #1042#1089#1077' '#1076#1086#1093#1086#1076#1099' '#1079#1072' '#1090#1077#1082#1091#1097#1077#1081' '#1084#1077#1089#1103#1094
          Caption = #1044#1086#1093#1076#1099' '#1074' '#1084#1077#1089#1103#1094':'
          ParentShowHint = False
          ShowHint = True
        end
        object Label13: TLabel
          Left = 16
          Top = 136
          Width = 126
          Height = 13
          Hint = #1042#1089#1077' '#1088#1072#1089#1093#1086#1076#1099' '#1079#1072' '#1084#1077#1089#1103#1094', '#1074#1082#1083#1102#1095#1072#1103' '#1080' '#1086#1076#1080#1085#1086#1095#1085#1099#1077
          Caption = #1054#1073#1097#1080#1077' '#1088#1072#1089#1093#1086#1076#1099' '#1074' '#1084#1077#1089#1103#1094':'
          ParentShowHint = False
          ShowHint = True
        end
        object Label14: TLabel
          Left = 146
          Top = 136
          Width = 6
          Height = 13
          Caption = '0'
        end
        object Label15: TLabel
          Left = 15
          Top = 153
          Width = 137
          Height = 13
          Hint = #1042#1089#1077' '#1088#1072#1089#1093#1086#1076#1099' '#1079#1072' '#1085#1077#1076#1077#1083#1102', '#1074#1082#1083#1102#1095#1072#1103' '#1080' '#1086#1076#1080#1085#1086#1095#1085#1099#1077
          Caption = #1054#1073#1097#1080#1077' '#1088#1072#1089#1093#1086#1076#1099' '#1074' '#1085#1077#1076#1077#1083#1102':'
          ParentShowHint = False
          ShowHint = True
        end
        object Label16: TLabel
          Left = 158
          Top = 153
          Width = 6
          Height = 13
          Caption = '0'
        end
        object Edit2: TEdit
          Left = 59
          Top = 35
          Width = 121
          Height = 21
          TabOrder = 0
          Text = '0'
          OnKeyPress = Edit2KeyPress
        end
        object Button3: TButton
          Left = 186
          Top = 33
          Width = 25
          Height = 25
          Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1082' '#1077#1078#1077#1084#1077#1089#1103#1095#1085#1086#1081' '#1087#1088#1080#1073#1099#1083#1080
          Caption = '+'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = Button3Click
        end
        object Button2: TButton
          Left = 209
          Top = 33
          Width = 25
          Height = 25
          Hint = #1042#1099#1095#1080#1089#1090#1100' '#1080#1079' '#1077#1078#1077#1084#1077#1089#1103#1095#1085#1086#1081' '#1087#1088#1080#1073#1099#1083#1080
          Caption = '-'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
          OnClick = Button2Click
        end
      end
      object EditName: TEdit
        Left = 10
        Top = 10
        Width = 234
        Height = 21
        TabOrder = 8
      end
    end
    object GroupBox3: TGroupBox
      Left = 3
      Top = 23
      Width = 878
      Height = 487
      Color = clBtnHighlight
      ParentBackground = False
      ParentColor = False
      TabOrder = 1
      Visible = False
      object Label2: TLabel
        Left = 465
        Top = 8
        Width = 89
        Height = 13
        Caption = #1056#1072#1089#1093#1086#1076#1099' '#1079#1072' '#1084#1077#1089#1103#1094
      end
      object Chart1: TChart
        Left = 3
        Top = 3
        Width = 451
        Height = 310
        Border.EndStyle = esRound
        Border.JoinStyle = jsBevel
        Border.SmallDots = True
        BorderRound = 1
        Legend.Alignment = laBottom
        Legend.Brush.Color = clWhite
        Legend.Frame.Visible = False
        Legend.ResizeChart = False
        Legend.Shadow.Visible = False
        Legend.Symbol.Continuous = True
        Legend.VertSpacing = -1
        MarginBottom = 0
        MarginLeft = 0
        MarginRight = 0
        MarginTop = 0
        Title.CustomPosition = True
        Title.Left = 150
        Title.Text.Strings = (
          #1050#1088#1091#1075#1086#1074#1072#1103' '#1076#1080#1072#1075#1088#1072#1084#1084#1072)
        Title.Top = 10
        Chart3DPercent = 20
        Shadow.Visible = False
        View3DOptions.Elevation = 315
        View3DOptions.FontZoom = 95
        View3DOptions.Orthogonal = False
        View3DOptions.Perspective = 0
        View3DOptions.Rotation = 360
        View3DWalls = False
        Zoom.Animated = True
        BevelOuter = bvNone
        TabOrder = 0
        PrintMargins = (
          15
          9
          15
          9)
        ColorPaletteIndex = 13
        object Series1: TPieSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.ShapeStyle = fosRoundRectangle
          Marks.Style = smsValue
          Marks.Visible = True
          XValues.Order = loAscending
          YValues.Name = 'Pie'
          YValues.Order = loNone
          Frame.InnerBrush.BackColor = clRed
          Frame.InnerBrush.Gradient.EndColor = clGray
          Frame.InnerBrush.Gradient.MidColor = clWhite
          Frame.InnerBrush.Gradient.StartColor = 4210752
          Frame.InnerBrush.Gradient.Visible = True
          Frame.MiddleBrush.BackColor = clYellow
          Frame.MiddleBrush.Gradient.EndColor = 8553090
          Frame.MiddleBrush.Gradient.MidColor = clWhite
          Frame.MiddleBrush.Gradient.StartColor = clGray
          Frame.MiddleBrush.Gradient.Visible = True
          Frame.OuterBrush.BackColor = clGreen
          Frame.OuterBrush.Gradient.EndColor = 4210752
          Frame.OuterBrush.Gradient.MidColor = clWhite
          Frame.OuterBrush.Gradient.StartColor = clSilver
          Frame.OuterBrush.Gradient.Visible = True
          Frame.Width = 4
          OtherSlice.Legend.Visible = False
        end
      end
      object DateTimePicker1: TDateTimePicker
        Left = 560
        Top = 4
        Width = 105
        Height = 21
        Date = 42362.595803032410000000
        Format = 'MMMM'
        Time = 42362.595803032410000000
        TabOrder = 1
        OnChange = DateTimePicker1Change
      end
    end
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 80
    Top = 256
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = Form1.ADOConnection2
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM Resource')
    Left = 128
    Top = 256
  end
  object ADOQuery2: TADOQuery
    Active = True
    Connection = Form1.ADOConnection2
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM Resource')
    Left = 24
    Top = 256
  end
end
