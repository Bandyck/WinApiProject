//#include <Windows.h>
//#include <tchar.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
//#include <time.h>
//static RECT		rectView;
//double CrossDotX(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
//double CrossDotY(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
//class CStar
//{
//public:
//	POINT point[10];
//	int x;
//	int y;
//	int r = 20;
//	int Rspeed = 50;
//	int Tspeed = 50;
//	void update();
//	void show(HDC hdc);
//	void Collision(CStar * List, int counter);
//};
//void CStar::update()
//{
//	if (x + Rspeed > rectView.right) { /*x = x + Rspeed - rectView.right;*/ Rspeed *= -1; }
//	if (x + Rspeed < rectView.left) { /*x = rectView.left - (x + Rspeed);*/ Rspeed *= -1; }
//	if (y + Tspeed > rectView.top) { /*y = y + Tspeed - rectView.top;*/ Tspeed *= -1; }
//	if (y - Tspeed < rectView.bottom) { /*y = rectView.bottom - (y + Tspeed);*/ Tspeed *= -1; }
//	x += Rspeed;
//	y += Tspeed;
//	double dx4 = 0;
//	dx4 = CrossDotX(x, x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r, y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
//	double dy4 = 0;
//	dy4 = CrossDotY(x, x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r, y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
//	double dx8 = 2 * x - dx4;
//	double dy8 = dy4;
//	double dy6 = 0;
//	dy6 = CrossDotY(x - r*cos(M_PI / 10.0), x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
//	this->point[0].x = this->x;
//	this->point[0].y = this->y - this->r;
//	this->point[1].x = this->x + (this->r*sin(M_PI / 5.0) *(1 - sin(M_PI / 10.0)) / (1 + cos(M_PI / 5.0)));
//	this->point[1].y = this->y - this->r*sin(M_PI / 10.0);
//	this->point[2].x = this->x + this->r*cos(M_PI / 10.0);
//	this->point[2].y = this->y - this->r*sin(M_PI / 10.0);
//	this->point[3].x = dx4;
//	this->point[3].y = dy4;
//	this->point[4].x = this->x + this->r*sin(M_PI / 5.0);
//	this->point[4].y = this->y + this->r*cos(M_PI / 5.0);
//	this->point[5].x = this->x;
//	this->point[5].y = dy6;
//	this->point[6].x = this->x - this->r*sin(M_PI / 5.0);
//	this->point[6].y = this->y + this->r*cos(M_PI / 5.0);
//	this->point[7].x = dx8;
//	this->point[7].y = dy8;
//	this->point[8].x = this->x - this->r*cos(M_PI / 10.0);
//	this->point[8].y = this->y - this->r*sin(M_PI / 10.0);
//	this->point[9].x = this->x - (this->r*sin(M_PI / 5.0) *(1 - sin(M_PI / 10.0)) / (1 + cos(M_PI / 5.0)));
//	this->point[9].y = this->y - this->r*sin(M_PI / 10.0);
//}
//void CStar::show(HDC hdc)
//{
//	Polygon(hdc, point, 10);
//}
//void CStar::Collision(CStar * List, int counter)
//{
//	for (int i = 1; i < counter; ++i)
//		if (sqrt(pow(this->x - List[i].x, 2) + pow(this->y - List[i].y, 2)) <= this->r + List[i].r)
//		{
//			this->Rspeed *= -1;
//			this->Tspeed *= -1;
//			List[i].Rspeed *= -1;
//			List[i].Tspeed *= -1;
//			break;
//		}
//}
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
//	static int		x, y;
//	static int		counter = 0;
//	static CStar cs[11] = {};
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		SetTimer(hwnd, 1, 33, NULL);
//		GetClientRect(hwnd, &rectView);
//		break;
//	case WM_LBUTTONDOWN:
//		if (counter < 10)
//		{
//			counter++;
//			cs[counter].x = LOWORD(lPARAM);
//			cs[counter].y = HIWORD(lPARAM);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		for (int i = 1; i <= counter; ++i)
//			cs[i].show(hdc);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_TIMER:
//	{
//		for (int i = 1; i <= counter; ++i)
//			cs[i].update();
//		for (int i = 1; i <= counter; ++i)
//			cs[i].Collision(cs, counter);
//		InvalidateRgn(hwnd, NULL, TRUE);
//	}
//	break;
//	case WM_DESTROY:
//		KillTimer(hwnd, 1);
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
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