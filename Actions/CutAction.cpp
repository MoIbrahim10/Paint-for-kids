#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "CutAction.h"


CutAction::CutAction(ApplicationManager* pApp) :Action(pApp)
{}

void CutAction::Execute()
{	
	GUI* pGUI = pManager->GetGUI();

	if (pManager->getselectedfigure().size()==0)
		pGUI->PrintMessage("Please Select a figure first to cut");
	else
	{
		pManager->SetClipboard(pManager->getselectedfigure());
		pManager->DeleteFigure();
		pManager->ClearSelectedFigs();
		pGUI->PrintMessage("Selected figure/figures cut into clipboard");
	}

}

