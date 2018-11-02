// Library Includes
#include <string>
#include <vector>

// Local Includes
#include "sceneManager.h"
#include "scene.h";

// Constructor
SceneManager::SceneManager()
{
}

// Deconstructor
SceneManager::~SceneManager()
{
}

void SceneManager::GenerateScene(std::string _SceneName)
{
	for (int i = 0; i < m_RegisteredScenes.size(); i++)
	{
		if (m_RegisteredScenes[i]->GetSceneName() == _SceneName)
		{
			m_RegisteredScenes[i]->GenerateScene();
		}
	}
}

void SceneManager::RemoveCurrentScene()
{
	system("CLS");
}

void SceneManager::AddToRegisteredScenes(Scene *_pScene)
{
	m_RegisteredScenes.push_back(_pScene);
}

std::string SceneManager::GetCurrentSceneName() const
{
	return m_CurrentSceneName;
}

void SceneManager::SetCurrentSceneName(std::string _SceneName)
{
	m_CurrentSceneName = _SceneName;
}
