// Library Includes
#include <string>
#include <vector>
#include <iostream>

// Local Includes
#include "sceneManager.h"
#include "scene.h"

// Constructor
SceneManager::SceneManager()
{
}

// Deconstructor
SceneManager::~SceneManager()
{
}

void SceneManager::PresentScene(std::string _SceneName)
{
	RemoveCurrentScene();

	for (int i = 0; i < m_RegisteredScenes.size(); i++)
	{
		if (m_RegisteredScenes[i]->GetSceneName() == _SceneName)
		{
			SetCurrentSceneName(_SceneName);
			m_RegisteredScenes[i]->InitializeScene();
			m_RegisteredScenes[i]->HandleUserInput();
		}
	}
}

void SceneManager::RemoveCurrentScene()
{
	system("CLS");
}

void SceneManager::RefreshCurrentScene()
{
	PresentScene(m_CurrentSceneName);
}

void SceneManager::RegisterScene(Scene *_pScene)
{
	m_RegisteredScenes.push_back(_pScene);
}

std::string SceneManager::GetCurrentSceneName() const
{
	return m_CurrentSceneName;
}

Scene* SceneManager::GetSceneByName(std::string _SceneName) const
{
	for (int i = 0; i < m_RegisteredScenes.size(); i++)
	{
		if (m_RegisteredScenes[i]->GetSceneName() == _SceneName)
		{
			return m_RegisteredScenes[i];
		}
	}
}

void SceneManager::SetCurrentSceneName(std::string _SceneName)
{
	m_CurrentSceneName = _SceneName;
}
