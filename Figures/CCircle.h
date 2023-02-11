#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point centerr;
	int radiuss;
	

public:
	CCircle();
	CCircle(Point, int, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI *pOut) const;
	virtual bool isInside(int x, int y);
	int resize(float);

	virtual CFigure *clone();
	CFigure *paste(int transX, int transY);
	Point highestPoint();

	void Save(ofstream& OutFile);
	void Load(ifstream& InFile);
	void printInfo(GUI *, int);
	string GetFigName();
};

#endif