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
class Enemy  {
public:
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
       std::cout << "Enemy destroyed" << std::endl;
    
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