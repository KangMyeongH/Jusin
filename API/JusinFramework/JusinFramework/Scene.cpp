#include "Scene.h"
#include "GameObject.h"

Scene::~Scene()
{
	for (auto& gameObject : mGameObjects)
	{
		delete gameObject;
		gameObject = nullptr;
	}
}

void Scene::Init()
{
	mPendingObjectList = mGameObjects;
}

void Scene::Start()
{
	for (auto& object : mPendingObjectList)
	{
		object->Start();
		mActiveObjectList.push_back(object);
	}
}

void Scene::Update()
{
	for (const auto& object : mActiveObjectList)
	{
		object->Update();
	}
}

void Scene::LateUpdate()
{
	for (const auto& object : mActiveObjectList)
	{
		object->LateUpdate();
	}
}

void Scene::Render(HDC hdc)
{
	for (const auto& object : mActiveObjectList)
	{
		object->Render(hdc);
	}
}
