#include <SFML/Graphics.hpp>
//Tile class for tile objects
class Tile {
public:
    Tile(const sf::Vector2f& position, const sf::Color& color, int tileSize)
    :position(position),color(color),tileSize(tileSize) {
        shape.setSize(sf::Vector2f(tileSize, tileSize));
        shape.setPosition(position);
        shape.setFillColor(color);
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(0.8);
    }
    //Function to retrieve shape
    sf::RectangleShape& getShape() {
        return shape;
    }
    sf::Vector2f& getPosition(){
        return position;
    }

private:
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Color color;
    int tileSize;
};