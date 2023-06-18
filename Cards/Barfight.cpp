//
// Created by user on 17/06/2023.
//

#include "Barfight.h"
void Barfight::applyEncounter(Player& player) const
{
    if(player.getJob() != "Warrior")
    {
        player.damage(POINTS_TO_DIMINISH);
    }
}