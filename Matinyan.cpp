#include "framework.h"
#include "Matinyan.h"
#include <string>

#define MAX_LOADSTRING 100

FLOAT shapeWidth = 200.0f;
FLOAT shapeHeight = 100.0f;

/*
    Right
    X + width
    Y + hight/2

    Left
    X
    Y + hight/2

    Up
    X + width/2
    Y

    Down
    X + width/2
    Y + height
*/

class Sizes {
    int x, y;
public:
    int XYs(int x, int y) {  }
};

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

using namespace Gdiplus;
using namespace std;
#pragma comment (lib, "Gdiplus.lib")

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

VOID Rectangle(HDC hdc, FLOAT a, FLOAT b)
{
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush   solidBrush(Color(0, 0, 0));

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawString(L"Do Something", -1, &font, ellipseRect, &stringFormat, &solidBrush);
    graphics.DrawEllipse(&BlackPen, ellipseRect);
}

VOID OnPaint(HDC hdc) {
    Graphics graphics(hdc);
}
VOID StartBlock(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush   solidBrush(Color(0, 0, 0));

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawString(L"start", -1, &font, ellipseRect, &stringFormat, &solidBrush);
    graphics.DrawEllipse(&BlackPen, ellipseRect);
}
VOID EndBlock(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush   solidBrush(Color(0, 0, 0));

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawString(L"end", -1, &font, ellipseRect, &stringFormat, &solidBrush);
    graphics.DrawEllipse(&BlackPen, ellipseRect);
}
VOID Arrow1(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    
    AdjustableArrowCap cap1(1, 1, false);
    AdjustableArrowCap cap2(2, 1, false);

    cap1.SetBaseCap(LineCapRound);
    cap1.SetBaseInset(5);
    cap1.SetStrokeJoin(LineJoinBevel);
    cap2.SetWidthScale(5);
    cap2.SetBaseCap(LineCapSquare);
    cap2.SetHeight(2);

    Pen blackPen(Color(0, 0, 0));
    blackPen.SetCustomStartCap(&cap1);
    blackPen.SetCustomEndCap(&cap2);

    graphics.DrawLine(&blackPen, a, a, a, b);
}
WINMAIN {
    HWND hWnd; MSG msg; WNDCLASS wndClass;
    GDISTART;

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MATINYAN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if(!InitInstance (hInstance, nCmdShow))
        return FALSE;

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MATINYAN));

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
            OnPaint(hdc);
            
            INT a = 30, b = 150;

            StartBlock(hdc, a, a);
            Arrow1(hdc, a + shapeWidth / 2, a + b);
            EndBlock(hdc, a, a + b);

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