#pragma once
#include "Menu.h"
class MainMenu final : public Menu
{
public:
	explicit 	MainMenu(const eMenuType type) : Menu(type) {}
	void 		RenderMenu() override;
	void 		SelectMenu() override;
};