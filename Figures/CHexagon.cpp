#include "CHexagon.h"

CHexagon::CHexagon() {}
CHexagon::CHexagon(Point point, int len, int height, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	TopLeft = point;
	SideLength  = len;
	Height  = height;

}

void CHexagon::DrawMe(GUI *pGUI) const
{
	pGUI->DrawHexagon(TopLeft, SideLength, Height, FigGfxInfo, Selected);
}

bool CHexagon::isInside(int x, int y)
{

	// if inside inner rectangle
	if (x >= TopLeft.x && x <= TopLeft.x + SideLength && y >= TopLeft.y && y <= TopLeft.y + Height)
		return true;

	float sideTrianglesArea = AreaTriangle(TopLeft.x, TopLeft.y, TopLeft.x, TopLeft.y + Height, TopLeft.x - 0.5 * SideLength, TopLeft.y + 0.5 * Height);

	// if inside left side triangle
	// left triangle >> (x,y), (x, y+h), (x-0.5l, y+0.5h)
	float Area1 = AreaTriangle(x, y, TopLeft.x, TopLeft.y + Height, TopLeft.x - 0.5 * SideLength, TopLeft.y + 0.5 * Height);
	float Area2 = AreaTriangle(TopLeft.x, TopLeft.y, x, y, TopLeft.x - 0.5 * SideLength, TopLeft.y + 0.5 * Height);
	float Area3 = AreaTriangle(TopLeft.x, TopLeft.y, TopLeft.x, TopLeft.y + Height, x, y);
	if (Area1 + Area2 + Area3 == sideTrianglesArea)
		return true;

	// if inside right side triangle
	// right triangle >> (x+l,y), (x+l, y+h), (x+1.5l, y+0.5h)
	Area1 = AreaTriangle(x, y, TopLeft.x + SideLength, TopLeft.y + Height, TopLeft.x + 1.5 * SideLength, TopLeft.y + 0.5 * Height);
	Area2 = AreaTriangle(TopLeft.x + SideLength, TopLeft.y, x, y, TopLeft.x + 1.5 * SideLength, TopLeft.y + 0.5 * Height);
	Area3 = AreaTriangle(TopLeft.x + SideLength, TopLeft.y, TopLeft.x + SideLength, TopLeft.y + Height, x, y);
	if (Area1 + Area2 + Area3 == sideTrianglesArea)
		return true;

	return false;
}

float CHexagon::AreaTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5);
}

int CHexagon::resize(float resizeFactor)
{
	Point center;
	int horiaontalDiff = SideLength / 2;
	int verticalDiff = Height / 2;
	center.x = TopLeft.x + horiaontalDiff;
	center.y = TopLeft.y + verticalDiff;

	if ((center.y - (verticalDiff * resizeFactor) > UI.height - UI.StatusBarHeight) || (center.y - (verticalDiff * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}
	if ((center.y + (verticalDiff * resizeFactor) > UI.height - UI.StatusBarHeight) || (center.y + (verticalDiff * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}

	TopLeft.x = center.x - horiaontalDiff * resizeFactor;
	TopLeft.y = center.y - verticalDiff * resizeFactor;
	Height *= resizeFactor;
	SideLength *= resizeFactor;
	return 1;
}

CFigure *CHexagon::clone()
{
	return new CHexagon(*this);
}

CFigure *CHexagon::paste(int transX, int transY)
{

	TopLeft.x += transX;
	TopLeft.y += transY;

	return new CHexagon(*this);
}

Point CHexagon::highestPoint()
{
	return TopLeft;
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEXAGON  " << this->TopLeft.x << "  " << this->TopLeft.y << "  " << this->SideLength << "  " << this->Height << "  ";
	OutFile << Color2String(FigGfxInfo.DrawClr) << "  ";
	if (FigGfxInfo.isFilled != false)
		OutFile << Color2String(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "No_Fill" << endl;
}

void CHexagon::Load(ifstream& Infile)
{
	string DrawClr;
	string FillClr;

	Infile >> this->TopLeft.x >> this->TopLeft.y >> this->SideLength >> this->Height;

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

void CHexagon::printInfo(GUI *pGUI, int x)
{
	pGUI->ClearStatusBar();

	stringstream msg;
	msg << "ID:" << x + 1 << " Hexagon , TopLeft Corner (" << TopLeft.x << " , " << (TopLeft.y) << ") , Side Length:" << SideLength << " , Height:" << Height << " , Area:" << ((3 * sqrt(3)) / 2) * pow(SideLength, 2);
	pGUI->PrintMessage(msg.str());
}

string CHexagon::GetFigName() {
	return "Hexagon";
}