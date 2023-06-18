//
// Created by user on 17/06/2023.
//

#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Treasure : public Card
{
    static const int COINS_TO_ADD = 10;
    void applyEncounter(Player& player) const override;
};

#endif //HW4_TREASURE_H
