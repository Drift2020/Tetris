#pragma once
#include "Block.h"
#include "Enums.h"
class  Figure_Parent
{

	int _x;
	int _y;
	Block ** _blocks;

public:
	Figure_Parent();
	Figure_Parent(int x, int y, Block ** blocks);
	~Figure_Parent();

	Block Get_block();
	int Get_X();
	int Get_Y();

	Block Get_block(Block *& block);
	void Set_X(int x);
	void Set_Y(int y);

	void Move_on(int x, int y);
	void Move_to(int x, int y);
	void Rotate(my_enums::Rotate r);
};

