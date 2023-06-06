
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "GlobalData.h"
#include "Robot.h"

Robot::Robot(sf::Vector2f pos, sf::Texture& texture) : pos(pos) {
	sprite.setTexture(texture);
	sprite.setScale(2, 2);
	velocity.x = (float)GetRandom(-3, 3);
	velocity.y = (float)GetRandom(-3, 3);
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