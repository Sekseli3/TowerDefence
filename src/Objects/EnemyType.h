// EnemyType.h
#ifndef TOWER_DEFENCE_2_ENEMYTYPE_H
#define TOWER_DEFENCE_2_ENEMYTYPE_H

#include <SFML/Graphics.hpp>

class Enemy;

/**
 * @brief The base class for different types of enemies in the game.
 */
class EnemyType {
public:
    /**
     * @brief Creates an enemy of this type at the specified position.
     * 
     * @param position The position of the enemy.
     * @param x The x-coordinate of the position.
     * @param y The y-coordinate of the position.
     * @return The created enemy object.
     */
    virtual Enemy createEnemy(sf::Vector2f& position, float x, float y) const = 0;

    /**
     * @brief Destructor for the EnemyType class.
     */
    virtual ~EnemyType() = default;
};

#endif