// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include <iostream>
#include <SFML/Graphics.hpp>

#include "main.h"

void WindowEvents(sf::RenderWindow* window, sf::Event event) {

    if (event.type == sf::Event::Closed) {
        std::cout << "Closing Window" << std::endl;
        window->close();
    }

    if (event.type == sf::Event::Resized)
    {
        std::cout << "Doesn't support resizing" << std::endl;
    }
}

int main()
{
    int screenWidth = sf::VideoMode::getDesktopMode().width;
    int screenHeight = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow* window;
    window = new sf::RenderWindow(sf::VideoMode(screenWidth / 2, screenHeight / 2), "SFML");
    window->setFramerateLimit(144);

    std::cout << "Opening Window" << std::endl;

    //Update Loop
    while (window->isOpen()) {

        sf::Event event;
        while (window->pollEvent(event))
        {
            WindowEvents(window, event);
        }
    }

    return 0;
}