#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>
#include "enemies.h"
#include "../gameEngine.hpp"



/// Tower class
class TowerType {
public:
    TowerType(double radius, int damage, double attack_range, double attack_speed, const sf::Color& color, int cost);

    double getRadius() const;
    int getDamage() const;
    double getAttackRange() const;
    double getAttackSpeed() const;
    const sf::Color& getColor() const;
    int getCost() const {return cost;}
    ~TowerType() {
    }

private:
    double radius;
    int damage;
    double attack_range;
    double attack_speed;
    sf::Color color;
    int cost;
};
class Tower  {
public:
    Tower(const sf::Vector2f& position, const TowerType& type);
    sf::ConvexShape& getShape();
    double getAttack_range() const;
    void attackEnemy(std::vector<Enemy> &enemies);
    sf::CircleShape getAttackShape();
    sf::Vector2f getPosition();
    // function to add clock to vector of clocks
    void addClock(UniversalClock &clock);
    TowerType getType() const {return type;}
    ~Tower() {
    }

private:
    sf::ConvexShape shape;
    TowerType type;
    sf::CircleShape attackShape;
    // list of universal clocks
    std::vector<UniversalClock> clocks;
    
};



#endif