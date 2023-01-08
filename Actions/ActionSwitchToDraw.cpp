#include "ActionSwitchToDraw.h"
#include "../GUI/GUI.h"
#include "../ApplicationManager.h";
ActionSwitchToDraw::ActionSwitchToDraw(ApplicationManager* pApp) :Action(pApp) {};
void ActionSwitchToDraw::Execute()
{
	pManager->showAllFigure();
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("SWITCH TO DRAW MODE");
	pGUI->CreateToolBar();
	pGUI->CreateDrawToolBar();
}