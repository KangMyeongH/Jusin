#pragma once
#include "GameObject.h"
class Player final : public GameObject
{
public:
	Player() : mSpeed(0) {}

	void Init() override;
	void Start() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

	void KeyInput();

private:
	float mSpeed;
};