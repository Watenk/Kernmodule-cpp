#pragma once

#include "GameManager.h"

using std::string;

//Dev
const bool debug = false;
const float UPSSpeed = 60; //Physics Update Speed in frames

//WindowSettings
const int screenWidth = 1920;
const int screenHeight = 1080;
const string windowName = "SFML";
const int targetFrameRate = 144;

//Player
const int playerSpeed = 65;
const float bulletSpeed = 10; 
const float bulletDelay = 10;

//Friction
const float gravity = 9.8f;
const float massImpact = 0.02f; //The impact mass has on friction

//Collision
const int minCollisionDistance = 100; //Minium distance between 2 objects to allow collision
const float collisionForceTransfer = 90; //Percentage
const float collisionExtraDistance = 10.0f; //Some extra space between the 2 collided objects