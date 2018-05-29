#include "Player.hpp"
#include <iostream>

Player::Player(const sf::Texture& playerTexture, unsigned winX, unsigned winY)
    : winX(winX), winY(winY) {
    sprite.setTexture(playerTexture);
    reset();
}

void Player::move() {
    switch(currentMove) {
    case UP:
	sprite.move(0, -1);
	break;
    case DOWN:
	sprite.move(0, 1);
	break;
    case LEFT:
	sprite.move(-1, 0);
	break;
    case RIGHT:
	sprite.move(1, 0);
	break;
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
