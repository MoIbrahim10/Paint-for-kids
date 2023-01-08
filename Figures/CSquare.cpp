#include "CSquare.h"

CSquare::CSquare() {}
CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length  = len;
}

void CSquare::DrawMe(GUI *pGUI) const
{
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
}

bool CSquare::isInside(int x, int y)
{
	if (x >= TopLeftCorner.x && x <= (TopLeftCorner.x + length) && y >= TopLeftCorner.y && y <= (TopLeftCorner.y + length))
	{
		return true;
	}
	return false;
}
int CSquare::resize(float resizeFactor)
{
	Point Center;
	int sideDisplacement = length / 2;
	Center.x = (TopLeftCorner.x + sideDisplacement);
	Center.y = (TopLeftCorner.y + sideDisplacement);

	if ((Center.y - (sideDisplacement * resizeFactor) > UI.height - UI.StatusBarHeight) || (Center.y - (sideDisplacement * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}
	if ((Center.y + (sideDisplacement * resizeFactor) > UI.height - UI.StatusBarHeight) || (Center.y + (sideDisplacement * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}

	TopLeftCorner.x = Center.x - sideDisplacement * resizeFactor;
	TopLeftCorner.y = Center.y - sideDisplacement * resizeFactor;
	
	length *= resizeFactor;
	return 1;
}

CFigure *CSquare::clone()
{
	return new CSquare(*this);
}

CFigure *CSquare::paste(int transX, int transY)
{

	TopLeftCorner.x += transX;
	TopLeftCorner.y += transY;

	return new CSquare(*this);
}

Point CSquare::highestPoint()
{
	return TopLeftCorner;
}


void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQUARE  " << this->TopLeftCorner.x << "  " << this->TopLeftCorner.y << "  " << this->length << "  " ;
	OutFile << Color2String(FigGfxInfo.DrawClr) << "  ";
	if (FigGfxInfo.isFilled)
		OutFile << Color2String(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "No_Fill" << endl;
}

void CSquare::Load(ifstream& Infile)
{
	string DrawClr;
	string FillClr;

	Infile >> this->TopLeftCorner.x >> this->TopLeftCorner.y >> this->length;

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

void CSquare::printInfo(GUI *pGUI, int x)
{
	pGUI->ClearStatusBar();
	stringstream msg;
	msg << "ID:" << x + 1 << " Square , P1 (" << TopLeftCorner.x << " , " << (TopLeftCorner.y) << ") , P2 (" << TopLeftCorner.x + length << " , " << TopLeftCorner.x + length << ") , Side Length:" << length << " , Area:" << pow(length, 2);
	pGUI->PrintMessage(msg.str());
}

string CSquare::GetFigName() {
	return "Square";
}