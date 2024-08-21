#include "Entity.h"

#include <cstring>

Entity::Entity()
{
	mName[0] = '\0';
	mMaxHp = 0;
	mHp = 0;
	mAtk = 0;
}

Entity::~Entity() = default;

void Entity::Initialize(const char* name, const int maxHp, const int atk)
{
	strcpy_s(mName, name);
	mMaxHp = maxHp;
	mHp = maxHp;
	mAtk = atk;
}

bool Entity::IsDeath() const
{
	return mHp <= 0;
}

void Entity::Resurrection()
{
	if (IsDeath()) mHp = mMaxHp;
}
