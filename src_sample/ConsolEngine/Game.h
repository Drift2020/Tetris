// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#pragma once
#include <chrono>
#include <ctime>
#include "BaseApp.h"
#include "Field.h"
#include "Creator.h"
#include "Figure_Parent.h"
//класс игры
class Game : public BaseApp
{
	typedef BaseApp Parent;

	

protected:
		int _scorre;
		int _size_creators;
		int _count_figures;
		Field * _my_field;
		Creator ** _creators;
		Figure_Parent ** _parent;

		Figure_Parent * _my_figure;
		Figure_Parent * _old_my_figure;

		std::chrono::system_clock::time_point start_time_figure;
		std::chrono::system_clock::time_point end_time_figure;
		bool time_my_figure;
#pragma region print

		void Print_field();
		void Print_scorre();
		void Print_preview();

#pragma endregion

#pragma region Create
		Figure_Parent *Create_figure(int x, int y);
		bool is_create(int x, int y);
		void Add_figure(Figure_Parent * b);

		void End_game();
		void Print_my_figure_in_field();
#pragma endregion

	


#pragma region Move

		void Move_my_figure();

		void Stop_block();
		void Stop_block(Figure_Parent *& _my_figure);

		void move_my_figure_mine(int x, int y);

		bool is_move(int x, int y);
#pragma endregion


#pragma region scorre


		void Check_lines();

		void Delete_line(int y);

		void Update_status_my_blocs(int y);

		void Down_block();

#pragma endregion

		

	public:
		Game();
		virtual void KeyPressed(int btnCode);//нажатие клавиши
		virtual void UpdateF(float deltaTime);//обновление в секундах
};
