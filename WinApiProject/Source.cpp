//#include <Windows.h>
//#include <tchar.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
//{				   // ���α׷� ���� ID,  �Ű� �� �ᵵ �Ǵ� �κ�, char *�� ����,     ���������� �����찡 ȭ�鿡 ��µ� �� ���¸� ����.
//				   //                                            ������ PSTR��� ��.
//	HWND hwnd;													  // �ڵ� ����.
//	MSG msg;													  // �޽��� ����.
//																  // �� �Ʒ����ʹ� ������ Ŭ���� ����
//	WNDCLASS WndClass;											  // ������ Ŭ���� ����.
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;					  // ������ ��� ����(CS_HREDRAW | CS_VREDRAW). 
//																  //				  = �������� ũ�⸦ �����ϸ� �ٽ� �׸��� ����
//	WndClass.lpfnWndProc = WndProc;								  // �޽��� ó���� ���� �Լ� �̸�. CALLBACK �Լ� �̸� ������ �ȴ�.
//	WndClass.cbClsExtra = 0;									  // Ŭ������ ���� ������ �޸� ũ�� = 0;
//	WndClass.cbWndExtra = 0;									  // �����츦 ���� ������ �޸� ũ�� = 0;
//	WndClass.hInstance = hInstance;								  // WindMain( ) �Լ��� ù ��° �Ű����� �̸��� �ִ´�.
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);			  // �⺻ ������. IDI_APPLICATION. �Ʒ��� �ٸ� ICON��.
//																  /// IDI_ASTERISK, IDI_ERROR, IDI_QUESTION, IDI_WARNING
//																  /// IDI_SHIELD, IDI_HAND, IDI_EXCLAMATION, IDI_INFORMATION
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);				  // �⺻ Ŀ��. IDC_ARROW. �Ʒ��� �ٸ� CURSOR��.
//																  /// IDC_APPSTARTING, IDC_CROSS, IDC_HAND, IDC_HELP 
//																  /// IDC_IBEAM, IDC_UPARROW, IDC_WAIT
//																  /// IDC_SIZEALL, IDC_SIZENESW, IDC_SIZENS, IDC_SIZENWSE, IDC_SIZEWE
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ������ ����. WHITE_BRUSH�� ��� ����.
//																  /// BLACK_BRUSH, GRAY_BRUSH, DKGRAY_BRUSH, LTGRAY_BRUSH
//																  /// (HBRUSH)CreateSolidBrush(RGB(255, 0, 0)). RGB(0~255)�� ǥ������.
//	WndClass.lpszMenuName = NULL;								  // �޴� �̸�.
//	WndClass.lpszClassName = _T("Window Class Name");			  // ������ Ŭ������ �̸�. 
//																  // _T�� �ٿ���� ��Ƽ����Ʈ, �����ڵ� ��� ���� ó�� ����.
//	RegisterClass(&WndClass);									  // ���� Ŭ������ Ŀ�ο� ������ִ� �Լ�. (&Class�� �̸�).
//																  // �� �Ʒ����ʹ� ������ ����.
//	hwnd = CreateWindow(										  // ������ ������ �ڵ鿡 CreateWindow( )�� �� ��ȯ.
//		_T("Window Class Name"),								  // ������ Ŭ���� �̸�.
//		_T("Window Title Name"),								  // ������ Ÿ��Ʋ �̸�. Ÿ��Ʋ �ٿ� ��Ÿ���� ���ڿ�.
//		WS_OVERLAPPEDWINDOW,									  // ������ ��Ÿ��. WS_OVERLAPPEDWINDOW.
//																  // WS_OVERLAPPEDWINDOW = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME
//																  // Ÿ��Ʋ �� + �ּ�ȭ ��ư + �ִ�ȭ ��ư + �ݱ� ��ư + ������ ���콺 ��ư ����.
//																  /// WS_OVERLAPPED, WS_POPUP, WS_CHILD, WS_MINIMIZE, WS_MAXIMIZE, WS_VISIBLE
//																  /// WS_BORDER, WS_DLGFRAME, WS_VSCROLL, WS_HSCROLL
//																  /// WS_SYSMENU, WS_THICKFRAME, WS_MINIMIZEBOX, WS_MAXIMIZEBOX
//		CW_USEDEFAULT,												// ������ ��ġ x ��ǥ. CW_USEDEFAULT = Ŀ�ο� ���� �⺻ ��.
//		CW_USEDEFAULT,												// ������ ��ġ y ��ǥ. CW_USEDEFAULT.
//		CW_USEDEFAULT,												// ������ ���� ũ��.   CW_USEDEFAULT.
//		CW_USEDEFAULT,												// ������ ���� ũ��.   CW_USEDEFAULT.
//		NULL,														// �θ� ������ �ڵ�.		// �ʺ��� �״��.
//		NULL,														// �޴� �ڵ�.				// �ʺ��� �״��.
//		hInstance,													// ���� ���α׷� �ν��Ͻ�.  // �ʺ��� �״��.
//		NULL														// ���� ������ ����.		// �ʺ��� �״��.
//	);
//	// �����츦 ȭ�鿡 �����ִ� �� �Լ�.
//	ShowWindow(hwnd, nCmdShow);										// hwnd = ��Ÿ�� ������ �ڵ� ��.
//																	// nCmdShow = ���������� �����찡 ȭ�鿡 ��µ� �� ���¸� ����.
//																	/// SW_HIDE, SW_MAXIMIZE, SW_MINIMIZE, SW_SHOW
//	UpdateWindow(hwnd);
//	// ������ ���α׷����� �޽����� ó���ϴ� ����.
//	// Ű����, ���콺 � ���� �̺�Ʈ �߻�.
//	// �̺�Ʈ �߻��� ���������� ��ȯ�ؼ� �޽��� ť�� ���ʷ� �ִ´�.
//	// WinMain( ) �Լ��� �� �׿��ִ� �޽��� ť���� �� �տ� ��� ���� �޽����� ������ �ؼ��� �޽��� ó�� �Լ��� ������.
//	// �� �Ʒ����ʹ� �޽��� ó��.
//	while (GetMessage(&msg, NULL, 0, 0))							// GetMessage( ) �Լ��� �޽��� ť���� �޽����� ������.
//																	// &msg = �޽����� ����� MSG ����ü�� ���� ������
//	{																// ���� �޽����� �� �Լ����� msg�� ����������,
//		TranslateMessage(&msg);										// TranslateMessage( ) �Լ��� msg�� ����� �޽����� �����ϰ� ����. 
//		DispatchMessage(&msg);                                      // DispatchMessage( ) �Լ��� �޽����� ó���ϴ� �Լ��� msg�� ����.
//	}
//	return (int)msg.wParam;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) // hwnd = ������ ������ �ڵ�.
//{					  														 // Winmain( )���� CreateWindow( ) �Լ��� ���� �̸�.
//																			 // iMsg = ��ũ�η� ����� �ٲ��� �޽���.
//																			 // wParam, lParam. �޽����� �ؼ��ϴ� ���.
//																			 // wParam = ����Ű ��(VK_BACK, VK_RETURN, ...)
//																			 // lParam = �ΰ� ����(��ĵ �ڵ�, Ű �ݺ� Ƚ��, ...).
//	switch (iMsg)															 // �޽����� ������ ���� �ٸ� ó���� �ʿ��ϹǷ� switch-case
//	{																		 // ���α׷����� ó���� ���ϴ� �޽����� case������ �����.
//	case WM_CREATE:															 // ������ ������ ó��.
//		break;
//	case WM_DESTROY:														 // ������ �ı��� ó��.
//		PostQuitMessage(0);													 // ���� �⺻ ������ WM_DESTROY�� �־�־���.
//		break;																 // while (GetMessage(&msg, NULL, 0, 0))���� ���Ḧ ����.
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);						 // �Ѱܹ��� �޽��� �� ������ ó�� ���� ���� 
//}																			 // �⺻ �޽��� ó�� �Լ����� ����϶�� �ϴ� �Լ�.
