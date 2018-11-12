// Library Includes
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

// Local Includes
#include "game.h"
#include "sceneManager.h"
#include "mainMenuScene.h"
#include "newGameScene.h"
#include "gameScene.h";
#include "gameOverScene.h";

int main()
{	
	srand(time(NULL));

	Game _Game = Game::GetInstance();

	// Initialize Scenes
	MainMenuScene* mainMenuScene = new MainMenuScene("MainMenuScene");
	NewGameScene* newGameScene = new NewGameScene("NewGameScene");
	GameScene* gameScene = new GameScene("GameScene");
	GameOverScene* gameOverScene = new GameOverScene("GameOverScene");

	// Register Scenes
	_Game.GetSceneManager().RegisterScene(mainMenuScene);
	_Game.GetSceneManager().RegisterScene(newGameScene);
	_Game.GetSceneManager().RegisterScene(gameScene);
	_Game.GetSceneManager().RegisterScene(gameOverScene);

	_Game.GetSceneManager().PresentScene("MainMenuScene");

	// Delete Scenes
	delete mainMenuScene;
	delete newGameScene;
	delete gameScene;
	delete gameOverScene;

	return 0;
}

