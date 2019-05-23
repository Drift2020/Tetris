#include "Creator_T1.h"



Creator_T1::Creator_T1() :Creator()
{
}


Creator_T1::~Creator_T1()
{
}

Figure_Parent * Creator_T1::FactoryMethod(int x,int y)
{
	Figure_Parent * temp = new Figure_T1(x, y);

	return temp;
}