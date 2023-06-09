#pragma once

#include <SFML/Graphics.hpp>
#include <list>

#include "BaseClass.h"

#include "SceneManager.h"
#include "FontManager.h"
#include "Inputs.h"
#include "CollisionManager.h"
#include "TextureManager.h"
#include "TimeManager.h"
#include "Vector2.h"

using std::list;

class GameManager {
public:
	GameManager(sf::RenderWindow* window);
	void update();
	void ups();
	void addBaseClass(BaseClass* newBaseClass);
	void removeBaseClass(BaseClass* newBaseClass);
	void addPhysicsObject(PhysicsObject* newPhysicsObject);
	void removePhysicsObject(PhysicsObject* newPhysicsObject);
	void removeAllPhysicsObjects();

	sf::RenderWindow* window;
	Inputs* inputs;
	FontManager* fontManager;
	TextureManager* textureManager;
	TimeManager* timeManager;

	list<PhysicsObject*> physicsObjectList;

private:
	void updateUps();
	sf::Text getText(string string, watenk::Vector2 pos);

	list<BaseClass*> baseClassList;

	CollisionManager* collisionManager;
	SceneManager* sceneManager;

	float upsDeltaTime = 0;
};