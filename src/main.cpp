#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Graphics/graphicFunctions.cpp"
#include "Graphics/GraphicsTest.cpp"
#include "Objects/enemies.h"
#include "gameEngine.cpp"
#include <ctime>
#include <iostream>
#include <vector>


int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int tileSize = 50; // Size of each tile in pixel
    double discreteTime = 0; // Calculated time since app has started
    double timeStep = 0.4; // timestep in milliseconds


    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Colored Tile Map");


    //draw tiles
    drawTiles(window,tileSize,windowWidth,windowHeight);

    //Create a arbitary tile to put the tower to
    sf::Vector2f tilePosition(7 * tileSize, 7 * tileSize);
    Tile tile(tilePosition, sf::Color::Black, tileSize);
    //Add tower to tile
    //drawGraphics(window,tileSize,windowWidth, windowHeight)
    Enemy enemy1 = addEnemy(window, tileSize,1,4);
    


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

    
        
        sf::sleep(sf::seconds(timeStep));
        discreteTime += timeStep;
        //move enemies around
    window.clear();

    //update the map after clearing window
    drawTiles(window,tileSize,windowWidth,windowHeight);

    //move all enemies
    
    enemy1.moveEnemy(timeStep, window);
    placeTower(event,window);
    window.display(); 
        
        
        //add towers with click. First click t and then green tile
        

    }

    return 0;
}
