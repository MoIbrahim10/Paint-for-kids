#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ActionPlayWithColor :public Action
{
	Point p;
	int correct;
	int wrong;
	color Fig_Color;
public:
	ActionPlayWithColor(ApplicationManager* pApp);
	virtual void Execute();
};