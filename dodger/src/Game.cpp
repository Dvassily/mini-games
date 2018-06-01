#include "Game.hpp"

Game::Game(sf::RenderWindow& window, Player& player, std::vector<Enemy*>& enemies)
    : window(window), player(player), enemies(enemies)
{
    font.loadFromFile("res/LiberationMono-Bold.ttf");

    initText.setString(initString);
    initText.setFont(font);
    sf::FloatRect textRect = initText.getLocalBounds();
    initText.setOrigin(textRect.left + textRect.width  / 2,
			   textRect.top  + textRect.height / 2);
    initText.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    
    gameOverText.setString(gameOverString);
    gameOverText.setFont(font);
    textRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textRect.left + textRect.width  / 2,
			   textRect.top  + textRect.height / 2);
    gameOverText.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    scoreText.setString("Score : " + std::to_string(score));
    scoreText.setFont(font);
    scoreText.setPosition(10, 10);
}

void Game::render(const State state) {
    window.clear(sf::Color(15, 15, 15));

    if (state == END) {
	window.draw(gameOverText);
	window.draw(scoreText);
    } else if (state == INIT) {
	window.draw(initText);
    } else if (state == IN_PROGRESS) {
	window.draw(player.getSprite());

	for (Enemy* enemy : enemies) {
	    window.draw(enemy->getSprite());
	}

	window.draw(scoreText);
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

void Game::incrementScore() {
    ++score;

    updateScore();
}

void Game::resetScore() {
    if (score > bestScore) {
	bestScore = score;
    }
    
    score = 0;

    updateScore();
}

void Game::updateScore() {
    std::string scoreString = "Score : " + std::to_string(score);

    if (bestScore > 0) {
	scoreString += "\nBest score : " + std::to_string(bestScore);
    }
    
    scoreText.setString(scoreString);

}
