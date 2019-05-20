#pragma once
#include "Block.h"
#include "Enums.h"
class  Figure_Parent
{
	//кординаты это верхний левцй угол
	int _x;
	int _y;
	Block ** _blocks;
	int _count_block;
public:
	Figure_Parent();
	Figure_Parent(int x, int y, Block ** blocks);
	~Figure_Parent();

	Block Get_block(int i);
	int Get_X();
	int Get_Y();

	void Set_block(Block *& block);
	void Set_X(int x);
	void Set_Y(int y);

	void Move_on(int x, int y);
	void Move_to(int x, int y);
	void Rotate(my_enums::Rotate r);
};

