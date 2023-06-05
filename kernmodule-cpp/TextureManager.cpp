
#include <iostream>

#include "TextureManager.h"

TextureManager::TextureManager() {
    playerTexture = new sf::Texture();
    if (!playerTexture->loadFromFile("Textures/player.png"))
    {
        std::cout << "Textures/player.png missing!" << std::endl;
    }
    
    enemyTexture = new sf::Texture();
    if (!enemyTexture->loadFromFile("Textures/robot.png"))
    {
        std::cout << "Textures/robot.png missing!" << std::endl;
    }
}