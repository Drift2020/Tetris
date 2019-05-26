
#include "Figure_Parent.h"
#include <algorithm>


#pragma region  system
Figure_Parent::Figure_Parent()
{
	 this->_x=0;
	 this->_y=0;
	 this->_size = 0;
	 this->_blocks = nullptr;
	 this->_state = my_enums::Down;
	 this->_state_rotate = my_enums::DOWN;
	
}


Figure_Parent::Figure_Parent(int x,int y)
{
	this->_x = x;
	this->_y = y;
	this->_size = 0;
	this->_state = my_enums::Down;
	this->_blocks = nullptr;
	this->_state_rotate = my_enums::DOWN;
}

 Figure_Parent::Figure_Parent(const Figure_Parent & obj)
{
	this->_x = obj._x;
	this->_y = obj._y;
	this->_state_block = obj._state_block;
	this->_state = obj._state;
	this->_size = obj._size;
	this->_state_rotate = obj._state_rotate;
	_blocks = new Block*[_size];

	for (int i = 0; i < _size; i++)
	{
		
		_blocks[i] = new Block(*obj._blocks[i]);
	}

	
}

Figure_Parent::Figure_Parent(Figure_Parent && obj)
{
	this->_x = obj._x;
	this->_y = obj._y;
	this->_state_block = obj._state_block;
	this->_state = obj._state;
	this->_size = obj._size;
	this->_state_rotate = obj._state_rotate;
	_blocks = new Block*[_size];

	for (int i = 0; i < _size; i++)
	{
	
		_blocks[i]= new Block(*obj._blocks[i]);
	}


	obj._x=0;
	obj._y=0;
	obj._state_rotate = my_enums::NONE;
	obj._state= my_enums::None;
	obj._state_block=my_enums::NoneT;
	//for (int i = 0; i < obj._size; i++)
	//{
	//	if (obj._blocks != nullptr && obj._blocks[i] != nullptr)
	//		delete obj._blocks[i];
	//}
	//delete[]obj._blocks;

	for (int i = 0; i < obj._size; i++)
	{

		obj._blocks[i] = nullptr;
	}
	delete[]obj._blocks;

	obj._size=0;
}

Figure_Parent & Figure_Parent::operator=(Figure_Parent && obj)
{
	if (this != &obj)
	{

		this->_x = obj._x;
		this->_y = obj._y;
		this->_state_block = obj._state_block;
		this->_state = obj._state;
		this->_size = obj._size;
		this->_state_rotate = obj._state_rotate;

		_blocks = new Block*[_size];

		for (int i = 0; i < _size; i++)
		{

			_blocks[i] = obj._blocks[i];
		}

		obj._state_rotate = my_enums::NONE;
		obj._x = 0;
		obj._y = 0;
		obj._state_block = my_enums::NoneT;
		obj._state = my_enums::None;

		for (int i = 0; i < obj._size; i++)
		{
			
				 obj._blocks[i] =nullptr;
		}
		delete[]obj._blocks;

		obj._size = 0;
	}
	return *this;
}

Figure_Parent & Figure_Parent::operator=(const Figure_Parent & obj)
{


	if (this != &obj)
	{

		this->_x = obj._x;
		this->_y = obj._y;
		this->_state_block = obj._state_block;
		this->_state = obj._state;
		this->_size = obj._size;
		this->_state_rotate = obj._state_rotate;
	
		
		_blocks = new Block*[_size];

		for (int i = 0; i < _size; i++)
		{
			
			_blocks[i] = new Block(*obj._blocks[i]);
		}


	}
	return *this;
}



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
	if (i >= 0 && _size > 0)
	{

		Block** temp = new Block*[_size - 1];

		for (int i1 = 0,i2=0; i1 < _size; i1++)
		{
			if (i1 != i)
			{
				temp[i2] = new Block(*_blocks[i1]);
				i2++;
			}
			
		}


		for (int i = 0; i < _size; i++)
		{
			delete _blocks[i];
		}
		delete[]_blocks;
		_size--;

		_blocks = new Block*[_size];

		for (int i = 0; i < _size; i++)
		{
			_blocks[i] = new Block(*temp[i]);
		}
		

	}
}
#pragma endregion







