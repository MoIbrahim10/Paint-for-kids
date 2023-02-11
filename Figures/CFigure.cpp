#include "CFigure.h"

CFigure::CFigure() {}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }


void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


Point CFigure::GetTopPoint(Point A, Point B) {
	if (A.y < B.y)
		return A;
	return B;
}

Point CFigure::GetTopPoint(Point A, Point B, Point C) {
	if (A.y < B.y && A.y < C.y)
		return A;
	if (B.y < C.y)
		return B;
	return C;
}

bool CFigure::IsFigureFilled()
{
	return FigGfxInfo.isFilled;
}


color CFigure::GetFigColor()
{
	return FigGfxInfo.FillClr;
}

color CFigure::String2Color(string x) const {
	if (x == "WHITE") return WHITE;
	if (x == "LIGHTYELLOW") return LIGHTYELLOW;
	if (x == "ORANGE") return ORANGE;
	if (x == "PINK") return PINK;
	if (x == "ROSE") return ROSE;
	if (x == "RED") return RED;
	if (x == "DARKRED") return DARKRED;
	if (x == "TAN") return TAN;
	if (x == "ROSYBROWN") return ROSYBROWN;
	if (x == "BROWN") return BROWN;
	if (x == "LAVENDER") return LAVENDER;
	if (x == "PURPLE") return PURPLE;
	if (x == "MEDIUMPURPLE") return MEDIUMPURPLE;
	if (x == "LIGHTGREEN") return LIGHTGREEN;
	if (x == "GREEN") return GREEN;
	if (x == "GREEN2") return GREEN2;
	if (x == "TEAL") return TEAL;
	if (x == "LIGHTTURQUOISE") return LIGHTTURQUOISE;
	if (x == "TURQUOISE") return TURQUOISE;
	if (x == "INDIGO") return INDIGO;
	if (x == "SKYBLUE") return SKYBLUE;
	if (x == "BLUE") return BLUE;
	if (x == "BLUEGRAY") return BLUEGRAY;
	if (x == "GRAY") return GRAY;
	if (x == "DARKGRAY") return DARKGRAY;
	if (x == "BLACK") return BLACK;
	if (x == "LIGHTGOLDENRODYELLOW") return LIGHTGOLDENRODYELLOW;
	return BLACK;
}
string CFigure::Color2String(color x) const {

	if (x == WHITE) return "WHITE";
	if (x == LIGHTYELLOW) return "LIGHTYELLOW";
	if (x == ORANGE) return "ORANGE";
	if (x == PINK) return "PINK";
	if (x == ROSE) return "ROSE";
	if (x == RED) return "RED";
	if (x == DARKRED) return "DARKRED";
	if (x == TAN) return "TAN";
	if (x == ROSYBROWN) return "ROSYBROWN";
	if (x == BROWN) return "BROWN";
	if (x == LAVENDER) return "LAVENDER";
	if (x == PURPLE) return "PURPLE";
	if (x == MEDIUMPURPLE) return "MEDIUMPURPLE";
	if (x == LIGHTGREEN) return "LIGHTGREEN";
	if (x == GREEN) return "GREEN";
	if (x == GREEN2) return "GREEN2";
	if (x == TEAL) return "TEAL";
	if (x == LIGHTTURQUOISE) return "LIGHTTURQUOISE";
	if (x == TURQUOISE) return "TURQUOISE";
	if (x == INDIGO) return "INDIGO";
	if (x == SKYBLUE) return "SKYBLUE";
	if (x == BLUE) return "BLUE";
	if (x == BLUEGRAY) return "BLUEGRAY";
	if (x == GRAY) return "GRAY";
	if (x == DARKGRAY) return "DARKGRAY";
	if (x == BLACK) return "BLACK";
	if (x == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	return "InValid";


}

int CFigure::getHiddenValue()
{
	return  !Showen;
}

void CFigure::show(bool s)
{
	Showen = s;
}