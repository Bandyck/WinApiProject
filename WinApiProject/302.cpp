//#include <Windows.h>
//#include <TCHAR.H>
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
//	static RECT		rectView;						   // 윈도우 크기를 벗어나지 않게 하기 위해서 윈도우의 크기를 알아야함.
//													   // 그래서 RECT 구조체 선언.
//	switch (iMsg)
//	{												   // GetClientRect( ) 함수. 
//	case WM_CREATE:									   // 클라이언트 영역의 왼쪽 상단 꼭지점 좌표와 오른쪽 하단 꼭지점 좌표가 RECT 구조체에 저장.
//		GetClientRect(hwnd, &rectView);				   // hwnd = 측정하려는 윈도우의 핸들.
//		x = 20, y = 20;								   // &rectView = 값을 저장할 RECT 구조체의 주소.
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);					
//		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
//		EndPaint(hwnd, &ps);							
//		break;
//	case WM_KEYDOWN:
//		if (wParam == VK_RIGHT)
//		{
//			x += 40;
//			if (x + 20 > rectView.right) x -= 40;
//		}
//		InvalidateRgn(hwnd, NULL, TRUE);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}