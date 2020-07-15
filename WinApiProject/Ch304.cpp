//#include <Windows.h>
//#include <tchar.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
//#include <time.h>
//void DrawStar(HDC hdc, double x, double y, double r);
//double CrossDotX(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
//double CrossDotY(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//static RECT rectView;
//class cCircle
//{
//public:
//	int x;
//	int y;
//	int r = 10;
//	int rad = 30;
//	int speed = 100;
//	void Update();
//	void Show();
//};
//void cCircle::Update()
//{
//	int Lspeed = speed;
//	int Tspeed = speed;
//	if (x+Lspeed > rectView.right) Lspeed *= -1;
//	if (x+Lspeed < rectView.left) Lspeed *= -1;
//	if (y+Tspeed > rectView.bottom) Tspeed *= -1;
//	if (y+Tspeed < rectView.top) Tspeed *= -1;
//	x += Lspeed;
//	y += Tspeed;
//	r = r;
//}
//void Show()
//{
//
//}
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
//	static cCircle cList[11] = {};
//	static int counter = 0;
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		GetClientRect(hwnd, &rectView);
//		SetTimer(hwnd, 1, 1000, NULL);
//		break;
//	case WM_LBUTTONDOWN:
//		if (counter != 10)
//		{
//			counter++;
//			cList[counter].x = LOWORD(lPARAM);
//			cList[counter].y = HIWORD(lPARAM);
//			for (int i = counter-1; i >=1; --i)
//				cList[i].Update();
//			InvalidateRgn(hwnd, NULL, TRUE);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//
//		for (int i = 1; i <= counter; ++i)
//		{
//			Ellipse(hdc, cList[i].x - cList[i].r, cList[i].y - cList[i].r, cList[i].x + cList[i].r, cList[i].y + cList[i].r);
//		}
//
//
//		EndPaint(hwnd, &ps);
//		break;
//
//	case WM_LBUTTONUP:
//		break;
//	case WM_TIMER:
//
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}