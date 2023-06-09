
#include <iostream>

#include "GlobalData.h"
#include "Robot.h"

Robot::Robot(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int health)
	: PhysicsObject(gameManager, pos, size, colliderSize, mass, health, *gameManager->textureManager->robotTexture) {

}

void Robot::ups() {
	PhysicsObject::ups();

	//Need To Add A.I.
	//Move Towards player
	//Shoot some bullets??
}