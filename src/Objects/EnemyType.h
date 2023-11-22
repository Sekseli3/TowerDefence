// EnemyType.h
#ifndef TOWER_DEFENCE_2_ENEMYTYPE_H
#define TOWER_DEFENCE_2_ENEMYTYPE_H

#include <SFML/Graphics.hpp>

class Enemy;

class EnemyType {
public:
    virtual Enemy createEnemy(sf::Vector2f& position, float x, float y) const = 0;
    virtual ~EnemyType() = default;
};

#endif