// Library Inlcludes
#include <iostream>
#include <string>

// Local Includes
#include "mainMenuScene.h"

MainMenuScene::MainMenuScene(std::string _SceneName)
	: Scene(_SceneName)
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::GenerateScene()
{
	// Inherit base GenerateScene method from Scene
	Scene::GenerateScene();

	std::cout << "Battleships." << std::endl;

	std::cout << std::endl;

	std::cout << "1) New Game" << std::endl;
	std::cout << "2) Exit Game" << std::endl;
}
