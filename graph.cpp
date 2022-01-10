#include "framework.h"
#include "Matinyan.h"
#include "graph.h"
#include <string>

using namespace Gdiplus;
using namespace std;
#pragma comment (lib, "Gdiplus.lib")

/*class ChartShapes {
	INT shapeWidth = 250; INT shapeHeight = 100;
private:
	void InitGraphics(HDC hdc) {
		Graphics graphics(hdc);
		Pen BlackPen(Color(0, 0, 0));
	}
	void MakeFont(HDC hdc, INT a, INT b) {
		FontFamily fontFamily(L"Arial");
		Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
		PointF pointF(a, b);
		StringFormat stringFormat;
		SolidBrush solidBrush(Color(0, 0, 0));
	}
	void MakeCap(Pen pen) {
		AdjustableArrowCap cap1(1, 1, false);
		AdjustableArrowCap cap2(2, 1, false);

		cap1.SetBaseCap(LineCapRound);
		cap1.SetBaseInset(5);
		cap1.SetStrokeJoin(LineJoinBevel);
		cap2.SetWidthScale(5);
		cap2.SetBaseCap(LineCapSquare);
		cap2.SetHeight(2);

		pen.SetCustomStartCap(&cap1);
		pen.SetCustomEndCap(&cap2);
	}
public:
	void ChartShapes::Arrow(HDC hdc, INT a) {
		Graphics graphics(hdc);
		Pen BlackPen(Color(0, 0, 0));
		graphics.DrawLine(&BlackPen, (INT)a + shapeWidth / 2, (INT)a + shapeHeight, (INT)a + shapeWidth / 2, (INT)a + shapeHeight * 2);
	}
};*/