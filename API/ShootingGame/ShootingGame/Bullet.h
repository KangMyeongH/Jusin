#pragma once
#include "MonoBehavior.h"
class Bullet : public MonoBehavior
{
public:
	Bullet() : mDC() {}

	Component* Clone() const override;

protected:
	void start() override;
	void update() override;
	void render() override;
	void end() override;

private:
	HDC mDC;
};

