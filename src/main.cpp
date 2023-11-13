#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Graphics/graphicFunctions.cpp"
#include "Graphics/GraphicsTest.cpp"
#include "Objects/enemies.h"
#include "gameEngine.cpp"
#include <ctime>
#include <iostream>


int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int tileSize = 50; // Size of each tile in pixels
    double discreteTime = 0; // Calculated time since app has started
    double timeStep = 0.4; // timestep in milliseconds


    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Colored Tile Map");

    //draw tiles
    drawTiles(window,tileSize,windowWidth,windowHeight);

    //Create a arbitary tile to put the tower to
    sf::Vector2f tilePosition(7 * tileSize, 7 * tileSize);
    Tile tile(tilePosition, sf::Color::Black, tileSize);
    //Add tower to tile
    addTower(window,tile);
    //drawGraphics(window,tileSize,windowWidth, windowHeight);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        
        
        sf::sleep(sf::seconds(timeStep));
        discreteTime += timeStep;
        updateGame(window,timeStep,tileSize,windowWidth,windowHeight, stored_enemies);
        
        
        
    }

    return 0;
}
