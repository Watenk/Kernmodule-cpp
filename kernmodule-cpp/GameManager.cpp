
#include <iostream>

#include "GameManager.h"

using std::to_string;

GameManager::GameManager(sf::RenderWindow* window) : window(window) {

	//Initialize Managers
	fontManager = new FontManager();
	inputs = new Inputs(this);
	sceneManager = new SceneManager(this);
	textureManager = new TextureManager();
	timeManager = new TimeManager();
	collisionManager = new CollisionManager(this);

	//Add Managers to BaseClassList
	addBaseClass(inputs);
	addBaseClass(timeManager);
	addBaseClass(collisionManager);

	//LoadScene
	sceneManager->switchScene("Lvl01");
}

void GameManager::update() {
	updateUps();

	//Update all baseclasses
	for (list<BaseClass*>::iterator it = baseClassList.begin(); it != baseClassList.end(); it++) {
		BaseClass* currentObject = *it;
		currentObject->update();
	}

	//Update all PhysicsObjects
	for (list<PhysicsObject*>::iterator it = physicsObjectList.begin(); it != physicsObjectList.end(); it++) {
		PhysicsObject* currentObject = *it;
		currentObject->update();
	}

	window->draw(getText("LowestFrame: " + to_string(timeManager->lowestFrame), watenk::Vector2(0, 0)));
}

void GameManager::ups() {

	//Update all baseclasses
	for (list<BaseClass*>::iterator it = baseClassList.begin(); it != baseClassList.end(); it++) {
		BaseClass* curentObject = *it;
		curentObject->ups();
	}

	//Update all PhysicsObjects
	for (list<PhysicsObject*>::iterator it = physicsObjectList.begin(); it != physicsObjectList.end(); it++) {
		PhysicsObject* currentObject = *it;
		currentObject->ups();
	}
}

void GameManager::addBaseClass(BaseClass* newBaseClass) {
	newBaseClass->start();
	baseClassList.push_back(newBaseClass);
}

void GameManager::removeBaseClass(BaseClass* newBaseClass) {
	baseClassList.remove(newBaseClass);
	delete newBaseClass;
}

void GameManager::addPhysicsObject(PhysicsObject* newPhysicsObject) {
	newPhysicsObject->start();
	physicsObjectList.push_back(newPhysicsObject);
}

void GameManager::removePhysicsObject(PhysicsObject* newPhysicsObject) {
	physicsObjectList.remove(newPhysicsObject);
	delete newPhysicsObject;
}

void GameManager::updateUps() {
	upsDeltaTime += timeManager->deltaTime;
	if (upsDeltaTime >= 1) {
	    upsDeltaTime = 0;
	    ups();
	}
}

sf::Text GameManager::getText(string string, watenk::Vector2 pos) {
	sf::Text text;
	text.setFont(fontManager->oswaldMedium);
	text.setString(string);
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::White);
	text.setPosition(pos.convertToSFML());
	return text;
}