//
// Created by user on 17/06/2023.
//

#ifndef HW4_GREMLIN_H
#define HW4_GREMLIN_H

#include "Card.h"
#include "BattleCard.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Gremlin : public BattleCard
{
    public:
        /*
         * constructor for Gremlin
         * initiates all parameters to default values 
         * force = 5, loot = 2
         */
        Gremlin() : BattleCard(FORCE, LOOT) {}
        /*
         * virtual function derived from Cards
         * applyies the effects of loosing to a Gremlin
         * the player looses 10 hp
         */
        void defeatsPlayer(Player &player) const override;
        /*
         * default functions
         */
        ~Gremlin() = default;
        Gremlin& operator=(const Gremlin& gremlin) = default;
        Gremlin(const Gremlin& gremlin) = default;
    private:
        static const int FORCE = 5;
        static const int LOOT = 2;
        static const int HP_TO_DEMINISH = 10;
        /*
        * virtual print function derived from card
        * prints the specific details for Gremlin
        * @PARAM os is the output stream 
        */
        void printCard(std::ostream& os) const override;
        /*
         * virtual print function derived from card
         * prints the specific details for beating a gremlin
         * @PARAM player is the player that won 
         */
        void printWin(Player &player) const override;
        /*
         * virtual print function derived from card
         * prints the specific details for loosing to a gremlin
         * @PARAM player is the player that lost 
         */
        void printLose(Player &player) const override;
};

#endif //HW4_GREMLIN_H
