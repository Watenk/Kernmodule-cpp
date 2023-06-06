#pragma once

class GameManager;

using std::string;

const int screenWidth = 1280;
const int screenHeight = 720;
const string windowName = "SFML";
const int targetFrameRate = 144;
const float UPSSpeed = 60;
const int playerSpeed = 5;

//Defined at runtime
GameManager* gameManager;