
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

// Deferred declaration
class TowerType;

/// Tower class
class Tower  {
public:
    Tower(const sf::Vector2f& position, double radius, int damage, double attack_range,
        double attack_speed){
        shape.setRadius(50);
        shape.setPosition(position);
        shape.setFillColor(sf::Color::Black);
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(0.8);
    }
    //Function to retrieve shape
    sf::CircleShape& getShape() {
        return shape;
    }
    private:
        sf::CircleShape shape;
};
