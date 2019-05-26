#pragma once
#include "Creator.h"
#include "Figure_T6.h"
class Creator_T6 :
	public Creator
{
public:
	Figure_Parent * FactoryMethod(int x, int y) override;
	Creator_T6();
	~Creator_T6();
};

