#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>


/// Tower class
class TowerType {
public:
    TowerType(double radius, int damage, double attack_range, double attack_speed, const sf::Color& color);

    double getRadius() const;
    int getDamage() const;
    double getAttackRange() const;
    double getAttackSpeed() const;
    const sf::Color& getColor() const;

private:
    double radius;
    int damage;
    double attack_range;
    double attack_speed;
    sf::Color color;
};
class Tower  {
public:
    Tower(const sf::Vector2f& position, const TowerType& type);
    sf::ConvexShape& getShape();

private:
    sf::ConvexShape shape;
    TowerType type;
};



#endif