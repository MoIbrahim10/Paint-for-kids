#ifndef ACTION_CHANGE_BG_COLOR_H
#define ACTION_CHANGE_BG_COLOR_H
#include "Action.h"

//Change Background Color class
class ChangeBgColor : public Action
{
	color BgColor;
public:
	// Constructor For Change Background Color Action Class 
	ChangeBgColor(ApplicationManager* pApp);
	//Excute Change Background Color Action
	virtual void Execute();
};

#endif