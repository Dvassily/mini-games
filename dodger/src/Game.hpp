#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Player.hpp"
#include "State.hpp"

class Game
{
private:

    const std::string gameOverString = "Game over\nPress the spacebar to restart the game";
    const std::string initString = "Press the spacebar to start the game";
    const int moveOffset = 10;
    Player& player;
    std::vector<Enemy*>& enemies;
    int score = 0;
    int bestScore = 0;
    sf::RenderWindow& window;
    sf::Clock clock;
    sf::Font font;
    sf::Text initText;
    sf::Text gameOverText;
    sf::Text scoreText;
    
public:
    Game(sf::RenderWindow& window, Player& player, std::vector<Enemy*>& enemies);
    void render(const State state);
    bool checkCollision();
    void incrementScore();
    void resetScore();
    void updateScore();
};

#endif /* GAME_H */
