#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

void drawGraphicsTest(sf::RenderWindow &window,
                const int tileSize,const int windowWidth, const int windowHeight){
                    
    
    sf::RectangleShape mapTiles[2][2];

            sf::RectangleShape& tile = mapTiles[0][0];
            sf::RectangleShape& tile1 = mapTiles[0][2];
            tile.setSize(sf::Vector2f(tileSize, tileSize));
            tile1.setSize(sf::Vector2f(tileSize, tileSize));

            tile.setFillColor(sf::Color::Green);  
            tile.setOutlineThickness(0.8);
            tile.setOutlineColor(sf::Color::Red);
            tile.setPosition(0 * tileSize, 0 * tileSize);
            
            tile1.setFillColor(sf::Color::Blue);
            tile1.setOutlineThickness(1);
            tile1.setOutlineColor(sf::Color::Red);
            tile1.setPosition(2*tileSize, 0*tileSize);

            window.draw(mapTiles[0][0]);
            window.draw(mapTiles[0][2]);
}
