#include "Creator_T5.h"



Creator_T5::Creator_T5()
{
}


Creator_T5::~Creator_T5()
{
}
Figure_Parent * Creator_T5::FactoryMethod(int x, int y)
{


	return (new Figure_T5(x, y));
}