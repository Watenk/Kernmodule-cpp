
#include <iostream>

#include "FontManager.h"


FontManager::FontManager() {

    std::cout << "Loading Fonts" << std::endl;

    if (!oswaldRegular.loadFromFile("Fonts/oswaldRegular.ttf"))
    {
        std::cout << "Fonts/oswaldRegular.ttf missing!" << std::endl;
    }
    if (!oswaldMedium.loadFromFile("Fonts/oswaldMedium.ttf"))
    {
        std::cout << "Fonts/oswaldMedium.ttf missing!" << std::endl;
    }
}

sf::Text FontManager::getText(string string, int size, sf::Color color, watenk::Vector2 pos) {
    sf::Text text;
    text.setFont(oswaldMedium);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(pos.convertToSFML());
    return text;
}