#pragma once

class Robot {
	public:
		Robot(sf::Vector2f pos, sf::Texture& texture, int screenWidth, int screenHeight);
		void Update();
		double GetRandom(float min, float max);
		sf::Sprite sprite;
	private:
		int screenWidth;
		int screenHeight;
		sf::Vector2f pos;
		sf::Vector2f velocity;
};