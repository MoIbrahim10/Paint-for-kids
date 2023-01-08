#ifndef ACTION_SWITCH_TO_DRAW_H
#define ACTION_SWITCH_TO_DRAW_H
#include "Action.h"

//Switch To Draw class
class ActionSwitchToDraw  :public Action
{
public:
	// Constructor For Switch to Draw Action Class 
	ActionSwitchToDraw(ApplicationManager* pApp);
	//Excute Switch To Draw Action
	virtual void Execute();
};

#endif
