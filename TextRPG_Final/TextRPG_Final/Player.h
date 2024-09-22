#pragma once
#include "GameObject.h"
#include "EquipmentItem.h"

class Player final : public GameObject
{
private:
	Player() : GameObject("Player", eTag::Player), mMaxHP(0), mHP(0), mATK(0), mWeaponSlot(nullptr), mArmorSlot(nullptr) {}
	~Player() override;

public:
	Player(const Player& rhs) 				= delete;
	Player(Player&& rhs) 					= delete;
	Player& operator=(const Player& rhs) 	= delete;
	Player& operator=(Player&& rhs) 		= delete;

public:
	// Methods
	static Player&	GetInstance() { static Player sPlayer; return sPlayer; }
	void			Initialize(const std::string& className, int maxHP, int atk);
	void 			Attack();
	void			Resurrection();
	bool			IsDeath() const;
	bool			EquipItem(Item* item);
	bool			UnequipItem(Item* item);

	// Property
	std::string		GetClass() const;
	int 			GetMaxHP() const;
	int 			GetHP() const;
	int 			GetATK() const;
	void 			SetClass(const std::string& className);
	void 			SetMaxHP(int maxHP);
	void 			SetHP(int hp);
	void 			SetATK(int atk);

private:
	std::string 		mClass;
	int 				mMaxHP;
	int 				mHP;
	int 				mATK;
	Item* 				mWeaponSlot;
	Item* 				mArmorSlot;
};
