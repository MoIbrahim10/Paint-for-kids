#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "LoadAction.h"
#include "../Figures/figuresHeader.h"
#include<fstream> 

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}

void LoadAction::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	CFigure* fig;
	string DrawClr, FillClr, bgColor, figureName;
	int figuresCount;

	pGUI->PrintMessage("Enter the name of the file you want to load");

	FileName = pGUI->GetSrting() + ".txt";
	loadFile.open("SavedFigures//" + FileName);

	if (loadFile.is_open())
	{
		pGUI->ClearDrawArea();
		pManager->ClearFigList();

		loadFile >> bgColor >> DrawClr >> FillClr;
		pGUI->setCrntBgColor(pManager->String2Color(bgColor));
		pGUI->setCrntDrawColor(pManager->String2Color(DrawClr));
		pGUI->setCrntFillColor(pManager->String2Color(FillClr));

		loadFile >> figuresCount;
		while (figuresCount)            //For each line on the file we will read it and determine its type
		{
			loadFile >> figureName;

			if (figureName == "CIRCLE")
				fig = new CCircle();
			else if (figureName == "ELLIPSE")
				fig = new CElipse;
			else if (figureName == "HEXAGON")
				fig = new CHexagon;
			else if (figureName == "RECTANGLE")
				fig = new CRectanlge;
			else if (figureName == "SQUARE")
				fig = new CSquare;
			else if (figureName == "TRIANGLE")
				fig = new CTriangle;
			else
				fig = NULL;
			if (fig) {
				fig->Load(loadFile);
				pManager->AddFigure(fig);
				figuresCount--;
			}
		}
		loadFile.close();
		pGUI->ClearStatusBar();
		pGUI->PrintMessage("File is Loaded Successfully");
	}
	else { pGUI->PrintMessage("No file found with name: " + FileName); }
}

void LoadAction::LoadActionStack() {
	pManager->setFileCounter( pManager->getFileCounter() - 1 );
	GUI* pGUI = pManager->GetGUI();
	int figuresCount;
	CFigure* fig;
	string DrawClr, FillClr, bgColor, figureName;
	stringstream counterIntToString;
	counterIntToString << pManager->getFileCounter();
	FileName = "File" + counterIntToString.str() + ".txt";
	loadFile.open("Stack//" + FileName);

	if (loadFile.is_open())
	{
		pGUI->ClearDrawArea();
		pManager->ClearFigList();

		loadFile >> bgColor >> DrawClr >> FillClr;
		pGUI->setCrntBgColor(pManager->String2Color(bgColor));
		pGUI->setCrntDrawColor(pManager->String2Color(DrawClr));
		pGUI->setCrntFillColor(pManager->String2Color(FillClr));

		loadFile >> figuresCount;
		while (figuresCount)            //For each line on the file we will read it and determine its type
		{
			loadFile >> figureName;

			if (figureName == "CIRCLE")
				fig = new CCircle();
			else if (figureName == "ELLIPSE")
				fig = new CElipse;
			else if (figureName == "HEXAGON")
				fig = new CHexagon;
			else if (figureName == "RECTANGLE")
				fig = new CRectanlge;
			else if (figureName == "SQUARE")
				fig = new CSquare;
			else if (figureName == "TRIANGLE")
				fig = new CTriangle;
			else
				fig = NULL;
			if (fig) {
				fig->Load(loadFile);
				pManager->AddFigure(fig);
				figuresCount--;
			}

		}
		loadFile.close();
		pGUI->ClearStatusBar();
	}
}



