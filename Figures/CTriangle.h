#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point One;
	Point Two;
	Point Three;


public:
public:
	CTriangle ();
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI *pOut) const;
	float area(int, int, int, int, int, int);
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