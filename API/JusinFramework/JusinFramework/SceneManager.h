#pragma once
#include <vector>

#include "framework.h"
#include "Resource.h"
#include "Define.h"

class Scene;
using SceneList = std::vector<Scene*>;
class SceneManager
{
public:
	SceneManager() 									= default;
	~SceneManager() 								= default;
public:
	SceneManager(const SceneManager&) 				= delete;
	SceneManager(SceneManager&&) 					= delete;
	SceneManager& operator=(const SceneManager&) 	= delete;
	SceneManager& operator=(SceneManager&&) 		= delete;

	//static SceneManager& GetInstance() { static SceneManager sSceneManager; return sSceneManager; }

	void 		Init();
	void		Start();
	void 		Update();
	void		LateUpdate();
	void 		Render(HDC hdc);

	template<typename T> void LoadScene();

private:
	Scene* 			mCurrentScene = nullptr;
	Scene* 			mNextScene = nullptr;
};

template <typename T>
void SceneManager::LoadScene()
{
	if (typeid(*mCurrentScene) != typeid(T))
	{
		mNextScene = new T;
	}
}