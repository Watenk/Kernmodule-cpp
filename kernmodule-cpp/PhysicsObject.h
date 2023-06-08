#pragma once

#include "BaseClass.h"

#include "Vector2.h"

using std::string;

class GameManager;

class PhysicsObject : public BaseClass {

public:
	PhysicsObject(GameManager* gamemanager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, sf::Texture& texture, int index);
	virtual void update() override;
	virtual void ups() override;
	void addInstantForce(watenk::Vector2 newVelocity);
	int getIndex();

	int index;
	watenk::Vector2 pos;
	watenk::Vector2 size;
	watenk::Vector2 velocity;
	watenk::Vector2 colliderSize;
	sf::Sprite sprite;
	float mass;
	bool objectStatic;

	//Collision
	watenk::Vector2 topLeft;
	watenk::Vector2 topRight;
	watenk::Vector2 bottomLeft;
	watenk::Vector2 bottomRight; 

	//Settings
	float staticFrictionCoefficient = 0.12f;
	float kineticFrictionCoefficient = 0.1f;
	float gravity = 9.8f;
	float staticTreshhold = 0.1f;

	//Debug
	sf::RectangleShape collisionRect1;
	sf::RectangleShape collisionRect2;
	sf::RectangleShape collisionRect3;
	sf::RectangleShape collisionRect4;

protected:
	void friction();
	void colliders();
	watenk::Vector2 convertNewtonToVelocity(watenk::Vector2 newton, float mass);
	watenk::Vector2 convertVelocityToNewton(watenk::Vector2 velocity, float mass);
	watenk::Vector2 calcFriction(watenk::Vector2 normalForce, float frictionCoefficient);
	sf::Text getText(string string, watenk::Vector2 pos);

	sf::Texture texture;
	float width;
	float height;

	GameManager* gameManager;
};