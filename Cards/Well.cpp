//
// Created by user on 17/06/2023.
//

#include "Well.h"
void Well::applyEncounter(Player& player) const
{
    if(player.getJob() != "Ninja")
    {
        player.damage(POINTS_TO_DIMINISH);
    }
}