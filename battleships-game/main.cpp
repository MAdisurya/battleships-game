// Library Includes
#include <iostream>
#include <string>

// Local Includes
#include "sceneManager.h"
#include "mainMenuScene.h"

using namespace std;

int main()
{
	SceneManager* sceneManager = new SceneManager();
	
	MainMenuScene* mainMenuScene = new MainMenuScene("MainMenuScene");

	int iTemp;
	cin >> iTemp;

	delete sceneManager;
	delete mainMenuScene;

	return 0;
}