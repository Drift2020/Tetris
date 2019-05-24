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

	for (int y1 = 0; y1 < this->_count_figures; y1++)
	{
		for (int x = 0; x < this->_parent[y1]->Get_size(); x++)
		{
			if(_parent[y1] != _my_figure)
			SetChar(_parent[y1]->Get_block(x)->Get_X()+ _parent[y1]->Get_X(),
				_parent[y1]->Get_block(x)->Get_Y() + _parent[y1]->Get_Y(),
				static_cast<wchar_t>(_parent[y1]->Get_block(x)->Get_symbol()));
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

#pragma region Create and end
//изменить рандом
Figure_Parent & Game::Create_figure(int x, int y)
{
	int random_number = 0 + rand() % _size_creators;



	return *_creators[0]->FactoryMethod(x,y);
}

bool Game::is_create(int x, int y)
{


	return true;
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

			SetChar(static_cast<short>(_old_my_figure->Get_block(i)->Get_X() + _old_my_figure->Get_X())
				, static_cast<short>(_old_my_figure->Get_block(i)->Get_Y() + _old_my_figure->Get_Y())
				, static_cast<wchar_t>('.'));

		
		}



	for (int i = 0; i < _my_figure->Get_size(); i++)
	{
		SetChar(static_cast<short>(_my_figure->Get_block(i)->Get_X() + _my_figure->Get_X()),
			static_cast<short>(_my_figure->Get_block(i)->Get_Y() + _my_figure->Get_Y()), _my_figure->Get_block(i)->Get_symbol());
	}
	//после должно быть падение фигуры
}

void Game::End_game()
{
	for (int y = 0; y < this->_count_figures; y++)
	{
		for (int x = 0; x < this->_parent[y]->Get_size(); x++)
		{
			for (int x1 = 0; x1 < this->_my_figure->Get_size(); x1++)
			{
				if ((_parent[y]->Get_state() == my_enums::Down || _parent[y]->Get_state() == my_enums::DownSys) &&
					(
					(_my_figure->Get_block(x1)->Get_X()+ _my_figure->Get_X()==_parent[y]->Get_X()+ _parent[y]->Get_block(x)->Get_X()&&
					_my_figure->Get_block(x1)->Get_Y() + _my_figure->Get_Y() == _parent[y]->Get_Y() + _parent[y]->Get_block(x)->Get_Y()&&
						_my_figure!= _parent[y])
						|| 
						_my_figure->Get_block(x1)->Get_X() + _my_figure->Get_X() == _parent[y]->Get_X() + _parent[y]->Get_block(x)->Get_X() &&
						_my_figure->Get_block(x1)->Get_Y() + _my_figure->Get_Y() +1== _parent[y]->Get_Y() + _parent[y]->Get_block(x)->Get_Y()&&
						_my_figure != _parent[y]
						) && _my_figure->Get_Y()==1
					)
				{
					_is_game = false;
					return;
				}
			}
		}

	}
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
			Print_field();
			Print_my_figure_in_field();
			time_my_figure = false;
		}
	}
}
void Game::Stop_block()
{
	if (_my_figure == nullptr)
		return;

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
void Game::Stop_block(Figure_Parent *& _my_figure)
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
			
			return;
		}
	}

	for (int y = 0; y < this->_count_figures; y++)
	{
		for (int x = 0; x < this->_parent[y]->Get_size(); x++)
		{
			for (int x2 = 0; x2 < _my_figure->Get_size(); x2++)
			{

				if (_parent[y] != _my_figure &&
					_parent[y]->Get_block(x)->Get_Y() + _parent[y]->Get_Y() == _my_figure->Get_block(x2)->Get_Y() + _my_figure->Get_Y() + 1 &&
					_parent[y]->Get_block(x)->Get_X() + _parent[y]->Get_X() + 1 == _my_figure->Get_block(x2)->Get_X() + _my_figure->Get_X() + 1)
				{

					_my_figure->Set_state(my_enums::Stop);
					for (int i = 0; i < _my_figure->Get_size(); i++)
					{
						_my_figure->Get_block(i)->Set_move(my_enums::Stop);
					}
					
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
bool Game::is_move(int x, int y)
{
	if (_my_figure == nullptr)
		return false;
	for (int x1 = 0; x1 < _my_figure->Get_size(); x1++)
	{
		if (_my_field->Get_symbol(COORD() = { static_cast<short>(_my_figure->Get_block(x1)->Get_X()+ x+ _my_figure->Get_X()),
											  static_cast<short>(_my_figure->Get_block(x1)->Get_Y() + y + _my_figure->Get_Y()) }) == '#'||
			_my_field->Get_symbol(COORD() = { static_cast<short>(_my_figure->Get_block(x1)->Get_X() + x + _my_figure->Get_X()),//из-за локальных coord +2
											  static_cast<short>(_my_figure->Get_block(x1)->Get_Y() + y + _my_figure->Get_Y()) }) == '#'
			)
		{
			return false;
		}
	}

	for (int y = 0; y < this->_count_figures; y++)
	{
		for (int x = 0; x < this->_parent[y]->Get_size(); x++)
		{
			for (int x2 = 0; x2 < _my_figure->Get_size(); x2++)
			{

				if (_parent[y] != _my_figure &&
					_parent[y]->Get_block(x)->Get_Y() + _parent[y]->Get_Y() +1 == _my_figure->Get_block(x2)->Get_Y() + _my_figure->Get_Y()+1  &&
					_parent[y]->Get_block(x)->Get_X() + _parent[y]->Get_X()  == _my_figure->Get_block(x2)->Get_X() + _my_figure->Get_X() + 1 ||
				(_parent[y] != _my_figure &&
					_parent[y]->Get_block(x)->Get_Y() + _parent[y]->Get_Y() + 1 == _my_figure->Get_block(x2)->Get_Y() + _my_figure->Get_Y() + 1 &&
					_parent[y]->Get_block(x)->Get_X() + _parent[y]->Get_X() == _my_figure->Get_block(x2)->Get_X() + _my_figure->Get_X() -1))
				{

					return false;
				}
			}
		}
	}


	return true;
}

#pragma endregion


#pragma region scorre

void Game::Check_lines()
{
	bool is_check = true;
	for (int y = 1; y < _my_field->Get_cF_end().Y-1 ; y++)
	{
		is_check = true;
		for (int x = 1; x < _my_field->Get_cF_end().X - 1; x++)
		{
		
			bool is_check2 = false;
			for (int y1 = 0; y1 < this->_count_figures; y1++)
			{
				for (int x1 = 0; x1 < this->_parent[y1]->Get_size(); x1++)
				{
					if (_parent[y1]->Get_block(x1)->Get_Y() + _parent[y1]->Get_Y() == y && 
						_parent[y1]->Get_block(x1)->Get_X() + _parent[y1]->Get_X() == x)
					{
						is_check2 = true;
					}
				}

			}
			if (!is_check2)
			{
				is_check = false;
				break;
			}
			
		}

		//delete line

		if (is_check)
		{
			Delete_line(y);
			Update_status_my_blocs(y);
			Down_block();
			this->_my_field->Reset_symbol();
		}
	}

}

void Game::Delete_line(int y)
{
	

		for (int y1 = 0; y1 < this->_count_figures; y1++)
		{
			for (int x = 0; x < this->_parent[y1]->Get_size(); x++)
			{
				if (_parent[y1]->Get_block(x)->Get_Y() + _parent[y1]->Get_Y() == y)
				{				
					_parent[y1]->Remove_block(x);
					x--;
				}
			}
		}

	_scorre += 100;
}

void Game::Update_status_my_blocs(int y)
{
	for (int y1 = 0; y1 < this->_count_figures; y1++)
	{
		for (int x = 0; x < this->_parent[y1]->Get_size(); x++)
		{
			if (_parent[y1]->Get_block(x)->Get_Y() + _parent[y1]->Get_Y() < y)
			{
				_parent[y1]->Get_block(x)->Set_move(my_enums::DownSys);
			}
		}
	}
}

void Game::Down_block()
{
	bool _is_work = true;
	while(_is_work)
	for (int y1 = 0; y1 < this->_count_figures; y1++)
	{
		_is_work = false;
		for (int x = 0; x < this->_parent[y1]->Get_size(); x++)
		{
		
			if (_parent[y1]->Get_block(x)->Get_move() == my_enums::DownSys)
			{
				Stop_block(_parent[y1]);
				if (_parent[y1]->Get_block(x)->Get_move() == my_enums::DownSys)
				{
					_is_work = true;
					_parent[y1]->Move_on(0, 1);
				}
				
			}
		}
	}
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
		if(is_move(1, 0))
			move_my_figure_mine(1, 0);
		
	}
	else if (btnCode == 75)
	{
		if (is_move(-1, 0))
			move_my_figure_mine(-1, 0);
	}

	

	
}

void Game::UpdateF(float deltaTime)
{
	
	
		

	Print_scorre();
	_my_field->Set_scorre(_scorre,2);

	if (_my_figure == nullptr)
	{
		Check_lines();
		if (is_create(7, 1))
		{			
			Figure_Parent * temp = new Figure_Parent(Create_figure(7, 1));
			Add_figure(temp);
		}
		End_game();
	}

	
	_my_field->Set_preview(_my_figure->Get_state_block());
	Print_preview();


	Stop_block();

	Move_my_figure();

	speed = normal;
	
}
