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
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		count = 0;
//		break;
//	case WM_PAINT:										// 206에서 이 WM_PAINT를 추가한 이유는 
//		hdc = BeginPaint(hwnd, &ps);					// GetDC( ) 함수의 나쁜 특성때문이다.
//		TextOut(hdc, 0, 0, str, _tcslen(str));			// 윈도우로 가리거나, 최소화 등을 했다가 다시 윈도우를 켜보면
//		EndPaint(hwnd, &ps);							// 이전에 입력했던 값이 가려져서 안보인다.
//		break;											// 그래서 WM_PAINT로 윈도우가 다시 올라오면 다시 그려주는 방식으로 문제를 해결.
//	case WM_CHAR:
//		hdc = GetDC(hwnd);
//		str[count++] = wParam;
//		str[count] = NULL;
//		TextOut(hdc, 0, 0, str, _tcslen(str));
//		ReleaseDC(hwnd, hdc);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}