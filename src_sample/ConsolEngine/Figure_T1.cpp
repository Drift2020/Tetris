#include "Figure_T1.h"
#include <algorithm>


#pragma region  system




Figure_T1::Figure_T1() : Figure_Parent()
{
	_size = 4;

	_blocks = new Block*[_size];
	
		Block * temp = new  Block(0,0,'&',my_enums::Stop);
		_blocks[0] = temp;
		 temp = new  Block(0,1,'&',my_enums::Stop);
		 _blocks[1] = temp;
		temp = new  Block(0, 2, '&', my_enums::Stop);
		_blocks[2] = temp;
		 temp = new Block(1, 2, '&', my_enums::Stop);
		 _blocks[3] = temp;
	
}

Figure_T1::Figure_T1(int x,int y) : Figure_Parent(x,y)
{
	_size = 4;

	_blocks = new Block *[_size];

	Block * temp = new  Block(x+0, y+0, '&', my_enums::Stop);
	_blocks[0] = temp;
	temp = new  Block(x+0, y+1, '&', my_enums::Stop);
	_blocks[1] = temp;
	temp = new  Block(x+0, y+2, '&', my_enums::Stop);
	_blocks[2] = temp;
	temp = new Block(x+1, y+2, '&', my_enums::Stop);
	_blocks[3] = temp;

}


Figure_T1::~Figure_T1()
{
	
}

Figure_T1::Figure_T1(const int x, const int y, const int size, Block ** blocks) :Figure_Parent(x, y,size, blocks)
{
	
}
void Figure_T1::Remove_block(int i)
{
	if (i > 0 && _size > 0)
	{
		
		Block** temp = new Block*[_size - 1];

		for (int i = 0; i < _size-1; i++)
		{
			temp[i] = _blocks[i];
		}


		for (int i = 0; i < _size ; i++)
		{
			delete _blocks[i];
		}
		_size--;

		_blocks = temp;

	}
}


#pragma endregion



#pragma region get
Block *Figure_T1::Get_block(int i)
{
	return _blocks[i];
}
int Figure_T1::Get_X()
{
	return _x;
}
int Figure_T1::Get_Y()
{
	return _y;
}

int   Figure_T1::Get_size() {
	return _size;
}
#pragma endregion


#pragma region set
void Figure_T1::Add_block(Block * block)
{

}
void Figure_T1::Set_X(int x)
{

}
void Figure_T1::Set_Y(int y)
{

}

void  Figure_T1::Set_size(int s)
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

