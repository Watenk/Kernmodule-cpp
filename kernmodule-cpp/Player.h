#pragma once

class Player {
public:
	Player(sf::Vector2f pos, sf::Texture& texture);
	void Update();
	void Move(sf::Vector2f direction);

	sf::Vector2f pos;
	sf::Sprite sprite;

private:
	sf::Texture texture;
};