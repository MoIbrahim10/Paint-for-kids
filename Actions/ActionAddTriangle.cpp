#include "ActionAddTriangle.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "SaveAction.h"

ActionAddTriangle::ActionAddTriangle(ApplicationManager * pApp):Action(pApp)
{}

//Execute the action
void ActionAddTriangle::Execute()
{
	Point P1, P2, P3;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	//Step 1 - Read Triangle data from the user
		//Read 1st point and store in point P1
	pGUI->PrintMessage("New Triangle: Click at first point");	
	pGUI->GetPointClicked(P1.x, P1.y);
	P1 = pGUI->ValidatePoint(P1);
		//Read 2nd point and store in point P2
	pGUI->PrintMessage("New Triangle: Click at second point");
	pGUI->GetPointClicked(P2.x, P2.y);
	P2 = pGUI->ValidatePoint(P2);
		//Read 3nd point and store in point P3
	pGUI->PrintMessage("New Triangle: Click at third point");
	pGUI->GetPointClicked(P3.x, P3.y);
	P3 = pGUI->ValidatePoint(P3);
		//Clear status bar
	pGUI->ClearStatusBar();

	//Step 3 - Create a Triangle with the parameters read from the user
	CTriangle *R=new CTriangle(P1,P2,P3,SqrGfxInfo);

	//Step 4 - Add the Triangle to the list of figures
	pManager->AddFigure(R);
	SaveAction saveAction(pManager);
	saveAction.SaveActionStack();
}

