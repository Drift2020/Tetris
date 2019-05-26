#include "Creator_T3.h"



Creator_T3::Creator_T3()
{
}


Creator_T3::~Creator_T3()
{
}

Figure_Parent * Creator_T3::FactoryMethod(int x, int y)
{
	

	return (new Figure_T3(x, y));
}