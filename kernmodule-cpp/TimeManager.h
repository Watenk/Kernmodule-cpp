#pragma once

#include <SFML/Graphics.hpp>

#include "BaseClass.h"

class TimeManager : public BaseClass {
public:
	void update();
	float deltaTime = 0;
	int frameTime = 0;
	int frameRate = 0;

private:
	sf::Clock clock;
	int previousFrame = 0;
};