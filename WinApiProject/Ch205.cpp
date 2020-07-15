//#include <Windows.h>
//#include <tchar.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
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
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	RECT rect1, rect2, rect3, rect4;
//	HBRUSH hBrush, oldBrush;
//	static bool leftflag = false, rightflag = false, topflag = false, bottomflag = false;
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		rect1.left = 100, rect1.top = 200, rect1.right = 200, rect1.bottom = 300; // 왼쪽
//		rect2.left = 300, rect2.top = 200, rect2.right = 400, rect2.bottom = 300; // 오른쪽
//		rect3.left = 200, rect3.top = 100, rect3.right = 300, rect3.bottom = 200; // 위
//		rect4.left = 200, rect4.top = 300, rect4.right = 300, rect4.bottom = 400; // 아래
//		Rectangle(hdc, rect1.left, rect1.top, rect1.right, rect1.bottom);			// 왼쪽
//		Rectangle(hdc, rect2.left, rect2.top, rect2.right, rect2.bottom);			// 오른쪽
//		Rectangle(hdc, rect3.left, rect3.top, rect3.right, rect3.bottom);			// 위
//		Rectangle(hdc, rect4.left, rect4.top, rect4.right, rect4.bottom);			// 아래
//		Rectangle(hdc, (rect1.left + rect2.left) / 2, (rect3.top + rect4.top) / 2, (rect1.right + rect2.right) / 2, (rect3.bottom + rect4.bottom) / 2); // 중간
//		DrawText(hdc, _T("왼쪽"), 2, &rect1, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
//		DrawText(hdc, _T("오른쪽"), 3, &rect2, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
//		DrawText(hdc, _T("위쪽"), 2, &rect3, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
//		DrawText(hdc, _T("아래쪽"), 3, &rect4, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
//		if (rightflag == true | leftflag == true | topflag == true | bottomflag == true)
//		{
//			hBrush = CreateSolidBrush(RGB(255, 0, 0));
//			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
//			if (leftflag == true)
//				Rectangle(hdc, rect1.left, rect1.top, rect1.right, rect1.bottom);
//			else if (rightflag == true)
//				Rectangle(hdc, rect2.left, rect2.top, rect2.right, rect2.bottom);
//			else if (topflag == true)
//				Rectangle(hdc, rect3.left, rect3.top, rect3.right, rect3.bottom);
//			else
//				Rectangle(hdc, rect4.left, rect4.top, rect4.right, rect4.bottom);
//			SelectObject(hdc, oldBrush);
//			DeleteObject(hBrush);
//		}
//		else
//		{
//			Rectangle(hdc, rect1.left, rect1.top, rect1.right, rect1.bottom);			// 왼쪽
//			Rectangle(hdc, rect2.left, rect2.top, rect2.right, rect2.bottom);			// 오른쪽
//			Rectangle(hdc, rect3.left, rect3.top, rect3.right, rect3.bottom);			// 위
//			Rectangle(hdc, rect4.left, rect4.top, rect4.right, rect4.bottom);			// 아래
//			Rectangle(hdc, (rect1.left + rect2.left) / 2, (rect3.top + rect4.top) / 2, (rect1.right + rect2.right) / 2, (rect3.bottom + rect4.bottom) / 2); // 중간
//			DrawText(hdc, _T("왼쪽"), 2, &rect1, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
//			DrawText(hdc, _T("오른쪽"), 3, &rect2, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
//			DrawText(hdc, _T("위쪽"), 2, &rect3, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
//			DrawText(hdc, _T("아래쪽"), 3, &rect4, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
//		}
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_KEYDOWN:
//		if (wParam == VK_RIGHT)
//		{
//			rightflag = true;
//			InvalidateRgn(hwnd, NULL, true);
//			break;
//		}
//		if (wParam == VK_LEFT)
//		{
//			leftflag = true;
//			InvalidateRgn(hwnd, NULL, true);
//			break;
//		}
//		if (wParam == VK_UP)
//		{
//			topflag = true;
//			InvalidateRgn(hwnd, NULL, true);
//			break;
//		}
//		if (wParam == VK_DOWN)
//		{
//			bottomflag = true;
//			InvalidateRgn(hwnd, NULL, true);
//			break;
//		}
//		break;
//	case WM_KEYUP:
//		if (wParam == VK_RIGHT)
//		{
//			rightflag = false;
//			InvalidateRgn(hwnd, NULL, true);
//			break;
//		}
//		if (wParam == VK_LEFT)
//		{
//			leftflag = false;
//			InvalidateRgn(hwnd, NULL, true);
//			break;
//		}
//		if (wParam == VK_UP)
//		{
//			topflag = false;
//			InvalidateRgn(hwnd, NULL, true);
//			break;
//		}
//		if (wParam == VK_DOWN)
//		{
//			bottomflag = false;
//			InvalidateRgn(hwnd, NULL, true);
//			break;
//		}
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}
