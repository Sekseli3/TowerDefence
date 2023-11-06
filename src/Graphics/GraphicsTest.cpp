#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

void drawGraphicsTest(sf::RenderWindow &window,
                const int tileSize,const int windowWidth, const int windowHeight){
                    
    
    sf::RectangleShape mapTiles[2][2];
    sf::CircleShape mapTowers[2][2];

            sf::RectangleShape& tile = mapTiles[0][0];
            sf::RectangleShape& tile1 = mapTiles[0][2];
            sf::CircleShape& tower1 = mapTowers[0][0];
            tile.setSize(sf::Vector2f(tileSize, tileSize));
            tile1.setSize(sf::Vector2f(tileSize, tileSize));
            tower1.setRadius(tileSize/3);

            tile.setFillColor(sf::Color::Green);  
            tile.setOutlineThickness(0.8);
            tile.setOutlineColor(sf::Color::Black);
            tile.setPosition(0 * tileSize, 0 * tileSize);
            
            tile1.setFillColor(sf::Color::Blue);
            tile1.setOutlineThickness(1);
            tile1.setOutlineColor(sf::Color::Black);
            tile1.setPosition(2*tileSize, 0*tileSize);

            tower1.setFillColor(sf::Color::White);
            tower1.setOutlineThickness(2);
            tower1.setOutlineColor(sf::Color::Red);
            tower1.setPosition(0*tileSize+tileSize/3/2, 0*tileSize+tileSize/3/2);

            window.draw(mapTiles[0][0]);
            window.draw(mapTiles[0][2]);
            window.draw(mapTowers[0][0]);
}
