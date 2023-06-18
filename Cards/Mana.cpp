//
// Created by user on 17/06/2023.
//

#include "Mana.h"
void Mana::applyEncounter(Player& player) const
{
    if(player.getJob() == "Healer")
    {
        player.heal(POINTS_TO_ADD_TO_HEALER);
    }
}