
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
	for (int i = 0; i < obj._size; i++)
	{
		if (obj._blocks != nullptr && obj._blocks[i] != nullptr)
			delete obj._blocks[i];
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
			
			_blocks[i] = new Block(*obj._blocks[i]);
		}

		obj._state_rotate = my_enums::NONE;
		obj._x = 0;
		obj._y = 0;
		obj._state_block= my_enums::NoneT;
		obj._state = my_enums::None;

		for (int i = 0; i < obj._size; i++)
		{
			if (obj._blocks != nullptr && obj._blocks[i] != nullptr)
				delete obj._blocks[i];
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

Figure_Parent::Figure_Parent(const int x, const int y, const int size, Block ** blocks)
{
	 _x = x;
	 _y = y;
	 _blocks = blocks;
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
	if (i > 0 && _size > 0)
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

my_enums::Block Figure_Parent::Get_state_block()
{
	return _state_block;
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
	

	_x += x;
	_y += y;
}
void Figure_Parent::Move_to(int x, int y)
{

}
void Figure_Parent::Rotate()
{
	
		switch (_state_rotate)
		{
		case my_enums::DOWN:

			_state_rotate = my_enums::Right;

			_blocks[0]->Set_X(0);
			_blocks[0]->Set_Y(1);

			_blocks[1]->Set_X(1);
			_blocks[1]->Set_Y(1);

			_blocks[2]->Set_X(2);
			_blocks[2]->Set_Y(1);

			_blocks[3]->Set_X(2);
			_blocks[3]->Set_Y(0);


			break;

		case my_enums::Right:

			_state_rotate = my_enums::UP;

			_blocks[0]->Set_X(0);
			_blocks[0]->Set_Y(0);

			_blocks[1]->Set_X(1);
			_blocks[1]->Set_Y(0);

			_blocks[2]->Set_X(1);
			_blocks[2]->Set_Y(1);

			_blocks[3]->Set_X(1);
			_blocks[3]->Set_Y(2);


			break;


		case my_enums::UP:

			_state_rotate = my_enums::Left;

			_blocks[0]->Set_X(0);
			_blocks[0]->Set_Y(1);

			_blocks[1]->Set_X(0);
			_blocks[1]->Set_Y(0);

			_blocks[2]->Set_X(1);
			_blocks[2]->Set_Y(0);

			_blocks[3]->Set_X(2);
			_blocks[3]->Set_Y(0);


			break;
			
		case my_enums::Left:

			_state_rotate = my_enums::DOWN;

			_blocks[0]->Set_X(0);
			_blocks[0]->Set_Y(0);

			_blocks[1]->Set_X(0);
			_blocks[1]->Set_Y(1);

			_blocks[2]->Set_X(0);
			_blocks[2]->Set_Y(2);

			_blocks[3]->Set_X(1);
			_blocks[3]->Set_Y(2);


			break;
		default:
			break;
		}
	
}
#pragma endregion









