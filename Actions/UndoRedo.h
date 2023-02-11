#ifndef ACTION_UndoRedo_H
#define ACTION_UndoRedo_H

#include "Action.h"

//Add Square Action class
class ActionUndoRedo : public Action
{
	bool isUndo;
public:
	int static Counter;
	ActionUndoRedo(ApplicationManager* pApp, bool);
	virtual void Execute();
};

#endif


