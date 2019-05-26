#pragma once
#include "Figure_Parent.h"
class Figure_T2 :
	public Figure_Parent
{
public:
#pragma region system
	Figure_T2(int x, int y);
	Figure_T2()
		;
	Figure_T2(const Figure_T2& obj);// Конструктор копирования------------------
	Figure_T2(Figure_T2 && obj);//кoнструктор переноса-----------------------------------
	Figure_T2  &operator =(Figure_T2  && obj);//Присв с переносом --------------------------
	Figure_T2  &operator =(const Figure_T2  & obj);//Присв с копированием --------------------------
	~Figure_T1();
#pragma endregion

#pragma region block
	void  Remove_block(int i) override;
	void  Add_block(Block * block) override;
#pragma endregion

#pragma region get
	Block *Get_block(int i) override;
	int  Get_X() override;
	int  Get_Y() override;
	int  Get_size() override;
	my_enums::Move  Get_state() override;
	my_enums::Block  Get_state_block() override;
	my_enums::Rotate Get_state_rotate() override;
#pragma endregion


#pragma region set
	void  Set_X(int x) override;
	void  Set_Y(int y) override;
	void  Set_size(int s) override;
	void  Set_state(my_enums::Move _state)override;
	void Set_state_block(my_enums::Block _state) override;
	void  Set_state_rotate(my_enums::Rotate _state) override;
#pragma endregion


#pragma region figure
	void  Rotate() override;
	void Move_to(int x, int y)override;
	void Move_on(int x, int y)override;
#pragma endregion
};

