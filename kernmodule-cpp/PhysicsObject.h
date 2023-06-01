#pragma once

class PhysicsObject {

public:
	PhysicsObject(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f colliderOffset, sf::Vector2f colliderSize, int mass, sf::Texture& texture, int index, bool debug);
	void ups();
	void addInstantForce(sf::Vector2f newVelocity);
	int getIndex();

	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Vector2f colliderOffset;
	sf::Vector2f colliderSize;
	int mass;
	bool debug;
	bool objectStatic;
	float staticFrictionCoefficient = 0.8f;
	float kineticFrictionCoefficient = 0.5f;
	float gravity = 9.8f; 
	sf::Sprite sprite;

private:
	void physics();
	void calcFriction();
	sf::Vector2f convertNewtonToVelocity(sf::Vector2f newton, float mass);
	sf::Vector2f convertVelocityToNewton(sf::Vector2f velocity, float mass);
	sf::Vector2f calcFriction(sf::Vector2f normalForce, float frictionCoefficient);

	sf::Texture texture;
	sf::Vector2f velocity;
	int index;
};