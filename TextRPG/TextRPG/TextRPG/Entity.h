#pragma once
#include <string.h>

class Entity
{
public:
	Entity();
	~Entity();

	// getter
	const char* GetName() const 	{ return mName; }
	int 		GetMaxHp() const 	{ return mMaxHp; }
	int 		GetHp() const 		{ return mHp; }
	int 		GetAtk() const 		{ return mAtk; }

	// setter
	void 		SetName(const char* name) 	{ strcpy_s(mName, name); }
	void 		SetMaxHp(const int maxHp) 	{ mMaxHp = maxHp; }
	void 		SetHp(const int hp) 		{ mHp = hp; }
	void 		SetAtk(const int atk) 		{ mAtk = atk; }

	void 		Initialize(const char* name, int maxHp, int atk);
	bool 		IsDeath() const;
	void 		Resurrection();

private:
	char 		mName[128];
	int 		mMaxHp;
	int 		mHp;
	int 		mAtk;
};
