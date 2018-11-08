// Library Includes
#include <iostream>

// Local Includes
#include "board.h"
#include "location.h"
#include "game.h"

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
	for (int i = 1; i < m_RegisteredLocations.size() + 1; i++)
	{
		std::cout << " ";
		std::cout << m_RegisteredLocations[i-1]->GetSymbol();
		std::cout << " ";

		if (i % 10 == 0)
		{
			std::cout << std::endl;
		}
	}
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
				// Set the old selected location back to "+"
				m_RegisteredLocations[m_SelectedLocationX + m_SelectedLocationY]->SetSymbol("+");
			}

			m_SelectedLocationX = _X;
			m_SelectedLocationY = _Y;

			Game::GetInstance().GetSceneManager().RefreshCurrentScene();
		}
	}
}

void Board::PlaceShip(Ship *p_Ship, Location *p_Location)
{
	p_Ship->SetPlaced(true);

	for (int i = 0; i < p_Ship->GetShipSize(); i++)
	{
		// Vertical
		Location *pNewLocation = m_RegisteredLocations[m_SelectedLocationX + (m_SelectedLocationY + (i * 10))];

		// Horizontal
		// Location *pNewLocation = m_RegisteredLocations[(m_SelectedLocationX + i) + m_SelectedLocationY];

		p_Ship->GetShipLocations().push_back(pNewLocation);
		pNewLocation->SetSymbol(p_Ship->GetShipSymbol());
		pNewLocation->SetOccupied(true);
	}

	Game::GetInstance().GetSceneManager().RefreshCurrentScene();
}

std::vector<Location*> Board::GetRegisteredLocations() const
{
	return m_RegisteredLocations;
}

std::vector<Ship*> Board::GetShips() const
{
	return m_Ships;
}

int Board::GetSelectedLocationX() const
{
	return m_SelectedLocationX;
}

int Board::GetSelectedLocationY() const
{
	return m_SelectedLocationY;
}