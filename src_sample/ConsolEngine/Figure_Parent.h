#pragma once
#include "Block.h"
#include "Enums.h"
#include <list>
class  Figure_Parent
{
	//главная фигура
protected:
	//кординаты это верхний левцй угол
	int _x;
	int _y;
	
	my_enums::Move _state;
	my_enums::Rotate _state_rotate;
	Block** _blocks;
	
	int _size;

public:
#pragma region system
	Figure_Parent();
	Figure_Parent(const int x, const int y, const int size, Block ** blocks);
	Figure_Parent(int x, int y);

	Figure_Parent(const Figure_Parent& obj);// Конструктор копирования------------------

	Figure_Parent(Figure_Parent && obj);//кoнструктор переноса-----------------------------------

	Figure_Parent  &operator =(Figure_Parent  && obj);//Присв с переносом --------------------------

	Figure_Parent  &operator =(const Figure_Parent  & obj);//Присв с копированием --------------------------

	virtual ~Figure_Parent();

#pragma endregion

	
#pragma region block

	void virtual Remove_block(int i);
	void virtual Add_block(Block * block);
#pragma endregion


#pragma region get
	Block virtual *Get_block(int i);
	int virtual Get_X();
	int virtual Get_Y();
	int virtual Get_size();
	my_enums::Move virtual Get_state();
#pragma endregion

	
#pragma region set

	void virtual Set_X(int x);
	void virtual Set_Y(int y);
	void virtual Set_size(int s);
	void virtual Set_state(my_enums::Move _state);
#pragma endregion


#pragma region figure
	void  Move_on(int x, int y);
	void  Move_to(int x, int y);
	void  Rotate();
#pragma endregion

	
};

