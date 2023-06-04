
#include "SceneManager.h"

SceneManager::SceneManager() {

}

void SceneManager::switchScene(string scene) {
	unloadScene(currentScene);
	loadScene(scene);
	currentScene = scene;
}

void SceneManager::loadScene(string scene) {

}

void SceneManager::unloadScene(string scene) {

}