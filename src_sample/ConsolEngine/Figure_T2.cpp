#include "Figure_T2.h"
#include <algorithm>


#pragma region  system




Figure_T2::Figure_T2() : Figure_Parent()
{
	_size = 4;
	this->_state_block = my_enums::T2;
	_blocks = new Block*[_size];

	
	_blocks[0] = new  Block(1, 0, '&', my_enums::Down);
 
	_blocks[1] = new  Block(1, 1, '&', my_enums::Down);

	_blocks[2] = new  Block(1, 2, '&', my_enums::Down);

	_blocks[3] = new Block(0, 2, '&', my_enums::Down);
	_state = my_enums::Down;
}

Figure_T2::Figure_T2(int x, int y) : Figure_Parent(x, y)
{
	_size = 4;
	this->_state_block = my_enums::T2;
	_blocks = new Block *[_size];


	_blocks[0] = new  Block(1, 0, '&', my_enums::Down);

	_blocks[1] = new  Block(1, 1, '&', my_enums::Down);

	_blocks[2] = new  Block(1, 2, '&', my_enums::Down);

	_blocks[3] = new Block(0, 2, '&', my_enums::Down);
	_state = my_enums::Down;
}


Figure_T2::~Figure_T2()
{

}



void Figure_T2::Remove_block(int i)
{
	if (i > 0 && _size > 0)
	{

		Block** temp = new Block*[_size - 1];

		for (int i = 0; i < _size - 1; i++)
		{
			temp[i] = _blocks[i];
		}


		for (int i = 0; i < _size; i++)
		{
			delete _blocks[i];
		}
		_size--;

		_blocks = temp;

	}
}


#pragma endregion



#pragma region get
Block *Figure_T2::Get_block(int i)
{
	return _blocks[i];
}
int Figure_T2::Get_X()
{
	return _x;
}
int Figure_T2::Get_Y()
{
	return _y;
}

int   Figure_T2::Get_size() {
	return _size;
}
my_enums::Block Figure_T2::Get_state_block()
{
	return _state_block;
}
#pragma endregion


#pragma region set
void Figure_T2::Add_block(Block * block)
{

}
void Figure_T2::Set_X(int x)
{

}
void Figure_T2::Set_Y(int y)
{

}

void  Figure_T2::Set_size(int s)
{

}
#pragma endregion

