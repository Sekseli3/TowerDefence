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
    Enemy(sf::Vector2f& position, double radius, int health, int speed, float x, float y)
    : position(position), x(x), y(y), speed(speed), health(health)
        {

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

        if (this->getXcoord() < 250){
            this->move(5,0);
            this->addX(5);  
        }
        else if (this->getYcoord() > 150 && this->getXcoord() == 250){
            this->move(0,-5);
            this->addY(-5); 
        }
        else if (this->getYcoord() == 150 && this->getXcoord() < 500){
            this->move(5,0);
            this->addX(5);  
        }
        else if (this->getYcoord() < 250 && this->getXcoord() == 500){
            this->move(0,5);
            this->addY(5);  
        }
        else if (this->getYcoord() == 250 && this->getXcoord() < 650){
            this->move(5,0);
            this->addX(5);  
        }
        else if (this->getYcoord() > 150 && this->getXcoord() == 650){
            this->move(0,-5);
            this->addY(-5);  
        }
        else if (this->getYcoord() < 250){
            this->move(5,0);
            this->addX(5);  
        }

        //std::cout << this->getXcoord() << ", " << this->getYcoord() << ", speed: " << this->getSpeed() << std::endl;
        window.draw(this->getShape());
    }

    int getSpeed(){
        return this->speed;
    }
    int getXcoord(){
        return this->x;
    }
    int getYcoord(){
        return this->y;
    }
    void addY(int b){
        this->y += b;
    }
    void addX(int a){
        this->x += a;    
    }

    void getHit(int damage){
        health -= damage;
    }

    int getHealth(){
        return this->health;
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