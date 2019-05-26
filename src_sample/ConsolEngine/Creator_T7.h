#pragma once
#include "Creator.h"
#include "Figure_T7.h"
class Creator_T7 :
	public Creator
{
public:
	Figure_Parent * FactoryMethod(int x, int y) override;
	Creator_T7();
	~Creator_T7();
};

