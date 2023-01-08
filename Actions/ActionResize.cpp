#include "ActionResize.h"
#include "..\ApplicationManager.h"
#include "SaveAction.h"
#include "..\GUI\GUI.h"
#include <math.h>

ActionResize::ActionResize(ApplicationManager * pApp, float factor):Action(pApp), resizeFactor(factor)
{}

void ActionResize::Execute()
{
	vector<CFigure*>& figlist = pManager->getselectedfigure();
	GUI* pGUI = pManager->GetGUI();
	for (int i = 0; i < figlist.size(); i++) {
		int x = figlist[i]->resize(resizeFactor);
		if (x == -1) {
			pGUI->PrintMessage("Some shapes couldn't be resized! Shape will be out of draw area");
		}
		else {
			pGUI->ClearStatusBar();
		}
	}
	SaveAction saveAction(pManager);
	saveAction.SaveActionStack();
}

