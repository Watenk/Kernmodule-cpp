#pragma once

#include <SFML/Graphics.hpp>

class TextureManager {
public:
	TextureManager();

	sf::Texture* playerTexture;
	sf::Texture* enemyTexture;
};