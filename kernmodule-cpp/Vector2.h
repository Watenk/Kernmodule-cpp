#pragma once

#include <SFML/Graphics.hpp>

namespace watenk {
	class Vector2 {
	public:
		Vector2();
		Vector2(float x, float y);
		sf::Vector2f convertToSFML();

		float x;
		float y;

	private:

	};

	Vector2 operator+(Vector2 vector1, Vector2 vector2);
	Vector2 operator-(Vector2 vector1, Vector2 vector2);
	Vector2 operator+=(Vector2 vector1, Vector2 vector2);
	Vector2 operator-=(Vector2 vector1, Vector2 vector2);
}