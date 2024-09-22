#include "pch.h"
#include "Inventory.h"

#include <algorithm>
#include <iostream>

Inventory::~Inventory()
{
	for (const auto& item : mItems)
	{
		delete item;
	}
}

Inventory::Inventory(const Inventory& rhs) : Component(rhs)
{
	for (int i = 0; i < InventorySize; i++)
	{
		if (rhs.mItems[i]) mItems[i] = dynamic_cast<Item*>(rhs.mItems[i]->Clone());
	}
}

Item& Inventory::operator[](const size_t index) const
{
	return *mItems[index];
}

Component* Inventory::Clone() const
{
	return new Inventory(*this);
}

bool Inventory::AddItem(Item* item)
{
	if (IsFull()) 
		return false;

	for (auto& itemSlot : mItems)
	{
		if (!itemSlot)
		{
			itemSlot = item;
			return true;
		}
	}

	return false;
}

bool Inventory::RemoveItem(const Item* item)
{
	for (auto& itemSlot : mItems)
	{
		if (itemSlot == item)
		{
			Destroy(itemSlot);
			itemSlot = nullptr;
			return true;
		}
	}

	return false;
}

Item* Inventory::GetItemByID(int itemID)
{
	// Dummy
	return nullptr;
}

ItemArray& Inventory::GetAllItems()
{
	return mItems;
}

bool Inventory::IsFull() const
{
	return std::all_of(mItems.begin(), mItems.end(), [](const auto& itemSlot)->bool { return itemSlot; });
}

void Inventory::ClearInventory()
{
	for (auto& slot : mItems)
	{
		Destroy(slot);
		slot = nullptr;
	}
}

int Inventory::GetInventoryCapacity()
{
	return InventorySize;
}