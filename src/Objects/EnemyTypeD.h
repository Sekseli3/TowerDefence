/// EnemyTypeD.h
#ifndef TOWER_DEFENCE_2_ENEMYTYPED_H
#define TOWER_DEFENCE_2_ENEMYTYPED_H

#include "EnemyType.h"

class EnemyTypeD : public EnemyType {
public:
    Enemy createEnemy(sf::Vector2f& position, float x, float y) const override;
};

#endif