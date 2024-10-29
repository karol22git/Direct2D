#pragma once
#include "GameLevel.h"
class Level1 : public GameLevel {
	float y = 0.0;
	float ySpeed = 0.0f;
public:
	void Load() override;
	void Unload() override;
	void Render(Graphics*) override;
	void Update() override;
};