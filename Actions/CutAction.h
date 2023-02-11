#ifndef ACTION_Cut_H
#define ACTION_Cut_H

#include "Action.h"

class CutAction : public Action
{
public:
	// Constructor For Cut Action Class 
	CutAction(ApplicationManager* pApp);
	//Excute Cut Action
	virtual void Execute();
};

#endif


