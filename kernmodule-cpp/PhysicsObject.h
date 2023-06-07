#pragma once

#include "BaseClass.h"

#include "Vector2.h"

class GameManager;

class PhysicsObject : public BaseClass {

public:
	PhysicsObject(GameManager* gamemanager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderOffset, watenk::Vector2 colliderSize, float mass, sf::Texture& texture, int index, bool debug);
	virtual void update() override;
	virtual void ups() override;
	void addInstantForce(watenk::Vector2 newVelocity);
	int getIndex();

	int index;
	watenk::Vector2 pos;
	watenk::Vector2 pos2; // top right
	watenk::Vector2 pos3; // bottom left
	watenk::Vector2 pos4; // bottom right
	watenk::Vector2 size;
	watenk::Vector2 colliderOffset;
	watenk::Vector2 colliderSize;
	sf::Sprite sprite;
	float mass;
	bool objectStatic;

	//Settings
	float staticFrictionCoefficient = 0.12f;
	float kineticFrictionCoefficient = 0.1f;
	float gravity = 9.8f;
	float staticTreshhold = 0.1f;

	//Debug
	bool debug;
	sf::RectangleShape collisionRect1;
	sf::RectangleShape collisionRect2;
	sf::RectangleShape collisionRect3;
	sf::RectangleShape collisionRect4;

protected:
	void physics();
	void friction();
	void collision();
	watenk::Vector2 convertNewtonToVelocity(watenk::Vector2 newton, float mass);
	watenk::Vector2 convertVelocityToNewton(watenk::Vector2 velocity, float mass);
	watenk::Vector2 calcFriction(watenk::Vector2 normalForce, float frictionCoefficient);

	sf::Texture texture;
	watenk::Vector2 velocity;
	float width;
	float height;

	GameManager* gameManager;
};