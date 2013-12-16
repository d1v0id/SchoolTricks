program XorCrypt;
uses crt;
var
	f, fd: file of char;
	fname_from: string;
	fname_to: string

procedure xorfile();
const
	key = 16;
var
	ch: char;
begin
	{$I-}
	AssignFile(f, fname_from);
	Reset(f);
	{$I+}
	if IOResult = 0 then begin
		AssignFile(fd, fname_to);
		Rewrite(fd);
		while not eof(f) do begin
			Read(f, ch);
			ch:= Chr(Ord(ch) xor key);
			Write(fd, ch);
		end;
		CloseFile(fd);
		CloseFile(f);
		WriteLn('File crypt or decrypt successful! Congratulation!');
	end
	else begin
		WriteLn('File not found! Error!');
	end;
end;

begin
	ReadLn(fname_from);
	REadLn(fname_to);
	xorfile;
end.
