#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "Vector2.h"

using std::string;

class FontManager {
public:
	FontManager();
	sf::Text getText(string string, int size, sf::Color color, watenk::Vector2 pos);

	sf::Font oswaldRegular;
	sf::Font oswaldMedium;
};