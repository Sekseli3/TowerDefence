#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

void drawTiles(sf::RenderWindow &window,
                const int tileSize,const int windowWidth, const int windowHeight){
                    
    const int mapWidth = windowWidth / tileSize;
    const int mapHeight = windowHeight / tileSize;
    sf::RectangleShape mapTiles[mapWidth][mapHeight];

    for (int x = 0; x < mapWidth; x++) {
        for (int y = 0; y < mapHeight; y++) {
            sf::RectangleShape& tile = mapTiles[x][y];
            tile.setSize(sf::Vector2f(tileSize, tileSize));

            // Assign colors to different tiles
            if (x == mapWidth / 2) {
                tile.setFillColor(sf::Color::White);
            } else {
                // Randomly decide whether to make it green or blue
                if (std::rand() % 2 == 0) {
                    tile.setFillColor(sf::Color::Green); // Green for plots of land
                } else {
                    tile.setFillColor(sf::Color::Blue); // Blue for lakes
                    tile.setOutlineColor(sf::Color::Black);
                    tile.setOutlineThickness(0.8);
                }
            }

            tile.setPosition(x * tileSize, y * tileSize);
        }
    }
            for (int x = 0; x < mapWidth; x++) {
            for (int y = 0; y < mapHeight; y++) {
                window.draw(mapTiles[x][y]);
            }
        }
}