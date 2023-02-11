#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "SaveAction.h"
#include<fstream>

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SaveAction::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	CFigure* fig;

	pGUI->PrintMessage("Please write the name of the file then press ENTER");
	FileName = pGUI->GetSrting();
	FileName += ".txt";
	ofstream savedFile;
	savedFile.open("SavedFigures//" + FileName);
	bool error = false;
	if (savedFile.fail()) //Check the FileName and loop till be Valid name
		error = true;
	while (error)
	{
		pGUI->PrintMessage("Please ENTER a valid name!");
		FileName = pGUI->GetSrting();
		FileName += ".txt";
		savedFile.open("SavedFigures//" + FileName);
		if (savedFile.good())
			error = false;
	}
	savedFile << pManager->Color2String(pGUI->getCrntBgColor()) << "\t" << pManager->Color2String(pGUI->getCrntDrawColor()) << "\t" << pManager->Color2String(pGUI->getCrntFillColor()) << "\n";
	savedFile << pManager->GetFigtList().size() << "\n";
	pManager->SaveScreen(savedFile);
	pGUI->PrintMessage("File Saved successfully!!");
	savedFile.close();
}

void SaveAction::SaveActionStack() {
	pManager->setFileCounter(pManager->getFileCounter() + 1);
	GUI* pGUI = pManager->GetGUI();
	CFigure* fig;
	stringstream counterIntToString;
	counterIntToString << pManager->getFileCounter();
	FileName = "File" + counterIntToString.str() + ".txt";
	ofstream savedFile;
	savedFile.open(("Stack//" + FileName),ios::trunc);
	savedFile << pManager->Color2String(pGUI->getCrntBgColor()) << "\t" << pManager->Color2String(pGUI->getCrntDrawColor()) << "\t" << pManager->Color2String(pGUI->getCrntFillColor()) << "\n";
	savedFile << pManager->GetFigtList().size() << "\n";
	pManager->SaveScreen(savedFile);
	savedFile.close();
}




