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

void Location::SetOccupied(bool _Occupied)
{
	m_Occupied = _Occupied;
}

void Location::SetSymbol(std::string _Symbol)
{
	m_Symbol = _Symbol;
}