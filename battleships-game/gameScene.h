#pragma once

// Local Includes
#include "scene.h"
#include "board.h"
#include "enemy.h"

class GameScene : public Scene
{
public:
	// Constructor
	GameScene(std::string);
	// Deconstructor
	~GameScene();

	// Member functions
	void InitializeScene() override;
	void HandleUserInput() override;
	void HandleUserKeyInput() override;

private:
	// Member variables
	Enemy * m_Enemy = new Enemy();
};

