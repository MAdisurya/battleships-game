// Library includes
#include <string>
#include <conio.h>
#include <iostream>

// Local includes
#include "scene.h"
#include "game.h"

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

void Scene::HandleUserKeyInput()
{

}

void Scene::GetUserKeyInput()
{
	int c = 0;
	bool usingKeyInput = true;

	while (usingKeyInput)
	{
		c = 0;

		switch ((c = _getch()))
		{
			case KEY_UP:
				m_KeyPressed = UP;
				HandleUserKeyInput();
				break;
			case KEY_DOWN:
				m_KeyPressed = DOWN;
				HandleUserKeyInput();
				break;
			case KEY_LEFT:
				m_KeyPressed = LEFT;
				HandleUserKeyInput();
				break;
			case KEY_RIGHT:
				m_KeyPressed = RIGHT;
				HandleUserKeyInput();
				break;
			case KEY_RETURN:
				m_KeyPressed = RETURN;
				HandleUserKeyInput();
				break;
			case KEY_ESC:
				Game::GetInstance().GetSceneManager().PresentScene("MainMenuScene");
				usingKeyInput = false;
				break;
			default:
				m_KeyPressed = NO_KEY;
				break;
		}
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

KeyPressed Scene::GetKeyPressed() const
{
	return m_KeyPressed;
}