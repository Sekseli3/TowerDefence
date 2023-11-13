#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "enemy.h"

// Deferred declaration
class EnemyType;

/// Enemy class
class Enemy  {
public:
    Enemy(sf::Vector2f& position, double radius, int hitpoints, double speed){
        shape.setRadius(20);
        shape.setPosition(position);
        shape.setFillColor(sf::Color::Red);
        shape.setOutlineColor(sf::Color::Red);
        shape.setOutlineThickness(0.8);
    }

    sf::Vector2f& Enemy::getPosition() {
        return 
    }

    //Function to retrieve shape
    sf::CircleShape& getShape() {
        return shape;
    }

    private:
        sf::CircleShape shape;
       
};