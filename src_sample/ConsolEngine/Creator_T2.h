#pragma once
#include "Creator.h"
#include "Figure_T2.h"
class Creator_T2 :
	public Creator
{
public:
	Creator_T2();
	~Creator_T2();
	Figure_Parent * FactoryMethod(int x, int y) override;
};

