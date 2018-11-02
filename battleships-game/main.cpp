// Library Includes
#include <iostream>
#include <string>

// Local Includes
#include "sceneManager.h"
#include "mainMenuScene.h"
#include "game.h"

using namespace std;

int main()
{	
	Game _Game = Game::GetInstance();
	MainMenuScene* mainMenuScene = new MainMenuScene("MainMenuScene");

	mainMenuScene->RegisterScene(&_Game.GetSceneManager());
	_Game.GetSceneManager().GenerateScene("MainMenuScene");

	int iTemp;
	cin >> iTemp;

	delete mainMenuScene;

	return 0;
}