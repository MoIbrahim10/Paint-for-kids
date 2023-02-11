#include "ActionDelete.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "SaveAction.h"

ActionDelete::ActionDelete(ApplicationManager * pApp):Action(pApp)
{}

//Execute the action
void ActionDelete::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	//Call Delete figure function to delete all selected figures
	pManager->DeleteFigure();
	//Clear status bar 
	pGUI->ClearStatusBar();

	SaveAction saveAction(pManager);
	saveAction.SaveActionStack();
}

