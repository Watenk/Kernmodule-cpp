#pragma once

class PhysicsObject {

public:
	PhysicsObject(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f colliderOffset, sf::Vector2f colliderSize, float mass, sf::Texture& texture, int index, bool debug);
	virtual void ups();
	void addInstantForce(sf::Vector2f newVelocity);
	int getIndex();

	int index;
	sf::Vector2f pos;
	sf::Vector2f pos2; // top right
	sf::Vector2f pos3; // bottom left
	sf::Vector2f pos4; // bottom right
	sf::Vector2f size;
	sf::Vector2f colliderOffset;
	sf::Vector2f colliderSize;
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
	sf::Vector2f convertNewtonToVelocity(sf::Vector2f newton, float mass);
	sf::Vector2f convertVelocityToNewton(sf::Vector2f velocity, float mass);
	sf::Vector2f calcFriction(sf::Vector2f normalForce, float frictionCoefficient);

	sf::Texture texture;
	sf::Vector2f velocity;
	float width;
	float height;
};