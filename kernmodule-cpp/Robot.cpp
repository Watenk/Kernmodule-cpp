
#include <iostream>

#include "Robot.h"

#include "GlobalData.h"
#include "Bullet.h"

Robot::Robot(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int health)
	: PhysicsObject(gameManager, pos, size, colliderSize, mass, health, *gameManager->textureManager->robotTexture) {

}

void Robot::ups() {
	PhysicsObject::ups();

	//Move Towards player
	float playerDistanceX = pos.x - gameManager->inputs->player->pos.x;
	float playerDistanceY = pos.y - gameManager->inputs->player->pos.y;
	float playerTotalDistance = abs(pos.x - gameManager->inputs->player->pos.x) + abs(pos.y - gameManager->inputs->player->pos.y);
	float robotRadian = std::atan2(playerDistanceY, playerDistanceX);

	if (playerTotalDistance >= robotPlayerTargetDistance) { //move towards player
		watenk::Vector2 robotNewton(-std::cos(robotRadian) * (robotSpeed + ((gameManager->score / 200.0f) * difficulty)), -std::sin(robotRadian) * (robotSpeed + ((gameManager->score / 200.0f) * difficulty)));
		addInstantForce(robotNewton);
	}
	else { //move away from player
		watenk::Vector2 robotNewton(-std::cos(robotRadian) * robotSpeed, -std::sin(robotRadian) * robotSpeed);
		addInstantForce(watenk::Vector2(robotNewton.x * -1, robotNewton.y * -1));
	}

	//Shooting
	if (robotShootSpeedTimer >= robotShootSpeed - (gameManager->score / 75.0f) * difficulty) {
		robotShootSpeedTimer = 0;
		float playerDistanceX = pos.x - gameManager->inputs->player->pos.x;
		float playerDistanceY = pos.y - gameManager->inputs->player->pos.y;

		if ((std::rand() % 10 + 1) <= 5) {
			playerDistanceX += (std::rand() % (int)(robotShootInaccuracy - (gameManager->score / 100.0f) * difficulty) + 1);
			playerDistanceY += (std::rand() % (int)(robotShootInaccuracy - (gameManager->score / 100.0f) * difficulty) + 1);
		}														   
		else {													   
			playerDistanceX -= (std::rand() % (int)(robotShootInaccuracy - (gameManager->score / 100.0f) * difficulty) + 1);
			playerDistanceY -= (std::rand() % (int)(robotShootInaccuracy - (gameManager->score / 100.0f) * difficulty) + 1);
		}

		//Calc radian player to mouse
		float playerRadian = std::atan2(playerDistanceY, playerDistanceX);

		//calc Bullet Origin Point
		robotBulletOrigin = watenk::Vector2(pos.x + robotBulletOriginRadius * -std::cos(playerRadian), pos.y + robotBulletOriginRadius * -std::sin(playerRadian));

		//Calc BulletVelocity
		watenk::Vector2 bulletNewton(-std::cos(playerRadian) * bulletSpeed, -std::sin(playerRadian) * bulletSpeed);

		Bullet* newBullet = new Bullet(gameManager, watenk::Vector2(robotBulletOrigin.x, robotBulletOrigin.y), watenk::Vector2(0.5f, 0.5f), watenk::Vector2(8, 8), bulletMass);
		newBullet->addInstantForce(bulletNewton);
		gameManager->addPhysicsObject(newBullet);
	}
	else {
		robotShootSpeedTimer++;
	}
}

void Robot::doDamage(int hp) {
	PhysicsObject::doDamage(hp);

	if (health <= 0) {
		gameManager->score += robotKillScoreAmount;
		if (gameManager->inputs->player->health < playerHealth) {
			gameManager->inputs->player->health += robotKillHealthAmount;
		}
	}
}