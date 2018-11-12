// Local Includes
#include "ship.h"
#include "game.h"
#include "scene.h"

Ship::Ship(std::string _ShipName, std::string _ShipSymbol, int _ShipSize)
{
	m_ShipSize = _ShipSize;
	m_ShipSymbol = _ShipSymbol;
	m_ShipName = _ShipName;
}

Ship::~Ship()
{
}

void Ship::RegisterShipLocation(Location *p_Location)
{
	m_ShipLocations.push_back(p_Location);
}

void Ship::RemoveShipLocation(Location *p_Location)
{
	for (int i = 0; i < m_ShipLocations.size(); i++)
	{
		if (m_ShipLocations[i]->GetX() == p_Location->GetX() && m_ShipLocations[i]->GetY() == p_Location->GetY())
		{
			m_ShipLocations.erase(m_ShipLocations.begin()+i);
		}
	}
}

void Ship::ResetShip()
{
	m_Placed = false;
	m_Destroyed = false;
	m_ShipLocations.clear();
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

bool Ship::IsDestroyed() const
{
	return m_ShipLocations.size() <= 0;
}

void Ship::SetPlaced(bool _Placed)
{
	m_Placed = _Placed;
}