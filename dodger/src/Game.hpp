#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Player.hpp"
#include "State.hpp"

class Game
{
private:

    const std::string gameOverString = "Game over. Press a key to restart the game";
    const std::string initString = "Press a key to start the game";
    const int moveOffset = 10;
    Player& player;
    std::vector<Enemy*>& enemies;
    sf::RenderWindow& window;
    sf::Clock clock;
    sf::Font font;
    sf::Text initText;
    sf::Text gameOverText;
    
public:
    Game(sf::RenderWindow& window, Player& player, std::vector<Enemy*>& enemies);
    void render(const State state);
    void moveEnemies();
    void addEnemy(Enemy* const enemy);
    bool checkCollision();
    void start();
    void stop();
    bool isInProgress();
};

#endif /* GAME_H */
