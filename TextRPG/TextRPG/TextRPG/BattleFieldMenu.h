#pragma once
#include "Menu.h"
class BattleFieldMenu final : public Menu
{
public:
	explicit 	BattleFieldMenu(const eMenuType type) : Menu(type) {}
	void 		RenderMenu() override;
	void 		SelectMenu() override;
};