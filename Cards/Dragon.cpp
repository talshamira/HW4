//
// Created by user on 17/06/2023.
//

#include "Dragon.h"
void Dragon::defeatsPlayer(Player &player) const
{
    player.killPlayer();
}

void Dragon::printCard(std::ostream& os) const
{
    printCardDetails(os, "Dragon");
    printMonsterDetails(os, FORCE, 0, LOOT, true);
}

void Dragon::printWin(Player &player) const
{
    printWinBattle(player.getName(), "Dragon");
}

void Dragon::printLose(Player &player) const
{
    printLossBattle(player.getName(), "Dragon");
}