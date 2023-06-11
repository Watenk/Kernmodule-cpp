
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Vector>

#include "SceneManager.h"
#include "GameManager.h"
#include "GlobalData.h"
#include "Player.h"
#include "Robot.h"

using std::to_string;

SceneManager::SceneManager(GameManager* gameManager) : gameManager(gameManager) {
	srand((unsigned int)time(NULL));
}

void SceneManager::update() {
	if (currentScene == "MainMenu") {
		updateMainMenu();
	}
	else if (currentScene == "Lvl01") {
		updateLvl01();
	}
	else if (currentScene == "GameOver") {
		updateGameOver();
	}
}

void SceneManager::loadScene(string scene) {
	unloadCurrentScene();

	if (scene == "MainMenu") {
		std::cout << "Loading Scene: MainMenu" << std::endl;
		loadMainMenu();
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
	std::vector<int> scores = gameManager->fileManager->getHighScores();
	highScore1 = scores[0];
	highScore2 = scores[1];
	highScore3 = scores[2];
}

void SceneManager::updateMainMenu() {

	//Play button
	sf::RectangleShape playbutton;
	playbutton.setSize(watenk::Vector2(200, 50).convertToSFML());
	playbutton.setPosition(watenk::Vector2(screenWidth / 2.0f - 90.0f, screenHeight - 200).convertToSFML());
	gameManager->window->draw(playbutton);
	gameManager->window->draw(gameManager->fontManager->getText("Play", 40, sf::Color::Black, watenk::Vector2(screenWidth / 2.0f - 25.0f, screenHeight - 200)));

	//ScoreBoard
	gameManager->window->draw(gameManager->fontManager->getText("HighScores:", 50, sf::Color::White, watenk::Vector2(0.0f, 25)));
	gameManager->window->draw(gameManager->fontManager->getText("1: " + to_string(highScore1), 50, sf::Color::White, watenk::Vector2(0.0f, 85)));
	gameManager->window->draw(gameManager->fontManager->getText("2: " + to_string(highScore2), 40, sf::Color::White, watenk::Vector2(0.0f, 135)));
	gameManager->window->draw(gameManager->fontManager->getText("3: " + to_string(highScore3), 30, sf::Color::White, watenk::Vector2(0.0f, 175)));
}

void SceneManager::updateGameOver() {
	gameManager->window->draw(gameManager->fontManager->getText("...Game Over...", 50, sf::Color::Red, watenk::Vector2(screenWidth / 2.0f - 125.0f, screenHeight / 3.5f)));
	gameManager->window->draw(gameManager->fontManager->getText("Score: " + to_string(gameManager->score), 30, sf::Color::White, watenk::Vector2(screenWidth / 2.0f - 50.0f, screenHeight / 2.0f)));

	if (gameOverTimer >= gameOverTime) {
		gameOverTimer = 0;
		gameManager->fileManager->saveScore(gameManager->score);
		gameManager->score = 0;
		loadScene("MainMenu");
	}
	else {
		gameOverTimer += gameManager->timeManager->deltaTime;
	}
}

void SceneManager::loadLvl01() {
	Player* player = new Player(gameManager, watenk::Vector2(500, 500), watenk::Vector2(2, 2), watenk::Vector2(15, 15), playerMass, playerHealth);
	gameManager->addPhysicsObject(player);
	gameManager->inputs->setPlayer(player);
}

void SceneManager::updateLvl01() {
	
	//UI
	gameManager->window->draw(gameManager->fontManager->getText("Score:" + to_string(gameManager->score), 20, sf::Color::White, watenk::Vector2((screenWidth / 2) - 150.0f, screenHeight - 30.0f)));
	gameManager->window->draw(gameManager->fontManager->getText("Health:" + to_string(gameManager->inputs->player->health), 20, sf::Color::Red, watenk::Vector2((screenWidth - screenWidth / 2) + 150.0f, screenHeight - 30.0f)));

	if (gameManager->inputs->playerDashTimer >= dashDelay) {
		gameManager->window->draw(gameManager->fontManager->getText("Dash Ready!!", 20, sf::Color::White, watenk::Vector2((screenWidth / 2) - 25.0f, screenHeight - 30.0f)));
	}

	if (gameManager->inputs->playerBurstTimer >= burstDelay) {
		gameManager->window->draw(gameManager->fontManager->getText("Burst Ready!!", 20, sf::Color::Blue, watenk::Vector2((screenWidth / 2) - 25.0f, screenHeight - 60.0f)));
	}

	//TimeScore
	if (lvl01TimeScoreTimer >= 1) {
		if (ifShootingNoTimeScore == true) {
			if (gameManager->inputs->isShooting == false) {
				lvl01TimeScoreTimer = 0.0f;
				gameManager->score += timeScore;
			}
		}
		else {
			lvl01TimeScoreTimer = 0.0f;
			gameManager->score += timeScore;
		}
	}
	else {
		lvl01TimeScoreTimer += gameManager->timeManager->deltaTime;
	}

	if (lvl01EnemyTimer >= 6.0f - (gameManager->score / 1500.0f) * difficulty) {
		gameManager->addPhysicsObject(new Robot(gameManager, watenk::Vector2(screenWidth + 100.0f + (float)(std::rand() % 100 + 1), (float)(std::rand() % screenHeight + 1)), watenk::Vector2(2, 2), watenk::Vector2(20, 20), robotMass, robotHealth + (int)((gameManager->score / 300) * difficulty)));
		lvl01EnemyTimer = 0.0f;
	}
	else {
		lvl01EnemyTimer += gameManager->timeManager->deltaTime;
	}
}