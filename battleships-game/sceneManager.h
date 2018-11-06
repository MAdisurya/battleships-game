#pragma once

#ifndef _SCENEMANAGER_H__
#define _SCENEMANAGER_H__

// Library Includes
#include <string>
#include <vector>

// Local Includes
class Scene;

class SceneManager
{
public:
	// Constructors
	SceneManager();
	// Deconstructor
	~SceneManager();

	// Member Functions
	void PresentScene(std::string _SceneName);
	void RemoveCurrentScene();
	void RegisterScene(Scene *_pScene);

	// Getters
	std::string GetCurrentSceneName() const;

	// Setters
	void SetCurrentSceneName(std::string _SceneName);

private:
	// Member Variables
	std::vector<Scene*> m_RegisteredScenes;

	std::string m_CurrentSceneName;
};

#endif // _SCENEMANAGER_H__
