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

	_parent[0] = new Figure_Parent(Create_figure(7,1));

	_scorre = 0;
	_my_figure = _parent[0];
	_old_my_figure = nullptr;
	
	time_my_figure = false;
}

#pragma region Create
//изменить рандом
Figure_Parent & Game::Create_figure(int x, int y)
{
	int random_number = 0 + rand() % _size_creators;
	return *_creators[0]->FactoryMethod(x,y);
}

void Game::Add_figure(Figure_Parent * b)
{
	Figure_Parent** temp = new Figure_Parent*[_count_figures + 1];

	for (int i = 0; i < _count_figures; i++)
	{

		temp[i] = new Figure_Parent(*_parent[i]);
	}
	temp[_count_figures] = new Figure_Parent(*b);



	for (int i = 0; i < _count_figures; i++)
	{
		delete _parent[i];
	}
	delete[] _parent;

	_count_figures++;
	_parent = new Figure_Parent*[_count_figures];


	for (int i = 0; i < _count_figures; i++)
	{

		_parent[i] = new Figure_Parent(*temp[i]);
	}
	_my_figure = _parent[_count_figures - 1];

}

void Game::Print_my_figure_in_field()
{
	if (_old_my_figure != nullptr)
		for (int i = 0; i < _old_my_figure->Get_size(); i++)
		{
			_my_field->Set_symbol(COORD() = { static_cast<short>(_old_my_figure->Get_block(i)->Get_X() + _old_my_figure->Get_X()),
				static_cast<short>(_old_my_figure->Get_block(i)->Get_Y() + _old_my_figure->Get_Y()) }, '.');
		}



	for (int i = 0; i < _my_figure->Get_size(); i++)
	{
		_my_field->Set_symbol(COORD() = { static_cast<short>(_my_figure->Get_block(i)->Get_X() + _my_figure->Get_X()),
			static_cast<short>(_my_figure->Get_block(i)->Get_Y() + _my_figure->Get_Y()) }, _my_figure->Get_block(i)->Get_symbol());
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
			delete _old_my_figure;
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
		//плюс 1 так как локальные y начинается с нуля
		if (this->_my_field->Get_cF_end().Y - 1 == (_my_figure->Get_block(i)->Get_Y() + _my_figure->Get_Y()) + 1)
		{
			_my_figure->Set_state(my_enums::Stop);
			for (int i = 0; i < _my_figure->Get_size(); i++)
			{
				_my_figure->Get_block(i)->Set_move(my_enums::Stop);
			}
			_my_figure = nullptr;
			return;
		}
	}

	for (int y = 0; y < this->_count_figures; y++)
	{
		for (int x= 0; x < this->_parent[y]->Get_size(); x++)
		{
			for (int x2 = 0; x2 < _my_figure->Get_size(); x2++)
			{
				int n1 = _parent[y]->Get_block(x)->Get_Y() + _parent[y]->Get_Y() + 1;
				int n2 = _my_figure->Get_block(x2)->Get_Y() + _my_figure->Get_Y() + 1;
				int n3 = _parent[y]->Get_block(x)->Get_X() + _parent[y]->Get_X() + 1;
				int n4 = _my_figure->Get_block(x2)->Get_X() + _my_figure->Get_X() + 1;
				if (_parent[y]!=_my_figure &&
					_parent[y]->Get_block(x)->Get_Y() + _parent[y]->Get_Y()== _my_figure->Get_block(x2)->Get_Y()+ _my_figure->Get_Y()+1&&
					_parent[y]->Get_block(x)->Get_X() + _parent[y]->Get_X() + 1 == _my_figure->Get_block(x2)->Get_X() + _my_figure->Get_X()+1)
				{

					_my_figure->Set_state(my_enums::Stop);
					for (int i = 0; i < _my_figure->Get_size(); i++)
					{
						_my_figure->Get_block(i)->Set_move(my_enums::Stop);
					}
					_my_figure = nullptr;
					return;
				}
			}
		}
	}
}

void Game::move_my_figure_mine(int x,int y)
{
	delete _old_my_figure;
	_old_my_figure = new Figure_Parent(*_my_figure);
	_my_figure->Move_on(x, y);
	Print_my_figure_in_field();
}
#pragma endregion


void Game::KeyPressed(int btnCode)//передвижение объекта
{
	if (btnCode == 80) 
		speed = run;
	else  
		speed = normal;

	if (btnCode == 32)
	{
		delete _old_my_figure;
		_old_my_figure = new Figure_Parent(*_my_figure);
		_my_figure->Rotate();
		Print_my_figure_in_field();

	}
	else if (btnCode == 77)
	{
		move_my_figure_mine(1, 0);
		
	}
	else if (btnCode == 75)
	{
		move_my_figure_mine(-1, 0);
	}

	

	
}

void Game::UpdateF(float deltaTime)
{
	
	Print_field();
		

	Print_scorre();
	_my_field->Set_scorre(_scorre,2);

	if (_my_figure == nullptr)
	{
		Figure_Parent * temp = new Figure_Parent(Create_figure(7,1));
		Add_figure(temp);
	
	}

	
	_my_field->Set_preview(_my_figure->Get_state_block());
	Print_preview();


	Stop_block();

	Move_my_figure();

	speed = normal;
	
}
