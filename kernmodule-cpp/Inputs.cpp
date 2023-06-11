
#include <iostream>
#include <SFML/Graphics.hpp>

#include "GlobalData.h"
#include "GameManager.h"
#include "Inputs.h"
#include "TimeManager.h"
#include "Bullet.h"

Inputs::Inputs(GameManager* gameManager) : gameManager(gameManager), player(NULL), playerShootingSpeed(playerShootSpeed){

}

void Inputs::update() {

    //Calc Mouse Angle and pos
    sf::Vector2f mousePosSFML = gameManager->window->mapPixelToCoords(sf::Mouse::getPosition(*gameManager->window));
    mousePos = watenk::Vector2(mousePosSFML.x, mousePosSFML.y);

    if (player != NULL) {
        playerInputs();
    }

    if (gameManager->sceneManager->currentScene == "MainMenu") {
        mainMenuInputs();
    }
}

void Inputs::setPlayer(Player* newPlayer) {
    player = newPlayer;
}

void Inputs::mainMenuInputs() {

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        //Player clicks on play button
        if (mousePos.x > screenWidth / 2 - 90 && mousePos.y > screenHeight - 200 && mousePos.x < screenWidth / 2 - 90 + 200 && mousePos.y < screenHeight - 200 + 50) {
            gameManager->sceneManager->loadScene("Lvl01");
        }
    }
}

void Inputs::playerInputs() {

    //Mouse
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        isShooting = true;

        if (playerShootSpeedTimer > playerShootingSpeed) {
            //Calc radian player to mouse
            float distanceX = player->pos.x - mousePos.x;
            float distanceY = player->pos.y - mousePos.y;

            if (burst) {
                if ((std::rand() % 10 + 1) <= 5) {
                    distanceX += (std::rand() % 100 + 1);
                    distanceY += (std::rand() % 100 + 1);
                }
                else {
                    distanceX -= (std::rand() % 100 + 1);
                    distanceY -= (std::rand() % 100 + 1);
                }
            }

            float mouseRadian = std::atan2(distanceY, distanceX);

            //calc Bullet Origin Point
            player->playerBulletOrigin = watenk::Vector2(player->pos.x + playerBulletOriginRadius * -std::cos(mouseRadian), player->pos.y + playerBulletOriginRadius * -std::sin(mouseRadian));

            //Calc BulletVelocity
            watenk::Vector2 bulletNewton(-std::cos(mouseRadian) * bulletSpeed, -std::sin(mouseRadian) * bulletSpeed);

            Bullet* newBullet = new Bullet(gameManager, watenk::Vector2(player->playerBulletOrigin.x, player->playerBulletOrigin.y), watenk::Vector2(0.5f, 0.5f), watenk::Vector2(8, 8), bulletMass);
            newBullet->addInstantForce(bulletNewton);
            gameManager->addPhysicsObject(newBullet);

            playerShootSpeedTimer = 0;
        }
        else {
            playerShootSpeedTimer += gameManager->timeManager->upsTime;
        }
    }
    else {
        isShooting = false;
    }

    //KeyBoard
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        player->addInstantForce(watenk::Vector2(0, -playerSpeed * gameManager->timeManager->upsTime));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        player->addInstantForce(watenk::Vector2(playerSpeed * gameManager->timeManager->upsTime, 0));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        player->addInstantForce(watenk::Vector2(0, playerSpeed * gameManager->timeManager->upsTime));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        player->addInstantForce(watenk::Vector2(-playerSpeed * gameManager->timeManager->upsTime, 0));
    }

    //Powers
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && playerDashTimer >= dashDelay) {

        float newXVelocity = playerMass * dashMultiplier * (player->velocity.x / 100);
        float newYVelocity = playerMass * dashMultiplier * (player->velocity.y / 100);

        player->velocity.x = 0.0f;
        player->velocity.y = 0.0f;

        player->addInstantForce(watenk::Vector2(newXVelocity, newYVelocity));
        playerDashTimer = 0;
    }
    else {
        playerDashTimer += gameManager->timeManager->deltaTime;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && playerBurstTimer >= burstDelay) {

        playerShootingSpeed = burstSpeed;
        burst = true;
        playerBurstTimer = 0;
    }
    else {
        playerBurstTimer += gameManager->timeManager->deltaTime;
    }

    if (burst) {
        playerBurstDurationTimer += gameManager->timeManager->deltaTime; 

        if (playerBurstDurationTimer >= burstDuration) {
            playerBurstDurationTimer = 0;
            burst = false;
            playerShootingSpeed = playerShootSpeed;
        }
    }
}