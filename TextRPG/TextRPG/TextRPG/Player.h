#pragma once
#include "Entity.h"
enum eJob
{
	Warrior = 1,
	Wizard,
	Thief
};

class Player : public Entity
{
public:
	void JobAdvancement(int index);
	void Attack(Entity* entity) const;

	// singleton
public:
	static Player& GetInstance() { static Player sPlayer; return sPlayer; }

private:
	Player() 								{}
	Player(const Player& ref) 				{}
	Player& operator=(const Player& ref) 	{}
	~Player() 								{}	
};