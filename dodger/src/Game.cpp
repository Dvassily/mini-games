#include "Game.hpp"

Game::Game(sf::RenderWindow& window, Player& player)
    : window(window), player(player)
{
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
	window.draw(player.getSprite());

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

void Game::addEnemy(Enemy* const enemy) {
    enemies.push_back(enemy);
}

bool Game::checkCollision() {
    for (Enemy* enemy : enemies) {
	if (enemy->getSprite().getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
	    return true;
	}
    }

    return false;
}

void Game::stop() {
    state = END;

    for (Enemy* enemy : enemies) {
	delete enemy;
    }

    enemies.clear();
}

void Game::start() {
    state = IN_PROGRESS;
    player.reset();
}

bool Game::isInProgress() {
    return state == IN_PROGRESS;
}
