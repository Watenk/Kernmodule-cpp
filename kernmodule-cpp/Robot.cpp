
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "Robot.h"

Robot::Robot(sf::Vector2f pos, sf::Texture& texture, int screenWidth, int screenHeight) : pos(pos), screenWidth(screenWidth), screenHeight(screenHeight) {
	sprite.setTexture(texture);
	velocity.x = GetRandom(-3, 3);
	velocity.y = GetRandom(-3, 3);
	sprite.setColor(sf::Color(1, 255, 255, 128));
}

void Robot::Update() {
	pos.x += velocity.x;
	pos.y += velocity.y;

	if (pos.x >= screenWidth || pos.x <= 0) {
		velocity.x *= -1;
	}

	if (pos.y >= screenHeight || pos.y <= 0) {
		velocity.y *= -1;
	}

	sprite.setPosition(pos.x, pos.y);
}

double Robot::GetRandom(float min, float max){
	static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(min, max);
	return dis(e);
}