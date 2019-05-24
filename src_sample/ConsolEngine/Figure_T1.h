#pragma once
#include "Figure_Parent.h"
class Figure_T1 :
	public Figure_Parent
{
public:

	Figure_T1(int x, int y);
	Figure_T1();
	 ~Figure_T1() override;

	 void  Remove_block(int i) override;

	 Block  * Get_block (int i) override;
	 int  Get_X() override;
	 int  Get_Y() override;
	 int  Get_size() override;
	 my_enums::Block  Get_state_block() override;

	 void  Add_block( Block * block) override;
	 void  Set_X(int x) override;
	 void  Set_Y(int y) override;
	 void  Set_size(int s) override;
	 void  Rotate() override;

};

