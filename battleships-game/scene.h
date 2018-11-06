#pragma once

#ifndef _SCENE_H__
#define _SCENE_H__

// Library Includes
#include <string>

// Local Includes
#include "sceneManager.h"

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
	bool CheckUserNumberInput(int _Input);

	// Getters
	std::string GetSceneName() const;

protected:
	// Member variables
	std::string m_SceneName;
	int m_UserNumberInput;
	int m_MaxInputOptions;
};

#endif // _SCENE_H__

