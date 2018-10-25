#pragma once

#ifndef _SCENE_H__
#define _SCENE_H__

// Library Includes
#include <string>

class Scene
{
public:
	// Constructors
	Scene(std::string _SceneName);
	// Deconstructor
	~Scene();

	// Member Functions
	std::string GetSceneName() const;

protected:
	std::string m_SceneName;
};

#endif // _SCENE_H__

