#ifndef ACTION_DELETE_H
#define ACTION_DELETE_H
#include "Action.h"

//Delete Action class
class ActionDelete : public Action
{
public:
	// Constructor For Delete Action Class 
	ActionDelete(ApplicationManager* pApp);
	//Excute Delete Action
	virtual void Execute();
};

#endif
