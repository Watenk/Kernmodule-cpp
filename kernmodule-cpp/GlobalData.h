#pragma once

#include "GameManager.h"

using std::string;

//Dev
const bool debug = true;

//WindowSettings
const int screenWidth = 1920;
const int screenHeight = 1080;
const string windowName = "SFML";
const int targetFrameRate = 144;

//GameSettings
const float difficulty = 1.0f; //lower value == Harder
const float UPSSpeed = 60; //Physics Update Speed in frames

//Player
const int playerSpeed = 65;

//Bullets
const float bulletSpeed = 30;
const float bulletDelay = 10; // Delay between bullet shots
const float bulletOriginRadius = 50; //Radius around player the bullet origin point rotates
const int bulletLifeTime = 200; //Updates a bullet will despawn;

//Friction
const float gravity = 9.8f;
const float massImpact = 0.02f; //The impact mass has on friction

//Collision
const int minCollisionDistance = 100; //Minium distance between 2 objects to allow collision
const float collisionForceTransfer = 90; //Percentage
const float collisionExtraDistance = 10.0f; //Some extra space between the 2 collided objects