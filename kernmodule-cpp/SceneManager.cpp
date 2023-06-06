
#include <SFML/Graphics.hpp>
#include <iostream>

#include "SceneManager.h"
#include "GameManager.h"
#include "GlobalData.h"
#include "Player.h"

SceneManager::SceneManager(GameManager* gameManager) : gameManager(gameManager) {

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

void SceneManager::loadMainMenu() {

}

void SceneManager::loadLvl01() {
	std::cout << "Loading Lvl01" << std::endl;

	Player* player = new Player(gameManager, sf::Vector2f(500, 500), sf::Vector2f(2, 2), sf::Vector2f(0, 0), sf::Vector2f(1, 1), 1.3f, 50.0f, *gameManager->textureManager->playerTexture, 0, true);
	gameManager->addBaseClass(player);
	gameManager->inputs->setPlayer(player);
}