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
//	static int		count, yPos;
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		count = 0;
//		yPos = 0;
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);					
//		TextOut(hdc, 0, yPos, str, _tcslen(str));		
//		EndPaint(hwnd, &ps);							
//		break;
//	case WM_CHAR:
//		if (wParam == VK_BACK && count > 0) count--;
//		else if (wParam == VK_RETURN)					// Enter키 처리.
//		{												// count를 초기화시키고, 다음 행에 출력하기 위해 yPos를 더해줌.
//			count = 0;									// 그러나, 코드를 잘 보면 알겠지만 다음 행에 출력시에는 전에 행이 다 날라가버림.
//			yPos += 20;									// WM_PAINT를 다시 불러오므로
//		}												// 그래서 이걸 해결하려면 211에 나올 DrawText( )를 이용해 영역 출력을 하거나
//		else str[count++] = wParam;						// 2차원 배열을 선언해서 이전에 입력했던 값을 저장해두어야한다.
//		str[count] = NULL;
//		InvalidateRgn(hwnd, NULL, TRUE);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}