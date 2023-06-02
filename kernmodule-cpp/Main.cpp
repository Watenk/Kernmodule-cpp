
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <list>

#include "GameSettings.h"
#include "Inputs.h"
#include "Time.h"
#include "PhysicsObject.h"
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
using std::list;

void start();
void update();
void ups();
void draw();
RenderWindow* generateWindow();
void windowEvents(RenderWindow* window, sf::Event event);
PhysicsObject* getPhysicsObject(list<PhysicsObject*> currentList, int targetIndex);
void addPhysicsObject(PhysicsObject* newObject);
bool doesItCollide(sf::Vector2f collisionVector, PhysicsObject* otherObject);

Inputs* inputs;
Watenk::Time* watenkTime;
RenderWindow* window;

//Textures
Texture* playerTexture;
Texture* robotTexture;

//Objects
list<PhysicsObject*> physicsObjects;
int physicsObjectsIndex = 0;
Player* player;

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
    start();

    while (window->isOpen()) {
        update();
    }

    return 0;
}

//-------------------------------------------------------------

void start() {
    inputs = new Inputs();
    watenkTime = new Watenk::Time;
    window = generateWindow();

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
    player = new Player(sf::Vector2f(500, 500), sf::Vector2f(2, 2), sf::Vector2f(0, 0), sf::Vector2f(1, 1), 1.3f, 50.0f, *playerTexture, physicsObjectsIndex, true);
    addPhysicsObject(player);

    //for (int i = 0; i < 20; i++) {
    //    addPhysicsObject(new PhysicsObject(sf::Vector2f(700, 500), sf::Vector2f(2, 2), sf::Vector2f(0, 0), sf::Vector2f(1, 1), 50, *robotTexture, physicsObjectsIndex, false));
    //}

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

void update() {

    inputs->update();
    watenkTime->update();

    //SFML Events
    sf::Event event;
    while (window->pollEvent(event))
    {
        windowEvents(window, event);
    }
    
    //UPS
    UPSDeltaTime += watenkTime->deltaTime;
    if (UPSDeltaTime >= 1) {
        UPSDeltaTime = 0;
        ups();
    }

    draw();
}

void ups() {
    
    for (list<PhysicsObject*>::iterator i = physicsObjects.begin(); i != physicsObjects.end(); i++) {
        PhysicsObject* object1 = *i;
        object1->ups();

        for (list<PhysicsObject*>::iterator j = physicsObjects.begin(); j != physicsObjects.end(); j++) {
            PhysicsObject* object2 = *j;

            if (doesItCollide(object1->pos, object2)) {

            }

            if (doesItCollide(object1->pos2, object2)) {

            }

            if (doesItCollide(object1->pos3, object2)) {

            }

            if (doesItCollide(object1->pos4, object2)) {

            }
        }
    }
}

void draw() {
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
    for (list<PhysicsObject*>::iterator it = physicsObjects.begin(); it != physicsObjects.end(); it++) {
        PhysicsObject currentPhysicsObject = *(*it);

        window->draw(currentPhysicsObject.sprite);
        if (currentPhysicsObject.debug) {
            window->draw(currentPhysicsObject.collisionRect1);
            window->draw(currentPhysicsObject.collisionRect2);
            window->draw(currentPhysicsObject.collisionRect3);
            window->draw(currentPhysicsObject.collisionRect4);
        }
    }

    // end the current frame
    window->display();
}

//------------------------------------------------------------------

void windowEvents(RenderWindow* window, sf::Event event) {

    if (event.type == Event::Closed) {
        cout << "Closing Window" << endl;
        window->close();
    }

    if (event.type == Event::Resized)
    {
        cout << "Doesn't support resizing" << endl;
    }
}

RenderWindow* generateWindow() {
    sf::RenderWindow* window;
    window = new RenderWindow(VideoMode(screenWidth, screenHeight), windowName, sf::Style::Fullscreen);
    cout << "Opening Window" << endl;
    window->setFramerateLimit(targetFrameRate);

    return window;
}

PhysicsObject* getPhysicsObject(list<PhysicsObject*> currentList, int targetIndex) {

    for (list<PhysicsObject*>::iterator it = physicsObjects.begin(); it != physicsObjects.end(); it++) {
        if ((*it)->getIndex() == targetIndex) {
            return *it;
        }
    }

    return NULL;
}

void addPhysicsObject(PhysicsObject* newObject) {
    physicsObjects.push_back(newObject);
    physicsObjectsIndex++;
}

bool doesItCollide(sf::Vector2f collisionVector, PhysicsObject* otherObject) {
    if (collisionVector.x > otherObject->pos.x && collisionVector.y > otherObject->pos.y && collisionVector.x < otherObject->pos4.x && collisionVector.y < otherObject->pos4.y) {
        return true;
    }
    return false;
}