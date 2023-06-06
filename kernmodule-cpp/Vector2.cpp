
#include "Vector2.h"

namespace watenk {

	Vector2::Vector2() : x(0.0f), y(0.0f) {

	}

	Vector2::Vector2(float newX, float newY) : x(newX), y(newY) {

	}

	//Operator Overloading
	Vector2 operator+(Vector2 vector1, Vector2 vector2) {
		float newX = vector1.x + vector2.x;
		float newY = vector1.y + vector2.y;
		return Vector2(newX, newY);
	}

	Vector2 operator-(Vector2 vector1, Vector2 vector2) {
		float newX = vector1.x - vector2.x;
		float newY = vector1.y - vector2.y;
		return Vector2(newX, newY);
	}

	Vector2 operator+=(Vector2 vector1, Vector2 vector2) {
		float newX = vector1.x + vector2.x;
		float newY = vector1.y + vector2.y;
		return Vector2(newX, newY);
	}

	Vector2 operator-=(Vector2 vector1, Vector2 vector2) {
		float newX = vector1.x - vector2.x;
		float newY = vector1.y - vector2.y;
		return Vector2(newX, newY);
	}
}