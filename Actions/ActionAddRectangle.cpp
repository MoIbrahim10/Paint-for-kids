#include "ActionAddRectangle.h"
#include "..\Figures\CRectanlge.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "SaveAction.h"

ActionAddRectangle::ActionAddRectangle(ApplicationManager * pApp):Action(pApp)
{}

//Execute the action
void ActionAddRectangle::Execute()
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

	//Step 1 - Read Rectangle data from the user
		//Read 1st point and store in point P1
	pGUI->PrintMessage("New Rectangle: Click at first point");	
	pGUI->GetPointClicked(P1.x, P1.y);
	P1 = pGUI->ValidatePoint(P1);
		//Read 2nd point and store in point P2
	pGUI->PrintMessage("New Rectangle: Click at second point");
	pGUI->GetPointClicked(P2.x, P2.y);
	P2 = pGUI->ValidatePoint(P2);
		//Clear status bar
	pGUI->ClearStatusBar();

	Point TopLeft;
	Point BotRight;
	TopLeft.x = P1.x < P2.x ? P1.x : P2.x;
	TopLeft.y = P1.y < P2.y ? P1.y : P2.y;
	BotRight.x = P1.x > P2.x ? P1.x : P2.x;
	BotRight.y = P1.y > P2.y ? P1.y : P2.y;
	//Step 2 - Create a Rectangle with the parameters read from the user
	CRectanlge *R=new CRectanlge(TopLeft, BotRight, SqrGfxInfo);

	//Step 3 - Add the Rectangle to the list of figures
	pManager->AddFigure(R);
	SaveAction saveAction(pManager);
	saveAction.SaveActionStack();
}

