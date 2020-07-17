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
//	static TCHAR	str[100];						// �� �� static���� ��������� �Ѵ�.
//	static int		count;							// �޽��� �ϳ��� ó���ϰ� ���� WndProc( )�Լ��� ����Ǹ鼭   
//	switch (iMsg)									// �� �޽����� ������ ������ ���ư������Ƿ� ���������� static���� ����.
//	{
//	case WM_CREATE:
//		count = 0;									// �����찡 ó�� ��������� count ������ 0���� �ʱ�ȭ.
//		break;
//	case WM_CHAR:
//		hdc = GetDC(hwnd);					
//		str[count++] = wParam;						// ����Ű�� ���� ������ WM_CHAR �޽����� �߻��ϰ� �Էµ� ���ڴ� wParam�� ����.
//		str[count] = NULL;							// count�� �Էµ� ������ ������ �Է¹���.
//		TextOut(hdc, 0, 0, str, _tcslen(str));
//		ReleaseDC(hwnd, hdc);							
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}