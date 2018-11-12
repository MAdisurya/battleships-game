#pragma once

// Local Includes
#include "game.h"

Game* Game::s_pGame = nullptr;

// TF: Constructor
Game::Game()
{
}

// TF: Destructor
Game::~Game()
{
}

bool Game::GetDebugMode() const
{
	return m_DebugMode;
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

void Game::ToggleDebugMode()
{
	m_DebugMode = !m_DebugMode;
}

void Game::ExitGame()
{
	exit(0);
}

void Game::SetDebugMode(bool _DebugMode)
{
	m_DebugMode = _DebugMode;
}
