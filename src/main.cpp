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

enum class GameState {
    MainMenu,
    Playing,
    EndScreen
};

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int tileSize = 50; // Size of each tile in pixel
    double discreteTime = 0; // Calculated time since app has started
    double timeStep = 0.1; // timestep in milliseconds
    GameState gameState = GameState::MainMenu;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Colored Tile Map");

    
    for (int i = 0; i > -40; i = i-2){
        addEnemy(window, tileSize, i, 4);
    }
    

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        //See in which game state we are and proceed accordingly
        if(gameState == GameState::MainMenu){
            mainMenu(window);
            //Proceed to Play
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                
                if(mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 400 && mousePos.y < 460) {
                    gameState = GameState::Playing;
                }
                if(mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 460 && mousePos.y < 520) {
                    gameState = GameState::EndScreen;
                }
            }
        }

        else if(gameState == GameState::Playing){
            //draw game
            drawTiles(window,tileSize,windowWidth,windowHeight);
            drawTowers(window);
            //move all enemies
            
            for (int i = 0; i<enemies.size();i++){
                enemies[i].moveEnemy(timeStep,window);
            }
            placeTower(event,window);
            sf::sleep(sf::seconds(timeStep));
            discreteTime += timeStep;
        }

        else if(gameState == GameState::EndScreen){
            //close window
            window.close();
        }

       
        
    //update the map after clearing window
    window.display();    
    }
    return 0;
}
