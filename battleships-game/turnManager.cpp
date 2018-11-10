// Library Includes
#include "turnManager.h"
#include "game.h"
#include "scene.h"
#include "gameScene.h"

TurnManager::TurnManager()
{
}

TurnManager::~TurnManager()
{
}

void TurnManager::NextTurn()
{
	m_CurrentTurn++;
	GameScene *pGameScene = static_cast<GameScene*>(Game::GetInstance().GetSceneManager().GetSceneByName("GameScene"));

	if (m_CurrentTurnOrder == PLAYER_TURN)
	{
		SetCurrentTurnOrder(ENEMY_TURN);
		pGameScene->GetEnemy().EnemyTurn(&pGameScene->GetPlayerBoard());
	}
	else
	{
		SetCurrentTurnOrder(PLAYER_TURN);
		pGameScene->GetUserKeyInput();
	}
}

TurnOrders TurnManager::GetCurrentTurnOrder() const
{
	return m_CurrentTurnOrder;
}

int TurnManager::GetCurrentTurn() const
{
	return m_CurrentTurn;
}

void TurnManager::SetCurrentTurnOrder(TurnOrders _TurnOrder)
{
	m_CurrentTurnOrder = _TurnOrder;
}
