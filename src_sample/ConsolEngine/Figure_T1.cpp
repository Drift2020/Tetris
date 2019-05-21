#include "Figure_T1.h"
#include <algorithm>


#pragma region  system




Figure_T1::Figure_T1() : Figure_Parent()
{
	size=4
	for (int i = 0; i < size; i++)
		_blocks;
}


Figure_T1::~Figure_T1()
{
	
}

Figure_T1::Figure_T1(int x, int y, std::list<Block> blocks) :Figure_Parent(x, y, blocks)
{
	
}
void Figure_T1::Remove_block(int i)
{
	if (i > 0 && _blocks.size() > 0)
	{
		pb = _blocks.begin();
		for (int i1 = 0; i1 < i; i++)
		{
			pb++;
		}

		_blocks.erase(pb, pb++);

	}
}


#pragma endregion



#pragma region get
Block Figure_T1::Get_block(int i)
{
	pb = _blocks.begin();
	for (int _i = 0; _i < i; _i++)
	{
		pb++;
	}
	return *pb;
}
int Figure_T1::Get_X()
{
	return _x;
}
int Figure_T1::Get_Y()
{
	return _y;
}
#pragma endregion


#pragma region set
void Figure_T1::Add_block(Block *& block)
{

}
void Figure_T1::Set_X(int x)
{

}
void Figure_T1::Set_Y(int y)
{

}
#pragma endregion


#pragma region  move
void Figure_T1::Move_on(int x, int y)
{

}
void Figure_T1::Move_to(int x, int y)
{

}
void Figure_T1::Rotate(my_enums::Rotate r)
{

}
#pragma endregion

