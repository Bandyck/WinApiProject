#include "stdafx.h"
#include "WinApiExercise.h"
#include <commdlg.h>
#pragma comment(lib, "msimg32.lib")
#define _USE_MATH_DEFINES
#include <math.h>
#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

// >> :

RECT rectView;
#define IDC_CHILD_BTN1 1000
#define IDC_CHILD_BTN2 1001
#define IDC_CHILD_BTN3 1002
HWND childHwnd[2];
LRESULT CALLBACK ChildWnd1Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWnd2Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
int Figure;
void DrawStar(HDC hdc, double x, double y, double r);
double CrossDotX(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
double CrossDotY(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);

// >> :
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPIEXERCISE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPIEXERCISE));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}
//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPIEXERCISE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPIEXERCISE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWnd1Proc;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child1");
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWnd2Proc;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child2");
	RegisterClassExW(&wcex);

	return RegisterClassExW(&wcex);
}
//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int mx, my;
    switch (message)
    {
	case WM_CREATE:
		mx = 0;
		my = 0;
		GetClientRect(hWnd, &rectView);
		childHwnd[0] = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			_T("Parent"),
			NULL,
			WS_CHILD | WS_VISIBLE,
			0,
			0,
			rectView.right / 2 - 1,
			rectView.bottom / 2 - 1,
			hWnd,
			NULL,
			hInst,
			NULL
		);
		childHwnd[1] = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			_T("Child1"),
			NULL,
			WS_CHILD | WS_VISIBLE,
			0,
			rectView.bottom / 2 + 1,
			rectView.right / 2 - 1,
			rectView.bottom / 2 - 1,
			hWnd,
			NULL,
			hInst,
			NULL
		);
		childHwnd[2] = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			_T("Child2"),
			NULL,
			WS_CHILD | WS_VISIBLE,
			rectView.right / 2 + 1,
			0,
			rectView.right / 2 - 1,
			rectView.bottom,
			hWnd,
			NULL,
			hInst,
			NULL
		);
		break;
	case WM_LBUTTONDOWN:
	{
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		InvalidateRgn(hWnd, NULL, false);
	}
		break;
	case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			switch (Figure)
			{
			case 1:
				Rectangle(hdc, mx - 10, my - 10, mx + 10, my + 10);
				break;
			case 2:
				Ellipse(hdc, mx - 10, my - 10, mx + 10, my + 10);
				break;
			case 3:
				DrawStar(hdc, mx, my, 10);
				break;
			default:
				break;
			}
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
LRESULT CALLBACK ChildWnd1Proc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch (iMsg)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, NULL);
		break;
	case WM_TIMER:
		InvalidateRgn(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		switch (Figure)
		{
		case 1:
			Rectangle(hdc, 50, 50, 250, 250);
			break;
		case 2:
			Ellipse(hdc, 50, 50, 250, 250);
			break;
		case 3:
			DrawStar(hdc, 150, 150, 100);
			break;
		default:
			break;
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		return 0;
	default:
		break;
	}
	return DefMDIChildProc(hWnd, iMsg, wParam, lParam);
}
LRESULT CALLBACK ChildWnd2Proc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hButton1;
	HWND hButton2;
	HWND hButton3;
	switch (iMsg)
	{
	case WM_CREATE:
		hButton1 = CreateWindow(
			_T("button"),
			_T("사각형 버튼"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			250,
			0,
			200,
			100,
			hWnd,
			(HMENU)IDC_CHILD_BTN1,
			hInst,
			NULL);
		hButton2 = CreateWindow(
			_T("button"),
			_T("원 버튼"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			250,
			100,
			200,
			100,
			hWnd,
			(HMENU)IDC_CHILD_BTN2,
			hInst,
			NULL);
		hButton3 = CreateWindow(
			_T("button"),
			_T("별 버튼"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			250,
			200,
			200,
			100,
			hWnd,
			(HMENU)IDC_CHILD_BTN3,
			hInst,
			NULL);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_CHILD_BTN1:
			Figure = 1;
			return 0;
		case IDC_CHILD_BTN2:
			Figure = 2;
			return 0;
		case IDC_CHILD_BTN3:
			Figure = 3;
			return 0;
		}
		return 0;
	case WM_DESTROY:
		return 0;
	default:
		break;
	}
	return DefMDIChildProc(hWnd, iMsg, wParam, lParam);
}
void DrawStar(HDC hdc, double x, double y, double r)
{
	double dx4 = 0;
	dx4 = CrossDotX(x, x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r, y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
	double dy4 = 0;
	dy4 = CrossDotY(x, x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r, y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));
	double dx8 = 2 * x - dx4;
	double dy8 = dy4;
	double dy6 = 0;
	dy6 = CrossDotY(x - r*cos(M_PI / 10.0), x + r*sin(M_PI / 5.0), x + r*cos(M_PI / 10.0), x - (r*sin(M_PI / 5.0)), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0), y - r*sin(M_PI / 10.0), y + r*cos(M_PI / 5.0));

	POINT point[10] = { { x, y - r },
	{ x + (r*sin(M_PI / 5.0) *(1 - sin(M_PI / 10.0)) / (1 + cos(M_PI / 5.0))),y - r*sin(M_PI / 10.0) },
	{ x + r*cos(M_PI / 10.0),y - r*sin(M_PI / 10.0) },
	{ dx4, dy4 },
	{ x + r*sin(M_PI / 5.0), y + r*cos(M_PI / 5.0) },
	{ x, dy6 },
	{ x - r*sin(M_PI / 5.0), y + r*cos(M_PI / 5.0) },
	{ dx8, dy8 },
	{ x - r*cos(M_PI / 10.0),y - r*sin(M_PI / 10.0) },
	{ x - (r*sin(M_PI / 5.0) *(1 - sin(M_PI / 10.0)) / (1 + cos(M_PI / 5.0))),y - r*sin(M_PI / 10.0) } };
	Polygon(hdc, point, 10);
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