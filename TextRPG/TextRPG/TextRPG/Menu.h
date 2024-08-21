#pragma once
#include "Entity.h"

enum class eMenuType
{
	Default,
	Start,
	Job,
	Main,
	SelectLevel,
	BattleField,
	End,
	Error = -1,
};

class Menu
{
public:
	Menu() : mMenuType(eMenuType::Default) 					{}
	explicit Menu(const eMenuType type) : mMenuType(type) 	{}
	virtual ~Menu();

	eMenuType 	GetMenuType() const 					{ return mMenuType; }
	void 		SetMenuType(const eMenuType menuType) 	{ mMenuType = menuType; }

	void 		RenderInfo(const Entity* entity);
	bool 		SwitchMenu(Menu** menu);

	virtual void 	RenderMenu();
	virtual void 	SelectMenu();

private:
	eMenuType mMenuType;
};

