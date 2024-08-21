#pragma once
#include "Menu.h"
class SelectLevelMenu final : public Menu
{
public:
	explicit 	SelectLevelMenu(const eMenuType type) : Menu(type) {}
	void 		RenderMenu() override;
	void		SelectMenu() override;
};