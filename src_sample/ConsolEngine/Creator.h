#pragma once
#include "Figure_Parent.h"
class Creator
{
public:
	virtual Figure_Parent * FactoryMethod(int x, int y)=0;
	Creator();
	/*Creator(const Creator& obj); 
	Creator& operator=(const Creator& obj); */
	virtual ~Creator();
};

