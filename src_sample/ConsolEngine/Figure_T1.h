#pragma once
#include "Figure_Parent.h"
class Figure_T1 :
	public Figure_Parent
{
public:
	Figure_T1(const int x, const int y,const int size, Block** blocks);
	Figure_T1();
	 ~Figure_T1() override;

	 void  Remove_block(int i) override;

	 Block  Get_block(int i) override;
	 int  Get_X() override;
	 int  Get_Y() override;
	 int  Get_size() override;

	 void  Add_block( Block * block) override;
	 void  Set_X(int x) override;
	 void  Set_Y(int y) override;
	 void  Set_size(int s) override;


	 void  Move_on(int x, int y) override;
	 void  Move_to(int x, int y) override;
	 void  Rotate(my_enums::Rotate r) override;
};
