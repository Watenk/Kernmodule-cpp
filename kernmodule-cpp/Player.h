#pragma once

#include "PhysicsObject.h"

class Player : public PhysicsObject {
public:
	Player(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int index);
	void update() override;
	void ups() override;
	
	watenk::Vector2 bulletOrigin;

private:
	void borderCollision();

};