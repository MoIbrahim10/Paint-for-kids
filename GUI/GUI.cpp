#include "GUI.h"

//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 49;
	UI.ColorWidth = 49;


	UI.isFilled = false;

	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	 //DARKSLATEGRAY //SLATEGRAY //BURLYWOOD //GAINSBORO //OLDLACE
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = WHITE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
	
}

//======================================================================================//
//								Input Functions										    //
//======================================================================================//

void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case ITM_RECTANGLE: return DRAW_RECTANGLE;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_ELIPSE: return DRAW_ELIPSE;
			case ITM_HEXAGON: return DRAW_HEX;
			case ITM_CHANGECOLOR: return CHNG_DRAW_CLR;
			case ITM_CHANGEFILL: return CHNG_FILL_CLR;
			case ITM_CHANGEBG: return CHNG_BK_CLR;
			case ITM_SELECT: return selectt;
			case ITM_DELETE: return deletee;
			case ITM_BRINGTOFRONT: return bringFront;
			case ITM_BRINGTOBACK: return bringBack;
			case ITM_QUARTER: return RESIZE_QUARTER;
			case ITM_HALF: return RESIZE_HALF;
			case ITM_DOUBLE: return RESIZE_DOUBLE;
			case ITM_QUADRUPLE: return RESIZE_QUADRUPLE;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_CUT: return CUT;
			case ITM_COPY: return COPY;
			case ITM_PASTE: return PASTE;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_PLAY:return SWITCHTOPLAY;
			case ITM_EXIT: return EXIT;	
				
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_COLOR) {
	
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.ColorWidth);
			

			switch (ClickedItemOrder)
			{
			case ITM_WHITE: return 	SET_WHITE;
			case ITM_LIGHT_YELLOW: return SET_LIGHT_YELLOW;
			case ITM_ORANGE: return SET_ORANGE;
			case ITM_PINK: return SET_PINK;
			case ITM_ROSE: return SET_ROSE;
			case ITM_RED: return SET_RED;
			case ITM_DARK_RED: return SET_DARK_RED;
			case ITM_TAN: return SET_TAN;
			case ITM_LIGHT_BROWN: return SET_LIGHT_BROWN;
			case ITM_BROWN: return SET_BROWN;
			case ITM_LAVENDER: return SET_LAVENDER;
			case ITM_PURPLE: return SET_PURPLE;
			case ITM_PURPLE2: return SET_PURPLE2;
			case ITM_LIGHT_GREEN: return SET_LIGHT_GREEN;
			case ITM_GREEN: return SET_GREEN;
			case ITM_GREEN2: return SET_GREEN2;
			case ITM_TEAL: return SET_TEAL;
			case ITM_LIGHT_TURQUOISE: return SET_LIGHT_TURQUOISE;
			case ITM_TURQUOISE: return SET_TURQUOISE;
			case ITM_INDIGO: return SET_INDIGO;
			case ITM_SKY_BLUE: return SET_SKY_BLUE;
			case ITM_BLUE: return SET_BLUE;
			case ITM_BLUE_GRAY: return SET_BLUE_GRAY;
			case ITM_GRAY: return SET_GRAY;
			case ITM_DARK_GRAY: return SET_DARK_GRAY;
			case ITM_BLACK: return SET_BLACK;
			//case ITM_BACK: return BACK;
			
					
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
	
	}
	else  //GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case FIGURE_TYPE: return PLAYWITHTYPE;
			case FIGURE_FILLCOLOR: return PLAYWITHCOLOR;
			case FIGURETYPE_AND_FILLCOLOR: return PLAYWITHTYPECOLOR;
			case ITM_DRAW:return SWITCHTODRAW;
			case ITM_EXIT2: return EXIT;
			default: return EMPTY;  //A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

}
//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	// pW->SetPen(BLACK, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	CreateToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\Menu_Sqr.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[ITM_RECTANGLE] = "images\\MenuItems\\Menu_Rectangle.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_ELIPSE] = "images\\MenuItems\\Menu_Elipse.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_Polygone.jpg";
	MenuItemImages[ITM_CHANGECOLOR] = "images\\MenuItems\\paintbrush.jpg";
	MenuItemImages[ITM_CHANGEFILL] = "images\\MenuItems\\palette.jpg";
	MenuItemImages[ITM_CHANGEBG] = "images\\MenuItems\\painter-tool.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_QUARTER] = "images\\MenuItems\\Quarter.jpg";
	MenuItemImages[ITM_HALF] = "images\\MenuItems\\Half.jpg";
	MenuItemImages[ITM_DOUBLE] = "images\\MenuItems\\Two.jpg";
	MenuItemImages[ITM_QUADRUPLE] = "images\\MenuItems\\Four.jpg";
	MenuItemImages[ITM_BRINGTOFRONT] = "images\\MenuItems\\Menu_toFront.jpg";
	MenuItemImages[ITM_BRINGTOBACK] = "images\\MenuItems\\Menu_toBack.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list
	//Draw menu item one image at a time

	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	// pWind->SetPen(BLACK, 3);
	// pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateColorBar() const
{
	CreateToolBar(); // clear the prev tool bar
	UI.InterfaceMode = MODE_COLOR;

	

	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\Colors\\white.jpg";
	MenuItemImages[ITM_LIGHT_YELLOW] = "images\\MenuItems\\Colors\\light-yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Colors\\orange.jpg";
	MenuItemImages[ITM_PINK] ="images\\MenuItems\\Colors\\pink.jpg";
	MenuItemImages[ITM_ROSE] = "images\\MenuItems\\Colors\\rose.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Colors\\red.jpg";
	MenuItemImages[ITM_DARK_RED] = "images\\MenuItems\\Colors\\dark-red.jpg";
	MenuItemImages[ITM_TAN] = "images\\MenuItems\\Colors\\tan.jpg";
	MenuItemImages[ITM_LIGHT_BROWN] = "images\\MenuItems\\Colors\\light-brown.jpg";
	MenuItemImages[ITM_BROWN] = "images\\MenuItems\\Colors\\brown.jpg";
	MenuItemImages[ITM_LAVENDER] = "images\\MenuItems\\Colors\\lavender.jpg";
	MenuItemImages[ITM_PURPLE] = "images\\MenuItems\\Colors\\Purple.jpg";
	MenuItemImages[ITM_PURPLE2] = "images\\MenuItems\\Colors\\Purple2.jpg";
	MenuItemImages[ITM_LIGHT_GREEN] = "images\\MenuItems\\Colors\\light-green.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Colors\\green.jpg";
	MenuItemImages[ITM_GREEN2] = "images\\MenuItems\\Colors\\green2.jpg";
	MenuItemImages[ITM_TEAL] = "images\\MenuItems\\Colors\\teal.jpg";
	MenuItemImages[ITM_LIGHT_TURQUOISE] = "images\\MenuItems\\Colors\\light-turquoise.jpg";
	MenuItemImages[ITM_TURQUOISE] = "images\\MenuItems\\Colors\\Turquoise.jpg";
	MenuItemImages[ITM_INDIGO] = "images\\MenuItems\\Colors\\indigo.jpg";
	MenuItemImages[ITM_SKY_BLUE] = "images\\MenuItems\\Colors\\sky-blue.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Colors\\blue.jpg";
	MenuItemImages[ITM_BLUE_GRAY] = "images\\MenuItems\\Colors\\blue-gray.jpg";
	MenuItemImages[ITM_GRAY] = "images\\MenuItems\\Colors\\gray.jpg";
	MenuItemImages[ITM_DARK_GRAY] = "images\\MenuItems\\Colors\\dark-gray.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Colors\\black.jpg";
	//MenuItemImages[ITM_BACK] = "images\\MenuItems\\back.jpg";

	///TODO: write code to create Color mode menu
	for (int i = 0; i < COLOR_ITM_COUNT; i++){
		if (i== COLOR_ITM_COUNT-1)pWind->DrawImage(MenuItemImages[i], i * UI.ColorWidth, 0, 62, UI.ToolBarHeight);
		else pWind->DrawImage(MenuItemImages[i], i * UI.ColorWidth, 0, UI.ColorWidth, UI.ToolBarHeight);
	}
	//Draw a line under the toolbar
	// pWind->SetPen(BLACK, 1);
	// pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	//PlayMenuItem
	///TODO: write code to create Play mode menu
	string PlayItemImages[DRAW_ITM_COUNT];
	PlayItemImages[FIGURE_TYPE] = "images\\MenuItems\\Fig_Type.jpg";
	PlayItemImages[FIGURE_FILLCOLOR] = "images\\MenuItems\\Fig_Color.jpg";
	PlayItemImages[FIGURETYPE_AND_FILLCOLOR] = "images\\MenuItems\\Fill_Color.jpg";
	PlayItemImages[ITM_DRAW] = "images\\MenuItems\\Draw.jpg";
	PlayItemImages[ITM_EXIT2] = "images\\MenuItems\\Exit.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	// pWind->SetPen(BLACK, 2);
	// pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Popins");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::setCrntBgColor(color c) {
	UI.BkGrndColor = c;
}

