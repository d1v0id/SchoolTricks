object Form1: TForm1
  Left = 139
  Top = 26
  Width = 832
  Height = 632
  Caption = 'Viewer'
  Color = clAppWorkSpace
  Constraints.MinHeight = 276
  Constraints.MinWidth = 177
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 169
    Top = 25
    Width = 655
    Height = 580
    Align = alClient
    Proportional = True
  end
  object Pnl_Control: TPanel
    Left = 0
    Top = 0
    Width = 824
    Height = 25
    Align = alTop
    TabOrder = 0
    object Btn_Open: TButton
      Left = 0
      Top = 0
      Width = 57
      Height = 25
      Caption = 'Open'
      TabOrder = 0
      OnClick = Btn_OpenClick
    end
    object Btn_Close: TButton
      Left = 56
      Top = 0
      Width = 57
      Height = 25
      Caption = 'Close'
      Enabled = False
      TabOrder = 1
      OnClick = Btn_CloseClick
    end
    object Btn_Exit: TButton
      Left = 672
      Top = 0
      Width = 55
      Height = 25
      Caption = 'Exit'
      TabOrder = 2
      OnClick = Btn_ExitClick
    end
  end
  object Pnl_List: TPanel
    Left = 0
    Top = 25
    Width = 169
    Height = 580
    Align = alLeft
    TabOrder = 1
    OnResize = Pnl_ListResize
    object GroupBox1: TGroupBox
      Left = 8
      Top = 496
      Width = 153
      Height = 73
      Caption = 'Slide Show'
      TabOrder = 0
      object Ed_Delay: TEdit
        Left = 48
        Top = 20
        Width = 41
        Height = 21
        TabOrder = 0
        Text = '1000'
        OnKeyPress = Ed_DelayKeyPress
      end
      object Btn_SlideShow: TButton
        Left = 96
        Top = 18
        Width = 49
        Height = 25
        Caption = 'On'
        TabOrder = 1
        OnClick = Btn_SlideShowClick
      end
      object CB_Repeat: TCheckBox
        Left = 48
        Top = 48
        Width = 97
        Height = 17
        Caption = 'Repeat in End'
        TabOrder = 2
        OnClick = CB_RepeatClick
      end
    end
    object M_List: TListBox
      Left = 1
      Top = 1
      Width = 167
      Height = 8
      Align = alTop
      ItemHeight = 13
      TabOrder = 1
      OnClick = M_ListClick
    end
    object GroupBox2: TGroupBox
      Left = 8
      Top = 368
      Width = 153
      Height = 121
      Caption = 'GroupBox2'
      TabOrder = 2
    end
  end
  object OpenPicDialog: TOpenPictureDialog
    InitialDir = 'D:\Pictures'
    OptionsEx = [ofExNoPlacesBar]
    Title = #1047#1072#1075#1088#1091#1079#1082#1072' '#1080#1084#1072#1075#1080' '#1080#1079' '#1092#1072#1081#1083#1072'...'
    Left = 432
    Top = 72
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 432
    Top = 112
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer2Timer
    Left = 528
    Top = 112
  end
end
