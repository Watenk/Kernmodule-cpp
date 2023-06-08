
#include <iostream>
#include <SFML/Graphics.hpp>

#include "PhysicsObject.h"
#include "GlobalData.h"
#include "GameManager.h"

using std::to_string;

PhysicsObject::PhysicsObject(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, sf::Texture& texture, int index)
	: gameManager(gameManager), pos(pos), size(size), colliderSize(colliderSize), mass(mass), texture(texture), index(index), objectStatic(false){

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
	sprite.setPosition(watenk::Vector2(pos.x - width / 2, pos.y - height / 2).convertToSFML());
	gameManager->window->draw(sprite);

	if (debug) {
		gameManager->window->draw(collisionRect1);
		gameManager->window->draw(collisionRect2);
		gameManager->window->draw(collisionRect3);
		gameManager->window->draw(collisionRect4);

		gameManager->window->draw(getText("Velocity: " + to_string((int)velocity.x) + ", " + to_string((int)velocity.y), watenk::Vector2(pos.x - width / 2, pos.y - height)));
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

void PhysicsObject::addInstantForce(watenk::Vector2 extraVelocity) {
	velocity.x += extraVelocity.x;
	velocity.y += extraVelocity.y;
}

int PhysicsObject::getIndex() {
	return index;
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

sf::Text PhysicsObject::getText(string string, watenk::Vector2 pos) {
	sf::Text text;
	text.setFont(gameManager->fontManager->oswaldMedium);
	text.setString(string);
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::White);
	text.setPosition(pos.convertToSFML());
	return text;
}