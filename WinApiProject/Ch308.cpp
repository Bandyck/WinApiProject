#include <Windows.h>
#include <tchar.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
static RECT		rectView;
double CrossDotX(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
double CrossDotY(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
class cStar
{
public:
	POINT point[10];
	int x;
	int y;
	int r = 20;
	int Rspeed = 50;
	int Tspeed = 50;
	void update();
	void show(HDC hdc);
	void Collision(cStar * List, int counter);
};
void cStar::update()
{
	if (this->x + this->Rspeed > rectView.right) { this->Rspeed *= -1; }
	if (this->x + this->Rspeed < rectView.left) { this->Rspeed *= -1; }
	if (this->y + this->Tspeed > rectView.top) { this->Tspeed *= -1; }
	if (this->y - this->Tspeed < rectView.bottom) { this->Tspeed *= -1; }
	this->x += this->Rspeed;
	this->y += this->Tspeed;
	double dx4 = 0;
	dx4 = CrossDotX(x, x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r, y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
	double dy4 = 0;
	dy4 = CrossDotY(x, x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r, y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
	double dx8 = 2 * x - dx4;
	double dy8 = dy4;
	double dy6 = 0;
	dy6 = CrossDotY(x - r*cos(M_PI / 10.0), x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
	this->point[0].x = this->x;
	this->point[0].y = this->y - this->r;
	this->point[1].x = this->x + (this->r*sin(M_PI / 5.0) *(1 - sin(M_PI / 10.0)) / (1 + cos(M_PI / 5.0)));
	this->point[1].y = this->y - this->r*sin(M_PI / 10.0);
	this->point[2].x = this->x + this->r*cos(M_PI / 10.0);
	this->point[2].y = this->y - this->r*sin(M_PI / 10.0);
	this->point[3].x = dx4;
	this->point[3].y = dy4;
	this->point[4].x = this->x + this->r*sin(M_PI / 5.0);
	this->point[4].y = this->y + this->r*cos(M_PI / 5.0);
	this->point[5].x = this->x;
	this->point[5].y = dy6;
	this->point[6].x = this->x - this->r*sin(M_PI / 5.0);
	this->point[6].y = this->y + this->r*cos(M_PI / 5.0);
	this->point[7].x = dx8;
	this->point[7].y = dy8;
	this->point[8].x = this->x - this->r*cos(M_PI / 10.0);
	this->point[8].y = this->y - this->r*sin(M_PI / 10.0);
	this->point[9].x = this->x - (this->r*sin(M_PI / 5.0) *(1 - sin(M_PI / 10.0)) / (1 + cos(M_PI / 5.0)));
	this->point[9].y = this->y - this->r*sin(M_PI / 10.0);
}
void cStar::show(HDC hdc)
{
	Polygon(hdc, point, 10);
}
void cStar::Collision(cStar * List, int counter)
{
	for (int i = 1; i < counter; ++i)
		if (sqrt(pow(this->x - List[i].x, 2) + pow(this->y - List[i].y, 2)) <= this->r + List[i].r)
		{
			this->Rspeed *= -1;
			this->Tspeed *= -1;
			List[i].Rspeed *= -1;
			List[i].Tspeed *= -1;
			break;
		}
}
class cRect
{
public:
	POINT point[4];
	int x;
	int y;
	int r = 20;
	int Rspeed = 50;
	int Tspeed = 50;
	void update();
	void show(HDC hdc);
	void Collision(cRect * List, int counter);
};
void cRect::update()
{
	if (this->x + this->Rspeed > rectView.right) { this->Rspeed *= -1; }
	if (this->x + this->Rspeed < rectView.left) { this->Rspeed *= -1; }
	if (this->y + this->Tspeed > rectView.top) { this->Tspeed *= -1; }
	if (this->y - this->Tspeed < rectView.bottom) { this->Tspeed *= -1; }
	this->x += this->Rspeed;
	this->y += this->Tspeed;

	
	//for (int i = 0; i < 4; ++i)
	//{

	//}
	this->point[0].x = this->x - this->r;
	this->point[0].y = this->y - this->r;
	this->point[1].x = this->x + this->r;
	this->point[1].y = this->y - this->r;
	this->point[2].x = this->x + this->r;
	this->point[2].y = this->y + this->r;
	this->point[3].x = this->x - this->r;
	this->point[3].y = this->y + this->r;
}
void cRect::show(HDC hdc)
{
	Polygon(hdc, this->point, 4);
}
void cRect::Collision(cRect * List, int counter)
{
	for (int i = 1; i < counter; ++i)
		if (sqrt(pow(this->x - List[i].x, 2) + pow(this->y - List[i].y, 2)) <= this->r + List[i].r)
		{
			this->Rspeed *= -1;
			this->Tspeed *= -1;
			List[i].Rspeed *= -1;
			List[i].Tspeed *= -1;
			break;
		}
}
class cCircle
{
public:
	int x;
	int y;
	int r = 20;
	int Rspeed = 50;
	int Tspeed = 50;
	void update();
	void show(HDC hdc);
	void Collision(cCircle * List, int counter);
};
void cCircle::update()
{
	if (this->x + this->Rspeed > rectView.right) { this->Rspeed *= -1; }
	if (this->x + this->Rspeed < rectView.left) { this->Rspeed *= -1; }
	if (this->y + this->Tspeed > rectView.top) { this->Tspeed *= -1; }
	if (this->y - this->Tspeed < rectView.bottom) { this->Tspeed *= -1; }
	this->x += this->Rspeed;
	this->y += this->Tspeed;
}
void cCircle::show(HDC hdc)
{
	Ellipse(hdc, this->x - this->r, this->y - this->r, this->x + this->r, this->y + this->r);
}
void cCircle::Collision(cCircle * List, int counter)
{
	for (int i = 1; i < counter; ++i)
		if (sqrt(pow(this->x - List[i].x, 2) + pow(this->y - List[i].y, 2)) <= this->r + List[i].r)
		{
			this->Rspeed *= -1;
			this->Tspeed *= -1;
			List[i].Rspeed *= -1;
			List[i].Tspeed *= -1;
		}
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
	static int		counter = 0;
	static cStar cs[31] = {};
	static cRect cr[31] = {};
	static cCircle cl[31] = {};
	switch (iMsg)
	{
	case WM_CREATE:
		SetTimer(hwnd, 1, 33, NULL);
		GetClientRect(hwnd, &rectView);
		break;
	case WM_LBUTTONDOWN:
		if (counter < 30)
		{
			counter++;
			if (counter % 3 == 1)
			{
				cs[counter].x = LOWORD(lPARAM);
				cs[counter].y = HIWORD(lPARAM);
			}
			else if (counter % 3 == 2)
			{
				cr[counter].x = LOWORD(lPARAM);
				cr[counter].y = HIWORD(lPARAM);
			}
			else
			{
				cl[counter].x = LOWORD(lPARAM);
				cl[counter].y = HIWORD(lPARAM);
			}
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int i = 1; i <= counter; i += 3)
			cs[i].show(hdc);
		for (int i = 2; i <= counter; i += 3)
			cr[i].show(hdc);
		for (int i = 3; i <= counter; i += 3)
			cl[i].show(hdc);
		EndPaint(hwnd, &ps);
		break;
	case WM_TIMER:
	{
		for (int i = 1; i <= counter; i += 3)
			cs[i].update();
		for (int i = 2; i <= counter; i += 3)
			cr[i].update();
		for (int i = 3; i <= counter; i += 3)
			cl[i].update();
		for (int i = 1; i <= counter; i += 3)
			cs[i].Collision(cs, counter);
		for (int i = 2; i <= counter; i += 3)
			cr[i].Collision(cr, counter);
		for (int i = 3; i <= counter; i += 3)
			cl[i].Collision(cl, counter);
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
double CrossDotX(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4)
{
	double a, b, c, d, e, f;
	double x, y;

	a = y1 - y2;
	b = -(x1 - x2);
	c = y3 - y4;
	d = -(x3 - x4);
	e = a*x1 + b*y1;
	f = c*x3 + d*y3;

	x = ((e*d - b*f)) / ((a*d - b*c));

	return x;
}
double CrossDotY(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4)
{
	double a, b, c, d, e, f;
	double x, y;

	a = y1 - y2;
	b = -(x1 - x2);
	c = y3 - y4;
	d = -(x3 - x4);
	e = a*x1 + b*y1;
	f = c*x3 + d*y3;

	y = ((a*f - e*c)) / ((a*d - b*c));

	return y;
}