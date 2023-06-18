//
// Created by user on 17/06/2023.
//

#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Barfight : public Card
{
public:
    static const int POINTS_TO_DIMINISH = 8;
    void applyEncounter(Player& player) const override;
};

#endif //HW4_BARFIGHT_H
