
#include <iostream>

#include "GameManager.h"

using std::to_string;

GameManager::GameManager(sf::RenderWindow* window) : window(window) {

	//Initialize Managers
	fontManager = new FontManager();
	inputs = new Inputs(this);
	textureManager = new TextureManager();
	timeManager = new TimeManager();
	collisionManager = new CollisionManager(this);
	sceneManager = new SceneManager(this);
	fileManager = new FileManager();

	//Add Managers to BaseClassList
	addBaseClass(inputs);
	addBaseClass(timeManager);
	addBaseClass(collisionManager);
	addBaseClass(sceneManager);

	//LoadScene
	sceneManager->loadScene("MainMenu");
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

	window->draw(fontManager->getText("LowestFrame: " + to_string(timeManager->lowestFrame), 15, sf::Color::White, watenk::Vector2(0, 0)));
}

void GameManager::ups() {

	//Update all baseclasses
	for (list<BaseClass*>::iterator it = baseClassList.begin(); it != baseClassList.end(); it++) {
		BaseClass* curentObject = *it;
		curentObject->ups();
	}

	//Delete Deleteable Physicsobjects
	list<PhysicsObject*>::iterator it = physicsObjectList.begin();
	while (it != physicsObjectList.end()) {
		PhysicsObject* currentObject = *it;
		if (currentObject->deleteObject) {
			delete *it;
			it = physicsObjectList.erase(it);
		}
		else {
			it++;
		}
	}

	//Update all PhysicsObjects
	for (list<PhysicsObject*>::iterator it = physicsObjectList.begin(); it != physicsObjectList.end(); it++) {
		PhysicsObject* currentObject = *it;
		currentObject->ups();
	}

	//Need to make this more efficient
	//Switch scene
	if (sceneManager->currentScene == "Lvl01" && killObjects == true) {
		killObjects = false;
		sceneManager->loadScene("GameOver");
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

void GameManager::removeAllPhysicsObjects() {

	list<PhysicsObject*>::iterator it = physicsObjectList.begin();
	while (it != physicsObjectList.end()) {
		delete *it;
		it = physicsObjectList.erase(it);
	}

	inputs->player = NULL;
}

void GameManager::updateUps() {
	upsupsTime += timeManager->upsTime;
	if (upsupsTime >= 1) {
	    upsupsTime = 0;
	    ups();
	}
}