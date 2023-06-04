#pragma once

#include <string>

using std::string;

class SceneManager {
public:
	SceneManager();
	void switchScene(string scene);
	string currentScene;

private:
	void loadScene(string scene);
	void unloadScene(string scene);

};