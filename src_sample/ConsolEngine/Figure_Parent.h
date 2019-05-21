#pragma once
#include "Block.h"
#include "Enums.h"
#include <list>
class  Figure_Parent
{
protected:
	//кординаты это верхний левцй угол
	int _x;
	int _y;
	
	Block** _blocks;
	
	int _size;

public:
	Figure_Parent();
	Figure_Parent(const int x, const int y, const int size, Block ** blocks);
	virtual ~Figure_Parent();
	Figure_Parent(const Figure_Parent& obj); // конструктор копирования
	Figure_Parent& operator=(const Figure_Parent& obj); // оператор присваивания

	void virtual Remove_block(int i);

	Block virtual Get_block(int i);
	int virtual Get_X();
	int virtual Get_Y();
	int virtual Get_size();

	void virtual Add_block(Block * block);
	void virtual Set_X(int x);
	void virtual Set_Y(int y);
	void virtual Set_size(int s);

	void virtual Move_on(int x, int y);
	void virtual Move_to(int x, int y);
	void virtual Rotate(my_enums::Rotate r);
};

