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
//	RECT			rt = { 0,0,1000,1000 };								  // Caret(캐럿). 문자를 입력할 때 깜빡이는 커서.
//	switch (iMsg)														  
//	{																	  // CreateCaret( ). 캐럿 생성하는 함수.
//	case WM_CREATE:													   	  // hwnd = 캐럿이 나타날 윈도우 핸들.
//		CreateCaret(hwnd, NULL, 5, 15);								   	  // NULL = 캐럿의 내부를 칠할 내용. NULL = 검은색.
//		ShowCaret(hwnd);											   	  // 5	   = 캐럿의 너비.
//		break;														   	  // 15   = 캐럿의 높이.
//	case WM_PAINT:													   	  // ShowCaret( ). 캐럿 보여주는 함수.
//		hdc = BeginPaint(hwnd, &ps);								   
//		GetTextExtentPoint(hdc, str, _tcslen(str), &size);			   	  // GetTextExtentPoint( ). 문자열 크기 측정 함수.
//		TextOut(hdc, 0, 0, str, _tcslen(str));							  // hdc = 화면을 받아옴.
//		SetCaretPos(size.cx, 0);										  // str = 크기를 측정할 문자열.
//		EndPaint(hwnd, &ps);											  // _tcslen(str) = 몇 번째 문자까지 크기를 측정할지. 여기선 끝까지.
//		break;															  // &size = SIZE 구조체( 가로 길이, 세로 길이 )의 주소.
//	case WM_CHAR:														  // SetCaretPos(캐럿이 시작될 x좌표, 캐럿이 시작될 y좌표) 함수.
//		if (wParam == VK_BACK && count > 0) count--;					  // size.cx = 여기서는 위에서 문자열의 가로 길이.
//		else str[count++] = wParam;
//		str[count] = NULL;
//		InvalidateRgn(hwnd, NULL, TRUE);
//		break;
//	case WM_DESTROY:
//		HideCaret(hwnd);												   // HideCaret( ). 캐럿 감추는 함수.
//		DestroyCaret();													   // DestroyCaret( ). 캐럿 삭제하는 함수.
//		PostQuitMessage(0);												   // 마지막에 삭제하므로 WM_DESTROY에 넣어준다.
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}