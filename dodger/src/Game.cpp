#include "Game.hpp"

Game::Game(sf::RenderWindow& window, Player& player, std::vector<Enemy*>& enemies)
    : window(window), player(player), enemies(enemies)
{
    font.loadFromFile("res/LiberationMono-Bold.ttf");
    gameOverText.setString(gameOverString);
    gameOverText.setFont(font);
    initText.setString(initString);
    initText.setFont(font);
}

void Game::render(const State state) {
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

bool Game::checkCollision() {
    for (Enemy* enemy : enemies) {
	if (enemy->getSprite().getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
	    return true;
	}
    }

    return false;
}
