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
//	RECT rect;
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		rect.left = 100;
//		rect.top = 100;
//		rect.right = 500;
//		rect.bottom = 500;
//		Rectangle(hdc, rect.left - 5, rect.top - 5, rect.right + 5, rect.bottom + 5);
//		DrawText(hdc, _T("HelloWorld"), 10, &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
//		DrawText(hdc, _T("HelloWorld"), 10, &rect, DT_SINGLELINE | DT_BOTTOM | DT_RIGHT);
//		DrawText(hdc, _T("HelloWorld"), 10, &rect, DT_SINGLELINE | DT_TOP | DT_LEFT);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}
