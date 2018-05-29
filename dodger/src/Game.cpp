#include "Game.hpp"
#include <random>
#include <iostream>

Game::Game(const sf::Texture& playerTexture, const sf::Texture& enemyTexture, sf::RenderWindow& window, int enemyRate)
    : enemyTexture(enemyTexture), window(window), enemyRate(enemyRate)
{
    playerSprite.setTexture(playerTexture);
    font.loadFromFile("res/LiberationMono-Bold.ttf");
    gameOverText.setString(gameOverString);
    gameOverText.setFont(font);
    initText.setString(initString);
    initText.setFont(font);
}

void Game::render() {
    window.clear(sf::Color(15, 15, 15));

    if (state == END) {
	window.draw(gameOverText);
    } else if (state == INIT) {
	window.draw(initText);
    } else if (state == IN_PROGRESS) {
	window.draw(playerSprite);

	for (Enemy* enemy : enemies) {
	    window.draw(enemy->getSprite());
	}
    }
    
    window.display();
}

void Game::moveEnemies() {
    for (Enemy* enemy : enemies) {
	if (enemy->checkMove()) {
	    enemy->move();
	}
    }
}

void Game::movePlayerLeft() {
    playerSprite.move(sf::Vector2f(-moveOffset, 0));
}

void Game::movePlayerRight() {
    playerSprite.move(sf::Vector2f(moveOffset, 0));
}

void Game::movePlayerDown() {
    playerSprite.move(sf::Vector2f(0, moveOffset));
}

void Game::movePlayerUp() {
    playerSprite.move(sf::Vector2f(0, -moveOffset));
}

bool Game::checkAddEnemy() {
    int elapsedTime = clock.getElapsedTime().asMilliseconds();

    if (elapsedTime >= enemyRate) {
	clock.restart();
	return true;
    }

    return false;
}

void Game::addEnemy() {
    // TODO: Take scale into account
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, window.getSize().x - enemyTexture.getSize().x);
    unsigned xPosition = distribution(generator);

    Enemy* enemy = new Enemy(5, xPosition, enemyTexture);
    enemies.push_back(enemy);
}

bool Game::checkCollision() {
    for (Enemy* enemy : enemies) {
	if (enemy->getSprite().getGlobalBounds().intersects(playerSprite.getGlobalBounds())) {
	    return true;
	}
    }
    std::cout << "foo" << std::endl;

    return false;
}

void Game::stop() {
    state = END;
}

void Game::start() {
    playerSprite.setPosition(sf::Vector2f(window.getSize().x / 2 - playerSprite.getTexture()->getSize().x / 2, window.getSize().y - playerSprite.getTexture()->getSize().y));

    state = IN_PROGRESS;
}

bool Game::isInProgress() {
    return state == IN_PROGRESS;
}
