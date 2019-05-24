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
	my_enums::Block _state_block;
	Block** _blocks;
	
	int _size;

public:
#pragma region system
	Figure_Parent();
	Figure_Parent(int x, int y);
	Figure_Parent(const Figure_Parent& obj);// Конструктор копирования------------------
	Figure_Parent(Figure_Parent && obj);//кoнструктор переноса-----------------------------------


	 Figure_Parent  &operator =(Figure_Parent  && obj);//Присв с переносом --------------------------
	 Figure_Parent  &operator =(const Figure_Parent  & obj);//Присв с копированием --------------------------
	 ~Figure_Parent();

#pragma endregion

	
#pragma region block

	virtual	void  Remove_block(int i)=0;
	
	virtual void  Add_block(Block * block)=0;
#pragma endregion


#pragma region get
	virtual Block *Get_block(int i)=0;
	virtual int  Get_X()=0;
	virtual int  Get_Y()=0;
	virtual int  Get_size()=0;
	virtual my_enums::Move  Get_state()=0;
	virtual my_enums::Block  Get_state_block()=0;
	virtual my_enums::Rotate Get_state_rotate() = 0;
#pragma endregion

	
#pragma region set

	virtual	void  Set_X(int x)=0;
	virtual void  Set_Y(int y) = 0;
	virtual void  Set_size(int s) = 0;
	virtual void  Set_state(my_enums::Move _state) = 0;
	virtual void  Set_state_block(my_enums::Block _state) = 0;
	virtual void  Set_state_rotate(my_enums::Rotate _state) = 0;

#pragma endregion


#pragma region figure
	virtual void  Move_on(int x, int y) = 0;
	virtual void  Move_to(int x, int y) = 0;
	virtual void   Rotate() = 0;
#pragma endregion

	
};

