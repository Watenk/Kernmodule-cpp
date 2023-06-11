#pragma once

#include "GameManager.h"

using std::string;

//Dev
const bool debug = false;

//WindowSettings
const int screenWidth = 1920;
const int screenHeight = 1080;
const string windowName = "SFML";
const int targetFrameRate = 144;

//GameSettings
const float difficulty = 1.0f;
const float UPSSpeed = 60.0f; //Physics Update Speed per second
const int timeScore = 1; //Every second
const float gameOverTime = 5; //Time the gameOver screen is visible
const bool ifShootingNoTimeScore = true;

//Player
const int playerSpeed = 65;
const float playerMass = 50.0f; //The mass will impact the speed!
const int playerHealth = 25;
const float playerShootSpeed = 5.0f; //Delay between bullet shots in ups
const float playerBulletOriginRadius = 50.0f; //Radius around player the bullet origin point rotates

//Powers
const int dashDelay = 5; // in Seconds
const float dashMultiplier = 300; //Strenght of the dash
const int burstDelay = 30; // in Seconds
const float burstSpeed = 1.0f; //Delay between bullet shots in ups
const int burstDuration = 5; //In Seconds

//Bullets
const float bulletSpeed = 150.0f;
const float bulletMass = 5.0f; //The mass will impact the speed!
const int bulletLifeTime = 200; //Updates a bullet will despawn;

//Friction
const float gravity = 9.8f;
const float massImpact = 0.02f; //The impact mass has on friction

//Collision
const int minCollisionDistance = 100; //Minium distance between 2 objects to allow collision
const float collisionForceTransfer = 90.0f; //Percentage
const float collisionExtraDistance = 10.0f; //Some extra space between the 2 collided objects
const float newtonDamage = 50.0f; //How much newton for 1 hp damage

//Robot
const float robotMass = 50.0f; //The mass will impact the speed!
const int robotKillScoreAmount = 50; //Score gained when a robot dies
const int robotKillHealthAmount = 1; //Health gained when killing a enemy
const float robotBulletOriginRadius = 100.0f; //Radius around robot the bullet origin point rotates
const float robotPlayerTargetDistance = 150.0f; //The target Distance between the player and the robot

//Robot dynamic base values (changes based on score)
const int robotHealth = 3;
const float robotSpeed = 50.0f;
const int robotShootInaccuracy = 400; //Amount a robot can miss a shot
const float robotShootSpeed = 60.0f; // Delay between bullet shots