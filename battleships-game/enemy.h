#pragma once

// Local Includes
#include "board.h"

class Enemy
{
public:
	// Constructor
	Enemy();
	// Deconstructor
	~Enemy();

	// Member functions
	void PlaceShips();
	void EnemyTurn(Board *p_PlayerBoard);

	// Getter methods
	Board* GetEnemyBoard() const;

private:
	// Member variables
	Board* m_EnemyBoard = new Board();
};

