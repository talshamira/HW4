//
// Created by user on 17/06/2023.
//

#include "Treasure.h"
void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(COINS_TO_ADD);
    printTreasureMessage();
}

void Treasure::printCard(std::ostream& os) const
{
    printCardDetails(os, "Treasure");
}