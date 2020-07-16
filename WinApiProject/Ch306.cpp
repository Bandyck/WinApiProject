//#include <Windows.h>
//#include <tchar.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
//#include <time.h>
//static RECT		rectView;
//class cRect
//{
//public:
//	POINT point[4];
//	int x;
//	int y;
//	int r = 20;
//	int Rspeed = 50;
//	int Tspeed = 50;
//	void update();
//	void show(HDC hdc);
//	void Collision(cRect * List, int counter);
//};
//void cRect::update()
//{
//	if (x + Rspeed > rectView.right) { /*x = x + Rspeed - rectView.right;*/ Rspeed *= -1; }
//	if (x + Rspeed < rectView.left) { /*x = rectView.left - (x + Rspeed);*/ Rspeed *= -1; }
//	if (y + Tspeed > rectView.top) { /*y = y + Tspeed - rectView.top;*/ Tspeed *= -1; }
//	if (y - Tspeed < rectView.bottom) { /*y = rectView.bottom - (y + Tspeed);*/ Tspeed *= -1; }
//	x += Rspeed;
//	y += Tspeed;
//	
//	this->point[0].x = this->x - this->r;
//	this->point[0].y = this->y - this->r;
//	this->point[1].x = this->x + this->r;
//	this->point[1].y = this->y - this->r;
//	this->point[2].x = this->x + this->r;
//	this->point[2].y = this->y + this->r;
//	this->point[3].x = this->x - this->r;
//	this->point[3].y = this->y + this->r;
//}
//void cRect::show(HDC hdc)
//{
//	Polygon(hdc, point, 4);
//}
//void cRect::Collision(cRect * List, int counter)
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
//	static cRect cr[11] = {};
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
//			cr[counter].x = LOWORD(lPARAM);
//			cr[counter].y = HIWORD(lPARAM);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		for (int i = 1; i <= counter; ++i)
//			cr[i].show(hdc);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_TIMER:
//	{
//		for (int i = 1; i <= counter; ++i)
//			cr[i].update();
//		for (int i = 1; i <= counter; ++i)
//			cr[i].Collision(cr, counter);
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