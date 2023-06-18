//
// Created by user on 17/06/2023.
//

#ifndef HW4_GREMLIN_H
#define HW4_GREMLIN_H

#include "Card.h"
#include "BattleCard.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Gremlin : public BattleCard
{
    static const int FORCE = 5;
    static const int LOOT = 2;
    static const int HP_TO_DEMINISH = 10;
    public:
        Gremlin() : BattleCard(FORCE, LOOT) {}
        void defeatsPlayer(Player &player) const override;
};

#endif //HW4_GREMLIN_H
