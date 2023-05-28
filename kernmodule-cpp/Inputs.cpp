
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "GameSettings.h"
#include "Inputs.h"
#include "Player.h"

extern Player* player;

void Inputs::Update() {

    PlayerInputs();
}

void Inputs::PlayerInputs() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
    }
}