#pragma once

#ifndef _NEWGAMESCENE_H__
#define _NEWGAMESCENE_H__

// Local Includes
#include "scene.h"
#include "board.h"

class NewGameScene : public Scene
{
public:
	// Constructor
	NewGameScene(std::string);
	// Deconstructor
	~NewGameScene();

	// Member functions
	virtual void InitializeScene() override;
	virtual void HandleUserInput() override;
	virtual void HandleUserKeyInput() override;

private:
	// Member variables
	Board* m_Board = new Board();
};

#endif // _NEWGAMESCENE_H__

