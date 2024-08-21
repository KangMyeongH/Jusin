#include "JobMenu.h"
#include "Player.h"

#include <iostream>

void JobMenu::RenderMenu()
{
	Menu::RenderMenu();
	std::cout << "1.Warrior    2.Wizard    3.Thief\n";
	std::cout << "Select Menu : ";
}

void JobMenu::SelectMenu()
{
	int number = 0;
	std::cin >> number;
	switch(number)
	{
	case 1:
		// 전사 전직
		Player::GetInstance().JobAdvancement(number);
		break;
	case 2:
		// 법사 전직
		Player::GetInstance().JobAdvancement(number);
		break;
	case 3:
		// 도적 전직
		Player::GetInstance().JobAdvancement(number);
		break;
	default:
		return;
	}

	SetMenuType(eMenuType::Main);
}
