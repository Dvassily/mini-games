#ifndef ENEMYGENERATOR_H
#define ENEMYGENERATOR_H

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class EnemyGenerator
{
private:
    const sf::Texture& enemyTexture;
    int minSpeed;
    int maxSpeed;
    int rate;
    int winX;
    sf::Clock clock;
    
public:
    EnemyGenerator(const sf::Texture& enemyTexture, int minSpeed, int maxSpeed, int rate, int winX);
    Enemy* generate();
};


#endif /* ENEMYGENERATOR_H */
