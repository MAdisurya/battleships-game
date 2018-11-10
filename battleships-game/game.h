#pragma once

// Local Includes
#include "sceneManager.h"
#include "turnManager.h"

class Game
{
public:
	// Deconstructor
	~Game();

	// Member functions
	static Game& GetInstance();
	SceneManager& GetSceneManager();
	TurnManager& GetTurnManager();
	void ExitGame();

private:
	// Constructor
	Game();

	// Member variables
	static Game* s_pGame;

	SceneManager *pSceneManager = new SceneManager();
	TurnManager *pTurnManager = new TurnManager();
};

