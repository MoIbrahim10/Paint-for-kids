#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;
	int length;


public:
	CSquare();
	CSquare(Point, int, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI *pOut) const;
	virtual bool isInside(int x, int y);
	int resize(float);

	virtual CFigure *clone();
	CFigure *paste(int transX, int transY);
	Point highestPoint();

	void Save(ofstream& OutFile);
	void Load(ifstream& InFile);
	void printInfo(GUI *pGUI, int);
	string GetFigName();
};

#endif