#pragma once

#include <string>

class GameManager;

using std::string;

class SceneManager {
public:
	SceneManager(GameManager* gameManager);
	void switchScene(string scene);
	
	string currentScene;

private:
	void loadScene(string scene);
	void unloadScene(string scene);
	void loadMainMenu();
	void loadLvl01();

	GameManager* gameManager;
};