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

std::string Scene::GetSceneName() const
{
	return m_SceneName;
}