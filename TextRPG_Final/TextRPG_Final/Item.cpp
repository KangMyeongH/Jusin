#include "pch.h"
#include "Item.h"


std::string Item::GetName() const
{
	return mName;
}

int Item::GetPrice() const
{
	return mPrice;
}

eItemType Item::GetItemType() const
{
	return mItemType;
}
