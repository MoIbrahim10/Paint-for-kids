#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "CopyAction.h"
#include "SaveAction.h"

CopyAction::CopyAction(ApplicationManager* pApp) :Action(pApp)
{
}

void CopyAction::Execute()
{
	GUI* pGUI = pManager->GetGUI();

	if (pManager->getselectedfigure().size() == 0)
		pGUI->PrintMessage("Please Select a figure first to cut");
	else 
	{
		vector<CFigure*> clonedFigs;
		for (int i = 0; i < pManager->getselectedfigure().size(); i++)
		{
			clonedFigs.emplace_back(pManager->getselectedfigure()[i]->clone());
			clonedFigs[i]->SetSelected(false);
			pManager->getselectedfigure()[i]->SetSelected(false);
		}
		pManager->SetClipboard(clonedFigs);
		pManager->ClearSelectedFigs();
		pGUI->PrintMessage("Selected figure/figures copied into clipboard");
	}
}
