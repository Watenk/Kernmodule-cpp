
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "GameData.h"
#include "GameManager.h"
#include "Inputs.h"
#include "TimeManager.h"

Inputs::Inputs() {

}

void Inputs::playerInputs(Player* player) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player->addInstantForce(sf::Vector2f(0, -player->accelerationSpeed * gameManager->timeManager->deltaTime));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player->addInstantForce(sf::Vector2f(player->accelerationSpeed * gameManager->timeManager->deltaTime, 0));

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player->addInstantForce(sf::Vector2f(0, player->accelerationSpeed * gameManager->timeManager->deltaTime));

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player->addInstantForce(sf::Vector2f(-player->accelerationSpeed * gameManager->timeManager->deltaTime, 0));
    }
}