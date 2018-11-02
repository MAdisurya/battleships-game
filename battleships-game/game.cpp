#include "game.h"

Game* Game::s_pGame = nullptr;

Game::Game()
{
}

Game::~Game()
{
}

Game& Game::GetInstance()
{
	if (s_pGame == nullptr)
	{
		s_pGame = new Game();
	}

	return *s_pGame;
}

SceneManager& Game::GetSceneManager()
{
	return *pSceneManager;
}
