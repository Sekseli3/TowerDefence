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
    Building,
    Attacking,
    EndScreen
};

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int tileSize = 50; // Size of each tile in pixel
    double discreteTime = 0; // Calculated time since app has started
    double timeStep = 0.01; // timestep in milliseconds
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
                    gameState = GameState::Building;
                }
                if(mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 460 && mousePos.y < 520) {
                    endScreen(window);
                    //window.close();
                }
            }
        }
        
        else if(gameState == GameState::Attacking){
            //draw game
            drawTiles(window,tileSize,windowWidth,windowHeight);
            drawTowers(window);
            sf::sleep(sf::seconds(timeStep));
            discreteTime += timeStep;

            for (int i = 0; i<enemies.size();i++){
                enemies[i].moveEnemy(timeStep,window);
            }
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right){
                gameState = GameState::EndScreen;
            }
        }

        else if(gameState == GameState::Building){
            drawTiles(window,tileSize,windowWidth,windowHeight);
            drawTowers(window);
            //Create the button for exiting build mode
            sf::RectangleShape buildButton = createButton(750,500,50,75,sf::Color::Black);
            window.draw(buildButton);
            placeTower(event,window);
            //See if we want to exit build mode
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if(buildButton.getGlobalBounds().contains(mousePos.x,mousePos.y)){
                    gameState = GameState::Attacking;
                }
            }
        }

        else if(gameState == GameState::EndScreen){
            endScreen(window);
        }

       
        
    //update the map after clearing window
    window.display();    
    }
    return 0;
}
