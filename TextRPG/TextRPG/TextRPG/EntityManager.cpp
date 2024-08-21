#include "EntityManager.h"

EntityManager::~EntityManager()
{
	delete mMonster;
}

void EntityManager::Initialize()
{
	if (!mMonster) mMonster = new Monster;
}
