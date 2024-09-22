#include "pch.h"
#include "Bullet.h"
#include "Define.h"
#include "GameObject.h"

Component* Bullet::Clone() const
{
	return new Bullet(*this);
}

void Bullet::start()
{
	mDC = GetDC(sHWnd);
	mGameObject->Scale = { 50, 50 };
}

void Bullet::update()
{
	mGameObject->Position.y -= 10;
}

void Bullet::render()
{
	Ellipse(mDC, mGameObject->Position.x, mGameObject->Position.y,
		mGameObject->Position.x + mGameObject->Scale.x, mGameObject->Position.y + mGameObject->Scale.y);
}

void Bullet::end()
{
}
