#ifndef ACTION_LOAD_H
#define ACTION_LOAD_H

#include "Action.h"

class LoadAction : public Action
{
	string FileName;
	ifstream loadFile;
public:
	LoadAction(ApplicationManager* );
	void LoadActionStack();
	virtual void Execute();
};

#endif


