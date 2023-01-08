#ifndef CELIPSE_H
#define CELIPSE_H

#include "CFigure.h"

class CElipse : public CFigure
{
private:
	Point One;
	Point Two;

public:
	CElipse();
	CElipse(Point p1, Point p2, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI *pOut) const;
	bool isInside(int x, int y);
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