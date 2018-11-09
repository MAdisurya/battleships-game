// Local Includes
#include "enemy.h"

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
		
		while (!m_EnemyBoard->CanPlace(pShip))
		{
			randomNumberX = rand() % 10;
			randomNumberY = rand() % 10;
			randomRotation = rand() % 2;

			m_EnemyBoard->SetRandomRotation(randomRotation);
			m_EnemyBoard->SetSelectedLocationX(randomNumberX);
			m_EnemyBoard->SetSelectedLocationY(randomNumberY);
		}

		m_EnemyBoard->PlaceShip(pShip);
	}

	m_EnemyBoard->ResetSelectedLocation();
}

void Enemy::EnemyTurn(Board *p_PlayerBoard)
{
	int randomHit = rand() % 10;
	int randomShipX = rand() % 10;
	int randomShipY = rand() % 10;

	if (randomHit <= 3)
	{
		for (int i = 0; i < p_PlayerBoard->GetShips().size(); i++)
		{
			/*if (p_PlayerBoard->GetShips()[i]->GetShipLocations())*/
		}
	}
}

Board* Enemy::GetEnemyBoard() const
{
	return m_EnemyBoard;
}
