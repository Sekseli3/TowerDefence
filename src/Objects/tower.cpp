#include "tower.h"
#include <iostream>

TowerType::TowerType(double radius, int damage, double attack_range, double attack_speed, const sf::Color& color)
    : radius(radius), damage(damage), attack_range(attack_range), attack_speed(attack_speed), color(color) {}

double TowerType::getRadius() const { return radius; }
int TowerType::getDamage() const { return damage; }
double TowerType::getAttackRange() const { return attack_range; }
double TowerType::getAttackSpeed() const { return attack_speed; }
const sf::Color& TowerType::getColor() const { return color; }



// Tower constructor
Tower::Tower(const sf::Vector2f& position, const TowerType& type)
    : type(type) {
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f(25, 50)); // Middle of the base
    shape.setPoint(1, sf::Vector2f(0, 0)); // Top left corner
    shape.setPoint(2, sf::Vector2f(50, 0)); // Top right corner
    shape.setPosition(position);
    shape.setFillColor(type.getColor());
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(2);
    attackShape.setRadius(type.getAttackRange());
    // draw circle on center of tower
    attackShape.setOrigin(type.getAttackRange()-25,type.getAttackRange()-25);

    attackShape.setPosition(position);
    attackShape.setFillColor(sf::Color::Transparent);
    attackShape.setOutlineColor(sf::Color::Red);
    attackShape.setOutlineThickness(3);
    

}

void Tower::attackEnemy(std::vector<Enemy> &enemies)
{
    for (int i = 0; i < enemies.size(); i++)
    {
        // if (enemies[i].getPosition().x < this->getPosition().x + this->getAttackRange() && enemies[i].getPosition().x > this->getPosition().x - this->getAttackRange() && enemies[i].getPosition().y < this->getPosition().y + this->getAttackRange() && enemies[i].getPosition().y > this->getPosition().y - this->getAttackRange())
        // {
        //     enemies[i].getHit(int(2));
        //     std::cout << "Enemy hit" << std::endl;
        // }
        // Check if enemy is in range using collistion detection
        // if (this->getShape().getGlobalBounds().intersects(enemies[i].getShape().getGlobalBounds()))
        // {
        //     enemies[i].getHit(this->getDamage());
        // }
        // && this->shape.getFillColor() == sf::Color::Red, Use this to differentiate between towers
        if (this->getAttackShape().getGlobalBounds().intersects(enemies[i].getShape().getGlobalBounds())&& this->shape.getFillColor() == sf::Color::Red)
        {
            //Tower that does damage
            enemies[i].getHit(int(5));
            break;
            //std::cout << "Enemy hit" << std::endl;
        }
        if (this->getAttackShape().getGlobalBounds().intersects(enemies[i].getShape().getGlobalBounds())&& this->shape.getFillColor() == sf::Color::Blue)
        {
            //Tower that slows
            enemies[i].reduceSpeed();
            break;
            //std::cout << "Enemy hit" << std::endl;
        }
        if (this->getAttackShape().getGlobalBounds().intersects(enemies[i].getShape().getGlobalBounds())&& this->shape.getFillColor() == sf::Color::Yellow)
        {
            //Tower that does damage
            enemies[i].getHit(int(5));
            break;
            //std::cout << "Enemy hit" << std::endl;
        }

        if (enemies[i].getPosition().x < this->shape.getPosition().x + this->type.getAttackRange() && enemies[i].getPosition().x > this->shape.getPosition().x - this->type.getAttackRange() && enemies[i].getPosition().y < this->shape.getPosition().y + this->type.getAttackRange() && enemies[i].getPosition().y > this->shape.getPosition().y - this->type.getAttackRange())
        {
            attackShape.setFillColor(sf::Color::Red);
        }
        else
        {
            attackShape.setFillColor(sf::Color::Transparent);
        }
        


    }

}

sf::CircleShape Tower::getAttackShape(){
    return attackShape;
}
    



// Function to retrieve shape
sf::ConvexShape& Tower::getShape() {
    return shape;
}
sf::Vector2f Tower::getPosition(){
    return shape.getPosition();
}