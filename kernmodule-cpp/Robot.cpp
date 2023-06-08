
#include "GlobalData.h"
#include "Robot.h"

Robot::Robot(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int index)
	: PhysicsObject(gameManager, pos, size, colliderSize, mass, *gameManager->textureManager->enemyTexture, index) {

}