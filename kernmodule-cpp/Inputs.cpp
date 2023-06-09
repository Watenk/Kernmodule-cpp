
#include <iostream>
#include <SFML/Graphics.hpp>

#include "GlobalData.h"
#include "GameManager.h"
#include "Inputs.h"
#include "TimeManager.h"
#include "Bullet.h"

Inputs::Inputs(GameManager* gameManager) : gameManager(gameManager), player(NULL) {

}

void Inputs::update() {

    if (player != NULL) {
        playerInputs();
    }
}

void Inputs::setPlayer(Player* newPlayer) {
    player = newPlayer;
}

void Inputs::playerInputs() {
 
    //Calc Mouse Angle and pos
    sf::Vector2f mousePosSFML = gameManager->window->mapPixelToCoords(sf::Mouse::getPosition(*gameManager->window));
    watenk::Vector2 mousePos = watenk::Vector2(mousePosSFML.x, mousePosSFML.y);

    float distanceX = player->pos.x - mousePos.x;
    float distanceY = player->pos.y - mousePos.y;
    float mouseRadian = std::atan2(distanceY, distanceX);

    //calc Bullet Origin Point
    player->bulletOrigin = watenk::Vector2(player->pos.x + bulletOriginRadius * -std::cos(mouseRadian),player->pos.y + bulletOriginRadius * -std::sin(mouseRadian));

    //Mouse
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        if (bulletDelayTimer > bulletDelay) {
            //Calc BulletVelocity
            watenk::Vector2 bulletNewton(-std::cos(mouseRadian) * bulletSpeed, -std::sin(mouseRadian) * bulletSpeed);

            Bullet* newBullet = new Bullet(gameManager, watenk::Vector2(player->bulletOrigin.x, player->bulletOrigin.y), watenk::Vector2(0.5f, 0.5f), watenk::Vector2(10, 10), 1, 0);
            newBullet->addInstantForce(bulletNewton);
            gameManager->addPhysicsObject(newBullet);

            bulletDelayTimer = 0;
        }
        else {
            bulletDelayTimer += gameManager->timeManager->deltaTime;
        }
    }

    //KeyBoard
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player->addInstantForce(watenk::Vector2(0, -playerSpeed * gameManager->timeManager->deltaTime));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player->addInstantForce(watenk::Vector2(playerSpeed * gameManager->timeManager->deltaTime, 0));

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player->addInstantForce(watenk::Vector2(0, playerSpeed * gameManager->timeManager->deltaTime));

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player->addInstantForce(watenk::Vector2(-playerSpeed * gameManager->timeManager->deltaTime, 0));
    }
}