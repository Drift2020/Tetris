// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "Game.h"

Game::Game() : Parent(100, 80)
{
	
	_my_field = new Field();
}

void Game::KeyPressed(int btnCode)//передвижение объекта
{
	//if (btnCode == 119) //w
	//	mObj1Y--;
	//else if (btnCode == 115) //s
	//	mObj1Y++;
	//else if (btnCode == 97) //a
	//	mObj1X--;
	//else if (btnCode == 100) //d
	//	mObj1X++;

	//if (mObj1X < 0)
	//	mObj1X = 0;
	//else if (mObj1X >= X_SIZE)
	//	mObj1X = X_SIZE - 1;

	//if (mObj1Y < 0)
	//	mObj1Y = 0;
	//else if (mObj1Y >=Y_SIZE)
	//	mObj1Y = Y_SIZE - 1;
}

void Game::UpdateF(float deltaTime)
{
	
	for (int y = 0; y < this->_my_field->Get_cF_end().Y; y++)
	{
		for (int x = 0; x < _my_field->Get_cF_end().X; x++)
		{
			

			SetChar(x, y, static_cast<wchar_t>(_my_field->Get_symbol(COORD() = { static_cast<short>(x),static_cast<short>(y) })));
		}
	}
	
	for (int y = 0; y < this->_my_field->Get_cP_end().Y; y++)
	{
		for (int x = 0; x < _my_field->Get_cP_end().X; x++)
		{


			SetChar(_my_field->Get_cP_start().X+x, _my_field->Get_cP_start().Y + y, static_cast<wchar_t>(_my_field->Get_preview(COORD() = { static_cast<short>(x),static_cast<short>(y) })));
		}
	}


	for (int y = 0; y < this->_my_field->Get_cS_end().Y; y++)
	{
		for (int x = 0; x < _my_field->Get_cS_end().X; x++)
		{


			SetChar(_my_field->Get_cS_start().X+x, _my_field->Get_cS_start().Y+ y, static_cast<wchar_t>(_my_field->Get_scorre(COORD() = { static_cast<short>(x),static_cast<short>(y) })));


		}
	}


	//SetChar(mObj1XOld, mObj1YOld, L' ');
	//SetChar(mObj1X, mObj1Y, L'O');

	//mObj1XOld = mObj1X;
	//mObj1YOld = mObj1Y;

	////-----------------------------

	//SetChar(mObj2X, mObj2Y, L' ');//Самопроизвольное движение объекта
	//if (mDirection)
	//{
	//	mObj2X++;
	//	if (mObj2X == 40)
	//		mDirection = false;
	//}
	//else
	//{
	//	mObj2X--;
	//	if (mObj2X == 10)
	//		mDirection = true;
	//}
	//SetChar(mObj2X, mObj2Y, L'F');
}
