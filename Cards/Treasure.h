//
// Created by user on 17/06/2023.
//

#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Treasure : public Card
{
    public:
        /*
         * default functions
         */
        Treasure() = default;
        ~Treasure() = default;
        Treasure& operator=(const Treasure& treasure) = default;
        Treasure(const Treasure& treasure) = default;
        /*
         * virtual function derived from Cards
         * applys the cards effects on the given player 
         * gives the given player 10 coins
         * @param player is the player who drew the card
         */
        void applyEncounter(Player& player) const override;
    private:
        /*
         * virtual print function derived from card
         * prints the specific details for Treasure
         * @PARAM os is the output stream 
         */
        void printCard(std::ostream& os) const override;
        static const int COINS_TO_ADD = 10;

};

#endif //HW4_TREASURE_H
