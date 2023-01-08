#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"
#include "SaveAction.h"
#include "..\GUI\GUI.h"


ChangeDrawColor::ChangeDrawColor(ApplicationManager* pApp) :Action(pApp)
{
	DrawColor = UI.DrawColor;
}

void ChangeDrawColor::Execute()
{
	UI.InterfaceMode = MODE_COLOR;
	GUI* pGUI = pManager->GetGUI();

	pGUI->CreateColorBar();


	pManager->GetColor(DrawColor);
	pGUI->setCrntDrawColor(DrawColor);

	vector<CFigure*>& figlist = pManager->getselectedfigure();

	for (int i = 0; i < figlist.size(); i++)
	{
		figlist[i]->ChngDrawClr(DrawColor);
		SaveAction saveAction(pManager);
		saveAction.SaveActionStack();
	}
	pGUI->CreateDrawToolBar();
	
}

