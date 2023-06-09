
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
	if (currentScene == "MainMenu") {
		updateMainMenu();
	}
	else if (currentScene == "Lvl01") {
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

void SceneManager::updateMainMenu() {

	//Play button
	sf::RectangleShape playbutton;
	playbutton.setSize(watenk::Vector2(200, 50).convertToSFML());
	playbutton.setPosition(watenk::Vector2(screenWidth / 2.0f - 90.0f, screenHeight / 5.0f).convertToSFML());
	gameManager->window->draw(playbutton);
	gameManager->window->draw(gameManager->fontManager->getText("Play", 40, sf::Color::Black, watenk::Vector2(screenWidth / 2.0f - 2.0f, screenHeight / 5.0f)));

	//ScoreBoard
	gameManager->window->draw(gameManager->fontManager->getText("Scoreboard:", 20, sf::Color::White, watenk::Vector2(screenWidth / 2.0f - 30.0f, screenHeight / 3.5f)));
}

void SceneManager::loadGameOver() {

}

void SceneManager::loadLvl01() {
	Player* player = new Player(gameManager, watenk::Vector2(500, 500), watenk::Vector2(2, 2), watenk::Vector2(15, 15), 50.0f, 3);
	gameManager->addPhysicsObject(player);
	gameManager->inputs->setPlayer(player);
}

void SceneManager::updateLvl01() {
	
	if (lvl01EnemyTimer > 10.0f - (gameManager->score / 1000) * difficulty) {
		//Need to Add Randomness
		gameManager->addPhysicsObject(new Robot(gameManager, watenk::Vector2(700, 500), watenk::Vector2(3, 3), watenk::Vector2(50, 50), 500.0f, 1));
		lvl01EnemyTimer = 0;
	}
	else {
		lvl01EnemyTimer += gameManager->timeManager->deltaTime;
	}
}