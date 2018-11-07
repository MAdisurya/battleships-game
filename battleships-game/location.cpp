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

int Location::GetX()
{
	return x;
}

int Location::GetY()
{
	return y;
}

std::string Location::GetSymbol()
{
	return m_Symbol;
}

void Location::SetSymbol(std::string _Symbol)
{
	m_Symbol = _Symbol;
}