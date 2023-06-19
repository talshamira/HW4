//
// Created by user on 16/06/2023.
//

#include "BattleCard.h"
BattleCard::BattleCard(int force, int loot) :
m_force(force),
m_loot(loot)
{}

void BattleCard::applyEncounter(Player &player) const
{
    //if player wins:
    if(player.getAttackStrength() >= this->m_force)
    {
        player.levelUp();
        player.addCoins(this->m_loot);
        printWin(player);
    }
    else
    {
        defeatsPlayer(player);
        printLose(player);
    }
}