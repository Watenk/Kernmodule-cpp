
#include <SFML/Graphics.hpp>
#include <iostream>

#include "SceneManager.h"
#include "GameManager.h"
#include "GlobalData.h"
#include "Player.h"
#include "Robot.h"

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

	Player* player = new Player(gameManager, watenk::Vector2(500, 500), watenk::Vector2(2, 2), watenk::Vector2(15, 15), 50.0f, 0);
	gameManager->addPhysicsObject(player);
	gameManager->inputs->setPlayer(player);

	gameManager->addPhysicsObject(new Robot(gameManager, watenk::Vector2(600, 600), watenk::Vector2(2, 2), watenk::Vector2(15, 15), 50.0f, 1));
}