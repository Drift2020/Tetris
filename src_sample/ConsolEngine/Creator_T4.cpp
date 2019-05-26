#include "Creator_T4.h"




Creator_T4::Creator_T4()
{
}


Creator_T4::~Creator_T4()
{
}

Figure_Parent * Creator_T4::FactoryMethod(int x, int y)
{


	return (new Figure_T4(x, y));
}