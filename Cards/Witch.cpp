//
// Created by user on 16/06/2023.
//

#include "Witch.h"
void Witch::defeatsPlayer(Player &player) const
{
    player.damage(HP_TO_DEMINISH);
    player.weakPlayer();
}
