#pragma once

#include <SFML/Graphics.hpp>

class TextureManager {
public:
	TextureManager();

	sf::Texture* backgroundTexture;
	sf::Texture* backgroundDunesTexture;
	sf::Texture* skyboxTexture;
	sf::Texture* playerTexture;
	sf::Texture* robotTexture;
	sf::Texture* bulletTexture;
};