#pragma once
#include "Creator.h"
#include "Figure_T3.h"
class Creator_T3 :
	public Creator
{
public:
	Figure_Parent * FactoryMethod(int x, int y) override;
	Creator_T3();
	~Creator_T3();
};

