//#include <Windows.h>
//#include <TCHAR.H>
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR plszCmdLine, int nCmdShow)
//{
//	HWND hwnd;
//	MSG msg;
//	WNDCLASS WndClass;
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
//	WndClass.hInstance = hInstance;
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//	WndClass.lpszMenuName = NULL;
//	WndClass.lpszClassName = _T("Window Class Name");
//	RegisterClass(&WndClass);
//	hwnd = CreateWindow(_T("Window Class Name"),
//		_T("Window Title Name"),
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,
//		CW_USEDEFAULT,
//		CW_USEDEFAULT,
//		CW_USEDEFAULT,
//		NULL,
//		NULL,
//		hInstance,
//		NULL
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return (int)msg.wParam;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lPARAM)
//{
//	HDC				hdc;								
//	PAINTSTRUCT		ps;
//	static TCHAR	str[100];
//	static int		count;
//	static SIZE		size;
//	RECT			rt = { 0,0,1000,1000 };								  // Caret(ĳ��). ���ڸ� �Է��� �� �����̴� Ŀ��.
//	switch (iMsg)														  
//	{																	  // CreateCaret( ). ĳ�� �����ϴ� �Լ�.
//	case WM_CREATE:													   	  // hwnd = ĳ���� ��Ÿ�� ������ �ڵ�.
//		CreateCaret(hwnd, NULL, 5, 15);								   	  // NULL = ĳ���� ���θ� ĥ�� ����. NULL = ������.
//		ShowCaret(hwnd);											   	  // 5	   = ĳ���� �ʺ�.
//		break;														   	  // 15   = ĳ���� ����.
//	case WM_PAINT:													   	  // ShowCaret( ). ĳ�� �����ִ� �Լ�.
//		hdc = BeginPaint(hwnd, &ps);								   
//		GetTextExtentPoint(hdc, str, _tcslen(str), &size);			   	  // GetTextExtentPoint( ). ���ڿ� ũ�� ���� �Լ�.
//		TextOut(hdc, 0, 0, str, _tcslen(str));							  // hdc = ȭ���� �޾ƿ�.
//		SetCaretPos(size.cx, 0);										  // str = ũ�⸦ ������ ���ڿ�.
//		EndPaint(hwnd, &ps);											  // _tcslen(str) = �� ��° ���ڱ��� ũ�⸦ ��������. ���⼱ ������.
//		break;															  // &size = SIZE ����ü( ���� ����, ���� ���� )�� �ּ�.
//	case WM_CHAR:														  // SetCaretPos(ĳ���� ���۵� x��ǥ, ĳ���� ���۵� y��ǥ) �Լ�.
//		if (wParam == VK_BACK && count > 0) count--;					  // size.cx = ���⼭�� ������ ���ڿ��� ���� ����.
//		else str[count++] = wParam;
//		str[count] = NULL;
//		InvalidateRgn(hwnd, NULL, TRUE);
//		break;
//	case WM_DESTROY:
//		HideCaret(hwnd);												   // HideCaret( ). ĳ�� ���ߴ� �Լ�.
//		DestroyCaret();													   // DestroyCaret( ). ĳ�� �����ϴ� �Լ�.
//		PostQuitMessage(0);												   // �������� �����ϹǷ� WM_DESTROY�� �־��ش�.
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}