#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CFigure.h"

class CRectanlge : public CFigure
{
private:
	Point TopLeftCorner;
	Point LowerRightCorner;


public:
	CRectanlge();
	CRectanlge(Point, Point, GfxInfo FigureGfxInfo);
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