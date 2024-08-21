#pragma once
#include "Menu.h"
class JobMenu final : public Menu
{
public:
	explicit 	JobMenu(const eMenuType type) : Menu(type) {}
	void 		RenderMenu() override;
	void 		SelectMenu() override;
};

