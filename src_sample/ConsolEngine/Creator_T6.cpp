#include "Creator_T6.h"



Creator_T6::Creator_T6()
{
}


Creator_T6::~Creator_T6()
{
}
Figure_Parent * Creator_T6::FactoryMethod(int x, int y)
{


	return (new Figure_T6(x, y));
}