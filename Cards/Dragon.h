//
// Created by user on 17/06/2023.
//

#ifndef HW4_DRAGON_H
#define HW4_DRAGON_H

#include "Card.h"
#include "BattleCard.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Dragon : public BattleCard
{
    static const int FORCE = 25;
    static const int LOOT = 1000;

    Dragon() : BattleCard(FORCE, LOOT) {}

    virtual void defeatsPlayer(Player &player) const;
};


#endif //HW4_DRAGON_H