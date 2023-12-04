#include <SFML/Graphics.hpp>
#include "gameEngine.hpp"
#include <cstdlib>
#include <ctime>
#include "Graphics/graphicFunctions.cpp"
#include "Graphics/GraphicsTest.cpp"
#include "Objects/enemies.h"
#include "gameEngine.hpp"
#include <ctime>
#include <iostream>
#include <vector>

// void timekeeer(int timeStep){
//     sf::Clock clock;
//     sf::Time time = clock.getElapsedTime();
// }
UniversalClock clock1;

enum class GameState {
    MainMenu,
    Building,
    Attacking,
    EndScreen
};

void moveEnemies(UniversalClock &clock, sf::RenderWindow &window, std::vector<Enemy> &stored_enemies, float delayTime){
    
    
        if (clock.isDelayFinished(delayTime)) {
            for (int i = 0; i < stored_enemies.size(); i++){
                stored_enemies[i].moveEnemy(0.1,window);
                clock.restartClock();
            }
        }
        for (size_t i = 0; i < stored_enemies.size(); i++) {
            window.draw(stored_enemies[i].getShape());
        }
        // kill eenemies
        for (int i = 0; i < stored_enemies.size(); i++){

            if (stored_enemies[i].getHealth() <= 0){
                stored_enemies.erase(stored_enemies.begin()+i);
            }
            
        }
      
    
}

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int tileSize = 50; // Size of each tile in pixel
    double discreteTime = 0; // Calculated time since app has started
    double timeStep = 0.01; // timestep in milliseconds
    int money = 123; // Initial money
    GameState gameState = GameState::MainMenu;    // sf::Clock clock;
    // sf::Time time = clock.getElapsedTime();
    UniversalClock clock1;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Colored Tile Map");
    
    for (int i = 0; i > -40; i = i-2){
        addEnemy(window, tileSize, i, 4);
    }


    while (window.isOpen()) {
        sf::Event event;
        money = 0;
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
                    window.close();
                }
            }
        }
        
        else if(gameState == GameState::Attacking){
            //draw game
            drawTiles(window,tileSize,windowWidth,windowHeight);
            drawTowers(window);
            drawMoney(window, money);
            //move all enemies
            moveEnemies(clock1, window, enemies,20);
  

            for (int i = 0; i<enemies.size();i++){
                // enemies[i].moveEnemy(timeStep,window);
                if (enemies[i].hasPassed()){
                    gameState = GameState::EndScreen;
                }
            }
            
        }

        else if(gameState == GameState::Building){
            drawTiles(window,tileSize,windowWidth,windowHeight);
            drawTowers(window);
            deleteTower(event,window);
            drawMoney(window, money);
            //Create the button for exiting build mode
            sf::RectangleShape buildButton = createButton(0,550,50,50,sf::Color::Black);
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
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
               gameState = GameState::MainMenu;
                }
        }

       
        
    //update the map after clearing window
    window.display();    
    }
    return 0;
}
