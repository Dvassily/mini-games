#include "EnemyGenerator.hpp"

#include <random>

EnemyGenerator::EnemyGenerator(const sf::Texture& enemyTexture, int minSpeed, int maxSpeed, int rate, int winX)
    : enemyTexture(enemyTexture), minSpeed(minSpeed), maxSpeed(maxSpeed), rate(rate), winX(winX)
{

}

Enemy* EnemyGenerator::generate() {
    int elapsedTime = clock.getElapsedTime().asMilliseconds();

    if (elapsedTime >= 1000 / rate) {
	clock.restart();

	// TODO: Take scale into account
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distributionPosition(0, winX - enemyTexture.getSize().x);

	std::uniform_int_distribution<int> distributionSpeed(minSpeed, maxSpeed);

	Enemy* enemy = new Enemy(distributionSpeed(generator), distributionPosition(generator), enemyTexture);
	return enemy;
    }

    return nullptr;
}
