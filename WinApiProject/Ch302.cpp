//#include <Windows.h>
//#include <tchar.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//void DrawCircle(HDC hdc, double x, double y, double r);
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
//	HDC hdc;
//	PAINTSTRUCT ps;
//	static int x, y;
//	static RECT rectView;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		GetClientRect(hwnd, &rectView);
//		x = 20; y = 20;
//		SetTimer(hwnd, 1, 700, NULL);
//		SetTimer(hwnd, 2, 1000, NULL);
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_TIMER:
//		switch (wParam)
//		{
//		case 1:
//			x += 40;
//			if (x + 20 > rectView.right) x = x - (x + 20 - rectView.right);
//			InvalidateRgn(hwnd, NULL, TRUE);
//		case 2:
//			y += 40;
//			if (y + 20 > rectView.bottom) y -= 40;
//			InvalidateRgn(hwnd, NULL, TRUE);
//		}
//		break;
//	case WM_DESTROY:
//		KillTimer(hwnd, 1);
//		KillTimer(hwnd, 2);
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}