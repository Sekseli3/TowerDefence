/// EnemyTypeB.h
#ifndef TOWER_DEFENCE_2_ENEMYTYPEB_H
#define TOWER_DEFENCE_2_ENEMYTYPEB_H

#include "EnemyType.h"

class EnemyTypeB : public EnemyType {
public:
    Enemy createEnemy(sf::Vector2f& position, float x, float y) const override;
};

#endif