#include "Core.h"

#include "SceneManager.h"

void Core::Init(HWND& hwnd)
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
	mSceneManager = new SceneManager;
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
	Rectangle(mHdc, 100, 100, WIN_WIDTH - 100, WIN_HEIGHT - 100);
	mSceneManager->Render(mHdc);
}
