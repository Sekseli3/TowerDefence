#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "../Objects/tower.h"
#include "../Objects/enemies.h"
#include "../tiles.cpp"
#include "../Objects/EnemyTypeA.h"
#include "../Objects/EnemyTypeB.h"
#include "../Objects/EnemyTypeC.h"

std::vector<Tile> tiles;
std::vector<Tower> towers;
std::vector<Enemy> enemies;
sf::RectangleShape playButton;
sf::RectangleShape exitButton;
bool towerPlacementMode = false;
TowerType* selectedTowerType = nullptr;
//function to draw all the tiles from hardcoded map
void drawTiles(sf::RenderWindow &window, const int tileSize, const int windowWidth, const int windowHeight) {
    //Count how many tiles we can fit in map
    const int mapWidth = windowWidth / tileSize;
    const int mapHeight = windowHeight / tileSize;


    // Define a hardcoded map, 0 for water(blue), 1 for grass(green) and other for path(white) 
    int hardcodedMap[16][12] = {
        {0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 1, 2, 0, 0, 0, 1},
        {1, 1, 1, 2, 1, 1, 1, 2, 0, 0, 0, 1},
        {1, 1, 1, 2, 1, 1, 1, 2, 0, 0, 0, 1},
        {1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1},
        {1, 1, 1, 2, 2, 2, 1, 2, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 2, 1, 2, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 2, 1, 2, 1, 1, 1, 1},
        {1, 1, 1, 2, 2, 2, 1, 2, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1}
    };

    //iterate through all the tiles
    for (int x = 0; x < mapWidth; x++) {
        for (int y = 0; y < mapHeight; y++) {
            //calculate position
            sf::Vector2f tilePosition(x * tileSize, y * tileSize);

            // Create a Tile object with the specified color, and tileSize
            int tileType = hardcodedMap[x][y];
            sf::Color tileColor;
            if (tileType == 0) {
                tileColor = sf::Color::Blue;
            } else if (tileType == 1) {
                tileColor = sf::Color::Green;
            } else {
                tileColor = sf::Color::White;
            }
            //create tile objects for each tile
            Tile tile(tilePosition, tileColor, tileSize);
            
            tiles.push_back(tile);
            // Draw the tile's shape
            window.draw(tile.getShape());
        }
    }
}
sf::RectangleShape createButton(float x, float y, float width, float height, sf::Color color) {
    sf::RectangleShape button(sf::Vector2f(width, height));
    button.setPosition(x, y);
    button.setFillColor(color);
    return button;
}

// Function to create a text
sf::Text createText(float x, float y, std::string content, sf::Font& font, unsigned int size,sf::Color color) {
    sf::Text text;
    text.setFont(font);
    text.setFillColor(color);
    text.setString(content);
    text.setCharacterSize(size);
    text.setPosition(x, y);
    return text;
}

void addTower(sf::RenderWindow &window, Tile tile, TowerType type){
    Tower tower(tile.getPosition(),type);
        towers.push_back(tower);
}

void addEnemy(sf::RenderWindow &window, int tileSize, int x, int y, int gameLevel, int difficulty){

    int iterator = gameLevel * difficulty;

    if (gameLevel <= 2) {
        for (int j = -1; j > -3*iterator; j--) {

            sf::Vector2f tileStartPosition_A((j)*tileSize+4, y * tileSize+4);
            EnemyTypeA enemyTypeA;
            enemies.push_back(enemyTypeA.createEnemy(tileStartPosition_A, (j)*tileSize,y*tileSize));
        }
    }
    else if (gameLevel > 2 && gameLevel <= 4) {
        for (int j = -1; j > -3*iterator; j--) {

            sf::Vector2f tileStartPosition_A((j)*tileSize+4, y * tileSize+4);
            EnemyTypeA enemyTypeA;
            enemies.push_back(enemyTypeA.createEnemy(tileStartPosition_A, (j)*tileSize,y*tileSize));

            sf::Vector2f tileStartPosition_B((j)*tileSize+7, y * tileSize+7);
            EnemyTypeB enemyTypeB;
            enemies.push_back(enemyTypeB.createEnemy(tileStartPosition_B, (j)*tileSize,y*tileSize));

        }
    }
    else if (gameLevel > 4 && gameLevel <= 6) {
        for (int j = -1; j > -4*iterator; j--) {

            sf::Vector2f tileStartPosition_B((j)*tileSize+7, y * tileSize+7);
            EnemyTypeB enemyTypeB;
            enemies.push_back(enemyTypeB.createEnemy(tileStartPosition_B, (j)*tileSize,y*tileSize));
            
            if (j>-2*iterator) {
                sf::Vector2f tileStartPosition_A((j/2-1)*tileSize+4, y * tileSize+4);
                EnemyTypeA enemyTypeA;
                enemies.push_back(enemyTypeA.createEnemy(tileStartPosition_A, (j/2-1)*tileSize,y*tileSize));
            }

            if (j>-1*iterator) {
                sf::Vector2f tileStartPosition_C((j/2-1) * tileSize+1, y * tileSize+1);
                EnemyTypeC enemyTypeC;
                enemies.push_back(enemyTypeC.createEnemy(tileStartPosition_C, (j/2-1)*tileSize,y*tileSize));
            }
        }
    }
    else if (gameLevel > 6) {
        for (int j = -1; j > -8*iterator; j--) {

            sf::Vector2f tileStartPosition_B((j)*tileSize+7, y * tileSize+7);
            EnemyTypeB enemyTypeB;
            enemies.push_back(enemyTypeB.createEnemy(tileStartPosition_B, (j)*tileSize,y*tileSize));
            
            if (j>-3*iterator) {
                sf::Vector2f tileStartPosition_A((j/3)*tileSize+4, y * tileSize+4);
                EnemyTypeA enemyTypeA;
                enemies.push_back(enemyTypeA.createEnemy(tileStartPosition_A, (j/3)*tileSize,y*tileSize));
            }

            if (j>-2*iterator) {
                sf::Vector2f tileStartPosition_C((j/2) * tileSize+1, y * tileSize+1);
                EnemyTypeC enemyTypeC;
                enemies.push_back(enemyTypeC.createEnemy(tileStartPosition_C, (j/2)*tileSize,y*tileSize));
            }
        }
    }

}



