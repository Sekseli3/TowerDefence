#include "tower.h"
#include <iostream>

TowerType::TowerType(double radius, int damage, double attack_range, double attack_speed, const sf::Color& color, int cost)
    : radius(radius), damage(damage), attack_range(attack_range), attack_speed(attack_speed), color(color),cost(cost) {}

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
    attackShape.setOutlineThickness(2);
    

    

}

// Function to add clock to vector of clocks
void Tower::addClock(UniversalClock &clock){
    clocks.push_back(clock);
}

int Tower::attackEnemy(std::vector<Enemy> &enemies)
{
    
    for (int i = 0; i < enemies.size(); i++)
    {
        
        if (this->getAttackShape().getGlobalBounds().intersects(enemies[i].getShape().getGlobalBounds())&& this->shape.getFillColor() == sf::Color::Red
        && !(enemies[i].getShape().getFillColor() == sf::Color::Yellow))
        {
            //Tower that does damage
            enemies[i].getHit(int(5));
            break;
            
        }
        else if (this->getAttackShape().getGlobalBounds().intersects(enemies[i].getShape().getGlobalBounds())&& this->shape.getFillColor() == sf::Color::Blue)
        {
            //Tower that slows
            enemies[i].reduceSpeed();
            
        }
        else if (this->getAttackShape().getGlobalBounds().intersects(enemies[i].getShape().getGlobalBounds())&& this->shape.getFillColor() == sf::Color::Yellow)
        {
            //Tower that does damage
            enemies[i].getHit(int(5));
            break;
            
        }

        else if (this->getAttackShape().getGlobalBounds().intersects(enemies[i].getShape().getGlobalBounds()) && this->shape.getFillColor() == sf::Color::Red
        && enemies[i].getShape().getFillColor() == sf::Color::Yellow)
        {
            //Delete the basic tower(the return does this) and kill the enemy
            enemies[i].getHit(int(10000));
            return 1;

        }
        else if (this->getAttackShape().getGlobalBounds().intersects(enemies[i].getShape().getGlobalBounds()) && this->shape.getFillColor() == sf::Color::Black
        && enemies[i].getShape().getFillColor() == sf::Color::Black)
        {
            return 2;
        }


        else if (enemies[i].getPosition().x < this->shape.getPosition().x + this->type.getAttackRange() && enemies[i].getPosition().x > this->shape.getPosition().x - this->type.getAttackRange() && enemies[i].getPosition().y < this->shape.getPosition().y + this->type.getAttackRange() && enemies[i].getPosition().y > this->shape.getPosition().y - this->type.getAttackRange())
        {
            attackShape.setFillColor(sf::Color::Red);
        }
        else
        {
            attackShape.setFillColor(sf::Color::Transparent);
        }
        
    }
    return 0;
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