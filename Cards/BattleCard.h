//
// Created by user on 16/06/2023.
//

#ifndef HW4_BATTLECARD_H
#define HW4_BATTLECARD_H

#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class BattleCard : public Card {
public:
    BattleCard(int force, int loot);
    virtual void defeatsPlayer(Player& player) const;
    void applyEncounter(Player& player) const override;
private:
    int m_force;  // The force of the monster
    int m_loot; // The profit you get when winning a battle or when getting a "Treasure" card
    virtual void printWin(Player &player) const = 0;
    virtual void printLose(Player &player) const = 0;
};


#endif //HW4_BATTLECARD_H
