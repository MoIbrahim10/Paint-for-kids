#include "CCircle.h"


CCircle::CCircle() {}
CCircle::CCircle(Point P1, int len, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	centerr = P1;
	radiuss  = len;

}

void CCircle::DrawMe(GUI *pGUI) const
{
	pGUI->DrawCircle(centerr, radiuss, FigGfxInfo, Selected);
}

bool CCircle::isInside(int x, int y)
{
	double dx = pow(x - centerr.x, 2);
	double dy = pow(y - centerr.y, 2);
	if (dx + dy < radiuss * radiuss)
		return true;
	return false;
}

int CCircle::resize(float resizeFactor)
{
	if ((centerr.y + (radiuss * resizeFactor) > UI.height - UI.StatusBarHeight) || (centerr.y - (radiuss * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}
	radiuss = radiuss * resizeFactor;
	return 1;
}

CFigure *CCircle::clone()
{
	return new CCircle(*this);
}

CFigure *CCircle::paste(int transX, int transY)
{
	centerr.x += transX;
	centerr.y += transY;
	return new CCircle(*this);
}

Point CCircle::highestPoint()
{
	Point TopP;
	TopP.x = centerr.x;
	TopP.y = centerr.y - radiuss;
	return TopP;
}

void CCircle::Save(ofstream& OutFile)      
{
	OutFile << "CIRCLE  " << this->centerr.x << "  " << this->centerr.y << "  " << radiuss << "  ";
	OutFile << Color2String(FigGfxInfo.DrawClr) << "  ";
	if (FigGfxInfo.isFilled != false)
		OutFile << Color2String(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "No_Fill" << endl;
}

void CCircle::Load(ifstream& Infile)     
{
	string DrawClr;
	string FillClr;
	Infile >> this->centerr.x >> this->centerr.y >>this->radiuss;

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

void CCircle::printInfo(GUI *pGUI, int x)
{
	pGUI->ClearStatusBar();

	stringstream msg;

	msg << "ID:" << x + 1 << " Circle , Center Point (" << centerr.x << "," << (centerr.y) << ") Radius:" << radiuss << " Unit , Area:" << (3.14 * pow(radiuss, 2));

	pGUI->PrintMessage(msg.str());
}

string CCircle::GetFigName() {
	return "CIRCLE";
}