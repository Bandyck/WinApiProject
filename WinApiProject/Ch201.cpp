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
//			_T("Window Title Name"),
//			WS_OVERLAPPEDWINDOW,
//			CW_USEDEFAULT,
//			CW_USEDEFAULT,
//			CW_USEDEFAULT,
//			CW_USEDEFAULT,
//			NULL,
//			NULL,
//			hInstance,
//			NULL
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
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break;
//	case WM_PAINT:
//	{
//		hdc = BeginPaint(hwnd, &ps);
//	//Ellipse(hdc, 0, 0, 40, 40);
//	double x = 300;
//	double y = 300;
//	double r1 = 100;
//	double r2 = (r1*tan(M_PI/12.0)) / (1 - tan(M_PI / 12.0));
//	double r = r1 + r2;
//	DrawCircle(hdc, x, y, r1);
//	DrawCircle(hdc, x + r, y, r2);
//	DrawCircle(hdc, x - r, y, r2);
//	DrawCircle(hdc, x, y + r, r2);
//	DrawCircle(hdc, x, y - r, r2);
//	DrawCircle(hdc, x + r*cos(M_PI / 3.0), y - r*sin(M_PI / 3.0), r2);
//	DrawCircle(hdc, x + r*cos(M_PI / 6.0), y - r*sin(M_PI / 6.0), r2);
//	DrawCircle(hdc, x + r*cos(M_PI / 3.0), y + r*sin(M_PI / 3.0), r2);
//	DrawCircle(hdc, x + r*cos(M_PI / 6.0), y + r*sin(M_PI / 6.0), r2);
//	DrawCircle(hdc, x - r*cos(M_PI / 3.0), y - r*sin(M_PI / 3.0), r2);
//	DrawCircle(hdc, x - r*cos(M_PI / 6.0), y - r*sin(M_PI / 6.0), r2);
//	DrawCircle(hdc, x - r*cos(M_PI / 3.0), y + r*sin(M_PI / 3.0), r2);
//	DrawCircle(hdc, x - r*cos(M_PI / 6.0), y + r*sin(M_PI / 6.0), r2);
//	
//	EndPaint(hwnd, &ps); 
//	
//	}
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}
//void DrawCircle(HDC hdc, double x, double y, double r)
//{
//	Ellipse(hdc, x - r, y - r, x + r, y + r);
//}