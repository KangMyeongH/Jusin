#pragma once
#include <list>

#include "Bullet.h"

class MonoBehavior;
class GameObject;

using MonoBehaviorList = std::list<MonoBehavior*>;
using GameObjectList = std::list<GameObject*>;
class Core
{
private:
	Core();
	~Core();

public:
	Core(const Core& rhs) 				= delete;
	Core(Core&& rhs) 					= delete;
	Core& operator=(const Core& rhs) 	= delete;
	Core& operator=(Core&& rhs) 		= delete;

	static Core& 	GetInstance() { static Core sCore; return sCore; }
	void 			AddMonoBehavior(MonoBehavior* monoBehavior);
	void			AddGameObject(GameObject* gameObject);
	void 			Start();
	void 			End();
	void 			Run();

private:
	void 			update();
	void 			render();

private:
	MonoBehaviorList 	mMonoBehaviors;
	GameObjectList		mGameObjects;
	HDC					mDC;
};

