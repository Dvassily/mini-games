#include "Enemy.hpp"

Enemy::Enemy(const unsigned speed, const unsigned x, const float scale, const sf::Texture& enemyTexture)
    : speed(speed) {
    sprite.setTexture(enemyTexture);
    sprite.setPosition(x, 0);
    sprite.setScale(scale, scale);
}

void Enemy::move() {
    sprite.move(0, speed);
}

const sf::Sprite& Enemy::getSprite() {
    return sprite;
}
