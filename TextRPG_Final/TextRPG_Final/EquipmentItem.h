#pragma once
#include "Item.h"
enum class eEquipmentType : std::int8_t
{
	Weapon,
	Armor
};

class EquipmentItem : public Item
{
public:
	EquipmentItem(const char* name, const int price, const eItemType type)
		: Item(name, price, type), mIsEquipped(false), mATK(0), mMaxHP(0), mEquipType() {}

	bool 				Use() override = 0;
	void 				DisplayItemInfo() const override = 0;

	eEquipmentType 		GetEquipType() const 	{ return mEquipType; }
	bool 				IsEquipped() const 		{ return mIsEquipped; }

protected:
	bool 				mIsEquipped;
	int 				mATK;
	int 				mMaxHP;
	eEquipmentType 		mEquipType;
};