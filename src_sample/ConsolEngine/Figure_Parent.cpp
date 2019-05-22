
#include "Figure_Parent.h"
#include <algorithm>


#pragma region  system
Figure_Parent::Figure_Parent()
{
	 _x=0;
	 _y=0;
	 _size = 0;
	

	
}


Figure_Parent::Figure_Parent(int x,int y)
{
	_x = x;
	_y = y;
	_size = 0;
	_state = my_enums::Down;


}

Figure_Parent::Figure_Parent(const int x, const int y, const int size, Block ** blocks)
{
	 _x = x;
	 _y = y;
	 _blocks = blocks;
}


//Figure_Parent::Figure_Parent(const Figure_Parent& obj) // конструктор копирования
//{
//	
//
//
//	
//}
//Figure_Parent& Figure_Parent::operator=(const Figure_Parent& obj) // оператор присваивания
//{
//	
//}

Figure_Parent::~Figure_Parent()
{
	for (int i=0;i< this->_size;i++)
	{
		 delete _blocks[i];
	}
	delete[]  _blocks;
}

void Figure_Parent::Remove_block(int i)
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
Block *Figure_Parent::Get_block(int i)
{
	return _blocks[i];
}
int Figure_Parent::Get_X()
{
	return _x;
}
int Figure_Parent::Get_Y()
{
	return _y;
}

int   Figure_Parent::Get_size() {
	return _size;
}
my_enums::Move Figure_Parent::Get_state()
{
	return this->_state;
}
#pragma endregion


#pragma region set
void Figure_Parent::Add_block(Block * block)
{

}
void Figure_Parent::Set_X(int x)
{

}
void Figure_Parent::Set_Y(int y)
{

}

void  Figure_Parent::Set_size(int s)
{

}
void Figure_Parent::Set_state(my_enums::Move _state)
{
	this->_state = _state;
}
#pragma endregion


#pragma region  move
void Figure_Parent::Move_on(int x, int y)
{

}
void Figure_Parent::Move_to(int x, int y)
{

}
void Figure_Parent::Rotate(my_enums::Rotate r)
{

}
#pragma endregion









