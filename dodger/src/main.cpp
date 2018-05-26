#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dodger");
    sf::Texture playerTexture;
    sf::Texture enemyTexture;

    if (! playerTexture.loadFromFile("res/player.png") || ! enemyTexture.loadFromFile("res/enemy.png")) {
	std::cerr << "Error occured while loading textures" << std::endl;
	return 1;
    }

    Game game(playerTexture, enemyTexture, window);
    
    
    while (window.isOpen()) {
	sf::Event event;
	while (window.pollEvent(event)) {
	    if (event.type == sf::Event::Closed)
		window.close();
	    else if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Left) {
		    game.movePlayerLeft();
		} else if (event.key.code == sf::Keyboard::Right) {
		    game.movePlayerRight();
		} else if (event.key.code == sf::Keyboard::Down) {
		    game.movePlayerDown();
		} else if (event.key.code == sf::Keyboard::Up) {
		    game.movePlayerUp();
		} 
	    }
	}

	game.render();
    }
    
    return 0;
}
