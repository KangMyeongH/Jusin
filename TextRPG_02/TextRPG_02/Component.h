#pragma once

class GameObject;

class Component
{
public:
	virtual ~Component() = default;
	virtual void Start() = 0;
	virtual void Update() = 0;

	void 		SetOwner(GameObject* owner)	{ mOwner = owner; }
	GameObject* GetOwner() const			{ return mOwner; }

private:
	GameObject* mOwner = nullptr;
};
