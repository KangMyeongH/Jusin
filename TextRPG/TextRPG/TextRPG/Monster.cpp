#include "Monster.h"

void Monster::SetDifficulty(const int index)
{
	switch (index)
	{
	case Easy:
		Initialize("Easy", 30, 3);
		break;
	case Medium:
		Initialize("Medium", 60, 6);
		break;
	case Hard:
		Initialize("Hard", 90, 9);
		break;
	default:
		break;
	}
}

void Monster::Attack(Entity* entity) const
{
	entity->SetHp(entity->GetHp() - GetAtk());
}