void placeTower(sf::Event event, sf::RenderWindow &window, int &money){

    //Define the tower types
    TowerType basicTower(30.0, 20, 100, 50.0, sf::Color::Red,30);
    TowerType advancedTower(40.0, 30, 100, 60.0, sf::Color::Blue,50);
    TowerType ultimateTower(50.0, 40, 250, 70.0, sf::Color::Yellow,120);

    // Create the buttons for each tower type
    sf::RectangleShape basicButton = createButton(50, 500, 50, 50, basicTower.getColor());
    sf::RectangleShape advancedButton = createButton(0, 500, 50, 50, advancedTower.getColor());
    sf::RectangleShape ultimateButton = createButton(50, 550, 50, 50, ultimateTower.getColor());

    // Draw the buttons
    window.draw(basicButton);
    window.draw(advancedButton);
    window.draw(ultimateButton);
    

    // Check if a button was clicked
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {
        if (basicButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            selectedTowerType = &basicTower;
        } else if (advancedButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            selectedTowerType = &advancedTower;
        } else if (ultimateButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            selectedTowerType = &ultimateTower;
        }
    }

    // Check if a tile was clicked
    if (selectedTowerType != nullptr && event.mouseButton.button == sf::Mouse::Right) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f rightPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        Tile& closestTile = findClosestTile(tiles, rightPosition);


        if (closestTile.getColor() == sf::Color::Green) {

            if (money < selectedTowerType->getCost()) {
                std::cout << "Not enough money" << std::endl;
                
            }
            else{
                 
            money -= selectedTowerType->getCost();
            
            addTower(window, closestTile, *selectedTowerType);
        

            selectedTowerType = nullptr;
            }
        }
    }
}

void drawTowers(sf::RenderWindow &window){
    for (Tower tower : towers) {
        window.draw(tower.getShape());
        window.draw(tower.getAttackShape());
        tower.attackEnemy(enemies);
        // std::cout << "Tower drawn" << std::endl;
    }
}

void attack(std::vector <Enemy> enemies, std::vector <Tower> towers){
    for (Tower tower : towers){
        tower.attackEnemy(enemies);
    }
}


void mainMenu(sf::RenderWindow &window, int difficulty) {
        sf::Font font;
    if (!font.loadFromFile("FreeMono.ttf")) {
        std::cout << "Could not load font" << std::endl;
    }

    std::vector<std::string> options = {"Easy", "Medium", "Hard", "Very Hard", "Insane"};
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> texts;

    for (int i = 0; i < options.size(); i++) {
        buttons.push_back(createButton(300, 100 + i * 60, 200, 50, sf::Color::Blue));
        texts.push_back(createText(350, 110 + i * 60, options[i], font, 24,sf::Color::White));
    }
    
    sf::RectangleShape playButton = createButton(300, 400, 200, 50, sf::Color::Green);
    sf::Text playText = createText(350, 410, "Play", font, 24,sf::Color::White);

    sf::RectangleShape exitButton = createButton(300, 460, 200, 50, sf::Color::Red);
    sf::Text exitText = createText(350, 470, "Exit", font, 24,sf::Color::White);

    window.clear();

    for (int i = 0; i < buttons.size(); i++) {
        if(difficulty == i+1){
            buttons[i].setFillColor(sf::Color::Yellow);
            texts[i].setFillColor(sf::Color::Black);
        }
            window.draw(buttons[i]);
            window.draw(texts[i]);
    }

    window.draw(playButton);
    window.draw(playText);

    window.draw(exitButton);
    window.draw(exitText);
}

void drawMoney(sf::RenderWindow &window, int money) {
        sf::Font font;
    if (!font.loadFromFile("FreeMono.ttf")) {
        std::cout << "Could not load font" << std::endl;
    }

    std::string moneyString = std::to_string(money) + "$";

    sf::Text moneyText = createText(670, -10, moneyString, font, 50, sf::Color::Yellow); 
    window.draw(moneyText);
}
void endScreen(sf::RenderWindow &window) {
    sf::Font font;
    if (!font.loadFromFile("FreeMono.ttf")) {
        std::cout << "Could not load font" << std::endl;
    }

    sf::Text text = createText(250, 200, "You lost!", font, 50,sf::Color::Red);
    sf::Text text2 = createText(20, 300, "Try with easier difficulty ;)", font, 45,sf::Color::Red);
    sf::Text text3 = createText(150, 400, "Click to try again", font, 45,sf::Color::Red);
    window.clear();
    window.draw(text);
    window.draw(text2);
    window.draw(text3);
}
void deleteTower(sf::Event event, sf::RenderWindow &window,int &money){
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f rightPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        Tile& closestTile = findClosestTile(tiles, rightPosition);
            for (int i = 0; i < towers.size(); i++) {
                if (towers[i].getPosition() == closestTile.getPosition()) {
                    money += towers[i].getType().getCost()/2;
                    towers.erase(towers.begin() + i);
                }
            }
    }
}