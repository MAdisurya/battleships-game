#pragma once

// Local Includes
#include "scene.h"

class GameOverScene : public Scene
{
public:
	// Constructor
	GameOverScene(std::string);
	// Deconstructor
	~GameOverScene();

	// Member functions
	virtual void InitializeScene() override;
	virtual void DisplayScene() override;
	virtual void HandleUserKeyInput() override;
	virtual void ResetScene() override;
};

