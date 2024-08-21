#pragma once
#include "Menu.h"
class StartMenu final : public Menu
{
public:
	explicit 	StartMenu(const eMenuType type) : Menu(type) {}
	void 		RenderMenu() override;
	void 		SelectMenu() override;
};

