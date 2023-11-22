/// Enemy.cpp

#include "enemies.h"
#include "EnemyType.h"  // Include the EnemyType header file



Enemy::Enemy(sf::Vector2f& position, double radius, int health, double speed, float x, float y, sf::Color& color)
    : position(position), x(x), y(y), speed(speed), health(health)
{
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
    
        if (this->getXcoord() < 250){
            this->move(this->getSpeed(),0);
            this->addX(this->getSpeed());  
        }
        else if (this->getYcoord() > 150 && this->getXcoord() == 250){
            this->move(0,-this->getSpeed());
            this->addY(-this->getSpeed()); 
        }
        else if (this->getYcoord() == 150 && this->getXcoord() < 500){
            this->move(this->getSpeed(),0);
            this->addX(this->getSpeed());  
        }
        else if (this->getYcoord() < 250 && this->getXcoord() == 500){
            this->move(0,this->getSpeed());
            this->addY(this->getSpeed());  
        }
        else if (this->getYcoord() == 250 && this->getXcoord() < 650){
            this->move(this->getSpeed(),0);
            this->addX(this->getSpeed());  
        }
        else if (this->getYcoord() > 150 && this->getXcoord() == 650){
            this->move(0,-this->getSpeed());
            this->addY(-this->getSpeed());  
        }
        else if (this->getYcoord() < 250){
            this->move(this->getSpeed(),0);
            this->addX(this->getSpeed());  
        }

        //std::cout << this->getXcoord() << ", " << this->getYcoord() << ", speed: " << this->getSpeed() << std::endl;
        window.draw(this->getShape());

}

bool Enemy::hasPassed() {
    if (this->getXcoord() > 800) return true;
}

int Enemy::getSpeed() {
    return speed; 
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