#pragma once

#include "PhysicsObject.h"

class Player : public PhysicsObject {
public:
	Player(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderOffset, watenk::Vector2 colliderSize, float accelerationSpeed, float mass, sf::Texture& texture, int index, bool debug);
	void update() override;
	void ups() override;

	float accelerationSpeed;

private:
	void borderCollision();
};