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
	int GetX();
	int GetY();
	std::string GetSymbol();

	// Setter methods
	void SetSymbol(std::string _Symbol);

private:
	// Member variables
	int x, y;
	std::string m_Symbol = "+";
};

