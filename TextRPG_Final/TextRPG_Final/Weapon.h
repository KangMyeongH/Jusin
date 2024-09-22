#pragma once
#include "EquipmentItem.h"
class Weapon : public EquipmentItem
{
public:
	Weapon() = delete;
	Weapon(const char* name, const int price, const eItemType type, const int atk)
		: EquipmentItem(name, price, type) {}

	bool Use() override;
	void DisplayItemInfo() const override;

};