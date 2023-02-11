#include "CElipse.h"

CElipse::CElipse() {}
CElipse::CElipse(Point p1, Point p2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	One = p1;
	Two = p2;
}

void CElipse::DrawMe(GUI *pGUI) const
{
	// Call Output::DrawRect to draw a Square on the screen
	pGUI->DrawElipse(One, Two, FigGfxInfo, Selected);
}

bool CElipse::isInside(int x, int y)
{
	Point center;
	center.x = 0.5 * (Two.x + One.x);
	center.y = 0.5 * (Two.y + One.y);
	float a = abs(Two.x - One.x) / 2;
	float b = abs(Two.y - One.y) / 2;
	float check = (pow(x - center.x, 2) / pow(a, 2)) + (pow(y - center.y, 2) / pow(b, 2));
	if (check <= 1)
		return true;
	return false;
}

int CElipse::resize(float resizeFactor)
{
	Point Center;
	Center.x = (One.x + Two.x) / 2;
	Center.y = (One.y + Two.y) / 2;

	int horizontal = abs(One.x - Center.x);
	int vertical = abs(One.y - Center.y);

	if ((Center.y - (vertical * resizeFactor) > UI.height - UI.StatusBarHeight) || (Center.y - (vertical * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}
	if ((Center.y + (vertical * resizeFactor) > UI.height - UI.StatusBarHeight) || (Center.y + (vertical * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}

	One.x = Center.x + horizontal * resizeFactor;
	Two.x = Center.x - horizontal * resizeFactor;

	One.y = Center.y + vertical * resizeFactor;
	Two.y = Center.y - vertical * resizeFactor;
	return 1;
}

CFigure *CElipse::clone()
{
	return new CElipse(*this);
}

CFigure *CElipse::paste(int transX, int transY)
{
	One.x += transX;
	One.y += transY;
	Two.x += transX;
	Two.y += transY;
	return new CElipse(*this);
}

Point CElipse::highestPoint()
{

	return GetTopPoint(One, Two);
}

void CElipse::Save(ofstream& OutFile)
{
	OutFile << "ELLIPSE  " << this->One.x << "  " << this->One.y << "  " << this->Two.x << "  " << this->Two.y << "  ";
	OutFile << Color2String(FigGfxInfo.DrawClr) << "  ";
	if (FigGfxInfo.isFilled != false)
		OutFile << Color2String(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "No_Fill" << endl;
}

void CElipse::Load(ifstream& Infile)
{
	string DrawClr;
	string FillClr;
	
	Infile >> this->One.x >> this->One.y >> this->Two.x >> this->Two.y;

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

void CElipse::printInfo(GUI *pGUI, int x)
{
	pGUI->ClearStatusBar();
	Point center;
	center.x = 0.5 * (Two.x + One.x);
	center.y = 0.5 * (Two.y + One.y);
	float a = abs(Two.x - One.x) / 2;
	float b = abs(Two.y - One.y) / 2;
	stringstream msg;
	msg << "ID:" << x + 1 << " Ellipse , Center (" << center.x << " , " << center.x << ") ,  Semi-major axis:" << max(a, b) << " , Semi-minor axis:" << min(a, b) << " , Area:" << 3.14 * a * b;
	pGUI->PrintMessage(msg.str());
}

string CElipse::GetFigName() {
	return "Ellipse";
}