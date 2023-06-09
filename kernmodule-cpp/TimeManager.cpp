
#include <iostream>

#include "TimeManager.h"
#include "GlobalData.h"

sf::Clock sfClock;

void TimeManager::update() {
    //Calc FrameTime
    int elapsedTime = (int)sfClock.getElapsedTime().asMicroseconds();
    frameTime = elapsedTime - previousFrame;
    frameRate = (int)(1000000 / frameTime);
    previousFrame = elapsedTime;

    //Calc AverageFrameRate
    if (lastFrameRateIndex == sizeof(lastFrameRates) / sizeof(int)) {
        lastFrameRateIndex = 0;

        lowestFrame = 10000;
        int totalFrames = 0;

        for (int i = 0; i < sizeof(lastFrameRates) / sizeof(int); i++) {
            totalFrames += lastFrameRates[i];

            if (lastFrameRates[i] < lowestFrame) {
                lowestFrame = lastFrameRates[i];
            }
        }
        averageFrameRate = totalFrames / (sizeof(lastFrameRates) / sizeof(int));
    }
    else {
        lastFrameRates[lastFrameRateIndex] = frameRate;
        lastFrameRateIndex++;
    }

    upsTime = UPSSpeed / frameRate;

    deltaTime = upsTime / 60;
}