void GUI::setCrntDrawColor(color c) {
	UI.DrawColor = c;
}


void GUI::setCrntFillColor(color c) {
	UI.FillColor = c;
	UI.isFilled = true;
	pWind->SetBrush(UI.FillColor);
}
color GUI::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
color GUI::getCrntBgColor() const	//get current filling color
{
	return UI.BkGrndColor;
}
color GUI::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//


Point GUI::ValidatePoint(Point P1) const  {
	if (P1.y < UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false;
		PrintMessage("Can't choose here!; please choose a point in the drawing area");
		while (!flag)
		{
			GetPointClicked(P1.x, P1.y);
			if (!(P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}
	return P1;
}
void GUI::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);

}

void GUI::DrawCircle(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, length, style);

}

void GUI::DrawRectangle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void GUI::DrawElipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::DrawHexagon(Point P1, int length, int height, GfxInfo HexGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, HexGfxInfo.BorderWdth);    //Set Drawing color & width

	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int XVert[] = { P1.x, P1.x + length, P1.x + 1.5 * length, P1.x + length, P1.x, P1.x - 0.5 * length };
	int YVert[] = { P1.y, P1.y, P1.y + 0.5 * height, P1.y + height, P1.y + height, P1.y + 0.5 * height };

	pWind->DrawPolygon(XVert, YVert, 6, style);


}
//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}
