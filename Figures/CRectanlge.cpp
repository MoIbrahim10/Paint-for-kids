#include "CRectanlge.h"

CRectanlge::CRectanlge(){}
CRectanlge::CRectanlge(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	LowerRightCorner = P2;

}

void CRectanlge::DrawMe(GUI *pGUI) const
{
	// Call Output::DrawRect to draw a Square on the screen
	pGUI->DrawRectangle(TopLeftCorner, LowerRightCorner, FigGfxInfo, Selected);
}

bool CRectanlge::isInside(int x, int y)
{
	if (x >= TopLeftCorner.x && x <= LowerRightCorner.x && y >= TopLeftCorner.y && y <= LowerRightCorner.y)
	{
		return true;
	}
	return false;
}


int CRectanlge::resize(float resizeFactor)
{
	Point Center;
	Center.x = (TopLeftCorner.x + LowerRightCorner.x) / 2;
	Center.y = (TopLeftCorner.y + LowerRightCorner.y) / 2;

	int horizontal = abs(TopLeftCorner.x - Center.x);
	int vertical = abs(TopLeftCorner.y - Center.y);

	if ((Center.y - (vertical * resizeFactor) > UI.height - UI.StatusBarHeight) || (Center.y - (vertical * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}
	if ((Center.y + (vertical * resizeFactor) > UI.height - UI.StatusBarHeight) || (Center.y + (vertical * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}

	TopLeftCorner.x = Center.x - (horizontal * resizeFactor);
	LowerRightCorner.x = Center.x + (horizontal * resizeFactor);

	TopLeftCorner.y = Center.y - (vertical * resizeFactor);
	LowerRightCorner.y = Center.y + (vertical * resizeFactor);
	return 1;
}

CFigure *CRectanlge::clone()
{
	return new CRectanlge(*this);
}

CFigure *CRectanlge::paste(int transX, int transY)
{
	TopLeftCorner.x += transX;
	TopLeftCorner.y += transY;
	LowerRightCorner.x += transX;
	LowerRightCorner.y += transY;
	return new CRectanlge(*this);
}

Point CRectanlge::highestPoint()
{
	return GetTopPoint(TopLeftCorner, LowerRightCorner);
}

void CRectanlge::Save(ofstream& OutFile)
{
	OutFile << "RECTANGLE  " << this->TopLeftCorner.x << "  " << this->TopLeftCorner.y << "  " << this->LowerRightCorner.x << "  " << this->LowerRightCorner.y << "  ";
	OutFile << Color2String(FigGfxInfo.DrawClr) << "  ";
	if (FigGfxInfo.isFilled)
		OutFile << Color2String(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "No_Fill" << endl;
}

void CRectanlge::Load(ifstream& Infile)
{
	string DrawClr;
	string FillClr;

	Infile >> this->TopLeftCorner.x >> this->TopLeftCorner.y >> this->LowerRightCorner.x >> this->LowerRightCorner.y;

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

void CRectanlge::printInfo(GUI *pGUI, int x)
{
	pGUI->ClearStatusBar();
	stringstream msg;
	int wWidth = abs(TopLeftCorner.x - LowerRightCorner.x);
	int hHeight = abs(TopLeftCorner.y - LowerRightCorner.y);
	msg << "ID:" << x + 1 << " Rectangle , P1 (" << TopLeftCorner.x << " , " << (TopLeftCorner.y) << ") , P2 (" << LowerRightCorner.x << " , " << (LowerRightCorner.y) << ") , Width:" << wWidth << " , Height:" << hHeight << " , Area:" << wWidth * hHeight;
	pGUI->PrintMessage(msg.str());
}

string CRectanlge::GetFigName() {
	return "Rectanlge";
}