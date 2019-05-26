#include "Creator_T7.h"



Creator_T7::Creator_T7()
{
}


Creator_T7::~Creator_T7()
{
}
Figure_Parent * Creator_T7::FactoryMethod(int x, int y)
{


	return (new Figure_T7(x, y));
}