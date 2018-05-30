#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "EnemyGenerator.hpp"
#include "Player.hpp"
#include "Move.hpp"
#include "State.hpp"

void moveEnemies(std::vector<Enemy*>& enemies) {
    for (Enemy* enemy : enemies) {
	if (enemy->checkMove()) {
	    enemy->move();
	}
    }
}

void clearEnemies(std::vector<Enemy*>& enemies) {
    for (Enemy* enemy : enemies) {
	delete enemy;
    }
    
    enemies.clear();
}

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dodger");
    sf::Texture playerTexture;
    sf::Texture enemyTexture;

    if (! playerTexture.loadFromFile("res/player.png") || ! enemyTexture.loadFromFile("res/enemy.png")) {
	std::cerr << "Error occured while loading textures" << std::endl;
	return 1;
    }

    Player player(playerTexture, window.getSize().x, window.getSize().y);
    std::vector<Enemy*> enemies;
    Game game(window, player, enemies);
    EnemyGenerator enemyGenerator(enemyTexture, 250, 500, 5, window.getSize().x);
    State state = INIT;
    
    while (window.isOpen()) {
	if (state == IN_PROGRESS) {
	    player.move();
	    moveEnemies(enemies);

	    if (game.checkCollision()) {
		state = END;
		clearEnemies(enemies);
	    }

	    Enemy* enemy = enemyGenerator.generate();
	    
	    if (enemy != nullptr) {
		enemies.push_back(enemy);
	    }
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
		}
	    } else if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Left) {
		    player.startMove(LEFT);
		} else if (event.key.code == sf::Keyboard::Right) {
		    player.startMove(RIGHT);
		} else if (event.key.code == sf::Keyboard::Down) {
		    player.startMove(DOWN);
		} else if (event.key.code == sf::Keyboard::Up) {
		    player.startMove(UP);
		} 
	    } else if (event.type == sf::Event::KeyReleased) {
		player.endMove();
	    }
	}
    }

    
    return 0;
}
