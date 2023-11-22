// EnemyTypeB.cpp
#include "EnemyTypeB.h"
#include "enemies.h"
#include <SFML/Graphics.hpp>

Enemy EnemyTypeB::createEnemy(sf::Vector2f& position, float x, float y) const {
    sf::Color cyan = sf::Color::Cyan;

    //SPEED NEEDS TO BE DIVISIBLE BY 5

    return Enemy(position, 16, 70, 5, x, y, cyan); // Adjust parameters as needed
}