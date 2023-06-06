
#include <iostream>
#include <SFML/Graphics.hpp>

#include "PhysicsObject.h"
#include "GlobalData.h"
#include "GameManager.h"

extern GameManager* gameManager;

PhysicsObject::PhysicsObject(GameManager* gameManager, sf::Vector2f pos, sf::Vector2f size, sf::Vector2f colliderOffset, sf::Vector2f colliderSize, float mass, sf::Texture& texture, int index, bool debug)
	: gameManager(gameManager), pos(pos), size(size), colliderOffset(colliderOffset), colliderSize(colliderSize), mass(mass), texture(texture), index(index), debug(debug), objectStatic(false){

	sprite.setTexture(texture);
	sprite.setScale(size.x, size.y);
	sprite.setPosition(pos);

	width = (float)texture.getSize().x * size.x;
	height = (float)texture.getSize().y * size.y;

	collisionRect1.setSize(sf::Vector2f(5, 5));
	collisionRect2.setSize(sf::Vector2f(5, 5));
	collisionRect3.setSize(sf::Vector2f(5, 5));
	collisionRect4.setSize(sf::Vector2f(5, 5));
}

void PhysicsObject::update() {
	sprite.setPosition(pos);
	gameManager->window->draw(sprite);
}

void PhysicsObject::ups() {

	physics();
}

void PhysicsObject::addInstantForce(sf::Vector2f extraVelocity) {
	velocity.x += extraVelocity.x;
	velocity.y += extraVelocity.y;
}

int PhysicsObject::getIndex() {
	return index;
}

void PhysicsObject::physics() {

	friction();
	collision();

	//Is object Static
	if (velocity.x >= -staticTreshhold && velocity.x <= staticTreshhold && velocity.y >= -staticTreshhold && velocity.y <= staticTreshhold) {
		velocity.x = 0.0f;
		velocity.y = 0.0f;
		objectStatic = true;
	}
	else {
		objectStatic = false;
	}

	//Set new Pos
	//std::cout << velocity.x << ", " << velocity.y << std::endl;
	pos.x += velocity.x;
	pos.y += velocity.y;
}

void PhysicsObject::friction() {

	sf::Vector2f groundFriction;
	sf::Vector2f groundNormalForce = convertVelocityToNewton(sf::Vector2f(gravity, gravity), mass);

	if (objectStatic) {
		groundFriction = convertNewtonToVelocity(calcFriction(groundNormalForce, staticFrictionCoefficient), mass);
	}
	else
	{
		groundFriction = convertNewtonToVelocity(calcFriction(groundNormalForce, kineticFrictionCoefficient), mass);
	}

	if (velocity.x > 0) {
		velocity.x -= groundFriction.x;
		if (velocity.x < 0) {
			velocity.x = 0.0f;
		}
	}
	else {
		velocity.x += groundFriction.x;
		if (velocity.x > 0) {
			velocity.x = 0.0f;
		}
	}

	if (velocity.y > 0) {
		velocity.y -= groundFriction.y;
		if (velocity.y < 0) {
			velocity.y = 0.0f;
		}
	}
	else {
		velocity.y += groundFriction.y;
		if (velocity.y > 0) {
			velocity.y = 0.0f;
		}
	}
}

void PhysicsObject::collision() {
	pos2.x = pos.x + width;
	pos2.y = pos.y;

	pos3.x = pos.x;
	pos3.y = pos.y + height;

	pos4.x = pos.x + width;
	pos4.y = pos.y + height;

	if (debug) {
		collisionRect1.setPosition(pos);
		collisionRect2.setPosition(pos2);
		collisionRect3.setPosition(pos3);
		collisionRect4.setPosition(pos4);
	}
}

sf::Vector2f PhysicsObject::convertVelocityToNewton(sf::Vector2f velocity, float mass) {
	float xNewton = mass * velocity.x;
	float yNewton = mass * velocity.y;
	return sf::Vector2f(xNewton, yNewton);
}

sf::Vector2f PhysicsObject::convertNewtonToVelocity(sf::Vector2f newton, float mass) {
	float xVelocity = newton.x / mass;
	float yVelocity = newton.y / mass;
	return sf::Vector2f(xVelocity, yVelocity);
}

sf::Vector2f PhysicsObject::calcFriction(sf::Vector2f normalForce, float frictionCoefficient) {
	float xFriction = frictionCoefficient * normalForce.x;
	float yFriction = frictionCoefficient * normalForce.y;
	return sf::Vector2f(xFriction, yFriction);
}