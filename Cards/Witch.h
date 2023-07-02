//
// Created by user on 16/06/2023.
//

#ifndef HW4_WITCH_H
#define HW4_WITCH_H


#include "Card.h"
#include "BattleCard.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Witch : public BattleCard
{
    public:
        /*
         * constructor for witch
         * initiates all parameters to default values 
         * force = 11, loot = 2
         */
        Witch() : BattleCard(FORCE, LOOT) {}
        /*
         * virtual function derived from Cards
         * applyies the effects of loosing to a witch
         * the players force is deminished by 1 
         * the player looses 10 hp
         */
        void defeatsPlayer(Player &player) const override;
        /*
         * default functions
         */
        ~Witch() = default;
        Witch& operator=(const Witch& witch) = default;
        Witch(const Witch& witch) = default;
    private:
        static const int FORCE = 11;
        static const int LOOT = 2;
        static const int HP_TO_DEMINISH = 10;
        /*
         * virtual print function derived from card
         * prints the specific details for witch
         * @PARAM os is the output stream 
         */
        void printCard(std::ostream& os) const override;
        /*
         * virtual print function derived from card
         * prints the specific details for beating a witch
         * @PARAM player is the player that won 
         */
        void printWin(Player &player) const override;
        /*
         * virtual print function derived from card
         * prints the specific details for loosing to a witch
         * @PARAM player is the player that lost 
         */
        void printLose(Player &player) const override;
};


#endif //HW4_WITCH_H
