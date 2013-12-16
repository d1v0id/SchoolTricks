unit TransmissionNoise;

interface

uses
	Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
	Dialogs, StdCtrls;

type
	TForm1 = class(TForm)
		Edit1: TEdit;
		Button1: TButton;
		Edit2: TEdit;
		Label1: TLabel;
		procedure Button1Click(Sender: TObject);
		private
			{ Private declarations }
		public
			{ Public declarations }
	end;

var
	Form1: TForm1;

implementation
const
	h: array[1..7, 1..4] of boolean = (
		(true, true, false, true),
		(true, false, true, true),
		(true, false, false, false),
		(false, true, true, true),
		(false, true, false, false),
		(false, false, true, false),
		(false, false, false, true)
	);

	p = 0.00;

	g: array[1..3, 1..7] of boolean = (
		(false, false, false, true, true, true, true),
		(false, true, true, false, false, true, true),
		(true, false, true, false, true, false, true)
	);
var
	a1, f: array[1..96] of boolean;
	y: array[1..24,1..7] of boolean;

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
var
	i, j, n, f1, f2: byte;
	sd: array[1..3] of boolean;
begin
	for i:= 1 to Edit1.GetTextLen do begin
		n:= Ord(Edit1.Text[i]);
		j:= 8;
		repeat
			a1[(i - 1) * 8 + j]:= Odd(n mod 2);
			n:= n div 2;
			Dec(j);
		until n < 1;
	end;

	for i:= 1 to Edit1.GetTextLen * 8 do begin
		if (i - 7) < 0 then f1:= 0 else if (i - 7) = 0 then f1:= 1 else f1:= Ord(f[i - 7]);
		if (i - 6) < 0 then f2:= 0 else if (i - 6) = 0 then f2:= 1 else f2:= Ord(f[i - 6]);
		if (i - 3) < 0 then j:= 0 else if (i - 3) = 0 then j:= 1 else j:= Ord(f[i - 3]);
		if (i - 6) = 0 then n:= 1 else n:= Ord(f[i - 1]);
		f[i]:= Odd((f1 + f2 + j + n) mod 2);
	end;

	for i:= 1 to Edit1.GetTextLen * 8 do begin
		 a1[i]:= a1[i] xor f[i];
	end;

	for n:= 1 to (Edit1.GetTextLen * 8) div 4 do begin
		for i:= 1 to 7 do begin
			for j:= 1 to 4 do begin
				y[n, i]:= Odd((Ord(y[n, i]) + Ord(a1[(n - 1) * 4 + j] and h[i, j])) mod 2);
			end;
		end;
	end;

	Randomize;
	for i:= 1 to (Edit1.GetTextLen * 8) div 4 do begin
		for j:= 1 to 7 do begin
			if Random(100) / 100 < p then begin
				y[i, j]:= not y[i, j];
			end;
		end;
	end;

	for n:= 1 to (Edit1.GetTextLen * 8) div 4 do begin
		for i:= 1 to 3 do begin
			sd[i]:= false;
			for j:= 1 to 7 do begin
				sd[i]:= Odd((Ord(sd[i]) + Ord(y[n, i] and g[i, j])) mod 2);
			end;
		end;

		if (Ord(sd[1]) <> 0) or (Ord(sd[2]) <> 0) or (Ord(sd[3]) <> 0) then begin
			f1:= Ord(sd[1]) + 2 * Ord(sd[2]) + 4 * Ord(sd[3]);
			y[n, f1]:= not y[n, f1];
		end;

		a1[n * 4 - 3]:= y[n, 3];
		a1[n * 4 - 2]:= y[n, 5];
		a1[n * 4 - 1]:= y[n, 6];
		a1[n * 4]:= y[n, 7];
	end;

	for i:= 1 to Edit1.GetTextLen * 8 do begin
		a1[i]:= a1[i] xor f[i];
	end;

	for i:= 1 to Edit1.GetTextLen do begin
		f1:= 128;
		n:= 0;
		for j:= 1 to 8 do begin
			if a1[(i-1)*8+j] then begin
				Inc(n,f1);
			end;
			f1:= f1 div 2;
		end;
		Edit2.Text:= Edit2.Text + Chr(n);
	end;

	j:= 0;
	for i:= 1 to Edit2.GetTextLen do begin
		if Edit2.Text[i] <> Edit1.Text[i] then begin
			Inc(j);
		end;
	end;
	Label1.Caption:= IntToStr(j);
end;

end.

