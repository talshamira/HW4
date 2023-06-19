//
// Created by user on 16/06/2023.
//

#include "Witch.h"
void Witch::defeatsPlayer(Player &player) const
{
    player.damage(HP_TO_DEMINISH);
    player.weakPlayer();
}
void Witch::printCard(std::ostream& os) const
{
    printCardDetails(os, "Witch");
    printMonsterDetails(os, FORCE, HP_TO_DEMINISH, LOOT, false);
}

void Witch::printWin(Player &player) const
{
    printWinBattle(player.getName(), "Witch");
}

void Witch::printLose(Player &player) const
{
    printLossBattle(player.getName(), "Witch");
}