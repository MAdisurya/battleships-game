// Library Includes
#include <iostream>

// Local Includes
#include "newGameScene.h"
#include "board.h"

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

	Board* board = new Board();

	std::cout << "New Game." << std::endl;
	std::cout << std::endl;

	board->PresentBoard();
}

void NewGameScene::HandleUserInput()
{
	// Inherit base HandleUserInput method from parent Scene class
	Scene::HandleUserInput();
}