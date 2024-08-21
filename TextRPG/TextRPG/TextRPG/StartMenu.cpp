#include "StartMenu.h"

#include <iostream>

void StartMenu::RenderMenu()
{
	Menu::RenderMenu();
	std::cout << "1.New Game    2.Load Game    3.Quit Game\n";
	std::cout << "Select Menu : ";
}

void StartMenu::SelectMenu()
{
	int number;
	std::cin >> number;

	switch (number)
	{
	case 1:
		SetMenuType(eMenuType::Job);
		break;
	case 2:
		SetMenuType(eMenuType::Main);
		break;
	case 3:
		SetMenuType(eMenuType::End);
		break;
	default: 
		SetMenuType(GetMenuType());
		break;
	}
}
