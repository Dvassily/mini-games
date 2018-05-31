#include "Enemy.hpp"

Enemy::Enemy(const unsigned speed, const unsigned x, const float scale, const sf::Texture& enemyTexture)
    : speed(speed) {
    sprite.setTexture(enemyTexture);
    sprite.setPosition(x, 0);
    sprite.setScale(scale, scale);
}

void Enemy::move() {
    int elapsedTime = clock.getElapsedTime().asMilliseconds();
    
    if (elapsedTime >= (1000 / speed)) {
	clock.restart();
	sprite.move(0, 1);
    }
}

const sf::Sprite& Enemy::getSprite() {
    return sprite;
}
