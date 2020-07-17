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
//		else if (wParam == VK_RETURN)					// EnterŰ ó��.
//		{												// count�� �ʱ�ȭ��Ű��, ���� �࿡ ����ϱ� ���� yPos�� ������.
//			count = 0;									// �׷���, �ڵ带 �� ���� �˰����� ���� �࿡ ��½ÿ��� ���� ���� �� ���󰡹���.
//			yPos += 20;									// WM_PAINT�� �ٽ� �ҷ����Ƿ�
//		}												// �׷��� �̰� �ذ��Ϸ��� 211�� ���� DrawText( )�� �̿��� ���� ����� �ϰų�
//		else str[count++] = wParam;						// 2���� �迭�� �����ؼ� ������ �Է��ߴ� ���� �����صξ���Ѵ�.
//		str[count] = NULL;
//		InvalidateRgn(hwnd, NULL, TRUE);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}