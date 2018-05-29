#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "EnemyGenerator.hpp"
#include "Player.hpp"
#include "Move.hpp"

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
    Game game(window, player);
    EnemyGenerator enemyGenerator(enemyTexture, 250, 500, 5, window.getSize().x);
    
    while (window.isOpen()) {
	if (game.isInProgress()) {
	    player.move();
	    game.moveEnemies();

	    if (game.checkCollision()) {
		game.stop();
	    }

	    Enemy* enemy = enemyGenerator.generate();
	    
	    if (enemy != nullptr) {
		game.addEnemy(enemy);
	    }
	}
	game.render();

	sf::Event event;
	while (window.pollEvent(event)) {
	    if (event.type == sf::Event::Closed)
		window.close();

	    if (! game.isInProgress()) {
		if (event.type == sf::Event::KeyPressed &&
		    event.key.code == sf::Keyboard::Space) {
		    game.start();
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
