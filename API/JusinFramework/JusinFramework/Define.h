#pragma once
#include "Vector2.h"
#include <cstdint>

enum class Tag : uint8_t
{
	Untagged,
	Player,
	Monster,
	Object
};

enum DIRECTION { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_LU, DIR_RU, DIR_END };