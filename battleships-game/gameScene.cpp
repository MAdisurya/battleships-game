// Library Includes
#include <iostream>

// Local Includes
#include "gameScene.h"
#include "game.h"

GameScene::GameScene(std::string _SceneName) : 
	Scene(_SceneName)
{
	
}

GameScene::~GameScene()
{
}

void GameScene::InitializeScene()
{
	// Inherit from base class
	Scene::InitializeScene();

	m_Enemy->PlaceShips();
	m_Enemy->GetEnemyBoard()->AllowKeyInputs();
	m_DisplayMessage = "Players Turn.";
	SetUsingKeyInput(true);
	DisplayScene();

	GetUserKeyInput();
}

void GameScene::DisplayScene()
{
	std::cout << "Player Battleship Board:" << std::endl;
	std::cout << std::endl;
	m_pPlayerBoard->PresentBoard();

	std::cout << std::endl;

	std::cout << "Enemy Battleship Board:" << std::endl;
	std::cout << std::endl;

	m_Enemy->GetEnemyBoard()->PresentBoard();
	
	std::cout << std::endl;
	std::cout << m_DisplayMessage << std::endl;
	std::cout << std::endl;

	std::cout << "Press 'Arrow keys' to move and 'Enter' to fire!" << std::endl;
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
			GetUserKeyInput();
			break;
		case DOWN:
			m_Enemy->GetEnemyBoard()->SetSelectedLocation(x, y + 10);
			x = m_Enemy->GetEnemyBoard()->GetSelectedLocationX();
			y = m_Enemy->GetEnemyBoard()->GetSelectedLocationY();
			GetUserKeyInput();
			break;
		case LEFT:
			m_Enemy->GetEnemyBoard()->SetSelectedLocation(x - 1, y);
			x = m_Enemy->GetEnemyBoard()->GetSelectedLocationX();
			y = m_Enemy->GetEnemyBoard()->GetSelectedLocationY();
			GetUserKeyInput();
			break;
		case RIGHT:
			m_Enemy->GetEnemyBoard()->SetSelectedLocation(x + 1, y);
			x = m_Enemy->GetEnemyBoard()->GetSelectedLocationX();
			y = m_Enemy->GetEnemyBoard()->GetSelectedLocationY();
			GetUserKeyInput();
			break;
		case RETURN:
			m_Enemy->GetEnemyBoard()->Fire(m_Enemy->GetEnemyBoard()->GetRegisteredLocations()[x + y]);
			break;
		default:
			break;
	}
}

void GameScene::ResetScene()
{
	// Inherit function from base parent
	Scene::ResetScene();

	m_Enemy->GetEnemyBoard()->ResetBoard();
}

Enemy& GameScene::GetEnemy()
{
	return *m_Enemy;
}
