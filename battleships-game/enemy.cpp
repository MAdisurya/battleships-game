// Library Includes
#include <iostream>

// Local Includes
#include "enemy.h"
#include "game.h"
#include "scene.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::PlaceShips()
{
	int randomNumberX = rand() % 10;
	int randomNumberY = rand() % 10;
	int randomRotation = rand() % 2;
	Ship *pShip = nullptr;

	for (int i = 0; i < m_EnemyBoard->GetShips().size(); i++)
	{
		pShip = m_EnemyBoard->GetShips()[i];
		randomRotation = rand() % 2;
		m_EnemyBoard->SetRandomRotation(randomRotation);

		while (!m_EnemyBoard->CanPlace(pShip))
		{
			randomNumberX = rand() % 10;
			randomNumberY = rand() % 10;

			m_EnemyBoard->SetSelectedLocationX(randomNumberX);
			m_EnemyBoard->SetSelectedLocationY(randomNumberY);
		}

		m_EnemyBoard->PlaceShip(pShip);
	}

	m_EnemyBoard->ResetSelectedLocation();
}

void Enemy::EnemyTurn(Board *p_PlayerBoard)
{
	// TF: Pseudo random numbers
	int randomHit = rand() % 10;
	int randomShip;
	int randomX = rand() % 10;
	int randomY = rand() % 10;

	if (p_PlayerBoard->GetShips().size() <= 1)
	{
		randomShip = 0;
	}
	else
	{
		randomShip = rand() % p_PlayerBoard->GetShips().size();
	}

	if (randomHit <= 3 && p_PlayerBoard->GetShips().size() > 0)
	{
		Ship* pPlayerShip = p_PlayerBoard->GetShips()[randomShip];

		for (int i = 0; i < pPlayerShip->GetShipLocations().size(); i++)
		{	
			p_PlayerBoard->Fire(pPlayerShip->GetShipLocations()[i]);
		}
	}
	else
	{
		while (p_PlayerBoard->GetRegisteredLocations()[randomX + (randomY * 10)]->IsOccupied())
		{
			randomX = rand() % 10;
			randomY = rand() % 10;
		}
		p_PlayerBoard->Fire(p_PlayerBoard->GetRegisteredLocations()[randomX + (randomY * 10)]);
	}
}

Board* Enemy::GetEnemyBoard() const
{
	return m_EnemyBoard;
}
