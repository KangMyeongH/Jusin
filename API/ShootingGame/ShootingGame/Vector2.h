#pragma once
class Vector2
{
public:
	Vector2() : x(0), y(0) {}
	Vector2(const int x, const int y) : x(x), y(y) {}

public:
	int x;
	int y;
};