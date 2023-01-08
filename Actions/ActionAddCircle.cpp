#include "ActionAddCircle.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "SaveAction.h"
#include <iostream>
ActionAddCircle::ActionAddCircle(ApplicationManager * pApp):Action(pApp)
{}

//Execute the action
void ActionAddCircle::Execute()
{
	Point P1,P2;
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	int circleRadius;
	GfxInfo CirrGfxInfo; //Style for drawn circle
	CirrGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CirrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	CirrGfxInfo.FillClr = pGUI->getCrntFillColor();
	CirrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	//Step 1 - Read Ellipse data from the user
		//Read 1st point and store in point P1
	pGUI->PrintMessage("New Circle: Click at center point");	
	pGUI->GetPointClicked(P1.x, P1.y);
	P1 = pGUI->ValidatePoint(P1);
		//Read 2nd point and store in point P2
	pGUI->PrintMessage("New Circle: Select radius");
	pGUI->GetPointClicked(P2.x, P2.y);
	circleRadius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));

	if ((P1.y + circleRadius > UI.height-UI.StatusBarHeight) || (P1.y - circleRadius < UI.ToolBarHeight))
	{
		bool flag = true;
		pGUI->PrintMessage("Can't choose here! Please choose another point in the drawing area");
		while (flag)
		{
			pGUI->GetPointClicked(P2.x, P2.y);
			//Step 2 - Prepare radius of circle
				//user clicked 2 points, radius will be the  distance between these points
			circleRadius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
			if (!((P1.y + circleRadius > UI.height - UI.StatusBarHeight) || (P1.y - circleRadius < UI.ToolBarHeight)))
				flag = false;
		}
	}
	//Clear status bar
	pGUI->ClearStatusBar();

	
	//Step 3 - Create a Circle with the parameters read from the user
	CCircle *C=new CCircle(P1, circleRadius, CirrGfxInfo);

	//Step 4 - Add the Circle to the list of figures
	pManager->AddFigure(C);
	SaveAction saveAction(pManager);
	saveAction.SaveActionStack();

}
