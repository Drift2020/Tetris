#include "Creator_T2.h"



Creator_T2::Creator_T2()
{
}


Creator_T2::~Creator_T2()
{
}
Figure_Parent * Creator_T2::FactoryMethod(int x, int y)
{
	

	return (new Figure_T2(x, y));
}