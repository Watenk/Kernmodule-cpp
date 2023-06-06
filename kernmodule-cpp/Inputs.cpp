
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "GameManager.h"
#include "Inputs.h"
#include "TimeManager.h"

Inputs::Inputs(GameManager* gameManager) : gameManager(gameManager), player(NULL) {

}

void Inputs::update() {

    if (player != NULL) {
        playerInputs();
    }
}

void Inputs::setPlayer(Player* newPlayer) {
    player = newPlayer;
}

void Inputs::playerInputs() {
 
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