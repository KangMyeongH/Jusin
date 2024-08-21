#include "Player.h"

void Player::JobAdvancement(const int index)
{
	switch (index)
	{
	case Warrior:
		Initialize("Warrior", 100, 10);
		break;
	case Wizard:
		Initialize("Wizard", 100, 10);
		break;
	case Thief:
		Initialize("Thief", 100, 10);
		break;
	default:
		break;
	}
}

void Player::Attack(Entity* entity) const
{
	entity->SetHp(entity->GetHp() - GetAtk());
}
