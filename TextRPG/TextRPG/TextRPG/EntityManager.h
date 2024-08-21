#pragma once
#include "Monster.h"

class EntityManager
{
	//singleton
public:
	static EntityManager& GetInstance() { static EntityManager sEntityManager; return sEntityManager; }
private:
	EntityManager() : mMonster(nullptr) 						{}
	EntityManager(const EntityManager& ref) : mMonster(nullptr) {}
	EntityManager& operator=(const EntityManager& ref) 			{}
	~EntityManager();

public:
	void 		Initialize();
	Monster* 	GetMonster() const { return mMonster; }

private:
	Monster* mMonster;

};

