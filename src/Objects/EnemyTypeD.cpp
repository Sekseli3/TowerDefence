// EnemyTypeD.cpp
#include "EnemyTypeD.h"
#include "enemies.h"
#include <SFML/Graphics.hpp>

Enemy EnemyTypeD::createEnemy(sf::Vector2f& position, float x, float y) const {
    sf::Color yellow = sf::Color::Yellow;

    //SPEED NEEDS TO BE DIVISIBLE BY 5

    return Enemy(position, 24, 2500, 1, x, y, yellow,5); // Adjust parameters as needed
}