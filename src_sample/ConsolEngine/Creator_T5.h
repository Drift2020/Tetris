#pragma once
#include "Creator.h"
#include "Figure_T5.h"
class Creator_T5 :
	public Creator
{
public:
	Figure_Parent * FactoryMethod(int x, int y) override;
	Creator_T5();
	~Creator_T5();
};

