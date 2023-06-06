#pragma once

class Robot {
public:
	Robot(watenk::Vector2 pos, sf::Texture& texture);
	void Update();
	double GetRandom(float min, float max);
	sf::Sprite sprite;
private:
	watenk::Vector2 pos;
	watenk::Vector2 velocity;
};