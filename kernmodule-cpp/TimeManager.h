#pragma once

#include <SFML/Graphics.hpp>

#include "BaseClass.h"

class TimeManager : public BaseClass {
public:
	void update() override;
	float deltaTime = 0;
	int frameTime = 0;
	int frameRate = 0;
	int averageFrameRate = 0;
	int lowestFrame = 10000;

private:
	sf::Clock clock;

	int previousFrame = 0;
	int lastFrameRates[10];
	int lastFrameRateIndex = 0;
};