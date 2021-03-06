#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "EnemyGenerator.hpp"
#include "Player.hpp"
#include "Move.hpp"
#include "State.hpp"

void moveEnemies(std::vector<Enemy*>& enemies) {
    for (Enemy* enemy : enemies) {
	enemy->move();
    }
}

void clearEnemies(std::vector<Enemy*>& enemies) {
    for (Enemy* enemy : enemies) {
	delete enemy;
    }
    
    enemies.clear();
}

void cleanEnemies(std::vector<Enemy*>& enemies, int winY) {
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [winY](Enemy* enemy) {
		if (enemy->getSprite().getPosition().y >= winY) {
		    delete enemy;
		    return true;
		}
		
		return false;
	    }), enemies.end());
}

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dodger");
    window.setVerticalSyncEnabled(true);
    
    sf::Texture playerTexture;
    sf::Texture enemyTexture;

    if (! playerTexture.loadFromFile("res/player.png") || ! enemyTexture.loadFromFile("res/enemy.png")) {
	std::cerr << "Error occured while loading textures" << std::endl;
	return 1;
    }

    Player player(playerTexture, 5, window.getSize().x, window.getSize().y);
    std::vector<Enemy*> enemies;
    Game game(window, player, enemies);
    EnemyGenerator enemyGenerator(enemyTexture, 1, 10, 3, window.getSize().x);
    State state = INIT;
    
    while (window.isOpen()) {
	if (state == IN_PROGRESS) {
	    player.move();
	    moveEnemies(enemies);
	    cleanEnemies(enemies, window.getSize().y);
	    
	    if (game.checkCollision()) {
		state = END;
		clearEnemies(enemies);
	    }

	    Enemy* enemy = enemyGenerator.generate();
	    
	    if (enemy != nullptr) {
		enemies.push_back(enemy);
	    }
	    game.incrementScore();
	}

	game.render(state);
	
	sf::Event event;
	while (window.pollEvent(event)) {
	    if (event.type == sf::Event::Closed)
		window.close();

	    if (state != IN_PROGRESS) {
		if (event.type == sf::Event::KeyPressed &&
		    event.key.code == sf::Keyboard::Space) {
		    state = IN_PROGRESS;
		    player.reset();
		    game.resetScore();
		}
	    }
	}
    }

    
    return 0;
}
