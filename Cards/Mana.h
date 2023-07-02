//
// Created by user on 17/06/2023.
//

#ifndef HW4_MANA_H
#define HW4_MANA_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Mana : public Card
{
    public:
        static const int POINTS_TO_ADD_TO_HEALER = 10;
        /*
         * default functions
         */
        Mana() = default;
        ~Mana() = default;
        Mana& operator=(const Mana& mana) = default;
        Mana(const Mana& mana) = default;
        /*
         * virtual function derived from Cards
         * applys the cards effects on the given player 
         * if the player is a Healer than the player is healed by 10 hp otherwise nothing happens
         * @param player is the player who drew the card
         */
        void applyEncounter(Player& player) const override;
    private:
        /*
         * virtual print function derived from card
         * prints the specific details for Mana
         * @PARAM os is the output stream 
         */
        void printCard(std::ostream& os) const override;
};


#endif //HW4_MANA_H
