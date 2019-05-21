// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#pragma once

#include "BaseApp.h"
#include "Field.h"
//класс игры
class Game : public BaseApp
{
	typedef BaseApp Parent;

	

	private:
		int _scorre;

		Field * _my_field;

	public:
		Game();
		virtual void KeyPressed(int btnCode);//нажатие клавиши
		virtual void UpdateF(float deltaTime);//обновление в секундах
};
