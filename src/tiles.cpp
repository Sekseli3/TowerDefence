#include <SFML/Graphics.hpp>
#include <cmath>
//Tile class for tile objects
/**
 * @brief Represents a tile in the game.
 */
class Tile {
public:
    /**
     * @brief Constructs a Tile object.
     * @param position The position of the tile.
     * @param color The color of the tile.
     * @param tileSize The size of the tile.
     */
    Tile(const sf::Vector2f& position, const sf::Color& color, int tileSize)
    :position(position),color(color),tileSize(tileSize) {
        shape.setSize(sf::Vector2f(tileSize, tileSize));
        shape.setPosition(position);
        shape.setFillColor(color);
        if(color == sf::Color::Green){
            shape.setOutlineColor(sf::Color::Black);
        }
        else{
            shape.setOutlineColor(color);
        }
        shape.setOutlineThickness(0.5);
    }
    
    /**
     * @brief Retrieves the shape of the tile.
     * @return A reference to the shape of the tile.
     */
    sf::RectangleShape& getShape() {
        return shape;
    }
    
    /**
     * @brief Retrieves the position of the tile.
     * @return A reference to the position of the tile.
     */
    sf::Vector2f& getPosition() {
        return position;
    }
    
    /**
     * @brief Retrieves the color of the tile.
     * @return A constant reference to the color of the tile.
     */
    const sf::Color& getColor() const{
        return color;
    }

private:
    sf::RectangleShape shape; /**< The shape of the tile. */
    sf::Vector2f position; /**< The position of the tile. */
    sf::Color color; /**< The color of the tile. */
    int tileSize; /**< The size of the tile. */
};

/**
 * Finds the closest Tile to the given position from the provided vector of Tiles.
 *
 * @param tiles The vector of Tiles to search from.
 * @param position The position to find the closest Tile to.
 * @return A reference to the closest Tile.
 */
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
