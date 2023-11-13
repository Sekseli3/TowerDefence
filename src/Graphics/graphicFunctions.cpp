#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "../Objects/tower.h"
#include "../Objects/enemies.h"
#include "../tiles.cpp"


//function to draw all the tiles from hardcoded map
void drawTiles(sf::RenderWindow &window, const int tileSize, const int windowWidth, const int windowHeight) {
    //Count how many tiles we can fit in map
    const int mapWidth = windowWidth / tileSize;
    const int mapHeight = windowHeight / tileSize;


    // Define a hardcoded map, 0 for water(blue), 1 for grass(green) and other for path(white) 
    int hardcodedMap[16][12] = {
        {0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    //iterate through all the tiles
    for (int x = 0; x < mapWidth; x++) {
        for (int y = 0; y < mapHeight; y++) {
            //calculate position
            sf::Vector2f tilePosition(x * tileSize, y * tileSize);

            // Create a Tile object with the specified color, and tileSize
            int tileType = hardcodedMap[x][y];
            sf::Color tileColor;
            if (tileType == 0) {
                tileColor = sf::Color::Blue;
            } else if (tileType == 1) {
                tileColor = sf::Color::Green;
            } else {
                tileColor = sf::Color::White;
            }
            //create tile objects for each tile
            Tile tile(tilePosition, tileColor, tileSize);

            // Draw the tile's shape
            window.draw(tile.getShape());
        }
    }
}
void addTower(sf::RenderWindow &window, Tile tile){
    Tower tower(tile.getPosition(),30,20,20,50);
    window.draw(tower.getShape());
}

Enemy addEnemy(sf::RenderWindow &window, int tileSize, int x, int y){
    sf::Vector2f tileStartPosition(x * tileSize+3, y * tileSize+3);
    Tile tile(tileStartPosition, sf::Color::Black, tileSize);
    Enemy enemy(tile.getPosition(), 30, 10, 1, x, y);
     
    window.draw(enemy.getShape());
    return enemy;
}

Enemy addEnemy(sf::RenderWindow &window, int tileSize, int x, int y){
    sf::Vector2f tileStartPosition(x * tileSize+3, y * tileSize+3);
    Tile tile(tileStartPosition, sf::Color::Black, tileSize);
    Enemy enemy(tile.getPosition(), 30, 10, 1, x, y);
     
    window.draw(enemy.getShape());
    return enemy;
}

void drawEnemies(sf::RenderWindow &window, std::vector<Enemy>& enemies){
    for (auto& it : enemies) {
        window.draw(it.getShape());
    }
}
