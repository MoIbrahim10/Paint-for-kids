#include "ChangeBgColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include "SaveAction.h"

ChangeBgColor::ChangeBgColor(ApplicationManager* pApp) :Action(pApp)
{
	BgColor = UI.BkGrndColor;
}

void ChangeBgColor::Execute()
{
	UI.InterfaceMode = MODE_COLOR;
	GUI* pGUI = pManager->GetGUI();
	pGUI->CreateColorBar();

	pManager->GetColor(BgColor);
	pGUI->setCrntBgColor(BgColor);
	pGUI->CreateDrawToolBar();
	SaveAction saveAction(pManager);
	saveAction.SaveActionStack();
}

