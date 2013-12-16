program SysColors;

uses
	Windows, Messages, SysUtils;

const
	SysColorArray: array[0..25] of integer = (COLOR_Background,
		COLOR_ActiveCaption, COLOR_InactiveCaption, COLOR_GRADIENTACTIVECAPTION,
		COLOR_GRADIENTINACTIVECAPTION, COLOR_Menu, COLOR_Window,
		COLOR_WindowFrame, COLOR_MenuText, COLOR_Highlight, COLOR_WindowText,
		COLOR_CaptionText, COLOR_ActiveBorder, COLOR_InactiveBorder,
		COLOR_AppWorkspace, COLOR_BtnFace, COLOR_BtnShadow, COLOR_GrayText,
		COLOR_BtnText, COLOR_InactiveCaptionText, COLOR_BtnHighlight,
		COLOR_3DDkShadow, COLOR_3DLight, COLOR_InfoText, COLOR_InfoBk,
		COLOR_HighlightText);

	ColorsArray: array[0..25] of integer = (0, 52942, 32896, 0, 0, 0, 3947580, 0,
		16777215, 54634, 16777215, 0, 0, 0, 0, 0, 0, 0, 16777215, 0, 8355711,
		4210752, 0, 0, 16777215, 0);

var
	Instance: HWND;
	WindowClass: TWndClass;
	Handle: HWND;
	msg: TMsg;
	cl: array[0..25] of integer;
	id1: integer;
	state: boolean;

procedure DoExit;
begin
	UnregisterHotKey(Handle, id1);
	GlobalDeleteAtom(id1);
	Halt;
end;

function WindowProc(hwn, msg, wpr, lpr: longint): longint; stdcall;
begin
	result:= defwindowproc(hwn, msg, wpr, lpr);
	if msg = wm_destroy then begin
		DoExit;
	end;

	if msg = wm_KeyDown then begin
		if wpr = VK_ESCAPE then begin
			DoExit;
		end;
	end;
end;

procedure WM_HotKeyHandler(var Message: TMessage);
var
	fuModifiers, uVirtKey: word;
	idHotKey, i: byte;
begin
	idHotkey:= Message.wParam;
	fuModifiers:= LOWORD(Message.lParam);
	uVirtKey:= HIWORD(Message.lParam);
	if (fuModifiers = MOD_WIN) AND (uVirtKey = VK_F12) then begin
		if not state then begin
			for i:= 0 to 25 do begin
				cl[i]:= GetSysColor(SysColorArray[i]);
			end;
			for i:= 0 to 25 do begin
				SetSysColors(1,SysColorArray[i],ColorsArray[i]);
			end;
			state:= true;
		end
		else begin
			for i:= 0 to 25 do SetSysColors(1,SysColorArray[i],cl[i]);
			state:= false;
		end;
	end;
	{ inherited; }
end;

begin
	id1:= GlobalAddAtom('hotkey');
	RegisterHotKey(Handle, id1, MOD_WIN, VK_F12);
	state:= false;

	instance:= GetModuleHandle(nil);
	WindowClass.Style:= CS_HRedraw or CS_VRedraw;
	WindowClass.Lpfnwndproc:= @windowproc;
	WindowClass.Hinstance:= Instance;
	WindowClass.HbrBackground:= color_btnface;
	WindowClass.LpszClassName:= 'DX';
	WindowClass.Hcursor:= LoadCursor(0, IDC_ARROW);

	RegisterClass(WindowClass);

	Handle:= CreateWindowEx(0, 'DX', '', WS_POPUP, 1, 1, 200, 200, 0, 0, Instance, nil);

	ShowWindow(Handle, SW_SHOW);
	UpdateWindow(Handle);

	while (GetMessage(msg, 0, 0, 0)) do begin
		Translatemessage(msg);
		Dispatchmessage(msg);
	end;
end.
