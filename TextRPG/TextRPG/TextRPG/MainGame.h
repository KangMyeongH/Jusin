#pragma once
#include "EntityManager.h"
#include "Menu.h"

class MainGame
{
public:
	MainGame();
	~MainGame();
	void Initialize();
	void Update();
private:
	Menu* mMenu;
};

