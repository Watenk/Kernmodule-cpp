
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "GameSettings.h"
#include "Inputs.h"
#include "Time.h"
#include "Robot.h"
#include "Player.h"

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

Inputs* inputs;
Watenk::Time* watenkTime;
RenderWindow* window;

//Textures
Texture* playerTexture;
Texture* robotTexture;

//Objects
Player* player;
Robot* robots[20];

//Text
Font* oswaldRegular;
Font* oswaldMedium;

//FPS
int frameRate;
int previousFrame;
float deltaTime;
float UPSDeltaTime;

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
    inputs = new Inputs();
    watenkTime = new Watenk::Time;
    window = GenerateWindow();

    //textures
    playerTexture = new Texture();
    if (!playerTexture->loadFromFile("Textures/player.png"))
    {
        cout << "Textures/player.png missing!" << endl;
    }

    robotTexture = new Texture();
    if (!robotTexture->loadFromFile("Textures/robot.png"))
    {
        cout << "Textures/robot.png missing!" << endl;
    }

    //Objects
    player = new Player(sf::Vector2f(screenWidth / 2, screenHeight - 100), *playerTexture);
    
    for (int i = 0; i < sizeof(robots) / sizeof(Robot*); i++) {

        robots[i] = new Robot(sf::Vector2f(100, 100), *robotTexture);
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

    inputs->Update();
    watenkTime->Update();

    //SFML Events
    sf::Event event;
    while (window->pollEvent(event))
    {
        WindowEvents(window, event);
    }
    
    //UPS
    UPSDeltaTime += watenkTime->deltaTime;
    if (UPSDeltaTime >= 1) {
        UPSDeltaTime = 0;
        UPS();
    }

    Draw();
}

void UPS() {

    player->Update();

    //Robots
    for (int i = 0; i < sizeof(robots) / sizeof(Robot*); i++) {
        robots[i]->Update();
    }
}

void Draw() {
    // clear the window with black color
    window->clear(Color::Black);

    //Text
    Text fpsText;
    fpsText.setFont(*oswaldRegular);
    fpsText.setString(to_string(watenkTime->frameRate));
    fpsText.setCharacterSize(15);
    fpsText.setFillColor(Color::White);
    window->draw(fpsText);

    //Objects
    window->draw(player->sprite);

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
    window = new RenderWindow(VideoMode(screenWidth, screenHeight), windowName, sf::Style::Fullscreen);
    cout << "Opening Window" << endl;
    window->setFramerateLimit(targetFrameRate);

    return window;
}