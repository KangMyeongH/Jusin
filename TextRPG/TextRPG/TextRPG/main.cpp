#include "MainGame.h"
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif


int main()
{
	MainGame* mainGame = new MainGame;
	const char* Name;
	Name = "Test";
	Name = "End";
	mainGame->Initialize();
	mainGame->Update();

	delete mainGame;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}
