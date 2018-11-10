#pragma once

// Library Includes
#include <vector>

// Local Includes
#include "ship.h"
class Location;

enum Rotation { VERTICAL, HORIZONTAL };

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
	void MakeInvisible();
	void SetSelectedLocation(int _X, int _Y);
	void ResetSelectedLocation();
	void PlaceShip(Ship *p_Ship);
	void RotatePlacement();
	void SetRandomRotation(int _Number);
	void Fire(Location *p_Location);
	void ResetBoard();
	bool CanPlace(Ship *p_Ship);

	// Getter methods
	std::vector<Location*> GetRegisteredLocations() const;
	std::vector<Ship*> GetShips() const;
	Rotation GetCurrentRotation() const;
	int GetSelectedLocationX() const;
	int GetSelectedLocationY() const;

	// Setter methods
	void SetSelectedLocationX(int _LocationX);
	void SetSelectedLocationY(int _LocationY);

private:
	// Member variables
	std::vector<Location*> m_RegisteredLocations;
	std::vector<Ship*> m_Ships;
	Rotation m_CurrentRotation = VERTICAL;
	bool m_AllowedKeyInputs = false;

	int m_SelectedLocationX = 0;
	int m_SelectedLocationY = 0;
	const int m_Width = 10;
	const int m_Height = 10;
};

