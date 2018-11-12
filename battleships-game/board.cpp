// Library Includes
#include <iostream>

// Local Includes
#include "board.h"
#include "location.h"
#include "game.h"
#include "scene.h"
#include "gameScene.h"

Board::Board()
{
	for (int i = 0; i < m_Height; i++)
	{
		for (int j = 0; j < m_Width; j++)
		{
			Location* newLocation = new Location(j, i);
			RegisterLocation(newLocation);
		}
	}

	// Patrol Boat
	m_Ships.push_back(new Ship("Patrol Boat", "P", 2));
	// Submarine
	m_Ships.push_back(new Ship("Submarine", "S", 3));
	// Destroyer
	m_Ships.push_back(new Ship("Destroyer", "D", 3));
	// Battleship
	m_Ships.push_back(new Ship("Battleship", "B", 4));
	// Aircraft Carrier
	m_Ships.push_back(new Ship("Aircraft Carrier", "A", 5));
}

Board::~Board()
{
}

void Board::AllowKeyInputs()
{
	m_AllowedKeyInputs = true;
}

void Board::RegisterLocation(Location *p_Location)
{
	m_RegisteredLocations.push_back(p_Location);
}

void Board::PresentBoard()
{
	// TF: Iteration Structure
	for (int i = 1; i < m_RegisteredLocations.size() + 1; i++)
	{
		std::cout << " ";
		std::cout << m_RegisteredLocations[i-1]->GetSymbol();
		std::cout << " ";

		// TF: Conditional Statement
		if (i % 10 == 0)
		{
			std::cout << std::endl;
		}
	}
}

void Board::Hide()
{
	for (int i = 0; i < m_RegisteredLocations.size(); i++)
	{
		m_RegisteredLocations[i]->SetSymbol("-");
	}
}

void Board::ResetBoard()
{
	for (int i = 0; i < m_RegisteredLocations.size(); i++)
	{
		m_RegisteredLocations[i]->ResetLocation();
	}

	for (int i = 0; i < m_Ships.size(); i++)
	{
		delete m_Ships[i];
	}

	m_Ships.clear();

	// Patrol Boat
	m_Ships.push_back(new Ship("Patrol Boat", "P", 2));
	// Submarine
	m_Ships.push_back(new Ship("Submarine", "S", 3));
	// Destroyer
	m_Ships.push_back(new Ship("Destroyer", "D", 3));
	// Battleship
	m_Ships.push_back(new Ship("Battleship", "B", 4));
	// Aircraft Carrier
	m_Ships.push_back(new Ship("Aircraft Carrier", "A", 5));

	m_SelectedLocationX = 0;
	m_SelectedLocationY = 0;
}

void Board::SetSelectedLocation(int _X, int _Y)
{
	if (m_AllowedKeyInputs)
	{
		if (_X >= 0 && _Y >= 0 && _X <= 9 && _Y <= 90)
		{
			if (!m_RegisteredLocations[_X + _Y]->IsOccupied())
			{
				// Set new selected location as "O"
				m_RegisteredLocations[_X + _Y]->SetSymbol("O");
			}
			
			if (!m_RegisteredLocations[m_SelectedLocationX + m_SelectedLocationY]->IsOccupied())
			{
				// Set the old selected location back to "-"
				m_RegisteredLocations[m_SelectedLocationX + m_SelectedLocationY]->SetSymbol("-");
			}

			m_SelectedLocationX = _X;
			m_SelectedLocationY = _Y;

			Game::GetInstance().GetSceneManager().RefreshCurrentScene();
		}
	}
}

void Board::ResetSelectedLocation()
{
	if (!m_RegisteredLocations[m_SelectedLocationX + m_SelectedLocationY]->IsOccupied())
	{
		m_RegisteredLocations[m_SelectedLocationX + m_SelectedLocationY]->SetSymbol("-");
	}

	m_SelectedLocationX = 0;
	m_SelectedLocationY = 0;
}

