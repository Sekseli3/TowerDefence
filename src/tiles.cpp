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
    sf::Vector2f& getPosition() {
        return position;
    }
    const sf::Color& getColor() const{
        return color;
    }

private:
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Color color;
    int tileSize;
};

Tile& findClosestTile(std::vector<Tile>& tiles, const sf::Vector2f& position) {
    Tile* closestTile = nullptr;
    float minDistance = std::numeric_limits<float>::max();

    for (Tile& tile : tiles) {
        sf::Vector2f tileCenter = tile.getPosition()+sf::Vector2f(25,25);
        float distance = std::hypot(position.x - tileCenter.x, position.y - tileCenter.y);

        if (distance < minDistance) {
            minDistance = distance;
            closestTile = const_cast<Tile*>(&tile);
        }
    }

    return *closestTile;
}
