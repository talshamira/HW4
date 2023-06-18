//
// Created by user on 16/06/2023.
//

#ifndef HW4_WITCH_H
#define HW4_WITCH_H


#include "Card.h"
#include "BattleCard.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Witch : public BattleCard
{
    static const int FORCE = 11;
    static const int LOOT = 2;
    static const int HP_TO_DEMINISH = 10;
    public:
        Witch() : BattleCard(FORCE, LOOT) {}
        void defeatsPlayer(Player &player) const override;
};


#endif //HW4_WITCH_H
