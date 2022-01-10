#include "framework.h"
#include "Matinyan.h"

using namespace Gdiplus;
using namespace std;
#pragma comment (lib, "Gdiplus.lib")

INT shapeWidth = 100;
INT shapeHeight = 50;
INT a = 200, b = shapeHeight * 2;
INT c = a + b;
INT d = a + b * 2;
INT e = a + b * 3;
INT f = a + b * 4;
INT g = a + b * 5;
INT h = a + b * 6;

HINSTANCE hInst; SZES;

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

VOID OnPaint(HDC hdc) {
    Graphics graphics(hdc);
}

VOID StartBlock(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
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
VOID PolyBlock(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF polyRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush solidBrush(Color(0, 0, 0));

    PointF pt1 = PointF(a + 0.0F, b + shapeHeight);  //  X = 0, Y = 100 UP
    PointF pt2 = PointF(a + 30.0F, b + 0.0F);   //  X = 30, Y = 0  RIGHT
    PointF pt3 = PointF(a + shapeWidth, b + 0.0F);  //  X = 200, Y = 0  DOWN
    PointF pt4 = PointF(a + shapeWidth - 30.0F, b + shapeHeight);//  X = 170 (200 - 30), Y = 100 LEFT
    PointF pts[4] = { pt1, pt2, pt3, pt4 };

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

    // Draw polygon
    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawPolygon(&BlackPen, pts, 4);
    graphics.DrawString(L"rect", -1, &font, polyRect, &stringFormat, &solidBrush);
}
VOID CaseBlock(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    RectF ellipseRect2(a - 15, b, shapeWidth + 30, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush solidBrush(Color(0, 0, 0));

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
    graphics.DrawLine(&BlackPen, (INT)a + shapeWidth / 2, d + shapeHeight, (INT)a + shapeWidth / 2, d + shapeHeight * 2);

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawString(L"esimwhat", -1, &font, ellipseRect, &stringFormat, &solidBrush);
    graphics.DrawRectangle(&BlackPen, ellipseRect);
    graphics.DrawRectangle(&BlackPen, ellipseRect2);
}
VOID MultiBlock(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF polyRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush solidBrush(Color(0, 0, 0));

    PointF pt1 = PointF(a + 0.0F, b + shapeHeight/2);  //  X = 0, Y = 100 UP
    PointF pt2 = PointF(a + 20.0F, b - 0.0F);   //  X = 30, Y = 0  RIGHT
    PointF pt3 = PointF(a + shapeWidth - 20.0F, b + 0.0F);  //  X = 200, Y = 0  DOWN
    PointF pt4 = PointF(a + shapeWidth, b + shapeHeight/2);//  X = 170 (200 - 30), Y = 100 LEFT
    PointF pt5 = PointF(a + shapeWidth - 20.0F, b + 50.0F);   //  X = 30, Y = 0  RIGHT
    PointF pt6 = PointF(a + 20.0F, b + 50.0F);  //  X = 200, Y = 0  DOWN
    PointF pts[6] = { pt1, pt2, pt3, pt4, pt5, pt6 };

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
    graphics.DrawLine(&BlackPen, (INT)a + shapeWidth / 2, e + shapeHeight, (INT)a + shapeWidth / 2, e + shapeHeight * 2);

    // Draw polygon
    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawPolygon(&BlackPen, pts, 6);
    graphics.DrawString(L"Loop", -1, &font, polyRect, &stringFormat, &solidBrush);
}
VOID RectBlock(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush solidBrush(Color(0, 0, 0));

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
    graphics.DrawLine(&BlackPen, (INT)a + shapeWidth / 2, f + shapeHeight, (INT)a + shapeWidth / 2, f + shapeHeight * 2);

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawString(L"Do something", -1, &font, ellipseRect, &stringFormat, &solidBrush);
    graphics.DrawRectangle(&BlackPen, ellipseRect);
}
VOID PolyBlock2(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF polyRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush solidBrush(Color(0, 0, 0));

    PointF pt1 = PointF(a + 0.0F, b + shapeHeight);  //  X = 0, Y = 100 UP
    PointF pt2 = PointF(a + 30.0F, b + 0.0F);   //  X = 30, Y = 0  RIGHT
    PointF pt3 = PointF(a + shapeWidth, b + 0.0F);  //  X = 200, Y = 0  DOWN
    PointF pt4 = PointF(a + shapeWidth - 30.0F, b + shapeHeight);//  X = 170 (200 - 30), Y = 100 LEFT
    PointF pts[4] = { pt1, pt2, pt3, pt4 };

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
    graphics.DrawLine(&BlackPen, (INT)a + shapeWidth / 2, g + shapeHeight, (INT)a + shapeWidth / 2, g + shapeHeight * 2);

    // Draw polygon
    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawPolygon(&BlackPen, pts, 4);
    graphics.DrawString(L"rect", -1, &font, polyRect, &stringFormat, &solidBrush);
}
VOID EndBlock(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush   solidBrush(Color(0, 0, 0));

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawString(L"end", -1, &font, ellipseRect, &stringFormat, &solidBrush);
    graphics.DrawEllipse(&BlackPen, ellipseRect);
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

            /*INT sc = 4;
            for (INT i = 0; i < sc; i++) {
                INT bc = a + b * i + 1;
                if (i == sc - 1) {
                    EndBlock(hdc, a, bc);
                }
                else {
                    PolyBlock(hdc, a, bc);
                }
            }*/

            /*INT _a(i) = a;
            for (INT i = 0; i < 10; i++) {
                if (i < _a) {
                    i = _a;
                    _a = _a + b;
                }
            }*/

            StartBlock(hdc, a, a);

            PolyBlock(hdc, a, c);

            CaseBlock(hdc, a, d);

            MultiBlock(hdc, a, e);

            RectBlock(hdc, a, f);

            PolyBlock2(hdc, a, g);

            EndBlock(hdc, a, h);

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