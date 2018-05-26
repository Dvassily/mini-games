#include "Game.hpp"

Game::Game(const sf::Texture& playerTexture, const sf::Texture& enemyTexture, sf::RenderWindow& window)
    : enemyTexture(enemyTexture), window(window)
{
    playerSprite.setTexture(playerTexture);
    reset();
}

void Game::reset() {
    playerSprite.setPosition(sf::Vector2f(window.getSize().x / 2 - playerSprite.getTexture()->getSize().x / 2,
					  window.getSize().y - playerSprite.getTexture()->getSize().y));
}

void Game::render() {
    window.clear(sf::Color(15, 15, 15));

    window.draw(playerSprite);
    
    window.display();
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
