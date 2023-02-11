#include "CTriangle.h"


CTriangle::CTriangle() {}
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	One  = P1;
	Two  = P2;
	Three  = P3;

}

void CTriangle::DrawMe(GUI *pGUI) const
{
	// Call Output::DrawRect to draw a Square on the screen
	pGUI->DrawTriangle(One, Two, Three, FigGfxInfo, Selected);
}

bool CTriangle::isInside(int x, int y)
{
	Point a = One;
	Point b = Two;
	Point c = Three;

	/* Calculate area of triangle ABC */
	float A = area(a.x, a.y, b.x, b.y, c.x, c.y); // a,b,c

	/* Calculate area of triangle PBC */
	float A1 = area(x, y, a.x, a.y, b.x, b.y); // x,a,b
	/* Calculate area of triangle PAC */
	float A2 = area(x, y, a.x, a.y, c.x, c.y); // x,a,c

	/* Calculate area of triangle PAB */
	float A3 = area(x, y, c.x, c.y, b.x, b.y); // x,b,c

	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == A1 + A2 + A3);
}

float CTriangle::area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

int CTriangle::resize(float resizeFactor)
{

	Point center;
	center.x = (One.x + Two.x + Three.x) / 3;
	center.y = (One.y + Two.y + Three.y) / 3;

	Point highest = highestPoint();
	Point lowest = One;
	if (lowest.y < Two.y) lowest = Two;
	if (lowest.y < Three.y) lowest = Three;
	if (center.y + ((lowest.y - center.y) * resizeFactor) > (UI.height - UI.StatusBarHeight) || (center.y - ((center.y - highest.y) * resizeFactor) < UI.ToolBarHeight)) { return -1; }

	One.x > center.x ? One.x = center.x + ((One.x - center.x) * resizeFactor) : One.x = center.x - ((center.x - One.x) * resizeFactor);
	One.y > center.y ? One.y = center.y + ((One.y - center.y) * resizeFactor) : One.y = center.y - ((center.y - One.y) * resizeFactor);

	Two.x > center.x ? Two.x = center.x + ((Two.x - center.x) * resizeFactor) : Two.x = center.x - ((center.x - Two.x) * resizeFactor);
	Two.y > center.y ? Two.y = center.y + ((Two.y - center.y) * resizeFactor) : Two.y = center.y - ((center.y - Two.y) * resizeFactor);

	Three.x > center.x ? Three.x = center.x + ((Three.x - center.x) * resizeFactor) : Three.x = center.x - ((center.x - Three.x) * resizeFactor);
	Three.y > center.y ? Three.y = center.y + ((Three.y - center.y) * resizeFactor) : Three.y = center.y - ((center.y - Three.y) * resizeFactor);
	return 1;
}

CFigure *CTriangle::clone()
{
	return new CTriangle(*this);
}

CFigure *CTriangle::paste(int transX, int transY)
{
	One.x += transX;
	Two.x += transX;
	Three.x += transX;
	One.y += transY;
	Two.y += transY;
	Three.y += transY;
	return new CTriangle(*this);
}

Point CTriangle::highestPoint()
{
	return GetTopPoint(One, Two, Three);
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "TRIANGLE  " << this->One.x << "  " << this->One.y << "  " << this->Two.x << "  " << this->Two.y << "  " << this->Three.x << "  " << this->Three.y << "  ";
	OutFile << Color2String(FigGfxInfo.DrawClr) << "  ";
	if (FigGfxInfo.isFilled)
		OutFile << Color2String(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "No_Fill" << endl;
}

void CTriangle::Load(ifstream& Infile)
{
	string DrawClr;
	string FillClr;

	Infile >> this->One.x >> this->One.y >> this->Two.x >> this->Two.y >> this->Three.x >> this->Three.y;

	Infile >> DrawClr;
	this->FigGfxInfo.DrawClr = String2Color(DrawClr);

	Infile >> FillClr;
	if (FillClr == "No_Fill")
		this->FigGfxInfo.isFilled = false;
	else
	{
		this->FigGfxInfo.FillClr = String2Color(FillClr);
		this->FigGfxInfo.isFilled = true;
	}
	FigGfxInfo.BorderWdth = UI.PenWidth;
	this->Selected = false;

}

void CTriangle::printInfo(GUI *pGUI, int x)
{
	pGUI->ClearStatusBar();
	stringstream msg;
	CFigure *temp = this;
	msg << "ID:" << x + 1 << " Triangle , P1 (" << One.x << " , " << One.y << ") , P2 (" << Two.x << " , " << Two.y << ") , P3 (" << Three.x << " , " << Three.y << ") , Area:" << area(One.x, One.y, Two.x, Two.y, Three.x, Three.y);
	pGUI->PrintMessage(msg.str());
}

string CTriangle::GetFigName() {
	return "Triangle";
}