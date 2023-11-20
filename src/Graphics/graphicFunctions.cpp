#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "../Objects/tower.h"
#include "../Objects/enemies.h"
#include "../tiles.cpp"

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
        {1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1}
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

void addTower(sf::RenderWindow &window, Tile tile, TowerType type){
    Tower tower(tile.getPosition(),type);
    towers.push_back(tower);
}


Enemy addEnemy(sf::RenderWindow &window, int tileSize, int x, int y){
    sf::Vector2f tileStartPosition(x * tileSize+3, y * tileSize+3);
    Tile tile(tileStartPosition, sf::Color::Black, tileSize);
    Enemy enemy(tile.getPosition(), 30, 10, 1, x, y);
    enemies.push_back(enemy);
    window.draw(enemy.getShape());
    return enemy;
}



void placeTower(sf::Event event, sf::RenderWindow &window){

    
    TowerType basicTower(30.0, 20, 20.0, 50.0, sf::Color::Red);
    TowerType advancedTower(40.0, 30, 30.0, 60.0, sf::Color::Blue);
    TowerType ultimateTower(50.0, 40, 40.0, 70.0, sf::Color::Yellow);

    // Create the buttons for each tower type
    sf::RectangleShape basicButton;
    basicButton.setSize(sf::Vector2f(75, 75));
    basicButton.setFillColor(basicTower.getColor());
    basicButton.setPosition(750, 200);

    sf::RectangleShape advancedButton;
    advancedButton.setSize(sf::Vector2f(75, 75));
    advancedButton.setFillColor(advancedTower.getColor());
    advancedButton.setPosition(750, 300);

    sf::RectangleShape ultimateButton;
    ultimateButton.setSize(sf::Vector2f(75, 75));
    ultimateButton.setFillColor(ultimateTower.getColor());
    ultimateButton.setPosition(750, 400);

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
            addTower(window, closestTile, *selectedTowerType);
        
            selectedTowerType = nullptr;
        }
    }
}

void drawTowers(sf::RenderWindow &window){
    for (Tower tower : towers) {
        window.draw(tower.getShape());
    }
}

// Function to create a button
sf::RectangleShape createButton(float x, float y, float width, float height, sf::Color color) {
    sf::RectangleShape button(sf::Vector2f(width, height));
    button.setPosition(x, y);
    button.setFillColor(color);
    return button;
}

// Function to create a text
sf::Text createText(float x, float y, std::string content, sf::Font& font, unsigned int size) {
    sf::Text text;
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(size);
    text.setPosition(x, y);
    return text;
}


void mainMenu(sf::RenderWindow &window) {
        sf::Font font;
    if (!font.loadFromFile("FreeMono.ttf")) {
        std::cout << "Could not load font" << std::endl;
    }

    std::vector<std::string> options = {"Easy", "Medium", "Hard", "Very Hard", "Insane"};
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> texts;

    for (int i = 0; i < options.size(); i++) {
        buttons.push_back(createButton(300, 100 + i * 60, 200, 50, sf::Color::Blue));
        texts.push_back(createText(350, 110 + i * 60, options[i], font, 24));
    }

    sf::RectangleShape playButton = createButton(300, 400, 200, 50, sf::Color::Green);
    sf::Text playText = createText(350, 410, "Play", font, 24);

    sf::RectangleShape exitButton = createButton(300, 460, 200, 50, sf::Color::Red);
    sf::Text exitText = createText(350, 470, "Exit", font, 24);

    window.clear();

    for (int i = 0; i < buttons.size(); i++) {
            window.draw(buttons[i]);
            window.draw(texts[i]);
    }

    window.draw(playButton);
    window.draw(playText);

    window.draw(exitButton);
    window.draw(exitText);
}