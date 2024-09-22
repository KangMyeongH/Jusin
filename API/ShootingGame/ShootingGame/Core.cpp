#include "pch.h"
#include "Core.h"

#include "Define.h"
#include "MonoBehavior.h"
#include "ObjectGun.h"

Core::Core()
{
	mDC = GetDC(sHWnd);
}

Core::~Core()
{
	for (auto& behavior : mMonoBehaviors)
	{
		delete behavior;
		behavior = nullptr;
	}
}

void Core::AddMonoBehavior(MonoBehavior* monoBehavior)
{
	mMonoBehaviors.push_back(monoBehavior);
	monoBehavior->start();
}

void Core::AddGameObject(GameObject* gameObject)
{
	mGameObjects.push_back(gameObject);
}

void Core::Start()
{
	SetTimer(sHWnd, 0, 0, nullptr);
	Vector2 position = { 400, 400 };
	GameObject* test = new ObjectGun(position);
	test->Scale.x = 100;
	test->Scale.y = 100;
	mGameObjects.push_back(new ObjectGun(position));

	for (const auto& behavior : mMonoBehaviors)
	{
		behavior->start();
	}
}

void Core::End()
{
	for (const auto& behavior : mMonoBehaviors)
	{
		behavior->end();
	}
}

void Core::Run()
{
	update();
	render();
}

void Core::update()
{
	for (const auto& behavior : mMonoBehaviors)
	{
		behavior->update();
	}
}

void Core::render()
{
	InvalidateRect(sHWnd, nullptr, true);

	for (const auto& behavior : mMonoBehaviors)
	{
		behavior->render();
	}
}
