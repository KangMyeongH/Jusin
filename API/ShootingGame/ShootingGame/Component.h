#pragma once
#include "framework.h"
#include "Object.h"

class GameObject;

class Component : public Object
{
public:
	Component() = default;
	~Component() override = default;
	Component(const Component& rhs) = default;
	virtual Component* Clone() const = 0;
	GameObject* GetParent() const 			{ return mGameObject; }
	void AttachParent(GameObject& parent) 	{ mGameObject = &parent; }

protected:
	GameObject* mGameObject = nullptr;
};
