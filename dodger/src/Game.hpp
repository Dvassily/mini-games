#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class Game
{
private:
    enum GameState {
	INIT, IN_PROGRESS, END
    };

    const std::string gameOverString = "Game over. Press a key to restart the game";
    const std::string initString = "Press a key to start the game";
    const int moveOffset = 10;
    const sf::Texture& enemyTexture;
    sf::Sprite playerSprite;
    std::vector<Enemy*> enemies;
    sf::RenderWindow& window;
    int enemyRate;
    int enemyCounter = 0;
    sf::Clock clock;
    sf::Font font;
    sf::Text initText;
    sf::Text gameOverText;
    GameState state = INIT;
    
public:
    Game(const sf::Texture& playerTexture, const sf::Texture& enemyTexture, sf::RenderWindow& window, int enemyRate);
    void render();
    void moveEnemies();
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerDown();
    void movePlayerUp();
    bool checkAddEnemy();
    void addEnemy();
    bool checkCollision();
    void start();
    void stop();
    bool isInProgress();
};

#endif /* GAME_H */
