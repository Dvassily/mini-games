#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Move.hpp"

class Player
{
private:
    sf::Sprite sprite;
    Move currentMove = STATIC;
    int speed;
    unsigned winX;
    unsigned winY;
    
public:
    Player(const sf::Texture& playerTexture, const int speed, const unsigned winX, const unsigned winY);
    void move();
    void startMove(Move move);
    void endMove();
    void reset();
    sf::Sprite& getSprite();
};


#endif /* PLAYER_H */
