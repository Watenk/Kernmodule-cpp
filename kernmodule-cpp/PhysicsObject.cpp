
#include <iostream>
#include <SFML/Graphics.hpp>

#include "PhysicsObject.h"
#include "GlobalData.h"
#include "GameManager.h"

using std::to_string;

PhysicsObject::PhysicsObject(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int health, sf::Texture& texture)
	: gameManager(gameManager), pos(pos), size(size), colliderSize(colliderSize), mass(mass), health(health), texture(texture), objectStatic(false){

	sprite.setTexture(texture);
	sprite.setScale(size.x, size.y);
	sprite.setPosition(pos.convertToSFML());

	width = (float)texture.getSize().x * size.x;
	height = (float)texture.getSize().y * size.y;

	if (debug) {
		collisionRect1.setSize(watenk::Vector2(5, 5).convertToSFML());
		collisionRect2.setSize(watenk::Vector2(5, 5).convertToSFML());
		collisionRect3.setSize(watenk::Vector2(5, 5).convertToSFML());
		collisionRect4.setSize(watenk::Vector2(5, 5).convertToSFML());
	}
}

void PhysicsObject::update() {
	sprite.setPosition(watenk::Vector2(pos.x - width / 2, pos.y - height / 2).convertToSFML());
	gameManager->window->draw(sprite);

	if (debug) {
		gameManager->window->draw(collisionRect1);
		gameManager->window->draw(collisionRect2);
		gameManager->window->draw(collisionRect3);
		gameManager->window->draw(collisionRect4);

		gameManager->window->draw(gameManager->fontManager->getText("Velocity: " + to_string((int)velocity.x) + ", " + to_string((int)velocity.y), 10, sf::Color::Yellow, watenk::Vector2(pos.x - width / 2, pos.y - height)));
	}
}

void PhysicsObject::ups() {
	//Is object Static
	if (velocity.x >= -staticTreshhold && velocity.x <= staticTreshhold && velocity.y >= -staticTreshhold && velocity.y <= staticTreshhold) {
		velocity.x = 0.0f;
		velocity.y = 0.0f;
		objectStatic = true;
	}
	else {
		objectStatic = false;
	}

	friction();
	colliders();

	pos.x += velocity.x;
	pos.y += velocity.y;
}

void PhysicsObject::addInstantForce(watenk::Vector2 extraNewton) {
	velocity.x += extraNewton.x / mass;
	velocity.y += extraNewton.y / mass;
}

void PhysicsObject::removeInstantForce(watenk::Vector2 removedNewton) {
	velocity.x -= removedNewton.x / mass;
	velocity.y -= removedNewton.y / mass;
}

void PhysicsObject::doDamage(int hp) {
	health -= hp;

	if (health <= 0) {
		deleteObject = true;
	}
}

void PhysicsObject::friction() {

	float groundFriction;
	float groundNormalForce = gravity * mass;

	if (objectStatic) {
		groundFriction = groundNormalForce * staticFrictionCoefficient * (mass * massImpact);
	}
	else
	{
		groundFriction = groundNormalForce * kineticFrictionCoefficient * (mass * massImpact);
	}

	if (velocity.x > 0) {
		velocity.x -= groundFriction / mass;
		if (velocity.x < 0) {
			velocity.x = 0.0f;
		}
	}
	else {
		velocity.x += groundFriction / mass;
		if (velocity.x > 0) {
			velocity.x = 0.0f;
		}
	}

	if (velocity.y > 0) {
		velocity.y -= groundFriction / mass;
		if (velocity.y < 0) {
			velocity.y = 0.0f;
		}
	}
	else {
		velocity.y += groundFriction / mass;
		if (velocity.y > 0) {
			velocity.y = 0.0f;
		}
	}
}

void PhysicsObject::colliders() {
	topLeft.x = pos.x - colliderSize.x;
	topLeft.y = pos.y - colliderSize.y;

	topRight.x = pos.x + colliderSize.x;
	topRight.y = pos.y - colliderSize.y;

	bottomLeft.x = pos.x - colliderSize.x;
	bottomLeft.y = pos.y + colliderSize.y;

	bottomRight.x = pos.x + colliderSize.x;
	bottomRight.y = pos.y + colliderSize.y;

	if (debug) {
		collisionRect1.setPosition(topLeft.convertToSFML());
		collisionRect2.setPosition(topRight.convertToSFML());
		collisionRect3.setPosition(bottomLeft.convertToSFML());
		collisionRect4.setPosition(bottomRight.convertToSFML());
	}
}