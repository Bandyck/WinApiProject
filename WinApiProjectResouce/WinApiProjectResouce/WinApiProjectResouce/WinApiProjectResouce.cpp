#include "stdafx.h"
#include <stdio.h>
#include "WinApiProjectResouce.h"
#include <math.h>
#include <commdlg.h>
#pragma comment(lib, "msimg32.lib")

#define MAX_LOADSTRING 100

HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// >> :

HBITMAP hBackImage;
BITMAP bitBack;

HBITMAP hTransparentImage;
BITMAP bitTransparent;

HBITMAP hAniImage;
BITMAP bitAni;
const int Sprite_Size_X = 57;
const int Sprite_Size_Y = 52;
int Run_Frame_Max = 0;
int Run_Frame_Min = 0;
int cur_Frame = Run_Frame_Min;

// 텍스트 출력 부분
RECT rectView;
void DrawRectText(HDC hdc);

HBITMAP HDoubleBufferImage;
void DrawBitmapDoubleBuffering(HWND hwnd, HDC hdc);

// 그림 부분
void CreateBitmap();
void DrawBitmap(HWND hwnd, HDC hdc);
void DeleteBitmap();

// 애니메이션 부분
void UpdateFrame(HWND hwnd);
VOID CALLBACK AniProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);

// 키입력 부분
VOID CALLBACK KeyStateProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
TCHAR sKeyState[128];

// 대화상자 부분
BOOL CALLBACK Dlg6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

// 윈도우 분할 부분
#define IDC_CHILD_BTN 100
#define IDC_CHILD_BTN1 101
HWND childHwnd[2];
LRESULT CALLBACK ChildWnd1Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWnd2Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// >> :
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPIPROJECTRESOUCE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPIPROJECTRESOUCE));
    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int) msg.wParam;
}
//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPIPROJECTRESOUCE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPIPROJECTRESOUCE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWnd1Proc;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child2");
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWnd2Proc;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child3");
	RegisterClassExW(&wcex);
	return RegisterClassExW(&wcex);
}
//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
void OutFromFile(TCHAR filename[], HWND hwnd)
{
	FILE *fPtr;
	HDC hdc;
	int line;
	TCHAR buffer[500];
	line = 0;
	hdc = GetDC(hwnd);
#ifdef _UNICODE
	_tfopen_s(&fPtr, filename, _T("r, ccs = UNICODE"));
#else
	_tfopen_s(&fPtr, filename, _T("r"));
#endif // _UNICODE
	while (_fgetts(buffer, 100, fPtr) != NULL)
	{
		if (buffer[_tcslen(buffer) - 1] == _T('\n'))
			buffer[_tcslen(buffer) - 1] = NULL;
		TextOut(hdc, 0, line * 20, buffer, _tcslen(buffer));
		line++;
	}
	fclose(fPtr);
	ReleaseDC(hwnd, hdc);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int i;

    switch (message)
    {
	case WM_CREATE:
		CreateBitmap();
		// SetTimer(hWnd, 123, 100, NULL);
		SetTimer(hWnd, 123, 100, AniProc);
		SetTimer(hWnd, 111, 100, KeyStateProc);
		GetClientRect(hWnd, &rectView);
		// 윈도우 분할 부분
		childHwnd[0] = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			_T("Child1"),
			NULL,
			WS_CHILD | WS_VISIBLE,
			0,
			0,
			rectView.right / 2 - 1,
			rectView.bottom / 2 - 1,
			hWnd,
			NULL,
			hInst,
			NULL
		);
		childHwnd[1] = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			_T("Child2"),
			NULL,
			WS_CHILD | WS_VISIBLE,
			0,
			rectView.bottom / 2 + 1,
			rectView.right / 2 - 1,
			rectView.bottom / 2 - 1,
			hWnd,
			NULL,
			hInst,
			NULL
		);
		childHwnd[2] = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			_T("Child3"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_CAPTION | WS_SYSMENU,
			rectView.right / 2 + 1,
			0,
			rectView.right / 2 - 1,
			rectView.bottom,
			hWnd,
			NULL,
			hInst,
			NULL
		);
		break;
	case WM_RBUTTONDOWN:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dlg6_1Proc);
		break;
	//case WM_TIMER:
	//	UpdateFrame(hWnd);
	//	InvalidateRgn(hWnd, NULL, false);
	//	break;
	case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);
			// DrawBitmap(hWnd, hdc);
			DrawBitmapDoubleBuffering(hWnd, hdc);
			DrawRectText(hdc);
			EndPaint(hWnd, &ps);
		}
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_DESTROY:
		DeleteBitmap();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
