//
// Created by user on 17/06/2023.
//

#ifndef HW4_MANA_H
#define HW4_MANA_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Mana : public Card
{
public:
    static const int POINTS_TO_ADD_TO_HEALER = 10;
    void applyEncounter(Player& player) const override;
};


#endif //HW4_MANA_H
