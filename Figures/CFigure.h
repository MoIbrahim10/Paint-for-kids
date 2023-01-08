#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"
#include <sstream>
#include <fstream>
#include <math.h>

// Base class for all figures
class CFigure
{
protected:
	int ID;				// Each figure has an ID
	bool Selected;		// true if the figure is selected.
	GfxInfo FigGfxInfo; // Figure graphis info
	bool Showen;
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool);	 // select/unselect the figure
	bool IsSelected() const; // check whether fig is selected

	virtual void DrawMe(GUI *) const = 0; // Draw the figure

	Point GetTopPoint(Point A, Point B);
	Point GetTopPoint(Point A, Point B, Point C);

	void ChngDrawClr(color Dclr); // changes the figure's drawing color
	void ChngFillClr(color Fclr); // changes the figure's filling color
	virtual bool isInside(int, int) = 0;
	virtual int resize(float) = 0;
	
	bool IsFigureFilled();
	color GetFigColor();

	virtual CFigure *clone() = 0;
	virtual CFigure *paste(int, int) = 0;
	virtual Point highestPoint() = 0;


	virtual color String2Color(string s) const;  //convert from string to color type
	virtual string Color2String(color c) const; //Convert color to string 

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &InFile) = 0;	//Load the figure parameters to the file
	
	
	virtual void printInfo(GUI *pGUI, int) = 0;
	virtual string GetFigName() = 0;
	int getHiddenValue();
	void show(bool);
	// virtual void Rotate() = 0;	//Rotate the figure
	// virtual void Move() = 0;		//Move the figure

};

#endif