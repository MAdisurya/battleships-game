#pragma once

// Local Includes
#include "sceneManager.h"
#include "turnManager.h"

// TF: Class
class Game
{
	// TF: Public Access specifier
public:
	// Deconstructor
	~Game();

	// Member functions
	void ExitGame();
	void ToggleDebugMode();

	// Getter methods
	// TF: Constant
	bool GetDebugMode() const;
	static Game& GetInstance();
	SceneManager& GetSceneManager();
	TurnManager& GetTurnManager();

	// Setter methods
	void SetDebugMode(bool _DebugMode);

	// TF: Private Access specifier
private:
	// Constructor
	Game();

	// Member variables
	// TF: Pointer Initialised
	static Game* s_pGame;
	bool m_DebugMode = false;

	// TF: Class Instance
	SceneManager *pSceneManager = new SceneManager();
	TurnManager *pTurnManager = new TurnManager();
};

