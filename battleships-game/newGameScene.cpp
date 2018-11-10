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

	m_DisplayMessage = "Current Rotation: Vertical";
	SetUsingKeyInput(true);

	m_Board->AllowKeyInputs();

	DisplayScene();
}

void NewGameScene::DisplayScene()
{
	std::cout << "Place your ships!" << std::endl;
	std::cout << std::endl;

	m_Board->PresentBoard();

	std::cout << std::endl;
	std::cout << m_DisplayMessage << std::endl;

	std::cout << std::endl;
	std::cout << "Press 'Arrow keys' to move target" << std::endl;
	std::cout << "Press 'Spacebar' to change rotation" << std::endl;
	std::cout << "Press 'Enter' or 'Return' to place ship" << std::endl;
	std::cout << "Press 'Escape' to return to the main menu" << std::endl;
	std::cout << std::endl;
	std::cout << "Press 'Enter' or 'Return' after all ships have been placed!" << std::endl;
	std::cout << std::endl;

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

	for (int i = 0; i < m_Board->GetShips().size(); i++)
	{
		if (m_Board->GetShips()[i]->IsPlaced())
		{
			continue;
		}
		pShip = m_Board->GetShips()[i];
	}

	switch (GetKeyPressed())
	{
		case UP:
			m_Board->SetSelectedLocation(x, y - 10);
			x = m_Board->GetSelectedLocationX();
			y = m_Board->GetSelectedLocationY();
			break;
		case DOWN:
			m_Board->SetSelectedLocation(x, y + 10);
			x = m_Board->GetSelectedLocationX();
			y = m_Board->GetSelectedLocationY();
			break;
		case LEFT:
			m_Board->SetSelectedLocation(x - 1, y);
			x = m_Board->GetSelectedLocationX();
			y = m_Board->GetSelectedLocationY();
			break;
		case RIGHT:
			m_Board->SetSelectedLocation(x + 1, y);
			x = m_Board->GetSelectedLocationX();
			y = m_Board->GetSelectedLocationY();
			break;
		case SPACE:
			m_Board->RotatePlacement();

			if (m_Board->GetCurrentRotation() == HORIZONTAL)
			{
				DisplayMessage("Current Rotation: Horizontal");
			}
			else
			{
				DisplayMessage("Current Rotation: Vertical");
			}

			break;
		case RETURN:
			if (pShip != nullptr && !m_Board->GetRegisteredLocations()[x+y]->IsOccupied())
			{
				m_Board->PlaceShip(pShip);
			}
			else if (pShip == nullptr)
			{
				SetUsingKeyInput(false);
				m_Board->ResetSelectedLocation();
				Game::GetInstance().GetSceneManager().GetSceneByName("GameScene")->SetPlayerBoard(m_Board);
				Game::GetInstance().GetSceneManager().PresentScene("GameScene");
			}

			break;
		default:
			break;
	}
}

void NewGameScene::ResetScene()
{
	// Inherit function from base parent
	Scene::ResetScene();

	m_Board->ResetBoard();
}