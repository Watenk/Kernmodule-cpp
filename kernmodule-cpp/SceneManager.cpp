
#include <SFML/Graphics.hpp>
#include <iostream>

#include "SceneManager.h"
#include "GameManager.h"
#include "GlobalData.h"
#include "Player.h"
#include "Robot.h"

SceneManager::SceneManager(GameManager* gameManager) : gameManager(gameManager) {

}

void SceneManager::update() {
	if (currentScene == "Lvl01") {
		updateLvl01();
	}
}

void SceneManager::loadScene(string scene) {
	unloadCurrentScene();

	if (scene == "MainMenu") {
		std::cout << "Loading Scene: MainMenu" << std::endl;
		currentScene = scene;
	}
	else if (scene == "Lvl01") {
		std::cout << "Loading Scene: Lvl01" << std::endl;
		loadLvl01();
		currentScene = scene;
	}
	else if (scene == "GameOver") {
		std::cout << "Loading Scene: GameOver" << std::endl;
		currentScene = scene;
	}
	else {
		std::cout << scene << " Scene Not Found..." << std::endl;
	}
}

void SceneManager::unloadCurrentScene() {
	std::cout << "Unloading Current Scene" << std::endl;
	gameManager->removeAllPhysicsObjects();
}

void SceneManager::loadMainMenu() {

}

void SceneManager::loadGameOver() {

}

void SceneManager::loadLvl01() {
	Player* player = new Player(gameManager, watenk::Vector2(500, 500), watenk::Vector2(2, 2), watenk::Vector2(15, 15), 50.0f, 0);
	gameManager->addPhysicsObject(player);
	gameManager->inputs->setPlayer(player);
}

void SceneManager::updateLvl01() {
	
}