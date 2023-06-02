#pragma once

#include "PhysicsObject.h"

class Player : public PhysicsObject {
public:
	Player(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f colliderOffset, sf::Vector2f colliderSize, float accelerationSpeed, float mass, sf::Texture& texture, int index, bool debug);
	void ups();
	float accelerationSpeed;

private:
	void borderCollision();
};