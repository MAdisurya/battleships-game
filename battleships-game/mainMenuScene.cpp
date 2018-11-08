// Library Inlcludes
#include <iostream>
#include <string>

// Local Includes
#include "mainMenuScene.h"
#include "game.h"

MainMenuScene::MainMenuScene(std::string _SceneName)
	: Scene(_SceneName)
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::InitializeScene()
{
	// Inherit base InitializeScene method from parent Scene class
	Scene::InitializeScene();

	std::cout << "Battleships." << std::endl;

	std::cout << std::endl;

	std::cout << "1) New Game" << std::endl;
	std::cout << "2) Exit Game" << std::endl;
	std::cout << "3) Credits" << std::endl;

	m_MaxInputOptions = 3;
}

void MainMenuScene::HandleUserInput()
{
	// Inherit base HandleUserInput method from parent Scene class
	Scene::HandleUserInput();

	switch (m_UserNumberInput)
	{
		case 1:
			Game::GetInstance().GetSceneManager().PresentScene("NewGameScene");
			break;
		case 2:
			Game::GetInstance().ExitGame();
			break;
		case 3:
			std::cout << "Credits!" << std::endl;
			break;
		default:
			break;
	}
}
