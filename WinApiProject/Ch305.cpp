#include <Windows.h>
#include <tchar.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
static RECT		rectView;
class cCircle
{
public:
	int x;
	int y;
	int r = 20;
	int Rspeed = 50;
	int Tspeed = 50;
	void update();
	void show(HDC hdc, cCircle cl);
};
void cCircle::update()
{
	if (x + Rspeed > rectView.right) Rspeed *= -1;
	if (x + Rspeed < rectView.left) Rspeed *= -1;
	if (y + Tspeed > rectView.top) Tspeed *= -1;
	if (y + Rspeed < rectView.bottom) Tspeed *= -1;
	x += Rspeed;
	y += Tspeed;
}
void cCircle::show(HDC hdc, cCircle cl)
{
	//if(i%2==0)
	//	Rectangle(hdc, cl[i].x - cl[i].r, cl[i].y - cl[i].r, cl[i].x + cl[i].r, cl[i].y + cl[i].r);
	//else 
	Ellipse(hdc, cl.x - cl.r, cl.y - cl.r, cl.x + cl.r, cl.y + cl.r);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR plszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = _T("Window Class Name");
	RegisterClass(&WndClass);
	hwnd = CreateWindow(_T("Window Class Name"),
			_T("Window Title Name"),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			NULL,
			NULL,
			hInstance,
			NULL
	);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lPARAM)
{
	HDC				hdc;
	PAINTSTRUCT		ps;
	static int		x, y;
	static cCircle cl[11] = {};
	static int		counter = 0;
	switch (iMsg)
	{
	case WM_CREATE:
		SetTimer(hwnd, 1, 33, NULL);
		GetClientRect(hwnd, &rectView);
		break;
	case WM_LBUTTONDOWN:
		if (counter < 10)
		{
			counter++;
			cl[counter].x = LOWORD(lPARAM);
			cl[counter].y = HIWORD(lPARAM);
		}
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int i = 1; i <= counter; ++i)
			cl[i].show(hdc, cl[i]);
		EndPaint(hwnd, &ps); 
		break;
	case WM_TIMER:
	{
		for (int i = 1; i <= counter; ++i)
			cl[i].update();
		InvalidateRgn(hwnd, NULL, TRUE);
	}
		break;
	case WM_DESTROY:
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
}