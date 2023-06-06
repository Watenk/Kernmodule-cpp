#pragma once

namespace watenk {
	class Vector2 {
	public:
		Vector2();
		Vector2(float x, float y);

		float x;
		float y;

	private:

	};

	Vector2 operator+(Vector2 vector1, Vector2 vector2);
	Vector2 operator-(Vector2 vector1, Vector2 vector2);
	Vector2 operator+=(Vector2 vector1, Vector2 vector2);
	Vector2 operator-=(Vector2 vector1, Vector2 vector2);
}