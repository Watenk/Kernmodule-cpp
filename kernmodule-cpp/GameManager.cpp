
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

	//Add Managers to BaseClassList
	addBaseClass(inputs);
	addBaseClass(timeManager);

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

	window->draw(getFpsText());

	//void draw() {
	////Objects
	//for (list<PhysicsObject*>::iterator it = physicsObjects.begin(); it != physicsObjects.end(); it++) {
	//    PhysicsObject currentPhysicsObject = *(*it);

	//    window->draw(currentPhysicsObject.sprite);
	//    if (currentPhysicsObject.debug) {
	//        window->draw(currentPhysicsObject.collisionRect1);
	//        window->draw(currentPhysicsObject.collisionRect2);
	//        window->draw(currentPhysicsObject.collisionRect3);
	//        window->draw(currentPhysicsObject.collisionRect4);
	//    }
	//}

	// end the current frame
	//}
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
	delete newBaseClass;
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

//PhysicsObject* getPhysicsObject(list<PhysicsObject*> currentList, int targetIndex) {
//
//    for (list<PhysicsObject*>::iterator it = physicsObjects.begin(); it != physicsObjects.end(); it++) {
//        if ((*it)->getIndex() == targetIndex) {
//            return *it;
//        }
//    }
//
//    return NULL;
//}

//void addPhysicsObject(PhysicsObject* newObject) {
//    physicsObjects.push_back(newObject);
//    physicsObjectsIndex++;
//}

//bool doesItCollide(sf::Vector2f collisionVector, PhysicsObject* otherObject) {
//    if (collisionVector.x > otherObject->pos.x && collisionVector.y > otherObject->pos.y && collisionVector.x < otherObject->pos4.x && collisionVector.y < otherObject->pos4.y) {
//        return true;
//    }
//    return false;
//}