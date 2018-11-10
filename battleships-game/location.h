#pragma once

// Library includes
#include <string>

class Location
{
public:
	// Constructor
	Location(int _x, int _y);
	// Deconstructor
	~Location();

	// Member functions
	void ResetLocation();

	// Getter methods
	int GetX() const;
	int GetY() const;
	bool IsOccupied() const;
	std::string GetSymbol() const;
	std::string GetShipName() const;

	// Setter methods
	void SetSymbol(std::string _Symbol);
	void SetShipName(std::string _ShipName);
	void SetOccupied(bool _Occupied);

private:
	// Member variables
	int x, y;
	bool m_Occupied = false;
	std::string m_Symbol = "-";
	std::string m_ShipName = "";
};

