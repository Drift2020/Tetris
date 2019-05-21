#include "Figure_T5.h"
#include <algorithm>


#pragma region  system




Figure_T5::Figure_T5() : Figure_Parent()
{

}


Figure_T5::~Figure_T5()
{

}

Figure_T5::Figure_T5(int x, int y, std::list<Block> blocks) :Figure_Parent(x, y, blocks)
{

}
void Figure_T5::Remove_block(int i)
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
Block Figure_T5::Get_block(int i)
{
	pb = _blocks.begin();
	for (int _i = 0; _i < i; _i++)
	{
		pb++;
	}
	return *pb;
}
int Figure_T5::Get_X()
{
	return _x;
}
int Figure_T5::Get_Y()
{
	return _y;
}
int   Figure_T5::Get_size() {
	return _size;
}
#pragma endregion


#pragma region set
void Figure_T5::Add_block(Block *& block)
{

}
void Figure_T5::Set_X(int x)
{

}
void Figure_T5::Set_Y(int y)
{

}
void  Figure_T5::Set_size(int s)
{

}
#pragma endregion


#pragma region  move
void Figure_T5::Move_on(int x, int y)
{

}
void Figure_T5::Move_to(int x, int y)
{

}
void Figure_T5::Rotate(my_enums::Rotate r)
{

}
#pragma endregion

