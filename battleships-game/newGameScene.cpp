// Library Includes
#include <iostream>

// Local Includes
#include "newGameScene.h"

NewGameScene::NewGameScene(std::string _SceneName) :
	Scene(_SceneName)
{
}

NewGameScene::~NewGameScene()
{
}

void NewGameScene::InitializeScene()
{
	// Inherit base InitializeScene method from parent Scene class
	Scene::InitializeScene();

	std::cout << "New Game." << std::endl;

	std::cout << std::endl;
}

void NewGameScene::HandleUserInput()
{
	// Inherit base HandleUserInput method from parent Scene class
	Scene::HandleUserInput();
}