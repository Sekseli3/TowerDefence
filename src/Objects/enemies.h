#ifndef TOWER_DEFENCE_2_ENEMY_H
#define TOWER_DEFENCE_2_ENEMY_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "EnemyType.h"
#include "../gameEngine.hpp"
#include <iostream>

class EnemyType;

/// Enemy class
/**
 * @class Enemy
 * @brief Represents an enemy object in the game.
 * 
 * The Enemy class encapsulates the properties and behaviors of an enemy in the game.
 * It includes information such as position, health, speed, and points awarded for defeating the enemy.
 * Enemies can move, take damage, and have their speed reduced based on their fill color.
 */
class Enemy  {
public:
 /**
     * @brief Constructs an enemy object with the given parameters.
     * @param position The initial position of the enemy.
     * @param radius The radius of the enemy.
     * @param health The initial health of the enemy.
     * @param speed The speed of the enemy.
     * @param x The x-coordinate of the enemy's position.
     * @param y The y-coordinate of the enemy's position.
     * @param color The color of the enemy.
     * @param points The points awarded for defeating the enemy.
     */
    Enemy(sf::Vector2f& position, double radius, int health, double speed, float x, float y, sf::Color& color,int points);   
    sf::CircleShape& getShape();
    sf::Vector2f& getPosition();


    void move(float x_dir, float y_dir);
    void moveEnemy(double timeStep, sf::RenderWindow &window);

    int getRoute();
    int getSpeed();
    int getXcoord();
    int getYcoord();

    void addY(int b);
    void addX(int a);

    /**
     * Decreases the health of the enemy by the specified amount.
     * 
     * @param h The amount to decrease the health by.
     */
    void lowerHealth(int h);

    bool hasPassed();
    bool isDead();

    void getHit(int damage){
        health -= damage;
    }

    int getHealth(){
        return this->health;
    }
    int getPoints(){
        return this->points;
    }
    /**
     * Reduces the speed of the enemy based on its fill color.
     * If the fill color is Cyan, the speed is set to 2.
     * If the fill color is Black or Red, the speed is set to 1.
     */
    void reduceSpeed(){
        if(this->shape.getFillColor() == sf::Color::Cyan){
            speed = 2;
        }
        else if(this->shape.getFillColor() == sf::Color::Black){
            speed = 1;
        }
        else if(this->shape.getFillColor() == sf::Color::Red){
            speed = 1;
        }
    }
    // destructor
    ~Enemy(){
    
    }
    private:
        sf::CircleShape shape;
        sf::Vector2f position;
        int x;
        int y;
        float speed;
        int health;
        int points;
        int route;
};

#endif