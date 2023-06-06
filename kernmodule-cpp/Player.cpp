
#include <iostream>
#include <SFML/Graphics.hpp>

#include "GlobalData.h"
#include "Player.h"
#include "GameManager.h"

Player::Player(GameManager* gameManager, sf::Vector2f pos, sf::Vector2f size, sf::Vector2f colliderOffset, sf::Vector2f colliderSize, float accelerationSpeed, float mass, sf::Texture& texture, int index, bool debug) 
	: PhysicsObject(gameManager, pos, size, colliderOffset, colliderSize, mass, texture, index, debug), accelerationSpeed(accelerationSpeed) {

}

void Player::update() {
	PhysicsObject::update();
}

void Player::ups() {
	borderCollision();
	PhysicsObject::ups();
}

void Player::borderCollision() {

	if (pos.x < 0) {
		pos.x = 0.f;
		velocity.x = 0.f;
	}

	if (pos4.x > screenWidth) {
		pos.x = screenWidth - width;
		velocity.x = 0.f;
	}

	if (pos.y < 0) {
		pos.y = 0;
		velocity.y = 0.f;
	}

	if (pos4.y > screenHeight) {
		pos.y = screenHeight - height;
		velocity.y = 0.f;
	}
}