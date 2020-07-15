//#include <Windows.h>
//#include <tchar.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
//#define BSIZE 40
//double LengthPts(int x1, int y1, int x2, int y2)
//{
//	return(sqrt((float)((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))));
//}
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
//	static int		x, y;
//	static int		mx, my;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		x = 50; y = 50;
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		Ellipse(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_LBUTTONDOWN:
//		mx = LOWORD(lPARAM);
//		my = HIWORD(lPARAM);
//		SetTimer(hwnd, 1, 1000, NULL);
//		break;
//	case WM_LBUTTONUP:
//		mx = LOWORD(lPARAM);
//		my = HIWORD(lPARAM);
//		SetTimer(hwnd, 1, 1000, NULL);
//		break;
//	case WM_MOUSEMOVE:
//		//mx = LOWORD(lPARAM);
//		//my = HIWORD(lPARAM);
//		//x = mx;
//		//y = my;
//		//InvalidateRgn(hwnd, NULL, TRUE);
//		break;
//	case WM_TIMER:
//		x += LengthPts(x, y, mx, my) / 10;
//		y += LengthPts(x, y, mx, my) / 10;
//		InvalidateRgn(hwnd, NULL, TRUE);
//		break;
//	case WM_DESTROY:
//		KillTimer(hwnd, 1);
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}