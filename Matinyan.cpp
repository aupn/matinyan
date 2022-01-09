#include "framework.h"
#include "Matinyan.h"
#include <string>

using namespace Gdiplus;
using namespace std;
#pragma comment (lib, "Gdiplus.lib")

#define MAX_LOADSTRING 100

INT shapeWidth = 200;
INT shapeHeight = 100;
INT a = 0, b = shapeHeight * 2;
INT c = a + b;

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

    AdjustableArrowCap cap1(1, 1, false);
    AdjustableArrowCap cap2(2, 1, false);

    cap1.SetBaseCap(LineCapRound);
    cap1.SetBaseInset(5);
    cap1.SetStrokeJoin(LineJoinBevel);
    cap2.SetWidthScale(5);
    cap2.SetBaseCap(LineCapSquare);
    cap2.SetHeight(2);

    BlackPen.SetCustomStartCap(&cap1);
    BlackPen.SetCustomEndCap(&cap2);

    graphics.DrawLine(&BlackPen, (INT)a + shapeWidth / 2, (INT)a + shapeHeight, (INT)a + shapeWidth / 2, (INT)a + shapeHeight * 2);

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawString(L"start", -1, &font, ellipseRect, &stringFormat, &solidBrush);
    graphics.DrawEllipse(&BlackPen, ellipseRect);
}
VOID RectBlock(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush   solidBrush(Color(0, 0, 0));

    AdjustableArrowCap cap1(1, 1, false);
    AdjustableArrowCap cap2(2, 1, false);

    cap1.SetBaseCap(LineCapRound);
    cap1.SetBaseInset(5);
    cap1.SetStrokeJoin(LineJoinBevel);
    cap2.SetWidthScale(5);
    cap2.SetBaseCap(LineCapSquare);
    cap2.SetHeight(2);

    BlackPen.SetCustomStartCap(&cap1);
    BlackPen.SetCustomEndCap(&cap2);

    //graphics.DrawLine(&BlackPen, (INT)a + shapeWidth / 2, (INT)a + (INT)b, (INT)a + shapeWidth / 2, (INT)a + shapeHeight * 2);
    graphics.DrawLine(&BlackPen, (INT)a + shapeWidth / 2, c + shapeHeight, (INT)a + shapeWidth / 2, c + shapeHeight * 2);

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawString(L"Do something", -1, &font, ellipseRect, &stringFormat, &solidBrush);
    graphics.DrawRectangle(&BlackPen, ellipseRect);
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

/* VOID Arrow1(HDC hdc, FLOAT a) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    AdjustableArrowCap cap1(1, 1, false);
    AdjustableArrowCap cap2(2, 1, false);

    cap1.SetBaseCap(LineCapRound);
    cap1.SetBaseInset(5);
    cap1.SetStrokeJoin(LineJoinBevel);
    cap2.SetWidthScale(5);
    cap2.SetBaseCap(LineCapSquare);
    cap2.SetHeight(2);

    BlackPen.SetCustomStartCap(&cap1);
    BlackPen.SetCustomEndCap(&cap2);

    graphics.DrawLine(&BlackPen, (INT)a + shapeWidth / 2, (INT)a + shapeHeight, (INT)a + shapeWidth / 2, (INT)a + shapeHeight * 2);
} */

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
    return (int)msg.wParam;
}

REGISTRATOR {
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MATINYAN));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MATINYAN);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

INSTANCE {
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
       return FALSE;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

WINPROCESSING{
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

            

            StartBlock(hdc, a, a);
            RectBlock(hdc, a, c);
            //Arrow1(hdc, a);
            
            //ChartShapes shape;
            //shape.Arrow(hdc, a + shapeWidth / 2);

            EndBlock(hdc, a, a + b + b);

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

ABOUTFX{
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