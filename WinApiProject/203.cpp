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
//	PAINTSTRUCT		ps;							// DrawText( )	함수. 박스 영역을 지정하고 그 안에 출력.			
//	RECT			rect;						// 이 박스를 이용하기 위해 RECT	구조체 먼저 선언.		
//	switch (iMsg)
//	{											  
//	case WM_CREATE:								 		   
//		break;																	   
//	case WM_PAINT:																   
//		hdc = BeginPaint(hwnd, &ps);											   
//		rect.left = 50;							// 박스 왼쪽 좌표.					
//		rect.top    = 40;                       // 박스 위쪽 좌표.
//		rect.right  = 200;						// 박스 오른쪽 좌표.
//		rect.bottom = 120;						// 박스 아래쪽 좌표.
//		DrawText(hdc, 									// hdc = BeginPaint( )로 얻어온 화면 영역.
//			_T("HelloWorld"), 							// 출력할 텍스트 문자열.
//			10, 										// 출력할 문자열 길이.
//			&rect,										// 지정할 박스 영역의 좌표가 저장된 구조체 변수의 주소값.
//			DT_SINGLELINE | DT_CENTER | DT_VCENTER);	// 어느 위치에 어떻게 문자열을 출력할지를 알려주는 플래그 값.	
//														// 여기선 한 줄로, 좌우중앙, 상하중앙에 출력.
//		EndPaint(hwnd, &ps);							/// DT_SINGLELINE, DT_LEFT, DT_CENTER, DT_RIGHT, DT_VCENTER
//		break;											/// DT_TOP, DT_BOTTOM, DT_CALCRECT, DT_NOCLIP
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lPARAM));
//}