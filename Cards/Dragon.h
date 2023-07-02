//
// Created by user on 17/06/2023.
//

#ifndef HW4_DRAGON_H
#define HW4_DRAGON_H

#include "Card.h"
#include "BattleCard.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Dragon : public BattleCard
{
    public:
        /*
         * constructor for dragon
         * initiates all parameters to default values 
         * force = 25, loot = 1000
         */
        Dragon() : BattleCard(FORCE, LOOT) {}
         /*
         * virtual function derived from Cards
         * applyies the effects of loosing to a witch
         * the player instantly looses
         */
        void defeatsPlayer(Player &player) const override;
        /*
         * default functions
         */
        ~Dragon() = default;
        Dragon(const Dragon& dragon) = default;
        Dragon& operator= (const Dragon& dragon) = default;
    private:
        static const int FORCE = 25;
        static const int LOOT = 1000;
        /*
         * virtual print function derived from card
         * prints the specific details for Dragon
         * @PARAM os is the output stream 
         */
        void printCard(std::ostream& os) const override;
        /*
         * virtual print function derived from card
         * prints the specific details for beating a Dragon
         * @PARAM player is the player that won 
         */
        void printWin(Player &player) const override;
        /*
         * virtual print function derived from card
         * prints the specific details for loosing to a Dragon
         * @PARAM player is the player that lost 
         */
        void printLose(Player &player) const override;
};


#endif //HW4_DRAGON_H
