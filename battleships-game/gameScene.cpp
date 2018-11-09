// Library Includes
#include <iostream>

// Local Includes
#include "gameScene.h"

GameScene::GameScene(std::string _SceneName) : 
	Scene(_SceneName)
{
	m_Enemy->PlaceShips();
	m_DisplayMessage = "Players Turn.";
}

GameScene::~GameScene()
{
}

void GameScene::InitializeScene()
{
	// Inherit from base class
	Scene::InitializeScene();

	std::cout << "Player Battleship Board:" << std::endl;
	std::cout << std::endl;
	m_pPlayerBoard->MakeInvisible();
	m_pPlayerBoard->PresentBoard();

	std::cout << std::endl;

	std::cout << "Enemy Battleship Board:" << std::endl;
	std::cout << std::endl;
	
	m_Enemy->GetEnemyBoard()->PresentBoard();
	m_Enemy->GetEnemyBoard()->AllowKeyInputs();

	std::cout << std::endl;
	std::cout << m_DisplayMessage << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Press 'Arrow keys' to move and 'Enter' to fire!" << std::endl;

	GetUserKeyInput();
}

void GameScene::HandleUserInput()
{
	// Inherit from base class
	Scene::HandleUserInput();
}

void GameScene::HandleUserKeyInput()
{
	// Inherit from base class
	Scene::HandleUserKeyInput();

	int x = m_Enemy->GetEnemyBoard()->GetSelectedLocationX();
	int y = m_Enemy->GetEnemyBoard()->GetSelectedLocationY();

	switch (GetKeyPressed())
	{
		case UP:
			m_Enemy->GetEnemyBoard()->SetSelectedLocation(x, y - 10);
			x = m_Enemy->GetEnemyBoard()->GetSelectedLocationX();
			y = m_Enemy->GetEnemyBoard()->GetSelectedLocationY();
			break;
		case DOWN:
			m_Enemy->GetEnemyBoard()->SetSelectedLocation(x, y + 10);
			x = m_Enemy->GetEnemyBoard()->GetSelectedLocationX();
			y = m_Enemy->GetEnemyBoard()->GetSelectedLocationY();
			break;
		case LEFT:
			m_Enemy->GetEnemyBoard()->SetSelectedLocation(x - 1, y);
			x = m_Enemy->GetEnemyBoard()->GetSelectedLocationX();
			y = m_Enemy->GetEnemyBoard()->GetSelectedLocationY();
		case RIGHT:
			m_Enemy->GetEnemyBoard()->SetSelectedLocation(x + 1, y);
			x = m_Enemy->GetEnemyBoard()->GetSelectedLocationX();
			y = m_Enemy->GetEnemyBoard()->GetSelectedLocationY();
		case RETURN:
			m_Enemy->GetEnemyBoard()->Fire(m_Enemy->GetEnemyBoard()->GetRegisteredLocations()[x + y]);
			m_Enemy->EnemyTurn(m_pPlayerBoard);
			break;
		default:
			break;
	}
}
