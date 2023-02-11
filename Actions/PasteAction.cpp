#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "PasteAction.h"
#include "SaveAction.h"

PasteAction::PasteAction(ApplicationManager* pApp):Action(pApp)
{}

void PasteAction::Execute()
{
	 
	GUI* pGUI = pManager->GetGUI();
	vector<CFigure*>& toBePasted = pManager->GetClipboard();

	if (toBePasted.size()==0)
		pGUI->PrintMessage("Clipboard is empty, cut or copy a figure first");
	else {
		Point x;
		pGUI->PrintMessage("Choose a point in the drawing area to paste");
		pGUI->GetPointClicked(x.x, x.y);

		Point P = pGUI->ValidatePoint(x);

		Point highestPoint = toBePasted[0]->highestPoint();
		for (int i = 0; i < toBePasted.size(); i++)
		{
			 highestPoint = (toBePasted[i]->highestPoint().y < highestPoint.y) ? toBePasted[i]->highestPoint() : highestPoint;
		}

		int transX = P.x - highestPoint.x;
		int transY = P.y - highestPoint.y;

		for (int i = 0; i < toBePasted.size(); i++)
		{
			toBePasted[i]->SetSelected(false);
			pManager->AddFigure(toBePasted[i]->paste(transX, transY));
		}

		pGUI->PrintMessage("Figures pasted!");
	}
	SaveAction saveAction(pManager);
	saveAction.SaveActionStack();
}





