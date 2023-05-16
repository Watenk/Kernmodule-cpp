
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow* window;
    window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML");
    window->setFramerateLimit(144);

    while (window->isOpen()) {

    }

    return 0;
}
