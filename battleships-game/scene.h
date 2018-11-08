#pragma once

#ifndef _SCENE_H__
#define _SCENE_H__

// Library Includes
#include <string>

// Local Includes
#include "sceneManager.h"

// Key macros
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 13
#define KEY_ESC 27

enum KeyPressed { UP, DOWN, LEFT, RIGHT, RETURN, NO_KEY };

class Scene
{
public:
	// Constructors
	Scene(std::string _SceneName);
	// Deconstructor
	~Scene();

	// Member Functions
	virtual void InitializeScene();
	virtual void HandleUserInput();
	virtual void HandleUserKeyInput();
	bool CheckUserNumberInput(int _Input);

	// Getters
	void GetUserKeyInput();
	std::string GetSceneName() const;
	KeyPressed GetKeyPressed() const;

protected:
	// Member variables
	std::string m_SceneName;
	KeyPressed m_KeyPressed = NO_KEY;
	int m_UserNumberInput;
	int m_MaxInputOptions;
	
};

#endif // _SCENE_H__

