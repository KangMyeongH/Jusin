#pragma once
#include "MonoBehavior.h"

class GameObject;
class ObjectBullet;

using BulletList = std::list <ObjectBullet*> ;
class Gun : public MonoBehavior
{
public:
	Gun() : mDC() {}
	Component* Clone() const override;

protected:
	void start() override;
	void update() override;
	void render() override;
	void end() override;

private:
	BulletList mBullets;
	HDC mDC;
};

