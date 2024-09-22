#pragma once
#include "Character.h"
#include "Singleton.h"

class Player final : public Character, public Singleton<Player>
{
public:
	Player(const Player&) = delete;
	Player(Player&&) = delete;
	Player& operator=(const Player&) = delete;
	Player& operator=(Player&&) = delete;

private:
	Player() { std::cout << "player" << std::endl; }
	~Player() override = default;

	friend class Singleton;
};