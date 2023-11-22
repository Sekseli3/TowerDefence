// EnemyTypeA.h
#ifndef TOWER_DEFENCE_2_ENEMYTYPEA_H
#define TOWER_DEFENCE_2_ENEMYTYPEA_H

#include "EnemyType.h"

class EnemyTypeA : public EnemyType {
public:
    Enemy createEnemy(sf::Vector2f& position, float x, float y) const override;
};

#endif