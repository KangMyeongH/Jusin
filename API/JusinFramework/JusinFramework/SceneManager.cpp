#include "SceneManager.h"
#include "Scene.h"
#include <algorithm>

#include "MainScene.h"

void SceneManager::Init()
{
	// TODO : 여기에 시작할 씬을 추가해줍니다.
	// mCurrentScene = new "시작할 Scene";
	// mCurrentScene->Init();
	mCurrentScene = new MainScene;
	mCurrentScene->Init();
}

void SceneManager::Start()
{
	if (!mNextScene)
	{
		mCurrentScene->Start();
		return;
	}

	delete mCurrentScene;
	mCurrentScene = mNextScene;
	mNextScene = nullptr;
	mCurrentScene->Init();
	mCurrentScene->Start();
}

void SceneManager::Update()
{
	mCurrentScene->Update();
}

void SceneManager::LateUpdate()
{
	mCurrentScene->LateUpdate();
}

void SceneManager::Render(HDC hdc)
{
	mCurrentScene->Render(hdc);
}