#pragma once

#ifndef _SCENEMANAGER_H__
#define _SCENEMANAGER_H__

// Library Includes
#include <string>

class SceneManager
{
public:
	// Constructors
	SceneManager();
	// Deconstructor
	~SceneManager();

	// Member Functions
	void GenerateScene(std::string _SceneName);
	void RemoveScene(std::string _SceneName);

	// Getters
	std::string GetCurrentSceneName() const;

	// Setters
	std::string SetCurrentSceneName(std::string _SceneName);

private:
	// Member Variables
	std::string m_CurrentSceneName;
};

#endif // _SCENEMANAGER_H__
