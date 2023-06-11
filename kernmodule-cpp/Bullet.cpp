
#include "Bullet.h"

#include "GameManager.h"
#include "GlobalData.h"

Bullet::Bullet(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass)
	: PhysicsObject(gameManager, pos, size, colliderSize, mass, 1, *gameManager->textureManager->bulletTexture) {

	staticFrictionCoefficient = 0;
	kineticFrictionCoefficient = 0;
}

void Bullet::ups() {
	PhysicsObject::ups();

	if (bulletLifeTimeTimer >= bulletLifeTime) {
		deleteObject = true;
	}
	else {
		bulletLifeTimeTimer++;
	}
}