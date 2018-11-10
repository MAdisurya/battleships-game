// Library Includes
#include <string>
#include <vector>
#include <iostream>

// Local Includes
#include "sceneManager.h"
#include "scene.h"
#include "newGameScene.h"
#include "gameScene.h"

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
		}
	}
}

void SceneManager::RemoveCurrentScene()
{
	system("CLS");
}

void SceneManager::RefreshCurrentScene()
{
	RemoveCurrentScene();

	for (int i = 0; i < m_RegisteredScenes.size(); i++)
	{
		if (m_RegisteredScenes[i]->GetSceneName() == m_CurrentSceneName)
		{
			m_RegisteredScenes[i]->DisplayScene();
		}
	}
}

void SceneManager::RegisterScene(Scene *_pScene)
{
	m_RegisteredScenes.push_back(_pScene);
}

void SceneManager::ResetAllScenes()
{
	for (int i = 0; i < m_RegisteredScenes.size(); i++)
	{
		m_RegisteredScenes[i]->ResetScene();
	}
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
