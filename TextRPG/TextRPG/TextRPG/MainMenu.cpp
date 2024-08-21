#include "MainMenu.h"

#include <iostream>

#include "Player.h"

void MainMenu::RenderMenu()
{
	Menu::RenderMenu();
	RenderInfo(&Player::GetInstance());
	std::cout << "1. Field    2. Quit Game\n";
	std::cout << "Select Menu : ";
}

void MainMenu::SelectMenu()
{
	int number;
	std::cin >> number;

	switch (number)
	{
	case 1:
		SetMenuType(eMenuType::SelectLevel);
		break;
	case 2:
		SetMenuType(eMenuType::End);
		break;
	default:
		SetMenuType(GetMenuType());
		break;
	}
}
