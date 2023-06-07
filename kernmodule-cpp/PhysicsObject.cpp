
#include <iostream>
#include <SFML/Graphics.hpp>

#include "PhysicsObject.h"
#include "GlobalData.h"
#include "GameManager.h"

extern GameManager* gameManager;

PhysicsObject::PhysicsObject(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderOffset, watenk::Vector2 colliderSize, float mass, sf::Texture& texture, int index, bool debug)
	: gameManager(gameManager), pos(pos), size(size), colliderOffset(colliderOffset), colliderSize(colliderSize), mass(mass), texture(texture), index(index), debug(debug), objectStatic(false){

	sprite.setTexture(texture);
	sprite.setScale(size.x, size.y);
	sprite.setPosition(pos.convertToSFML());

	width = (float)texture.getSize().x * size.x;
	height = (float)texture.getSize().y * size.y;

	collisionRect1.setSize(watenk::Vector2(5, 5).convertToSFML());
	collisionRect2.setSize(watenk::Vector2(5, 5).convertToSFML());
	collisionRect3.setSize(watenk::Vector2(5, 5).convertToSFML());
	collisionRect4.setSize(watenk::Vector2(5, 5).convertToSFML());
}

void PhysicsObject::update() {
	sprite.setPosition(pos.convertToSFML());
	gameManager->window->draw(sprite);
}

void PhysicsObject::ups() {

	physics();
}

void PhysicsObject::addInstantForce(watenk::Vector2 extraVelocity) {
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

	watenk::Vector2 groundFriction;
	watenk::Vector2 groundNormalForce = convertVelocityToNewton(watenk::Vector2(gravity, gravity), mass);

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
		collisionRect1.setPosition(pos.convertToSFML());
		collisionRect2.setPosition(pos2.convertToSFML());
		collisionRect3.setPosition(pos3.convertToSFML());
		collisionRect4.setPosition(pos4.convertToSFML());
	}
}

watenk::Vector2 PhysicsObject::convertVelocityToNewton(watenk::Vector2 velocity, float mass) {
	float xNewton = mass * velocity.x;
	float yNewton = mass * velocity.y;
	return watenk::Vector2(xNewton, yNewton);
}

watenk::Vector2 PhysicsObject::convertNewtonToVelocity(watenk::Vector2 newton, float mass) {
	float xVelocity = newton.x / mass;
	float yVelocity = newton.y / mass;
	return watenk::Vector2(xVelocity, yVelocity);
}

watenk::Vector2 PhysicsObject::calcFriction(watenk::Vector2 normalForce, float frictionCoefficient) {
	float xFriction = frictionCoefficient * normalForce.x;
	float yFriction = frictionCoefficient * normalForce.y;
	return watenk::Vector2(xFriction, yFriction);
}