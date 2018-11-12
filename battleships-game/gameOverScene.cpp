// Library Includes
#include <iostream>

// Local Includes
#include "game.h"
#include "gameOverScene.h"

GameOverScene::GameOverScene(std::string _SceneName) :
	Scene(_SceneName)
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::InitializeScene()
{
	// Inherit from base parent class
	Scene::InitializeScene();

	DisplayScene();
	GetUserKeyInput();
}

void GameOverScene::DisplayScene()
{
	// Inherit from base parent class
	Scene::DisplayScene();

	if (Game::GetInstance().GetTurnManager().GetCurrentTurnOrder() == ENEMY_TURN)
	{
		std::cout << "Congratulations, you won!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Too bad, you lost :(" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "The Game finsihed in " << Game::GetInstance().GetTurnManager().GetCurrentTurn() << " turns.";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Press 'Esc' key to return to the Main Menu.";
}

void GameOverScene::HandleUserKeyInput()
{
	// Inherit from base parent class
	Scene::HandleUserKeyInput();

	switch (GetKeyPressed())
	{
		case RETURN:
			break;
		default:
			break;
	}
}

void GameOverScene::ResetScene()
{
	// Inherit from base parent class
	Scene::ResetScene();
}
