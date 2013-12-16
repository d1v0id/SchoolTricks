unit Unit4;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls;

type
  TForm4 = class(TForm)
    Timer1: TTimer;
    procedure Timer1Timer(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form4: TForm4;

implementation

uses Unit1;

{$R *.dfm}

procedure TForm4.Timer1Timer(Sender: TObject);
begin
  Randomize;
  if Width < 1024 then begin
    Width:= Width + Round(Random(10000)/1000);
  end else begin
    {if (Form1.winners[1]<>1) and (Form1.winners[1]<>2) then Form1.winners[1]:= 3
    else Form1.winners[2]:= 3;}
    Timer1.Enabled:= false;
    if Form1.winners[1] = 0 then Form1.winners[1]:= 3 else
    if Form1.winners[2] = 0 then Form1.winners[2]:= 3 else
    if Form1.winners[3] = 0 then begin Form1.winners[3]:= 3; Form1.Finish(Form4); end;
  end;
end;

procedure TForm4.FormClose(Sender: TObject; var Action: TCloseAction);
begin
    Action:= caNone;
end;
end.
