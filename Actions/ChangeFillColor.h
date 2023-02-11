#pragma once

#include "Action.h"

//Add Square Action class
class ChangeFillColor : public Action
{
	color FillColor;
public:
	// Constructor For Change Fill Color Action Class 
	ChangeFillColor(ApplicationManager* pApp);
	//Excute Change Fill Color Action
	virtual void Execute();
};
