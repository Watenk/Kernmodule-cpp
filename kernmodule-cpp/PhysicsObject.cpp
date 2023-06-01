
#include <iostream>
#include <SFML/Graphics.hpp>

#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f colliderOffset, sf::Vector2f colliderSize, int mass, sf::Texture& texture, int index, bool debug)
	: pos(pos), size(size), colliderOffset(colliderOffset), colliderSize(colliderSize), mass(mass), texture(texture), index(index), debug(debug), objectStatic(false){

	sprite.setTexture(texture);
	sprite.setScale(size.x, size.y);
	sprite.setPosition(pos);
}

void PhysicsObject::ups() {

	physics();

	sprite.setPosition(pos);
}

void PhysicsObject::addInstantForce(sf::Vector2f extraVelocity) {
	velocity.x += extraVelocity.x;
	velocity.y += extraVelocity.y;
}

int PhysicsObject::getIndex() {
	return index;
}

void PhysicsObject::physics() {

	//Is object Static
	if (velocity.x >= -0.1 && velocity.x <= 0.1 && velocity.y >= -0.1 && velocity.y <= 0.1) {
		velocity.x = 0.f;
		velocity.y = 0.f;
		objectStatic = true;
	}
	else {
		objectStatic = false;
	}

	calcFriction();

	std::cout << velocity.x << ", " << velocity.y << std::endl;

	//Set new Pos
	pos.x += velocity.x / mass;
	pos.y += velocity.y / mass;
}

void PhysicsObject::calcFriction() {
	// Friction
	// staticFrictionCoefficient = initial friction force
	// kineticFrictionCoefficient =  when a object already moves

	sf::Vector2f normalForce = convertVelocityToNewton(sf::Vector2f(gravity, gravity), mass);
	sf::Vector2f friction;

	if (objectStatic) {

		friction = calcFriction(normalForce, staticFrictionCoefficient);
	}
	else
	{
		friction = calcFriction(normalForce, kineticFrictionCoefficient);
	}

	addInstantForce(sf::Vector2f(-friction.x, -friction.y));
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