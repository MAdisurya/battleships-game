// Library Includes
#include <iostream>

// Local Includes
#include "newGameScene.h"
#include "game.h"

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

	m_Board->PresentBoard();
	m_Board->AllowKeyInputs();
	GetUserKeyInput();
}

void NewGameScene::HandleUserInput()
{
	// Inherit base HandleUserInput method from parent Scene class
	Scene::HandleUserInput();
}

void NewGameScene::HandleUserKeyInput()
{
	// Inherit base HandlUserKeyInput() from parent Scene class
	Scene::HandleUserKeyInput();

	int x = m_Board->GetSelectedLocationX();
	int y = m_Board->GetSelectedLocationY();
	Ship *pShip = nullptr;

	switch (GetKeyPressed())
	{
		case UP:
			m_Board->SetSelectedLocation(x, y - 10);
			break;
		case DOWN:
			m_Board->SetSelectedLocation(x, y + 10);
			break;
		case LEFT:
			m_Board->SetSelectedLocation(x - 1, y);
			break;
		case RIGHT:
			m_Board->SetSelectedLocation(x + 1, y);
			break;
		case RETURN:
			for (int i = 0; i < m_Board->GetShips().size(); i++)
			{
				if (m_Board->GetShips()[i]->IsPlaced())
				{
					continue;
				}
				pShip = m_Board->GetShips()[i];
			}

			if (pShip != nullptr && !m_Board->GetRegisteredLocations()[x+y]->IsOccupied())
			{
				m_Board->PlaceShip(pShip, m_Board->GetRegisteredLocations()[x + y]);
			}
			break;
		default:
			break;
	}
}