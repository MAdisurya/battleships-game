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
	// if s_pGame is null, create a new instance of Game
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

TurnManager& Game::GetTurnManager()
{
	return *pTurnManager;
}

void Game::ExitGame()
{
	exit(0);
}
