#include <Windows.h>
#include <TCHAR.H>

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
	static RECT		rectView;
	switch (iMsg)
	{
	case WM_CREATE:
		GetClientRect(hwnd, &rectView);
		x = 20, y = 20;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);					
		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
		EndPaint(hwnd, &ps);							
		break;														// 유저의 입력이 아닌 주기적으로 신호를 주려면 타이머 메시지를 이용함.
	case WM_KEYDOWN:												// SetTimer( ) 함수.
		if (wParam == VK_RIGHT) SetTimer(hwnd, 1, 70, NULL);		// hwnd = 윈도우 핸들 값.
		break;														// 1 = Timer의 ID. 여러 개의 Timer가 있을 수 있으므로 이를 구별하는 숫자.
	case WM_TIMER:													// 70 = 70밀리초. 1초 = 1000밀리초.
		x += 40;													// NULL = 타이머가 보내는 WM_TIMER 메시지를 받을 함수 이름.
		if (x + 20 > rectView.right) x -= 40;						//		  NULL 이면 WndProc( ) 함수가 받는다.
		InvalidateRgn(hwnd, NULL, TRUE);
		break;
	case WM_DESTROY:
		KillTimer(hwnd, 1);											// KillTimer( ) 함수. Timer( )를 정지시킬 때 쓰는 함수.
		PostQuitMessage(0);											// hwnd = 윈도우 핸들 값.
		break;														// 1 = 정지시킬 Timer의 ID.
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
}