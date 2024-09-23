#include "Core.h"

#include "SceneManager.h"

void Core::Init(HWND& hwnd)
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
	mSceneManager = &SceneManager::GetInstance();
	mSceneManager->Init();
}

void Core::Progress()
{
	start();
	update();
	lateUpdate();
	render();
}

void Core::start()
{
	mSceneManager->Start();
}

void Core::update()
{
	mSceneManager->Update();
}

void Core::lateUpdate()
{
	mSceneManager->LateUpdate();
}

void Core::render()
{
	Rectangle(mHdc, 0, 0, WIN_WIDTH, WIN_HEIGHT);
	mSceneManager->Render(mHdc);
}
