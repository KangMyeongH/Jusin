#include "pch.h"
#include "StartMenu.h"

#include <iostream>

void StartMenu::RenderMenu()
{
	system("cls");
	std::cout << "Start Menu\n";
	std::cout << "====================================\n";
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
		mNextMenuType = eMenuType::SelectJob;
		break;

	case 2:
		mNextMenuType = eMenuType::Main;
		break;

	case 3:
		mNextMenuType = eMenuType::End;
		break;

	default:
		break;
	}
}
