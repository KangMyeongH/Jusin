#include "Menu.h"
#include "BattleFieldMenu.h"
#include "EndMenu.h"
#include "JobMenu.h"
#include "MainMenu.h"
#include "SelectLevelMenu.h"
#include "StartMenu.h"

#include <iostream>

Menu::~Menu()
{
	
}

void Menu::RenderInfo(const Entity* entity)
{
	std::cout << "NAME : " << entity->GetName() << '\n';
	std::cout << "HP   : " << entity->GetHp() << "    ATK : " << entity->GetAtk() << '\n';
	std::cout << "====================================\n";
}

void Menu::RenderMenu()
{
	system("cls");
	switch(mMenuType)
	{
	case eMenuType::Default:
		std::cout << "Default Menu\n";
		break;
	case eMenuType::Start:
		std::cout << "Start Menu\n";
		break;
	case eMenuType::Main:
		std::cout << "Main Menu\n";
		break;
	case eMenuType::SelectLevel:
		std::cout << "SelectLevel Menu\n";
		break;
	case eMenuType::BattleField:
		std::cout << "BattleField Menu\n";
		break;
	case eMenuType::End:
		std::cout << "Quit Game\n";
		return;
	case eMenuType::Job:
		std::cout << "JobSelect Menu\n";
		break;
	case eMenuType::Error:
		std::cout << "Error!\n";
		return;
	}

	std::cout << "====================================\n";
}

void Menu::SelectMenu()
{
}

bool Menu::SwitchMenu(Menu** menu)
{
	const Menu* temp = *menu;

	switch(mMenuType)
	{
	case eMenuType::Default:
		delete temp;
		//*menu = new Menu();
		return true;

	case eMenuType::Start:
		delete temp;
		*menu = new StartMenu(eMenuType::Start);
		return true;

	case eMenuType::Job:
		delete temp;
		*menu = new JobMenu(eMenuType::Job);
		return true;

	case eMenuType::Main:
		delete temp;
		*menu = new MainMenu(eMenuType::Main);
		return true;

	case eMenuType::SelectLevel:
		delete temp;
		*menu = new SelectLevelMenu(eMenuType::SelectLevel);
		return true;

	case eMenuType::BattleField:
		delete temp;
		*menu = new BattleFieldMenu(eMenuType::BattleField);
		return true;

	case eMenuType::End:
		delete temp;
		*menu = new EndMenu(eMenuType::End);
		return false;

	case eMenuType::Error:
		std::cout << "ERROR!!";
		return false;

	default:
		mMenuType = eMenuType::Error;
		return false;
	}
}