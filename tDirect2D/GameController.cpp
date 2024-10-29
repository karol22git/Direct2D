#include "GameController.h"
GameLevel* GameController::currentLevel;
bool GameController::Loading;


void GameController::LoadInitialLevel(GameLevel* lvl) {
	Loading = true;
	currentLevel = lvl;
	currentLevel->Load();
	Loading = false;
}

void GameController::SwitchLevel(GameLevel* lvl) {
	Loading = true;
	currentLevel->Unload();
	lvl->Load();
	delete currentLevel;
	currentLevel = lvl;
	Loading = false;
}

void GameController::Render(Graphics* gfx) {
	if (Loading) return;
	currentLevel->Render(gfx);
}


void GameController::Update() {
	if (Loading) return;
	currentLevel->Update();
}


void GameController::Init() {
	Loading = true;
	currentLevel = 0;
}