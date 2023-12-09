/// Enemy.cpp
#include <iostream>
#include "enemies.h"
#include "EnemyType.h"  // Include the EnemyType header file
#include <random>


Enemy::Enemy(sf::Vector2f& position, double radius, int health, double speed, float x, float y, sf::Color& color,int points)
    : position(position), x(x), y(y), speed(speed), health(health),points(points)
{   
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);
    route = distrib(gen);
    shape.setRadius(radius);
    shape.setPosition(position);
    shape.setFillColor(color);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(0.8);
}

sf::CircleShape& Enemy::getShape() {
    return shape;
}

sf::Vector2f& Enemy::getPosition() {
    return position;
}

void Enemy::move(float x_dir, float y_dir) {
    shape.move(x_dir, y_dir);
}

void Enemy::moveEnemy(double timeStep, sf::RenderWindow &window) {
    double x = this->getXcoord();
    double y = this->getYcoord();
    double speed = this->getSpeed();

    if (this->getRoute() == 0) {
        if (x < 250){
            this->move(speed,0);
            this->addX(speed);  
        }
        else if (y > 150 && x >= 240 && x <= 260){
            this->move(0,-speed);
            this->addY(-speed); 
        }
        else if (y >= 150 && x < 500){
            this->move(speed,0);
            this->addX(speed);  
        }
        else if (y < 250 && x >= 490 && x <= 510){
            this->move(0,speed);
            this->addY(speed);  
        }
        else if (y >= 240 && y <= 260 && x < 650){
            this->move(speed,0);
            this->addX(speed);  
        }
        else if (y > 150 && x >= 640 && x <= 660){
            this->move(0,-speed);
            this->addY(-speed);  
        }
        else if (y<250) {
            this->move(speed,0);
            this->addX(speed); 
        }
             
    }
    else if (this->getRoute() == 1) {
        if (x < 250){
            this->move(speed,0);
            this->addX(speed);  
        }
        else if (y < 350 && x >= 240 && x <= 260){
            this->move(0,speed);
            this->addY(speed); 
        }
        else if (y >= 350){
            this->move(speed,0);
            this->addX(speed);  
        } 
    }
    window.draw(this->getShape());
}

bool Enemy::hasPassed() {
    if (this->getXcoord() > 800) return true;
}

int Enemy::getSpeed() {
    return speed; 
}

int Enemy::getRoute() {
    return route;
}

int Enemy::getXcoord() {
    return x;
}

int Enemy::getYcoord() {
    return y;
}

void Enemy::addY(int b) {
    y += b;
}

void Enemy::addX(int a) {
    x += a;
}

void Enemy::lowerHealth(int h) {
    health -= h;
}

bool Enemy::isDead() {
    if (this->health <= 0) return true;
}
