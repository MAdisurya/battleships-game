// Library Includes
#include <iostream>
#include <string>

// Local Includes
#include "game.h"
#include "sceneManager.h"
#include "mainMenuScene.h"
#include "newGameScene.h"

int main()
{	
	Game _Game = Game::GetInstance();

	// Initialize Scenes
	MainMenuScene* mainMenuScene = new MainMenuScene("MainMenuScene");
	NewGameScene* newGameScene = new NewGameScene("NewGameScene");

	// Register Scenes
	_Game.GetSceneManager().RegisterScene(mainMenuScene);
	_Game.GetSceneManager().RegisterScene(newGameScene);

	_Game.GetSceneManager().PresentScene("MainMenuScene");

	int iTemp;
	std::cin >> iTemp;

	delete mainMenuScene;

	return 0;
}

