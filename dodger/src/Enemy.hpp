#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::Sprite sprite;
    const unsigned speed;
    
public:
    Enemy(const unsigned speed, const unsigned x, const float scale, const sf::Texture& enemyTexture);
    void move();
    const sf::Sprite& getSprite();
};


#endif /* ENEMY_H */
