#include "SelectLevelMenu.h"
#include "Player.h"
#include "EntityManager.h"

#include <iostream>

void SelectLevelMenu::RenderMenu()
{
	Menu::RenderMenu();
	RenderInfo(&Player::GetInstance());
	std::cout << "1.Easy    2.Medium    3.Hard    4.Main Menu\n";
	std::cout << "Select Menu : ";
}

void SelectLevelMenu::SelectMenu()
{
	int number;
	std::cin >> number;

	switch (number)
	{
	case 1:
		// 초급 몬스터 설정
		EntityManager::GetInstance().GetMonster()->SetDifficulty(number);
		SetMenuType(eMenuType::BattleField);
		break;
	case 2:
		// 중급 몬스터 설정
		EntityManager::GetInstance().GetMonster()->SetDifficulty(number);
		SetMenuType(eMenuType::BattleField);
		break;
	case 3:
		// 고급 몬스터 설정
		EntityManager::GetInstance().GetMonster()->SetDifficulty(number);
		SetMenuType(eMenuType::BattleField);
		break;
	case 4:
		SetMenuType(eMenuType::Main);
		break;
	default:
		SetMenuType(GetMenuType());
		break;
	}
}
