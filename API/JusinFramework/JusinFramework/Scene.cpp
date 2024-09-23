#include "Scene.h"
#include "GameObject.h"

Scene::~Scene()
{
	for (auto& gameObject : mActiveObjectList)
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
	if (mPendingObjectList.empty()) return;

	for (auto& object : mPendingObjectList)
	{
		object->Start();
	}

	mActiveObjectList.insert(mActiveObjectList.end(), mPendingObjectList.begin(), mPendingObjectList.end());
	mPendingObjectList.clear();
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

void Scene::Render(HDC& hdc)
{
	for (const auto& object : mActiveObjectList)
	{
		object->Render(hdc);
	}
}
