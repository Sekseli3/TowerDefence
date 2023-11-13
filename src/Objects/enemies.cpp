/*
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

// Deferred declaration
class EnemyType;

/// Tower class
class Enemy  {
public:
    Enemy(sf::Vector2f& position, double radius, int health, int x, int y){
        shape.setRadius(22);
        shape.setPosition(position);
        shape.setFillColor(sf::Color::Black);
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(0.8);
    }

    //Function to retrieve shape
    sf::CircleShape& getShape() {
        return shape;
    }
    sf::Vector2f& getPosition() {
        return position;
    }
    int getXcoord(){
        return x;
    }
    int getYcoord(){
        return y;
    }
    void move(float x, float y) {
        // Set the position of the enemy object
        shape.setPosition(x, y);
    }

    private:
        sf::CircleShape shape;
        sf::Vector2f position;
        int x;
        int y;
};

*/