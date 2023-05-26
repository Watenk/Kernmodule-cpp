
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "Robot.h"

using sf::RenderWindow;
using sf::VideoMode;
using sf::Texture;
using sf::Sprite;
using sf::Event;
using sf::Clock;
using sf::Text;
using sf::Color;
using sf::Font;

using std::cout;
using std::endl;
using std::string;
using std::to_string;

//Functions
void Start();
void Update();
void UPS();
void Draw();
RenderWindow* GenerateWindow();
void WindowEvents(RenderWindow* window, Event event);
void CalcFrameRate();

//Settings
int screenWidth = 1280;
int screenHeight = 720;
string windowName = "SFML";
int targetFrameRate = 144;
float UPSSpeed = 60;

//Textures
Texture* robotTexture;

//Robots
Robot* robots[10000];

//Text
Font* oswaldRegular;
Font* oswaldMedium;

//FPS
int frameRate;
int previousFrame;
float deltaTime;
float UPSDeltaTime;

RenderWindow* window;
Clock* sfClock;

int main()
{
    Start();

    while (window->isOpen()) {
        Update();
    }

    return 0;
}

//--------------------------------------------------------------

void Start() {
    window = GenerateWindow();
    sfClock = new Clock();

    //textures
    robotTexture = new Texture();
    if (!robotTexture->loadFromFile("Textures/robot.png"))
    {
        cout << "Textures/robot.png missing!" << endl;
    }

    //Robots
    for (int i = 0; i < sizeof(robots) / sizeof(Robot*); i++) {

        robots[i] = new Robot(sf::Vector2f(100, 100), *robotTexture, screenWidth, screenHeight);
    }

    //text
    oswaldRegular = new Font();
    if (!oswaldRegular->loadFromFile("Fonts/oswaldRegular.ttf"))
    {
        cout << "Fonts/oswaldRegular.ttf missing!" << endl;
    }
    oswaldMedium = new Font();
    if (!oswaldMedium->loadFromFile("Fonts/oswaldMedium.ttf"))
    {
        cout << "Fonts/oswaldMedium.ttf missing!" << endl;
    }
}

void Update() {

    //SFML Events
    sf::Event event;
    while (window->pollEvent(event))
    {
        WindowEvents(window, event);
    }
    
    CalcFrameRate();

    UPSDeltaTime += deltaTime;
    if (UPSDeltaTime >= 1) {
        UPSDeltaTime = 0;
        UPS();
    }

    Draw();
}

void UPS() {

    //Robots
    for (int i = 0; i < sizeof(robots) / sizeof(Robot*); i++) {
        robots[i]->Update();
    }
}

void Draw() {
    // clear the window with black color
    window->clear(Color::Black);

    //FPS Text
    Text fpsText;
    fpsText.setFont(*oswaldRegular);
    fpsText.setString(to_string(frameRate));
    fpsText.setCharacterSize(15);
    fpsText.setFillColor(Color::White);
    window->draw(fpsText);

    for (int i = 0; i < sizeof(robots) / sizeof(Robot*); i++) {
        window->draw(robots[i]->sprite);
    }

    // end the current frame
    window->display();
}

//------------------------------------------------------------------

void WindowEvents(RenderWindow* window, sf::Event event) {

    if (event.type == Event::Closed) {
        cout << "Closing Window" << endl;
        window->close();
    }

    if (event.type == Event::Resized)
    {
        cout << "Doesn't support resizing" << endl;
    }
}

RenderWindow* GenerateWindow() {
    sf::RenderWindow* window;
    window = new RenderWindow(VideoMode(screenWidth, screenHeight), windowName);
    cout << "Opening Window" << endl;
    window->setFramerateLimit(targetFrameRate);

    return window;
}

void CalcFrameRate() {
    int elapsedTime = sfClock->getElapsedTime().asMicroseconds();
    int frameTime = elapsedTime - previousFrame;
    frameRate = 1000000 / frameTime;
    previousFrame = elapsedTime;

    deltaTime = UPSSpeed / frameRate;
}