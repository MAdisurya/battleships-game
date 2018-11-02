// Library includes
#include <string>

// Local includes
#include "scene.h"

// Constructor
Scene::Scene(std::string _SceneName)
{
	m_SceneName = _SceneName;
}

// Deconstructor
Scene::~Scene()
{
}

void Scene::RegisterScene(SceneManager *_pSceneManager)
{
	_pSceneManager->AddToRegisteredScenes(this);
}

void Scene::GenerateScene()
{
	
}

std::string Scene::GetSceneName() const
{
	return m_SceneName;
}