
#include <iostream>

#include "TextureManager.h"

TextureManager::TextureManager() {
 
    std::cout << "Loading Textures" << std::endl;
    
    backgroundTexture = new sf::Texture();
    if (!backgroundTexture->loadFromFile("Textures/background.png"))
    {
        std::cout << "Textures/background.png missing!" << std::endl;
    }
    else {
        backgroundTexture->setRepeated(true);
    }

    backgroundDunesTexture = new sf::Texture();
    if (!backgroundDunesTexture->loadFromFile("Textures/backgroundDunes.png"))
    {
        std::cout << "Textures/backgroundDunes.png missing!" << std::endl;
    }
    else {
        backgroundDunesTexture->setRepeated(true);
    }

    skyboxTexture = new sf::Texture();
    if (!skyboxTexture->loadFromFile("Textures/skybox.jpg"))
    {
        std::cout << "Textures/skybox.png missing!" << std::endl;
    }

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