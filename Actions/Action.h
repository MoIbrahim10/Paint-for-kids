#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include <math.h>
class ApplicationManager; //forward class declaration

//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor
	virtual void Execute() =0; //Excuted action
};

#endif