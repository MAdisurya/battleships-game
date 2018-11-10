#pragma once

enum TurnOrders { PLAYER_TURN, ENEMY_TURN };

class TurnManager
{
public:
	// Constructor
	TurnManager();
	// Deconstructor
	~TurnManager();

	// Member functions
	void NextTurn();

	// Getter methods
	TurnOrders GetCurrentTurnOrder() const;
	int GetCurrentTurn() const;

	// Setter methods
	void SetCurrentTurnOrder(TurnOrders _TurnOrder);

private:
	// Member variables
	TurnOrders m_CurrentTurnOrder = PLAYER_TURN;
	int m_CurrentTurn = 1;
};

