#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
private:
    enum GameState {
	INIT, IN_PROGRESS, END
    };

    sf::Sprite playerSprite;
    const sf::Texture& enemyTexture;
    sf::RenderWindow& window;
    const int moveOffset = 10;
    
public:
    Game(const sf::Texture& playerTexture, const sf::Texture& enemyTexture, sf::RenderWindow& window);
    void render();
    void reset();
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerDown();
    void movePlayerUp();
};

#endif /* GAME_H */
