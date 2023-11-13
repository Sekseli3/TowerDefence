#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>


void updateGame(sf::RenderWindow &window, int timeStep, int tileSize,
    int windowWidth, int windowHeight, std::vector<Enemy> &stored_enemies){
    
    //move enemies around
    window.clear();

    //update the map after clearing window
    drawTiles(window,tileSize,windowWidth,windowHeight);

    //move all enemies
    for (std::size_t i = 0; i != stored_enemies.size(); ++i) {
        stored_enemies[i].moveEnemy(timeStep, window);
    }

    window.display(); 
          
}