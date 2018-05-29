#include "Enemy.hpp"

Enemy::Enemy(const unsigned speed, const unsigned x, const sf::Texture& enemyTexture)
    : speed(speed) {
    sprite.setTexture(enemyTexture);
    sprite.setPosition(x, 0);

}

bool Enemy::checkMove() {
    int elapsedTime = clock.getElapsedTime().asMilliseconds();
    
    if (elapsedTime >= (1000 / speed)) {
	clock.restart();
	return true;
    }

    return false;
}

void Enemy::move() {
    sprite.move(0, 1);
}

const sf::Sprite& Enemy::getSprite() {
    return sprite;
}
