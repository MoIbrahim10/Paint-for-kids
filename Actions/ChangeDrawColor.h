#ifndef ACTION_CHANGE_DRAW_COLOR_H
#define ACTION_CHANGE_DRAW_COLOR_H
#include "Action.h"
#include"..\Figures\CFigure.h"

class ChangeDrawColor :public Action {

	color DrawColor;

public:
	// Constructor For Change Draw Color Class 
	ChangeDrawColor(ApplicationManager* pApp);
	//Excute Change Draw Color Action
	virtual void Execute();	
};

#endif

