unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls;

type

  mem = record
    name: string[30];
    money: longint;
    wnd: byte;
    index: byte;
  end;

  TForm1 = class(TForm)
    Edit1: TEdit;
    Label1: TLabel;
    Edit2: TEdit;
    RadioGroup1: TRadioGroup;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Label2: TLabel;
    Label3: TLabel;
    ListBox1: TListBox;
    Image1: TImage;
    Img_Win1: TImage;
    Img_Win3: TImage;
    Img_Win2: TImage;
    procedure Button3Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Edit2KeyPress(Sender: TObject; var Key: Char);
    procedure ListBox1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Finish(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
    i: byte;
    m: array[1..10] of mem;
    winners: array[1..3] of byte;
    time: integer;
  end;

var
  Form1: TForm1;

implementation

uses Unit2, Unit3, Unit4;

{$R *.dfm}

procedure TForm1.Finish(Sender: TObject);
begin
  Image1.Top:= Height - Image1.Height;
  Image1.Left:= Round(Width/2-Image1.Width/2);

  case winners[1] of
    1: begin Img_Win1.Left:= Image1.Left+35; Img_Win1.Top:= 0; end;
    2: begin Img_Win2.Left:= Image1.Left+35; Img_Win2.Top:= 0; end;
    3: begin Img_Win3.Left:= Image1.Left+35; Img_Win3.Top:= 0; end;
  end;

  case winners[2] of
    1: begin Img_Win1.Left:= Image1.Left; Img_Win1.Top:= 20; end;
    2: begin Img_Win2.Left:= Image1.Left; Img_Win2.Top:= 20; end;
    3: begin Img_Win3.Left:= Image1.Left; Img_Win3.Top:= 20; end;
  end;

  case winners[3] of
    1: begin Img_Win1.Left:= Image1.Left+Image1.Width-30; Img_Win1.Top:= 20; end;
    2: begin Img_Win2.Left:= Image1.Left+Image1.Width-30; Img_Win2.Top:= 20; end;
    3: begin Img_Win3.Left:= Image1.Left+Image1.Width-30; Img_Win3.Top:= 20; end;
  end;

  Image1.Visible:= True;
  Img_Win1.Visible:= True;
  Img_Win2.Visible:= True;
  Img_Win3.Visible:= True;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  i:= i + 1;
  if (Edit1.Text <> '') and (Edit2.Text <> '')
    and (RadioGroup1.ItemIndex <> -1) then begin
    ListBox1.Items.Add(IntToStr(i));
    with m[i] do begin
      name:= Edit1.Text;
      money:= StrToInt(Edit2.Text);
      wnd:= RadioGroup1.ItemIndex + 1;
      index:= i;
    end;
    Edit1.Text:= '';
    Edit2.Text:= '';
    RadioGroup1.ItemIndex:= -1;
  end;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  Form1.Close;
end;

procedure TForm1.Edit2KeyPress(Sender: TObject; var Key: Char);
begin
  if (not (Key in ['0'..'9'])) and (key <> #8) then Key:= #0; 
end;

procedure TForm1.ListBox1Click(Sender: TObject);
var
  j: byte;
begin
  for j:= 1 to 10 do
  with m[j] do begin
    if index = ListBox1.ItemIndex + 1 then begin
      Edit1.Text:= name;
      Edit2.Text:= IntToStr(money);
      RadioGroup1.ItemIndex:= wnd - 1;
    end;
  end;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  if ListBox1.Items.Count <> 0 then begin
    Caption:= 'Run!';
    BorderStyle:= bsNone;
    Top:= 0;
    Left:= 0;
    Height:= 90;
    Width:= 1024;
    Button1.Top:= Height - Button1.Height;
    Button1.Left:= Width - Button1.Width;
    Button2.Visible:= false;
    Button3.Visible:= false;
    Label3.Visible:= false;
    Edit1.Visible:= false;
    Edit2.Visible:= false;
    ListBox1.Visible:= false;
    RadioGroup1.Visible:= false;

    Label1.Caption:= 'Start';
    Label1.Font.Size:= 20;
    Label1.Top:= 0;
    Label1.Left:= 0;

    Label2.Caption:= 'Finish';
    Label2.Font.Size:= 20;
    Label2.Top:= 0;
    Label2.Left:= Width - Label2.Width;

    {Label3.Caption:= '2nd [1st] 3rd';
    Label3.Font.Size:= 20;
    Label3.Top:= 0;
    Label3.Left:= Round(Width/2-Label3.Width/2);}

    Form2.Left:= 0;
    Form3.Left:= 0;
    Form4.Left:= 0;
    Form2.Top:= Form1.Top + Form1.Height + 10;
    Form3.Top:= Form1.Top + Form1.Height + 50;
    Form4.Top:= Form1.Top + Form1.Height + 90;
    Form2.Show;
    Form3.Show;
    Form4.Show;
    Form2.Timer1.Enabled:= true;
    Form3.Timer1.Enabled:= true;
    Form4.Timer1.Enabled:= true;
    Form1.Activate;
  end
  else ShowMessage('Ставки не сделаны!!!');
end;
end.
