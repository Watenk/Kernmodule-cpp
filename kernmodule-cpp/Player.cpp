
#include <iostream>
#include <SFML/Graphics.hpp>

#include "GlobalData.h"
#include "Player.h"
#include "GameManager.h"

Player::Player(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int health) 
	: PhysicsObject(gameManager, pos, size, colliderSize, mass, health, *gameManager->textureManager->playerTexture) {

}

void Player::update() {
	PhysicsObject::update();
}

void Player::ups() {
	borderCollision();
	PhysicsObject::ups();
}

void Player::doDamage(int hp) {
	PhysicsObject::doDamage(hp);

	if (health <= 0) {
		gameManager->sceneManager->loadScene("GameOver");
	}
}

void Player::borderCollision() {

	if (topLeft.x < 0) {
		pos.x = colliderSize.x;
		velocity.x = 0.f;
	}

	if (bottomRight.x > screenWidth) {
		pos.x = screenWidth - colliderSize.x;
		velocity.x = 0.f;
	}

	if (topLeft.y < 0) {
		pos.y = colliderSize.y;
		velocity.y = 0.f;
	}

	if (bottomRight.y > screenHeight) {
		pos.y = screenHeight - colliderSize.y;
		velocity.y = 0.f;
	}
}
