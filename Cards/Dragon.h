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
private:
    static const int FORCE = 25;
    static const int LOOT = 1000;
    void printCard(std::ostream& os) const override;
    void printWin(Player &player) const override;
    void printLose(Player &player) const override;

public:
        Dragon() : BattleCard(FORCE, LOOT) {}
        void defeatsPlayer(Player &player) const override;
};


#endif //HW4_DRAGON_H
