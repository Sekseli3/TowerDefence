#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Graphics/graphicFunctions.cpp"
#include <ctime>

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int tileSize = 50; // Size of each tile in pixels

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Colored Tile Map");


    drawTiles(window,tileSize,windowWidth,windowHeight);

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
