#pragma once

class Robot {
public:
	Robot(sf::Vector2f pos, sf::Texture& texture);
	void Update();
	double GetRandom(float min, float max);
	sf::Sprite sprite;
private:
	sf::Vector2f pos;
	sf::Vector2f velocity;
};