//
// Created by user on 17/06/2023.
//

#include "Barfight.h"
void Barfight::applyEncounter(Player& player) const
{
    bool isWarrior = (player.getJob() == "Warrior") ? true : false;
    if(!isWarrior)
    {
        player.damage(POINTS_TO_DIMINISH);
    }

    printBarfightMessage(isWarrior);
}

void Barfight::printCard(std::ostream& os) const
{
    printCardDetails(os, "Barfight");
}