#pragma once

// Local Includes
#include "sceneManager.h";

class Game
{
public:
	// Deconstructor
	~Game();

	// Member functions
	static Game& GetInstance();

	SceneManager& GetSceneManager();

private:
	// Constructor
	Game();

	// Member variables
	static Game* s_pGame;

	SceneManager *pSceneManager = new SceneManager();
};

