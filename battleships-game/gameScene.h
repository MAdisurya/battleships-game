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
	virtual void InitializeScene() override;
	virtual void DisplayScene() override;
	virtual void HandleUserInput() override;
	virtual void HandleUserKeyInput() override;
	virtual void ResetScene() override;

	// Getter methods
	Enemy& GetEnemy();

private:
	// Member variables
	Enemy* m_Enemy = new Enemy();
};

