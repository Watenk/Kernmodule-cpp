#pragma once

namespace Watenk {
	class Time {
	public:
		Time();
		void Update();
		float deltaTime = 0;
		int frameTime = 0;
		int frameRate = 0;

	private:
		sf::Clock clock;
		int previousFrame = 0;
	};
}