// 윈도우 분할 부분
LRESULT CALLBACK ChildWnd1Proc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hButton;
	switch (iMsg)
	{
	case WM_CREATE:
		hButton = CreateWindow(
			_T("button"),
			_T("확인"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200,
			0,
			100,
			25,
			hWnd,
			(HMENU)IDC_CHILD_BTN,
			hInst,
			NULL);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_CHILD_BTN:
			HDC hdc = GetDC(hWnd);
			TextOut(hdc, 0, 100, _T("Child2"), 6);
			ReleaseDC(hWnd, hdc);
			return 0;
		}
	case WM_PAINT:
		return 0;
	case WM_DESTROY:
		return 0;
	default:
		break;
	}
	return DefMDIChildProc(hWnd, iMsg, wParam, lParam);
}
LRESULT CALLBACK ChildWnd2Proc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hButton1;
	switch (iMsg)
	{
	case WM_CREATE:
		hButton1 = CreateWindow(
			_T("button"),
			_T("확인"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200,
			0,
			100,
			25,
			hWnd,
			(HMENU)IDC_CHILD_BTN1,
			hInst,
			NULL);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_CHILD_BTN1:
			HDC hdc = GetDC(childHwnd[1]);
			TextOut(hdc, 0, 100, _T("RightWindow"), 11);
			ReleaseDC(childHwnd[1], hdc);
			return 0;
		}
		return 0;
	case WM_DESTROY:
		return 0;
	default:
		break;
	}
	return DefMDIChildProc(hWnd, iMsg, wParam, lParam);
}
// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
void CreateBitmap()
{
	{
		hBackImage = (HBITMAP)LoadImage(NULL, _TEXT("images/ncu.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		GetObject(hBackImage, sizeof(BITMAP), &bitBack);
	}
	{
		hTransparentImage = (HBITMAP)LoadImage(NULL, _TEXT("images/sigong.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		GetObject(hTransparentImage, sizeof(BITMAP), &bitTransparent);

	}
	{
		hAniImage = (HBITMAP)LoadImage(NULL, _TEXT("images/zero_run.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		GetObject(hAniImage, sizeof(BITMAP), &bitAni);
		Run_Frame_Max = bitAni.bmWidth / Sprite_Size_X - 1;
		Run_Frame_Min = 2;
		cur_Frame = Run_Frame_Min;
	}
}
void DrawBitmap(HWND hwnd, HDC hdc)
{
	HDC hMenDC;
	HBITMAP hOldBitmap;
	int bx, by;

	{
		hMenDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMenDC, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;

		BitBlt(hdc, 0, 0, bx, by, hMenDC, 0, 0, SRCCOPY);
		SelectObject(hMenDC, hOldBitmap);
		DeleteDC(hMenDC);
	}
	{
		hMenDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMenDC, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;
		
		BitBlt(hdc, 100, 100, bx, by, hMenDC, 0, 0, SRCCOPY);
		TransparentBlt(hdc, 200, 100, bx, by, hMenDC, 0, 0, bx, by, RGB(255, 0, 255));
		SelectObject(hMenDC, hOldBitmap);
		DeleteDC(hMenDC);
	}
	{
		hMenDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMenDC, hAniImage);
		bx = bitAni.bmWidth / 16;
		by = bitAni.bmHeight / 2;

		int xStart = cur_Frame * bx;
		int yStart = 0;
		TransparentBlt(hdc, 300, 100, bx, by, hMenDC, xStart, yStart, bx, by, RGB(255, 0, 255));
		SelectObject(hMenDC, hOldBitmap);
		DeleteDC(hMenDC);
	}
}
void DeleteBitmap()
{
	DeleteObject(hBackImage);
	DeleteObject(hTransparentImage);
	DeleteObject(hAniImage);
}
void UpdateFrame(HWND hwnd)
{
	cur_Frame++;
	if(cur_Frame > Run_Frame_Max)
		cur_Frame = Run_Frame_Min;
}
VOID CALLBACK AniProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	UpdateFrame(hwnd);
	InvalidateRgn(hwnd, NULL, false);
}
void DrawRectText(HDC hdc)
{
	static int yPos = 0;
	TCHAR strTest[] = _T("텍스트 출력");
	TextOut(hdc, 10, yPos, strTest, _tcslen(strTest));
	TextOut(hdc, 100, 10, sKeyState, _tcslen(sKeyState));
	yPos += 5;
	if (yPos > rectView.bottom) yPos = 0;
}
void DrawBitmapDoubleBuffering(HWND hwnd, HDC hdc)
{
	HDC hMenDC;
	HBITMAP hOldBitmap;
	int bx, by;

	HDC hMenDC2;
	HBITMAP hOldBitmap2;

	hMenDC = CreateCompatibleDC(hdc);
	if (HDoubleBufferImage == NULL)
		HDoubleBufferImage = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
	hOldBitmap = (HBITMAP)SelectObject(hMenDC, HDoubleBufferImage);

	{
		hMenDC2 = CreateCompatibleDC(hMenDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMenDC2, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;

		BitBlt(hMenDC, 0, 0, bx, by, hMenDC2, 0, 0, SRCCOPY);
		SelectObject(hMenDC2, hOldBitmap2);
		DeleteDC(hMenDC2);
	}
	{
		hMenDC2 = CreateCompatibleDC(hMenDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMenDC2, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;

		BitBlt(hMenDC, 100, 100, bx, by, hMenDC2, 0, 0, SRCCOPY);
		TransparentBlt(hMenDC, 200, 100, bx, by, hMenDC2, 0, 0, bx, by, RGB(255, 0, 255));
		SelectObject(hMenDC2, hOldBitmap2);
		DeleteDC(hMenDC2);
	}
	{
		hMenDC2 = CreateCompatibleDC(hMenDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMenDC2, hAniImage);
		bx = bitAni.bmWidth / 16;
		by = bitAni.bmHeight / 2;

		int xStart = cur_Frame * bx;
		int yStart = 0;
		TransparentBlt(hMenDC, 300, 100, bx, by, hMenDC2, xStart, yStart, bx, by, RGB(255, 0, 255));
		SelectObject(hMenDC2, hOldBitmap2);
		DeleteDC(hMenDC2);
	}
	BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, hMenDC, 0, 0, SRCCOPY);
	SelectObject(hMenDC, hOldBitmap);
}
VOID CALLBACK KeyStateProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	if (GetKeyState('A') & 0x8000)
	{
		wsprintf(sKeyState, _TEXT("%s"), _T("A-Key"));
	}
	else if (GetKeyState('S') & 0x8000)
	{
		wsprintf(sKeyState, _TEXT("%s"), _T("S-Key"));
	}
	else if (GetKeyState('D') & 0x8000)
	{
		wsprintf(sKeyState, _TEXT("%s"), _T("D-Key"));
	}
	else if (GetKeyState('W') & 0x8000)
	{
		wsprintf(sKeyState, _TEXT("%s"), _T("W-Key"));
	}
	else
	{
		wsprintf(sKeyState, _TEXT(""));
	}
}
BOOL CALLBACK Dlg6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	/* 대화 상자 부분 */
	TCHAR word[256];

	/* 체크 박스와 라디오 버튼 부분 */
	static int Check[3], Radio;
	TCHAR hobby[][30] = { _T("독서"),_T("음악감상"),_T("컴퓨터 게임") };
	TCHAR sex[][30] = { _T("여자"),_T("남자") };
	TCHAR output[200];

	/* 콤보 박스 컨트롤 부분 */
	static HWND hCombo;
	static int selection;
	TCHAR name[20];

	switch (iMsg)
	{
	case WM_INITDIALOG:
		{
			/* 대화 상자 부분 */
			HWND hButton;
			/* 체크 박스와 라디오 버튼 부분 */
			CheckRadioButton(hDlg, IDC_RADIO_FEMALE, IDC_RADIO_MALE, IDC_RADIO_FEMALE);
			/* 콤보 박스 컨트롤 부분 */
			hCombo = GetDlgItem(hDlg, IDC_COMBO_LIST);

			return 1;
		}
		return (INT_PTR)TRUE;											   
	case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			/* 대화 상자 부분 */
			case ID_BUTTON_COPY:
				GetDlgItemText(hDlg, IDC_EDIT_INPUT, word, 256);
				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, word);
				break;
			case ID_BUTTON_DELETE:
				SetDlgItemText(hDlg, IDC_EDIT_INPUT, _T(""));
				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, _T(""));
				break;
			/* 대화 상자 부분 */
			/* 체크 박스와 라디오 버튼 부분 */
			case IDC_CHECK_READING:
				Check[0] = 1 - Check[0];
				break;
			case IDC_CHECK_MUSIC:
				Check[1] = 1 - Check[1];
				break;
			case IDC_CHECK_GAME:
				Check[2] = 1 - Check[2];
				break;
			case IDC_RADIO_FEMALE:
				Radio = 0;
				break;
			case IDC_RADIO_MALE:
				Radio = 1;
				break;
			case IDC_BUTTON_OUTPUT_HOSE:
				_stprintf_s(output, 
					_T("선택한 취미는 %s %s %s입니다.\r\n")
					_T("선택한 성별은 %s입니다."),
					Check[0] ? hobby[0] : _T(""), Check[1] ? hobby[1] : _T(""), Check[2] ? hobby[2] : _T(""),
					sex[Radio]);
				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT_HOSE, output);
				break;
			/* 체크 박스와 라디오 버튼 부분 */
			/* 콤보 박스 컨트롤 부분 */
			case IDC_BUTTON_JOIN:
				GetDlgItemText(hDlg, IDC_EDIT_NAME, name, 20);
				if (_tcscmp(name, _T("")))
					SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)name);
				return 0;
			case IDC_BUTTON_WITHDRAW:
				SendMessage(hCombo, CB_DELETESTRING, selection, 0);
				return 0;
			case IDC_COMBO_LIST:
				if (HIWORD(wParam) == CBN_SELCHANGE)
					selection = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
				break;
			/* 콤보 박스 컨트롤 부분 */

			case ID_BUTTON_END:
				EndDialog(hDlg, 0);
				break;
			case IDCANCEL:
				EndDialog(hDlg, 0);
				break;
			}
		}
		break;
	}
	return false;
}
// 배경은 그대로.
// 텍스트는 맨 윗칸에서 흰색 뒤쪽 배경을 지우고 좌우로 왔다갔다 움직임.
// 애니매이션은 키를 받아야 움직이게, 오른쪽 누르면 오른쪽 애니매이션.
//									  왼쪽 누르면 왼쪽 애니메이션.
//									  위/아래 누르면 기존 애니메이션.