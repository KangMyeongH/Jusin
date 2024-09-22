#pragma once
#include "GameObject.h"

enum class eItemType : uint8_t
{
	Default,
	Equipment,
	Consumables,
	Materials
};

class Item : public GameObject
{
public:
	Item(const char* name, const int price, const eItemType type)
		: GameObject(name, eTag::Item), mItemName(name), mPrice(price), mItemType(type) {}
	~Item() override = default;
	Item(const Item& rhs) = default;
	Item(Item&& rhs) = default;
	Item& operator=(const Item& rhs) = default;
	Item& operator=(Item&& rhs) = default;

	virtual std::string 	GetName() const;
	virtual int 			GetPrice() const;
	virtual eItemType 		GetItemType() const;
	virtual bool			Use() = 0;
	virtual void 			DisplayItemInfo() const = 0;

protected:
	std::string 	mItemName;
	int 			mPrice;
	eItemType 		mItemType;
};

