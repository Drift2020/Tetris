// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#pragma once
#include <chrono>
#include <ctime>
#include "BaseApp.h"
#include "Field.h"
#include "Creator.h"
#include "Figure_Parent.h"
//����� ����
class Game : public BaseApp
{
	typedef BaseApp Parent;

	

	private:
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
		Figure_Parent &Create_figure(int x, int y);
		void Add_figure(Figure_Parent * b);

		void Print_my_figure_in_field();
#pragma endregion

	



#pragma region Move

		void Move_my_figure();

		void Stop_block();

#pragma endregion


#pragma region Get



#pragma endregion

		

	public:
		Game();
		virtual void KeyPressed(int btnCode);//������� �������
		virtual void UpdateF(float deltaTime);//���������� � ��������
};
