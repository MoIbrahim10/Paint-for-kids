#ifndef ACTION_SAVE_H
#define ACTION_SAVE_H

#include "Action.h"

class SaveAction : public Action
{
	string FileName;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void Execute();
	void SaveActionStack();
};

#endif


