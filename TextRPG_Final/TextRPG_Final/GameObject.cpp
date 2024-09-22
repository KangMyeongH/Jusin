#include "pch.h"
#include "GameObject.h"

GameObject::~GameObject()
{
	if (!mComponents.empty())
	{
		for(iterator iter = mComponents.begin(); iter != mComponents.end(); ++iter)
		{
			delete *iter;
			*iter = nullptr;
		}
	}
}

GameObject::GameObject(const GameObject& rhs) : Object(rhs), mActiveSelf(rhs.mActiveSelf), mTag(rhs.mTag)
{
	if (!rhs.mComponents.empty())
	{
		for (auto iter = rhs.mComponents.begin(); iter != rhs.mComponents.end(); ++iter)
		{
			mComponents.push_back((*iter)->Clone());
		}
	}
}

GameObject& GameObject::operator=(const GameObject& rhs)// : Object(rhs), mActiveSelf(rhs.mActiveSelf), mTag(rhs.mTag)
{
	if (!rhs.mComponents.empty())
	{
		for (auto iter = rhs.mComponents.begin(); iter != rhs.mComponents.end(); ++iter)
		{
			mComponents.push_back((*iter)->Clone());
		}
	}
	return *this;
}
