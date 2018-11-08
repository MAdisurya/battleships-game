#pragma once

// Library Includes
#include <vector>

// Local Includes
#include "ship.h"
class Location;

class Board
{
public:
	// Constructor
	Board();
	// Deconstructor
	~Board();

	// Member Functions
	void AllowKeyInputs();
	void RegisterLocation(Location *p_Location);
	void PresentBoard();
	void SetSelectedLocation(int _X, int _Y);
	void PlaceShip(Ship *p_Ship, Location *p_Location);

	// Getter methods
	std::vector<Location*> GetRegisteredLocations() const;
	std::vector<Ship*> GetShips() const;
	int GetSelectedLocationX() const;
	int GetSelectedLocationY() const;

private:
	// Member variables
	std::vector<Location*> m_RegisteredLocations;
	std::vector<Ship*> m_Ships;
	bool m_AllowedKeyInputs = false;

	int m_SelectedLocationX = 0;
	int m_SelectedLocationY = 0;
	const int m_Width = 10;
	const int m_Height = 10;
};

