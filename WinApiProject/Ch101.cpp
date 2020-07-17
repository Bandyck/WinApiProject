//#include <Windows.h>
//#include <tchar.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
//{				   // 프로그램 구분 ID,  신경 안 써도 되는 부분, char *와 같음,     정숫값으로 윈도우가 화면에 출력될 때 형태를 정의.
//				   //                                            요즘은 PSTR대신 씀.
//	HWND hwnd;													  // 핸들 생성.
//	MSG msg;													  // 메시지 생성.
//																  // 이 아래부터는 윈도우 클래스 생성
//	WNDCLASS WndClass;											  // 윈도우 클래스 생성.
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;					  // 윈도우 출력 형태(CS_HREDRAW | CS_VREDRAW). 
//																  //				  = 윈도우의 크기를 변경하면 다시 그리는 형태
//	WndClass.lpfnWndProc = WndProc;								  // 메시지 처리를 위한 함수 이름. CALLBACK 함수 이름 적으면 된다.
//	WndClass.cbClsExtra = 0;									  // 클래스를 위한 여분의 메모리 크기 = 0;
//	WndClass.cbWndExtra = 0;									  // 윈도우를 위한 여분의 메모리 크기 = 0;
//	WndClass.hInstance = hInstance;								  // WindMain( ) 함수의 첫 번째 매개변수 이름을 넣는다.
//	WndClass.hIcon = LoadIcon(NULL, IDI_QUESTION);				  // 기본 아이콘. IDI_APPLICATION. 아래는 다른 ICON들.
//																  /// IDI_ASTERISK, IDI_ERROR, IDI_QUESTION, IDI_WARNING
//																  /// IDI_SHIELD, IDI_HAND, IDI_EXCLAMATION, IDI_INFORMATION
//	WndClass.hCursor = LoadCursor(NULL, IDC_IBEAM);				  // 기본 커서. IDC_ARROW. 아래는 다른 CURSOR들.
//																  /// IDC_APPSTARTING, IDC_CROSS, IDC_HAND, IDC_HELP 
//																  /// IDC_IBEAM, IDC_UPARROW, IDC_WAIT
//																  /// IDC_SIZEALL, IDC_SIZENESW, IDC_SIZENS, IDC_SIZENWSE, IDC_SIZEWE
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); // 윈도우 배경색. WHITE_BRUSH는 흰색 바탕.
//																  /// BLACK_BRUSH, GRAY_BRUSH, DKGRAY_BRUSH, LTGRAY_BRUSH
//																  /// (HBRUSH)CreateSolidBrush(RGB(255, 0, 0)). RGB(0~255)로 표현가능.
//	WndClass.lpszMenuName = NULL;								  // 메뉴 이름.
//	WndClass.lpszClassName = _T("Window Class Name");			  // 윈도우 클래스의 이름. 
//																  // _T를 붙여줘야 멀티바이트, 유니코드 상관 없이 처리 가능.
//	RegisterClass(&WndClass);									  // 만든 클래스를 커널에 등록해주는 함수. (&Class의 이름).
//																  // 이 아래부터는 윈도우 생성.
//	hwnd = CreateWindow(										  // 위에서 생성한 핸들에 CreateWindow( )로 값 반환.
//		_T("Window Class Name"),								  // 윈도우 클래스 이름.
//		_T("홍길동의 첫 번째 윈도우"),							  // 윈도우 타이틀 이름. 타이틀 바에 나타나는 문자열.
//		WS_OVERLAPPEDWINDOW,									  // 윈도우 스타일. WS_OVERLAPPEDWINDOW.
//																  // WS_OVERLAPPEDWINDOW = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME
//																  // 타이틀 바 + 최소화 버튼 + 최대화 버튼 + 닫기 버튼 + 오른쪽 마우스 버튼 가능.
//																  /// WS_OVERLAPPED, WS_POPUP, WS_CHILD, WS_MINIMIZE, WS_MAXIMIZE, WS_VISIBLE
//																  /// WS_BORDER, WS_DLGFRAME, WS_VSCROLL, WS_HSCROLL
//																  /// WS_SYSMENU, WS_THICKFRAME, WS_MINIMIZEBOX, WS_MAXIMIZEBOX
//		200,														// 윈도우 위치 x 좌표. CW_USEDEFAULT = 커널에 의한 기본 값.
//		300,														// 윈도우 위치 y 좌표. CW_USEDEFAULT.
//		600,														// 윈도우 가로 크기.   CW_USEDEFAULT.
//		400,														// 윈도우 세로 크기.   CW_USEDEFAULT.
//		NULL,														// 부모 윈도우 핸들.		// 초보는 그대로.
//		NULL,														// 메뉴 핸들.				// 초보는 그대로.
//		hInstance,													// 응용 프로그램 인스턴스.  // 초보는 그대로.
//		NULL														// 생성 윈도우 정보.		// 초보는 그대로.
//	);
//	// 윈도우를 화면에 보여주는 두 함수.
//	ShowWindow(hwnd, nCmdShow);										// hwnd = 나타낼 윈도우 핸들 값.
//																	// nCmdShow = 정숫값으로 윈도우가 화면에 출력될 때 형태를 정의.
//																	/// SW_HIDE, SW_MAXIMIZE, SW_MINIMIZE, SW_SHOW
//	UpdateWindow(hwnd);
//	// 윈도우 프로그램에서 메시지를 처리하는 과정.
//	// 키보드, 마우스 등에 의해 이벤트 발생.
//	// 이벤트 발생을 정수값으로 전환해서 메시지 큐에 차례로 넣는다.
//	// WinMain( ) 함수는 이 쌓여있는 메시지 큐에서 맨 앞에 대기 중인 메시지를 꺼내고 해석해 메시지 처리 함수에 보낸다.
//	// 이 아래부터는 메시지 처리.
//	while (GetMessage(&msg, NULL, 0, 0))							// GetMessage( ) 함수가 메시지 큐에서 메시지를 꺼낸다.
//																	// &msg = 메시지가 저장된 MSG 구조체에 대한 포인터
//	{																// 꺼낸 메시지를 위 함수에서 msg에 저장했으니,
//		TranslateMessage(&msg);										// TranslateMessage( ) 함수로 msg에 저장된 메시지를 적절하게 변형. 
//		DispatchMessage(&msg);                                      // DispatchMessage( ) 함수는 메시지를 처리하는 함수에 msg를 보냄.
//	}
//	return (int)msg.wParam;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) // hwnd = 생성된 윈도우 핸들.
//{					  														 // Winmain( )에서 CreateWindow( ) 함수로 만든 이름.
//																			 // iMsg = 매크로로 영어로 바꿔준 메시지.
//																			 // wParam, lParam. 메시지를 해석하는 방법.
//	switch (iMsg)															 // 메시지에 종류에 따라 다른 처리가 필요하므로 switch-case
//	{																		 // 프로그램에서 처리를 원하는 메시지만 case문으로 만든다.
//	case WM_CREATE:															 // 윈도우 생성시 처리.
//		break;
//	case WM_DESTROY:														 // 윈도우 파괴시 처리.
//		PostQuitMessage(0);													 // 거의 기본 값으로 WM_DESTROY에 넣어둬야함.
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);						 // 넘겨받은 메시지 중 위에서 처리 안한 것은 
//}																			 // 기본 메시지 처리 함수에서 담당하라고 하는 함수.
