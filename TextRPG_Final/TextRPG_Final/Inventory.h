#pragma once
#include "Component.h"
#include "Item.h"
#include <array>

enum : std::uint8_t
{
	InventorySize = 5
};

using ItemArray = std::array<Item*, InventorySize>;
class Inventory final : public Component
{
public:
	Inventory() = default;
	~Inventory() override;
	Inventory(const Inventory& rhs);
	Item& operator[](size_t index) const;

	Component* Clone() const override;

	bool 		AddItem(Item* item);
	bool 		RemoveItem(const Item* item);
	Item* 		GetItemByID(int itemID);
	ItemArray& 	GetAllItems();
	bool 		IsFull() const;
	void 		ClearInventory();
	int 		GetInventoryCapacity();

private:
	ItemArray mItems{};
};