#pragma once
class Vector2
{
public:
	Vector2() : x(0), y(0) {}
	Vector2(const float x, const float y) : x(x), y(y) {}

public:
	float x;
	float y;
};