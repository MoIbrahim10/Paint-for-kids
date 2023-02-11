#include "ActionBringToBack.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <math.h>
#include "SaveAction.h"

ActionBringToBack::ActionBringToBack(ApplicationManager * pApp):Action(pApp)
{}

//Execute the action
void ActionBringToBack::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	//Step 1 - Read point clicked from the user
	pGUI->PrintMessage("Click on any shape");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();

	//Step 2 - Get selected figure from figure list
	CFigure* r = pManager->GetFigure(P1.x, P1.y);
	
	//Step 3 - Check if no figure is selected
	if (!r) { return; }

	//Step 4 - Reshaping figure list
		//Get a refrence of the figure list to be edited 
	vector<CFigure*>& figlist = pManager->GetFigtList();
		//Temporary pointer
	CFigure* temp;
		//Finding the selected figure from the figure list
	for (int i = 0; i < figlist.size(); i++)
	{
		if (figlist[i] == r)
		{
			//Temporary pointer will point at the selected figure
			temp = figlist[i];
			//Selected figure will be erased from the figure
			figlist.erase(figlist.begin() + i);
			//Selected figure will be pushed again at the beginning of the figure list using the temporary pointer
			figlist.insert(figlist.begin(), temp);
			break;
		}
	}
	SaveAction saveAction(pManager);
	saveAction.SaveActionStack();

}

