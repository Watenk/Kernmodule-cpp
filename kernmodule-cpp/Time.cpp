
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Time.h"
#include "GameSettings.h"

using std::cout;

namespace Watenk {
    Time::Time() {
        sf::Clock clock;
    }

    void Time::update() {
        int elapsedTime = (int)clock.getElapsedTime().asMicroseconds();
        frameTime = elapsedTime - previousFrame;
        frameRate = 1000000 / frameTime;
        previousFrame = elapsedTime;
        deltaTime = UPSSpeed / frameRate;
    }
}