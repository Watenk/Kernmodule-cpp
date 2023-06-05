#pragma once

#include <SFML/Graphics.hpp>
#include <list>

#include "BaseClass.h"

#include "SceneManager.h"
#include "FontManager.h"
#include "Inputs.h"
#include "PhysicsManager.h"
#include "TextureManager.h"
#include "TimeManager.h"

using std::list;

class GameManager {
public:
	GameManager(sf::RenderWindow* window);
	void update();
	void ups();
	void addBaseClass(BaseClass* newBaseClass);
	void removeBaseClass(BaseClass* newBaseClass);

private:
	void draw();
	void updateUps();
	sf::Text getFpsText();

	list<BaseClass*> baseClassList;
	sf::RenderWindow* window;
	FontManager* fontManager;
	Inputs* inputs;
	PhysicsManager* physicsManager;
	TextureManager* textureManager;
	TimeManager* timeManager;

	float upsDeltaTime = 0;
};