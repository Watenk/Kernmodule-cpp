
#include <iostream>

#include "TextureManager.h"

TextureManager::TextureManager() {
 
    std::cout << "Loading Textures" << std::endl;
    
    playerTexture = new sf::Texture();
    if (!playerTexture->loadFromFile("Textures/player.png"))
    {
        std::cout << "Textures/player.png missing!" << std::endl;
    }
    
    robotTexture = new sf::Texture();
    if (!robotTexture->loadFromFile("Textures/robot.png"))
    {
        std::cout << "Textures/robot.png missing!" << std::endl;
    }

    bulletTexture = new sf::Texture();
    if (!bulletTexture->loadFromFile("Textures/bullet.png"))
    {
        std::cout << "Textures/bullet.png missing!" << std::endl;
    }
}