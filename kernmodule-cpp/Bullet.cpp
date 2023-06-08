
#include "Bullet.h"

#include "GameManager.h"

Bullet::Bullet(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int index)
	: PhysicsObject(gameManager, pos, size, colliderSize, mass, *gameManager->textureManager->bulletTexture, index) {

	staticFrictionCoefficient = 0;
	kineticFrictionCoefficient = 0;
}