#pragma once

#include "PhysicsObject.h"

class Player : public PhysicsObject {
public:
	Player(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int health);
	void update() override;
	void ups() override;
	void doDamage(int hp) override;
	
	watenk::Vector2 playerBulletOrigin;

private:
	void borderCollision();

};