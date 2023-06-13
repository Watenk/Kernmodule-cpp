#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "BaseClass.h"

class GameManager;

using std::string;

class SceneManager : public BaseClass {
public:
	SceneManager(GameManager* gameManager);
	void update() override;
	void loadScene(string scene);
	
	string currentScene;

private:
	void unloadCurrentScene();
	void loadMainMenu();
	void updateMainMenu();
	void updateGameOver();
	void loadLvl01();
	void updateLvl01();

	float lvl01EnemyTimer = 0;
	float lvl01TimeScoreTimer = 0;
	float gameOverTimer = 0;

	int highScore1 = 0;
	int highScore2 = 0;
	int highScore3 = 0;

	sf::Sprite skyboxSprite;
	sf::Sprite backgroundSprite;
	sf::Sprite backgroundSprite2;
	sf::Sprite backgroundDunesSprite;
	sf::Sprite backgroundDunesSprite2;

	GameManager* gameManager;
};