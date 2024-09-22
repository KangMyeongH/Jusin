#pragma once
#include <cstdint>
enum class eMenuType : std::int8_t
{
	Default,
	Start,
	Main,
	SelectJob,
	SelectLevel,
	Battle,
	End,
	Error = -1
};

class Menu
{
public:
	explicit Menu(const eMenuType type) : mNextMenuType(type) {}
	virtual ~Menu() 					= default;
	Menu(const Menu& rhs) 				= default;
	Menu(Menu&& rhs) noexcept 			= default;
	Menu& operator=(const Menu& rhs) 	= default;
	Menu& operator=(Menu&& rhs) 		= default;

	virtual void RenderMenu() 			= 0;
	virtual void SelectMenu() 			= 0;
	
	eMenuType GetNextMenuType() const 			{ return mNextMenuType; }
	void SetNextMenuType(const eMenuType type) 	{ mNextMenuType = type; }
protected:
	eMenuType mNextMenuType;
};