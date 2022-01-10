#pragma once

#ifndef _GRAPH_HEADER_
#define _GRAPH_HEADER_

#include "framework.h"
#include "Matinyan.h"
#include "graph.h"
#include <string>

using namespace Gdiplus;
using namespace std;
#pragma comment (lib, "Gdiplus.lib")

class ChartShapes {
private:
	void InitGraphics(HDC hdc);
	void MakeFont(HDC hdc, INT a, INT b);
	void MakeCap(Pen pen);
public:
	void Arrow(HDC hdc, INT a);
};

class Geeks
{
    // Access specifier
public:

    // Data Members
    string geekname;

    // Member Functions()
    void printname()
    {
        geekname = "asdf";
    }
};

#endif