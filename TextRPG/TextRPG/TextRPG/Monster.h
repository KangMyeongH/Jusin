#pragma once
#include "Entity.h"
enum eDifficulty
{
	Easy = 1,
	Medium,
	Hard
};
class Monster : public Entity
{
public:
	void SetDifficulty(int index);
	void Attack(Entity* entity) const;
};