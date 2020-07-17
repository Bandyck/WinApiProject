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
//	static TCHAR	str[100];
//	static int		count;
//	switch (iMsg)
//	{
//	case WM_CREATE:									   // TextOut의 중복된 부분을 없애기 위해 나온 함수.
//		count = 0;									   // InvalidateRgn( ) 함수. 화면 영역 수정 함수.
//		break;										   // 특정 영역에 WM_PAINT 메시지를 강제로 발생시키는 효과
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);					
//		TextOut(hdc, 0, 0, str, _tcslen(str));		
//		EndPaint(hwnd, &ps);							
//		break;
//	case WM_CHAR:
//		str[count++] = wParam;
//		str[count] = NULL;								// InvalidateRgn(hwnd, NULL, TRUE) = 윈도우 화면 전체를 다 삭제했다가 다시 그림.
//		InvalidateRgn(hwnd, NULL, TRUE);				// hwnd = 수정 영역이 포함된 윈도우의 핸들 값
//	case WM_DESTROY:									// NULL = 두 번째 인자는 수정 영역에 대한 핸들 값인데 NULL = 클라이언드 영역 전체.
//		PostQuitMessage(0);								// TRUE = 수정 영역을 모두 삭제. FALSE = 수정 부분만 추가(뒤에 남아 있음)
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}