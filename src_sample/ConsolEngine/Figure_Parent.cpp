
#include "Figure_Parent.h"
#include <algorithm>


#pragma region  system
Figure_Parent::Figure_Parent()
{
	 _x=0;
	 _y=0;
	 _size = 0;
	 _blocks = new Block*[];

	
}

Figure_Parent::Figure_Parent(const int x, const int y, const int size, Block ** blocks)
{
	 _x = x;
	 _y = y;
	 _blocks = blocks;
}


Figure_Parent::Figure_Parent(const Figure_Parent& obj) // конструктор копирования
{
	


	
}
Figure_Parent& Figure_Parent::operator=(const Figure_Parent& obj) // оператор присваивания
{
	
}

Figure_Parent::~Figure_Parent()
{
	for (int i=0;i< this->_size;i++)
	{
		 delete _blocks[i];
	}
	delete[]  _blocks;
}

//void Figure_Parent::Remove_block(int i)
//{
//	if (i > 0 && _blocks.size() > 0)
//	{
//		pb = _blocks.begin();
//		for (int i1 = 0; i1 < i; i++)
//		{
//			pb++;
//		}
//
//		_blocks.erase(pb, pb++);
//
//	}
//}
#pragma endregion



//#pragma region get
//Block Figure_Parent::Get_block(int i)
//{
//	pb = _blocks.begin();
//	for (int _i = 0; _i < i; _i++)
//	{
//		pb++;
//	}
//	return *pb;
//}
//int Figure_Parent::Get_X()
//{
//	return _x;
//}
//int Figure_Parent::Get_Y()
//{
//	return _y;
//}
//#pragma endregion
//
//
//#pragma region set
//void Figure_Parent::Add_block(Block *& block)
//{
//
//}
//void Figure_Parent::Set_X(int x)
//{
//
//}
//void Figure_Parent::Set_Y(int y)
//{
//
//}
//#pragma endregion
//
//
//#pragma region  move
//void Figure_Parent::Move_on(int x, int y)
//{
//
//}
//void Figure_Parent::Move_to(int x, int y)
//{
//
//}
//void Figure_Parent::Rotate(my_enums::Rotate r)
//{
//
//}
//#pragma endregion







