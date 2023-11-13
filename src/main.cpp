#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Graphics/graphicFunctions.cpp"
#include "Graphics/GraphicsTest.cpp"
#include <ctime>
#include <iostream>

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int tileSize = 50; // Size of each tile in pixel

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Colored Tile Map");


    //draw tiles
    drawTiles(window,tileSize,windowWidth,windowHeight);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.display();
        //add towers with click. First click t and then green tile
        placeTower(event,window);

    }

    return 0;
}
