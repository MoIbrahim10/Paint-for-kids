#include "ActionAddSquare.h"
#include "..\Figures\CSquare.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "SaveAction.h"

ActionAddSquare::ActionAddSquare(ApplicationManager * pApp):Action(pApp)
{}

//Execute the action
void ActionAddSquare::Execute() 
{
	Point P1,P2;
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	//Step 1 - Read Square data from the user
		//Read 1st point and store in point P1
	pGUI->PrintMessage("New Square: Click at first point");	
	pGUI->GetPointClicked(P1.x, P1.y);
	P1 = pGUI->ValidatePoint(P1);
		//Read 2nd point and store in point P2
	pGUI->PrintMessage("New Square: Click at second point");
	pGUI->GetPointClicked(P2.x, P2.y);
	P2 = pGUI->ValidatePoint(P2);
		//Clear status bar
	pGUI->ClearStatusBar();

	// Step 2 - Prepare data of drawn Square
		//User clicked 2 points,Top left point of the Square = the lowest (x,y) between the 2 points
	Point topLeft ;
	topLeft.x = P1.x<P2.x? P1.x: P2.x;
	topLeft.y = P1.y<P2.y? P1.y: P2.y;
		//The Side length of the Sqaure = The maximum between ( The absolute differnece of the 2 points on the x coordinates ) and ( The absolute differnece of the 2 points on the y coordinates )
	int SideLength = max(abs(P1.x-P2.x), abs(P1.y-P2.y));
	
	//Step 3 - Create a Square with the parameters read from the user
	CSquare *R=new CSquare(topLeft, SideLength, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
	SaveAction saveAction(pManager);
	saveAction.SaveActionStack();
}
