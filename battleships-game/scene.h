#pragma once

#ifndef _SCENE_H__
#define _SCENE_H__

// Library Includes
#include <string>

// Local Includes
#include "sceneManager.h"
#include "board.h"

// Key macros
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_RETURN 13
#define KEY_ESC 27

enum KeyPressed { UP, DOWN, LEFT, RIGHT, SPACE, RETURN, NO_KEY };

class Scene
{
public:
	// Constructors
	Scene(std::string _SceneName);
	// Deconstructor
	~Scene();

	// Member Functions
	virtual void InitializeScene();
	virtual void DisplayScene();
	virtual void HandleUserInput();
	virtual void HandleUserKeyInput();
	virtual void ResetScene();
	void DisplayMessage(std::string _Message);
	void GetUserKeyInput();
	bool CheckUserNumberInput(int _Input);

	// Getters
	Board& GetPlayerBoard();
	bool UsingKeyInput() const;
	std::string GetSceneName() const;
	KeyPressed GetKeyPressed() const;

	// Setters
	void SetPlayerBoard(Board *p_PlayerBoard);
	void SetUsingKeyInput(bool _Using);

protected:
	// Member variables
	std::string m_SceneName;
	std::string m_DisplayMessage = "";
	Board *m_pPlayerBoard = nullptr;
	KeyPressed m_KeyPressed = NO_KEY;
	int m_UserNumberInput;
	int m_MaxInputOptions;
	bool m_UsingKeyInput = false;
};

#endif // _SCENE_H__

