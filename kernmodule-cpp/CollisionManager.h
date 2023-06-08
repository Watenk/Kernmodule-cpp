#pragma once

#include <list>

#include "Vector2.h"
#include "PhysicsObject.h"

using std::list;

class GameManager;

class CollisionManager : public BaseClass {
public:
	CollisionManager(GameManager* gameManager);
	void ups() override;

private:
	float getDistance(PhysicsObject* object1, PhysicsObject* object2);
	bool checkCollision(PhysicsObject* object1, PhysicsObject* object2);
	void doCollision(PhysicsObject* object1, PhysicsObject* object2);
	bool listContains(PhysicsObject* object);

	list<PhysicsObject*> calcedObjects;
	GameManager* gameManager;
};