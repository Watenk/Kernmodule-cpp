
#include <iostream>

#include "GameManager.h"

using std::to_string;

GameManager::GameManager(sf::RenderWindow* window) : window(window) {
	//Initialize Managers
	fontManager = new FontManager();
	textureManager = new TextureManager();
	timeManager = new TimeManager();

	//Add Managers to BaseClassList
	addBaseClass(timeManager);
}

void GameManager::update() {
	updateUps();

	//Update all baseclasses
	for (list<BaseClass*>::iterator it = baseClassList.begin(); it != baseClassList.end(); it++) {
		BaseClass* curentObject = *it;
		curentObject->update();
	}

	window->draw(getFpsText());
}

void GameManager::ups() {

	//physicsManager.update();
	
	//Update all baseclasses
	for (list<BaseClass*>::iterator it = baseClassList.begin(); it != baseClassList.end(); it++) {
		BaseClass* curentObject = *it;
		curentObject->ups();
	}
}

void GameManager::addBaseClass(BaseClass* newBaseClass) {
	newBaseClass->start();
	baseClassList.push_back(newBaseClass);
}

void GameManager::removeBaseClass(BaseClass* newBaseClass) {
	baseClassList.remove(newBaseClass);

	//Need to call destructor - MEMORY LEAK!!
}

void GameManager::draw() {
	//window->draw(baseClass)
}

void GameManager::updateUps() {
	upsDeltaTime += timeManager->deltaTime;
	if (upsDeltaTime >= 1) {
	    upsDeltaTime = 0;
	    ups();
	}
}

sf::Text GameManager::getFpsText() {
	sf::Text fpsText;
	fpsText.setFont(fontManager->oswaldMedium);
	fpsText.setString(to_string(timeManager->frameRate));
	fpsText.setCharacterSize(15);
	fpsText.setFillColor(sf::Color::White);
	return fpsText;
}