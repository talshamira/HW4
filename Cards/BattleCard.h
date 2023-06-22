//
// Created by user on 16/06/2023.
//

#ifndef HW4_BATTLECARD_H
#define HW4_BATTLECARD_H

#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <iostream>


class BattleCard : public Card {
public:
    BattleCard(int force, int loot);
    virtual ~BattleCard() = default;

    //if player is defeated in battle - acts according the kind of the card (Witch Dragon or Gremlin)
    virtual void defeatsPlayer(Player& player) const = 0;

    //do the action of the card according the kind of the card
    void applyEncounter(Player& player) const override;

private:
    int m_force;  // The force of the monster
    int m_loot; // The profit you get when winning a battle or when getting a "Treasure" card

    //prints win message of the player won the battle
    virtual void printWin(Player &player) const = 0;

    //prints lose message of the player won the battle
    virtual void printLose(Player &player) const = 0;
};


#endif //HW4_BATTLECARD_H
