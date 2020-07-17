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
//	static TCHAR	str[1000];
//	static int		count, yPos;
//	RECT			rt = { 0,0,1000,1000 };						   // DrawText( ) 를 위한 영역 선언
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		count = 0;
//		yPos = 0;
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);								// 엔터키와 같은지 확인할 필요없이
//		DrawText(hdc, str, _tcslen(str), &rt, DT_TOP | DT_LEFT);	// DrawText( ) 를 이용하면 어차피 영역을 출력한다.
//		EndPaint(hwnd, &ps);										// 단, 이를 위해서는 DT_SINGLELINE 을 넣으면 안된다.
//		break;														// ABC [ENTER] DEF [ENTER] ...  이 모든 값들이 str에 저장.
//	case WM_CHAR:
//		if (wParam == VK_BACK && count > 0) count--;
//		else str[count++] = wParam;
//		str[count] = NULL;
//		InvalidateRgn(hwnd, NULL, TRUE);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}