#include "pch.h"
#include "ObjectBullet.h"

#include "Bullet.h"

ObjectBullet::ObjectBullet(const Vector2 position)
{
	Position = position;
	AddComponent<Bullet>();
}
