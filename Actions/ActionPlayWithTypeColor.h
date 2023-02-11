#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ActionPlayWithTypeColor : public Action
{
	Point p;
	int correct;
	int wrong;
	color Fig_Type_color;
	string Fig;

public:
	ActionPlayWithTypeColor(ApplicationManager* pApp);


	virtual void Execute();
};