#pragma once

#ifndef _MAINMENUSCENE_H__
#define _MAINMENUSCENE_H__

// Local Includes
#include "scene.h"

class MainMenuScene : public Scene
{
public:
	// Constructor
	MainMenuScene(std::string);
	// Deconstructor
	~MainMenuScene();

	// Member functions
	virtual void GenerateScene() override;
};

#endif // _MAINMENUSCENE_H__

