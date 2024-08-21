#pragma once
#include "Menu.h"
class EndMenu final : public Menu
{
public:
	explicit 	EndMenu(const eMenuType type) : Menu(type) {}
	void 		RenderMenu() override;
	void 		SelectMenu() override;
};