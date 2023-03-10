#include "Move.h"

void Move::move(const float &speed, sf::Sprite &sprite) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {//Right
        sprite.move(speed, 0);
        sprite.setRotation(270);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //Up
        sprite.move(0, -speed);
        sprite.setRotation(180);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //Left
        sprite.move(-speed, 0);
        sprite.setRotation(90);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // Down
        sprite.move(0, speed);
        sprite.setRotation(0);
    }

}

