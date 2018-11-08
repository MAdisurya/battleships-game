#pragma once

// Library Includes
#include <string>
#include <vector>

// Local Includes
#include "location.h"

class Ship
{
public:
	// Constructor
	Ship(std::string _ShipName, std::string _ShipSymbol, int _ShipSize);
	// Deconstructor
	~Ship();

	// Getter methods
	std::vector<Location*> GetShipLocations() const;
	std::string GetShipSymbol() const;
	std::string GetShipName() const;
	int GetShipSize() const;
	bool IsPlaced() const;

	// Setter methods
	void SetPlaced(bool _Placed);

private:
	// Member variables
	std::vector<Location*> m_ShipLocations;
	std::string m_ShipSymbol;
	std::string m_ShipName;
	int m_ShipSize;
	bool m_Placed = false;
};

