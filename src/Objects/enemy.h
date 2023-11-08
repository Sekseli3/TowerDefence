#ifndef TOWER_DEFENCE_2_ENEMY_H
#define TOWER_DEFENCE_2_ENEMY_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

// Deferred declaration
class EnemyType;

/// Enemy class
class Enemy  {
public:
    Enemy(sf::Vector2f& position, double radius, int hitpoints, double speed){
        shape.setRadius(15);
        shape.setPosition(position);
        shape.setFillColor(sf::Color::Red);
        shape.setOutlineColor(sf::Color::Red);
        shape.setOutlineThickness(0.8);
    }


    //position getter
    sf::Vector2f& getPosition();


    //Function to retrieve shape
    sf::CircleShape& getShape() {
        return shape;
    }

    private:
        sf::CircleShape shape;
      //  sf::Vector2f& position_;
        int hitpoints_;

};

#endif