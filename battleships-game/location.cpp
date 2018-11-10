// Local Includes
#include "location.h"

Location::Location(int _x, int _y)
{
	x = _x;
	y = _y;
}

Location::~Location()
{
}

void Location::ResetLocation()
{
	m_Symbol = "-";
	m_ShipName = "";
	m_Occupied = false;
}

int Location::GetX() const
{
	return x;
}

int Location::GetY() const
{
	return y;
}

bool Location::IsOccupied() const
{
	return m_Occupied;
}

std::string Location::GetSymbol() const
{
	return m_Symbol;
}

std::string Location::GetShipName() const
{
	return m_ShipName;
}

void Location::SetOccupied(bool _Occupied)
{
	m_Occupied = _Occupied;
}

void Location::SetSymbol(std::string _Symbol)
{
	m_Symbol = _Symbol;
}

void Location::SetShipName(std::string _ShipName)
{
	m_ShipName = _ShipName;
}