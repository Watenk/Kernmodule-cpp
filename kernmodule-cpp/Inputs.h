#pragma once

#include "Player.h"

class Inputs : public BaseClass {
public:
	Inputs(GameManager* gameManager);
	void update() override;
	void setPlayer(Player* newPlayer);
	watenk::Vector2 mousePos;

	Player* player;

	bool isShooting = false;
	float playerDashTimer = 0;
	float playerBurstTimer = 0;
	
private:
	void mainMenuInputs();
	void playerInputs();

	GameManager* gameManager;

	float playerShootingSpeed = 0;
	float playerShootSpeedTimer = 0;
	bool burst = false;
	float playerBurstDurationTimer = 0;
};