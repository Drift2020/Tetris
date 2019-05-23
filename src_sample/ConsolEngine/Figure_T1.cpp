#include "Figure_T1.h"
#include <algorithm>


#pragma region  system




Figure_T1::Figure_T1() : Figure_Parent()
{
	_size = 4;

	_blocks = new Block*[_size];
	
		Block * temp = new  Block(0,0,'&',my_enums::Down);
		_blocks[0] = temp;
		 temp = new  Block(0,1,'&',my_enums::Down);
		 _blocks[1] = temp;
		temp = new  Block(0, 2, '&', my_enums::Down);
		_blocks[2] = temp;
		 temp = new Block(1, 2, '&', my_enums::Down);
		 _blocks[3] = temp;
		 _state = my_enums::Down;
}

Figure_T1::Figure_T1(int x,int y) : Figure_Parent(x,y)
{
	_size = 4;

	_blocks = new Block *[_size];


	_blocks[0] = new  Block(0, 0, '&', my_enums::Stop);

	_blocks[1] = new  Block(0, 1, '&', my_enums::Stop);
	
	_blocks[2] = new  Block(0, 2, '&', my_enums::Stop);
	
	_blocks[3] = new Block(1, 2, '&', my_enums::Stop);

}


Figure_T1::~Figure_T1()
{
	
}

Figure_T1::Figure_T1(const int x, const int y, const int size, Block ** blocks) :Figure_Parent(x, y,size, blocks)
{
	
}


//Figure_T1::Figure_T1(const Figure_T1 & obj):Figure_Parent(obj)
//{
//	
//
//}
//
//Figure_T1::Figure_T1(Figure_T1 && obj) :Figure_Parent(obj)
//{
//	
//}
//
//Figure_T1 & Figure_T1::operator=(Figure_T1 && obj)
//{
//	if (this != &obj)
//	{
//
//		this->_x = obj._x;
//		this->_y = obj._y;
//
//		this->_state = obj._state;
//		this->_size = obj._size;
//
//		for (int i = 0; i < this->_size; i++)
//		{
//			if (_blocks != nullptr && _blocks[i] != nullptr)
//				delete _blocks[i];
//		}
//		delete[]_blocks;
//
//		_blocks = new Block*[_size];
//
//		for (int i = 0; i < _size; i++)
//		{
//			_blocks[i] = obj._blocks[i];
//		}
//
//
//		obj._x = 0;
//		obj._y = 0;
//
//		obj._state = my_enums::None;
//
//		for (int i = 0; i < obj._size; i++)
//		{
//			if (obj._blocks != nullptr && obj._blocks[i] != nullptr)
//				delete obj._blocks[i];
//		}
//		delete[]obj._blocks;
//
//		obj._size = 0;
//	}
//	return *this;
//}
//
//Figure_T1 & Figure_T1::operator=(const Figure_T1 & obj)
//{
//	if (this != &obj)
//	{
//
//		this->_x = obj._x;
//		this->_y = obj._y;
//
//		this->_state = obj._state;
//		this->_size = obj._size;
//
//		for (int i = 0; i < this->_size; i++)
//		{
//			if (_blocks != nullptr && _blocks[i] != nullptr)
//				delete _blocks[i];
//		}
//		delete[]_blocks;
//
//		_blocks = new Block*[_size];
//
//		for (int i = 0; i < _size; i++)
//		{
//			_blocks[i] = obj._blocks[i];
//		}
//
//
//	}
//	return *this;
//}

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



