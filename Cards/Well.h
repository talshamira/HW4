//
// Created by user on 17/06/2023.
//

#ifndef HW4_WELL_H
#define HW4_WELL_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Well : public Card
{
public:
    static const int POINTS_TO_DIMINISH = 10;
    void applyEncounter(Player& player) const override;
};

#endif //HW4_WELL_H
