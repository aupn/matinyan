// Matinyan.cpp - ste che //

#include "framework.h"
#include "Matinyan.h"
#include <string>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

using namespace Gdiplus;
using namespace std;
#pragma comment (lib, "Gdiplus.lib")

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
VOID StartEndBlock(HDC, int);

VOID OnPaint0(HDC hdc) {
    Graphics graphics(hdc);

    // Create a Pen object.
    Pen blackPen(Color(255, 0, 0, 0), 3);

    // Create a RectF object.
    RectF rect(0.0f, 0.0f, 200.0f, 200.0f);

    // Draw rect.
    graphics.DrawRectangle(&blackPen, rect);
}
VOID OnPaint(HDC hdc) {
    Graphics graphics(hdc);
    
}
VOID StartEndBlock(HDC hdc, INT typo) {
   Graphics graphics(hdc);
   Pen bluePen(Color(255, 0, 0, 255));
   RectF ellipseRect(0.0f, 0.0f, 200.0f, 100.0f);
   SolidBrush brush(Color(255, 0, 0, 255));
   FontFamily fontFamily(L"Arial");
   Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
   PointF pointF(10.0f, 20.0f);

   if (typo == 0) {
       graphics.DrawString(L"start", -1, &font, pointF, &brush);
       graphics.DrawEllipse(&bluePen, ellipseRect);
   }
   else if (typo == 1) {
       graphics.DrawString(L"end", -1, &font, pointF, &brush);
       graphics.DrawEllipse(&bluePen, ellipseRect);
   }
}
VOID Test(HDC hdc) {
    Graphics graphics(hdc);
    WCHAR string[] = L"Start";

    FontFamily   fontFamily(L"Arial");
    Font         font(&fontFamily, 12, FontStyleBold, UnitPoint);
    RectF        ellipseRect(30.0f, 10.0f, 200.0f, 100.0f);
    StringFormat stringFormat;
    SolidBrush   solidBrush(Color(255, 0, 0, 255));

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);

    graphics.DrawString(string, -1, &font, ellipseRect, &stringFormat, &solidBrush);

    Pen pen(Color(255, 0, 0, 0));
    graphics.DrawEllipse(&pen, ellipseRect);
}

WINMAIN {
    HWND hWnd; MSG msg; WNDCLASS wndClass;
    GDISTART;

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MATINYAN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if(!InitInstance (hInstance, nCmdShow))
        return FALSE;

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MATINYAN));

    // Main message loop:
    while(GetMessage(&msg, nullptr, 0, 0)) {
        if(!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    GDIEND;
    return (int) msg.wParam;
}

REGISTRATOR {
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MATINYAN));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MATINYAN);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

INSTANCE {
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if(!hWnd)
       return FALSE;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

WINPROCESSING {
    switch (message) {
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case IDM_ABOUT:
                    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                    break;
                case IDM_EXIT:
                    DestroyWindow(hWnd);
                    break;
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            OnPaint(hdc); Test(hdc);
            //StartEndBlock(hdc, 0); //MatinyanNamak(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

ABOUTFX {
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
        case WM_INITDIALOG:
            return (INT_PTR)TRUE;
        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
                EndDialog(hDlg, LOWORD(wParam));
                return (INT_PTR)TRUE;
            }
            break;
    }
    return (INT_PTR)FALSE;
}
