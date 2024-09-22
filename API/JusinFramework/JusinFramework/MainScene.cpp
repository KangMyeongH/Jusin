#include "MainScene.h"
#include "Player.h"

void MainScene::Init()
{
	mGameObjects.push_back(new Player);
	Scene::Init();
}

void MainScene::Start()
{
	Scene::Start();
}

void MainScene::Update()
{
	Scene::Update();
}

void MainScene::LateUpdate()
{
	Scene::LateUpdate();
}

void MainScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
