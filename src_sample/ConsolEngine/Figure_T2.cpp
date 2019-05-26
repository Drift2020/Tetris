#include "Figure_T2.h"
#include <algorithm>


#pragma region  system




Figure_T2::Figure_T2() : Figure_Parent()
{
	_size = 4;
	this->_state_block = my_enums::T2;
	_blocks = new Block*[_size];


	_blocks[0] = new  Block(1, 0, '&', my_enums::Down);;

	_blocks[1] = new  Block(1, 1, '&', my_enums::Down);

	_blocks[2] = new  Block(1, 2, '&', my_enums::Down);

	_blocks[3] = new Block(0, 2, '&', my_enums::Down);
	_state = my_enums::Down;
}

Figure_T2::Figure_T2(const Figure_T2 & obj) :Figure_Parent(obj)
{
}

Figure_T2::Figure_T2(Figure_T2 && obj)
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


	obj._x = 0;
	obj._y = 0;
	obj._state_rotate = my_enums::NONE;
	obj._state = my_enums::None;
	obj._state_block = my_enums::NoneT;


	for (int i = 0; i < obj._size; i++)
	{

		obj._blocks[i] = nullptr;
	}
	delete[]obj._blocks;
	/*for (int i = 0; i < obj._size; i++)
	{
		if (obj._blocks != nullptr && obj._blocks[i] != nullptr)
			delete obj._blocks[i];
	}
	delete[]obj._blocks;*/

	obj._size = 0;
}

Figure_T2 & Figure_T2::operator=(Figure_T2 && obj)
{
	if (this != &obj)
	{
		Figure_Parent::operator= (obj);

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

			obj._blocks[i] = nullptr;
		}
		delete[]obj._blocks;
		/*for (int i = 0; i < obj._size; i++)
		{
			if (obj._blocks != nullptr && obj._blocks[i] != nullptr)
				delete obj._blocks[i];
		}
		delete[]obj._blocks;*/

		obj._size = 0;
	}
	return *this;
}

Figure_T2 & Figure_T2::operator=(const Figure_T2 & obj)
{
	if (this != &obj)
	{
		Figure_Parent::operator= (obj);
		/*	this->_x = obj._x;
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
	*/

	}
	return *this;
}

Figure_T2::Figure_T2(int x, int y) : Figure_Parent(x, y)
{
	_size = 4;
	this->_state_block = my_enums::T2;
	_blocks = new Block *[_size];


	_blocks[0] = new  Block(0, 0, '&', my_enums::Stop);

	_blocks[1] = new  Block(0, 1, '&', my_enums::Stop);

	_blocks[2] = new  Block(0, 2, '&', my_enums::Stop);

	_blocks[3] = new Block(1, 2, '&', my_enums::Stop);

}


Figure_T2::~Figure_T2()
{

}






#pragma endregion

#pragma region Block

void Figure_T2::Remove_block(int i)
{
	if (i >= 0 && _size > 0)
	{

		Block** temp = new Block*[_size - 1];

		for (int i1 = 0, i2 = 0; i1 < _size; i1++)
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

void Figure_T2::Add_block(Block * block)
{

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
my_enums::Rotate Figure_T2::Get_state_rotate()
{
	return this->_state_rotate;
}
my_enums::Move Figure_T2::Get_state()
{
	return _state;
}
#pragma endregion


#pragma region set

void Figure_T2::Set_X(int x)
{
	this->_x = x;
}
void Figure_T2::Set_Y(int y)
{
	this->_y = y;
}

void  Figure_T2::Set_size(int s)
{
	this->_size = s;
}
void Figure_T2::Set_state(my_enums::Move _state)
{
	this->_state = _state;
}
void Figure_T2::Set_state_block(my_enums::Block _state)
{
	this->_state_block = _state;
}
void Figure_T2::Set_state_rotate(my_enums::Rotate _state)
{
	this->_state_rotate = _state;
}
#pragma endregion


#pragma region figure
void Figure_T2::Rotate()
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


void Figure_T2::Move_on(int x, int y)
{
	_x += x;
	_y += y;
}
void Figure_T2::Move_to(int x, int y)
{

}
#pragma endregion

