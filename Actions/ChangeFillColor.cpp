#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "SaveAction.h"

ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) :Action(pApp)
{
	FillColor = UI.FillColor;
}

void ChangeFillColor::Execute()
{
	UI.InterfaceMode = MODE_COLOR;
	GUI* pGUI = pManager->GetGUI();

	pGUI->CreateColorBar();
	
	pManager->GetColor(FillColor);
	pGUI->setCrntFillColor(FillColor);

	vector<CFigure*>& figlist = pManager->getselectedfigure();

	for (int i = 0; i < figlist.size(); i++)
	{
		figlist[i]->ChngFillClr(FillColor);
		SaveAction saveAction(pManager);
		saveAction.SaveActionStack();
	}
	pGUI->CreateDrawToolBar();
	
}

