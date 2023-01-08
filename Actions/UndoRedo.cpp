#include "UndoRedo.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "LoadAction.h"
#include <math.h>
#include <iostream>

ActionUndoRedo::ActionUndoRedo(ApplicationManager* pApp, bool _mode) :Action(pApp),isUndo(_mode)
{}
void ActionUndoRedo::Execute()
{
	Point P1;

	GUI* pGUI = pManager->GetGUI();
	if(isUndo)
	{
		if (pManager->getFileCounter()<2) {
			pGUI->PrintMessage("No action to undo");
		}
		else {
			std::cout << pManager->getFileCounter() << "\n";
			Counter++;
			LoadAction load(pManager);
			load.LoadActionStack();
		}
	}
	else {
		if (Counter < 1) {
			pGUI->PrintMessage("No action to redo");
		}
		else {
			Counter--;
			pManager->setFileCounter(pManager->getFileCounter()+2);
			LoadAction load(pManager);
			load.LoadActionStack();
		}
	}
	
}

int ActionUndoRedo::Counter = 0;

