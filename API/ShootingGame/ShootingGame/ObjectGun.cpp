#include "pch.h"
#include "ObjectGun.h"

#include "Gun.h"

ObjectGun::ObjectGun(const Vector2 position)
{
	Position = position;
	AddComponent<Gun>();
}
