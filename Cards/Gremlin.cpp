//
// Created by user on 17/06/2023.
//

#include "Gremlin.h"
void Gremlin::defeatsPlayer(Player &player) const
{
    player.damage(HP_TO_DEMINISH);
}

void Gremlin::printCard(std::ostream& os) const
{
    printCardDetails(os, "Gremlin");
    printMonsterDetails(os, FORCE, HP_TO_DEMINISH, LOOT, false);
}

void Gremlin::printWin(Player &player) const
{
    printWinBattle(player.getName(), "Gremlin");
}

void Gremlin::printLose(Player &player) const
{
    printLossBattle(player.getName(), "Gremlin");
}