/// EnemyTypeC.h
#ifndef TOWER_DEFENCE_2_ENEMYTYPEC_H
#define TOWER_DEFENCE_2_ENEMYTYPEC_H

#include "EnemyType.h"

class EnemyTypeC : public EnemyType {
public:
    Enemy createEnemy(sf::Vector2f& position, float x, float y) const override;
};

#endif