#pragma once

#include "PhysicsObject.h"

class Bullet : public PhysicsObject {
public:
	Bullet(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int index);
};