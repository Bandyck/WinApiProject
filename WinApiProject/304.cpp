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
		break;														// ������ �Է��� �ƴ� �ֱ������� ��ȣ�� �ַ��� Ÿ�̸� �޽����� �̿���.
	case WM_KEYDOWN:												// SetTimer( ) �Լ�.
		if (wParam == VK_RIGHT) SetTimer(hwnd, 1, 70, NULL);		// hwnd = ������ �ڵ� ��.
		break;														// 1 = Timer�� ID. ���� ���� Timer�� ���� �� �����Ƿ� �̸� �����ϴ� ����.
	case WM_TIMER:													// 70 = 70�и���. 1�� = 1000�и���.
		x += 40;													// NULL = Ÿ�̸Ӱ� ������ WM_TIMER �޽����� ���� �Լ� �̸�.
		if (x + 20 > rectView.right) x -= 40;						//		  NULL �̸� WndProc( ) �Լ��� �޴´�.
		InvalidateRgn(hwnd, NULL, TRUE);
		break;
	case WM_DESTROY:
		KillTimer(hwnd, 1);											// KillTimer( ) �Լ�. Timer( )�� ������ų �� ���� �Լ�.
		PostQuitMessage(0);											// hwnd = ������ �ڵ� ��.
		break;														// 1 = ������ų Timer�� ID.
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
}