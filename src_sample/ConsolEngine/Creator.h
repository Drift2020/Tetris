#pragma once
#include "Figure_Parent.h"
class Creator
{
public:
	Figure_Parent virtual *FactoryMethod();
	Creator();
	Creator(const Creator& obj); 
	Creator& operator=(const Creator& obj); 
	virtual ~Creator();
};
