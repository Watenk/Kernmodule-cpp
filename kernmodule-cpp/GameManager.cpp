
#include "GameManager.h"
#include "SceneManager.h"

#include "FontManager.h"
#include "PhysicsManager.h"
#include "TextureManager.h"
#include "TimeManager.h"

GameManager::GameManager() {

}

void GameManager::update() {
	updateUps();


}

void GameManager::ups() {

}

void GameManager::addBaseClass(BaseClass* newBaseClass) {
	baseClassObjects.push_back(newBaseClass);
}

void GameManager::removeBaseClass() {

}

void GameManager::updateUps() {
	//UPSDeltaTime += watenkTime->deltaTime;
	//if (UPSDeltaTime >= 1) {
	//    UPSDeltaTime = 0;
	//    mainUps();
	//}
}