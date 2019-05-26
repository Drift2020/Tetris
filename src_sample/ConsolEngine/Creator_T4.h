#pragma once
#include "Creator.h"
#include "Figure_T4.h"
class Creator_T4 :
	public Creator
{
public:
	Figure_Parent * FactoryMethod(int x, int y) override;
	Creator_T4();
	~Creator_T4();
};

