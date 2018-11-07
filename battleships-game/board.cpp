// Library Includes
#include <iostream>

// Local Includes
#include "board.h"
#include "location.h"

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
}

Board::~Board()
{
}

void Board::RegisterLocation(Location *p_Location)
{
	m_RegisteredLocations.push_back(p_Location);
}

void Board::PresentBoard()
{
	for (int i = 1; i < m_RegisteredLocations.size() + 1; i++)
	{
		std::cout << m_RegisteredLocations[i-1]->GetSymbol();
		std::cout << "  ";

		if (i % 10 == 0)
		{
			std::cout << std::endl << std::endl;
		}
	}
}