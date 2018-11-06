// Library includes
#include <string>
#include <iostream>

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

void Scene::InitializeScene()
{
}

void Scene::HandleUserInput()
{
	// Get the user input
	std::cin >> m_UserNumberInput;

	// Check if input is valid
	if (!CheckUserNumberInput(m_UserNumberInput) || !std::cin)
	{
		std::cout << "Please enter a valid input" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		HandleUserInput();
	}
}

bool Scene::CheckUserNumberInput(int _Input)
{
	if (_Input < 1)
	{
		return false;
	}
	 
	if (_Input > m_MaxInputOptions)
	{
		return false;
	}

	return true;
}

std::string Scene::GetSceneName() const
{
	return m_SceneName;
}