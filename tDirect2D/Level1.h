#pragma once
#include "GameLevel.h"
class Level1 : public GameLevel {
	float y = 0.0;
	float ySpeed = 0.0f;
	SpriteSheet* sprite;
public:
	void Load() override;
	void Unload() override;
	void Render() override;
	void Update() override;
};