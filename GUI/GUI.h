#ifndef GUI_H
#define GUI_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"


//This class is responsible for Grphical User Interface handling
//All user input and program outputs MUST be done through this class
//No other class is allowed to perform direct i/o
class GUI	
{
public:	
	window* pWind;	//Pointer to the Graphics Window
public:
	GUI();	
	~GUI();	
	window* CreateWind(int, int, int , int) const; //creates the application window

	/////////// Input Functoinality  /////////////////
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting() const ;	 //Returns a string entered by the user
	ActionType MapInputToActionType() const; //Read the user click and map to an action


	/////////// Output Functoinality  ////////////////
	void CreateToolBar() const;
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateColorBar() const;
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions	
	Point ValidatePoint(Point P1) const;
	void DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected=false) const;			//Draw a Square
	void DrawRectangle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const;				//Draw a Rectangle
	void DrawCircle(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const;				//Draw a Circle
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const;		//Draw a Triangle
	void DrawElipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const;					//Draw an Elipse
	void DrawHexagon(Point P1, int length, int height, GfxInfo HexGfxInfo, bool selected) const;		//Draw an Elipse
	
	///TODO: Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	void setCrntDrawColor(color );
	void setCrntFillColor(color ) ;	
	void setCrntBgColor(color ) ;
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	color getCrntBgColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


};


#endif