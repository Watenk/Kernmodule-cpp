
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <list>

#include "GameData.h"
#include "GameManager.h"

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;

using std::cout;
using std::endl;

void mainStart();
void mainUpdate();
RenderWindow* generateWindow();
void windowEvents(RenderWindow* window, sf::Event event);

RenderWindow* window;

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
}

void mainUpdate() {

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
    sf::RenderWindow* window = new RenderWindow(VideoMode(screenWidth, screenHeight), windowName);
    cout << "Opening Window" << endl;
    window->setFramerateLimit(targetFrameRate);

    return window;
}