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

	// Getter methods
	int GetX() const;
	int GetY() const;
	bool IsOccupied() const;
	std::string GetSymbol() const;

	// Setter methods
	void SetSymbol(std::string _Symbol);
	void SetOccupied(bool _Occupied);

private:
	// Member variables
	int x, y;
	bool m_Occupied = false;
	std::string m_Symbol = "+";
};