void Board::PlaceShip(Ship *p_Ship)
{
	if (CanPlace(p_Ship))
	{
		for (int i = 0; i < p_Ship->GetShipSize(); i++)
		{
			Location *pNewLocation = nullptr;

			if (m_CurrentRotation == VERTICAL)
			{
				// Vertical
				pNewLocation = m_RegisteredLocations[m_SelectedLocationX + (m_SelectedLocationY + (i * m_Height))];
			}
			else
			{
				// Horizontal
				pNewLocation = m_RegisteredLocations[(m_SelectedLocationX + i) + m_SelectedLocationY];
			}

			pNewLocation->SetSymbol(p_Ship->GetShipSymbol());
			pNewLocation->SetShipName(p_Ship->GetShipName());
			pNewLocation->SetOccupied(true);
			p_Ship->SetPlaced(true);
			p_Ship->RegisterShipLocation(pNewLocation);
		}

		Game::GetInstance().GetSceneManager().RefreshCurrentScene();
	}
}

void Board::RotatePlacement()
{
	if (m_CurrentRotation == VERTICAL)
	{
		m_CurrentRotation = HORIZONTAL;
	}
	else
	{
		m_CurrentRotation = VERTICAL;
	}
}

void Board::SetRandomRotation(int _Number)
{
	if (_Number == 0)
	{
		m_CurrentRotation = VERTICAL;
	}
	else
	{
		m_CurrentRotation = HORIZONTAL;
	}
}

void Board::Fire(Location *p_Location)
{
	if (p_Location->GetSymbol() != "X" && p_Location->GetSymbol() != "*")
	{
		if (p_Location->IsOccupied())
		{
			p_Location->SetSymbol("X");
			p_Location->SetOccupied(true);

			for (int i = 0; i < m_Ships.size(); i++)
			{
				if (m_Ships[i]->GetShipName() == p_Location->GetShipName())
				{
					m_Ships[i]->RemoveShipLocation(p_Location);
				}

				if (m_Ships[i]->IsDestroyed())
				{
					if (Game::GetInstance().GetTurnManager().GetCurrentTurnOrder() == ENEMY_TURN)
					{
						Game::GetInstance().GetSceneManager().GetSceneByName("GameScene")->DisplayMessage("Enemy Destroyed: " + m_Ships[i]->GetShipName());
					}
					else
					{
						Game::GetInstance().GetSceneManager().GetSceneByName("GameScene")->DisplayMessage("Player Destroyed: " + m_Ships[i]->GetShipName());
					}

					m_Ships.erase(m_Ships.begin() + i);
				}
			}

			if (m_Ships.size() <= 0)
			{
				Game::GetInstance().GetSceneManager().PresentScene("GameOverScene");
			}

			p_Location->SetShipName("");
		}
		else
		{
			p_Location->SetSymbol("*");
			p_Location->SetOccupied(true);
		}

		Game::GetInstance().GetSceneManager().RefreshCurrentScene();
		Game::GetInstance().GetTurnManager().NextTurn();
	}
}

bool Board::CanPlace(Ship *p_Ship)
{
	for (int i = 0; i < p_Ship->GetShipSize(); i++)
	{
		Location *pNewLocation = nullptr;

		if (m_CurrentRotation == VERTICAL)
		{
			// Vertical
			pNewLocation = m_RegisteredLocations[m_SelectedLocationX + (m_SelectedLocationY + (i * m_Height))];
		}
		else
		{
			// Horizontal
			pNewLocation = m_RegisteredLocations[(m_SelectedLocationX + i) + m_SelectedLocationY];
		}

		if (pNewLocation->IsOccupied())
		{
			return false;
		}

		if (m_CurrentRotation == HORIZONTAL)
		{
			if (pNewLocation->GetX() == (m_Height - p_Ship->GetShipSize()))
			{
				return true;
			}

			if(pNewLocation->GetX() >= m_Height - 1)
			{
				return false;
			}
		}
		else
		{
			if (pNewLocation->GetY() == (m_Width - p_Ship->GetShipSize()))
			{
				return true;
			}

			if (pNewLocation->GetY() >= m_Width - 1)
			{
				return false;
			}
		}
	}

	return true;
}

std::vector<Location*> Board::GetRegisteredLocations() const
{
	return m_RegisteredLocations;
}

std::vector<Ship*> Board::GetShips() const
{
	return m_Ships;
}

Rotation Board::GetCurrentRotation() const
{
	return m_CurrentRotation;
}

int Board::GetSelectedLocationX() const
{
	return m_SelectedLocationX;
}

int Board::GetSelectedLocationY() const
{
	return m_SelectedLocationY;
}

void Board::SetSelectedLocationX(int _LocationX)
{
	m_SelectedLocationX = _LocationX;
}

void Board::SetSelectedLocationY(int _LocationY)
{
	m_SelectedLocationY = _LocationY;
}