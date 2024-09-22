#pragma once

#include "LinkedList.h"
#include "Component.h"

#include <string>
#include <typeinfo>

//using Iterator = LinkedList<Component*>::Iterator;

class GameObject
{
public:
	GameObject();
	~GameObject();

	template <typename T> T* 		GetComponent();
	LinkedList<Component*> 			GetComponents();
	template <typename T> void 		AddComponent();
	template <typename T> void		RemoveComponent();

private:
	LinkedList<Component*> 	mComponentList;
};

template <typename T>
T* GameObject::GetComponent()
{
	// List is Empty return nullptr
	if (!mComponentList.GetSize()) return nullptr;

	// Check Class Type
	for (LinkedList<Component*>::Iterator iterator = mComponentList.Begin(); iterator != mComponentList.End(); ++iterator)
	{
		Component* temp = *iterator;
		if (typeid(T) == typeid(*temp)) return static_cast<T*>(temp);
	}

	return nullptr;
}

template <typename T>
void GameObject::AddComponent()
{
	Component* component = new T;
	mComponentList.PushBack(component);
	component->SetOwner(this);
}

template <typename T>
void GameObject::RemoveComponent()
{
	// List is empty return nullptr
	if (!mComponentList.GetSize()) return;

	// Find component
	for (LinkedList<Component*>::Iterator iterator = mComponentList.Begin(); iterator != mComponentList.End(); ++iterator)
	{
		Component* component = *iterator;
		// Remove component
		if (typeid(T) == typeid(*component))
		{
			delete component;
			mComponentList.Erase(iterator);
			return;
		}
	}
}
