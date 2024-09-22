#pragma once
#include "framework.h"
#include "Resource.h"
#include "Define.h"

class GameObject
{
public:
	GameObject() : mTag(Tag::Untagged), Position({ 0,0 }), Scale({ 1.f,1.f }) {}
	virtual ~GameObject() = default;
	GameObject(const GameObject&) = default;
	GameObject(GameObject&&) = default;
	GameObject& operator=(const GameObject&) = default;
	GameObject& operator=(GameObject&&) = default;

	virtual void Init() 			= 0;
	virtual void Start() 			= 0;
	virtual void Update() 			= 0;
	virtual void LateUpdate() 		= 0;
	virtual void Render(HDC hdc) 	= 0;

protected:
	Tag 		mTag;

public:
	Vector2 	Position;
	Vector2 	Scale;
};
