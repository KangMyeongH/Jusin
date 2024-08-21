#include "MainGame.h"
#include "StartMenu.h"

MainGame::MainGame()
{
	mMenu = nullptr;
}

MainGame::~MainGame()
{
	mMenu->RenderMenu();
	delete mMenu;
}

void MainGame::Initialize()
{
	if(!mMenu)	mMenu = new StartMenu(eMenuType::Start);
	EntityManager::GetInstance().Initialize();
}

void MainGame::Update()
{
	while (true)
	{
		mMenu->RenderMenu();
		mMenu->SelectMenu();
		if (!mMenu->SwitchMenu(&mMenu)) break;
	}
}
