#include "ApplicationManager.h"
#include "Actions_headers.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	pGUI = new GUI;
	fileCounter = 1;
}
void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();

	}while(ActType != EXIT);
}
//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_SQUARE:
		newAct = new ActionAddSquare(this);
		break;

	case DRAW_CIRCLE:
		newAct = new ActionAddCircle(this);
		break;

	case DRAW_RECTANGLE:
		newAct = new ActionAddRectangle(this);
		break;

	case DRAW_TRIANGLE:
		newAct = new ActionAddTriangle(this);
		break;

	case DRAW_ELIPSE:
		newAct = new ActionAddElipse(this);
		break;

	case DRAW_HEX:
		newAct = new ActionAddHexagon(this);
		break;

	case CHNG_DRAW_CLR: 
		newAct = new ChangeDrawColor(this);
		break;
	case CHNG_FILL_CLR:
		newAct = new ChangeFillColor(this);
		break;
	case CHNG_BK_CLR:
		newAct = new ChangeBgColor(this);
		break;

	case selectt:
		newAct = new ActionSelect(this);
		break;

	case deletee:
		newAct = new ActionDelete(this);
		break;

	case bringFront:
		newAct = new ActionBringToFront(this);
		break;

	case bringBack:
		newAct = new ActionBringToBack(this);
		break;
	case RESIZE_QUARTER:
		newAct = new ActionResize(this, 0.25);
		break;
	case RESIZE_HALF:
		newAct = new ActionResize(this, 0.5 );
		break;
	case RESIZE_DOUBLE:
		newAct = new ActionResize(this, 2);
		break;
	case RESIZE_QUADRUPLE:
		newAct = new ActionResize(this, 4);
		break;
	case UNDO:
		newAct = new ActionUndoRedo(this,true);
		break;
	case REDO:
		newAct = new ActionUndoRedo(this,false);
		break;
	case CUT:
		newAct = new CutAction(this);
		break;
	case COPY:
		newAct = new CopyAction(this);
		break;
	case PASTE:
		newAct = new PasteAction(this);
		break;
	case SAVE:
		newAct = new SaveAction(this);
		break;
	case LOAD:
		newAct = new LoadAction(this);
		break;
	case EXIT:
		newAct = new ExitAction(this);
		break;
	case SWITCHTOPLAY:
		newAct = new ActionSwitchTOPlay(this);
		break;
	case SWITCHTODRAW:
		newAct = new ActionSwitchToDraw(this);
		break;
	case PLAYWITHTYPE:
		newAct = new ActionPlayWithType(this);
		break;
	case PLAYWITHCOLOR:
		newAct = new ActionPlayWithColor(this);
		break;
	case PLAYWITHTYPECOLOR:
		newAct = new ActionPlayWithTypeColor(this);
		break;
	case STATUS:	//a click on the status bar ==> no action
		return NULL;
		break;
	default:
		//if (ActType == NULL);
		//else
		newAct = new ActionSelect(this);
		break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//
//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	FigList.push_back(pFig);
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for (int i=FigList.size()-1;i>=0;i--)
	{
		if (FigList[i]->isInside(x, y))
		{
			return FigList[i];
		}
	}
	return NULL;
}

vector<CFigure*>& ApplicationManager::GetFigtList()
{
	return FigList;
}


