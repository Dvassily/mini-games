#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::Sprite sprite;
    sf::Clock clock;
    const unsigned speed;
    
public:
    Enemy(const unsigned speed, const unsigned x, const sf::Texture& enemyTexture);
    bool checkMove();
    void move();
    const sf::Sprite& getSprite();
};


#endif /* ENEMY_H */