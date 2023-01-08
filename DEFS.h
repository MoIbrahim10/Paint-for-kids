#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_SQUARE,	//Draw a Square
	DRAW_CIRCLE,	//Draw an Ellipse
	DRAW_RECTANGLE,	//Draw a Rectangle
	DRAW_TRIANGLE,	//Draw a Triangle
	DRAW_ELIPSE,	//Draw a Triangle
	DRAW_HEX,		//Draw a Hexagon
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE_HALF,			//Resize a figure(s)
	RESIZE_QUARTER,
	RESIZE_DOUBLE,
	RESIZE_QUADRUPLE,


	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	selectt,
	deletee,
	bringFront,
	bringBack,
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	UNDO,
	REDO,
	CUT,
	COPY,
	PASTE,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode
	
	SET_WHITE,
	SET_LIGHT_YELLOW,
	SET_YELLOW,
	SET_ORANGE,
	SET_PINK,
	SET_ROSE,
	SET_RED,
	SET_DARK_RED,
	SET_TAN,
	SET_LIGHT_BROWN,
	SET_BROWN,
	SET_LAVENDER,
	SET_PURPLE,
	SET_PURPLE2,
	SET_LIGHT_GREEN,
	SET_GREEN,
	SET_GREEN2,
	SET_TEAL,
	SET_LIGHT_TURQUOISE,
	SET_TURQUOISE,
	SET_INDIGO,
	SET_SKY_BLUE,
	SET_BLUE,
	SET_BLUE_GRAY,
	SET_GRAY,
	SET_DARK_GRAY,
	SET_BLACK,
	BACK,

	PLAYWITHTYPE,
	PLAYWITHCOLOR,
	PLAYWITHTYPECOLOR,
	SWITCHTODRAW,
	SWITCHTOPLAY

};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif