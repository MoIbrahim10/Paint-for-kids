#ifndef ACTION_SWITCH_TO_PLAY_H
#define ACTION_SWITCH_TO_PLAY_H
#include "Action.h"

//Switch To Play class
class ActionSwitchTOPlay:public Action
{
public:
	// Constructor For Switch to Play Action Class 
	ActionSwitchTOPlay(ApplicationManager* pApp);
	//Excute Switch To Play Action
	virtual void Execute();
};

#endif
