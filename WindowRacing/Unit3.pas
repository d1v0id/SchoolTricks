unit Unit3;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls;

type
  TForm3 = class(TForm)
    Timer1: TTimer;
    procedure Timer1Timer(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form3: TForm3;

implementation

uses Unit1;

{$R *.dfm}

procedure TForm3.Timer1Timer(Sender: TObject);
begin
  Randomize;
  if Width < 1024 then begin
    Width:= Width + Round(Random(10000)/1000);
  end else begin
    {if (Form1.winners[1]<>2) and (Form1.winners[1]<>3) then Form1.winners[1]:= 1
    else Form1.winners[2]:= 1;}
    Timer1.Enabled:= false;
    if Form1.winners[1] = 0 then Form1.winners[1]:= 2 else
    if Form1.winners[2] = 0 then Form1.winners[2]:= 2 else
    if Form1.winners[3] = 0 then begin Form1.winners[3]:= 2; Form1.Finish(Form3); end;
  end;
end;

procedure TForm3.FormClose(Sender: TObject; var Action: TCloseAction);
begin
    Action:= caNone;
end;
end.
