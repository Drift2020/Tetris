// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "Game.h"
#include "Creator.h"
#include "Creator_T1.h"
#include "Figure_Parent.h"
#pragma region Print

void Game::Print_field()
{
	for (int y = 0; y < this->_my_field->Get_cF_end().Y; y++)
	{
		for (int x = 0; x < _my_field->Get_cF_end().X; x++)
		{


			SetChar(x, y, static_cast<wchar_t>(_my_field->Get_symbol(COORD() = { static_cast<short>(x),static_cast<short>(y) })));
		}
	}
}

void Game::Print_scorre()
{

	for (int y = 0; y < this->_my_field->Get_cS_end().Y; y++)
	{
		for (int x = 0; x < _my_field->Get_cS_end().X; x++)
		{


			SetChar(_my_field->Get_cS_start().X + x, _my_field->Get_cS_start().Y + y, static_cast<wchar_t>(_my_field->Get_scorre(COORD() = { static_cast<short>(x),static_cast<short>(y) })));


		}
	}

	
}

void Game::Print_preview()
{
	for (int y = 0; y < this->_my_field->Get_cP_end().Y; y++)
	{
		for (int x = 0; x < _my_field->Get_cP_end().X; x++)
		{


			SetChar(_my_field->Get_cP_start().X + x, _my_field->Get_cP_start().Y + y, static_cast<wchar_t>(_my_field->Get_preview(COORD() = { static_cast<short>(x),static_cast<short>(y) })));
		}
	}
}



#pragma endregion

Game::Game() : Parent(26, 25)
{
	_size_creators = 1;
	_count_figures = 1;
	_my_field = new Field();
	_creators = new Creator*[_size_creators];

	_creators[0] = new  Creator_T1();


	_parent = new Figure_Parent*[_count_figures];

	_parent[0] = Create_figure();
	_scorre = 0;
	_my_figure = _parent[0];
	_old_my_figure = nullptr;
	
	time_my_figure = false;
}

#pragma region Create
Figure_Parent * Game::Create_figure()
{
	int random_number = 0 + rand() % _size_creators;
	return _creators[random_number]->FactoryMethod();
}

void Game::Add_figure(Figure_Parent * b)
{
	Figure_Parent** temp = new Figure_Parent*[_count_figures + 1];
	
	for (int i = 0; i < _count_figures; i++)
	{
		temp[i] = _parent[i];
	}
	temp[_count_figures + 1] = b;

	for (int i = 0; i < _count_figures; i++)
	{
		delete _parent[i];
	}
	delete[] _parent;

	_count_figures++;
	_parent = new Figure_Parent*[_count_figures];


	for (int i = 0; i < _count_figures; i++)
	{
		_parent[i] = temp[i];
	}
	

}

void Game::Print_my_figure_in_field()
{
	if(_old_my_figure!=nullptr)
	for (int i = 0; i < _old_my_figure->Get_size(); i++)
	{
		_my_field->Set_symbol(COORD() = { static_cast<short>(_old_my_figure->Get_block(i)->Get_X()),static_cast<short>(_old_my_figure->Get_block(i)->Get_Y()) }, '.');
	}

	

	for (int i = 0; i < _my_figure->Get_size(); i++)
	{
		_my_field->Set_symbol(COORD() = { static_cast<short>(_my_figure->Get_block(i)->Get_X()), static_cast<short>(_my_figure->Get_block(i)->Get_Y()) }, _my_figure->Get_block(i)->Get_symbol());
	}
//после должно быть падение фигуры
}

#pragma endregion

#pragma region move
void Game::Move_my_figure()
{
	if (_my_figure != nullptr)
	{
	
		if (!time_my_figure)
		{
			start_time_figure = std::chrono::system_clock::now();
			time_my_figure = true;
		}

		end_time_figure = std::chrono::system_clock::now();

		std::chrono::duration<float> elapsed_seconds = end_time_figure - start_time_figure;
		
		if (elapsed_seconds.count() > speed)
		{
			_old_my_figure = new Figure_Parent(*_my_figure);
		
			_my_figure->Move_on(0, 1);

			Print_my_figure_in_field();
			time_my_figure = false;
		}
	}
}
void Game::Stop_block()
{
	for (int i = 0; i < _my_figure->Get_size(); i++)
	{
		if (this->_my_field->Get_cF_end().Y - 1 == _my_figure->Get_block(i)->Get_Y())
		{
			_my_figure->Set_state(my_enums::Stop);
			for (int i = 0; i < _my_figure->Get_size(); i++)
			{
				_my_figure->Get_block(i)->Set_move(my_enums::Stop);
			}

		}
	}
}
#pragma endregion


void Game::KeyPressed(int btnCode)//передвижение объекта
{
	//if (btnCode == 119) //w
	//	mObj1Y--;
	if (btnCode == 115) //s
		speed = run;
	else  //s
		speed = normal;

	//if (btnCode == 97) //a
	//	mObj1X--;
	//else if (btnCode == 100) //d
	//	mObj1X++;

	//if (mObj1X < 0)
	//	mObj1X = 0;
	//else if (mObj1X >= X_SIZE)
	//	mObj1X = X_SIZE - 1;

	//if (mObj1Y < 0)
	//	mObj1Y = 0;
	//else if (mObj1Y >=Y_SIZE)
	//	mObj1Y = Y_SIZE - 1;
}

void Game::UpdateF(float deltaTime)
{
	
	Print_field();
		
	Print_preview();

	Print_scorre();
	_my_field->Set_scorre(_scorre,2);

	if (_my_figure == nullptr)
	{
		Figure_Parent * temp = Create_figure();
		Add_figure(temp);
		_my_figure = temp;
	}

	Stop_block();

	Move_my_figure();

	speed = normal;
	//SetChar(mObj1XOld, mObj1YOld, L' ');
	//SetChar(mObj1X, mObj1Y, L'O');

	//mObj1XOld = mObj1X;
	//mObj1YOld = mObj1Y;

	////-----------------------------

	//SetChar(mObj2X, mObj2Y, L' ');//Самопроизвольное движение объекта
	//if (mDirection)
	//{
	//	mObj2X++;
	//	if (mObj2X == 40)
	//		mDirection = false;
	//}
	//else
	//{
	//	mObj2X--;
	//	if (mObj2X == 10)
	//		mDirection = true;
	//}
	//SetChar(mObj2X, mObj2Y, L'F');
}
