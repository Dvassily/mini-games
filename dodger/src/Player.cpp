#include "Player.hpp"
#include <iostream>

Player::Player(const sf::Texture& playerTexture, const int speed, const unsigned winX, const unsigned winY)
    : speed(speed), winX(winX), winY(winY) {
    sprite.setTexture(playerTexture);
    reset();
}

void Player::move() {
    int moveX = 0;
    int moveY = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	moveY = -speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	moveY = speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	moveX = -speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	moveX = speed;
    }

    int newX = sprite.getPosition().x + moveX;
    int newY = sprite.getPosition().y + moveY;

    if (newX >= 0 && newX + sprite.getTexture()->getSize().x <= winX &&
	newY >= 0 && newY + sprite.getTexture()->getSize().y <= winY) {
	sprite.move(moveX, moveY);
    }
}

void Player::reset() {
    sprite.setPosition(sf::Vector2f(winX / 2 - sprite.getTexture()->getSize().x / 2, winY - sprite.getTexture()->getSize().y));    
}

sf::Sprite& Player::getSprite() {
    return sprite;
}
