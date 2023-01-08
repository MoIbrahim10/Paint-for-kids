#ifndef ACTION_Copy_H
#define ACTION_Copy_H

#include "Action.h"

//Add Square Action class
class CopyAction : public Action
{
public:
	// Constructor For Copy Action Class 
	CopyAction(ApplicationManager* pApp);
	//Excute Copy Action
	virtual void Execute();
};

#endif


