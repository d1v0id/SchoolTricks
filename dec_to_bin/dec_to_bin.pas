program DecToBin;
var
	i_dec: integer;
	i: byte;

function Bin(Value: integer; n: byte): boolean;
asm
	bt eax, edx
	setc al
	and eax, 0FFh
end;

begin
	ReadLn(i_dec);
	for i:= 0 to 31 do begin
		Write(Ord(Bin(i_dec, i)))
	end;
end.

