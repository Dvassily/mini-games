#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Player.hpp"

class Game
{
private:
    enum GameState {
	INIT, IN_PROGRESS, END
    };

    const std::string gameOverString = "Game over. Press a key to restart the game";
    const std::string initString = "Press a key to start the game";
    const int moveOffset = 10;
    Player& player;
    std::vector<Enemy*> enemies;
    sf::RenderWindow& window;
    sf::Clock clock;
    sf::Font font;
    sf::Text initText;
    sf::Text gameOverText;
    GameState state = INIT;
    
public:
    Game(sf::RenderWindow& window, Player& player);
    void render();
    void moveEnemies();
    void addEnemy(Enemy* const enemy);
    bool checkCollision();
    void start();
    void stop();
    bool isInProgress();
};

#endif /* GAME_H */
