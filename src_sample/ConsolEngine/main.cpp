// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "Game.h"

void main ()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Game app= Game();
	app.Run();
	_CrtDumpMemoryLeaks();
}
