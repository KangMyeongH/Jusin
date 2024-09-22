#include "pch.h"
#include "GameObject.h"

GameObject::GameObject() = default;

GameObject::~GameObject()
{
	if (mComponentList.GetSize())
	{
		for(LinkedList<Component*>::Iterator iterator = mComponentList.Begin(); iterator != mComponentList.End(); ++iterator)
		{
			delete *iterator;
		}
	}
}

LinkedList<Component*> GameObject::GetComponents()
{
	return mComponentList;
}
