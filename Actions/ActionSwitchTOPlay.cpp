#include "ActionSwitchTOPlay.h";
#include "../GUI/GUI.h"
#include "../ApplicationManager.h";
ActionSwitchTOPlay::ActionSwitchTOPlay(ApplicationManager *pApp) : Action(pApp) {};
 void ActionSwitchTOPlay::Execute()
{
     GUI* pGUI = pManager->GetGUI();
     pGUI->PrintMessage("Switch To Play Mode");
     pGUI->CreateToolBar();
     pGUI->CreatePlayToolBar();
}

