#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Graphics/graphicFunctions.cpp"
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
    EndScreen,
    Tutorial
};

/**
 * Moves the enemies on the screen based on the given clock, window, and delay time.
 * Also updates the money based on the enemies killed.
 *
 * @param clock The UniversalClock object used to track the delay time.
 * @param window The sf::RenderWindow object used to draw the enemies.
 * @param stored_enemies The vector of Enemy objects representing the enemies on the screen.
 * @param delayTime The delay time in seconds between enemy movements.
 * @param Money The reference to the money variable to update based on enemies killed.
 */
void moveEnemies(UniversalClock &clock, sf::RenderWindow &window, std::vector<Enemy> &stored_enemies, float delayTime,int &Money){
    
    
        if (clock.isDelayFinished(delayTime)) {
            for (int i = 0; i < stored_enemies.size(); i++){
                stored_enemies[i].moveEnemy(0.1,window);
                clock.restartClock();
            }
        }
        for (int i = stored_enemies.size()-1; i >= 0; i--) {
            window.draw(stored_enemies[i].getShape());
        }
        // kill eenemies
        for (int i = 0; i < stored_enemies.size(); i++){

            if (stored_enemies[i].getHealth() <= 0){
                Money += stored_enemies[i].getPoints();
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
    int money = 100; // Initial money
    int difficulty = 1; // Initial difficulty
    bool addNext = true; // boolean value for adding enemies
    int gameLevel = 1; // game level starting from one
    GameState gameState = GameState::MainMenu;    // sf::Clock clock;
    // sf::Time time = clock.getElapsedTime();
    UniversalClock clock1;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Colored Tile Map");
    
    


    while (window.isOpen()) {
        sf::Event event;
        // money = 0;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        //See in which game state we are and proceed accordingly
        if(gameState == GameState::MainMenu){

            mainMenu(window,difficulty);
            //Proceed to Play
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            
                if(mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 40 && mousePos.y < 100) {
                    gameState = GameState::Tutorial;
                }
                if(mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 400 && mousePos.y < 460) {
                    gameState = GameState::Building;
                }
                if(mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 460 && mousePos.y < 520) {
                    window.close();
                }
                if (mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 340 && mousePos.y < 400){
                    difficulty = 5;
                   
                }
                if (mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 280 && mousePos.y < 340){
                    difficulty = 4;
                   
                }
                if (mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 220 && mousePos.y < 280){
                    difficulty = 3;
                   
                }
                if (mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 160 && mousePos.y < 220){
                    difficulty = 2;
                   
                }
                if (mousePos.x > 300 && mousePos.x < 550 && mousePos.y > 100 && mousePos.y < 160){
                    difficulty = 1;
                   
                }
            }
        }
        
        else if(gameState == GameState::Attacking){
            //draw game
            drawTiles(window,tileSize,windowWidth,windowHeight,difficulty);
            drawTowers(window, money);
            drawMoney(window, money);
            drawWave(window,gameLevel);
            //move all enemies
            moveEnemies(clock1, window, enemies,10,money);
            addNext = true;

            for (int i = 0; i<enemies.size();i++){
                // enemies[i].moveEnemy(timeStep,window);
                if (enemies[i].hasPassed()){
                    gameState = GameState::EndScreen;
                }
            }

            if (enemies.empty()){ gameState = GameState::Building; }
            
        }

        else if(gameState == GameState::Building){
            sf::Font font;
            if (!font.loadFromFile("src/assets/FreeMono.ttf")) {
               std::cout << "Could not load font" << std::endl;
            }
            drawTiles(window,tileSize,windowWidth,windowHeight,difficulty);
            onlyDrawTowers(window);
            deleteTower(event,window,money);
            drawMoney(window, money);
            drawWave(window, gameLevel);
            //Create the button for exiting build mode
            sf::RectangleShape buildButton = createButton(0,550,50,50,sf::Color::Black);
            sf::Text playText = createText(5, 552, "GO", font, 30, sf::Color::White);

            window.draw(buildButton);
            window.draw(playText);
            placeTower(event,window,money);

            //Add enemies for next round
            if (addNext == true) {
                addEnemy(window, tileSize, 0, 4, gameLevel, difficulty);
                addNext = false;
                gameLevel++;
            }

            //See if we want to exit build mode
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if(buildButton.getGlobalBounds().contains(mousePos.x,mousePos.y)){
                    gameState = GameState::Attacking;
                }
            }
        }

        else if(gameState == GameState::EndScreen){
            bool toMain = false;
            endScreen(window);
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
               gameState = GameState::MainMenu;
               sf::sleep(sf::seconds(0.1));
                }
            towers.clear();
            enemies.clear();
            gameLevel = 1;
            addNext = true;
            money = 100;
            
        }
        else if(gameState == GameState::Tutorial) {
            toMain = false;
            tutorial(window);
            if(toMain == true){
                gameState = GameState::MainMenu;
                
            }
        }

    //update the map after clearing window
    window.display();    
    }
    return 0;
}
