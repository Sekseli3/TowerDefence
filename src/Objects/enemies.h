#ifndef TOWER_DEFENCE_2_ENEMY_H
#define TOWER_DEFENCE_2_ENEMY_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

// Deferred declaration
class EnemyType;

/// Tower class
class Enemy  {
public:
    Enemy(sf::Vector2f& position, double radius, int health, int speed, int x, int y){
        shape.setRadius(22);
        shape.setPosition(position);
        shape.setFillColor(sf::Color::Red);
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
    void move(float x_dir, float y_dir) {
        // Set the position of the enemy object
        shape.move(x_dir, y_dir);
    }
    void moveEnemy(double timeStep, sf::RenderWindow &window){
        this->move(5,0);
        window.draw(this->getShape());
    }

    int getSpeed(){
        return speed;
    }
    int getXcoord(){
        return x;
    }
    int getYcoord(){
        return y;
    }
    void setStats(float velocity, int hp){
        this->speed = velocity;
        this->health = hp;
    }

    void getHit(int damage){
        this->health -= damage;
    }

  

    private:
        sf::CircleShape shape;
        sf::Vector2f position;
        int x;
        int y;
        float speed;
        int health;

        
};


#endif