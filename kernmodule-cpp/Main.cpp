
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <list>

#include "GameSettings.h"
#include "GameManager.h"

//#include "Inputs.h"
//#include "Time.h"
//#include "PhysicsObject.h"
//#include "Player.h"

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;

using std::cout;
using std::endl;

void mainStart();
void mainUpdate();
void mainUps();
RenderWindow* generateWindow();
void windowEvents(RenderWindow* window, sf::Event event);
//PhysicsObject* getPhysicsObject(list<PhysicsObject*> currentList, int targetIndex);
//void addPhysicsObject(PhysicsObject* newObject);
//bool doesItCollide(sf::Vector2f collisionVector, PhysicsObject* otherObject);

//Inputs* inputs;
RenderWindow* window;
GameManager* gameManager;

////Textures
//Texture* playerTexture;
//Texture* robotTexture;

////Objects
//list<PhysicsObject*> physicsObjects;
//int physicsObjectsIndex = 0;
//Player* player;

int main()
{
    mainStart();

    while (window->isOpen()) {
        mainUpdate();
    }

    return 0;
}

//-------------------------------------------------------------

void mainStart() {

    window = generateWindow();
    gameManager = new GameManager(window);
    //inputs = new Inputs();

    ////Objects
    //player = new Player(sf::Vector2f(500, 500), sf::Vector2f(2, 2), sf::Vector2f(0, 0), sf::Vector2f(1, 1), 1.3f, 50.0f, *playerTexture, physicsObjectsIndex, true);
    //addPhysicsObject(player);

    ////for (int i = 0; i < 20; i++) {
    ////    addPhysicsObject(new PhysicsObject(sf::Vector2f(700, 500), sf::Vector2f(2, 2), sf::Vector2f(0, 0), sf::Vector2f(1, 1), 50, *robotTexture, physicsObjectsIndex, false));
    ////}
}

void mainUpdate() {

    //inputs->update();

    //SFML Events
    sf::Event event;
    while (window->pollEvent(event))
    {
        windowEvents(window, event);
    }

    window->clear(Color::Black);
    
    gameManager->update();

    window->display();
}

void mainUps() {
    
    //for (list<PhysicsObject*>::iterator i = physicsObjects.begin(); i != physicsObjects.end(); i++) {
    //    PhysicsObject* object1 = *i;
    //    object1->ups();

    //    for (list<PhysicsObject*>::iterator j = physicsObjects.begin(); j != physicsObjects.end(); j++) {
    //        PhysicsObject* object2 = *j;

    //        if (doesItCollide(object1->pos, object2)) {

    //        }

    //        if (doesItCollide(object1->pos2, object2)) {

    //        }

    //        if (doesItCollide(object1->pos3, object2)) {

    //        }

    //        if (doesItCollide(object1->pos4, object2)) {

    //        }
    //    }
    //}
}

//void draw() {
    // clear the window with black color

    ////Text
    //Text fpsText;


    ////Objects
    //for (list<PhysicsObject*>::iterator it = physicsObjects.begin(); it != physicsObjects.end(); it++) {
    //    PhysicsObject currentPhysicsObject = *(*it);

    //    window->draw(currentPhysicsObject.sprite);
    //    if (currentPhysicsObject.debug) {
    //        window->draw(currentPhysicsObject.collisionRect1);
    //        window->draw(currentPhysicsObject.collisionRect2);
    //        window->draw(currentPhysicsObject.collisionRect3);
    //        window->draw(currentPhysicsObject.collisionRect4);
    //    }
    //}

    // end the current frame
//}

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
    sf::RenderWindow* window = new RenderWindow(VideoMode(screenWidth, screenHeight), windowName, sf::Style::Fullscreen);
    cout << "Opening Window" << endl;
    window->setFramerateLimit(targetFrameRate);

    return window;
}

//PhysicsObject* getPhysicsObject(list<PhysicsObject*> currentList, int targetIndex) {
//
//    for (list<PhysicsObject*>::iterator it = physicsObjects.begin(); it != physicsObjects.end(); it++) {
//        if ((*it)->getIndex() == targetIndex) {
//            return *it;
//        }
//    }
//
//    return NULL;
//}

//void addPhysicsObject(PhysicsObject* newObject) {
//    physicsObjects.push_back(newObject);
//    physicsObjectsIndex++;
//}

//bool doesItCollide(sf::Vector2f collisionVector, PhysicsObject* otherObject) {
//    if (collisionVector.x > otherObject->pos.x && collisionVector.y > otherObject->pos.y && collisionVector.x < otherObject->pos4.x && collisionVector.y < otherObject->pos4.y) {
//        return true;
//    }
//    return false;
//}