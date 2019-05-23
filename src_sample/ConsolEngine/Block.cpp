#include "Block.h"


#pragma region System
Block::Block()
{
	_x = 0;
	_y = 0;
	_symbol = ' ';
    _move = my_enums::Stop;
}

Block::Block(int x, int y, char  symbol, my_enums::Move m)
{
	_x = x;
	_y = y;
	_symbol = symbol;
	_move = m;
}


Block & Block::operator=(const Block & obj)
{
	if (this != &obj)
	{
		this->_x = obj._x;
		this->_y = obj._y;
		this->_symbol = obj._symbol;
		this->_move = obj._move;
	}
	return *this;
}

Block & Block::operator=(Block && obj)
{
	if (this != &obj)
	{
		this->_x = obj._x;
		this->_y = obj._y;
		this->_symbol = obj._symbol;
		this->_move = obj._move;

		obj._x = 0;
		obj._y = 0;
		obj._symbol = '\0';
		obj._move = my_enums::None;
	}
	return *this;
}

Block::~Block()
{
	_x = 0;
	_y = 0;
	_symbol = ' ';
}
#pragma endregion



#pragma region Get
char Block::Get_symbol()
{
	return _symbol;
}
int Block::Get_X()
{
	return _x;
}
int Block::Get_Y()
{
	return _y;
}

my_enums::Move  Block::Get_move()
{
	return _move;
}
#pragma endregion


#pragma region Set
void Block::Set_symbol(char  symbol)
{
	_symbol = symbol;
}
void Block::Set_X(int x)
{
	_x = x;
}
void Block::Set_Y(int y)
{
	_y = y;
}

void Block::Set_move(my_enums::Move m)
{
	_move = m;
}
void Block::Add_y(int y)
{
	_y += y;
}
void Block::Add_x(int x)
{
	_x += x;
}
#pragma endregion


#pragma region Moves
void Block::Move_on(int x, int y)
{
	_x += x;
	_y += y;
}

void Block::Move_to(int x, int y)
{
	_x = x;
	_y = y;
}

#pragma endregion

