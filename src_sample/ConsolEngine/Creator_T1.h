#pragma once
#include "Creator.h"
#include "Figure_T1.h"
class Creator_T1 :
	public Creator
{
public:
	Creator_T1();
	~Creator_T1();

	Figure_Parent  FactoryMethod(int x,int y) override;
};

