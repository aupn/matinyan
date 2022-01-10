@@ -1,5 +1,3 @@
// Matinyan.cpp - ste che //

#include "framework.h"
#include "Matinyan.h"
#include <string>
@@ -33,106 +31,110 @@ class Sizes {
    int XYs(int x, int y) {  }
};

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

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
VOID Rectangle(HDC hdc, FLOAT a, FLOAT b)
{
    Graphics graphics(hdc);
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(0, 0, 0));

    // Create a Pen object.
    Pen blackPen(Color(255, 0, 0, 0), 3);

    // Create a RectF object.
    RectF rect(0.0f, 0.0f, 200.0f, 200.0f);
    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush   solidBrush(Color(0, 0, 0));

    // Draw rect.
    graphics.DrawRectangle(&blackPen, rect);
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
    Pen bluePen(Color(255, 0, 0, 255));
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(255, 0, 0, 255));
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush   solidBrush(Color(255, 0, 0, 255));
    SolidBrush   solidBrush(Color(0, 0, 0));

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawString(L"start", -1, &font, ellipseRect, &stringFormat, &solidBrush);
    graphics.DrawEllipse(&bluePen, ellipseRect);
    graphics.DrawEllipse(&BlackPen, ellipseRect);
}
VOID EndBlock(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);
    Pen bluePen(Color(255, 0, 0, 255));
    Pen BlackPen(Color(0, 0, 0));
    RectF ellipseRect(a, b, shapeWidth, shapeHeight);
    SolidBrush brush(Color(255, 0, 0, 255));
    SolidBrush brush(Color(0, 0, 0));

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
    PointF pointF(a, b);
    StringFormat stringFormat;
    SolidBrush   solidBrush(Color(255, 0, 0, 255));
    SolidBrush   solidBrush(Color(0, 0, 0));

    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    graphics.DrawString(L"end", -1, &font, ellipseRect, &stringFormat, &solidBrush);
    graphics.DrawEllipse(&bluePen, ellipseRect);
    graphics.DrawEllipse(&BlackPen, ellipseRect);
}

VOID Arrow1(HDC hdc, FLOAT a, FLOAT b, FLOAT c, FLOAT d) {
VOID Arrow1(HDC hdc, FLOAT a, FLOAT b) {
    Graphics graphics(hdc);

    AdjustableArrowCap cap1(1, 1, false);
    AdjustableArrowCap cap2(2, 1, false);

    Pen pen(Color(255, 0, 0, 255), 8);
    pen.SetStartCap(LineCapArrowAnchor);
    graphics.DrawLine(&pen, a, b, c, d);
    cap1.SetBaseCap(LineCapRound);
    cap1.SetBaseInset(5);
    cap1.SetStrokeJoin(LineJoinBevel);
    cap2.SetWidthScale(5);
    cap2.SetBaseCap(LineCapSquare);
    cap2.SetHeight(2);

    //graphics.DrawLine(&blackPen, a, a, a, b);
    //graphics.DrawLine(&blackPen, 0, 0, 200, 200);
    //graphics.DrawLines(&blackPen, 0, 0, 200, 200);
}
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
@@ -143,7 +145,6 @@ WINMAIN {
    GDIEND;
    return (int) msg.wParam;
}

REGISTRATOR {
    WNDCLASSEXW wcex;

@@ -162,7 +163,6 @@ REGISTRATOR {

    return RegisterClassExW(&wcex);
}

INSTANCE {
   hInst = hInstance;

@@ -198,13 +198,10 @@ WINPROCESSING {
            HDC hdc = BeginPaint(hWnd, &ps);
            OnPaint(hdc);

            INT a, b, c, d; 
            a = 30; b = 160; c = 80; d = 200;
            INT a = 30, b = 150;

            StartBlock(hdc, a, a);
            Arrow1(hdc, a, b, c, d);
            EndBlock(hdc, a, b);
            Arrow1(hdc, a, b, c, d);
            Arrow1(hdc, a + shapeWidth / 2, a + b);
            EndBlock(hdc, a, a + b);

            EndPaint(hWnd, &ps);
@@ -232,4 +229,4 @@ ABOUTFX {
            break;
    }
    return (INT_PTR)FALSE;
}
} 