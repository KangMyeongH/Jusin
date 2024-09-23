#pragma once
#include "framework.h"
#include "Resource.h"
#include <list>

class GameObject;
using GameObjectList = std::list<GameObject*>;
class Scene
{
public:
	Scene() 							= default;
	virtual ~Scene();
	Scene(const Scene& rhs) 			= delete;
	Scene(Scene&& rhs) 					= delete;
	Scene& operator=(const Scene& rhs) 	= delete;
	Scene& operator=(Scene&& rhs) 		= delete;

	virtual void 		Init();
	virtual void 		Start();
	virtual void 		Update();
	virtual void 		LateUpdate();
	virtual void 		Render(HDC& hdc);

protected:
	GameObjectList 		mGameObjects;
	GameObjectList		mActiveObjectList;
	GameObjectList		mPendingObjectList;
};