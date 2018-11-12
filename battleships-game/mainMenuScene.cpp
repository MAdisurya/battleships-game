// Library Inlcludes
#include <iostream>
#include <string>

// Local Includes
#include "mainMenuScene.h"
#include "game.h"

// TF: Copy Constructor
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

	m_DisplayMessage = "Debug Mode OFF";
	DisplayScene();

	m_MaxInputOptions = 3;

	HandleUserInput();
}

void MainMenuScene::DisplayScene()
{
	std::cout << "Battleships." << std::endl;

	std::cout << std::endl;

	std::cout << "1) New Game" << std::endl;
	std::cout << "2) Exit Game" << std::endl;
	std::cout << "3) Toggle Debug Mode" << std::endl;

	std::cout << std::endl;

	std::cout << m_DisplayMessage << std::endl;

	std::cout << std::endl;

	std::cout << "Please enter a number from 1-3" << std::endl;
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
			Game::GetInstance().ToggleDebugMode();

			if (Game::GetInstance().GetDebugMode())
			{
				DisplayMessage("Debug Mode ON");
			}
			else
			{
				DisplayMessage("Debug Mode OFF");
			}

			Game::GetInstance().GetSceneManager().RefreshCurrentScene();
			HandleUserInput();
			break;
		default:
			break;
	}
}
