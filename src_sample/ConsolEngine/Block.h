#pragma 
#include "Enums.h"
//Базовый класс для хранения блоков

class Block
{
protected:
	int _x;
	int _y;
	char _symbol;
	my_enums::Move _move;
public:
	Block();
	Block(int x, int y, char _symbol, my_enums::Move m);

	Block(const Block& obj) {
		this->_x = obj._x;
		this->_y = obj._y;
		this->_symbol = obj._symbol;
		this->_move = obj._move;
	}// Конструктор копирования------------------

	Block(Block && obj) {
		this->_x = obj._x;
		this->_y = obj._y;
		this->_symbol = obj._symbol;
		this->_move = obj._move;

		obj._x = 0;
		obj._y = 0;
		obj._symbol = '\0';
		obj._move = my_enums::None;
	}//констр переноса-----------------------

	Block &operator =(Block  && obj);//Присв с переносом --------------------------

	Block &operator =(const Block  & obj);//Присв с копированием --------------------------

	~Block();




	char Get_symbol();
	int Get_X();
	int Get_Y();
	my_enums::Move Get_move();

	void Set_symbol(char  symbol);
	void Set_X(int x);
	void Set_Y(int y);
	void Set_move(my_enums::Move m);

	void Add_y(int y);
	void Add_x(int x);

	void Move_on(int x, int y);
	void Move_to(int x, int y);


};

