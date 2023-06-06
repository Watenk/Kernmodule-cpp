
#include "TimeManager.h"
#include "GameData.h"

sf::Clock sfClock;

void TimeManager::update() {
    int elapsedTime = (int)sfClock.getElapsedTime().asMicroseconds();
    frameTime = elapsedTime - previousFrame;
    frameRate = 1000000 / frameTime;
    previousFrame = elapsedTime;
    deltaTime = UPSSpeed / frameRate;
}