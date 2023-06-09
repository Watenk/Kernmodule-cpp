#pragma once

#include "Player.h"

class Inputs : public BaseClass {
public:
	Inputs(GameManager* gameManager);
	void update() override;
	void setPlayer(Player* newPlayer);

	Player* player;

private:
	void mainMenuInputs();
	void playerInputs();

	watenk::Vector2 mousePos;
	float bulletDelayTimer = 0;

	GameManager* gameManager;
};