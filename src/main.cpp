#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Graphics/graphicFunctions.cpp"
#include "Graphics/GraphicsTest.cpp"
#include <ctime>
#include "Objects/enemy.h"


int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int tileSize = 50; // Size of each tile in pixels

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Colored Tile Map");

    //draw tiles
    drawTiles(window,tileSize,windowWidth,windowHeight);

    //Create a arbitary tile to put the tower to
    sf::Vector2f tilePosition(7 * tileSize, 7 * tileSize);
    Tile tile(tilePosition, sf::Color::Black, tileSize);
    //Add tower to tile
    addTower(window,tile);
    //drawGraphics(window,tileSize,windowWidth, windowHeight);

    //add enemy
    std::vector<Enemy> enemies;
    sf::Vector2f ePos(0,200);
    Enemy enemy1(ePos, 15, 20, 20);
    enemies.push_back(enemy1);
    sf::Vector2f ePos2(100,200);
    Enemy enemy2(ePos2, 15, 20, 20);
    enemies.push_back(enemy2);

    

    drawEnemies(window, enemies);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.display();
    }

    return 0;
}
