//#include <Windows.h>
//#include <tchar.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//void DrawStar(HDC hdc, double x, double y, double r);
//double CrossDotX(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
//double CrossDotY(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
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
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	POINT point[10] = {};
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawStar(hdc, 300, 300, 100);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}
//void DrawStar(HDC hdc, double x, double y, double r)
//{
//	double dx4=0;
//	dx4 = CrossDotX(x, x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r, y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
//	double dy4=0;
//	dy4 = CrossDotY(x, x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r, y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
//	double dx8 = 2*x-dx4;
//	double dy8 = dy4;
//	double dy6 = 0;
//		dy6 = CrossDotY(x - r*cos(M_PI / 10.0), x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
//
//	POINT point[10] = { {x, y - r},
//					{x + (r*sin(M_PI / 5.0) *(1 - sin(M_PI / 10.0)) / (1 + cos(M_PI / 5.0))),y - r*sin(M_PI / 10.0) },
//					{x + r*cos(M_PI / 10.0),y - r*sin(M_PI / 10.0)},
//					{dx4, dy4},
//					{x + r*sin(M_PI / 5.0), y + r*cos(M_PI / 5.0)},
//					{x, dy6},
//					{ x - r*sin(M_PI / 5.0), y + r*cos(M_PI / 5.0) },
//					{dx8, dy8},
//					{ x - r*cos(M_PI / 10.0),y - r*sin(M_PI / 10.0) },
//					{ x - (r*sin(M_PI / 5.0) *(1 - sin(M_PI / 10.0)) / (1 + cos(M_PI / 5.0))),y - r*sin(M_PI / 10.0) }};
//	Polygon(hdc, point, 10);
//}
//double CrossDotX(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4)
//{
//	double a, b, c, d, e, f;
//	double x, y;
//
//	a = y1 - y2;
//	b = -(x1 - x2);
//	c = y3 - y4;
//	d = -(x3 - x4);
//	e = a*x1 + b*y1;
//	f = c*x3 + d*y3;
//
//	x = ((e*d - b*f)) / ((a*d - b*c));
//	
//	return x;
//}
//double CrossDotY(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4)
//{
//	double a, b, c, d, e, f;
//	double x, y;
//
//	a = y1 - y2;
//	b = -(x1 - x2);
//	c = y3 - y4;
//	d = -(x3 - x4);
//	e = a*x1 + b*y1;
//	f = c*x3 + d*y3;
//
//	y = ((a*f - e*c)) / ((a*d - b*c));
//
//	return y;
//}
