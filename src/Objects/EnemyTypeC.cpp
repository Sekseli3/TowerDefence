// EnemyTypeC.cpp
#include "EnemyTypeC.h"
#include "enemies.h"
#include <SFML/Graphics.hpp>

Enemy EnemyTypeC::createEnemy(sf::Vector2f& position, float x, float y) const {
    sf::Color black = sf::Color::Black;

    //SPEED NEEDS TO BE DIVISIBLE BY 5

    return Enemy(position, 24, 2500, 1, x, y, black,5); // Adjust parameters as needed
}