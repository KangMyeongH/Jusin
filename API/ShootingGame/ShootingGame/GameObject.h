#pragma once
#include "Object.h"
#include "Component.h"

#include <vector>

enum class eTag : uint8_t
{
	Untagged,
	Player,
	Monster,
	Item,
	Manager
};

using iterator = std::vector<Component*>::iterator;
using vector = std::vector<Component*>;
class GameObject : public Object
{
public:
	// constructor
	GameObject() = default;
	explicit GameObject(const char* name) : Object(name), mActiveSelf(true), mTag(eTag::Untagged) {}
	GameObject(const char* name, const eTag tag) : Object(name), mActiveSelf(true), mTag(tag) {}
	~GameObject() override;
	GameObject(const GameObject& rhs);
	GameObject(GameObject&& rhs) noexcept			 = default;
	GameObject& operator=(const GameObject& rhs);
	GameObject& operator=(GameObject&& rhs) noexcept = default;

	template<typename T> void 	AddComponent()
	{
		mComponents.push_back(new T);
		mComponents.back()->AttachParent(*this);
	}
	template<typename T> T* 	GetComponent()
	{
		if (mComponents.size())
		{
			for (iterator iter = mComponents.begin(); iter != mComponents.end(); ++iter)
			{
				Component* temp = *iter;
				if (typeid(T) == typeid(*temp)) return static_cast<T*>(temp);
			}
		}

		return nullptr;
	}
	vector 						GetComponents()
	{
		return mComponents;
	}
	template<typename T> void	RemoveComponent()
	{
		if (mComponents.size())
		{
			for (iterator iter = mComponents.begin(); iter != mComponents.end(); ++iter)
			{
				Component* temp = *iter;
				if (typeid(T) == typeid(*temp))
				{
					delete temp;
					mComponents.erase(iter);
					return;
				}
			}
		}
	}

protected:
	bool mActiveSelf;
	eTag mTag;
	vector mComponents;

public:
	Vector2 Position;
	Vector2 Scale = { 1,1 };
};