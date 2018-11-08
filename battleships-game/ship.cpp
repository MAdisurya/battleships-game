// Local Includes
#include "ship.h"

Ship::Ship(std::string _ShipName, std::string _ShipSymbol, int _ShipSize)
{
	m_ShipSize = _ShipSize;
	m_ShipSymbol = _ShipSymbol;
	m_ShipName = _ShipName;
}

Ship::~Ship()
{
}

std::vector<Location*> Ship::GetShipLocations() const
{
	return m_ShipLocations;
}

std::string Ship::GetShipSymbol() const
{
	return m_ShipSymbol;
}

std::string Ship::GetShipName() const
{
	return m_ShipName;
}

int Ship::GetShipSize() const
{
	return m_ShipSize;
}

bool Ship::IsPlaced() const
{
	return m_Placed;
}

void Ship::SetPlaced(bool _Placed)
{
	m_Placed = _Placed;
}