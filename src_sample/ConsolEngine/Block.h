#pragma 
#include "Enums.h"


class Block
{
	int _x;
	int _y;
	char _symbol;
	my_enums::Move _move;
public:
	Block();
	Block(int x, int y, char & _symbol, my_enums::Move m);
	~Block();


	char Get_symbol();
	int Get_X();
	int Get_Y();
	my_enums::Move Get_move();

	void Set_symbol(char & symbol);
	void Set_X(int x);
	void Set_Y(int y);
	void Set_move(my_enums::Move m);

	void Move_on(int x, int y);
	void Move_to(int x, int y);


};

