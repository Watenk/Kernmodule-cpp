#pragma once

#include "PhysicsObject.h"

class Robot : public PhysicsObject {
public:
	Robot(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int health);
	void ups() override;

private:

};