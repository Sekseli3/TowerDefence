#include "tower.h"
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
}



// Function to retrieve shape
sf::ConvexShape& Tower::getShape() {
    return shape;
}
