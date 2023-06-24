//
// Created by user on 17/06/2023.
//

#include "Mana.h"
void Mana::applyEncounter(Player& player) const
{
    bool isHealer = (player.getJob() == "Healer") ? true : false;
    if(isHealer)
    {
        player.heal(POINTS_TO_ADD_TO_HEALER);
    }
    printManaMessage(isHealer);
}

void Mana::printCard(std::ostream& os) const
{
    printCardDetails(os, "Mana");
}