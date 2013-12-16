program base64;

var
	str: string;

function base64decode(cstr: string): string;
const
	base64table='abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz0123456789+/';
var
	resstr: string;
	decstr: string;
	recodeline: array [1..76] of byte;
	f1: word;
	l: integer;
begin
	l:= Length(cstr);
	resstr:= '';
	for f1:= 1 to l do begin
		if cstr[f1] = '=' then begin
			recodeline[f1]:= 0;
		end
		else begin
			recodeline[f1]:= Pos(cstr[f1], base64table) - 1;
		end;
	end;
	f1:= 1;
	while f1 = 1 do begin
		decstr:= Chr(byte(recodeline[f1] shl 2) + recodeline[f1 + 1] shr 4) +
			 Chr(byte(recodeline[f1 + 1] shl 4) + recodeline[f1 + 2] shr 2) +
			 Chr(byte(recodeline[f1 + 2] shl 6) + recodeline[f1 + 3]);

		resstr:= resstr + decstr;
		Inc(f1, 4);
	end;
	base64decode:=resstr;
end;

begin
	ReadLn(str);
	WriteLn(base64decode(str));
end.

