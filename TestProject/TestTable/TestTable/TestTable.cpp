#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

#include <iostream>
#include <vector>
using namespace std;

/*
class Transaction
{
public:
	Transaction();
	virtual ~Transaction() = default;

	virtual void LogTransaction() const = 0;
private:
	void init();
};

Transaction::Transaction()
{
	init();
}

void Transaction::init()
{
	LogTransaction();
}

class BuyTransaction : public Transaction
{
public:
	BuyTransaction() { LogTransaction(); }
	void LogTransaction() const override { cout << "BuyTransaction" << endl; }
};
*/

// 이동 생성자, 대입 이동 연산자
/*
class Obj
{
public:
	Obj() : mNum(0)
		{ cout << "Obj 기본 생성자\n"; }
	~Obj() = default;
	Obj(const Obj& rhs) : mNum(rhs.mNum)
		{ cout << "Obj 복사 생성자\n"; }
	Obj(Obj&& rhs) noexcept : mNum(rhs.mNum)
		{ cout << "Obj 이동 생성자\n"; rhs.mNum = 0; }
	Obj& operator=(const Obj& rhs)
		{ cout << "Obj 대입 연산자\n"; mNum = rhs.mNum; return *this; }
	Obj& operator=(Obj&& rhs) noexcept
		{ cout << "Obj 이동 대입 연산자\n"; mNum = rhs.mNum; rhs.mNum = 0; return *this; }

	int GetNum() const 			{ return mNum; }
	void SetNum(const int num) 	{ mNum = num; }
private:
	int mNum;
};

class Player : public Obj
{
public:
	Player() : mPriority(0) { cout << "Player 기본 생성자\n"; }
	~Player() = default;
	Player(const Player& rhs) : Obj(rhs), mPriority(rhs.mPriority) { cout << "Player 복사 생성자\n"; }
	Player(Player&& rhs) noexcept;
	Player& operator=(const Player& rhs) { cout << "Player 대입 연산자\n"; Obj::operator=(rhs); mPriority = rhs.mPriority; return *this; }
	Player& operator=(Player&& rhs) noexcept { cout << "Obj 이동 대입 연산자\n"; Obj::operator=(std::move(rhs)); mPriority = rhs.mPriority; rhs.mPriority = 0; return *this; }

	int GetPriority() const 				{ return mPriority; }
	void SetPriority(const int priority) 	{ mPriority = priority; }
private:
	int mPriority;
};

Player::Player(Player&& rhs) noexcept: Obj(std::move(rhs)), mPriority(rhs.mPriority)
{ cout << "Player 이동 생성자\n"; rhs.mPriority = 0; }
*/

// 팩토리 메소드 패턴
/*class Button
{

};
class CheckBox
{

};

class UIAbstractFactory
{
public:
	virtual Button* CreateButton() = 0;
	virtual CheckBox* CreateCheckBox() = 0;
};

class WindowsUIFactory : public UIAbstractFactory
{
public:
	Button* CreateButton() override { return new WindowsButton(); }
	CheckBox* CreateCheckBox() override { return new WindowsCheckBox(); }
};

class MacOSUIFactory : public UIAbstractFactory
{
public:
	Button* CreateButton() override { return new MacOSButton(); }
	CheckBox* CreateCheckBox() override { return new MacOSCheckBox(); }
};

void createUI(UIAbstractFactory* factory)
{
	Button* button = factory->CreateButton();
	CheckBox* checkBox = factory->CreateCheckBox();
}*/

/*
class Base
{
public:
	explicit Base(const int num) : mNum(num) {}
	Base(const Base& rhs) : mNum(rhs.mNum) { cout << "복사 생성자 호출\n"; }
	Base& operator=(const Base& rhs)
	{
		cout << "대입 연산자 호출\n";
		mNum = rhs.mNum; return *this;
	}

	Base& operator+(const Base& rhs)
	{
		mNum += rhs.mNum;
		return *this;
	}

	int GetNum() const { return mNum; }
private:
	int mNum;
};*/

/*
class Item
{
public:
	// 깊은 복사를 하는 복사 생성자가 있다는 가정임.
	Item() = default;
	Item(string type) : mItemType(std::move(type)) {}

	Item(const Item& rhs) : mItemType(rhs.mItemType) {}
public:
	virtual Item* Clone() = 0;
	void PrintItemType() const { cout << mItemType << '\n'; }
protected:
	string mItemType;
};

class Weapon : public Item
{
public:
	Weapon() : Item("Weapon") {}
	Weapon(const Weapon& rhs) : Item(rhs) {}
public:
	Item* Clone() override
	{
		return new Weapon(*this);
	}
};

class Armor : public Item
{
public:
	Armor() : Item("Armor") {}
	Armor(const Weapon& rhs) : Item(rhs) {}
public:
	Item* Clone() override
	{
		return new Armor(*this);
	}
};

class Inventory
{
public:
	void AddItem(Item* item)
	{
		mInventory.push_back(item->Clone());
	}

	template<typename T>
	void AddItem(Item* item)
	{
		
	}
private:
	vector<Item*> mInventory;
};

*/
int main()
{
	int* temp = new int;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}