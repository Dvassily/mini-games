#include "Player.hpp"
#include <iostream>

Player::Player(const sf::Texture& playerTexture, const unsigned speed, const unsigned winX, const unsigned winY)
    : speed(speed), winX(winX), winY(winY) {
    sprite.setTexture(playerTexture);
    reset();
}

void Player::move() {
    int elapsedTime = clock.getElapsedTime().asMilliseconds();
    bool mustMove = true;
    
    // if (elapsedTime >= (1000 / speed)) {
    // 	clock.restart();
    // 	mustMove = true;
    // }

    if (mustMove) {
	switch(currentMove) {
	case UP:
	    sprite.move(0, -5);
	    break;
	case DOWN:
	    sprite.move(0, 5);
	    break;
	case LEFT:
	    sprite.move(-5, 0);
	    break;
	case RIGHT:
	    sprite.move(5, 0);
	    break;
	}
    }
}

void Player::startMove(Move move) {
    this->currentMove = move;
}

void Player::endMove() {
    this->currentMove = STATIC;
}

void Player::reset() {
    sprite.setPosition(sf::Vector2f(winX / 2 - sprite.getTexture()->getSize().x / 2, winY - sprite.getTexture()->getSize().y));    
}

sf::Sprite& Player::getSprite() {
    return sprite;
}
