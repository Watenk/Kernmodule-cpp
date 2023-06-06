
#include <SFML/Graphics.hpp>
#include <iostream>

#include "SceneManager.h"
#include "GameManager.h"
#include "GameData.h"
#include "Player.h"

SceneManager::SceneManager() {

}

void SceneManager::switchScene(string scene) {
	unloadScene(currentScene);
	loadScene(scene);
	currentScene = scene;
}

void SceneManager::loadScene(string scene) {
	if (scene == "Lvl01") {
		loadLvl01();
	}
}

void SceneManager::unloadScene(string scene) {

}

void SceneManager::loadLvl01() {
	std::cout << "Loading Lvl01" << std::endl;
	gameManager->addBaseClass(new Player(sf::Vector2f(500, 500), sf::Vector2f(2, 2), sf::Vector2f(0, 0), sf::Vector2f(1, 1), 1.3f, 50.0f, *gameManager->textureManager->playerTexture, 0, true));
}