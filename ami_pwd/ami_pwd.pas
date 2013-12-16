program AmiPwd;

const
	UnScan: string[50] = '*1234567890****QWERTYUIOP****ASDFGHJKL*****ZXCVBNM';

var
	a, b, c, i: byte;
	str1: string;

function cmos(ad: byte): byte; assembler;
asm
	mov al, ad
	out 70h, al
	jmp @m
    @m:
	in al, 71h
end;


function code(a, b: byte): byte; assembler;
asm
	mov bl, a
	mov al, b
    @m2:
	test bl, 0c3h
	jp @m1
	stc
    @m1:
	rcr bl, 1
	dec al
	jne @m2
	mov al, bl
end;

begin
	b:= cmos($37) and $f0;
	for i:= $38 to $3d do begin
		a:= 0;
		c:= cmos(i);

		if c = 0 then begin
			break;
		end;

		repeat
			inc(a)
		until (code(b, a) = c) or (a > 50);

		if (a > 50) or (UnScan[a] = '*') then begin
			exit;
		end;

		str1:= str1 + UnScan[a];
		b:= c;
	end;
	WriteLn('The CURRENT password is: ' + str1);
end.

