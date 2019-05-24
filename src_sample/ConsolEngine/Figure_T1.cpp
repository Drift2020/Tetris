#include "Figure_T1.h"
#include <algorithm>


#pragma region  system




Figure_T1::Figure_T1() : Figure_Parent()
{
	_size = 4;
	this->_state_block = my_enums::T1;
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
	this->_state_block = my_enums::T1;
	_blocks = new Block *[_size];


	_blocks[0] = new  Block(0, 0, '&', my_enums::Stop);

	_blocks[1] = new  Block(0, 1, '&', my_enums::Stop);
	
	_blocks[2] = new  Block(0, 2, '&', my_enums::Stop);
	
	_blocks[3] = new Block(1, 2, '&', my_enums::Stop);

}


Figure_T1::~Figure_T1()
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
my_enums::Block Figure_T1::Get_state_block()
{
	return _state_block;
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


void Figure_T1::Rotate()
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
