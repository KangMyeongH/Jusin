#include "Player.h"
#include "framework.h"

void Player::Init()
{
}

void Player::Start()
{
	mTag = Tag::Player;
	Position = { WIN_WIDTH / 2.f, WIN_HEIGHT / 2.f };
	Scale = { 100.f, 100.f };
	mSpeed = 10.f;
}

void Player::Update()
{
	KeyInput();
}

void Player::LateUpdate()
{
}

void Player::Render(HDC hdc)
{
	Rectangle(hdc, Position.x - Scale.x / 2.f, Position.y - Scale.y / 2.f,
		Position.x + Scale.x / 2.f, Position.y + Scale.y / 2.f);
}

void Player::KeyInput()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		Position.x += mSpeed;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		Position.x -= mSpeed;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		Position.y -= mSpeed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		Position.y += mSpeed;
	}
}
