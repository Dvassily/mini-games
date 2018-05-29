#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Move.hpp"

class Player
{
private:
    sf::Sprite sprite;
    sf::Clock clock;
    Move currentMove = STATIC;
    unsigned winX;
    unsigned winY;
    
public:
    Player(const sf::Texture& playerTexture, unsigned winX, unsigned winY);
    void move();
    void startMove(Move move);
    void endMove();
    void reset();
    sf::Sprite& getSprite();
};


#endif /* PLAYER_H */
