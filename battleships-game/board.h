#pragma once

// Library Includes
#include <vector>

// Local Includes
class Location;

class Board
{
public:
	// Constructor
	Board();
	// Deconstructor
	~Board();

	// Member Functions
	void RegisterLocation(Location *p_Location);
	void PresentBoard();

private:
	// Member variables
	std::vector<Location*> m_RegisteredLocations;

	const int m_Width = 10;
	const int m_Height = 10;
};