int ApplicationManager::GetFigureIndex(CFigure* x)
{
	for (int i = 0; i < FigList.size(); i++)
	{
		if (FigList[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void ApplicationManager::DeleteFigure()
{
	for (int i = FigList.size() - 1; i >= 0; i--)
	{
		if (FigList[i]->IsSelected())
		{
			for (int j = selectedfigure.size() - 1; j >= 0; j--)
			{
				if (FigList[i] == selectedfigure[j])
				{
					selectedfigure.erase(selectedfigure.begin() + j);
					break;
				}
			}
			FigList.erase(FigList.begin() + i);
		}
	}
}


void ApplicationManager::pushselectedfigure(CFigure* pfig)
{
	selectedfigure.push_back(pfig);
}

void ApplicationManager::popselectedfigure(CFigure* pfig)
{
	for (int i = 0; i < selectedfigure.size(); i++) {
		if (pfig == selectedfigure[i]) {
			selectedfigure.erase(selectedfigure.begin() + i);
			break;
		}
	}
}

vector<CFigure*>& ApplicationManager::getselectedfigure() 
{
	return selectedfigure;
}

void ApplicationManager::ClearSelectedFigs() {
	selectedfigure.clear();
}

void ApplicationManager::SetClipboard(vector<CFigure*> figs)
{
	clearClipboard();
	for (int i = 0; i < figs.size(); i++) {
		Clipboard.push_back(figs[i]);
	}
}

vector<CFigure*>&  ApplicationManager::GetClipboard() 
{
	return Clipboard;
}


void ApplicationManager::clearClipboard()
{
	Clipboard.clear();
}

color ApplicationManager::String2Color(string x) const {
	if (x == "WHITE") return WHITE;
	if (x == "LIGHTYELLOW") return LIGHTYELLOW;
	if (x == "ORANGE") return ORANGE;
	if (x == "PINK") return PINK;
	if (x == "ROSE") return ROSE;
	if (x == "RED") return RED;
	if (x == "DARKRED") return DARKRED;
	if (x == "TAN") return TAN;
	if (x == "ROSYBROWN") return ROSYBROWN;
	if (x == "BROWN") return BROWN;
	if (x == "LAVENDER") return LAVENDER;
	if (x == "PURPLE") return PURPLE;
	if (x == "MEDIUMPURPLE") return MEDIUMPURPLE;
	if (x == "LIGHTGREEN") return LIGHTGREEN;
	if (x == "GREEN") return GREEN;
	if (x == "GREEN2") return GREEN2;
	if (x == "TEAL") return TEAL;
	if (x == "LIGHTTURQUOISE") return LIGHTTURQUOISE;
	if (x == "TURQUOISE") return TURQUOISE;
	if (x == "INDIGO") return INDIGO;
	if (x == "SKYBLUE") return SKYBLUE;
	if (x == "BLUE") return BLUE;
	if (x == "BLUEGRAY") return BLUEGRAY;
	if (x == "GRAY") return GRAY;
	if (x == "DARKGRAY") return DARKGRAY;
	if (x == "BLACK") return BLACK;
	if (x == "LIGHTGOLDENRODYELLOW") return LIGHTGOLDENRODYELLOW;
	return BLACK;
}
string ApplicationManager::Color2String(color x) const {

	if (x == WHITE) return "WHITE";
	if (x == LIGHTYELLOW) return "LIGHTYELLOW";
	if (x == ORANGE) return "ORANGE";
	if (x == PINK) return "PINK";
	if (x == ROSE) return "ROSE";
	if (x == RED) return "RED";
	if (x == DARKRED) return "DARKRED";
	if (x == TAN) return "TAN";
	if (x == ROSYBROWN) return "ROSYBROWN";
	if (x == BROWN) return "BROWN";
	if (x == LAVENDER) return "LAVENDER";
	if (x == PURPLE) return "PURPLE";
	if (x == MEDIUMPURPLE) return "MEDIUMPURPLE";
	if (x == LIGHTGREEN) return "LIGHTGREEN";
	if (x == GREEN) return "GREEN";
	if (x == GREEN2) return "GREEN2";
	if (x == TEAL) return "TEAL";
	if (x == LIGHTTURQUOISE) return "LIGHTTURQUOISE";
	if (x == TURQUOISE) return "TURQUOISE";
	if (x == INDIGO) return "INDIGO";
	if (x == SKYBLUE) return "SKYBLUE";
	if (x == BLUE) return "BLUE";
	if (x == BLUEGRAY) return "BLUEGRAY";
	if (x == GRAY) return "GRAY";
	if (x == DARKGRAY) return "DARKGRAY";
	if (x == BLACK) return "BLACK";
	if (x == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	return "InValid";
}



void ApplicationManager::GetColor(color& _Color) {

	ActionType getColorAction = pGUI->MapInputToActionType();
	switch (getColorAction) {

	case SET_WHITE:
		_Color = WHITE;
		break;
	case SET_LIGHT_YELLOW:
		_Color = LIGHTYELLOW;
		break;
	case SET_ORANGE:
		_Color = ORANGE;
		break;
	case SET_PINK:
		_Color = PINK;
		break;
	case SET_ROSE:
		_Color = ROSE;
		break;
	case SET_RED:
		_Color = RED;
		break;
	case SET_DARK_RED:
		_Color = DARKRED;
		break;
	case SET_TAN:
		_Color = TAN;
		break;
	case SET_LIGHT_BROWN:
		_Color = ROSYBROWN;
		break;
	case SET_BROWN:
		_Color = BROWN;
		break;
	case SET_LAVENDER:
		_Color = LAVENDER;
		break;
	case SET_PURPLE:
		_Color = PURPLE;
		break;
	case SET_PURPLE2:
		_Color = MEDIUMPURPLE;
		break;
	case SET_LIGHT_GREEN:
		_Color = LIGHTGREEN;
		break;
	case SET_GREEN:
		_Color = GREEN;
		break;
	case SET_GREEN2:
		_Color = GREEN2;
		break;
	case SET_TEAL:
		_Color = TEAL;
		break;
	case SET_LIGHT_TURQUOISE:
		_Color = LIGHTTURQUOISE;
		break;
	case SET_TURQUOISE:
		_Color = TURQUOISE;
		break;
	case SET_INDIGO:
		_Color = INDIGO;
		break;
	case SET_SKY_BLUE:
		_Color = SKYBLUE;
		break;
	case SET_BLUE:
		_Color = BLUE;
		break;
	case SET_BLUE_GRAY:
		_Color = BLUEGRAY;
		break;
	case SET_GRAY:
		_Color = GRAY;
		break;
	case SET_DARK_GRAY:
		_Color = DARKGRAY;
		break;
	case SET_BLACK:
		_Color = BLACK;
		break;
	}
}
void ApplicationManager::SaveScreen(ofstream& OutFile)   //Call the Save function for each Figure
{
	for (int i = 0; i < FigList.size(); ++i)
		FigList[i]->Save(OutFile);
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//
// 
//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pGUI->ClearDrawArea();

	for (int i = 0; i < FigList.size(); i++) {
		if (!FigList[i]->getHiddenValue())
		{
			FigList[i]->DrawMe(pGUI);
		}
	}	
	if (UI.InterfaceMode == MODE_DRAW) {
		/*pGUI->CreateToolBar();*/
		//pGUI->CreateDrawToolBar();
		/*pGUI->CreateStatusBar();*/
	}
	else if (UI.InterfaceMode == MODE_PLAY)
		pGUI->CreatePlayToolBar();	
	
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////


string ApplicationManager::GetRandomFigure(int& Count)const
{
	Count = 0;
	int random;
	string FigureName;
	if (FigList.size() != 0)
	{
		if (FigList.size() != 1)
		{
			random = rand() % (FigList.size());
			FigureName = FigList[random]->GetFigName();
			for (int i = 0; i < FigList.size(); i++)//to get count of  spcefic  type of Shapes in drawing area
			{
				if (FigList[random]->GetFigName() == FigList[i]->GetFigName())
				{

					Count++;
				}
			}
		}
		else
		{
			FigureName = FigList[0]->GetFigName();
			Count = 1;
		}
		return FigureName;
	}
	else
	{
		return "Empty";
	}

}

color ApplicationManager::GetRandomColor(int& Count)const {
  Count = 0;
  int random;
  color FigureColor;
  bool flag = false;

  if (FigList.size() != 0) {
      for (int i = 0; i < FigList.size(); i++)
      {
        if (FigList[i]->IsFigureFilled())
        {
          flag = true;
          break;
        }
      }
    if (flag == true) {
      if (FigList.size() != 1)
      {
        do {
          random = rand() % FigList.size();
        } while (!FigList[random]->IsFigureFilled());

        FigureColor = FigList[random]->GetFigColor();
        
        for (int i = 0; i < FigList.size(); i++)
        {
          if (FigList[random]->GetFigColor() == FigList[i]->GetFigColor())
          {
            Count++;
          }
        }
      }
      else
      {
        FigureColor = FigList[0]->GetFigColor();
        Count = 1;
      }
      return FigureColor;
    }

  }

  return UI.BkGrndColor;
}

string ApplicationManager::GetRandomColorType(int& Count, color& FigColor) const
{
  Count = 0;
  int random;
  string Figure;
  bool flag = false;

  if (FigList.size() != 0)
  {
    for (int i = 0; i < FigList.size(); i++)
    {
      if (FigList[i]->IsFigureFilled())
      {
        flag = true;
        break;
      }
    }
    if (flag = true) {
      if (FigList.size() != 1)
      {
        do {
          random = rand() % FigList.size();
        } while (!FigList[random]->IsFigureFilled());
        FigColor = FigList[random]->GetFigColor(); //COLOR
        Figure = FigList[random]->GetFigName();	//TYPE
        for (int i = 0; i < FigList.size(); i++)
        {
          if (FigColor == FigList[i]->GetFigColor() && Figure == FigList[i]->GetFigName())
          {
            Count++;
          }
        }
      }
      else
      {
        FigColor = FigList[0]->GetFigColor();
        Figure = FigList[0]->GetFigName();
        Count = 1;

      }
    }

    return Figure;
  }
  else return "Empty";
}

void ApplicationManager::showAllFigure()
{
	for (int i = 0; i < FigList.size(); i++)
	{
		FigList[i]->show(true);
	}
}

void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigList.size(); i++)
		delete FigList[i];

	FigList.clear();
}

void ApplicationManager::setFileCounter(int newFileCounter) {

	fileCounter= newFileCounter;
}

int ApplicationManager::getFileCounter() {
	return fileCounter;
}

//Destructor
ApplicationManager::~ApplicationManager()
{

	//for (int i = 0; i < selectedfigure.size(); i++)
	//	delete selectedfigure[i];

	for (int i = 0; i < Clipboard.size(); i++)
		delete Clipboard[i];

	for (int i = 0; i < FigList.size(); i++)
		delete FigList[i];

	delete pGUI;
}
