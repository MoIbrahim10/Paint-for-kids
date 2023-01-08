#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLOR
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SQUR,			//Square item in menu
	ITM_CIRCLE,			//Circle item in menu
	ITM_RECTANGLE,		//Rectangle item in menu
	ITM_TRIANGLE,		//Triangle item in menu
	ITM_ELIPSE,			//Ellipse item in menu
	ITM_HEXAGON,//Hexagon item in menu
	ITM_CHANGECOLOR,
	ITM_CHANGEFILL,
	ITM_CHANGEBG,
	ITM_SELECT,
	ITM_DELETE,
	ITM_BRINGTOFRONT,
	ITM_BRINGTOBACK,
	ITM_QUARTER,
	ITM_HALF,
	ITM_DOUBLE,
	ITM_QUADRUPLE,
	//TODO: Add more items names here
	ITM_UNDO,
	ITM_REDO,
	ITM_CUT,
	ITM_COPY,
	ITM_PASTE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_PLAY,
	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	//TODO: Add more items names here
	FIGURE_TYPE,
	FIGURE_FILLCOLOR,
	FIGURETYPE_AND_FILLCOLOR,
	ITM_DRAW,
	ITM_EXIT2,
	PLAY_ITM_COUNT    //no. of menu items ==> This should be the last line in this enum

};



enum ColorMenuItem // The items of colors
{
	ITM_WHITE,
	ITM_LIGHT_YELLOW,
	ITM_ORANGE,
	ITM_PINK,
	ITM_ROSE,
	ITM_RED,
	ITM_DARK_RED,
	ITM_TAN,
	ITM_LIGHT_BROWN,
	ITM_BROWN,
	ITM_LAVENDER,
	ITM_PURPLE,
	ITM_PURPLE2,
	ITM_LIGHT_GREEN,
	ITM_GREEN,
	ITM_GREEN2,
	ITM_TEAL,
	ITM_LIGHT_TURQUOISE,
	ITM_TURQUOISE,
	ITM_INDIGO,
	ITM_SKY_BLUE,
	ITM_BLUE,
	ITM_BLUE_GRAY,
	ITM_GRAY,
	ITM_DARK_GRAY,
	ITM_BLACK,
	//ITM_BACK,
	//ITM_BACK,blue-gray,dark-red,gray,lavender,light-brown,light-turquoise,light-yellow,Purple,rose,sky-blue,Turquoise,teal
	//light - green tan,green2,purple2,indigo
	COLOR_ITM_COUNT
};

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth,		//Width of each item in toolbar menu
		ColorWidth;
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	bool isFilled;
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif