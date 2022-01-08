#pragma once

#include "resource.h"
#include <ObjIdl.h>
#include <gdiplus.h>

#define WINMAIN int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
#define REGISTRATOR ATOM MyRegisterClass(HINSTANCE hInstance)
#define INSTANCE BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
#define ABOUTFX INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
#define GDISTART GdiplusStartupInput gdiplusStartupInput; ULONG_PTR gdiplusToken; GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
#define GDIEND GdiplusShutdown(gdiplusToken);
#define WINPROCESSING LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)