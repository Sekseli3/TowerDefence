// EnemyTypeA.cpp
#include "EnemyTypeA.h"
#include "enemies.h"
#include <SFML/Graphics.hpp>

Enemy EnemyTypeA::createEnemy(sf::Vector2f& position, float x, float y) const {
    sf::Color red = sf::Color::Red;

    //SPEED NEEDS TO BE DIVISIBLE BY 5

    return Enemy(position, 20, 300, 2.5, x, y, red,1); // Adjust parameters as needed
}
