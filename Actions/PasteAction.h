#ifndef ACTION_Paste_H
#define ACTION_Paste_H

#include "Action.h"

class PasteAction : public Action
{
public:
	PasteAction(ApplicationManager* pApp);
	virtual void Execute();
};

#endif


