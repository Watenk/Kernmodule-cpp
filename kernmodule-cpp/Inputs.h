#pragma once

#include "Player.h"

class Inputs : public BaseClass {
public:
	Inputs(GameManager* gameManager);
	void update() override;
	void setPlayer(Player* newPlayer);

	Player* player;

private:
	void playerInputs();

	float bulletDelayTimer = 0;

	GameManager* gameManager;
};