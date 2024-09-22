#include "pch.h"
#include "Player.h"

#include "Inventory.h"
#include "Weapon.h"

Player::~Player()
{
	delete mWeaponSlot;
	delete mArmorSlot;
}

void Player::Initialize(const std::string& className, const int maxHP, const int atk)
{
	mName = className;
	mMaxHP = maxHP;
	mHP = maxHP;
	mATK = atk;

	AddComponent<Inventory>();
}

void Player::Attack()
{

}

void Player::Resurrection()
{
	mHP = mMaxHP;
}

bool Player::IsDeath() const
{
	return mHP <= 0;
}

bool Player::EquipItem(Item* item)
{
	if (mWeaponSlot)
	{
		GetComponent<Inventory>()->
	}
}

bool Player::UnequipItem(Item* item)
{
}

std::string Player::GetClass() const
{
	return mClass;
}

int Player::GetMaxHP() const
{
	return mMaxHP;
}

int Player::GetHP() const
{
	return mHP;
}

int Player::GetATK() const
{
	return mATK;
}

void Player::SetClass(const std::string& className)
{
	mClass = className;
}

void Player::SetMaxHP(const int maxHP)
{
	mMaxHP = maxHP;
}

void Player::SetHP(const int hp)
{
	mHP = hp;
}

void Player::SetATK(const int atk)
{
	mATK = atk;
}