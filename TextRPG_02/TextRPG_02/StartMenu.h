#pragma once
#include "Menu.h"
class StartMenu final : public Menu
{
public:
	explicit StartMenu(const eMenuType type) : Menu(type) {}
	~StartMenu() override = default;
	StartMenu(const StartMenu& rhs) = default;
	StartMenu(StartMenu&& rhs) = default;
	StartMenu& operator=(const StartMenu& rhs) = default;
	StartMenu& operator=(StartMenu&& rhs) = default;

	void RenderMenu() override;
	void SelectMenu() override;
};

