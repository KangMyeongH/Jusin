#include "BattleFieldMenu.h"

#include <iostream>

#include "EntityManager.h"
#include "Player.h"

void BattleFieldMenu::RenderMenu()
{
	Menu::RenderMenu();
	RenderInfo(&Player::GetInstance()); // player info
	RenderInfo(EntityManager::GetInstance().GetMonster()); // monster info
	std::cout << "1.Attack    2.Run Away\n";
	std::cout << "Select Menu : ";
}

void BattleFieldMenu::SelectMenu()
{
	int number;
	std::cin >> number;

	switch (number)
	{
	case 1:
		// 공격
		Player::GetInstance().Attack(EntityManager::GetInstance().GetMonster());
		EntityManager::GetInstance().GetMonster()->Attack(&Player::GetInstance());

		if(Player::GetInstance().IsDeath())
		{
			std::cout << "Player Lose!!\n";
			Player::GetInstance().Resurrection();
			SetMenuType(eMenuType::SelectLevel);
			system("pause");
			break;
		}

		if (EntityManager::GetInstance().GetMonster()->IsDeath())
		{
			std::cout << "Player Win!!\n";
			SetMenuType(eMenuType::SelectLevel);
			system("pause");
			break;
		}

		SetMenuType(GetMenuType());
		break;

	case 2:
		// 도망가기
		SetMenuType(eMenuType::SelectLevel);
		break;
	default:
		SetMenuType(GetMenuType());
		break;
	}
}
