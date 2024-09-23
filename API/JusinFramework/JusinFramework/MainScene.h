#pragma once
#include "Scene.h"
class MainScene final : public Scene
{
public:
	~MainScene() override = default;
	void Init() override;
	void Start() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC& hdc) override;
};