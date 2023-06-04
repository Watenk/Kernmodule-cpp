
#include <iostream>
#include <SFML/Graphics.hpp>

#include "TimeManager.h"
#include "GameSettings.h"

using std::cout;

TimeManager::TimeManager() {
    sf::Clock clock;
}

void TimeManager::update() {
    int elapsedTime = (int)clock.getElapsedTime().asMicroseconds();
    frameTime = elapsedTime - previousFrame;
    frameRate = 1000000 / frameTime;
    previousFrame = elapsedTime;
    deltaTime = UPSSpeed / frameRate;
}