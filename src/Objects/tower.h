#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>
#include "enemies.h"
#include "../gameEngine.hpp"



/// Tower class
/**
 * @brief Represents a type of tower in the tower defense game.
 */
class TowerType {
public:
    /**
     * @brief Constructs a TowerType object with the specified parameters.
     * @param radius The radius of the tower.
     * @param damage The damage inflicted by the tower.
     * @param attack_range The attack range of the tower.
     * @param attack_speed The attack speed of the tower.
     * @param color The color of the tower.
     * @param cost The cost of the tower.
     */
    TowerType(double radius, int damage, double attack_range, double attack_speed, const sf::Color& color, int cost);

    /**
     * @brief Gets the radius of the tower.
     * @return The radius of the tower.
     */
    double getRadius() const;

    /**
     * @brief Gets the damage inflicted by the tower.
     * @return The damage inflicted by the tower.
     */
    int getDamage() const;

    /**
     * @brief Gets the attack range of the tower.
     * @return The attack range of the tower.
     */
    double getAttackRange() const;

    /**
     * @brief Gets the attack speed of the tower.
     * @return The attack speed of the tower.
     */
    double getAttackSpeed() const;

    /**
     * @brief Gets the color of the tower.
     * @return The color of the tower.
     */
    const sf::Color& getColor() const;

    /**
     * @brief Gets the cost of the tower.
     * @return The cost of the tower.
     */
    int getCost() const {return cost;}

    /**
     * @brief Destructor for the TowerType object.
     */
    ~TowerType() {
    }

private:
    double radius;              ///< The radius of the tower.
    int damage;                 ///< The damage inflicted by the tower.
    double attack_range;        ///< The attack range of the tower.
    double attack_speed;        ///< The attack speed of the tower.
    sf::Color color;            ///< The color of the tower.
    int cost;                   ///< The cost of the tower.
};
class Tower  {
public:
    Tower(const sf::Vector2f& position, const TowerType& type);
    sf::ConvexShape& getShape();
    double getAttack_range() const;
    int attackEnemy(std::vector<Enemy> &enemies);
    sf::CircleShape getAttackShape();
    sf::Vector2f getPosition();
    // function to add clock to vector of clocks
    void addClock(UniversalClock &clock);
    TowerType getType() const {return type;}
    ~Tower() {
    }

private:
    sf::ConvexShape shape;
    TowerType type;
    sf::CircleShape attackShape;
    // list of universal clocks
    std::vector<UniversalClock> clocks;
    
};



#endif