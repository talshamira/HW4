//
// Created by user on 17/06/2023.
//

#include "Well.h"
void Well::applyEncounter(Player& player) const
{
    bool isNinja = (player.getJob() == "Ninja") ? true : false;
    if(!isNinja)
    {
        player.damage(POINTS_TO_DIMINISH);
    }
    printWellMessage(isNinja);
}

void Well::printCard(std::ostream& os) const
{
    printCardDetails(os, "Well");
}