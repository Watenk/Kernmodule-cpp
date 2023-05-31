
#include <iostream>
#include <SFML/Graphics.hpp>

#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f colliderOffset, sf::Vector2f colliderSize, int weight, sf::Texture& texture, int index, bool debug)
	: pos(pos), size(size), colliderOffset(colliderOffset), colliderSize(colliderSize), weight(weight), texture(texture), index(index), debug(debug){

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
	pos.x += velocity.x / weight;
	pos.y += velocity.y / weight;
}

void PhysicsObject::calcFriction() {
	// Friction
	// staticFrictionCoefficient = initial friction force
	// kineticFrictionCoefficient =  when a object already moves
	// friction (f), frictionCoefficient (u), normalForce (N), mass (m), gravity (g)
	// 
	// f = u * N
	// N = m * g

	float normalForce = weight * gravity;
	float friction;

	if (objectStatic) {

		friction = staticFrictionCoefficient * normalForce;
	}
	else
	{
		friction = kineticFrictionCoefficient * normalForce;
	}

	float xVelocityNewton = (velocity.x * weight) - friction;
	float yVelocityNewton = (velocity.y * weight) - friction;

	if (xVelocityNewton > 0) {
		xVelocityNewton = 0.f;
	}

	if (yVelocityNewton > 0) {
		yVelocityNewton = 0.f;
	}

	addInstantForce(sf::Vector2f(xVelocityNewton / weight, yVelocityNewton / weight));
}