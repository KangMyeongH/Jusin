#include "pch.h"
#include "Object.h"

Object::operator bool() const
{
	return mActive;
}

bool Object::operator==(const Object& rhs)
{
	return this == &rhs;
}

bool Object::operator!=(const Object& rhs)
{
	return this != &rhs;
}

void Object::Destroy(const Object* object)
{
	delete object;
}

std::string Object::ToString() const
{
	return mName;
}
