#include "Figure_Parent.h"
#include <algorithm>


#pragma region  system
Figure_Parent::Figure_Parent()
{
	 _x=0;
	 _y=0;
	 _blocks = nullptr;
}

Figure_Parent::Figure_Parent(int x, int y, Block ** blocks)
{
	 _x = x;
	 _y = y;
	 _blocks = blocks;
}

Figure_Parent::~Figure_Parent()
{
	for (int i = 0; i < _count_block; i++)
	{
		delete _blocks[i];
	}
	delete[]_blocks;
}
#pragma endregion



#pragma region get
Block Get_block() 
{

}
int Get_X()
{

}
int Get_Y()
{

}
#pragma endregion


#pragma region set
void Set_block(Block *& block)
{

}
void Set_X(int x)
{

}
void Set_Y(int y)
{

}
#pragma endregion


#pragma region  move
void Move_on(int x, int y)
{

}
void Move_to(int x, int y)
{

}
void Rotate(my_enums::Rotate r)
{

}
#pragma endregion







