
#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameSettings.h"
#include "Player.h"

Player::Player(sf::Vector2f pos, sf::Texture& texture) : pos(pos), texture(texture) {
	sprite.setTexture(texture);
	sprite.setScale(3, 3);
	sprite.setPosition(pos);
}

void Player::Update() {
	sprite.setPosition(pos);

}

void Player::Move(sf::Vector2f direction) {

	pos.x += direction.x;
	pos.y += direction.y;

	if (pos.x < 0) {
		pos.x = 0;
	}

	if (pos.x > screenWidth) {
		pos.x = screenWidth;
	}

	if (pos.y < 0) {
		pos.y = 0;
	}

	if (pos.y > screenHeight) {
		pos.y = screenHeight;
	}
}