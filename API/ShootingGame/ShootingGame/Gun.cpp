#include "pch.h"
#include "Gun.h"

#include "Define.h"
#include "ObjectBullet.h"

Component* Gun::Clone() const
{
	return new Gun(*this);
}

void Gun::start()
{
	mDC = GetDC(sHWnd);
}

void Gun::update()
{
	if(GetAsyncKeyState(VK_SPACE))
	{
		mBullets.push_back(new ObjectBullet(mGameObject->Position));
	}

	else if (GetAsyncKeyState(VK_UP))
	{
		mGameObject->Position.y -= 10;
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		mGameObject->Position.y += 10;
	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{
		mGameObject->Position.x += 10;
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		mGameObject->Position.x -= 10;
	}
}

void Gun::render()
{
	Rectangle(mDC, mGameObject->Position.x, mGameObject->Position.y,
		mGameObject->Position.x + mGameObject->Scale.x, mGameObject->Position.y + mGameObject->Scale.y);
}

void Gun::end()
{
}
