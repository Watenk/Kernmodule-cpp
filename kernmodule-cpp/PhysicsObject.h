#pragma once

#include "BaseClass.h"

#include "Vector2.h"

using std::string;

class GameManager;

class PhysicsObject : public BaseClass {

public:
	PhysicsObject(GameManager* gameManager, watenk::Vector2 pos, watenk::Vector2 size, watenk::Vector2 colliderSize, float mass, int health, sf::Texture& texture);
	virtual void update() override;
	virtual void ups() override;
	virtual void doDamage(int hp);
	void addInstantForce(watenk::Vector2 extraNewton);
	void removeInstantForce(watenk::Vector2 removedNewton);

	bool deleteObject = false;
	watenk::Vector2 pos;
	watenk::Vector2 size;
	watenk::Vector2 velocity;
	watenk::Vector2 colliderSize;
	sf::Sprite sprite;
	int health;
	float mass;

	//Collision
	watenk::Vector2 topLeft;
	watenk::Vector2 topRight;
	watenk::Vector2 bottomLeft;
	watenk::Vector2 bottomRight; 

	//Settings
	float staticFrictionCoefficient = 0.12f;
	float kineticFrictionCoefficient = 0.1f;
	float staticTreshhold = 0.1f;

	//Debug
	sf::RectangleShape collisionRect1;
	sf::RectangleShape collisionRect2;
	sf::RectangleShape collisionRect3;
	sf::RectangleShape collisionRect4;

protected:
	void friction();
	void colliders();

	bool objectStatic;
	sf::Texture texture;
	float width;
	float height;

	GameManager* gameManager;
};