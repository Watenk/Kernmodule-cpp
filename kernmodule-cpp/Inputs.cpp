
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "GameSettings.h"
#include "Inputs.h"
#include "Player.h"
#include "Time.h"
//
//extern Player* player;
//extern Watenk::Time* watenkTime;
//
//void Inputs::update() {
//
//    playerInputs();
//}
//
//void Inputs::playerInputs() {
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//    {
//        player->addInstantForce(sf::Vector2f(0, -player->accelerationSpeed * watenkTime->deltaTime));
//    }
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//    {
//        player->addInstantForce(sf::Vector2f(player->accelerationSpeed * watenkTime->deltaTime, 0));
//
//    }
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//    {
//        player->addInstantForce(sf::Vector2f(0, player->accelerationSpeed * watenkTime->deltaTime));
//
//    }
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//    {
//        player->addInstantForce(sf::Vector2f(-player->accelerationSpeed * watenkTime->deltaTime, 0));
//    }
//}